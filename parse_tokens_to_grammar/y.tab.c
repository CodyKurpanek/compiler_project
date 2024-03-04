/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 3 "Bison.y"

	#include<stdio.h>
	#include<stdlib.h>
	#include <string.h>
	extern FILE *yyin;
	extern int yylex();
    extern int yyparse();
	int yyerror(char * s);

#line 81 "y.tab.c"

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

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    INTEGER = 258,                 /* INTEGER  */
    IDENTIFIER = 259,              /* IDENTIFIER  */
    END_STATEMENT = 260,           /* END_STATEMENT  */
    COMMENT_SINGLE = 261,          /* COMMENT_SINGLE  */
    ZERO = 262,                    /* ZERO  */
    NEG_NUM = 263,                 /* NEG_NUM  */
    POS_NUM = 264,                 /* POS_NUM  */
    MULT = 265,                    /* MULT  */
    DIV = 266,                     /* DIV  */
    PLUS = 267,                    /* PLUS  */
    MINUS = 268,                   /* MINUS  */
    LESS = 269,                    /* LESS  */
    EQ = 270,                      /* EQ  */
    GREATER = 271,                 /* GREATER  */
    NOT_EQ = 272,                  /* NOT_EQ  */
    LESS_EQ = 273,                 /* LESS_EQ  */
    GREATER_EQ = 274,              /* GREATER_EQ  */
    L_PAREN = 275,                 /* L_PAREN  */
    R_PAREN = 276,                 /* R_PAREN  */
    L_BRACK = 277,                 /* L_BRACK  */
    R_BRACK = 278,                 /* R_BRACK  */
    L_CURL = 279,                  /* L_CURL  */
    R_CURL = 280,                  /* R_CURL  */
    EQUAL = 281,                   /* EQUAL  */
    IF = 282,                      /* IF  */
    ELSE = 283,                    /* ELSE  */
    COMMA = 284,                   /* COMMA  */
    BEGIN_PHASE = 285,             /* BEGIN_PHASE  */
    DO = 286,                      /* DO  */
    BEGIN_FUNCTION = 287,          /* BEGIN_FUNCTION  */
    OUT_ARROW = 288,               /* OUT_ARROW  */
    IN_ARROW = 289,                /* IN_ARROW  */
    STOP = 290,                    /* STOP  */
    CONSOLE_IN = 291,              /* CONSOLE_IN  */
    CONSOLE_OUT = 292,             /* CONSOLE_OUT  */
    NEW_LINE = 293                 /* NEW_LINE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 15 "Bison.y"

	char *id;	
	char *keyWord;
	char sym;
	int num;

#line 176 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INTEGER = 3,                    /* INTEGER  */
  YYSYMBOL_IDENTIFIER = 4,                 /* IDENTIFIER  */
  YYSYMBOL_END_STATEMENT = 5,              /* END_STATEMENT  */
  YYSYMBOL_COMMENT_SINGLE = 6,             /* COMMENT_SINGLE  */
  YYSYMBOL_ZERO = 7,                       /* ZERO  */
  YYSYMBOL_NEG_NUM = 8,                    /* NEG_NUM  */
  YYSYMBOL_POS_NUM = 9,                    /* POS_NUM  */
  YYSYMBOL_MULT = 10,                      /* MULT  */
  YYSYMBOL_DIV = 11,                       /* DIV  */
  YYSYMBOL_PLUS = 12,                      /* PLUS  */
  YYSYMBOL_MINUS = 13,                     /* MINUS  */
  YYSYMBOL_LESS = 14,                      /* LESS  */
  YYSYMBOL_EQ = 15,                        /* EQ  */
  YYSYMBOL_GREATER = 16,                   /* GREATER  */
  YYSYMBOL_NOT_EQ = 17,                    /* NOT_EQ  */
  YYSYMBOL_LESS_EQ = 18,                   /* LESS_EQ  */
  YYSYMBOL_GREATER_EQ = 19,                /* GREATER_EQ  */
  YYSYMBOL_L_PAREN = 20,                   /* L_PAREN  */
  YYSYMBOL_R_PAREN = 21,                   /* R_PAREN  */
  YYSYMBOL_L_BRACK = 22,                   /* L_BRACK  */
  YYSYMBOL_R_BRACK = 23,                   /* R_BRACK  */
  YYSYMBOL_L_CURL = 24,                    /* L_CURL  */
  YYSYMBOL_R_CURL = 25,                    /* R_CURL  */
  YYSYMBOL_EQUAL = 26,                     /* EQUAL  */
  YYSYMBOL_IF = 27,                        /* IF  */
  YYSYMBOL_ELSE = 28,                      /* ELSE  */
  YYSYMBOL_COMMA = 29,                     /* COMMA  */
  YYSYMBOL_BEGIN_PHASE = 30,               /* BEGIN_PHASE  */
  YYSYMBOL_DO = 31,                        /* DO  */
  YYSYMBOL_BEGIN_FUNCTION = 32,            /* BEGIN_FUNCTION  */
  YYSYMBOL_OUT_ARROW = 33,                 /* OUT_ARROW  */
  YYSYMBOL_IN_ARROW = 34,                  /* IN_ARROW  */
  YYSYMBOL_STOP = 35,                      /* STOP  */
  YYSYMBOL_CONSOLE_IN = 36,                /* CONSOLE_IN  */
  YYSYMBOL_CONSOLE_OUT = 37,               /* CONSOLE_OUT  */
  YYSYMBOL_NEW_LINE = 38,                  /* NEW_LINE  */
  YYSYMBOL_YYACCEPT = 39,                  /* $accept  */
  YYSYMBOL_fcodeseg = 40,                  /* fcodeseg  */
  YYSYMBOL_codeseg = 41,                   /* codeseg  */
  YYSYMBOL_statement = 42,                 /* statement  */
  YYSYMBOL_number = 43,                    /* number  */
  YYSYMBOL_array = 44,                     /* array  */
  YYSYMBOL_fill = 45,                      /* fill  */
  YYSYMBOL_single_choice = 46,             /* single_choice  */
  YYSYMBOL_Parameter = 47,                 /* Parameter  */
  YYSYMBOL_condition = 48,                 /* condition  */
  YYSYMBOL_choice = 49,                    /* choice  */
  YYSYMBOL_condition_op = 50,              /* condition_op  */
  YYSYMBOL_Expression = 51,                /* Expression  */
  YYSYMBOL_option = 52,                    /* option  */
  YYSYMBOL_operation = 53,                 /* operation  */
  YYSYMBOL_loop = 54,                      /* loop  */
  YYSYMBOL_Function_Call = 55,             /* Function_Call  */
  YYSYMBOL_Parameter_Call = 56,            /* Parameter_Call  */
  YYSYMBOL_if_statement = 57,              /* if_statement  */
  YYSYMBOL_else = 58                       /* else  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
typedef yytype_int8 yy_state_t;

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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   167

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  71
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  120

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   293


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

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
      35,    36,    37,    38
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    38,    38,    39,    40,    41,    42,    45,    46,    47,
      48,    51,    52,    53,    54,    55,    56,    60,    61,    62,
      65,    66,    67,    70,    71,    72,    73,    76,    77,    78,
      84,    85,    86,    90,    91,    92,    95,    96,    97,    98,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     115,   116,   117,   120,   121,   122,   123,   128,   129,   130,
     131,   137,   138,   141,   144,   145,   146,   147,   148,   151,
     154,   155
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "INTEGER",
  "IDENTIFIER", "END_STATEMENT", "COMMENT_SINGLE", "ZERO", "NEG_NUM",
  "POS_NUM", "MULT", "DIV", "PLUS", "MINUS", "LESS", "EQ", "GREATER",
  "NOT_EQ", "LESS_EQ", "GREATER_EQ", "L_PAREN", "R_PAREN", "L_BRACK",
  "R_BRACK", "L_CURL", "R_CURL", "EQUAL", "IF", "ELSE", "COMMA",
  "BEGIN_PHASE", "DO", "BEGIN_FUNCTION", "OUT_ARROW", "IN_ARROW", "STOP",
  "CONSOLE_IN", "CONSOLE_OUT", "NEW_LINE", "$accept", "fcodeseg",
  "codeseg", "statement", "number", "array", "fill", "single_choice",
  "Parameter", "condition", "choice", "condition_op", "Expression",
  "option", "operation", "loop", "Function_Call", "Parameter_Call",
  "if_statement", "else", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-69)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-57)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -69,     4,   -69,     8,   -11,    21,    21,    -1,    16,   -69,
      -7,    32,   -69,   -69,   -69,   -69,    14,    40,   105,    33,
      37,    41,    51,   -69,    61,   112,    63,   -69,    29,   111,
     105,   -69,    38,    30,    64,   141,   145,   149,   -69,   -69,
     153,    53,   -69,   -69,   -69,   -69,   -69,   -69,   -69,   -69,
     -69,   -69,   128,    75,    13,   -69,    72,   -69,   -69,   -69,
     -69,   -69,   -16,   -69,   -69,    35,   -69,   -69,   -69,   -69,
     134,   -69,   -69,   -69,   -69,   -69,   -69,   -69,    95,    58,
      98,   -69,   -69,   107,   106,   140,    92,   -69,   -69,   -69,
     -69,   -69,    48,    56,    21,   -69,   129,   -69,   -69,   -69,
      59,   117,   -69,   113,   -69,   -69,   -69,   -69,   -15,   -69,
     -69,   -69,   -69,   -69,    87,    67,   -69,   -69,   -69,   -69
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       6,     0,     1,     0,    21,     0,     0,     0,    32,    16,
       0,     0,    12,     3,     5,     4,    13,     0,     0,    36,
      39,    38,    37,    35,     0,     0,     0,    10,    32,    68,
       0,     2,     0,     0,    53,    19,    18,    17,    52,    14,
       0,     0,    46,    47,    44,    45,    40,    42,    41,    43,
      49,    48,     0,     0,     0,    31,     0,    65,    19,    18,
      17,    67,     0,    15,    11,    20,    59,    60,    57,    58,
       0,    10,    36,    39,    38,    37,    33,    10,    51,     0,
       0,     9,     8,     0,     0,     0,     0,    53,    56,    55,
      54,    50,     0,     0,     0,     7,     0,    63,    64,    66,
       0,    71,    61,     0,    30,    29,    28,    27,     0,    26,
      10,    69,    62,    22,     0,     0,    25,    24,    23,    70
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -69,   -69,   -68,   138,    -5,   -69,   -69,   -69,   118,    -4,
      88,   -69,   -12,    80,   -69,   166,   -69,   -69,   -69,   -69
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,    54,    80,    38,    12,   108,   109,    29,    24,
      25,    52,    81,    40,    70,    82,    14,    62,    15,   111
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      23,    23,    26,    92,     2,    84,    39,     3,     4,    93,
     113,    17,    16,    85,   114,    18,     3,    78,    63,    28,
      35,    36,    37,    27,    61,    19,    30,    64,    20,    21,
      22,     5,    28,    55,     6,     7,     8,    31,    79,     9,
      32,    10,   115,     6,     7,    58,    59,    60,     9,    33,
      10,     3,    78,    65,   -34,    35,    36,    37,   -19,     3,
      78,    86,   -18,    35,    36,    37,   105,   106,   107,   -51,
       3,    78,   -17,   101,    35,    36,    37,    71,     6,     7,
      99,   102,    41,     9,    53,    10,     6,     7,    94,    23,
     103,     9,   119,    10,   116,   117,   118,     6,     7,    77,
     -21,    83,     9,    95,    10,   -53,   -53,   -53,   -53,    34,
      96,    97,    35,    36,    37,    57,   100,    17,    58,    59,
      60,    18,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    72,   104,   112,    73,    74,    75,    87,    11,
      76,    88,    89,    90,    98,   110,    56,    58,    59,    60,
      91,   -56,   -56,   -56,   -56,   -55,   -55,   -55,   -55,   -54,
     -54,   -54,   -54,    66,    67,    68,    69,    13
};

static const yytype_int8 yycheck[] =
{
       5,     6,     6,    71,     0,    21,    18,     3,     4,    77,
      25,    22,     4,    29,    29,    26,     3,     4,    30,     3,
       7,     8,     9,    24,    29,     4,    33,    32,     7,     8,
       9,    27,     3,     4,    30,    31,    32,     5,    25,    35,
      26,    37,   110,    30,    31,     7,     8,     9,    35,     9,
      37,     3,     4,    23,    21,     7,     8,     9,    21,     3,
       4,    26,    21,     7,     8,     9,     7,     8,     9,     5,
       3,     4,    21,    25,     7,     8,     9,    24,    30,    31,
      85,    25,    21,    35,    21,    37,    30,    31,    30,    94,
      94,    35,    25,    37,     7,     8,     9,    30,    31,    24,
       5,    29,    35,     5,    37,    10,    11,    12,    13,     4,
       3,     5,     7,     8,     9,     4,    24,    22,     7,     8,
       9,    26,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,     4,     4,    21,     7,     8,     9,     4,     1,
      52,     7,     8,     9,     4,    28,    28,     7,     8,     9,
      70,    10,    11,    12,    13,    10,    11,    12,    13,    10,
      11,    12,    13,    10,    11,    12,    13,     1
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    40,     0,     3,     4,    27,    30,    31,    32,    35,
      37,    42,    44,    54,    55,    57,     4,    22,    26,     4,
       7,     8,     9,    43,    48,    49,    48,    24,     3,    47,
      33,     5,    26,     9,     4,     7,     8,     9,    43,    51,
      52,    21,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    50,    21,    41,     4,    47,     4,     7,     8,
       9,    43,    56,    51,    43,    23,    10,    11,    12,    13,
      53,    24,     4,     7,     8,     9,    49,    24,     4,    25,
      42,    51,    54,    29,    21,    29,    26,     4,     7,     8,
       9,    52,    41,    41,    30,     5,     3,     5,     4,    43,
      24,    25,    25,    48,     4,     7,     8,     9,    45,    46,
      28,    58,    21,    25,    29,    41,     7,     8,     9,    25
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    39,    40,    40,    40,    40,    40,    41,    41,    41,
      41,    42,    42,    42,    42,    42,    42,    43,    43,    43,
      44,    44,    44,    45,    45,    45,    45,    46,    46,    46,
      47,    47,    47,    48,    48,    48,    49,    49,    49,    49,
      50,    50,    50,    50,    50,    50,    50,    50,    50,    50,
      51,    51,    51,    52,    52,    52,    52,    53,    53,    53,
      53,    54,    54,    55,    56,    56,    56,    56,    56,    57,
      58,    58
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     2,     2,     2,     0,     3,     2,     2,
       0,     4,     1,     2,     3,     3,     1,     1,     1,     1,
       4,     1,     8,     3,     3,     3,     1,     1,     1,     1,
       5,     2,     0,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     6,     7,     5,     3,     1,     3,     1,     0,     7,
       3,     0
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  case 2: /* fcodeseg: fcodeseg statement END_STATEMENT  */
#line 38 "Bison.y"
                                             {printf("fcodeseg -> fcodeseg statement END_STATEMENT\n");}
