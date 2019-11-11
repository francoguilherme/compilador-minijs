%{
#include <string>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct Atributos {
  vector<string> v;
  int l;
};

#define YYSTYPE Atributos

void erro( string msg );
void print( string st );
void print_all(vector<string> commands);
void insere_variavel( vector<string> var, int line );
void checa_variavel_dupla(vector<string> var);
void checa_variavel_existe(vector<string> var);
string gera_label( string prefixo );
vector<string> resolve_enderecos( vector<string> entrada );
vector<string> concatena( vector<string> a, vector<string> b );
vector<string> operator+( vector<string> a, vector<string> b );
vector<string> operator+( vector<string> a, string b );
vector<string> operator+( string b, vector<string> a);
vector<string> operator+( vector<string> a, const char* b );
vector<string> operator+( const char* b, vector<string> a );

// prototipo para o analisador lexico (gerado pelo lex)
int yylex();
void yyerror( const char* );
int retorna( int tk );

int linha = 1;
int coluna = 1;

%}

%token NUM STR ID PRINT LET NEWOBJECT NEWARRAY IF ELSE WHILE FOR EQUALS END 0 "end of file"

%left '+' '-'
%left '*' '/'

%%

P : CMDs ';' P
  | CMDs { $$.v = resolve_enderecos( $$.v ); print_all( $$.v ); print("."); }
  ;

BLOCO : CMD { $$.v = $1.v; }
      | '{' CMDs '}' { $$.v = $2.v; }

CMDs : CMD CMDs { $$.v = $1.v + $2.v; }
     | CMD { $$.v = $1.v; }
     ;

CMD : CMD_LET
    | CMD_IF
    | CMD_WHILE
    | CMD_FOR
    | A_PROP ';' { $$.v = $1.v; }
    | A ';' { $$.v = $1.v; }
    ;

A_PROP : | PROP '=' E { $$.v = $1.v + $3.v + "[=]" + "^"; }

A : ARR '=' E { $$.v = $1.v + $3.v + "[=]" + "^"; }
  | ID '=' E { checa_variavel_existe( $1.v ); $$.v = $1.v + $3.v + "=" + "^"; }
  ;

ARR : E INDEX { $$.v = $1.v + $2.v; }

INDEX : '[' E ']' INDEX { $$.v = $2.v + $4.v; }
      | '[' E ']' { $$.v = $2.v; }

PROP : E '[' E ']' { $$.v = $1.v + $3.v; }
     | E '.' ID { $$.v = $1.v + $3.v; }

CMD_FOR : FOR '(' LET B ';' E ';' E ')' BLOCO
              { string checa = gera_label("while"); string then = gera_label("then"); string fim = gera_label("fim_if");
                $$.v = $4.v + (":" + checa) + $6.v + then + "?" + fim + "#" + (":" + then) + $10.v + $8.v + "^" + checa + "#" + (":" + fim); }
        | FOR '(' E ';' E ';' E ')' BLOCO
              { string checa = gera_label("while"); string then = gera_label("then"); string fim = gera_label("fim_if");
                $$.v = $3.v + (":" + checa) + $5.v + then + "?" + fim + "#" + (":" + then) + $9.v + $7.v + checa + "#" + (":" + fim); }

CMD_WHILE : WHILE '(' E ')' BLOCO
            { string checa = gera_label("while"); string then = gera_label("then"); string fim = gera_label("fim");
              $$.v = (":" + checa) + $3.v + then + "?" + fim + "#" + (":" + then) + $5.v + checa + "#" + (":" + fim); }

CMD_LET : LET IDS ';' { $$.v = $2.v; }
        ;

IDS : B ',' IDS { $$.v = $1.v + $3.v; }
    | B
    ;

B : ID { insere_variavel( $1.v, $1.l ); $$.v = $1.v + "&"; }
  | ID '=' E { insere_variavel( $1.v, $1.l ); $$.v = $1.v + "&" + $1.v + $3.v + "=" + "^"; }

CMD_IF : IF '(' E ')' BLOCO
         { string label = gera_label("then"); string fim = gera_label("fim_if");
           $$.v = $3.v + label + "?" + fim + "#" + (":" + label) + $5.v + (":" + fim); }
       | IF '(' E ')' BLOCO ELSE BLOCO
         { string then = gera_label("then"); string els = gera_label("else"); string else_then = gera_label("then"); string fim = gera_label("fim_if");
           $$.v = $3.v + then + "?" + els + "#" + (":" + then) + $5.v + fim + "#" + (":" + els) + $7.v + (":" + fim); }

