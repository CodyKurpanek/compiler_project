/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 2 "Bison.y"

	//#include "HashTable.h"
	#include<stdio.h>
	#include<stdlib.h>
	#include <string.h>
	#include <stdbool.h>
	extern FILE *yyin;
	extern int yylex();
    extern int yyparse();
	extern int line;
	int yyerror(char * s);
	int scope; // use later
	struct CodeNode 
	{
		char code[1000];
		char name[20];
	};
	struct symbol {
		char *name;
		char *type;
		int scope;
	};
	#define NHASH 9997
	struct symbol symtab[NHASH];

	void lookup(char* sym, char* type);
	void lookup2(char* sym, char* type);
	void lookup3(char* sym, char* type);

	//variable
	int scopeCount = 1; // This is for cases where we have multiple if and loop statemnetst inside a fucntion or main 
	int label = 0;
	int scope = 0;
	int exp1_cnt = 0;
	bool error = false;
	bool has_main = false;
	char *allCode; 

#line 109 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    INTEGER = 258,
    IDENTIFIER = 259,
    END_STATEMENT = 260,
    COMMENT_SINGLE = 261,
    FUNC = 262,
    RETURN = 263,
    ZERO = 264,
    NEG_NUM = 265,
    POS_NUM = 266,
    MULT = 267,
    DIV = 268,
    PLUS = 269,
    MINUS = 270,
    LESS = 271,
    EQ = 272,
    GREATER = 273,
    NOT_EQ = 274,
    LESS_EQ = 275,
    GREATER_EQ = 276,
    MOD = 277,
    L_PAREN = 278,
    R_PAREN = 279,
    L_BRACK = 280,
    R_BRACK = 281,
    L_CURL = 282,
    R_CURL = 283,
    EQUAL = 284,
    IF = 285,
    ELSE = 286,
    COMMA = 287,
    BEGIN_PHASE = 288,
    DO = 289,
    BEGIN_FUNCTION = 290,
    OUT_ARROW = 291,
    IN_ARROW = 292,
    STOP = 293,
    CONSOLE_IN = 294,
    CONSOLE_OUT = 295,
    NEW_LINE = 296
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 44 "Bison.y"


	char *id;	
	char *keyWord;
	char sym;
	int num;
	struct CodeNode* cn;


#line 213 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   219

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  19
/* YYNRULES -- Number of rules.  */
#define YYNRULES  76
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  144

#define YYUNDEFTOK  2
#define YYMAXUTOK   296


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    89,    89,   104,   115,   125,   135,   145,   156,   167,
     177,   188,   198,   208,   218,   228,   238,   250,   259,   275,
     295,   321,   333,   349,   365,   376,   392,   405,   418,   421,
     430,   439,   450,   468,   478,   488,   504,   522,   543,   561,
     579,   602,   630,   642,   662,   674,   685,   697,   721,   730,
     739,   748,   762,   770,   778,   786,   795,   803,   813,   843,
     852,   860,   871,   880,   889,   899,   908,   921,   930,   939,
     948,   957,   971,  1012,  1039,  1087,  1099
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTEGER", "IDENTIFIER", "END_STATEMENT",
  "COMMENT_SINGLE", "FUNC", "RETURN", "ZERO", "NEG_NUM", "POS_NUM", "MULT",
  "DIV", "PLUS", "MINUS", "LESS", "EQ", "GREATER", "NOT_EQ", "LESS_EQ",
  "GREATER_EQ", "MOD", "L_PAREN", "R_PAREN", "L_BRACK", "R_BRACK",
  "L_CURL", "R_CURL", "EQUAL", "IF", "ELSE", "COMMA", "BEGIN_PHASE", "DO",
  "BEGIN_FUNCTION", "OUT_ARROW", "IN_ARROW", "STOP", "CONSOLE_IN",
  "CONSOLE_OUT", "NEW_LINE", "$accept", "start", "fcodeseg", "codeseg",
  "statement", "number", "array", "Function", "Parameter", "condition",
  "choice", "condition_op", "Expression", "option", "operation", "loop",
  "Function_Call", "if_statement", "else", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296
};
# endif