#line 1300 "y.tab.c"
    break;

  case 3: /* fcodeseg: fcodeseg loop  */
#line 39 "Bison.y"
                              {printf("fcodeseg -> fcodeseg loop\n");}
#line 1306 "y.tab.c"
    break;

  case 4: /* fcodeseg: fcodeseg if_statement  */
#line 40 "Bison.y"
                                          {printf("fcodeseg -> fcodeseg if_statement\n");}
#line 1312 "y.tab.c"
    break;

  case 5: /* fcodeseg: fcodeseg Function_Call  */
#line 41 "Bison.y"
                                   {printf("fcodeseg -> fcodeseg Function_Call\n");}
#line 1318 "y.tab.c"
    break;

  case 7: /* codeseg: codeseg statement END_STATEMENT  */
#line 45 "Bison.y"
                                            {printf("codeseg -> codeseg statement END_STATEMEN\n");}
#line 1324 "y.tab.c"
    break;

  case 8: /* codeseg: codeseg loop  */
#line 46 "Bison.y"
                         {printf("codeseg -> codeseg loop\n");}
#line 1330 "y.tab.c"
    break;

  case 9: /* codeseg: codeseg Expression  */
#line 47 "Bison.y"
                               {printf("codeseg -> codeseg condition\n");}
#line 1336 "y.tab.c"
    break;

  case 11: /* statement: INTEGER IDENTIFIER EQUAL number  */