E : ID '=' E { checa_variavel_existe( $1.v ); $$.v = $1.v + $3.v + "="; }
  | PROP '=' E { checa_variavel_existe( $1.v ); $$.v = $1.v + $3.v + "[=]"; }
  | '(' E ')' { $$.v = $2.v; }
  | E '+' E { $$.v = $1.v + $3.v + "+"; }
  | E '-' E { $$.v = $1.v + $3.v + "-"; }
  | E '*' E { $$.v = $1.v + $3.v + "*"; }
  | E '/' E { $$.v = $1.v + $3.v + "/"; }
  | E '>' E { $$.v = $1.v + $3.v + ">"; }
  | E '<' E { $$.v = $1.v + $3.v + "<"; }
  | E EQUALS E { $$.v = $1.v + $3.v + "=="; }
  | F { $$.v = $1.v; }
  ;

F : ID { $$.v = $1.v + "@"; }
  | PROP { $$.v = $1.v + "[@]"; }
  | NUM { $$.v = $1.v; }
  | '-' NUM { $$.v = "0" + $2.v + "-"; }
  | STR { $$.v = $1.v; }
  | NEWOBJECT { $$.v = $1.v; }
  | NEWARRAY { $$.v = $1.v; }
  ;

%%

#include "lex.yy.c"

map<int,string> nome_tokens = {
  { PRINT, "print" },
  { STR, "string" },
  { ID, "nome de identificador" },
  { NUM, "numero" }
};

map<string,int> tabela_variaveis;

void print_all(vector<string> commands) {
  for (auto a: commands) {
    cout << a << " ";
    if (a == "^")
      cout << "\n";
  }
}

void insere_variavel( vector<string> command, int line ) {
   string var = command[0];
   if (tabela_variaveis.count( var ) > 0) {
    string erro = "a variável '" + var + "' já foi declarada na linha " + to_string(tabela_variaveis[var]) + ".";
    yyerror(erro.c_str());
  } else {
    tabela_variaveis[var] = line;
  }
}

void checa_variavel_existe( vector<string> command ) {
  string var = command[0];
  if (tabela_variaveis.count( var ) == 0) {
    string erro = "a variável '" + var + "' não foi declarada.";
    yyerror(erro.c_str());
  }
}

string nome_token( int token ) {
  if( nome_tokens.find( token ) != nome_tokens.end() )
    return nome_tokens[token];
  else {
    string r;
    
    r = token;
    return r;
  }
}

int retorna( int tk ) {  
  yylval.v = vector<string>();
  yylval.v.push_back(yytext);
  yylval.l = yylineno;
  coluna += strlen( yytext ); 

  return tk;
}

vector<string> concatena( vector<string> a, vector<string> b ) {
  a.insert( a.end(), b.begin(), b.end() );
  return a;
}

vector<string> operator+( vector<string> a, vector<string> b ) {
  return concatena( a, b );
}

vector<string> operator+( vector<string> a, string b ) {
  a.push_back(b);
  return a;
}

vector<string> operator+( string b, vector<string> a) {
  a.insert(a.begin(), b);
  return a;
}

vector<string> operator+( vector<string> a, const char* b ) {
  string str = b;
  a.push_back(str);
  return a;
}

vector<string> operator+( const char* b, vector<string> a ) {
  string str = b;
  a.insert(a.begin(), str);
  return a;
}

string gera_label( string prefixo ) {
  static int n = 0;

  return prefixo + "_" + to_string( ++n ) + ":";
}

vector<string> resolve_enderecos( vector<string> entrada ) {
  map<string,int> label;
  vector<string> saida;

  for( auto command: entrada ) 
    if( command[0] == ':' )
      label[command.substr(1)] = saida.size();
    else
      saida.push_back( command );
  
   for( int i = 0; i < saida.size(); i++ ) 
    if( label.count( saida[i] ) > 0 )
      saida[i] = to_string(label[saida[i]]);
    
  return saida;
}

void yyerror( const char* msg ) {
  cerr << "Erro: " << msg << endl;
       //<< "Perto de : '" << yylval.v << "'" <<endl;
  exit(1);
}

void print( string st ) {
  cout << st << " ";
}

int main() {
  yyparse();
  
  cout << endl;
   
  return 0;
}