/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */

#include <stdio.h>	
#include "ast.h"
#define YYSTYPE struct ASTNode *

#line 72 "parser.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
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
   by #include "parser.tab.h".  */
#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    id = 258,
    class_def = 259,
    prog = 260,
    char_lit = 261,
    str_lit = 262,
    dec = 263,
    hex = 264,
    true = 265,
    false = 266,
    lt = 267,
    le = 268,
    gt = 269,
    ge = 270,
    eq = 271,
    ass = 272,
    not = 273,
    neq = 274,
    or = 275,
    and = 276,
    int_type = 277,
    void_type = 278,
    bool_type = 279,
    if_keyword = 280,
    for_keyword = 281,
    return_keyword = 282,
    break_keyword = 283,
    continue_keyword = 284,
    else_keyword = 285,
    pe = 286,
    me = 287,
    callout_keyword = 288
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 157 "parser.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
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
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

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
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   370

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  92
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  161

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   288

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    38,     2,     2,
      45,    46,    36,    34,    44,    35,     2,    37,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    41,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    42,     2,    43,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    39,     2,    40,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    32,    32,    33,    36,    40,    44,    50,    54,    60,
      66,    70,    74,    78,    83,    87,    93,    97,   101,   105,
     111,   115,   121,   127,   131,   137,   141,   145,   151,   155,
     161,   165,   171,   177,   181,   187,   191,   197,   201,   205,
     209,   213,   217,   221,   225,   229,   233,   239,   243,   247,
     253,   257,   261,   265,   271,   275,   281,   285,   290,   294,
     300,   304,   308,   312,   316,   320,   326,   332,   336,   343,
     347,   351,   355,   361,   365,   369,   373,   377,   383,   387,
     391,   395,   401,   405,   411,   415,   421,   425,   429,   435,
     439,   445,   449
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "id", "class_def", "prog", "char_lit",
  "str_lit", "dec", "hex", "true", "false", "lt", "le", "gt", "ge", "eq",
  "ass", "not", "neq", "or", "and", "int_type", "void_type", "bool_type",
  "if_keyword", "for_keyword", "return_keyword", "break_keyword",
  "continue_keyword", "else_keyword", "pe", "me", "callout_keyword", "'+'",
  "'-'", "'*'", "'/'", "'%'", "'{'", "'}'", "';'", "'['", "']'", "','",
  "'('", "')'", "$accept", "program", "fields", "field_decls",
  "field_decl", "list_id", "method_decls", "method_decl", "inputs",
  "input", "block", "block_parts", "var_declarations", "statements",
  "var_declaration", "ids", "type", "statement", "assign_op",
  "method_call", "callout_args", "location", "exprs", "expr",
  "method_name", "callout_arg", "bin_op", "arith_op", "rel_op", "eq_op",
  "cond_op", "literal", "int_literal", "bool_literal", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,    43,    45,    42,    47,    37,   123,
     125,    59,    91,    93,    44,    40,    41
};
# endif

#define YYPACT_NINF -57

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-57)))