#line 51 "Bison.y"
                                             {printf("statment -> INTEGER IDENTIFIER EQUAL number\n");}
#line 1342 "y.tab.c"
    break;

  case 12: /* statement: array  */
#line 52 "Bison.y"
                   {printf("statment -> array\n");}
#line 1348 "y.tab.c"
    break;

  case 13: /* statement: INTEGER IDENTIFIER  */
#line 53 "Bison.y"
                                  {printf("statement -> INTEGER  IDENTIFIER\n");}
#line 1354 "y.tab.c"
    break;

  case 14: /* statement: IDENTIFIER EQUAL Expression  */
#line 54 "Bison.y"
                                                 {printf("statement -> IDENTIFIER EQUAL Expression\n");}
#line 1360 "y.tab.c"
    break;

  case 15: /* statement: CONSOLE_OUT OUT_ARROW Expression  */
#line 55 "Bison.y"
                                                      {printf("statement ->  CONSOLE_OUT OUT_ARROW Expression\n");}
#line 1366 "y.tab.c"
    break;

  case 16: /* statement: STOP  */
#line 56 "Bison.y"
                          {printf("statment -> STOP\n");}
#line 1372 "y.tab.c"
    break;

  case 17: /* number: POS_NUM  */
#line 60 "Bison.y"
                     {printf("number -> POS_NUM\n");}
