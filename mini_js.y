%{
#include <string>
#include <iostream>
#include <map>

using namespace std;

struct Atributos {
  string v;
  int l;
};

#define YYSTYPE Atributos

void erro( string msg );
void Print( string st );
void Insere_variavel( string var, int line );
void Checa_variavel_dupla(string var);
void Checa_variavel_existe(string var);

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

P : END { Print( "." ); }
  | I
  | LET D ';' P
  | A ';' P
  ;

I : IF '(' E ')' { Print( "?" ); } P
  ;

A : ID { Checa_variavel_existe( $1.v ); Print( $1.v ); } '=' E { Print( "= ^\n" ); }
  ;

D : B ',' D
  | B
  ;

B : ID { Insere_variavel( $1.v, $1.l ); Print( $1.v + "&" + "\n"); }
  | ID { Insere_variavel( $1.v, $1.l ); Print( $1.v + "&"); } { Print( $1.v ); } '=' E { Print( "= ^\n" ); }
  ;
  
E : E '+' E { Print( "+" ); }
  | E '-' E { Print( "-" ); }
  | E '*' E { Print( "*" ); }
  | E '/' E { Print( "/" ); }
  | E '>' E { Print( ">" ); }
  | E '<' E { Print( "<" ); }
  | ID { Checa_variavel_existe( $1.v ); Print( $1.v ); } '=' E { Print( "=" ); }
  | F
  ;
  
F : ID { Print( $1.v + "@" ); }
  | NUM { Print( $1.v ); }
  | STR { Print( $1.v ); }
  | NEWOBJECT { Print( "{}" ); }
  | NEWARRAY { Print( "[]" ); }
  | '(' E ')'
  | ID '(' PARAM ')' { Print( $1.v + " #" ); }
  ;
  
PARAM : ARGs
      |
      ;
  
ARGs : E ',' ARGs
     | E
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

void Insere_variavel( string var, int line ) {
   if (tabela_variaveis.count( var ) > 0) {
    string erro = "a variável '" + var + "' já foi declarada na linha " + to_string(tabela_variaveis[var]) + ".";
    yyerror(erro.c_str());
    exit(0);
  } else {
    tabela_variaveis[var] = line;
  }
}

void Checa_variavel_existe( string var ) {
  if (tabela_variaveis.count( var ) == 0) {
    string erro = "a variável '" + var + "' não foi declarada.";
    yyerror(erro.c_str());
    exit(0);
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
  yylval.v = yytext;
  yylval.l = yylineno;
  coluna += strlen( yytext ); 

  return tk;
}

void yyerror( const char* msg ) {
  cout << endl << "Erro: " << msg << endl;
       //<< "Perto de : '" << yylval.v << "'" <<endl;
  exit( 0 );
}

void Print( string st ) {
  cout << st << " ";
}

int main() {
  yyparse();
  
  cout << endl;
   
  return 0;
}