#define YYPACT_NINF (-87)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-67)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -87,    17,   101,   -87,    21,    22,    27,    83,   119,   119,
     -87,    13,    49,    58,   -87,   -87,   -87,   -87,    39,   110,
     140,    65,    44,   141,   145,   156,    84,   -87,   160,    94,
     -87,   -87,   -87,   -87,    78,   180,    86,    96,   103,   -87,
     155,   175,    92,    98,   106,     1,   -87,   -87,   160,    70,
      70,   -87,   -87,   -87,   -87,   -87,   -87,   179,    95,   -87,
     -87,   -87,   -87,   -87,   -87,   119,   115,   108,   118,   121,
     135,   136,    25,   -87,   147,   148,   151,   183,   179,   177,
     -87,    -9,    37,   168,   -87,   -87,   -87,   188,   -87,   -87,
     -87,   -87,   184,     5,   -87,   -87,   -87,   119,   119,   119,
     176,   178,   181,   -87,   -87,   182,    76,   -87,    -1,    32,
     185,   186,   187,   -87,   -87,   -87,   -87,   -87,   -87,   -87,
     199,   -87,   123,   175,   174,   201,   -87,   -87,     6,   -87,
     -87,   -87,   -87,   -87,    73,   -87,   189,   -87,   -87,   -87,
     -87,   -87,    87,   -87
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
      10,     0,     2,     1,     0,     0,     0,     0,     0,     0,
      28,     0,     0,     0,    17,     6,     4,     5,    18,     0,
       0,     0,     9,    31,    30,    29,     0,    27,     0,    64,
      48,    51,    50,    49,     0,     0,     0,     0,     0,     3,
       0,     0,     0,     0,     0,    62,    60,    19,     0,    46,
      46,     7,    69,    70,    67,    68,    71,     0,     0,    52,
      54,    53,    55,    57,    56,     0,     0,    24,    21,     0,
       0,     0,    62,    20,     0,     0,     0,     0,     0,     0,
      44,     0,     0,    62,    66,    65,    63,     8,    64,    16,
      47,    16,     0,     0,    34,    33,    32,     0,     0,     0,
       0,     0,     0,    58,    43,     0,     0,    73,     0,     0,
       0,     0,     0,    38,    40,    37,    35,    39,    36,    16,
       0,    45,    59,     0,    76,     0,    14,    12,    61,    13,
      72,    25,    23,    22,     0,    42,     0,    74,    11,    15,
      41,    16,     0,    75
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -87,   -87,   -87,   -86,   206,   203,   -87,   -87,   164,   208,
     -53,   -87,    -7,    -3,   167,   216,   -56,   217,   -87
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,   108,   125,    46,    14,    15,    81,    34,
      35,    65,   126,    48,    57,   127,    29,   129,   137
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      27,    88,     4,   122,    28,   109,   -26,   123,    23,    24,
      25,   139,    90,    47,   111,   105,   112,     3,   -64,   -64,
     -64,   -64,    88,   106,    50,    18,    77,   124,   -64,     8,
     -59,    21,     9,   134,    73,     4,   122,    10,    11,    12,
     123,    23,    24,    25,   113,   114,   115,    19,    50,   -59,
      37,    20,   128,   128,    87,   142,   -62,   -62,   -62,   -62,
     130,   107,     8,    39,    40,     9,   -62,    50,    41,   106,
      10,    11,    12,    79,    80,   103,     4,   122,   128,   120,
     121,   123,    23,    24,    25,    38,   128,    22,    49,    51,
       4,   122,    23,    24,    25,   123,    23,    24,    25,   -61,
      67,   140,    58,     8,     4,     5,     9,    68,     6,     7,
      66,    10,    11,    12,    42,   143,    27,     8,    74,    43,
       9,    44,    89,    30,    75,    10,    11,    12,    31,    32,
      33,     8,    76,    92,     9,   -62,   -62,   -62,   -62,    10,
      11,    12,    91,    93,    45,   -62,    50,    94,    19,    23,
      24,    25,    20,   -66,   -66,   -66,   -66,   -65,   -65,   -65,
     -65,    95,    96,   -66,    69,    70,    71,   -65,   -63,   -63,
     -63,   -63,    52,    53,    54,    55,    97,    98,   -63,    72,
      99,   104,    56,    83,    23,    24,    25,   100,    84,    85,
      86,    50,   101,   -58,   102,   110,    59,    60,    61,    62,
      63,    64,   116,   135,   117,   136,   138,   118,    13,   119,
      26,   131,   132,   133,    82,    78,   141,    36,    16,    17
};