#line 1378 "y.tab.c"
    break;

  case 18: /* number: NEG_NUM  */
#line 61 "Bison.y"
                             {printf("number -> NEG_NUM\n");}
#line 1384 "y.tab.c"
    break;

  case 19: /* number: ZERO  */
#line 62 "Bison.y"
                          {printf("number -> ZERO\n");}
#line 1390 "y.tab.c"
    break;

  case 20: /* array: IDENTIFIER L_BRACK POS_NUM R_BRACK  */
#line 65 "Bison.y"
                                                {printf("array -> IDENTIFIER L_BRACK POS_NUM R_BRACK\n");}
#line 1396 "y.tab.c"
    break;

  case 21: /* array: IDENTIFIER  */
#line 66 "Bison.y"
                                {printf("array -> IDENTIFIER\n");}
#line 1402 "y.tab.c"
    break;

  case 22: /* array: IDENTIFIER L_BRACK POS_NUM R_BRACK EQUAL L_CURL fill R_CURL  */
#line 67 "Bison.y"
                                                                                 {printf("array -> IDENTIFIER L_BRACK POS_NUM R_BRACK EQUAL L_CURL fill R_CURL\n");}
#line 1408 "y.tab.c"
    break;

  case 23: /* fill: fill COMMA POS_NUM  */
