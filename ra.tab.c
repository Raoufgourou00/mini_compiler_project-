
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

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
#line 1 "ra.y"

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "TS.h"
    #include "QUAD.h"
    #include "RS.h"

    int yylex();
    int yyerror(char *);
    extern FILE *yyin;
    extern int line, col;
    int nature;
    char* type;
    char* valeur; 
    Liste_Element_Struct Liste = NULL;
    bool div_par_zero = false;
    int nb_erreurs = 0;



/* Line 189 of yacc.c  */
#line 95 "ra.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
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
     mc_var = 258,
     mc_code = 259,
     mc_integer = 260,
     mc_float = 261,
     mc_const = 262,
     mc_struct = 263,
     mc_if = 264,
     mc_else = 265,
     mc_for = 266,
     mc_while = 267,
     deux_points = 268,
     acc_ouv = 269,
     acc_fer = 270,
     croch_ouv = 271,
     croch_fer = 272,
     pvg = 273,
     vg = 274,
     aff = 275,
     par_ouv = 276,
     par_fer = 277,
     point = 278,
     plus = 279,
     moins = 280,
     slash = 281,
     etoile = 282,
     and = 283,
     or = 284,
     not = 285,
     sup = 286,
     inf = 287,
     sup_egal = 288,
     inf_egal = 289,
     egal_egal = 290,
     non_egal = 291,
     idf = 292,
     reel = 293,
     entier = 294
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 21 "ra.y"

                char* nom;
        


