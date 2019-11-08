DIGITO  [0-9]
LETRA   [A-Za-z_]
DOUBLE  {DIGITO}+("."{DIGITO}+)?
ID      {LETRA}({LETRA}|{DIGITO})*
STR 	(\"|\')([^\"\n]|(\\\")|\"\")+(\"|\')

LET        "let"
NEWOBJECT  "{}"
NEWARRAY   "[]"
IF         "if"

%option noyywrap
%%

"\t"       { coluna += 4; }
" "        { coluna++; }
"\n"	   { yylineno++; coluna = 1; }

{DOUBLE}   { return retorna( NUM ); }
{STR}	   { return retorna( STR ); }

"print"    { return retorna( PRINT ); }

{IF}        { return retorna( IF ); }
{LET}       { return retorna( LET ); }
{ID}        { return retorna( ID ); }
{NEWOBJECT} { return retorna( NEWOBJECT ); }
{NEWARRAY}  { return retorna( NEWARRAY ); }

.          { return retorna( *yytext ); }

%% 