#line 70 "Bison.y"
                                {printf("fill -> fill COMMA POS_NUM\n");}
#line 1414 "y.tab.c"
    break;

  case 24: /* fill: fill COMMA NEG_NUM  */
#line 71 "Bison.y"
                                        {printf("fill -> fill COMMA NEG_NUM\n");}
#line 1420 "y.tab.c"
    break;

  case 25: /* fill: fill COMMA ZERO  */
#line 72 "Bison.y"
                                     {printf("fill -> fill COMMA ZERO\n");}
#line 1426 "y.tab.c"
    break;

  case 26: /* fill: single_choice  */
#line 73 "Bison.y"
                                   {printf("fill -> single_choice\n");}
#line 1432 "y.tab.c"
    break;

  case 27: /* single_choice: POS_NUM  */
#line 76 "Bison.y"
                        {printf("single_choice -> POS_NUM");}
#line 1438 "y.tab.c"
    break;

  case 28: /* single_choice: NEG_NUM  */
#line 77 "Bison.y"
                                    {printf("single_choice -> NEG_NUM");}
#line 1444 "y.tab.c"
    break;

  case 29: /* single_choice: ZERO  */
#line 78 "Bison.y"
                             {printf("single_choice -> ZERO");}
#line 1450 "y.tab.c"
    break;

  case 30: /* Parameter: INTEGER Parameter COMMA INTEGER IDENTIFIER  */
