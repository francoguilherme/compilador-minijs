%{
#include <string>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct Atributos {
  vector<string> v;
  int l;
};

#define YYSTYPE Atributos

void erro(string msg);
void PrintAll(vector<string> commands);
void Insere_variavel(string var, int line);
void Checa_variavel_dupla(string var);
void Checa_variavel_existe(string var);
vector<string> concatena(vector<string> a, vector<string> b);
vector<string> operator +( vector<string> a, vector<string> b );

// prototipo para o analisador lexico (gerado pelo lex)
int yylex();
void yyerror( const char* );
int retorna( int tk );

int linha = 1;
int coluna = 1;

%}

%token NUM STR ID PRINT LET NEWOBJECT NEWARRAY IF END 0 "end of file"

%left '+' '-'
%left '*' '/'

%%

P : CMDs ';' P
  | CMDs ';'
  ;

CMDs : CMD CMDs { $$.v = $1.v + $2.v; }
     | END { PrintAll( $$.v ); }
     ;

CMD : CMD_LET
    | A ';' { $$.v = $1.v; }
    ;

CMD_LET : LET IDS ';' { $$.v = $2.v; }
        ;

IDS : B ',' IDS { $$.v = $1.v + $3.v; }
    | B
    ;

B : ID { Insere_variavel( $1.v, $1.l ); $$.v = $1.v + "&"; }
  | ID '=' E { Insere_variavel( $1.v, $1.l ); $$.v = $1.v + "&" + $1.v + $3.v + "=" + "^"; }

A : ID '=' E { Checa_variavel_existe( $1.v ); $$.v = $1.v + $3.v + "=" + "^"; }
  ;

E : ID '=' E { Checa_variavel_existe( $1.v ); $$.v = $$1.v + $$3.v + "="; }
  | E '+' E { $$.v = $1.v + $3.v + "+"; }
  | E '-' E { $$.v = $1.v + $3.v + "-"; }
  | E '*' E { $$.v = $1.v + $3.v + "*"; }
  | E '/' E { $$.v = $1.v + $3.v + "/"; }
  | E '>' E { $$.v = $1.v + $3.v + ">"; }
  | E '<' E { $$.v = $1.v + $3.v + "<"; }
  | F { $$.v = $1.v; }
  ;
  
F : ID { $$.v = $1.v + "@"; }
  | NUM { $$.v = $1.v; }
  | STR { $$.v = $1.v; }
  | NEWOBJECT { $$.v = $1.v; }
  | NEWARRAY { $$.v = $1.v; }
  ;

%%

#include "lex.yy.c"

map<int,string> nome_tokens = {
  { PrintAll, "PrintAll" },
  { STR, "string" },
  { ID, "nome de identificador" },
  { NUM, "numero" }
};

map<string,int> tabela_variaveis;

void Insere_variavel( string var, int line ) {
   if (tabela_variaveis.count( var ) > 0) {
    string erro = "a variável '" + var + "' já foi declarada na linha " + to_string(tabela_variaveis[var]) + ".";
    yyerror(erro.c_str());
  } else {
    tabela_variaveis[var] = line;
  }
}

void Checa_variavel_existe( string var ) {
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
  vector<string> vect;
  yylval.v = vect.push_back(yytext);
  yylval.l = yylineno;
  coluna += strlen( yytext ); 

  return tk;
}

void yyerror( const char* msg ) {
  cerr << "Erro: " << msg << endl;
       //<< "Perto de : '" << yylval.v << "'" <<endl;
  exit( 1 );
}

void PrintAll(vector<string> commands) {
  /*for (vector<int>::size_type i = 0; i != commands.size(); i++) {
    if (commands[i] == "\n") {
      cout << commands[i];
    } else {
      cout << commands[i] << " ";
    }
  }*/
}

vector<string> operator +( vector<string> a, vector<string> b ) {
  return concatena( a, b );
}

vector<string> concatena( vector<string> a, vector<string> b ) {
  a.insert( a.end(), b.begin(), b.end() );
  return a;
}

int main() {
  yyparse();
  
  cout << endl;
   
  return 0;
}