static const yytype_uint8 yycheck[] =
{
       7,    57,     3,     4,     7,    91,     5,     8,     9,    10,
      11,     5,    65,    20,     9,    24,    11,     0,    12,    13,
      14,    15,    78,    32,    23,     4,    25,    28,    22,    30,
       5,     4,    33,   119,    41,     3,     4,    38,    39,    40,
       8,     9,    10,    11,    97,    98,    99,    25,    23,     5,
      37,    29,   108,   109,    57,   141,    12,    13,    14,    15,
      28,    24,    30,     5,    25,    33,    22,    23,    29,    32,
      38,    39,    40,     3,     4,    78,     3,     4,   134,     3,
       4,     8,     9,    10,    11,    36,   142,     4,    23,     5,
       3,     4,     9,    10,    11,     8,     9,    10,    11,     5,
       4,    28,    24,    30,     3,     4,    33,     4,     7,     8,
      24,    38,    39,    40,     4,    28,   123,    30,    26,     9,
      33,    11,    27,     4,    26,    38,    39,    40,     9,    10,
      11,    30,    26,    25,    33,    12,    13,    14,    15,    38,
      39,    40,    27,    25,     4,    22,    23,    26,    25,     9,
      10,    11,    29,    12,    13,    14,    15,    12,    13,    14,
      15,    26,    26,    22,     9,    10,    11,    22,    12,    13,
      14,    15,    12,    13,    14,    15,    29,    29,    22,     4,
      29,     4,    22,     4,     9,    10,    11,     4,     9,    10,
      11,    23,     9,     5,    11,    11,    16,    17,    18,    19,
      20,    21,    26,     4,    26,    31,     5,    26,     2,    27,
       7,    26,    26,    26,    50,    48,    27,     9,     2,     2
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    43,    44,     0,     3,     4,     7,     8,    30,    33,
      38,    39,    40,    46,    48,    49,    57,    59,     4,    25,
      29,     4,     4,     9,    10,    11,    47,    54,    55,    58,
       4,     9,    10,    11,    51,    52,    51,    37,    36,     5,
      25,    29,     4,     9,    11,     4,    47,    54,    55,    23,
      23,     5,    12,    13,    14,    15,    22,    56,    24,    16,
      17,    18,    19,    20,    21,    53,    24,     4,     4,     9,
      10,    11,     4,    54,    26,    26,    26,    25,    56,     3,
       4,    50,    50,     4,     9,    10,    11,    55,    58,    27,
      52,    27,    25,    25,    26,    26,    26,    29,    29,    29,
       4,     9,    11,    55,     4,    24,    32,    24,    45,    45,
      11,     9,    11,    52,    52,    52,    26,    26,    26,    27,
       3,     4,     4,     8,    28,    46,    54,    57,    58,    59,
      28,    26,    26,    26,    45,     4,    31,    60,     5,     5,
      28,    27,    45,    28
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    42,    43,    44,    44,    44,    44,    44,    44,    44,
      44,    45,    45,    45,    45,    45,    45,    46,    46,    46,
      46,    46,    46,    46,    46,    46,    46,    46,    46,    47,
      47,    47,    48,    48,    48,    48,    48,    48,    48,    48,
      48,    49,    50,    50,    50,    50,    50,    51,    52,    52,
      52,    52,    53,    53,    53,    53,    53,    53,    54,    54,
      54,    54,    55,    55,    55,    55,    55,    56,    56,    56,
      56,    56,    57,    58,    59,    60,    60
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     3,     2,     2,     2,     4,     5,     3,
       0,     3,     2,     2,     2,     3,     0,     1,     2,     3,
       4,     3,     6,     6,     3,     6,     3,     2,     1,     1,
       1,     1,     5,     5,     5,     6,     6,     6,     6,     6,
       6,     8,     4,     2,     1,     3,     0,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     6,     4,     7,     4,     0
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
#line 90 "Bison.y"
{
	if(!has_main)
	{
		yyerror("No main");
		error = true;
	}
	
	if(!error)
		allCode = (yyvsp[0].cn)->code;
	
	
}
#line 1509 "y.tab.c"
    break;

  case 3:
#line 105 "Bison.y"
                        {
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
				strcpy(new->code, "");
				strcpy(new->name, "");
				strcat(new->code, (yyvsp[-2].cn)->code);
				strcat(new->code, (yyvsp[-1].cn)->code);

				(yyval.cn) = new;
			}
#line 1523 "y.tab.c"
    break;

  case 4:
#line 116 "Bison.y"
                  {
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
				strcpy(new->code, "");
				strcpy(new->name, "");
				strcat(new->code, (yyvsp[-1].cn)->code);
				strcat(new->code, (yyvsp[0].cn)->code);

				(yyval.cn) = new;
		  }
#line 1537 "y.tab.c"
    break;

  case 5:
#line 126 "Bison.y"
                  {
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
				strcpy(new->code, "");
				strcpy(new->name, "");
				strcat(new->code, (yyvsp[-1].cn)->code);
				strcat(new->code, (yyvsp[0].cn)->code);

				(yyval.cn) = new;
		  }
#line 1551 "y.tab.c"
    break;

  case 6:
#line 136 "Bison.y"
                  {
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
				strcpy(new->code, "");
				strcpy(new->name, "");
				strcat(new->code, (yyvsp[-1].cn)->code);
				strcat(new->code, (yyvsp[0].cn)->code);

				(yyval.cn) = new;
		  }
#line 1565 "y.tab.c"
    break;

  case 7:
#line 146 "Bison.y"
                  {
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
				strcpy(new->code, "");
				strcpy(new->name, "");
				printf("Error on line %d: invalid spot for return.\n", line);
				error = true;


				(yyval.cn) = new;
		  }
#line 1580 "y.tab.c"
    break;

  case 8:
#line 157 "Bison.y"
                  {
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
				strcpy(new->code, "");
				strcpy(new->name, "");
				printf("Error on line %d: invalid spot for return.\n", line);
				error = true;

				
				(yyval.cn)=new;
		  }
#line 1595 "y.tab.c"
    break;

  case 9:
#line 168 "Bison.y"
                  {
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
				strcpy(new->code, "");
				strcpy(new->name, "");
				printf("Error on line %d: invalid spot for return.\n", line);
				error = true;

				(yyval.cn) = new;
		  }
#line 1609 "y.tab.c"
    break;

  case 10:
#line 178 "Bison.y"
                        {
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
				strcpy(new->code, "");
				strcpy(new->name, "");

				(yyval.cn) = new;
			}
#line 1621 "y.tab.c"
    break;

  case 11:
#line 189 "Bison.y"
                        {
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
				strcpy(new->code, "");
				strcpy(new->name, "");
				strcat(new->code, (yyvsp[-2].cn)->code);
				strcat(new->code, (yyvsp[-1].cn)->code);

				(yyval.cn) = new;
		   }
#line 1635 "y.tab.c"
    break;

  case 12:
#line 199 "Bison.y"
                  {
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
				strcpy(new->code, "");
				strcpy(new->name, "");
				strcat(new->code, (yyvsp[-1].cn)->code);
				strcat(new->code, (yyvsp[0].cn)->code);

				(yyval.cn) = new;
		   }
#line 1649 "y.tab.c"
    break;

  case 13:
#line 209 "Bison.y"
                  {
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
				strcpy(new->code, "");
				strcpy(new->name, "");
				strcat(new->code, (yyvsp[-1].cn)->code);
				strcat(new->code, (yyvsp[0].cn)->code);
				
				(yyval.cn) = new;
		  }
#line 1663 "y.tab.c"
    break;

  case 14:
#line 219 "Bison.y"
                  {
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
				strcpy(new->code, "");
				strcpy(new->name, "");
				strcat(new->code, (yyvsp[-1].cn)->code);
				strcat(new->code, (yyvsp[0].cn)->code);

				(yyval.cn) = new;
		   }
#line 1677 "y.tab.c"
    break;

  case 15:
#line 229 "Bison.y"
                  {
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
				strcpy(new->code, "");
				strcpy(new->name, "");
				strcat(new->code, (yyvsp[-2].cn)->code);
				strcat(new->code, (yyvsp[-1].cn)->code);

				(yyval.cn) = new;
		  }
#line 1691 "y.tab.c"
    break;

  case 16:
#line 239 "Bison.y"
                  {
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
				strcpy(new->code, "");
				strcpy(new->name, "");
				(yyval.cn) = new;
		  }
#line 1702 "y.tab.c"
    break;

  case 17:
#line 251 "Bison.y"
                   {
				struct CodeNode *new = malloc(sizeof(struct CodeNode));
				strcpy(new->code, "");
				strcpy(new->name, "");
				strcat(new->code, (yyvsp[0].cn)->code);

				(yyval.cn) = new;
		   }
#line 1715 "y.tab.c"
    break;

  case 18:
#line 260 "Bison.y"
                        {
				char *temp = (yyvsp[0].id);
				lookup(temp, "INTEGER");
				//create new empty CodeNode
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
				strcpy(new->code, "");
				strcpy(new->name, "");

				//. id  (declare)
				strcat(new->code, ". ");
				strcat(new->code, (yyvsp[0].id));
				strcat(new->code, "\n");

				(yyval.cn)=new;
			}
#line 1735 "y.tab.c"
    break;

  case 19:
#line 276 "Bison.y"
                        {
				char *temp = (yyvsp[-2].id);
				lookup2(temp, "INTEGER");
				lookup3(temp, "INTEGER");
				//create new empty CodeNode
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
				strcpy(new->code, "");
				strcpy(new->name, "");
				strcat(new->code, (yyvsp[0].cn)->code);
				strcat(new->code, "= ");
				strcat(new->code, (yyvsp[-2].id));
				strcat(new->code, ", ");
				strcat(new->code, (yyvsp[0].cn)->name);
				

				strcat(new->code, "\n");

				(yyval.cn)=new;
			}
#line 1759 "y.tab.c"
    break;

  case 20:
#line 296 "Bison.y"
                        {
				char *temp = (yyvsp[-2].id);
				lookup(temp, "INTEGER");
				lookup3(temp, "INTEGER");
				//create new empty CodeNode
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
				strcpy(new->code, "");
				strcpy(new->name, "");

				//. id  (declare)
				strcat(new->code, (yyvsp[0].cn)->code);
				strcat(new->code, ". ");
				strcat(new->code, (yyvsp[-2].id));
				strcat(new->code, "\n");


				strcat(new->code, "= ");
				strcat(new->code, (yyvsp[-2].id));
				strcat(new->code, ", ");
				strcat(new->code, (yyvsp[0].cn)->name);
				
				strcat(new->code, "\n");
				
				(yyval.cn)=new;				
			}
#line 1789 "y.tab.c"
    break;

  case 21:
#line 322 "Bison.y"
                   {
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
				strcpy(new->code, "");
				strcpy(new->name, "");
				strcat(new->code, ".> ");
				strcat(new->code, (yyvsp[0].id));
				strcat(new->code, "\n");
				
				(yyval.cn) = new;

		   }
#line 1805 "y.tab.c"
    break;

  case 22:
#line 334 "Bison.y"
                   {
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
				strcpy(new->code, "");
				strcpy(new->name, "");
				strcat(new->code, ".[]> ");
				strcat(new->code, (yyvsp[-3].id));
				strcat(new->code, ", ");
				char temp[100];  
				int value = (yyvsp[-1].num);
                sprintf(temp, "%d", value); 
				strcat(new->code, temp);
				strcat(new->code, "\n");

				(yyval.cn) = new;
		   }
#line 1825 "y.tab.c"
    break;

  case 23:
#line 350 "Bison.y"
                   {
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
				strcpy(new->code, "");
				strcpy(new->name, "");
				strcat(new->code, ".[]> ");
				strcat(new->code, (yyvsp[-3].id));
				strcat(new->code, ", ");
				char temp[100];  
				int value = (yyvsp[-1].num);
                sprintf(temp, "%d", value); 
				strcat(new->code, temp);
				strcat(new->code, "\n");

				(yyval.cn) = new;
		   }
#line 1845 "y.tab.c"
    break;

  case 24:
#line 366 "Bison.y"
                   {
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
				strcpy(new->code, "");
				strcpy(new->name, "");
				strcat(new->code, ".< ");
				strcat(new->code, (yyvsp[0].id));
				strcat(new->code, "\n");

				(yyval.cn) = new;
		   }
#line 1860 "y.tab.c"
    break;

  case 25:
#line 377 "Bison.y"
                   {
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
				strcpy(new->code, "");
				strcpy(new->name, "");
				strcat(new->code, ".[]< ");
				strcat(new->code, (yyvsp[-3].id));
				strcat(new->code, ", ");
				char temp[100];  
				int value = (yyvsp[-1].num);
                sprintf(temp, "%d", value); 
				strcat(new->code, temp);
				strcat(new->code, "\n");

				(yyval.cn) = new;
		   }
#line 1880 "y.tab.c"
    break;

  case 26:
#line 393 "Bison.y"
                   {
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
				strcpy(new->code, "");
				strcpy(new->name, "");
				strcat(new->code, "= ");
				strcat(new->code, (yyvsp[-2].id));
				strcat(new->code, ", ");
				strcat(new->code, (yyvsp[0].id));

				(yyval.cn) = new;

		   }
#line 1897 "y.tab.c"
    break;

  case 27:
#line 406 "Bison.y"
                  {
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
				strcpy(new->code, "");
				strcpy(new->name, "");

				strcat(new->code, (yyvsp[0].cn)->code);
				strcat(new->code, "ret ");
				strcat(new->code, (yyvsp[0].cn)->name);
				strcat(new->code, "\n");
				
				(yyval.cn)=new;
		  }
#line 1914 "y.tab.c"
    break;

  case 28:
#line 418 "Bison.y"
                          {printf("statment -> STOP\n");}
#line 1920 "y.tab.c"
    break;

  case 29:
#line 422 "Bison.y"
                        {
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
				strcpy(new->code, "");
				strcpy(new->name, "");
				sprintf(new->code, "%i", (yyvsp[0].num));

				(yyval.cn)=new;
			}
#line 1933 "y.tab.c"
    break;

  case 30:
#line 431 "Bison.y"
                   {
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
				strcpy(new->code, "");
				strcpy(new->name, "");
				sprintf(new->code, "%i", (yyvsp[0].num));

				(yyval.cn)=new;
			}
#line 1946 "y.tab.c"
    break;

  case 31:
#line 440 "Bison.y"
                   {
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
				strcpy(new->code, "");
				strcpy(new->name, "");
				sprintf(new->code, "%i", (yyvsp[0].num));

				(yyval.cn)=new;
			}
#line 1959 "y.tab.c"
    break;

  case 32:
#line 451 "Bison.y"
                        {
				char *temp = (yyvsp[-3].id);
				lookup(temp, "ARRAY");
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
                strcpy(new->code, "");
                strcpy(new->name, "");
                strcat(new->code, ".[] ");
                strcat(new->code, (yyvsp[-3].id));
                strcat(new->code, ", ");
                char temp1[100];  
				int value = (yyvsp[-1].num);
                sprintf(temp1, "%d", value); 
                strcat(new->code, temp1);
                strcat(new->code, "\n");

                (yyval.cn) = new;
			}
#line 1981 "y.tab.c"
    break;

  case 33:
#line 469 "Bison.y"
                        {
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
                strcpy(new->code, "");
                strcpy(new->name, "");
				printf("Error on line %d: invalid array size.\n", line);
				error = true;
                
                (yyval.cn) = new;
			}
#line 1995 "y.tab.c"
    break;

  case 34:
#line 479 "Bison.y"
                        {
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
                strcpy(new->code, "");
                strcpy(new->name, "");
				printf("Error on line %d: invalid array size.\n", line);
				error = true;
                
                (yyval.cn) = new;
			}
#line 2009 "y.tab.c"
    break;

  case 35:
#line 489 "Bison.y"
                   {
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
                strcpy(new->code, "");
                strcpy(new->name, "");
				strcat(new->code, "=[] ");
				strcat(new->code, (yyvsp[-5].id));
				strcat(new->code, ", ");
				strcat(new->code, (yyvsp[-3].id));
				strcat(new->code, ", ");
				strcat(new->code, (yyvsp[-1].id));
				strcat(new->code, "\n");
				

				(yyval.cn) = new;
		   }
#line 2029 "y.tab.c"
    break;

  case 36:
#line 505 "Bison.y"
                   {
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
                strcpy(new->code, "");
                strcpy(new->name, "");
				strcat(new->code, "=[] ");
				strcat(new->code, (yyvsp[-5].id));
				strcat(new->code, ", ");
				strcat(new->code, (yyvsp[-3].id));
				strcat(new->code, ", ");
				char temp[100];  
				int value = (yyvsp[-1].num);
                sprintf(temp, "%d", value); 
                strcat(new->code, temp);
				strcat(new->code, "\n");

				(yyval.cn) = new;
		   }
#line 2051 "y.tab.c"
    break;

  case 37:
#line 523 "Bison.y"
                   {
			    char *temp = (yyvsp[-5].id);
				lookup2(temp, "ARRAY");
				lookup3(temp, "ARRAY");
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
                strcpy(new->code, "");
                strcpy(new->name, "");
				strcat(new->code, "[]= ");
				strcat(new->code, (yyvsp[-5].id));
				strcat(new->code, ", ");
				char temp1[100];  
				int value = (yyvsp[-3].num);
                sprintf(temp1, "%d", value); 
				strcat(new->code, temp1);
				strcat(new->code, ", ");
				strcat(new->code, (yyvsp[0].cn)->code);
				strcat(new->code, "\n");

				(yyval.cn) = new;
		   }
#line 2076 "y.tab.c"
    break;

  case 38:
#line 544 "Bison.y"
                   {
			    char *temp = (yyvsp[-5].id);
				lookup2(temp, "ARRAY");
				lookup3(temp, "ARRAY");
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
                strcpy(new->code, "");
                strcpy(new->name, "");
				strcat(new->code, "[]= ");
				strcat(new->code, (yyvsp[-5].id));
				strcat(new->code, ", ");
				strcat(new->code, (yyvsp[-3].id));
				strcat(new->code, ", ");
				strcat(new->code, (yyvsp[0].cn)->code);
				strcat(new->code, "\n");

				(yyval.cn) = new;
		   }
#line 2098 "y.tab.c"
    break;

  case 39:
#line 562 "Bison.y"
                   {
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
                strcpy(new->code, "");
                strcpy(new->name, "");
				strcat(new->code, "=[] ");
				strcat(new->code, (yyvsp[-5].id));
				strcat(new->code, ", ");
				strcat(new->code, (yyvsp[-3].id));
				strcat(new->code, ", ");
				char temp[100];  
				int value = (yyvsp[-1].num);
                sprintf(temp, "%d", value); 
                strcat(new->code, temp);
				strcat(new->code, "\n");

				(yyval.cn) = new;
		   }
#line 2120 "y.tab.c"
    break;

  case 40:
#line 580 "Bison.y"
                   {
			    char *temp = (yyvsp[-5].id);
				lookup2(temp, "ARRAY");
				lookup3(temp, "ARRAY");
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
                strcpy(new->code, "");
                strcpy(new->name, "");
				strcat(new->code, "[]= ");
				strcat(new->code, (yyvsp[-5].id));
				strcat(new->code, ", ");
				char temp1[100];  
				int value = (yyvsp[-3].num);
                sprintf(temp1, "%d", value); 
				strcat(new->code, temp1);
				strcat(new->code, ", ");
				strcat(new->code, (yyvsp[0].cn)->code);
				strcat(new->code, "\n");

				(yyval.cn) = new;
		   }
#line 2145 "y.tab.c"
    break;

  case 41:
#line 603 "Bison.y"
                                {	
					char *temp = (yyvsp[-6].id);
					lookup(temp, "FUNCTION");
					if(strcmp((yyvsp[-6].id), "main") == 0)
					{
						has_main = true;
					}
					struct CodeNode* new = malloc(sizeof(struct CodeNode));
					strcpy(new->code, "");
					strcpy(new->name, "");
					strcat(new->code, "func ");
					strcat(new->code, (yyvsp[-6].id));
					strcat(new->code, "\n");
					strcat(new->code, (yyvsp[-4].cn)->code);
					strcat(new->code, (yyvsp[-1].cn)->code);
					strcat(new->code, "endfunc\n");

					(yyval.cn)=new;

				}
#line 2170 "y.tab.c"
    break;

  case 42:
#line 631 "Bison.y"
                                {
					struct CodeNode* new = malloc(sizeof(struct CodeNode));
					strcpy(new->code, "");
					strcpy(new->name, "");
					strcat(new->code, (yyvsp[-3].cn)->code);
					strcat(new->code, ". ");
					strcat(new->code, (yyvsp[0].id));
					strcat(new->code, "\n");

					(yyval.cn) = new;
				}
#line 2186 "y.tab.c"
    break;

  case 43:
#line 643 "Bison.y"
                                {
					struct CodeNode* new = malloc(sizeof(struct CodeNode));
					strcpy(new->code, "");
					strcpy(new->name, "");
					strcat(new->code, ". ");
					strcat(new->code, (yyvsp[0].id));
					strcat(new->code, "\n");
					strcat(new->code, "= ");
					strcat(new->code, (yyvsp[0].id));
					strcat(new->code, ", ");
					strcat(new->code, "$");
					strcat(new->code, "0");
					strcat(new->code, "\n");

					


					(yyval.cn) = new;
				}
#line 2210 "y.tab.c"
    break;

  case 44:
#line 663 "Bison.y"
                          {
					struct CodeNode* new = malloc(sizeof(struct CodeNode));
					strcpy(new->code, "");
					strcpy(new->name, "");
					strcat(new->code, "param ");
					strcat(new->code, (yyvsp[0].id));
					strcat(new->code, "\n");


					(yyval.cn) = new;
			  }
#line 2226 "y.tab.c"
    break;

  case 45:
#line 675 "Bison.y"
                          {
					struct CodeNode* new = malloc(sizeof(struct CodeNode));
					strcpy(new->code, "");
					strcpy(new->name, "");
					strcat(new->code, (yyvsp[-2].cn)->code);
					strcat(new->code, "param ");
					strcat(new->code, (yyvsp[0].id));
					strcat(new->code, "\n");
					(yyval.cn) = new;
			  }
#line 2241 "y.tab.c"
    break;

  case 46:
#line 686 "Bison.y"
                            {
					struct CodeNode* new = malloc(sizeof(struct CodeNode));
					strcpy(new->code, "");
					strcpy(new->name, "");

					
					(yyval.cn) = new;
				}
#line 2254 "y.tab.c"
    break;

  case 47:
#line 698 "Bison.y"
                                {
					char varname[10];
					sprintf(varname, "tmp_exp%i", exp1_cnt); // we create new temp 
					struct CodeNode* new = malloc(sizeof(struct CodeNode));
					strcpy(new->code, "");
					strcpy(new->name, varname);
					strcat(new->code, ". ");
					strcat(new->code, varname);
					strcat(new->code, "\n");
					strcat(new->code, (yyvsp[-1].cn)->code);
					strcat(new->code, " ");
					strcat(new->code, varname);
					strcat(new->code, ", ");
					strcat(new->code, (yyvsp[-2].cn)->code);
					strcat(new->code, ", ");
					strcat(new->code, (yyvsp[0].cn)->code);
					strcat(new->code, "\n");

					exp1_cnt += 1;
					(yyval.cn) = new;
				}
#line 2280 "y.tab.c"
    break;

  case 48:
#line 722 "Bison.y"
                                {
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
				strcpy(new->code, "");
				strcpy(new->name, "");
				sprintf(new->code, "%s", (yyvsp[0].id));

				(yyval.cn)=new;
				}
#line 2293 "y.tab.c"
    break;

  case 49:
#line 731 "Bison.y"
                          {
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
				strcpy(new->code, "");
				strcpy(new->name, "");
				sprintf(new->code, "%i", (yyvsp[0].num));

				(yyval.cn)=new;
				}
#line 2306 "y.tab.c"
    break;

  case 50:
#line 740 "Bison.y"
                          {
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
				strcpy(new->code, "");
				strcpy(new->name, "");
				sprintf(new->code, "%i", (yyvsp[0].num));

				(yyval.cn)=new;
				}
#line 2319 "y.tab.c"
    break;

  case 51:
#line 749 "Bison.y"
                          {
				//create new empty CodeNode
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
				strcpy(new->code, "");
				strcpy(new->name, "");
				sprintf(new->code, "%i", (yyvsp[0].num));

				(yyval.cn)=new;
				}
#line 2333 "y.tab.c"
    break;

  case 52:
#line 763 "Bison.y"
                                {
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
				strcpy(new->code, "<");
				strcpy(new->name, "");

				(yyval.cn)=new;
				}
#line 2345 "y.tab.c"
    break;

  case 53:
#line 771 "Bison.y"
                          {
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
				strcpy(new->code, ">");
				strcpy(new->name, "");

				(yyval.cn)=new;
			  }
#line 2357 "y.tab.c"
    break;

  case 54:
#line 779 "Bison.y"
                          {
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
				strcpy(new->code, "==");
				strcpy(new->name, "");

				(yyval.cn)=new;
			  }
#line 2369 "y.tab.c"
    break;

  case 55:
#line 787 "Bison.y"
                          {
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
				strcpy(new->code, "!=");
				strcpy(new->name, "");

				(yyval.cn)=new;
			  }
#line 2381 "y.tab.c"
    break;

  case 56:
#line 796 "Bison.y"
                          {
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
				strcpy(new->code, ">=");
				strcpy(new->name, "");

				(yyval.cn)=new;
			  }
#line 2393 "y.tab.c"
    break;

  case 57:
#line 804 "Bison.y"
                          {
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
				strcpy(new->code, "<=");
				strcpy(new->name, "");

				(yyval.cn)=new;
			  }
#line 2405 "y.tab.c"
    break;

  case 58:
#line 814 "Bison.y"
                                {
					
					//create new empty CodeNode
					struct CodeNode* new = malloc(sizeof(struct CodeNode));
					strcpy(new->code, "");
					strcpy(new->name, "");

					//.tmp_exp1
					//operation tmp_exp1, value, value
					char varname[10];
					sprintf(varname, "tmp_exp%i", exp1_cnt);
					strcat(new->code, (yyvsp[-2].cn)->code);
					strcat(new->code, (yyvsp[0].cn)->code);
					strcat(new->code, ". ");
					strcat(new->code, varname);
					strcat(new->code, "\n");
					strcat(new->code, (yyvsp[-1].cn)->code);
					strcat(new->code, varname);
					strcat(new->code, ", ");
					strcat(new->code, (yyvsp[-2].cn)->name);
					strcat(new->code, ", ");
					strcat(new->code, (yyvsp[0].cn)->name);
					strcat(new->code, "\n");
					strcat(new->name, varname);

					exp1_cnt++;
					(yyval.cn)=new;
				}
#line 2438 "y.tab.c"
    break;

  case 59:
#line 844 "Bison.y"
                          {
					struct CodeNode* new = malloc(sizeof(struct CodeNode));
					strcpy(new->code, "");
					strcpy(new->name, "");
					strcat(new->name, (yyvsp[0].id));

					(yyval.cn) = new;
			  }
#line 2451 "y.tab.c"
    break;

  case 60:
#line 853 "Bison.y"
                          {
					struct CodeNode* new = malloc(sizeof(struct CodeNode));
					strcpy(new->code, "");
					strcpy(new->name, "");
					strcat(new->name, (yyvsp[0].cn)->code);
					(yyval.cn) = new;
			  }
#line 2463 "y.tab.c"
    break;

  case 61:
#line 861 "Bison.y"
                          {
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
				strcpy(new->code, "");
				strcpy(new->name, "");
				strcpy(new->code, (yyvsp[0].cn)->code);
				strcpy(new->name, (yyvsp[0].cn)->name);
				(yyval.cn)=new;
				}
#line 2476 "y.tab.c"
    break;

  case 62:
#line 872 "Bison.y"
                                {
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
				strcpy(new->code, "");
				strcpy(new->name, "");
				sprintf(new->name, "%s", (yyvsp[0].id));

				(yyval.cn)=new;
				}
#line 2489 "y.tab.c"
    break;

  case 63:
#line 881 "Bison.y"
                          {
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
				strcpy(new->code, "");
				strcpy(new->name, "");
				sprintf(new->name, "%i", (yyvsp[0].num));

				(yyval.cn)=new;
			  }
#line 2502 "y.tab.c"
    break;

  case 64:
#line 890 "Bison.y"
                          {
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
				strcpy(new->code, "");
				strcpy(new->name, "");
				strcpy(new->code, (yyvsp[0].cn)->code);
				strcpy(new->name, (yyvsp[0].cn)->name);
				(yyval.cn)=new;
				}
#line 2515 "y.tab.c"
    break;

  case 65:
#line 900 "Bison.y"
                          {
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
				strcpy(new->code, "");
				strcpy(new->name, "");
				sprintf(new->code, "%i", (yyvsp[0].num));

				(yyval.cn)=new;
				}
#line 2528 "y.tab.c"
    break;

  case 66:
#line 909 "Bison.y"
                          {
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
				strcpy(new->code, "");
				strcpy(new->name, "");
				sprintf(new->code, "%i", (yyvsp[0].num));

				(yyval.cn)=new;
				}
#line 2541 "y.tab.c"
    break;

  case 67:
#line 922 "Bison.y"
                                {
				//create new empty CodeNode
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
				strcpy(new->code, "+ ");
				strcpy(new->name, "");
				
				(yyval.cn)=new;
			  }
#line 2554 "y.tab.c"
    break;

  case 68:
#line 931 "Bison.y"
                          {
				//create new empty CodeNode
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
				strcpy(new->code, "- ");
				strcpy(new->name, "");
				
				(yyval.cn)=new;
			  }
#line 2567 "y.tab.c"
    break;

  case 69:
#line 940 "Bison.y"
                          {
				//create new empty CodeNode
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
				strcpy(new->code, "* ");
				strcpy(new->name, "");
				
				(yyval.cn)=new;
			  }
#line 2580 "y.tab.c"
    break;

  case 70:
#line 949 "Bison.y"
                          {
				//create new empty CodeNode
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
				strcpy(new->code, "/ ");
				strcpy(new->name, "");
				
				(yyval.cn)=new;
			  }
#line 2593 "y.tab.c"
    break;

  case 71:
#line 958 "Bison.y"
                          {
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
				strcpy(new->code, "% ");
				strcpy(new->name, "");
				
				(yyval.cn)=new;
			  }
#line 2605 "y.tab.c"
    break;

  case 72:
#line 972 "Bison.y"
                                {
					char labelName1[10];
					sprintf(labelName1, "L%i", label); // Lablel for Begging of Loop
					label += 1;
					char labelName2[10];
					sprintf(labelName2, "L%i", label); // Label for End of Loop
					label += 1;
					struct CodeNode* new = malloc(sizeof(struct CodeNode));
					strcat(new->name, "");
					strcat(new->code, "");

					strcat(new->code, ": "); // we declare Lable 1 
					strcat(new->code, labelName1);
					strcat(new->code, "\n");

					strcat(new->code, (yyvsp[-4].cn)->code); // negating condition 
					strcat(new->code, "! ");
					strcat(new->code, (yyvsp[-4].cn)->name);
					strcat(new->code, ", ");
					strcat(new->code, (yyvsp[-4].cn)->name);
					strcat(new->code, "\n");

					strcat(new->code, "?:= "); // If-Statement
					strcat(new->code, labelName2);
					strcat(new->code, ", ");
					strcat(new->code, (yyvsp[-4].cn)->name);
					strcat(new->code, "\n");
					strcat(new->code, (yyvsp[-1].cn)->code);
					strcat(new->code, ":= ");
					strcat(new->code, labelName1);
					strcat(new->code, "\n");

					strcat(new->code, ": "); // we declare Lable 2
					strcat(new->code, labelName2);
					strcat(new->code, "\n");

					(yyval.cn) = new;
				}
#line 2648 "y.tab.c"
    break;

  case 73:
#line 1013 "Bison.y"
                                {
					// char *temp = $1;
					// lookup2(temp, "FUNCTION");
					char varname[10];
					sprintf(varname, "tmp_exp%i", exp1_cnt);
					struct CodeNode* new = malloc(sizeof(struct CodeNode));
					strcpy(new->code, "");
					strcpy(new->name, "");
					strcat(new->code, ". ");
					strcat(new->code, varname);
					strcat(new->code, "\n");
					strcat(new->code, (yyvsp[-1].cn)->code); // this will do the assembly code for the values in
					strcat(new->code, "call ");
					strcat(new->code, (yyvsp[-3].id));
					strcat(new->code, ", ");
					strcat(new->code, varname);
					strcat(new->code, "\n");
					strcat(new->name, varname);

					exp1_cnt++;
					(yyval.cn) = new;
					
				}
#line 2676 "y.tab.c"
    break;

  case 74:
#line 1040 "Bison.y"
                                {	
					char labelName[10];
					char elseLabel[10];
					char endLabel[10];
					sprintf(labelName, "L%i", label); // Created new Lable
					label += 1;
					sprintf(elseLabel, "L%i", label);
					label += 1;
					sprintf(endLabel, "L%i", label);
					label += 1;
					scope += scopeCount;
					struct CodeNode* new = malloc(sizeof(struct CodeNode));
					strcpy(new->code, "");
					strcpy(new->name, "");
					strcat(new->code, (yyvsp[-5].cn)->code);
				
					strcat(new->code, "?:= ");
					strcat(new->code, labelName);
					strcat(new->code, ", ");
					strcat(new->code, (yyvsp[-5].cn)->name);
					strcat(new->code, "\n");
					strcat(new->code, ":= ");
					strcat(new->code, elseLabel);
					strcat(new->code, "\n");
					strcat(new->code, ": ");
					strcat(new->code, labelName);
					strcat(new->code, "\n");
					strcat(new->code, (yyvsp[-2].cn)->code);
					strcat(new->code, ":= ");
					strcat(new->code, endLabel);
					strcat(new->code, "\n");
					strcat(new->code, ": ");
					strcat(new->code, elseLabel);
					strcat(new->code, "\n");
					strcat(new->code, (yyvsp[0].cn)->code);
					strcat(new->code, ": ");
					strcat(new->code, endLabel);
					strcat(new->code, "\n");


					// we are assuming there is a newline after codeseg
					scope -= scopeCount;
					scopeCount += 1;
					(yyval.cn) = new;
				}
#line 2726 "y.tab.c"
    break;

  case 75:
#line 1088 "Bison.y"
                           {
					scope += scopeCount;
					struct CodeNode* new = malloc(sizeof(struct CodeNode));
					strcpy(new->code, "");
					strcpy(new->name, "");
					strcat(new->code, (yyvsp[-1].cn)->code);
					scope -= scopeCount;
					scopeCount += 1;
					
					(yyval.cn) = new;
			   }
#line 2742 "y.tab.c"
    break;

  case 76:
#line 1100 "Bison.y"
                          {
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
				strcpy(new->code, "");
				strcpy(new->name, "");

				(yyval.cn) = new;
			  }
#line 2754 "y.tab.c"
    break;


#line 2758 "y.tab.c"

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
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp);
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
#line 1109 "Bison.y"



 int main(int argc, char* argv[])
{
	const char* file = argv[1]; //arv[1] this is the input file 
	FILE *myFile = fopen(argv[1],"r"); 

	if(!myFile)
	{
		printf("Can't open file");
		return -1;
	}
	yyin = myFile; // yyin 
	yyparse();

	FILE *fptr;  // create file pointer 
	fptr = fopen("mil_code.mil","w"); // we point to file mil_code 
	fputs(allCode,fptr);
	free(allCode);
	fclose(fptr);

	return 0;
} 