#line 84 "Bison.y"
                                                           {printf("Parameter -> INTEGER Parameter COMMA INTEGER IDENTIFIER\n");}
#line 1456 "y.tab.c"
    break;

  case 31: /* Parameter: INTEGER IDENTIFIER  */
#line 85 "Bison.y"
                                   {printf("Parameter -> INTEGER IDENTIFIER\n");}
#line 1462 "y.tab.c"
    break;

  case 33: /* condition: choice condition_op choice  */
#line 90 "Bison.y"
                                           {printf("condition -> choice_1 condition_op choice_2\n");}
#line 1468 "y.tab.c"
    break;

  case 34: /* condition: IDENTIFIER  */
#line 91 "Bison.y"
                                   {printf("condition -> IDENTIFIER\n");}
#line 1474 "y.tab.c"
    break;

  case 35: /* condition: number  */
#line 92 "Bison.y"
                                   {printf("condition -> number\n");}
#line 1480 "y.tab.c"
    break;

  case 36: /* choice: IDENTIFIER  */
#line 95 "Bison.y"
                               {printf("choice -> IDENTIFIER\n");}
#line 1486 "y.tab.c"
    break;

  case 37: /* choice: POS_NUM  */
#line 96 "Bison.y"
                                    {printf("choice -> POS_NUM\n");}
#line 1492 "y.tab.c"
    break;

  case 38: /* choice: NEG_NUM  */
#line 97 "Bison.y"
                                    {printf("choice -> NEG_NUM\n");}
#line 1498 "y.tab.c"
    break;

  case 39: /* choice: ZERO  */
#line 98 "Bison.y"
                                 {printf("choice -> ZERO\n");}
#line 1504 "y.tab.c"
    break;

  case 40: /* condition_op: LESS  */
#line 103 "Bison.y"
                     {printf("condition_op -> LESS\n");}
#line 1510 "y.tab.c"
    break;

  case 41: /* condition_op: GREATER  */
#line 104 "Bison.y"
                                    {printf("condition_op -> GREATER\n");}
#line 1516 "y.tab.c"
    break;

  case 42: /* condition_op: EQ  */
#line 105 "Bison.y"
                               {printf("condition_op -> EQ\n");}
#line 1522 "y.tab.c"
    break;

  case 43: /* condition_op: NOT_EQ  */
#line 106 "Bison.y"
                                   {printf("condition_op -> NOT_EQ\n");}
#line 1528 "y.tab.c"
    break;

  case 44: /* condition_op: PLUS  */
#line 107 "Bison.y"
                                 {printf("condition_op -> PLUS\n");}
#line 1534 "y.tab.c"
    break;

  case 45: /* condition_op: MINUS  */
#line 108 "Bison.y"
                                  {printf("condition_op -> MINUS\n");}
#line 1540 "y.tab.c"
    break;

  case 46: /* condition_op: MULT  */
#line 109 "Bison.y"
                                 {printf("condition_op -> MULT\n");}
#line 1546 "y.tab.c"
    break;

  case 47: /* condition_op: DIV  */
#line 110 "Bison.y"
                                {printf("condition_op -> DIV\n");}
#line 1552 "y.tab.c"
    break;

  case 48: /* condition_op: GREATER_EQ  */
#line 111 "Bison.y"
                                       {printf("condition_op -> GREATER_EQ\n");}
#line 1558 "y.tab.c"
    break;

  case 49: /* condition_op: LESS_EQ  */
#line 112 "Bison.y"
                                    {printf("condition_op -> LESS_EQ\n");}
#line 1564 "y.tab.c"
    break;

  case 50: /* Expression: option operation option  */
#line 115 "Bison.y"
                                        {printf("Expression -> choice_1 condition_op choice_2\n");}
#line 1570 "y.tab.c"
    break;

  case 51: /* Expression: IDENTIFIER  */
#line 116 "Bison.y"
                                   {printf("Expression -> IDENTIFIER\n");}
#line 1576 "y.tab.c"
    break;

  case 52: /* Expression: number  */