/* Line 214 of yacc.c  */
#line 176 "ra.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 188 "ra.tab.c"

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
# if YYENABLE_NLS
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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   190

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  60
/* YYNRULES -- Number of states.  */
#define YYNSTATES  149

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   294

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,    15,    18,    19,    23,    29,    36,    38,
      40,    42,    45,    47,    49,    53,    60,    62,    67,    70,
      71,    75,    79,    81,    84,    85,    87,    89,    91,    93,
      98,   105,   113,   117,   121,   125,   129,   131,   135,   140,
     142,   144,   148,   154,   159,   164,   169,   175,   179,   187,
     192,   197,   201,   205,   208,   212,   216,   220,   224,   228,
     232
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      41,     0,    -1,    37,    14,     3,    14,    42,    15,     4,
      14,    51,    15,    15,    -1,    42,    43,    -1,    -1,    45,
      47,    18,    -1,     7,    37,    20,    44,    18,    -1,     8,
      14,    48,    15,    37,    18,    -1,    39,    -1,    38,    -1,
      46,    -1,     8,    37,    -1,     5,    -1,     6,    -1,    47,
      19,    37,    -1,    47,    19,    37,    16,    39,    17,    -1,
      37,    -1,    37,    16,    39,    17,    -1,    48,    49,    -1,
      -1,    46,    50,    18,    -1,    50,    19,    37,    -1,    37,
      -1,    51,    52,    -1,    -1,    53,    -1,    55,    -1,    58,
      -1,    61,    -1,    37,    20,    54,    18,    -1,    37,    23,
      37,    20,    54,    18,    -1,    37,    16,    39,    17,    20,
      54,    18,    -1,    54,    24,    54,    -1,    54,    25,    54,
      -1,    54,    26,    54,    -1,    54,    27,    54,    -1,    37,
      -1,    37,    23,    37,    -1,    37,    16,    39,    17,    -1,
      39,    -1,    38,    -1,    21,    54,    22,    -1,    56,    10,
      14,    51,    15,    -1,    57,    14,    51,    15,    -1,    57,
      14,    51,    15,    -1,     9,    21,    63,    22,    -1,    11,
      59,    14,    51,    15,    -1,    21,    60,    22,    -1,    37,
      13,    54,    13,    39,    13,    39,    -1,    62,    14,    51,
      15,    -1,    12,    21,    63,    22,    -1,    63,    29,    63,
      -1,    63,    28,    63,    -1,    30,    63,    -1,    54,    32,
      54,    -1,    54,    31,    54,    -1,    54,    34,    54,    -1,
      54,    33,    54,    -1,    54,    35,    54,    -1,    54,    36,
      54,    -1,    21,    63,    22,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    37,    37,    40,    41,    44,    48,    54,    65,    72,
      81,    82,    91,    92,    95,   101,   109,   115,   125,   126,
     128,   134,   140,   149,   150,   153,   154,   155,   156,   159,
     175,   191,   213,   219,   225,   233,   240,   254,   269,   285,
     293,   301,   304,   305,   307,   309,   313,   315,   317,   323,
     325,   328,   329,   330,   331,   332,   333,   334,   335,   336,
     337
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "mc_var", "mc_code", "mc_integer",
  "mc_float", "mc_const", "mc_struct", "mc_if", "mc_else", "mc_for",
  "mc_while", "deux_points", "acc_ouv", "acc_fer", "croch_ouv",
  "croch_fer", "pvg", "vg", "aff", "par_ouv", "par_fer", "point", "plus",
  "moins", "slash", "etoile", "and", "or", "not", "sup", "inf", "sup_egal",
  "inf_egal", "egal_egal", "non_egal", "idf", "reel", "entier", "$accept",
  "S", "LISTE_DEC", "DEC", "VALEUR", "TYPE", "TYPE_SIMPLE", "LISTE_VAR",
  "LISTE_DEC_SIMPLE", "DEC_SIMPLE", "LISTE_VAR_SIMPLE", "LISTE_INST",
  "INST", "INST_AFF", "EXP", "INST_IF", "AVANT_ELSE", "AVANT_INST",
  "INST_FOR", "FOR_INIT", "FOR_PAR", "INST_WHILE", "WHILE_PAR", "COND", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    40,    41,    42,    42,    43,    43,    43,    44,    44,
      45,    45,    46,    46,    47,    47,    47,    47,    48,    48,
      49,    50,    50,    51,    51,    52,    52,    52,    52,    53,
      53,    53,    54,    54,    54,    54,    54,    54,    54,    54,
      54,    54,    55,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      63
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,    11,     2,     0,     3,     5,     6,     1,     1,
       1,     2,     1,     1,     3,     6,     1,     4,     2,     0,
       3,     3,     1,     2,     0,     1,     1,     1,     1,     4,
       6,     7,     3,     3,     3,     3,     1,     3,     4,     1,
       1,     3,     5,     4,     4,     4,     5,     3,     7,     4,
       4,     3,     3,     2,     3,     3,     3,     3,     3,     3,
       3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     4,     0,    12,    13,
       0,     0,     0,     3,     0,    10,     0,    19,    11,     0,
      16,     0,     0,     0,    24,     0,     5,     0,     9,     8,
       0,     0,     0,    18,     0,     0,    14,     6,     0,    22,
       0,     0,     0,     0,     0,     0,    23,    25,    26,     0,
       0,    27,    28,     0,    17,     0,     7,    20,     0,     0,
       0,     0,     0,     2,     0,     0,     0,     0,    24,    24,
       0,    21,     0,     0,    36,    40,    39,     0,     0,     0,
       0,    24,     0,     0,     0,     0,     0,    24,     0,     0,
      15,     0,     0,    53,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    45,     0,     0,     0,
      47,     0,    50,     0,     0,    29,     0,     0,    43,    49,
      41,    60,     0,    37,    32,    33,    34,    35,    55,    54,
      57,    56,    58,    59,    52,    51,     0,    46,     0,     0,
      42,    38,     0,     0,    30,     0,    31,     0,    48
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     7,    13,    30,    14,    15,    21,    23,    33,
      40,    34,    46,    47,    77,    48,    49,    50,    51,    61,
      80,    52,    53,    78
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -66
static const yytype_int16 yypact[] =
{
     -22,     4,    25,    26,   -66,    29,   -66,   107,   -66,   -66,
       8,   -11,    37,   -66,    39,   -66,    42,   -66,   -66,    80,
      69,    49,    36,    54,   -66,    66,   -66,    79,   -66,   -66,
     100,    82,    83,   -66,    -7,   130,   133,   -66,   137,   -66,
      74,   139,   140,   141,   148,   125,   -66,   -66,   -66,   154,
     151,   -66,   -66,   152,   -66,   128,   -66,   -66,   131,    33,
     134,   155,    33,   -66,   135,    27,   136,   156,   -66,   -66,
     158,   -66,    33,    33,   -10,   -66,   -66,    75,   114,   159,
     157,   -66,   122,   160,    27,    99,   161,   -66,     5,    12,
     -66,    55,   124,   -66,   143,   146,    27,    27,    27,    27,
      27,    27,    27,    27,    27,    27,   -66,    33,    33,    27,
     -66,    41,   -66,   164,   132,   -66,    27,    46,   166,   -66,
     -66,   -66,   163,   -66,    77,    77,   -66,   -66,   108,   108,
     108,   108,   108,   108,   -66,   150,    71,   -66,    27,   103,
     -66,   -66,   147,   113,   -66,   172,   -66,   149,   -66
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -66,   -66,   -66,   -66,   -66,   -66,   167,   -66,   -66,   -66,
     -66,   -59,   -66,   -66,   -65,   -66,   -66,   -66,   -66,   -66,
     -66,   -66,   -66,   -61
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -45
static const yytype_int16 yytable[] =
{
      85,    82,    41,    17,    42,    43,    94,    91,    44,    88,
      89,    92,    93,    95,    41,     1,    42,    43,     3,   114,
     118,    41,   111,    42,    43,     4,    18,   119,   117,     5,
      45,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,    19,    45,     6,   136,    16,   134,   135,    84,    45,
      41,   139,    42,    43,    72,    41,   137,    42,    43,     8,
       9,   140,    22,    73,    74,    75,    76,    26,    27,    31,
      74,    75,    76,   143,    28,    29,    20,   120,    45,    96,
      97,    98,    99,    45,   142,    25,   100,   101,   102,   103,
     104,   105,    57,    58,    24,    96,    97,    98,    99,    96,
      97,    98,    99,    98,    99,    35,   100,   101,   102,   103,
     104,   105,     8,     9,    10,    11,    36,   115,    37,    38,
      39,   144,    12,    96,    97,    98,    99,    96,    97,    98,
      99,   146,    96,    97,    98,    99,   106,    96,    97,    98,
      99,    64,   107,   108,   112,    65,   121,    54,    66,    55,
     107,   108,   107,   108,   120,    56,    96,    97,    98,    99,
      59,    60,    62,    63,    67,    68,    69,    70,    71,    81,
      87,    79,   109,    86,    83,    90,   -44,   113,   107,   110,
     141,   116,   122,   123,   138,   147,   145,     0,   148,     0,
      32
};

static const yytype_int16 yycheck[] =
{
      65,    62,     9,    14,    11,    12,    16,    72,    15,    68,
      69,    72,    73,    23,     9,    37,    11,    12,    14,    84,
      15,     9,    81,    11,    12,     0,    37,    15,    87,     3,
      37,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,     4,    37,    14,   109,    37,   107,   108,    21,    37,
       9,   116,    11,    12,    21,     9,    15,    11,    12,     5,
       6,    15,    20,    30,    37,    38,    39,    18,    19,    15,
      37,    38,    39,   138,    38,    39,    37,    22,    37,    24,
      25,    26,    27,    37,    13,    16,    31,    32,    33,    34,
      35,    36,    18,    19,    14,    24,    25,    26,    27,    24,
      25,    26,    27,    26,    27,    39,    31,    32,    33,    34,
      35,    36,     5,     6,     7,     8,    37,    18,    18,    37,
      37,    18,    15,    24,    25,    26,    27,    24,    25,    26,
      27,    18,    24,    25,    26,    27,    22,    24,    25,    26,
      27,    16,    28,    29,    22,    20,    22,    17,    23,    16,
      28,    29,    28,    29,    22,    18,    24,    25,    26,    27,
      21,    21,    21,    15,    10,    14,    14,    39,    37,    14,
      14,    37,    13,    37,    39,    17,    10,    17,    28,    22,
      17,    20,    39,    37,    20,    13,    39,    -1,    39,    -1,
      23
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    37,    41,    14,     0,     3,    14,    42,     5,     6,
       7,     8,    15,    43,    45,    46,    37,    14,    37,     4,
      37,    47,    20,    48,    14,    16,    18,    19,    38,    39,
      44,    15,    46,    49,    51,    39,    37,    18,    37,    37,
      50,     9,    11,    12,    15,    37,    52,    53,    55,    56,
      57,    58,    61,    62,    17,    16,    18,    18,    19,    21,
      21,    59,    21,    15,    16,    20,    23,    10,    14,    14,
      39,    37,    21,    30,    37,    38,    39,    54,    63,    37,
      60,    14,    63,    39,    21,    54,    37,    14,    51,    51,
      17,    54,    63,    63,    16,    23,    24,    25,    26,    27,
      31,    32,    33,    34,    35,    36,    22,    28,    29,    13,
      22,    51,    22,    17,    54,    18,    20,    51,    15,    15,
      22,    22,    39,    37,    54,    54,    54,    54,    54,    54,
      54,    54,    54,    54,    63,    63,    54,    15,    20,    54,
      15,    17,    13,    54,    18,    39,    18,    13,    39
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
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

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
# if YYLTYPE_IS_TRIVIAL
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
        case 2:

/* Line 1455 of yacc.c  */
#line 37 "ra.y"
    {Afficher_QUAD();YYACCEPT;;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 45 "ra.y"
    {
        MAJ_TS1(type);
    ;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 49 "ra.y"
    {      
        if(!Double_Declaration_Entite((yyvsp[(2) - (5)].nom))) {
            Inserer_Element_TS1((yyvsp[(2) - (5)].nom), 0, type, valeur);
        }
    ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 55 "ra.y"
    {
        if(!Double_Declaration_Structure((yyvsp[(5) - (6)].nom))) {

            Inserer_Element_TS2((yyvsp[(5) - (6)].nom));
            MAJ_TS2((yyvsp[(5) - (6)].nom), Liste);
        }

        Liste = NULL;
    ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 66 "ra.y"
    {
            type = Allouer_Char(8);
            valeur = Allouer_Char(strlen((yyvsp[(1) - (1)].nom)) + 1);
            strcpy(type, "INTEGER");
            strcpy(valeur, (yyvsp[(1) - (1)].nom));
        ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 73 "ra.y"
    {   
            type = Allouer_Char(6);
            valeur = Allouer_Char(strlen((yyvsp[(1) - (1)].nom)) + 1);
            strcpy(type, "FLOAT");
            strcpy(valeur, (yyvsp[(1) - (1)].nom));
        ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 83 "ra.y"
    {
        if(!Structure_Non_Declare((yyvsp[(2) - (2)].nom))) { 
            
            type = Allouer_Char(strlen((yyvsp[(2) - (2)].nom)) + 1);
            strcpy(type, (yyvsp[(2) - (2)].nom));
        }
    ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 91 "ra.y"
    {type = Allouer_Char(8); strcpy(type, "INTEGER");;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 92 "ra.y"
    {type = Allouer_Char(6); strcpy(type, "FLOAT");;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 96 "ra.y"
    {   
            if(!Double_Declaration_Entite((yyvsp[(3) - (3)].nom))) {          
                Inserer_Element_TS1((yyvsp[(3) - (3)].nom), 1, "#", "#");
            }
        ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 102 "ra.y"
    {
           if(!Double_Declaration_Entite((yyvsp[(3) - (6)].nom))) {      
                if(!Taille_Negative((yyvsp[(3) - (6)].nom), atoi((yyvsp[(5) - (6)].nom)))) {
                    Inserer_Element_TS1((yyvsp[(3) - (6)].nom), 2, "#", (yyvsp[(5) - (6)].nom));
                }
           }
        ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 110 "ra.y"
    {
            if(!Double_Declaration_Entite((yyvsp[(1) - (1)].nom))) {      
                Inserer_Element_TS1((yyvsp[(1) - (1)].nom), 1, "#", "#");
            }
        ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 116 "ra.y"
    {
            if(!Double_Declaration_Entite((yyvsp[(1) - (4)].nom))) {    
                if(!Taille_Negative((yyvsp[(1) - (4)].nom), atoi((yyvsp[(3) - (4)].nom)))) {  
                    Inserer_Element_TS1((yyvsp[(1) - (4)].nom), 2, "#", (yyvsp[(3) - (4)].nom));
                }
            }
        ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 129 "ra.y"
    {
                MAJ_Liste_Element_Struct(Liste, type);
            ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 135 "ra.y"
    {
                    if(!Double_Declaration_Entite_Structure(Liste, (yyvsp[(3) - (3)].nom))) {
                        Inserer_Element(&Liste, (yyvsp[(3) - (3)].nom), "#");
                    }
                ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 141 "ra.y"
    {
                    if(!Double_Declaration_Entite_Structure(Liste, (yyvsp[(1) - (1)].nom))) {
                        Inserer_Element(&Liste, (yyvsp[(1) - (1)].nom), "#");
                    }
                ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 160 "ra.y"
    {
            if(!Entite_Non_Declare((yyvsp[(1) - (4)].nom))) {      
                if(!Est_Une_Constante((yyvsp[(1) - (4)].nom))) {
                    if(strcmp(Get_Idf_Type((yyvsp[(1) - (4)].nom)), "INTEGER") == 0) {
                        Empiler_Type(0);    
                    }
                    else {
                        Empiler_Type(1);
                    }
                    Traitement_Types();
                }
            }
            Incompatibilite_Types((yyvsp[(1) - (4)].nom));
            Affectation_QUAD((yyvsp[(1) - (4)].nom), "");
        ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 176 "ra.y"
    {
            char* idf = Idf_Point_Idf((yyvsp[(1) - (6)].nom), (yyvsp[(3) - (6)].nom));
            if(!Entite_Non_Declare(idf)) {
                if(strcmp(Get_Idf_Type(idf), "INTEGER") == 0) {
                    Empiler_Type(0);    
                }
                else {
                    Empiler_Type(1);
                }
                Traitement_Types();
            }
            Incompatibilite_Types(idf);
            Affectation_QUAD(idf, "");
        ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 192 "ra.y"
    {
            if(!Entite_Non_Declare((yyvsp[(1) - (7)].nom))) {      
                if(!Est_Une_Constante((yyvsp[(1) - (7)].nom))) {
                    if(Est_Un_Tableau((yyvsp[(1) - (7)].nom))) {
                        if(!Out_Of_Bounds((yyvsp[(1) - (7)].nom), atoi((yyvsp[(3) - (7)].nom)))) {
                            if(strcmp(Get_Idf_Type((yyvsp[(1) - (7)].nom)), "INTEGER") == 0) {
                                Empiler_Type(0);    
                            }
                            else {
                                Empiler_Type(1);
                            }
                            Traitement_Types();
                        }
                    }    
                }
            }
            Incompatibilite_Types_Tab((yyvsp[(1) - (7)].nom), (yyvsp[(3) - (7)].nom));
            Affectation_QUAD((yyvsp[(1) - (7)].nom), ""); //chck this
        ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 214 "ra.y"
    {   
        Addition_QUAD("", "");     
        Traitement_Types();
        div_par_zero = false;
    ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 220 "ra.y"
    {
        Soustraction_QUAD("", ""); 
        Traitement_Types();
        div_par_zero = false;
    ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 226 "ra.y"
    {   
        Division_QUAD("", ""); 
        Division_Par_Zero(div_par_zero);
        //printf("\n");
        Traitement_Types();
        div_par_zero = false;
    ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 234 "ra.y"
    {   
        Multiplication_QUAD("", ""); 
        Traitement_Types();
        div_par_zero = false;
        
    ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 241 "ra.y"
    {   
        //printf(" ");
        if(!Entite_Non_Declare((yyvsp[(1) - (1)].nom)))
        {    
            if(strcmp(Get_Idf_Type((yyvsp[(1) - (1)].nom)), "INTEGER") == 0) {
                Empiler_Type(0);    
            }
            else {
                Empiler_Type(1);
            }
        }
        Affectation_QUAD("", (yyvsp[(1) - (1)].nom));
    ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 255 "ra.y"
    {   
        //printf(" ");
        char* idf = Idf_Point_Idf((yyvsp[(1) - (3)].nom), (yyvsp[(3) - (3)].nom));
        if(!Entite_Non_Declare(idf))
        {
            if(strcmp(Get_Idf_Type(idf), "INTEGER") == 0) {
                Empiler_Type(0);    
            }
            else {
                Empiler_Type(1);
            }
        }
        Affectation_QUAD("", idf);
    ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 270 "ra.y"
    {
        if(!Entite_Non_Declare((yyvsp[(1) - (4)].nom))) {
            if(Est_Un_Tableau((yyvsp[(1) - (4)].nom))) {
                if(!Out_Of_Bounds((yyvsp[(1) - (4)].nom), atoi((yyvsp[(3) - (4)].nom)))) {
                    if(strcmp(Get_Idf_Type((yyvsp[(1) - (4)].nom)), "INTEGER") == 0) {
                        Empiler_Type(0);    
                    }
                    else {
                        Empiler_Type(1);
                    }
                }
            }
        }
        Affectation_QUAD("", (yyvsp[(1) - (4)].nom)); //check this
    ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 286 "ra.y"
    {   
        Empiler_Type(0);
        Affectation_QUAD("", (yyvsp[(1) - (1)].nom));
        if(atoi((yyvsp[(1) - (1)].nom)) == 0) {
            div_par_zero = true;
        }
    ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 294 "ra.y"
    {
        Empiler_Type(1);
        Affectation_QUAD("", (yyvsp[(1) - (1)].nom));
        if(atof((yyvsp[(1) - (1)].nom)) == 0) {
            div_par_zero = true;
        }
    ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 304 "ra.y"
    {Routine_If_Apres_Inst2();;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 305 "ra.y"
    {Routine_If_Apres_Inst2();;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 307 "ra.y"
    {Routine_If_Apres_Inst1();;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 309 "ra.y"
    {Routine_If_Apres_Cond(); ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 313 "ra.y"
    {Routine_FOR_Apres();;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 318 "ra.y"
    {
    Routine_FOR_Cond((yyvsp[(1) - (7)].nom), (yyvsp[(5) - (7)].nom), (yyvsp[(7) - (7)].nom));
;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 323 "ra.y"
    {Routine_While_Apres_Inst();;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 325 "ra.y"
    {Routine_While_Apres_Cond();;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 328 "ra.y"
    {Or_QUAD();;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 329 "ra.y"
    {And_QUAD();;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 330 "ra.y"
    {Not_Quad();;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 331 "ra.y"
    {Inf_QUAD();;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 332 "ra.y"
    {Sup_QUAD();;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 333 "ra.y"
    {Inf_Egal_QUAD();;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 334 "ra.y"
    {Sup_Egal_QUAD();;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 335 "ra.y"
    {Egal_Egal_QUAD();;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 336 "ra.y"
    {Non_Egal_QUAD();;}
    break;



/* Line 1455 of yacc.c  */
#line 2003 "ra.tab.c"
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



/* Line 1675 of yacc.c  */
#line 341 "ra.y"

int yyerror(char* msg){
    printf("%s : line %d, col %d \n", msg, line, col);
    exit(0);
    return 1;
}
int main(){
    yydebug=0;
    yyin = fopen("in.txt", "r");
    yyparse();

    if(nb_erreurs > 0) {
        exit(1);
    }
    Afficher_TS1();
    Afficher_TS2();
    Afficher_QUAD();
    fclose(yyin);
    return 0;
}