#define YYTABLE_NINF -67

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       7,    18,    39,    13,   -57,    20,   -57,    45,   -57,   -57,
      27,    57,    60,    57,   -57,    83,    55,   -57,    69,    57,
     -57,   -57,   101,   -39,    70,   -10,   -57,    66,    10,     0,
     110,    76,     1,   -57,   114,   -57,   -57,    75,    76,     9,
      77,   105,   -57,    73,    76,   -57,   -57,   -57,    76,    10,
      -5,    80,   117,    53,    94,    95,    96,   -57,   -57,    82,
     125,   134,    98,   118,   -57,    99,    34,    97,   -57,   -57,
     -57,   100,    81,    81,   129,   -57,   -57,   -57,   -57,    81,
      81,   -57,    81,   255,   -57,   -57,   -57,   -57,   -57,   141,
     -57,   134,   115,   -57,   -57,   -57,   111,   -57,   -57,   -57,
     -57,    81,    23,   -57,   223,   156,    81,    62,   332,   184,
     -57,   -57,   -57,   -57,   -57,   -57,   -57,   -57,   -57,   -57,
     -57,   -57,   -57,   -57,    81,   -57,   -57,   -57,   -57,    59,
     -57,   154,   265,   -57,    63,   305,   -57,    76,   212,   -57,
     305,    67,   -57,   -57,   -57,    81,   -57,   135,    81,   -57,
     120,   305,   130,   305,    76,   295,   -57,    67,   -57,   -57,
     -57
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,    35,     0,    36,     2,
       0,     4,     0,     5,    15,     0,     0,     3,     0,     6,
       8,    14,     0,    10,     9,     0,     7,     0,     0,     0,
       0,     0,     0,    20,     0,    89,    90,     0,     0,     0,
      12,     0,    18,     0,     0,    22,    11,    16,     0,     0,
      56,     0,     0,     0,     0,     0,     0,    24,    46,     0,
      27,    26,     0,     0,    30,     0,     0,     0,    21,    19,
      17,     0,     0,     0,     0,    61,    87,    91,    92,     0,
       0,    42,     0,     0,    60,    86,    88,    44,    45,     0,
      23,    25,     0,    31,    28,    33,    32,    38,    47,    48,
      49,     0,     0,    13,     0,     0,     0,    63,    64,     0,
      79,    81,    78,    80,    82,    83,    85,    84,    73,    74,
      75,    76,    77,    43,     0,    69,    70,    71,    72,     0,
      29,     0,     0,    50,     0,    58,    57,     0,     0,    62,
      65,     0,    52,    34,    37,     0,    51,    39,     0,    68,
       0,    67,    55,    59,     0,     0,    53,     0,    40,    41,
      54
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -57,   -57,   -57,   -57,   167,   -57,   168,    -4,   151,   138,
     -31,   -57,   -57,   122,   123,   -57,    -3,   -56,   -57,   -57,
      28,   -57,   -57,   -52,   -57,   -57,   -57,   -57,   -57,   -57,
     -57,   -57,   -24,   -57
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    10,    11,    12,    24,    13,    14,    32,    33,
      58,    59,    60,    61,    62,    96,    34,    64,   101,    65,
     150,    66,   134,   151,    67,   152,   124,   125,   126,   127,
     128,    84,    85,    86
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      42,    83,    15,    28,    37,    93,    29,    47,    15,    21,
      22,     1,     6,    69,     8,    21,    22,    70,    35,    36,
     104,   105,     6,     3,     8,    71,    75,   107,   108,    76,
     109,    35,    36,    77,    78,    93,    31,    72,    63,     4,
     -66,    79,     6,     7,     8,    43,    38,    44,    16,   132,
     135,    98,     5,    43,   138,    48,    75,    63,    80,    76,
       9,    35,    36,    77,    78,    99,   100,    17,    82,   133,
      75,    79,   140,    76,   149,    35,    36,    77,    78,     6,
       7,     8,   116,   117,    75,    79,    23,    76,    80,    35,
      36,    77,    78,   153,    81,     6,   155,     8,    82,    79,
      25,    20,    80,   141,    27,   142,   147,   145,    50,   146,
      26,    29,    82,    40,    30,    41,    80,    45,    46,    49,
      74,    95,    90,   158,   159,    73,    82,     6,    50,     8,
      51,    52,    53,    54,    55,    87,    88,    50,    56,    94,
      97,    89,   102,   103,    41,    57,   106,     6,   129,     8,
      51,    52,    53,    54,    55,   131,   130,   143,    56,    51,
      52,    53,    54,    55,    41,   154,   156,    56,   110,   111,
     112,   113,   114,    41,   157,   115,   116,   117,    18,    19,
      39,    68,    91,    92,     0,   160,     0,     0,     0,     0,
     118,   119,   120,   121,   122,     0,   110,   111,   112,   113,
     114,     0,   137,   115,   116,   117,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   118,   119,
     120,   121,   122,     0,   110,   111,   112,   113,   114,     0,
     139,   115,   116,   117,     0,   110,   111,   112,   113,   114,
       0,     0,   115,   116,   117,     0,   118,   119,   120,   121,
     122,     0,     0,     0,     0,     0,   148,   118,   119,   120,
     121,   122,     0,     0,     0,     0,   136,   110,   111,   112,
     113,   114,     0,     0,   115,   116,   117,   110,   111,   112,
     113,   114,     0,     0,   115,   116,   117,     0,     0,   118,
     119,   120,   121,   122,     0,     0,   123,     0,     0,   118,
     119,   120,   121,   122,     0,     0,   144,   110,   111,   112,
     113,   114,     0,     0,   115,   116,   117,   110,   111,   112,
     113,   114,     0,     0,   115,   116,   117,     0,     0,   118,
     119,   120,   121,   122,    41,     0,     0,     0,     0,   118,
     119,   120,   121,   122,   110,   111,   112,   113,     0,     0,
       0,   115,   116,   117,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   120,   121,
     122
};