static unsigned symhash(char* sym){
	unsigned int hash = 0;
	unsigned c;

	while(c = *sym++) hash = hash*9 ^ c;

	return hash;
}

void lookup(char* sym, char* type){//for declaring multiple times
	struct symbol *sp = &symtab[symhash(sym)%NHASH];
	int scount = NHASH;
	while(--scount >= 0){
		if((sp->name && !strcmp(sp->name, sym)) && sp->scope == scope){//if symbol exists 
			printf("Error on line %d: symbol exists.\n", line);//bad, redeclaring it
			error = true;
			return;
		}
		if(!sp->name){
			sp->name = strdup(sym);
			sp->scope = scope;
			sp->type = strdup(type);
			return;
		}
	}
}

void lookup2(char* sym, char* type){// to set variable, the variable must already be declared
	struct symbol *sp = &symtab[symhash(sym)%NHASH];
	int scount = NHASH;
	while(--scount >= 0){
		if((sp->name && !strcmp(sp->name, sym)) && sp->scope == scope){ //if symbol exists
			//good. set the value
			return;
		}
		if(!sp->name){//otherwise
			//bad; trying to add value to undeclared variable
			printf("Error on line %d: variable not defined.\n", line);
			error = true;
			return;
		}
	}
}

void lookup3(char* sym, char* type){// for modifying wrong type
	struct symbol *sp = &symtab[symhash(sym)%NHASH];
	int scount = NHASH;
	while(--scount >= 0){
		//if symbol exists, and right type
		if((sp->name && !strcmp(sp->name, sym)) && sp->scope == scope && strcmp(sp->type, type) == 0){
			//good. return
			return;
		}
		//now, if it does exist, it must be the wrong type. Throw error.
		else if(sp->name){
			printf("Error on line %d: Modifying wrong variable type.\n", line);
			error = true;
			return;
		}
	}
}


int yyerror(char * s)
{
	printf("ERROR: %s\n", s);
	return 0;
}


