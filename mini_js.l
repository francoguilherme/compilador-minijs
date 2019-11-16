DIGITO  [0-9]
LETRA   [A-Za-z_]
DOUBLE  {DIGITO}+("."{DIGITO}+)?
ID      {LETRA}({LETRA}|{DIGITO})*
STR 	((\")([^\"\n]|(\\\")|\"\")+(\"))|(\')([^\'\n]|(\\\")|\"\")+(\')

LET        "let"
NEWOBJECT  "{}"
NEWARRAY   "[]"
IF         "if"
ELSE       "else"
WHILE      "while"
FOR        "for"
FUNCTION   "function"
RETURN     "return"
EQUALS     "=="
ASM        "asm{".*"}"

%option noyywrap
%%

"\t"       { coluna += 4; }
" "        { coluna++; }
"\n"	   { yylineno++; coluna = 1; }

{DOUBLE}   { return retorna( NUM ); }
{STR}	   { return retorna( STR ); }

"print"    { return retorna( PRINT ); }

{IF}        { return retorna( IF ); }
{ELSE}      { return retorna( ELSE ); }
{WHILE}     { return retorna( WHILE ); }
{FOR}       { return retorna( FOR ); }
{FUNCTION}  { return retorna( FUNCTION ); }
{RETURN}    { return retorna( RETURN ); }
{EQUALS}    { return retorna( EQUALS ); }
{LET}       { return retorna( LET ); }
{ID}        { return retorna( ID ); }
{NEWOBJECT} { return retorna( NEWOBJECT ); }
{NEWARRAY}  { return retorna( NEWARRAY ); }
{ASM}       { return retornaASM( ASM ); }

.          { return retorna( *yytext ); }

%% 