#line 117 "Bison.y"
                                   {printf("Expression -> number\n");}
#line 1582 "y.tab.c"
    break;

  case 53: /* option: IDENTIFIER  */
#line 120 "Bison.y"
                               {printf("option -> IDENTIFIER\n");}
#line 1588 "y.tab.c"
    break;

  case 54: /* option: POS_NUM  */
#line 121 "Bison.y"
                                    {printf("option -> POS_NUM\n");}
#line 1594 "y.tab.c"
    break;

  case 55: /* option: NEG_NUM  */
#line 122 "Bison.y"
                                    {printf("option -> NEG_NUM\n");}
#line 1600 "y.tab.c"
    break;

  case 56: /* option: ZERO  */
#line 123 "Bison.y"
                                 {printf("option -> ZERO\n");}
#line 1606 "y.tab.c"
    break;

  case 57: /* operation: PLUS  */
#line 128 "Bison.y"
                     {printf("operation -> PLUS\n");}
#line 1612 "y.tab.c"
    break;

  case 58: /* operation: MINUS  */
#line 129 "Bison.y"
                                  {printf("operation -> MINUS\n");}
#line 1618 "y.tab.c"
    break;

  case 59: /* operation: MULT  */
#line 130 "Bison.y"
                                 {printf("operation -> MULT\n");}
#line 1624 "y.tab.c"
    break;

  case 60: /* operation: DIV  */
#line 131 "Bison.y"
                                {printf("operation -> DIV\n");}
#line 1630 "y.tab.c"
    break;

  case 61: /* loop: BEGIN_PHASE condition R_PAREN L_CURL codeseg R_CURL  */
#line 137 "Bison.y"
                                                                    {printf("loop -> BEGIN_PHASE condition R_PAREN L_CURL codeseg R_CUR\n");}
#line 1636 "y.tab.c"
    break;

  case 62: /* loop: DO L_CURL codeseg R_CURL BEGIN_PHASE condition R_PAREN  */
#line 138 "Bison.y"
                                                                                   {printf("loop -> DO codeseg R_CURL BEGIN_PHASE condition R_PAREN\n");}
#line 1642 "y.tab.c"
    break;

  case 63: /* Function_Call: BEGIN_FUNCTION Parameter Parameter_Call R_PAREN END_STATEMENT  */
#line 141 "Bison.y"
                                                                              {printf("Function_Call -> BEGIN_FUNCTION Parameter Parameter_Call R_PAREN END_STATEMENT\n");}
#line 1648 "y.tab.c"
    break;

  case 64: /* Parameter_Call: Parameter_Call COMMA IDENTIFIER  */
#line 144 "Bison.y"
                                                {printf("Parameter_Call -> Parameter_Call COMMA IDENTIFIER\n");}
#line 1654 "y.tab.c"
    break;

  case 65: /* Parameter_Call: IDENTIFIER  */
#line 145 "Bison.y"
                                       {printf("Parameter_Call -> IDENTIFIER\n");}
#line 1660 "y.tab.c"
    break;

  case 66: /* Parameter_Call: Parameter_Call COMMA number  */
#line 146 "Bison.y"
                                                        {printf("Parameter_Call -> Parameter_Call COMMA number\n");}
#line 1666 "y.tab.c"
    break;

  case 67: /* Parameter_Call: number  */
#line 147 "Bison.y"
                                   {printf("Parameter_Call -> number\n");}
#line 1672 "y.tab.c"
    break;

  case 69: /* if_statement: IF condition R_PAREN L_CURL codeseg R_CURL else  */
#line 151 "Bison.y"
                                                                {printf("if_statement -> IF condition R_PAREN L_CURL codeseg R_CURL else\n");}
#line 1678 "y.tab.c"
    break;

  case 70: /* else: ELSE codeseg R_CURL  */
#line 154 "Bison.y"
                                    {printf("else -> ELSE L_CURL codeseg R_CURL\n");}
#line 1684 "y.tab.c"
    break;


#line 1688 "y.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 158 "Bison.y"



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
	return 0;
} 


int yyerror(char * s)
{
	printf("ERROR: %s\n", s);
	return 0;
}