static const yytype_int16 yycheck[] =
{
      31,    53,     5,    42,    28,    61,    45,    38,    11,    13,
      13,     4,    22,    44,    24,    19,    19,    48,     8,     9,
      72,    73,    22,     5,    24,    49,     3,    79,    80,     6,
      82,     8,     9,    10,    11,    91,    46,    42,    41,     0,
      45,    18,    22,    23,    24,    44,    46,    46,     3,   101,
     102,    17,    39,    44,   106,    46,     3,    60,    35,     6,
      40,     8,     9,    10,    11,    31,    32,    40,    45,    46,
       3,    18,   124,     6,     7,     8,     9,    10,    11,    22,
      23,    24,    20,    21,     3,    18,     3,     6,    35,     8,
       9,    10,    11,   145,    41,    22,   148,    24,    45,    18,
      45,    41,    35,    44,     3,    46,   137,    44,     3,    46,
      41,    45,    45,     3,    44,    39,    35,     3,    43,    42,
       3,     3,    40,   154,   155,    45,    45,    22,     3,    24,
      25,    26,    27,    28,    29,    41,    41,     3,    33,    41,
      41,    45,    45,    43,    39,    40,    17,    22,     7,    24,
      25,    26,    27,    28,    29,    44,    41,     3,    33,    25,
      26,    27,    28,    29,    39,    30,    46,    33,    12,    13,
      14,    15,    16,    39,    44,    19,    20,    21,    11,    11,
      29,    43,    60,    60,    -1,   157,    -1,    -1,    -1,    -1,
      34,    35,    36,    37,    38,    -1,    12,    13,    14,    15,
      16,    -1,    46,    19,    20,    21,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    35,
      36,    37,    38,    -1,    12,    13,    14,    15,    16,    -1,
      46,    19,    20,    21,    -1,    12,    13,    14,    15,    16,
      -1,    -1,    19,    20,    21,    -1,    34,    35,    36,    37,
      38,    -1,    -1,    -1,    -1,    -1,    44,    34,    35,    36,
      37,    38,    -1,    -1,    -1,    -1,    43,    12,    13,    14,
      15,    16,    -1,    -1,    19,    20,    21,    12,    13,    14,
      15,    16,    -1,    -1,    19,    20,    21,    -1,    -1,    34,
      35,    36,    37,    38,    -1,    -1,    41,    -1,    -1,    34,
      35,    36,    37,    38,    -1,    -1,    41,    12,    13,    14,
      15,    16,    -1,    -1,    19,    20,    21,    12,    13,    14,
      15,    16,    -1,    -1,    19,    20,    21,    -1,    -1,    34,
      35,    36,    37,    38,    39,    -1,    -1,    -1,    -1,    34,
      35,    36,    37,    38,    12,    13,    14,    15,    -1,    -1,
      -1,    19,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    37,
      38
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,    48,     5,     0,    39,    22,    23,    24,    40,
      49,    50,    51,    53,    54,    63,     3,    40,    51,    53,
      41,    54,    63,     3,    52,    45,    41,     3,    42,    45,
      44,    46,    55,    56,    63,     8,     9,    79,    46,    55,
       3,    39,    57,    44,    46,     3,    43,    57,    46,    42,
       3,    25,    26,    27,    28,    29,    33,    40,    57,    58,
      59,    60,    61,    63,    64,    66,    68,    71,    56,    57,
      57,    79,    42,    45,     3,     3,     6,    10,    11,    18,
      35,    41,    45,    70,    78,    79,    80,    41,    41,    45,
      40,    60,    61,    64,    41,     3,    62,    41,    17,    31,
      32,    65,    45,    43,    70,    70,    17,    70,    70,    70,
      12,    13,    14,    15,    16,    19,    20,    21,    34,    35,
      36,    37,    38,    41,    73,    74,    75,    76,    77,     7,
      41,    44,    70,    46,    69,    70,    43,    46,    70,    46,
      70,    44,    46,     3,    41,    44,    46,    57,    44,     7,
      67,    70,    72,    70,    30,    70,    46,    44,    57,    57,
      67
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    47,    48,    48,    49,    49,    49,    50,    50,    51,
      52,    52,    52,    52,    53,    53,    54,    54,    54,    54,
      55,    55,    56,    57,    57,    58,    58,    58,    59,    59,
      60,    60,    61,    62,    62,    63,    63,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    65,    65,    65,
      66,    66,    66,    66,    67,    67,    68,    68,    69,    69,
      70,    70,    70,    70,    70,    70,    71,    72,    72,    73,
      73,    73,    73,    74,    74,    74,    74,    74,    75,    75,
      75,    75,    76,    76,    77,    77,    78,    78,    78,    79,
      79,    80,    80
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     5,     1,     1,     2,     3,     2,     2,
       1,     4,     3,     6,     2,     1,     5,     6,     5,     6,
       1,     3,     2,     3,     2,     2,     1,     1,     2,     3,
       1,     2,     2,     1,     3,     1,     1,     4,     2,     5,
       7,     7,     2,     3,     2,     2,     1,     1,     1,     1,
       3,     4,     4,     6,     3,     1,     1,     4,     1,     3,
       1,     1,     3,     2,     2,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
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

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

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
      yychar = yylex ();
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
     '$$ = $1'.

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
#line 32 "parser.y" /* yacc.c:1646  */
    {(yyval) = getASTUnaryNode(getASTNodeNONE(),PROG_TYPE);printPostFix((yyval));printf("\n");return 0;}
#line 1395 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 33 "parser.y" /* yacc.c:1646  */
    { (yyval) = getASTUnaryNode((yyvsp[-1]),PROG_TYPE); printPostFix((yyval));printf("\n");return 0;}
#line 1401 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 37 "parser.y" /* yacc.c:1646  */
    {
		(yyval)=getASTNodeBinaryNode((yyvsp[0]),getASTNodeNONE(),FIELDS);
		}
#line 1409 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 41 "parser.y" /* yacc.c:1646  */
    {
		(yyval)=getASTNodeBinaryNode(getASTNodeNONE(),(yyvsp[0]),FIELDS);
		}
#line 1417 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 45 "parser.y" /* yacc.c:1646  */
    {
		(yyval)=getASTNodeBinaryNode((yyvsp[-1]),(yyvsp[0]),FIELDS);
		}
#line 1425 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 51 "parser.y" /* yacc.c:1646  */
    {
			(yyval)=getASTNodeBinaryNode((yyvsp[-2]),(yyvsp[-1]),FIELD_DECLS);
			}
#line 1433 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 55 "parser.y" /* yacc.c:1646  */
    {
			(yyval)=getASTNodeBinaryNode((yyvsp[-1]),getASTNodeNONE(),FIELD_DECLS);
			}
#line 1441 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 61 "parser.y" /* yacc.c:1646  */
    {
			(yyval)=getASTNodeBinaryNode((yyvsp[-1]),(yyvsp[0]),FIELD_DECL);
			}
#line 1449 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 67 "parser.y" /* yacc.c:1646  */
    {
			(yyval)=getASTNodeTernaryNode(getASTUnaryNode(getASTNodeNONE(),ID),getASTNodeNONE(),getASTNodeNONE(),LIST_ID);
			}
#line 1457 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 71 "parser.y" /* yacc.c:1646  */
    {
			(yyval)=getASTNodeTernaryNode(getASTUnaryNode(getASTNodeNONE(),ID),(yyvsp[-1]),getASTNodeNONE(),LIST_ID);
			}
#line 1465 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 75 "parser.y" /* yacc.c:1646  */
    {
			(yyval)=getASTNodeTernaryNode((yyvsp[-2]),getASTUnaryNode(getASTNodeNONE(),ID),getASTNodeNONE(),LIST_ID);
			}
#line 1473 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 79 "parser.y" /* yacc.c:1646  */
    {
			(yyval)=getASTNodeTernaryNode((yyvsp[-5]),getASTUnaryNode(getASTNodeNONE(),ID),(yyvsp[-1]),LIST_ID);
			}
#line 1481 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 84 "parser.y" /* yacc.c:1646  */
    {
		    	(yyval)=getASTNodeBinaryNode((yyvsp[-1]),(yyvsp[0]),METHOD_DECLS);
			   }
#line 1489 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 88 "parser.y" /* yacc.c:1646  */
    {
				(yyval)=getASTNodeBinaryNode((yyvsp[0]),getASTNodeNONE(),METHOD_DECLS);
				}
#line 1497 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 94 "parser.y" /* yacc.c:1646  */
    {
			  (yyval)=getASTNodeQuaternaryNode((yyvsp[-4]),getASTUnaryNode(getASTNodeNONE(),ID),(yyvsp[0]),getASTNodeNONE(),METHOD_DECL);
			  }
#line 1505 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 98 "parser.y" /* yacc.c:1646  */
    {
			  (yyval)=getASTNodeQuaternaryNode((yyvsp[-5]),getASTUnaryNode(getASTNodeNONE(),ID),(yyvsp[-2]),(yyvsp[0]),METHOD_DECL);
			  }
#line 1513 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 102 "parser.y" /* yacc.c:1646  */
    {
			  (yyval)=getASTNodeTernaryNode(getASTUnaryNode(getASTNodeNONE(),ID),(yyvsp[0]),getASTNodeNONE(),VOID_METHOD_DECL);
			  }
#line 1521 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 106 "parser.y" /* yacc.c:1646  */
    {
			  (yyval)=getASTNodeTernaryNode(getASTUnaryNode(getASTNodeNONE(),ID),(yyvsp[-2]),(yyvsp[0]),VOID_METHOD_DECL);
			  }
#line 1529 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 112 "parser.y" /* yacc.c:1646  */
    {
		(yyval)=getASTNodeBinaryNode((yyvsp[0]),getASTNodeNONE(),INPUTS);
		}
#line 1537 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 116 "parser.y" /* yacc.c:1646  */
    {
		(yyval)=getASTNodeBinaryNode((yyvsp[-2]),(yyvsp[-1]),INPUTS);
		}
#line 1545 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 122 "parser.y" /* yacc.c:1646  */
    {
		(yyval)=getASTNodeBinaryNode((yyvsp[-1]),getASTUnaryNode(getASTNodeNONE(),ID),INPUT);
		}
#line 1553 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 128 "parser.y" /* yacc.c:1646  */
    {
		(yyval)=getASTUnaryNode((yyvsp[-1]),BLOCK);
		}
#line 1561 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 132 "parser.y" /* yacc.c:1646  */
    {
		(yyval)=getASTUnaryNode(getASTNodeNONE(),BLOCK);
		}
#line 1569 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 138 "parser.y" /* yacc.c:1646  */
    {
			(yyval)=getASTNodeBinaryNode((yyvsp[-1]),(yyvsp[0]),BLOCK_PARTS);
			}
#line 1577 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 142 "parser.y" /* yacc.c:1646  */
    {
			(yyval)=getASTNodeBinaryNode((yyvsp[0]),getASTNodeNONE(),BLOCK_PARTS);
			}
#line 1585 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 146 "parser.y" /* yacc.c:1646  */
    {
			(yyval)=getASTNodeBinaryNode(getASTNodeNONE(),(yyvsp[0]),BLOCK_PARTS);
			}
#line 1593 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 152 "parser.y" /* yacc.c:1646  */
    {
						(yyval)=getASTNodeBinaryNode((yyvsp[-1]),getASTNodeNONE(),VAR_DECLS);
					}
#line 1601 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 156 "parser.y" /* yacc.c:1646  */
    {
				 		(yyval)=getASTNodeBinaryNode((yyvsp[-2]),(yyvsp[-1]),VAR_DECLS);
				 	}
#line 1609 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 162 "parser.y" /* yacc.c:1646  */
    {
				(yyval)=getASTNodeBinaryNode((yyvsp[0]),getASTNodeNONE(),STMTS);
			}
#line 1617 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 166 "parser.y" /* yacc.c:1646  */
    {
				(yyval)=getASTNodeBinaryNode((yyvsp[-1]),(yyvsp[0]),STMTS);
			}
#line 1625 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 172 "parser.y" /* yacc.c:1646  */
    {
					(yyval)=getASTNodeBinaryNode((yyvsp[-1]),(yyvsp[0]),VAR_DECL);
				}
#line 1633 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 178 "parser.y" /* yacc.c:1646  */
    {
		(yyval)=getASTUnaryNode(getASTNodeNONE(),ID);
	}
#line 1641 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 182 "parser.y" /* yacc.c:1646  */
    {
		(yyval)=getASTNodeBinaryNode((yyvsp[-2]),getASTUnaryNode(getASTNodeNONE(),ID),IDS);
	}
#line 1649 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 188 "parser.y" /* yacc.c:1646  */
    {
				(yyval)=getASTUnaryNode(getASTNodeNONE(),INT_TYPE);
			}
#line 1657 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 192 "parser.y" /* yacc.c:1646  */
    {
				(yyval)=getASTUnaryNode(getASTNodeNONE(),BOOL_TYPE);
			}
#line 1665 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 198 "parser.y" /* yacc.c:1646  */
    {
				(yyval)=getASTNodeTernaryNode((yyvsp[-3]),(yyvsp[-2]),(yyvsp[-1]),STMT);
			}
#line 1673 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 202 "parser.y" /* yacc.c:1646  */
    {
				(yyval)=getASTNodeTernaryNode((yyvsp[-1]),getASTNodeNONE(),getASTNodeNONE(),STMT);
			}
#line 1681 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 206 "parser.y" /* yacc.c:1646  */
    {
				(yyval)=getASTNodeTernaryNode((yyvsp[-2]),(yyvsp[0]),getASTNodeNONE(),STMT_IF);
			}
#line 1689 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 210 "parser.y" /* yacc.c:1646  */
    {
				(yyval)=getASTNodeTernaryNode((yyvsp[-4]),(yyvsp[-2]),(yyvsp[0]),STMT_IF_ELSE);
			}
#line 1697 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 214 "parser.y" /* yacc.c:1646  */
    {
				(yyval)=getASTNodePentnaryNode(getASTUnaryNode(getASTNodeNONE(),ID),(yyvsp[-4]),(yyvsp[-3]),(yyvsp[-1]),(yyvsp[0]),FOR);
			}
#line 1705 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 218 "parser.y" /* yacc.c:1646  */
    {
				(yyval)=getASTNodeBinaryNode(getASTUnaryNode(getASTNodeNONE(),RET),getASTNodeNONE(),RETURN);
			}
#line 1713 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 222 "parser.y" /* yacc.c:1646  */
    {
				(yyval)=getASTNodeBinaryNode(getASTUnaryNode(getASTNodeNONE(),RET),(yyvsp[-1]),RETURN);
			}
#line 1721 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 226 "parser.y" /* yacc.c:1646  */
    {
				(yyval)=getASTUnaryNode(getASTNodeNONE(),BREAK);
			}
#line 1729 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 230 "parser.y" /* yacc.c:1646  */
    {
				(yyval)=getASTUnaryNode(getASTNodeNONE(),CONT);
			}
#line 1737 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 234 "parser.y" /* yacc.c:1646  */
    {
				(yyval)=getASTUnaryNode(getASTNodeNONE(),BLOCK);
			}
#line 1745 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 240 "parser.y" /* yacc.c:1646  */
    {
				(yyval)=getASTUnaryNode(getASTNodeNONE(),ASS);
			}
#line 1753 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 244 "parser.y" /* yacc.c:1646  */
    {
				(yyval)=getASTUnaryNode(getASTNodeNONE(),PLUS_EQ);
			}
#line 1761 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 248 "parser.y" /* yacc.c:1646  */
    {
				(yyval)=getASTUnaryNode(getASTNodeNONE(),MINUS_EQ);
			}
#line 1769 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 254 "parser.y" /* yacc.c:1646  */
    {
				(yyval)=getASTNodeBinaryNode((yyvsp[-2]),getASTNodeNONE(),METHOD_CALL);
			}
#line 1777 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 258 "parser.y" /* yacc.c:1646  */
    {
				(yyval)=getASTNodeBinaryNode((yyvsp[-3]),(yyvsp[-1]),METHOD_CALL);
			}
#line 1785 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 262 "parser.y" /* yacc.c:1646  */
    {
				(yyval)=getASTNodeTernaryNode(getASTUnaryNode(getASTNodeNONE(),CALLOUT),getASTUnaryNode(getASTNodeNONE(),STR_LIT),getASTNodeNONE(),METHOD_CALL);
			}
#line 1793 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 266 "parser.y" /* yacc.c:1646  */
    {
				(yyval)=getASTNodeTernaryNode(getASTUnaryNode(getASTNodeNONE(),CALLOUT),getASTUnaryNode(getASTNodeNONE(),STR_LIT),(yyvsp[-1]),METHOD_CALL);
			}
#line 1801 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 272 "parser.y" /* yacc.c:1646  */
    {
				(yyval)=getASTNodeBinaryNode((yyvsp[-2]),(yyvsp[0]),CALLOUT_ARGS);
			}
#line 1809 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 276 "parser.y" /* yacc.c:1646  */
    {
				(yyval)=getASTNodeBinaryNode((yyvsp[0]),getASTNodeNONE(),CALLOUT_ARGS);
			}
#line 1817 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 282 "parser.y" /* yacc.c:1646  */
    {
				(yyval)=getASTNodeBinaryNode(getASTUnaryNode(getASTNodeNONE(),ID),getASTNodeNONE(),LOCATION);
			}
#line 1825 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 286 "parser.y" /* yacc.c:1646  */
    {
				(yyval)=getASTNodeBinaryNode(getASTUnaryNode(getASTNodeNONE(),ID),(yyvsp[-1]),LOCATION);
			}
#line 1833 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 291 "parser.y" /* yacc.c:1646  */
    {
				(yyval)=getASTNodeBinaryNode((yyvsp[0]),getASTNodeNONE(),EXPRS);
			}
#line 1841 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 295 "parser.y" /* yacc.c:1646  */
    {
				(yyval)=getASTNodeBinaryNode((yyvsp[-2]),(yyvsp[0]),EXPRS);
			}
#line 1849 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 301 "parser.y" /* yacc.c:1646  */
    {
		 (yyval)=getASTNodeTernaryNode((yyvsp[0]),getASTNodeNONE(),getASTNodeNONE(),EXPR);
	 }
#line 1857 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 305 "parser.y" /* yacc.c:1646  */
    {
   	 	 (yyval)=getASTNodeTernaryNode(getASTUnaryNode(getASTNodeNONE(),ID),getASTNodeNONE(),getASTNodeNONE(),EXPR);
 	 }
#line 1865 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 309 "parser.y" /* yacc.c:1646  */
    {
	 	(yyval)=(yyvsp[-1]);
	 }
#line 1873 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 313 "parser.y" /* yacc.c:1646  */
    {
	 	(yyval)=getASTNodeTernaryNode(getASTUnaryNode(getASTNodeNONE(),NOT),(yyvsp[0]),getASTNodeNONE(),EXPR);
	 }
#line 1881 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 317 "parser.y" /* yacc.c:1646  */
    {
	 	(yyval)=getASTNodeTernaryNode(getASTUnaryNode(getASTNodeNONE(),SUB),(yyvsp[0]),getASTNodeNONE(),EXPR);
	 }
#line 1889 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 321 "parser.y" /* yacc.c:1646  */
    {
	 	(yyval)=getASTNodeTernaryNode((yyvsp[-2]),(yyvsp[-1]),(yyvsp[0]),EXPR);
	 }
#line 1897 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 327 "parser.y" /* yacc.c:1646  */
    {
				(yyval)=getASTUnaryNode(getASTNodeNONE(),ID);
			}
#line 1905 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 333 "parser.y" /* yacc.c:1646  */
    {
				(yyval)=getASTUnaryNode((yyvsp[0]),CALLOUT_ARG);
			}
#line 1913 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 337 "parser.y" /* yacc.c:1646  */
    {
             	(yyval)=getASTUnaryNode(getASTUnaryNode(getASTNodeNONE(),STR_LIT),CALLOUT_ARG);
             }
#line 1921 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 344 "parser.y" /* yacc.c:1646  */
    {
			(yyval)=getASTUnaryNode((yyvsp[0]),BIN_OP);
		}
#line 1929 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 348 "parser.y" /* yacc.c:1646  */
    {
			(yyval)=getASTUnaryNode((yyvsp[0]),BIN_OP);
		}
#line 1937 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 352 "parser.y" /* yacc.c:1646  */
    {
			(yyval)=getASTUnaryNode((yyvsp[0]),BIN_OP);
		}
#line 1945 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 356 "parser.y" /* yacc.c:1646  */
    {
			(yyval)=getASTUnaryNode((yyvsp[0]),BIN_OP);
		}
#line 1953 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 362 "parser.y" /* yacc.c:1646  */
    {
			(yyval)=getASTUnaryNode(getASTNodeNONE(),ADD);
		}
#line 1961 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 366 "parser.y" /* yacc.c:1646  */
    {
			(yyval)=getASTUnaryNode(getASTNodeNONE(),SUB);
		}
#line 1969 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 370 "parser.y" /* yacc.c:1646  */
    {
			(yyval)=getASTUnaryNode(getASTNodeNONE(),MUL);
		}
#line 1977 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 374 "parser.y" /* yacc.c:1646  */
    {
			(yyval)=getASTUnaryNode(getASTNodeNONE(),DIV);
		}
#line 1985 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 378 "parser.y" /* yacc.c:1646  */
    {
			(yyval)=getASTUnaryNode(getASTNodeNONE(),MOD);
		}
#line 1993 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 384 "parser.y" /* yacc.c:1646  */
    {
		(yyval)=getASTUnaryNode(getASTNodeNONE(),GT);
	}
#line 2001 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 388 "parser.y" /* yacc.c:1646  */
    {
		(yyval)=getASTUnaryNode(getASTNodeNONE(),LT);
	}
#line 2009 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 392 "parser.y" /* yacc.c:1646  */
    {
		(yyval)=getASTUnaryNode(getASTNodeNONE(),GE);
	}
#line 2017 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 396 "parser.y" /* yacc.c:1646  */
    {
		(yyval)=getASTUnaryNode(getASTNodeNONE(),LE);
	}
#line 2025 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 402 "parser.y" /* yacc.c:1646  */
    {
		(yyval)=getASTUnaryNode(getASTNodeNONE(),EQ);
	}
#line 2033 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 406 "parser.y" /* yacc.c:1646  */
    {
		(yyval)=getASTUnaryNode(getASTNodeNONE(),NEQ);
	}
#line 2041 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 412 "parser.y" /* yacc.c:1646  */
    {
		(yyval)=getASTUnaryNode(getASTNodeNONE(),AND);
	}
#line 2049 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 416 "parser.y" /* yacc.c:1646  */
    {
		(yyval)=getASTUnaryNode(getASTNodeNONE(),OR);
	}
#line 2057 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 422 "parser.y" /* yacc.c:1646  */
    {
		(yyval)=getASTUnaryNode(getASTNodeNONE(),INT_LIT);
	}
#line 2065 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 426 "parser.y" /* yacc.c:1646  */
    {
		(yyval)=getASTUnaryNode(getASTNodeNONE(),CHAR_LIT);
	}
#line 2073 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 430 "parser.y" /* yacc.c:1646  */
    {
		(yyval)=getASTUnaryNode(getASTNodeNONE(),BOOL_LIT);
	}
#line 2081 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 436 "parser.y" /* yacc.c:1646  */
    {
		(yyval)=getASTNodeIntLiteral(yylval);
	}
#line 2089 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 440 "parser.y" /* yacc.c:1646  */
    {
		(yyval)=getASTNodeIntLiteral(yylval);
	}
#line 2097 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 446 "parser.y" /* yacc.c:1646  */
    {
		(yyval)=getASTUnaryNode(getASTNodeNONE(),T);
	}
#line 2105 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 450 "parser.y" /* yacc.c:1646  */
    {
		(yyval)=getASTUnaryNode(getASTNodeNONE(),F);
	}
#line 2113 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 2117 "parser.tab.c" /* yacc.c:1646  */
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

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

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
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 455 "parser.y" /* yacc.c:1906  */


main(int argc, char **argv)
{
	yyparse();
}

yyerror(char *s)
{
	fprintf(stderr, "error: %s\n", s);
}
