%{
#include <string>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct Atributos {
  vector<string> v;
  int nargs;
  int l;
};

vector<string> funcoes;

#define YYSTYPE Atributos

void erro( string msg );
void print( string st );
void print_all(vector<string> commands);
void insere_variavel( vector<string> var, int line );
void checa_variavel_dupla(vector<string> var);
void checa_variavel_existe(vector<string> var);
string gera_label( string prefixo );
vector<string> gera_variaveis_locais( vector<string> vars );
vector<string> resolve_enderecos( vector<string> entrada );
vector<string> concatena( vector<string> a, vector<string> b );
vector<string> operator+( vector<string> a, vector<string> b );
vector<string> operator+( vector<string> a, string b );
vector<string> operator+( string b, vector<string> a);
vector<string> operator+( vector<string> a, const char* b );
vector<string> operator+( const char* b, vector<string> a );
vector<string> split( string st );

// prototipo para o analisador lexico (gerado pelo lex)
int yylex();
void yyerror( const char* );
int retorna( int tk );
int retornaASM( int tk );

int linha = 1;
int coluna = 1;

%}

%token NUM STR ID PRINT LET NEWOBJECT NEWARRAY IF ELSE WHILE FOR FUNCTION RETURN ASM EQUALS END 0 "end of file"

%right '='
%nonassoc '<' '>' EQUALS
%left '+' '-'
%left '*' '/' '%'
%left '.'
%left '{' '['

%%

P : CMDs ';' P
  | CMDs { $$.v = resolve_enderecos( $$.v + "." + funcoes ); print_all( $$.v ); }
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
    | CMD_FUNCTION
    | CMD_RETURN
    | CALL
    | E ASM ';' {$$.v = $1.v + $2.v+ "^"; }
    | A_PROP ';' { $$.v = $1.v; }
    | A ';' { $$.v = $1.v; }
    ;

CALL : E '(' ')'
     | E '(' PARAMS ')'

CMD_FUNCTION : FUNCTION ID '(' ')' BLOCO
               { string label_fun = gera_label($2.v.at(0));
                 funcoes = funcoes + (":" + label_fun) + $5.v + "undefined" + "@" + "'&retorno'" + "@" + "~";
                 $$.v = $2.v + "&" + $2.v + "{}" + "=" + "'&funcao'" + label_fun + "[=]" + "^"; }
             | FUNCTION ID '(' PARAMS ')' BLOCO
               { string label_fun = gera_label($2.v.at(0));
                 vector<string> locais = gera_variaveis_locais($4.v);
                 funcoes = funcoes + (":" + label_fun) + locais + $6.v + "undefined" + "@" + "'&retorno'" + "@" + "~";
                 $$.v = $2.v + "&" + $2.v + "{}" + "=" + "'&funcao'" + label_fun + "[=]" + "^"; }

CMD_RETURN : RETURN ';'
           | RETURN E ';' { $$.v = $2.v + "'&retorno'"+ "@" + "~"; }

A_PROP : PROP '=' E { $$.v = $1.v + $3.v + "[=]" + "^"; }

A : ARR '=' E { $$.v = $1.v + $3.v + "[=]" + "^"; }
  | ID '=' E { $$.v = $1.v + $3.v + "=" + "^"; }
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

E : ID '=' E { $$.v = $1.v + $3.v + "="; }
  | PROP '=' E { $$.v = $1.v + $3.v + "[=]"; }
  | '(' E ')' { $$.v = $2.v; }
  | E '+' E { $$.v = $1.v + $3.v + "+"; }
  | E '-' E { $$.v = $1.v + $3.v + "-"; }
  | E '*' E { $$.v = $1.v + $3.v + "*"; }
  | E '/' E { $$.v = $1.v + $3.v + "/"; }
  | E '>' E { $$.v = $1.v + $3.v + ">"; }
  | E '<' E { $$.v = $1.v + $3.v + "<"; }
  | E '%' E { $$.v = $1.v + $3.v + "%"; }
  | E '(' ARGS ')' { $$.v = $3.v + to_string($3.nargs) + $1.v + "$"; }
  | E EQUALS E { $$.v = $1.v + $3.v + "=="; }
  | F { $$.v = $1.v; }
  ;

PARAMS : E ',' PARAMS { $$.v = $1.v + $3.v; }
     | E { $$.v = $1.v; }
     | { $$.v.clear(); }

ARGS : E ',' ARGS { $$.nargs = $3.nargs + 1; $$.v = $1.v + $3.v; }
     | E { $$.nargs = 1; $$.v = $1.v; }
     | { $$.v.clear(); $$.nargs = 0; }

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
    if (a == "^" || a == "." || a == "~")
      cout << "\n";
  }
}

vector<string> gera_variaveis_locais( vector<string> vars ) {
  vector<string> locais;
  for( int i = 0; i < vars.size(); i++ ) 
    locais = locais + vars.at(i) + "&" + vars.at(i) + "arguments" + "@" + to_string(i) + "[@]" + "=" + "^";
  return locais;
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

int retornaASM( int tk ) {
  string lexema(yytext);
  lexema = lexema.substr(4, lexema.size() - 5);
  yylval.v = split(lexema + " ");
  yylval.l = yylineno;
  coluna += strlen( yytext );
  return tk;
}

vector<string> split( string st ) {
  vector<string> res;
  string token;

  for(int i=0; i<st.size(); i++){
    if (st[i] != *" ") {
      token = token + st[i];
    }
    else {
      res.push_back(token);
      token = "";
    }
  }
  return res;
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