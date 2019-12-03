/* A Bison parser, made by GNU Bison 2.4.2.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2006, 2009-2010 Free Software
   Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "mini_js.y"

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



/* Line 189 of yacc.c  */
#line 119 "y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     END = 0,
     NUM = 258,
     STR = 259,
     ID = 260,
     PRINT = 261,
     LET = 262,
     NEWOBJECT = 263,
     NEWARRAY = 264,
     IF = 265,
     ELSE = 266,
     WHILE = 267,
     FOR = 268,
     FUNCTION = 269,
     RETURN = 270,
     ASM = 271,
     EQUALS = 272
   };
#endif
/* Tokens.  */
#define END 0
#define NUM 258
#define STR 259
#define ID 260
#define PRINT 261
#define LET 262
#define NEWOBJECT 263
#define NEWARRAY 264
#define IF 265
#define ELSE 266
#define WHILE 267
#define FOR 268
#define FUNCTION 269
#define RETURN 270
#define ASM 271
#define EQUALS 272




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 197 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  54
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   580

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  79
/* YYNRULES -- Number of states.  */
#define YYNSTATES  163

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   272

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    25,     2,     2,
      31,    32,    23,    21,    34,    22,    26,    24,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    35,    29,
      19,    18,    20,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    28,     2,    33,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    27,     2,    30,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     7,     9,    11,    15,    18,    21,    23,
      25,    27,    29,    31,    33,    35,    38,    42,    45,    48,
      50,    54,    59,    65,    72,    75,    79,    83,    87,    91,
      94,    99,   103,   108,   112,   123,   133,   139,   143,   147,
     149,   151,   155,   161,   169,   173,   177,   181,   185,   189,
     193,   197,   201,   205,   209,   214,   218,   220,   222,   226,
     228,   229,   233,   235,   236,   238,   240,   242,   245,   247,
     249,   251,   255,   259,   263,   265,   266,   270,   272,   273
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      37,     0,    -1,    40,    29,    37,    -1,    40,    -1,    41,
      -1,    27,    40,    30,    -1,    27,    30,    -1,    41,    40,
      -1,    41,    -1,    52,    -1,    55,    -1,    51,    -1,    50,
      -1,    43,    -1,    44,    -1,    42,    29,    -1,    56,    16,
      29,    -1,    45,    29,    -1,    46,    29,    -1,    39,    -1,
      56,    31,    32,    -1,    56,    31,    58,    32,    -1,    14,
       5,    31,    32,    38,    -1,    14,     5,    31,    57,    32,
      38,    -1,    15,    29,    -1,    15,    56,    29,    -1,    49,
      18,    56,    -1,    47,    18,    56,    -1,     5,    18,    56,
      -1,    56,    48,    -1,    28,    56,    33,    48,    -1,    28,
      56,    33,    -1,    56,    28,    56,    33,    -1,    56,    26,
       5,    -1,    13,    31,     7,    54,    29,    56,    29,    56,
      32,    38,    -1,    13,    31,    56,    29,    56,    29,    56,
      32,    38,    -1,    12,    31,    56,    32,    38,    -1,     7,
      53,    29,    -1,    54,    34,    53,    -1,    54,    -1,     5,
      -1,     5,    18,    56,    -1,    10,    31,    56,    32,    38,
      -1,    10,    31,    56,    32,    38,    11,    38,    -1,     5,
      18,    56,    -1,    49,    18,    56,    -1,    31,    56,    32,
      -1,    56,    21,    56,    -1,    56,    22,    56,    -1,    56,
      23,    56,    -1,    56,    24,    56,    -1,    56,    20,    56,
      -1,    56,    19,    56,    -1,    56,    25,    56,    -1,    56,
      31,    58,    32,    -1,    56,    17,    56,    -1,    59,    -1,
      39,    -1,    56,    34,    57,    -1,    56,    -1,    -1,    56,
      34,    58,    -1,    56,    -1,    -1,     5,    -1,    49,    -1,
       3,    -1,    22,     3,    -1,     4,    -1,     8,    -1,     9,
      -1,    27,    61,    30,    -1,    28,    60,    33,    -1,    60,
      34,    56,    -1,    56,    -1,    -1,    62,    34,    61,    -1,
      62,    -1,    -1,     5,    35,    56,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    58,    58,    59,    62,    63,    65,    67,    68,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      84,    85,    87,    91,    97,    98,   100,   102,   103,   106,
     108,   109,   111,   112,   114,   117,   121,   125,   128,   129,
     132,   133,   135,   138,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   158,   159,
     160,   162,   163,   164,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   177,   178,   179,   181,   182,   183,   185
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "$undefined", "NUM", "STR", "ID", "PRINT",
  "LET", "NEWOBJECT", "NEWARRAY", "IF", "ELSE", "WHILE", "FOR", "FUNCTION",
  "RETURN", "ASM", "EQUALS", "'='", "'<'", "'>'", "'+'", "'-'", "'*'",
  "'/'", "'%'", "'.'", "'{'", "'['", "';'", "'}'", "'('", "')'", "']'",
  "','", "':'", "$accept", "P", "BLOCO", "BLOCOVAZIO", "CMDs", "CMD",
  "CALL", "CMD_FUNCTION", "CMD_RETURN", "A_PROP", "A", "ARR", "INDEX",
  "PROP", "CMD_FOR", "CMD_WHILE", "CMD_LET", "IDS", "B", "CMD_IF", "E",
  "PARAMS", "ARGS", "F", "ELEMS", "CAMPOS", "CAMPO", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,    61,    60,
      62,    43,    45,    42,    47,    37,    46,   123,    91,    59,
     125,    40,    41,    93,    44,    58
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    36,    37,    37,    38,    38,    39,    40,    40,    41,
      41,    41,    41,    41,    41,    41,    41,    41,    41,    41,
      42,    42,    43,    43,    44,    44,    45,    46,    46,    47,
      48,    48,    49,    49,    50,    50,    51,    52,    53,    53,
      54,    54,    55,    55,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    57,    57,
      57,    58,    58,    58,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    60,    60,    60,    61,    61,    61,    62
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     1,     1,     3,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     2,     3,     2,     2,     1,
       3,     4,     5,     6,     2,     3,     3,     3,     3,     2,
       4,     3,     4,     3,    10,     9,     5,     3,     3,     1,
       1,     3,     5,     7,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     4,     3,     1,     1,     3,     1,
       0,     3,     1,     0,     1,     1,     1,     2,     1,     1,
       1,     3,     3,     3,     1,     0,     3,     1,     0,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    66,    68,    64,     0,    69,    70,     0,     0,     0,
       0,     0,     0,     0,    75,     0,     0,    19,     3,     8,
       0,    13,    14,     0,     0,     0,    65,    12,    11,     9,
      10,     0,    56,     0,    40,     0,    39,     0,     0,     0,
       0,    64,    24,    57,    65,     0,    67,     0,     6,     0,
      77,    74,     0,     0,     1,     0,     7,    15,    17,    18,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    29,    28,     0,    37,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    25,    63,     0,
      71,    78,    72,     0,    46,     2,    27,    26,    16,    55,
      52,    51,    47,    48,    49,    50,    53,    33,     0,    20,
      62,     0,    41,    38,     0,     0,     0,     0,     0,    59,
       0,    44,    45,     0,     0,    79,    76,    73,    32,    63,
      54,     0,    42,     4,    36,     0,     0,    22,    60,     0,
      32,    54,     0,    30,    61,    64,     0,     0,     0,     0,
      58,    23,     0,     5,    43,     0,     0,    31,     0,     0,
       0,    35,    34
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    16,   132,    43,    18,   133,    20,    21,    22,    23,
      24,    25,   143,    44,    27,    28,    29,    35,    36,    30,
      31,   120,   111,    32,    52,    49,    50
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -101
static const yytype_int16 yypact[] =
{
     203,  -101,  -101,   -13,    11,  -101,  -101,   -14,    -8,    -3,
      29,   247,    17,     1,   278,   278,    38,   554,    21,   203,
      22,  -101,  -101,    27,    32,    55,    68,  -101,  -101,  -101,
    -101,    46,  -101,   278,    71,    35,     6,   278,   278,   263,
      62,    76,  -101,  -101,    78,   476,  -101,    67,  -101,    75,
      63,   528,   -22,   368,  -101,   203,  -101,  -101,  -101,  -101,
     278,   278,    77,   278,   278,   278,   278,   278,   278,   278,
     278,   102,   278,     5,  -101,   385,   278,  -101,    11,   398,
     414,    11,   489,   163,   278,   278,   278,  -101,   278,   278,
    -101,   104,  -101,   278,  -101,  -101,   528,   431,  -101,   541,
     541,   541,    18,    18,    64,    64,    64,  -101,   323,  -101,
     291,    79,   528,  -101,   232,   232,    81,   278,   232,   307,
      80,   528,   528,   338,    87,   528,  -101,   528,     7,   278,
      92,   174,   111,  -101,  -101,   278,   502,  -101,   278,   232,
    -101,  -101,   278,  -101,  -101,   -11,    93,   232,   515,   278,
    -101,  -101,   353,  -101,  -101,   278,   444,    96,   460,   232,
     232,  -101,  -101
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -101,    70,  -100,     0,   -18,     3,  -101,  -101,  -101,  -101,
    -101,  -101,    95,     2,  -101,  -101,  -101,    49,    47,  -101,
      15,    -9,   -84,  -101,  -101,    39,  -101
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -58
static const yytype_int16 yytable[] =
{
      17,    56,    26,    19,   124,    33,    47,    33,     1,     2,
      41,    92,    93,     5,     6,   134,    34,    37,   137,    17,
      46,    26,    19,    38,    89,   -31,    45,    12,    39,    51,
      53,    48,    13,    14,    40,   142,    15,   109,    54,   151,
      78,    68,    69,    70,    71,   144,    86,   154,    75,    88,
      55,    57,    79,    80,    82,    17,    58,    26,    19,   161,
     162,    59,    62,    63,    77,    64,    65,    66,    67,    68,
      69,    70,    71,    60,    72,    96,    97,    73,    99,   100,
     101,   102,   103,   104,   105,   106,    61,   108,   110,    76,
      71,   112,    86,    83,    84,    88,    85,    91,   119,   121,
     122,   123,    89,   110,   125,    90,    98,   107,   127,    47,
     135,   130,   139,   146,    17,    17,    26,    26,    17,   141,
      26,   -21,   147,   153,   142,    95,    74,   113,   116,   150,
     126,    17,   136,    26,    19,     0,     0,     0,     0,    17,
       0,    26,     0,     0,   110,     0,     0,    17,     0,    26,
     148,     0,     0,   119,     0,     0,     0,   152,     0,    17,
      17,    26,    26,     0,   156,     0,     1,     2,    41,     0,
     158,     5,     6,     0,     0,     0,     0,     1,     2,   145,
       0,     4,     5,     6,     7,    12,     8,     9,    10,    11,
      13,    14,     0,     0,    15,   118,    12,     0,     0,     0,
       0,    13,    14,     0,    48,    15,     1,     2,     3,     0,
       4,     5,     6,     7,     0,     8,     9,    10,    11,     0,
       0,     0,     0,     0,     0,    12,     0,     0,     0,     0,
      13,    14,     0,     0,    15,     1,     2,     3,     0,     4,
       5,     6,     7,     0,     8,     9,    10,    11,     0,     0,
       1,     2,    41,     0,    12,     5,     6,     0,     0,   131,
      14,     0,     0,    15,     0,     0,     1,     2,    41,    12,
      81,     5,     6,     0,    13,    14,    42,     0,    15,     0,
       0,     1,     2,    41,     0,    12,     5,     6,     0,     0,
      13,    14,     0,     0,    15,     0,     0,     0,     0,     0,
      12,     0,     0,     0,     0,    13,    14,     0,    63,    15,
      64,    65,    66,    67,    68,    69,    70,    71,     0,    86,
       0,     0,    88,     0,    63,   129,    64,    65,    66,    67,
      68,    69,    70,    71,     0,    86,     0,     0,    88,     0,
      63,   138,    64,    65,    66,    67,    68,    69,    70,    71,
       0,    86,     0,     0,    88,    63,   128,    64,    65,    66,
      67,    68,    69,    70,    71,     0,    86,     0,     0,    88,
      63,   140,    64,    65,    66,    67,    68,    69,    70,    71,
       0,    86,     0,     0,    88,    63,   157,    64,    65,    66,
      67,    68,    69,    70,    71,     0,    86,     0,     0,    88,
      94,   -44,    63,     0,    64,    65,    66,    67,    68,    69,
      70,    71,     0,    86,     0,    63,    88,    64,    65,    66,
      67,    68,    69,    70,    71,     0,    86,     0,     0,    88,
     114,    63,     0,    64,    65,    66,    67,    68,    69,    70,
      71,     0,    86,     0,     0,    88,   115,   -45,    63,     0,
      64,    65,    66,    67,    68,    69,    70,    71,     0,    86,
       0,    63,    88,    64,    65,    66,    67,    68,    69,    70,
      71,     0,    86,     0,     0,    88,   159,    63,     0,    64,
      65,    66,    67,    68,    69,    70,    71,     0,    86,     0,
       0,    88,   160,    63,     0,    64,    65,    66,    67,    68,
      69,    70,    71,     0,    86,    87,    63,    88,    64,    65,
      66,    67,    68,    69,    70,    71,     0,    86,   117,    63,
      88,    64,    65,    66,    67,    68,    69,    70,    71,     0,
      86,   149,    63,    88,    64,    65,    66,    67,    68,    69,
      70,    71,     0,    86,   155,    63,    88,    64,    65,    66,
      67,    68,    69,    70,    71,     0,    86,     0,   -58,    88,
     -58,   -58,    66,    67,    68,    69,    70,    71,     0,    86,
     -57,   -57,    88,   -57,   -57,   -57,     0,   -57,   -57,   -57,
     -57
};

static const yytype_int16 yycheck[] =
{
       0,    19,     0,     0,    88,    18,     5,    18,     3,     4,
       5,    33,    34,     8,     9,   115,     5,    31,   118,    19,
       3,    19,    19,    31,    35,    18,    11,    22,    31,    14,
      15,    30,    27,    28,     5,    28,    31,    32,     0,   139,
      34,    23,    24,    25,    26,   129,    28,   147,    33,    31,
      29,    29,    37,    38,    39,    55,    29,    55,    55,   159,
     160,    29,    16,    17,    29,    19,    20,    21,    22,    23,
      24,    25,    26,    18,    28,    60,    61,    31,    63,    64,
      65,    66,    67,    68,    69,    70,    18,    72,    73,    18,
      26,    76,    28,    31,    18,    31,    18,    34,    83,    84,
      85,    86,    35,    88,    89,    30,    29,     5,    93,     5,
      29,    32,    32,   131,   114,   115,   114,   115,   118,    32,
     118,    29,    11,    30,    28,    55,    31,    78,    81,   138,
      91,   131,   117,   131,   131,    -1,    -1,    -1,    -1,   139,
      -1,   139,    -1,    -1,   129,    -1,    -1,   147,    -1,   147,
     135,    -1,    -1,   138,    -1,    -1,    -1,   142,    -1,   159,
     160,   159,   160,    -1,   149,    -1,     3,     4,     5,    -1,
     155,     8,     9,    -1,    -1,    -1,    -1,     3,     4,     5,
      -1,     7,     8,     9,    10,    22,    12,    13,    14,    15,
      27,    28,    -1,    -1,    31,    32,    22,    -1,    -1,    -1,
      -1,    27,    28,    -1,    30,    31,     3,     4,     5,    -1,
       7,     8,     9,    10,    -1,    12,    13,    14,    15,    -1,
      -1,    -1,    -1,    -1,    -1,    22,    -1,    -1,    -1,    -1,
      27,    28,    -1,    -1,    31,     3,     4,     5,    -1,     7,
       8,     9,    10,    -1,    12,    13,    14,    15,    -1,    -1,
       3,     4,     5,    -1,    22,     8,     9,    -1,    -1,    27,
      28,    -1,    -1,    31,    -1,    -1,     3,     4,     5,    22,
       7,     8,     9,    -1,    27,    28,    29,    -1,    31,    -1,
      -1,     3,     4,     5,    -1,    22,     8,     9,    -1,    -1,
      27,    28,    -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,
      22,    -1,    -1,    -1,    -1,    27,    28,    -1,    17,    31,
      19,    20,    21,    22,    23,    24,    25,    26,    -1,    28,
      -1,    -1,    31,    -1,    17,    34,    19,    20,    21,    22,
      23,    24,    25,    26,    -1,    28,    -1,    -1,    31,    -1,
      17,    34,    19,    20,    21,    22,    23,    24,    25,    26,
      -1,    28,    -1,    -1,    31,    17,    33,    19,    20,    21,
      22,    23,    24,    25,    26,    -1,    28,    -1,    -1,    31,
      17,    33,    19,    20,    21,    22,    23,    24,    25,    26,
      -1,    28,    -1,    -1,    31,    17,    33,    19,    20,    21,
      22,    23,    24,    25,    26,    -1,    28,    -1,    -1,    31,
      32,    16,    17,    -1,    19,    20,    21,    22,    23,    24,
      25,    26,    -1,    28,    -1,    17,    31,    19,    20,    21,
      22,    23,    24,    25,    26,    -1,    28,    -1,    -1,    31,
      32,    17,    -1,    19,    20,    21,    22,    23,    24,    25,
      26,    -1,    28,    -1,    -1,    31,    32,    16,    17,    -1,
      19,    20,    21,    22,    23,    24,    25,    26,    -1,    28,
      -1,    17,    31,    19,    20,    21,    22,    23,    24,    25,
      26,    -1,    28,    -1,    -1,    31,    32,    17,    -1,    19,
      20,    21,    22,    23,    24,    25,    26,    -1,    28,    -1,
      -1,    31,    32,    17,    -1,    19,    20,    21,    22,    23,
      24,    25,    26,    -1,    28,    29,    17,    31,    19,    20,
      21,    22,    23,    24,    25,    26,    -1,    28,    29,    17,
      31,    19,    20,    21,    22,    23,    24,    25,    26,    -1,
      28,    29,    17,    31,    19,    20,    21,    22,    23,    24,
      25,    26,    -1,    28,    29,    17,    31,    19,    20,    21,
      22,    23,    24,    25,    26,    -1,    28,    -1,    17,    31,
      19,    20,    21,    22,    23,    24,    25,    26,    -1,    28,
      16,    17,    31,    19,    20,    21,    -1,    23,    24,    25,
      26
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     7,     8,     9,    10,    12,    13,
      14,    15,    22,    27,    28,    31,    37,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    49,    50,    51,    52,
      55,    56,    59,    18,     5,    53,    54,    31,    31,    31,
       5,     5,    29,    39,    49,    56,     3,     5,    30,    61,
      62,    56,    60,    56,     0,    29,    40,    29,    29,    29,
      18,    18,    16,    17,    19,    20,    21,    22,    23,    24,
      25,    26,    28,    31,    48,    56,    18,    29,    34,    56,
      56,     7,    56,    31,    18,    18,    28,    29,    31,    35,
      30,    34,    33,    34,    32,    37,    56,    56,    29,    56,
      56,    56,    56,    56,    56,    56,    56,     5,    56,    32,
      56,    58,    56,    53,    32,    32,    54,    29,    32,    56,
      57,    56,    56,    56,    58,    56,    61,    56,    33,    34,
      32,    27,    38,    41,    38,    29,    56,    38,    34,    32,
      33,    32,    28,    48,    58,     5,    40,    11,    56,    29,
      57,    38,    56,    30,    38,    29,    56,    33,    56,    32,
      32,    38,    38
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 3:

/* Line 1464 of yacc.c  */
#line 59 "mini_js.y"
    { (yyval).v = resolve_enderecos( (yyval).v + "." + funcoes ); print_all( (yyval).v ); }
    break;

  case 4:

/* Line 1464 of yacc.c  */
#line 62 "mini_js.y"
    { (yyval).v = (yyvsp[(1) - (1)]).v; }
    break;

  case 5:

/* Line 1464 of yacc.c  */
#line 63 "mini_js.y"
    { (yyval).v = (yyvsp[(2) - (3)]).v; }
    break;

  case 7:

/* Line 1464 of yacc.c  */
#line 67 "mini_js.y"
    { (yyval).v = (yyvsp[(1) - (2)]).v + (yyvsp[(2) - (2)]).v; }
    break;

  case 8:

/* Line 1464 of yacc.c  */
#line 68 "mini_js.y"
    { (yyval).v = (yyvsp[(1) - (1)]).v; }
    break;

  case 16:

/* Line 1464 of yacc.c  */
#line 78 "mini_js.y"
    {(yyval).v = (yyvsp[(1) - (3)]).v + (yyvsp[(2) - (3)]).v + "^"; }
    break;

  case 17:

/* Line 1464 of yacc.c  */
#line 79 "mini_js.y"
    { (yyval).v = (yyvsp[(1) - (2)]).v; }
    break;

  case 18:

/* Line 1464 of yacc.c  */
#line 80 "mini_js.y"
    { (yyval).v = (yyvsp[(1) - (2)]).v; }
    break;

  case 19:

/* Line 1464 of yacc.c  */
#line 81 "mini_js.y"
    { (yyval).v.clear(); }
    break;

  case 20:

/* Line 1464 of yacc.c  */
#line 84 "mini_js.y"
    { (yyval).v = "0" + (yyvsp[(1) - (3)]).v + "$" + "^"; }
    break;

  case 21:

/* Line 1464 of yacc.c  */
#line 85 "mini_js.y"
    { (yyval).v = (yyvsp[(3) - (4)]).v + to_string((yyvsp[(3) - (4)]).nargs) + (yyvsp[(1) - (4)]).v + "$" + "^"; }
    break;

  case 22:

/* Line 1464 of yacc.c  */
#line 88 "mini_js.y"
    { string label_fun = gera_label((yyvsp[(2) - (5)]).v.at(0));
                 funcoes = funcoes + (":" + label_fun) + (yyvsp[(5) - (5)]).v + "undefined" + "@" + "'&retorno'" + "@" + "~";
                 (yyval).v = (yyvsp[(2) - (5)]).v + "&" + (yyvsp[(2) - (5)]).v + "{}" + "=" + "'&funcao'" + label_fun + "[=]" + "^"; }
    break;

  case 23:

/* Line 1464 of yacc.c  */
#line 92 "mini_js.y"
    { string label_fun = gera_label((yyvsp[(2) - (6)]).v.at(0));
                 vector<string> locais = gera_variaveis_locais((yyvsp[(4) - (6)]).v);
                 funcoes = funcoes + (":" + label_fun) + locais + (yyvsp[(6) - (6)]).v + "undefined" + "@" + "'&retorno'" + "@" + "~";
                 (yyval).v = (yyvsp[(2) - (6)]).v + "&" + (yyvsp[(2) - (6)]).v + "{}" + "=" + "'&funcao'" + label_fun + "[=]" + "^"; }
    break;

  case 25:

/* Line 1464 of yacc.c  */
#line 98 "mini_js.y"
    { (yyval).v = (yyvsp[(2) - (3)]).v + "'&retorno'"+ "@" + "~"; }
    break;

  case 26:

/* Line 1464 of yacc.c  */
#line 100 "mini_js.y"
    { (yyval).v = (yyvsp[(1) - (3)]).v + (yyvsp[(3) - (3)]).v + "[=]" + "^"; }
    break;

  case 27:

/* Line 1464 of yacc.c  */
#line 102 "mini_js.y"
    { (yyval).v = (yyvsp[(1) - (3)]).v + (yyvsp[(3) - (3)]).v + "[=]" + "^"; }
    break;

  case 28:

/* Line 1464 of yacc.c  */
#line 103 "mini_js.y"
    { (yyval).v = (yyvsp[(1) - (3)]).v + (yyvsp[(3) - (3)]).v + "=" + "^"; }
    break;

  case 29:

/* Line 1464 of yacc.c  */
#line 106 "mini_js.y"
    { (yyval).v = (yyvsp[(1) - (2)]).v + (yyvsp[(2) - (2)]).v; }
    break;

  case 30:

/* Line 1464 of yacc.c  */
#line 108 "mini_js.y"
    { (yyval).v = (yyvsp[(2) - (4)]).v + (yyvsp[(4) - (4)]).v; }
    break;

  case 31:

/* Line 1464 of yacc.c  */
#line 109 "mini_js.y"
    { (yyval).v = (yyvsp[(2) - (3)]).v; }
    break;

  case 32:

/* Line 1464 of yacc.c  */
#line 111 "mini_js.y"
    { (yyval).v = (yyvsp[(1) - (4)]).v + (yyvsp[(3) - (4)]).v; }
    break;

  case 33:

/* Line 1464 of yacc.c  */
#line 112 "mini_js.y"
    { (yyval).v = (yyvsp[(1) - (3)]).v + (yyvsp[(3) - (3)]).v; }
    break;

  case 34:

/* Line 1464 of yacc.c  */
#line 115 "mini_js.y"
    { string checa = gera_label("while"); string then = gera_label("then"); string fim = gera_label("fim_if");
                (yyval).v = (yyvsp[(4) - (10)]).v + (":" + checa) + (yyvsp[(6) - (10)]).v + then + "?" + fim + "#" + (":" + then) + (yyvsp[(10) - (10)]).v + (yyvsp[(8) - (10)]).v + "^" + checa + "#" + (":" + fim); }
    break;

  case 35:

/* Line 1464 of yacc.c  */
#line 118 "mini_js.y"
    { string checa = gera_label("while"); string then = gera_label("then"); string fim = gera_label("fim_if");
                (yyval).v = (yyvsp[(3) - (9)]).v + "^" + (":" + checa) + (yyvsp[(5) - (9)]).v + then + "?" + fim + "#" + (":" + then) + (yyvsp[(9) - (9)]).v + (yyvsp[(7) - (9)]).v + "^" + checa + "#" + (":" + fim); }
    break;

  case 36:

/* Line 1464 of yacc.c  */
#line 122 "mini_js.y"
    { string checa = gera_label("while"); string then = gera_label("then"); string fim = gera_label("fim");
              (yyval).v = (":" + checa) + (yyvsp[(3) - (5)]).v + then + "?" + fim + "#" + (":" + then) + (yyvsp[(5) - (5)]).v + checa + "#" + (":" + fim); }
    break;

  case 37:

/* Line 1464 of yacc.c  */
#line 125 "mini_js.y"
    { (yyval).v = (yyvsp[(2) - (3)]).v; }
    break;

  case 38:

/* Line 1464 of yacc.c  */
#line 128 "mini_js.y"
    { (yyval).v = (yyvsp[(1) - (3)]).v + (yyvsp[(3) - (3)]).v; }
    break;

  case 40:

/* Line 1464 of yacc.c  */
#line 132 "mini_js.y"
    { insere_variavel( (yyvsp[(1) - (1)]).v, (yyvsp[(1) - (1)]).l ); (yyval).v = (yyvsp[(1) - (1)]).v + "&"; }
    break;

  case 41:

/* Line 1464 of yacc.c  */
#line 133 "mini_js.y"
    { insere_variavel( (yyvsp[(1) - (3)]).v, (yyvsp[(1) - (3)]).l ); (yyval).v = (yyvsp[(1) - (3)]).v + "&" + (yyvsp[(1) - (3)]).v + (yyvsp[(3) - (3)]).v + "=" + "^"; }
    break;

  case 42:

/* Line 1464 of yacc.c  */
#line 136 "mini_js.y"
    { string label = gera_label("then"); string fim = gera_label("fim_if");
           (yyval).v = (yyvsp[(3) - (5)]).v + label + "?" + fim + "#" + (":" + label) + (yyvsp[(5) - (5)]).v + (":" + fim); }
    break;

  case 43:

/* Line 1464 of yacc.c  */
#line 139 "mini_js.y"
    { string then = gera_label("then"); string els = gera_label("else"); string else_then = gera_label("then"); string fim = gera_label("fim_if");
           (yyval).v = (yyvsp[(3) - (7)]).v + then + "?" + els + "#" + (":" + then) + (yyvsp[(5) - (7)]).v + fim + "#" + (":" + els) + (yyvsp[(7) - (7)]).v + (":" + fim); }
    break;

  case 44:

/* Line 1464 of yacc.c  */
#line 142 "mini_js.y"
    { (yyval).v = (yyvsp[(1) - (3)]).v + (yyvsp[(3) - (3)]).v + "="; }
    break;

  case 45:

/* Line 1464 of yacc.c  */
#line 143 "mini_js.y"
    { (yyval).v = (yyvsp[(1) - (3)]).v + (yyvsp[(3) - (3)]).v + "[=]"; }
    break;

  case 46:

/* Line 1464 of yacc.c  */
#line 144 "mini_js.y"
    { (yyval).v = (yyvsp[(2) - (3)]).v; }
    break;

  case 47:

/* Line 1464 of yacc.c  */
#line 145 "mini_js.y"
    { (yyval).v = (yyvsp[(1) - (3)]).v + (yyvsp[(3) - (3)]).v + "+"; }
    break;

  case 48:

/* Line 1464 of yacc.c  */
#line 146 "mini_js.y"
    { (yyval).v = (yyvsp[(1) - (3)]).v + (yyvsp[(3) - (3)]).v + "-"; }
    break;

  case 49:

/* Line 1464 of yacc.c  */
#line 147 "mini_js.y"
    { (yyval).v = (yyvsp[(1) - (3)]).v + (yyvsp[(3) - (3)]).v + "*"; }
    break;

  case 50:

/* Line 1464 of yacc.c  */
#line 148 "mini_js.y"
    { (yyval).v = (yyvsp[(1) - (3)]).v + (yyvsp[(3) - (3)]).v + "/"; }
    break;

  case 51:

/* Line 1464 of yacc.c  */
#line 149 "mini_js.y"
    { (yyval).v = (yyvsp[(1) - (3)]).v + (yyvsp[(3) - (3)]).v + ">"; }
    break;

  case 52:

/* Line 1464 of yacc.c  */
#line 150 "mini_js.y"
    { (yyval).v = (yyvsp[(1) - (3)]).v + (yyvsp[(3) - (3)]).v + "<"; }
    break;

  case 53:

/* Line 1464 of yacc.c  */
#line 151 "mini_js.y"
    { (yyval).v = (yyvsp[(1) - (3)]).v + (yyvsp[(3) - (3)]).v + "%"; }
    break;

  case 54:

/* Line 1464 of yacc.c  */
#line 152 "mini_js.y"
    { (yyval).v = (yyvsp[(3) - (4)]).v + to_string((yyvsp[(3) - (4)]).nargs) + (yyvsp[(1) - (4)]).v + "$"; }
    break;

  case 55:

/* Line 1464 of yacc.c  */
#line 153 "mini_js.y"
    { (yyval).v = (yyvsp[(1) - (3)]).v + (yyvsp[(3) - (3)]).v + "=="; }
    break;

  case 56:

/* Line 1464 of yacc.c  */
#line 154 "mini_js.y"
    { (yyval).v = (yyvsp[(1) - (1)]).v; }
    break;

  case 57:

/* Line 1464 of yacc.c  */
#line 155 "mini_js.y"
    { (yyval).v.clear(); }
    break;

  case 58:

/* Line 1464 of yacc.c  */
#line 158 "mini_js.y"
    { (yyval).v = (yyvsp[(1) - (3)]).v + (yyvsp[(3) - (3)]).v; }
    break;

  case 59:

/* Line 1464 of yacc.c  */
#line 159 "mini_js.y"
    { (yyval).v = (yyvsp[(1) - (1)]).v; }
    break;

  case 60:

/* Line 1464 of yacc.c  */
#line 160 "mini_js.y"
    { (yyval).v.clear(); }
    break;

  case 61:

/* Line 1464 of yacc.c  */
#line 162 "mini_js.y"
    { (yyval).nargs = (yyvsp[(3) - (3)]).nargs + 1; (yyval).v = (yyvsp[(1) - (3)]).v + (yyvsp[(3) - (3)]).v; }
    break;

  case 62:

/* Line 1464 of yacc.c  */
#line 163 "mini_js.y"
    { (yyval).nargs = 1; (yyval).v = (yyvsp[(1) - (1)]).v; }
    break;

  case 63:

/* Line 1464 of yacc.c  */
#line 164 "mini_js.y"
    { (yyval).v.clear(); (yyval).nargs = 0; }
    break;

  case 64:

/* Line 1464 of yacc.c  */
#line 166 "mini_js.y"
    { (yyval).v = (yyvsp[(1) - (1)]).v + "@"; }
    break;

  case 65:

/* Line 1464 of yacc.c  */
#line 167 "mini_js.y"
    { (yyval).v = (yyvsp[(1) - (1)]).v + "[@]"; }
    break;

  case 66:

/* Line 1464 of yacc.c  */
#line 168 "mini_js.y"
    { (yyval).v = (yyvsp[(1) - (1)]).v; }
    break;

  case 67:

/* Line 1464 of yacc.c  */
#line 169 "mini_js.y"
    { (yyval).v = "0" + (yyvsp[(2) - (2)]).v + "-"; }
    break;

  case 68:

/* Line 1464 of yacc.c  */
#line 170 "mini_js.y"
    { (yyval).v = (yyvsp[(1) - (1)]).v; }
    break;

  case 69:

/* Line 1464 of yacc.c  */
#line 171 "mini_js.y"
    { (yyval).v = (yyvsp[(1) - (1)]).v; }
    break;

  case 70:

/* Line 1464 of yacc.c  */
#line 172 "mini_js.y"
    { (yyval).v = (yyvsp[(1) - (1)]).v; }
    break;

  case 71:

/* Line 1464 of yacc.c  */
#line 173 "mini_js.y"
    { (yyval).v = "{}" + (yyvsp[(2) - (3)]).v; }
    break;

  case 72:

/* Line 1464 of yacc.c  */
#line 174 "mini_js.y"
    { (yyval).v = "[]" + (yyvsp[(2) - (3)]).v; }
    break;

  case 73:

/* Line 1464 of yacc.c  */
#line 177 "mini_js.y"
    { (yyval).nargs = (yyvsp[(1) - (3)]).nargs + 1; (yyval).v = (yyvsp[(1) - (3)]).v + to_string((yyval).nargs) + (yyvsp[(3) - (3)]).v + "[<=]"; }
    break;

  case 74:

/* Line 1464 of yacc.c  */
#line 178 "mini_js.y"
    { (yyval).nargs = 0; (yyval).v = to_string((yyval).nargs) + (yyvsp[(1) - (1)]).v + "[<=]"; }
    break;

  case 75:

/* Line 1464 of yacc.c  */
#line 179 "mini_js.y"
    { (yyval).v.clear(); (yyval).nargs = 0; }
    break;

  case 76:

/* Line 1464 of yacc.c  */
#line 181 "mini_js.y"
    { (yyval).v = (yyvsp[(1) - (3)]).v + (yyvsp[(3) - (3)]).v; }
    break;

  case 77:

/* Line 1464 of yacc.c  */
#line 182 "mini_js.y"
    { (yyval).v = (yyvsp[(1) - (1)]).v; }
    break;

  case 78:

/* Line 1464 of yacc.c  */
#line 183 "mini_js.y"
    { (yyval).v.clear(); }
    break;

  case 79:

/* Line 1464 of yacc.c  */
#line 185 "mini_js.y"
    { (yyval).v = (yyvsp[(1) - (3)]).v + (yyvsp[(3) - (3)]).v + "[<=]"; }
    break;



/* Line 1464 of yacc.c  */
#line 2096 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1684 of yacc.c  */
#line 187 "mini_js.y"


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
    if (vars.at(i) == "@")
      vars.erase(vars.begin() + i);

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
