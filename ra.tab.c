/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "ra.y"

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "TS.h"
    #include "QUAD.h"
    #include "RS.h"
    #include "GEN.h"
    #include "OPTIM.h"

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
    char* nom_idf = NULL;
    char temp[20];


/* Line 371 of yacc.c  */
#line 93 "ra.tab.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "ra.tab.h".  */
#ifndef YY_YY_RA_TAB_H_INCLUDED
# define YY_YY_RA_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
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
/* Line 387 of yacc.c  */
#line 25 "ra.y"

                char* nom;
        

/* Line 387 of yacc.c  */
#line 180 "ra.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

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

#endif /* !YY_YY_RA_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 208 "ra.tab.c"

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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
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

# define YYCOPY_NEEDED 1

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

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   206

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  64
/* YYNRULES -- Number of states.  */
#define YYNSTATES  155

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
      98,   105,   110,   115,   119,   123,   127,   131,   134,   137,
     139,   143,   148,   150,   152,   156,   162,   167,   172,   177,
     182,   187,   189,   194,   198,   207,   211,   215,   218,   222,
     226,   230,   234,   238,   242
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
      -1,    51,    52,    -1,    -1,    53,    -1,    56,    -1,    59,
      -1,    62,    -1,    37,    20,    55,    18,    -1,    37,    23,
      37,    20,    55,    18,    -1,    54,    20,    55,    18,    -1,
      37,    16,    55,    17,    -1,    55,    24,    55,    -1,    55,
      25,    55,    -1,    55,    26,    55,    -1,    55,    27,    55,
      -1,    25,    55,    -1,    24,    55,    -1,    37,    -1,    37,
      23,    37,    -1,    37,    16,    55,    17,    -1,    39,    -1,
      38,    -1,    21,    55,    22,    -1,    57,    10,    14,    51,
      15,    -1,    58,    14,    51,    15,    -1,    58,    14,    51,
      15,    -1,     9,    21,    65,    22,    -1,    60,    14,    51,
      15,    -1,    61,    21,    65,    22,    -1,    12,    -1,    63,
      14,    51,    15,    -1,    64,    55,    22,    -1,    11,    21,
      37,    13,    55,    13,    39,    13,    -1,    65,    29,    65,
      -1,    65,    28,    65,    -1,    30,    65,    -1,    55,    32,
      55,    -1,    55,    31,    55,    -1,    55,    34,    55,    -1,
      55,    33,    55,    -1,    55,    35,    55,    -1,    55,    36,
      55,    -1,    21,    65,    22,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    41,    41,    44,    45,    48,    52,    59,    70,    77,
      86,    87,    96,    97,   100,   106,   114,   120,   130,   131,
     133,   139,   145,   154,   155,   158,   159,   160,   161,   164,
     180,   196,   215,   234,   240,   246,   253,   260,   265,   270,
     283,   297,   319,   327,   335,   338,   339,   341,   343,   346,
     348,   350,   353,   355,   357,   359,   360,   361,   362,   363,
     364,   365,   366,   367,   368
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
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
  "INST", "INST_AFF", "A", "EXP", "INST_IF", "AVANT_ELSE", "AVANT_INST",
  "INST_WHILE", "APRES_COND_WHILE", "AVANT_COND_WHILE", "INST_FOR",
  "AVANT_INST_FOR", "AVANT_COND_FOR", "COND", YY_NULL
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
      53,    53,    54,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    56,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    65
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,    11,     2,     0,     3,     5,     6,     1,     1,
       1,     2,     1,     1,     3,     6,     1,     4,     2,     0,
       3,     3,     1,     2,     0,     1,     1,     1,     1,     4,
       6,     4,     4,     3,     3,     3,     3,     2,     2,     1,
       3,     4,     1,     1,     3,     5,     4,     4,     4,     4,
       4,     1,     4,     3,     8,     3,     3,     2,     3,     3,
       3,     3,     3,     3,     3
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     4,     0,    12,    13,
       0,     0,     0,     3,     0,    10,     0,    19,    11,     0,
      16,     0,     0,     0,    24,     0,     5,     0,     9,     8,
       0,     0,     0,    18,     0,     0,    14,     6,     0,    22,
       0,     0,     0,    51,     0,     0,    23,    25,     0,    26,
       0,     0,    27,     0,     0,    28,     0,     0,    17,     0,
       7,    20,     0,     0,     0,     2,     0,     0,     0,     0,
       0,    24,    24,     0,    24,     0,     0,     0,    39,    43,
      42,     0,     0,    21,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    24,     0,     0,     0,     0,     0,    38,
      37,     0,     0,    53,     0,     0,     0,     0,    15,     0,
       0,    57,     0,     0,     0,     0,     0,     0,    48,     0,
       0,     0,    32,    29,     0,    31,     0,    46,    49,    50,
      52,    44,     0,    40,    33,    34,    35,    36,    64,    59,
      58,    61,    60,    62,    63,    56,    55,     0,     0,    45,
      41,     0,    30,     0,    54
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     7,    13,    30,    14,    15,    21,    23,    33,
      40,    34,    46,    47,    48,    86,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    87
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -69
static const yytype_int16 yypact[] =
{
     -26,    18,    28,    38,   -69,    48,   -69,    78,   -69,   -69,
       1,   -12,    73,   -69,    42,   -69,    70,   -69,   -69,   127,
      76,    35,    66,    16,   -69,   113,   -69,   114,   -69,   -69,
     135,   128,   130,   -69,    -8,   138,   153,   -69,   150,   -69,
     104,   154,   160,   -69,   171,    14,   -69,   -69,   167,   -69,
     178,   175,   -69,   176,   170,   -69,   179,    57,   -69,   155,
     -69,   -69,   159,    50,   161,   -69,    57,    57,   162,    57,
     181,   -69,   -69,    50,   -69,    57,    57,    57,   -10,   -69,
     -69,   152,   180,   -69,    50,    50,    94,   -14,   187,   107,
     122,   172,   132,   -69,    24,    31,   142,    54,   158,    86,
      86,    57,   164,   -69,    57,    57,    57,    57,   -69,    75,
     144,   -69,    57,    57,    57,    57,    57,    57,   -69,    50,
      50,    57,   -69,   -69,    57,   -69,    61,   192,   -69,   -69,
     -69,   -69,   118,   -69,    86,    86,   -69,   -69,   -69,   112,
     112,   112,   112,   112,   112,   -69,   177,    90,   136,   -69,
     -69,   165,   -69,   190,   -69
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -69,   -69,   -69,   -69,   -69,   -69,   183,   -69,   -69,   -69,
     -69,   -48,   -69,   -69,   -69,   -57,   -69,   -69,   -69,   -69,
     -69,   -69,   -69,   -69,   -69,   -68
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -48
static const yytype_int16 yytable[] =
{
      81,    41,    17,    42,    43,    96,   101,    44,   118,    89,
      90,     1,    92,   102,   119,   120,   110,   111,    98,    99,
     100,     8,     9,    94,    95,    18,    97,   109,     4,    45,
      66,    31,     3,    41,    67,    42,    43,    68,    16,   127,
      41,     5,    42,    43,   132,   126,   128,   134,   135,   136,
     137,   145,   146,    26,    27,   139,   140,   141,   142,   143,
     144,    45,     6,    41,   147,    42,    43,   148,    45,   130,
      41,    84,    42,    43,    76,    77,   149,    19,    75,    20,
      85,    76,    77,     8,     9,    10,    11,    78,    79,    80,
      22,    45,    25,    12,    78,    79,    80,   131,    45,   104,
     105,   106,   107,   151,    28,    29,   112,   113,   114,   115,
     116,   117,   106,   107,   104,   105,   106,   107,   104,   105,
     106,   107,    61,    62,   122,   112,   113,   114,   115,   116,
     117,   104,   105,   106,   107,   150,   104,   105,   106,   107,
     123,    24,   104,   105,   106,   107,   104,   105,   106,   107,
     125,    36,    35,    37,   152,    58,   104,   105,   106,   107,
     104,   105,   106,   107,   129,    38,   138,    39,    60,    59,
     119,   120,   119,   120,   103,    63,   104,   105,   106,   107,
     131,    64,   104,   105,   106,   107,    65,    69,    70,    71,
      72,    73,   124,    74,    82,    93,    83,   108,    88,    91,
     121,   133,   -47,   154,   153,   119,    32
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-69)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_uint8 yycheck[] =
{
      57,     9,    14,    11,    12,    73,    16,    15,    22,    66,
      67,    37,    69,    23,    28,    29,    84,    85,    75,    76,
      77,     5,     6,    71,    72,    37,    74,    84,     0,    37,
      16,    15,    14,     9,    20,    11,    12,    23,    37,    15,
       9,     3,    11,    12,   101,    93,    15,   104,   105,   106,
     107,   119,   120,    18,    19,   112,   113,   114,   115,   116,
     117,    37,    14,     9,   121,    11,    12,   124,    37,    15,
       9,    21,    11,    12,    24,    25,    15,     4,    21,    37,
      30,    24,    25,     5,     6,     7,     8,    37,    38,    39,
      20,    37,    16,    15,    37,    38,    39,    22,    37,    24,
      25,    26,    27,    13,    38,    39,    31,    32,    33,    34,
      35,    36,    26,    27,    24,    25,    26,    27,    24,    25,
      26,    27,    18,    19,    17,    31,    32,    33,    34,    35,
      36,    24,    25,    26,    27,    17,    24,    25,    26,    27,
      18,    14,    24,    25,    26,    27,    24,    25,    26,    27,
      18,    37,    39,    18,    18,    17,    24,    25,    26,    27,
      24,    25,    26,    27,    22,    37,    22,    37,    18,    16,
      28,    29,    28,    29,    22,    21,    24,    25,    26,    27,
      22,    21,    24,    25,    26,    27,    15,    20,    10,    14,
      14,    21,    20,    14,    39,    14,    37,    17,    37,    37,
      13,    37,    10,    13,    39,    28,    23
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    37,    41,    14,     0,     3,    14,    42,     5,     6,
       7,     8,    15,    43,    45,    46,    37,    14,    37,     4,
      37,    47,    20,    48,    14,    16,    18,    19,    38,    39,
      44,    15,    46,    49,    51,    39,    37,    18,    37,    37,
      50,     9,    11,    12,    15,    37,    52,    53,    54,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    17,    16,
      18,    18,    19,    21,    21,    15,    16,    20,    23,    20,
      10,    14,    14,    21,    14,    21,    24,    25,    37,    38,
      39,    55,    39,    37,    21,    30,    55,    65,    37,    55,
      55,    37,    55,    14,    51,    51,    65,    51,    55,    55,
      55,    16,    23,    22,    24,    25,    26,    27,    17,    55,
      65,    65,    31,    32,    33,    34,    35,    36,    22,    28,
      29,    13,    17,    18,    20,    18,    51,    15,    15,    22,
      15,    22,    55,    37,    55,    55,    55,    55,    22,    55,
      55,    55,    55,    55,    55,    65,    65,    55,    55,    15,
      17,    13,    18,    39,    13
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

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
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
  FILE *yyo = yyoutput;
  YYUSE (yyo);
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
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




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

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

       Refer to the stacks through separate pointers, to allow yyoverflow
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
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
  if (yypact_value_is_default (yyn))
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
      if (yytable_value_is_error (yyn))
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
/* Line 1792 of yacc.c  */
#line 41 "ra.y"
    {Inserer_Element_TS1((yyvsp[(1) - (11)].nom), 99, "p", "p"); YYACCEPT;}
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 49 "ra.y"
    {   
        MAJ_TS1(type);
    }
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 53 "ra.y"
    {      
        if(!Double_Declaration_Entite((yyvsp[(2) - (5)].nom))) {

            Inserer_Element_TS1((yyvsp[(2) - (5)].nom), 0, type, valeur);
        }
    }
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 60 "ra.y"
    {
        if(!Double_Declaration_Structure((yyvsp[(5) - (6)].nom))) {

            Inserer_Element_TS2((yyvsp[(5) - (6)].nom));
            MAJ_TS2((yyvsp[(5) - (6)].nom), Liste);
        }

        Liste = NULL;
    }
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 71 "ra.y"
    {
            type = Allouer_Char(8);
            valeur = Allouer_Char(strlen((yyvsp[(1) - (1)].nom)));
            strcpy(type, "INTEGER");
            strcpy(valeur, (yyvsp[(1) - (1)].nom));
        }
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 78 "ra.y"
    {   
            type = Allouer_Char(6);
            valeur = Allouer_Char(strlen((yyvsp[(1) - (1)].nom)));
            strcpy(type, "FLOAT");
            strcpy(valeur, (yyvsp[(1) - (1)].nom));
        }
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 88 "ra.y"
    {
        if(!Structure_Non_Declare((yyvsp[(2) - (2)].nom))) { 
        
            type = Allouer_Char(strlen((yyvsp[(2) - (2)].nom)));
            strcpy(type, (yyvsp[(2) - (2)].nom));
        }
    }
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 96 "ra.y"
    {type = Allouer_Char(8); strcpy(type, "INTEGER");}
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 97 "ra.y"
    {type = Allouer_Char(6); strcpy(type, "FLOAT");}
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 101 "ra.y"
    {   
            if(!Double_Declaration_Entite((yyvsp[(3) - (3)].nom))) {          
                Inserer_Element_TS1((yyvsp[(3) - (3)].nom), 1, "#", "#");
            }
        }
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 107 "ra.y"
    {
           if(!Double_Declaration_Entite((yyvsp[(3) - (6)].nom))) {      
                if(!Taille_Negative((yyvsp[(3) - (6)].nom), atoi((yyvsp[(5) - (6)].nom)))) {
                    Inserer_Element_TS1((yyvsp[(3) - (6)].nom), 2, "#", (yyvsp[(5) - (6)].nom));
                }
           }
        }
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 115 "ra.y"
    {
            if(!Double_Declaration_Entite((yyvsp[(1) - (1)].nom))) {      
                Inserer_Element_TS1((yyvsp[(1) - (1)].nom), 1, "#", "#");
            }
        }
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 121 "ra.y"
    {
            if(!Double_Declaration_Entite((yyvsp[(1) - (4)].nom))) {    
                if(!Taille_Negative((yyvsp[(1) - (4)].nom), atoi((yyvsp[(3) - (4)].nom)))) {  
                    Inserer_Element_TS1((yyvsp[(1) - (4)].nom), 2, "#", (yyvsp[(3) - (4)].nom));
                }
            }
        }
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 134 "ra.y"
    {
                MAJ_Liste_Element_Struct(Liste, type);
            }
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 140 "ra.y"
    {
                    if(!Double_Declaration_Entite_Structure(Liste, (yyvsp[(3) - (3)].nom))) {
                        Inserer_Element(&Liste, (yyvsp[(3) - (3)].nom), "#");
                    }
                }
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 146 "ra.y"
    {
                    if(!Double_Declaration_Entite_Structure(Liste, (yyvsp[(1) - (1)].nom))) {
                        Inserer_Element(&Liste, (yyvsp[(1) - (1)].nom), "#");
                    }
                }
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 165 "ra.y"
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
        }
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 181 "ra.y"
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
        }
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 197 "ra.y"
    {   
            if(nom_idf != NULL) {

                if(strcmp(Get_Idf_Type(nom_idf), "INTEGER") == 0) {
                    Empiler_Type(0);    
                }
                else {
                    Empiler_Type(1);
                }
                Traitement_Types();
                Incompatibilite_Types_Tab(nom_idf);

                Affectation_QUAD(Case_Tab(nom_idf, temp), "");
                nom_idf = NULL;
            }          
            
        }
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 216 "ra.y"
    {
        if(!Entite_Non_Declare((yyvsp[(1) - (4)].nom))) {      
            if(!Est_Une_Constante((yyvsp[(1) - (4)].nom))) {
                if(Est_Un_Tableau((yyvsp[(1) - (4)].nom))) {
                    
                    nom_idf = Allouer_Char(strlen((yyvsp[(1) - (4)].nom)));
                    strcpy(nom_idf, (yyvsp[(1) - (4)].nom));

                    Empiler_Type(0);
                    Traitement_Types();
                    Incompatibilite_Types_Index((yyvsp[(1) - (4)].nom));

                    Depiler(temp);
                }    
            }
        }
    }
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 235 "ra.y"
    {   
        Addition_QUAD("", "");     
        Traitement_Types();
        div_par_zero = false;
    }
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 241 "ra.y"
    {
        Soustraction_QUAD("", ""); 
        Traitement_Types();
        div_par_zero = false;
    }
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 247 "ra.y"
    {   
        Division_QUAD("", ""); 
        Division_Par_Zero(div_par_zero);
        Traitement_Types();
        div_par_zero = false;
    }
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 254 "ra.y"
    {   
        Multiplication_QUAD("", ""); 
        Traitement_Types();
        div_par_zero = false;
        
    }
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 261 "ra.y"
    {
        Moins_QUAD("");
        div_par_zero = false;
    }
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 266 "ra.y"
    {
        Plus_QUAD("");
        div_par_zero = false;
    }
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 271 "ra.y"
    {   
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
    }
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 284 "ra.y"
    {   
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
    }
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 298 "ra.y"
    {
        if(!Entite_Non_Declare((yyvsp[(1) - (4)].nom))) {
            if(Est_Un_Tableau((yyvsp[(1) - (4)].nom))) {  

                Empiler_Type(0);
                Traitement_Types();
                Incompatibilite_Types_Index((yyvsp[(1) - (4)].nom));

                if(strcmp(Get_Idf_Type((yyvsp[(1) - (4)].nom)), "INTEGER") == 0) {
                    Empiler_Type(0);    
                }
                else {
                    Empiler_Type(1);
                }
            }
        }

        char temp[20];
        Depiler(temp);
        Affectation_QUAD("", Case_Tab((yyvsp[(1) - (4)].nom),temp));
    }
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 320 "ra.y"
    {   
        Empiler_Type(0);
        Affectation_QUAD("", (yyvsp[(1) - (1)].nom));
        if(atoi((yyvsp[(1) - (1)].nom)) == 0) {
            div_par_zero = true;
        }
    }
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 328 "ra.y"
    {
        Empiler_Type(1);
        Affectation_QUAD("", (yyvsp[(1) - (1)].nom));
        if(atof((yyvsp[(1) - (1)].nom)) == 0) {
            div_par_zero = true;
        }
    }
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 338 "ra.y"
    {Routine_If_Apres_Inst2();}
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 339 "ra.y"
    {Routine_If_Apres_Inst2();}
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 341 "ra.y"
    {Routine_If_Apres_Inst1();}
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 343 "ra.y"
    {Routine_If_Apres_Cond(); }
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 346 "ra.y"
    {Routine_While_Apres_Inst();}
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 348 "ra.y"
    {Routine_While_Apres_Cond();}
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 350 "ra.y"
    {Routine_While_Avant_Cond();}
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 353 "ra.y"
    {Routine_For_Apres_Inst();}
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 355 "ra.y"
    {Routine_For_Apres_Cond();}
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 357 "ra.y"
    {Routine_For_Apres_Init((yyvsp[(3) - (8)].nom), (yyvsp[(7) - (8)].nom));}
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 359 "ra.y"
    {Or_QUAD();}
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 360 "ra.y"
    {And_QUAD();}
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 361 "ra.y"
    {Not_Quad();}
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 362 "ra.y"
    {Inf_QUAD();}
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 363 "ra.y"
    {Sup_QUAD();}
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 364 "ra.y"
    {Inf_Egal_QUAD();}
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 365 "ra.y"
    {Sup_Egal_QUAD();}
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 366 "ra.y"
    {Egal_Egal_QUAD();}
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 367 "ra.y"
    {Non_Egal_QUAD();}
    break;


/* Line 1792 of yacc.c  */
#line 2035 "ra.tab.c"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
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
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
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
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
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
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
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


/* Line 2055 of yacc.c  */
#line 372 "ra.y"

int yyerror(char* msg){
    printf("%s : line %d, col %d \n", msg, line, col);
    exit(0);
    return 1;
}
int main() {
    yydebug=0;
    yyin = fopen("in.txt", "r");
    yyparse();
    if(nb_erreurs > 0) {
        exit(1);
    }
    Afficher_TS1();
    Afficher_TS2();
    Afficher_QUAD();
    
    Optim();
    printf("Optimisation...\n");
    printf("------------------------Apres Optimisation-------------------\n");
    Afficher_QUAD(); 
    
    Generer();

    fclose(yyin);
    return 0;
}