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
#line 1 "bison.y"

#include <math.h>
#include "flex.yy.h"
#include "tabla_simbolos.h"
#include "errores.h"
#include <stdbool.h>

// Variables globales
contenedor c;
bool hacerEcho = true;
bool script = false;
bool error = false;


#line 86 "bison.tab.c"

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

#include "bison.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NUM = 3,                        /* NUM  */
  YYSYMBOL_CONSTANTE = 4,                  /* CONSTANTE  */
  YYSYMBOL_VARIABLE = 5,                   /* VARIABLE  */
  YYSYMBOL_FUNC0 = 6,                      /* FUNC0  */
  YYSYMBOL_FUNC1 = 7,                      /* FUNC1  */
  YYSYMBOL_COMANDO0 = 8,                   /* COMANDO0  */
  YYSYMBOL_COMANDO1 = 9,                   /* COMANDO1  */
  YYSYMBOL_ARCHIVO = 10,                   /* ARCHIVO  */
  YYSYMBOL_LIB = 11,                       /* LIB  */
  YYSYMBOL_12_ = 12,                       /* '-'  */
  YYSYMBOL_13_ = 13,                       /* '+'  */
  YYSYMBOL_14_ = 14,                       /* '*'  */
  YYSYMBOL_15_ = 15,                       /* '/'  */
  YYSYMBOL_16_ = 16,                       /* '%'  */
  YYSYMBOL_NEG = 17,                       /* NEG  */
  YYSYMBOL_18_ = 18,                       /* '^'  */
  YYSYMBOL_19_n_ = 19,                     /* '\n'  */
  YYSYMBOL_20_ = 20,                       /* ';'  */
  YYSYMBOL_21_ = 21,                       /* '('  */
  YYSYMBOL_22_ = 22,                       /* ')'  */
  YYSYMBOL_23_ = 23,                       /* '='  */
  YYSYMBOL_24_ = 24,                       /* ','  */
  YYSYMBOL_YYACCEPT = 25,                  /* $accept  */
  YYSYMBOL_entrada = 26,                   /* entrada  */
  YYSYMBOL_linea = 27,                     /* linea  */
  YYSYMBOL_expresion = 28,                 /* expresion  */
  YYSYMBOL_asignacion = 29,                /* asignacion  */
  YYSYMBOL_comando = 30,                   /* comando  */
  YYSYMBOL_funcion = 31                    /* funcion  */
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
#define YYLAST   173

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  25
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  7
/* YYNRULES -- Number of rules.  */
#define YYNRULES  45
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  87

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   267


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
      19,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    16,     2,     2,
      21,    22,    14,    13,    24,    12,     2,    15,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    20,
       2,    23,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    18,     2,     2,     2,     2,     2,
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
       5,     6,     7,     8,     9,    10,    11,    17
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    45,    45,    50,    53,    54,    67,    78,    91,   102,
     111,   120,   133,   147,   148,   153,   163,   170,   177,   184,
     191,   204,   217,   224,   233,   248,   263,   269,   278,   283,
     288,   303,   318,   332,   346,   359,   372,   388,   394,   403,
     415,   439,   462,   471,   478,   485
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
  "\"end of file\"", "error", "\"invalid token\"", "NUM", "CONSTANTE",
  "VARIABLE", "FUNC0", "FUNC1", "COMANDO0", "COMANDO1", "ARCHIVO", "LIB",
  "'-'", "'+'", "'*'", "'/'", "'%'", "NEG", "'^'", "'\\n'", "';'", "'('",
  "')'", "'='", "','", "$accept", "entrada", "linea", "expresion",
  "asignacion", "comando", "funcion", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-21)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -21,    27,   -21,   -21,   -20,   -16,    -9,    -7,     7,    18,
      71,   -21,    71,   -21,   142,     0,    31,    50,    60,    60,
      71,    15,   -21,   -21,   -21,    -4,    42,   -21,   -21,    38,
      98,    71,    71,    71,    71,    71,    71,   -21,    41,    37,
     -21,    61,   -21,    63,   -21,    70,   152,   -21,   152,   -21,
     109,   -21,    57,    69,    73,    80,   -21,    83,   -21,    39,
      39,    -5,    -5,    38,    38,   -21,   -21,    72,   -21,   -21,
     -21,   -21,   -21,   -21,   -21,   -21,    40,   -21,    71,   -21,
      85,   120,   -21,    71,   -21,   131,   -21
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     1,    13,    14,    15,     0,    28,    30,     0,
       0,     4,     0,     3,     0,     0,     0,     0,     0,     0,
       0,     0,    34,    35,    37,     0,     0,    14,    15,    16,
       0,     0,     0,     0,     0,     0,     0,     5,     0,     0,
       7,     0,     9,     0,    11,     0,    26,    27,    24,    25,
       0,    29,     0,     0,     0,     0,    31,     0,    23,    18,
      17,    19,    20,    21,    22,     6,    45,     0,     8,    10,
      12,    39,    36,    32,    33,    38,     0,    43,     0,    42,
       0,     0,    40,     0,    44,     0,    41
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -21,   -21,   -21,   -10,   -21,   -21,    59
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,    13,    14,    15,    16,    17
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      29,    52,    30,    18,    53,    54,    55,    19,    46,    48,
      50,    35,    20,    36,    21,    22,    23,    24,    56,    40,
      41,    59,    60,    61,    62,    63,    64,     2,    25,    67,
       3,     4,     5,    26,     6,     7,     8,    51,     9,    10,
       3,    27,    28,     3,    27,    28,    11,    57,    12,    10,
      42,    43,    10,    33,    34,    35,    36,    36,    12,    66,
      65,    12,    79,     3,    27,    28,    80,     6,    81,    44,
      45,     9,    10,    85,     3,    27,    28,    47,    49,    72,
      68,    12,    69,    10,    31,    32,    33,    34,    35,    70,
      36,    73,    12,     0,    77,    74,    78,    31,    32,    33,
      34,    35,    75,    36,    76,     0,     0,    82,     0,    83,
      31,    32,    33,    34,    35,     0,    36,     0,     0,     0,
      58,    31,    32,    33,    34,    35,     0,    36,     0,     0,
       0,    71,    31,    32,    33,    34,    35,     0,    36,     0,
       0,     0,    84,    31,    32,    33,    34,    35,     0,    36,
       0,     0,     0,    86,    31,    32,    33,    34,    35,     0,
      36,    37,    38,    39,    31,    32,    33,    34,    35,     0,
      36,     0,     0,    39
};

static const yytype_int8 yycheck[] =
{
      10,     5,    12,    23,     8,     9,    10,    23,    18,    19,
      20,    16,    21,    18,    21,     8,     9,    10,    22,    19,
      20,    31,    32,    33,    34,    35,    36,     0,    21,    39,
       3,     4,     5,    15,     7,     8,     9,    22,    11,    12,
       3,     4,     5,     3,     4,     5,    19,     5,    21,    12,
      19,    20,    12,    14,    15,    16,    18,    18,    21,    22,
      19,    21,    22,     3,     4,     5,    76,     7,    78,    19,
      20,    11,    12,    83,     3,     4,     5,    18,    19,    22,
      19,    21,    19,    12,    12,    13,    14,    15,    16,    19,
      18,    22,    21,    -1,    22,    22,    24,    12,    13,    14,
      15,    16,    22,    18,    21,    -1,    -1,    22,    -1,    24,
      12,    13,    14,    15,    16,    -1,    18,    -1,    -1,    -1,
      22,    12,    13,    14,    15,    16,    -1,    18,    -1,    -1,
      -1,    22,    12,    13,    14,    15,    16,    -1,    18,    -1,
      -1,    -1,    22,    12,    13,    14,    15,    16,    -1,    18,
      -1,    -1,    -1,    22,    12,    13,    14,    15,    16,    -1,
      18,    19,    20,    21,    12,    13,    14,    15,    16,    -1,
      18,    -1,    -1,    21
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    26,     0,     3,     4,     5,     7,     8,     9,    11,
      12,    19,    21,    27,    28,    29,    30,    31,    23,    23,
      21,    21,     8,     9,    10,    21,    15,     4,     5,    28,
      28,    12,    13,    14,    15,    16,    18,    19,    20,    21,
      19,    20,    19,    20,    19,    20,    28,    31,    28,    31,
      28,    22,     5,     8,     9,    10,    22,     5,    22,    28,
      28,    28,    28,    28,    28,    19,    22,    28,    19,    19,
      19,    22,    22,    22,    22,    22,    21,    22,    24,    22,
      28,    28,    22,    24,    22,    28,    22
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    25,    26,    26,    27,    27,    27,    27,    27,    27,
      27,    27,    27,    28,    28,    28,    28,    28,    28,    28,
      28,    28,    28,    28,    29,    29,    29,    29,    30,    30,
      30,    30,    30,    30,    30,    30,    30,    30,    30,    31,
      31,    31,    31,    31,    31,    31
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     1,     2,     3,     2,     3,     2,
       3,     2,     3,     1,     1,     1,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     3,
       1,     3,     4,     4,     2,     2,     4,     2,     4,     4,
       6,     8,     5,     4,     6,     3
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
  case 2: /* entrada: %empty  */
#line 45 "bison.y"
                        {
                            if (!script) {
                                printf(CYAN">"RESET" ");
                            }
                        }
#line 1168 "bison.tab.c"
    break;

  case 4: /* linea: '\n'  */
#line 53 "bison.y"
                        { printf(CYAN">"RESET" "); }
#line 1174 "bison.tab.c"
    break;

  case 5: /* linea: expresion '\n'  */
#line 54 "bison.y"
                                      {
                                    if (!error) {
                                        if (isnan((yyvsp[-1].numero))) {
                                            lanzar_error("NAN_DETECTADO");
                                        } else if (hacerEcho) {
                                            printf(VERDE"  %lf"RESET"\n\n", (yyvsp[-1].numero));
                                        }
                                    }
                                    if (!script) {
                                        printf(CYAN">"RESET" ");
                                    }
                                    error = false;
                                }
#line 1192 "bison.tab.c"
    break;

  case 6: /* linea: expresion ';' '\n'  */
#line 67 "bison.y"
                                      {
                                    if (!error) {
                                        if (isnan((yyvsp[-2].numero))) {
                                            lanzar_error("NAN_DETECTADO");
                                        }
                                    }
                                    if (!script) {
                                        printf(CYAN">"RESET" ");
                                    }
                                    error = false;
                                }
#line 1208 "bison.tab.c"
    break;

  case 7: /* linea: asignacion '\n'  */
#line 78 "bison.y"
                              {
                            if (!error) {
                                if (isnan((yyvsp[-1].numero))) {
                                    lanzar_error("NAN_DETECTADO");
                                } else if (hacerEcho) {
                                    printf(VERDE"  %lf"RESET"\n\n", (yyvsp[-1].numero));
                                }
                            }
                            if (!script) {
                                printf(CYAN">"RESET" ");
                            }
                            error = false;
                        }
#line 1226 "bison.tab.c"
    break;

  case 8: /* linea: asignacion ';' '\n'  */
#line 91 "bison.y"
                                      {
                                    if (!error) {
                                        if (isnan((yyvsp[-2].numero))) {
                                            lanzar_error("NAN_DETECTADO");
                                        }
                                    }
                                    if (!script) {
                                        printf(CYAN">"RESET" ");
                                    }
                                    error = false;
                                }
#line 1242 "bison.tab.c"
    break;

  case 9: /* linea: comando '\n'  */
#line 102 "bison.y"
                               {
                                if (isnan((yyvsp[-1].numero)) && !error) {
                                    lanzar_error("NAN_DETECTADO");
                                }
                                if (!script) {
                                    printf(CYAN">"RESET" ");
                                }
                                error = false;
                            }
#line 1256 "bison.tab.c"
    break;

  case 10: /* linea: comando ';' '\n'  */
#line 111 "bison.y"
                                   {
                                    if (isnan((yyvsp[-2].numero)) && !error) {
                                        lanzar_error("NAN_DETECTADO");
                                    }
                                    if (!script) {
                                        printf(CYAN">"RESET" ");
                                    }
                                    error = false;
                                }
#line 1270 "bison.tab.c"
    break;

  case 11: /* linea: funcion '\n'  */
#line 120 "bison.y"
                                {
                                if (!error) {
                                    if (isnan((yyvsp[-1].numero))) {
                                        lanzar_error("NAN_DETECTADO");
                                    } else if (hacerEcho) {
                                        printf(VERDE"  %lf"RESET"\n\n", (yyvsp[-1].numero));
                                    }
                                }
                                if (!script) {
                                    printf(CYAN">"RESET" ");
                                }
                                error = false;
                            }
#line 1288 "bison.tab.c"
    break;

  case 12: /* linea: funcion ';' '\n'  */
#line 133 "bison.y"
                                 {
                                    if (!error) {
                                        if (isnan((yyvsp[-2].numero))) {
                                            lanzar_error("NAN_DETECTADO");
                                        }
                                    }
                                    if (!script) {
                                        printf(CYAN">"RESET" ");
                                    }
                                    error = false;
                                }
#line 1304 "bison.tab.c"
    break;

  case 14: /* expresion: CONSTANTE  */
#line 148 "bison.y"
                            {
                            c = buscar_elemento((yyvsp[0].cadena));
                            (yyval.numero) = c.valor.var;
                            free((yyvsp[0].cadena));
                        }
#line 1314 "bison.tab.c"
    break;

  case 15: /* expresion: VARIABLE  */
#line 153 "bison.y"
                             {
                            if ((c = buscar_elemento((yyvsp[0].cadena))).lexema != NULL) {
                                (yyval.numero) = c.valor.var;
                            } else {
                                lanzar_error("VARIABLE_NON_DEFINIDA");
                                error = true;
                                (yyval.numero) = NAN;
                            }
                            free((yyvsp[0].cadena));
                        }
#line 1329 "bison.tab.c"
    break;

  case 16: /* expresion: '-' expresion  */
#line 163 "bison.y"
                                  {
                                 if (!isnan((yyvsp[0].numero))) {
                                     (yyval.numero) = -(yyvsp[0].numero);
                                 } else {
                                     (yyval.numero) = NAN;
                                 }
                            }
#line 1341 "bison.tab.c"
    break;

  case 17: /* expresion: expresion '+' expresion  */
#line 170 "bison.y"
                                    {
                            if (!isnan((yyvsp[-2].numero)) && !isnan((yyvsp[0].numero))) {
                                (yyval.numero) = (yyvsp[-2].numero) + (yyvsp[0].numero);
                            } else {
                                (yyval.numero) = NAN;
                            }
                        }
#line 1353 "bison.tab.c"
    break;

  case 18: /* expresion: expresion '-' expresion  */
#line 177 "bison.y"
                                    {
                            if (!isnan((yyvsp[-2].numero)) && !isnan((yyvsp[0].numero))) {
                                (yyval.numero) = (yyvsp[-2].numero) - (yyvsp[0].numero);
                            } else {
                                (yyval.numero) = NAN;
                            }
                        }
#line 1365 "bison.tab.c"
    break;

  case 19: /* expresion: expresion '*' expresion  */
#line 184 "bison.y"
                                    {
                            if (!isnan((yyvsp[-2].numero)) && !isnan((yyvsp[0].numero))) {
                                (yyval.numero) = (yyvsp[-2].numero) * (yyvsp[0].numero);
                            } else {
                                (yyval.numero) = NAN;
                            }
                        }
#line 1377 "bison.tab.c"
    break;

  case 20: /* expresion: expresion '/' expresion  */
#line 191 "bison.y"
                                    {
                            if ((yyvsp[0].numero) == 0) {
                                lanzar_error("DIV_CERO");
                                error = true;
                                (yyval.numero) = NAN;
                            } else {
                                if (!isnan((yyvsp[-2].numero)) && !isnan((yyvsp[0].numero))) {
                                    (yyval.numero) = (yyvsp[-2].numero) / (yyvsp[0].numero);
                                } else {
                                    (yyval.numero) = NAN;
                                }
                            }
                        }
#line 1395 "bison.tab.c"
    break;

  case 21: /* expresion: expresion '%' expresion  */
#line 204 "bison.y"
                                    {
                            if ((yyvsp[0].numero) == 0) {
                                lanzar_error("MOD_CERO");
                                error = true;
                                (yyval.numero) = NAN;
                            } else {
                                if (!isnan((yyvsp[-2].numero)) && !isnan((yyvsp[0].numero))) {
                                    (yyval.numero) = fmod((yyvsp[-2].numero), (yyvsp[0].numero));
                                } else {
                                    (yyval.numero) = NAN;
                                }
                            }
                        }
#line 1413 "bison.tab.c"
    break;

  case 22: /* expresion: expresion '^' expresion  */
#line 217 "bison.y"
                                    {
                            if (!isnan((yyvsp[-2].numero)) && !isnan((yyvsp[0].numero))) {
                                (yyval.numero) = pow((yyvsp[-2].numero), (yyvsp[0].numero));
                            } else {
                                (yyval.numero) = NAN;
                            }
                        }
#line 1425 "bison.tab.c"
    break;

  case 23: /* expresion: '(' expresion ')'  */
#line 224 "bison.y"
                              {
                             if (!isnan((yyvsp[-1].numero))) {
                                 (yyval.numero) = (yyvsp[-1].numero);
                             } else {
                                 (yyval.numero) = NAN;
                             }
                         }
#line 1437 "bison.tab.c"
    break;

  case 24: /* asignacion: VARIABLE '=' expresion  */
#line 233 "bison.y"
                                         {
                           if (!error) {
                               if ((c = buscar_elemento((yyvsp[-2].cadena))).lexema != NULL) {
                                   asignar_valor((yyvsp[-2].cadena), (yyvsp[0].numero));
                               } else {
                                   c.lexema = strdup((yyvsp[-2].cadena));
                                   c.comp_lexico = VARIABLE;
                                   c.valor.var = (yyvsp[0].numero);
                                   insertar_elemento(c);
                                   free(c.lexema);
                               }
                           }
                           (yyval.numero) = (yyvsp[0].numero);
                           free((yyvsp[-2].cadena));
                        }
#line 1457 "bison.tab.c"
    break;

  case 25: /* asignacion: VARIABLE '=' funcion  */
#line 248 "bison.y"
                                 {
                           if (!error) {
                               if ((c = buscar_elemento((yyvsp[-2].cadena))).lexema != NULL) {
                                   asignar_valor((yyvsp[-2].cadena), (yyvsp[0].numero));
                               } else {
                                   c.lexema = strdup((yyvsp[-2].cadena));
                                   c.comp_lexico = VARIABLE;
                                   c.valor.var = (yyvsp[0].numero);
                                   insertar_elemento(c);
                                   free(c.lexema);
                               }
                           }
                           (yyval.numero) = (yyvsp[0].numero);
                           free((yyvsp[-2].cadena));
                        }
#line 1477 "bison.tab.c"
    break;

  case 26: /* asignacion: CONSTANTE '=' expresion  */
#line 263 "bison.y"
                                  {
                            lanzar_error("CONSTANTE_NON_MODIFICABLE");
                            error = true;
                            (yyval.numero) = NAN;
                            free((yyvsp[-2].cadena));
                        }
#line 1488 "bison.tab.c"
    break;

  case 27: /* asignacion: CONSTANTE '=' funcion  */
#line 269 "bison.y"
                                {
                            lanzar_error("CONSTANTE_NON_MODIFICABLE");
                            error = true;
                            (yyval.numero) = NAN;
                            free((yyvsp[-2].cadena));
                        }
#line 1499 "bison.tab.c"
    break;

  case 28: /* comando: COMANDO0  */
#line 278 "bison.y"
                                    {
                                        c = buscar_elemento((yyvsp[0].cadena));
                                        free((yyvsp[0].cadena));
                                        (*(c.valor.funcptr))();
                                    }
#line 1509 "bison.tab.c"
    break;

  case 29: /* comando: COMANDO0 '(' ')'  */
#line 283 "bison.y"
                                       {
                                        c = buscar_elemento((yyvsp[-2].cadena));
                                        free((yyvsp[-2].cadena));
                                        (*(c.valor.funcptr))();
                                    }
#line 1519 "bison.tab.c"
    break;

  case 30: /* comando: COMANDO1  */
#line 288 "bison.y"
                    {
                                        c = buscar_elemento((yyvsp[0].cadena));
                                        int result1 = strcmp(c.lexema, "clear");
                                        int result2 = strcmp(c.lexema, "help");
                                        int result3 = strcmp(c.lexema, "?");
                                        int result4 = strcmp(c.lexema, "echo");
                                        if (result1 == 0 || result2 == 0 || result3 == 0 || result4 == 0) {
                                            (*(c.valor.funcptr))(NULL);
                                        } else {
                                            lanzar_error("La función tiene argumentos");
                                            error = true;
                                            (yyval.numero) = NAN;
                                        }
                                        free((yyvsp[0].cadena));
                                    }
#line 1539 "bison.tab.c"
    break;

  case 31: /* comando: COMANDO1 '(' ')'  */
#line 303 "bison.y"
                                       {
                                        c = buscar_elemento((yyvsp[-2].cadena));
                                        int result1 = strcmp(c.lexema, "clear");
                                        int result2 = strcmp(c.lexema, "help");
                                        int result3 = strcmp(c.lexema, "?");
                                        int result4 = strcmp(c.lexema, "echo");
                                        if (result1 == 0 || result2 == 0 || result3 == 0 || result4 == 0) {
                                            (*(c.valor.funcptr))(NULL);
                                        } else {
                                            lanzar_error("La función tiene argumentos");
                                            error = true;
                                            (yyval.numero) = NAN;
                                        }
                                        free((yyvsp[-2].cadena));
                                       }
#line 1559 "bison.tab.c"
    break;

  case 32: /* comando: COMANDO1 '(' COMANDO0 ')'  */
#line 318 "bison.y"
                                       {
                                        c = buscar_elemento((yyvsp[-3].cadena));
                                        int result1 = strcmp(c.lexema, "help");
                                        int result2 = strcmp(c.lexema, "?");
                                        if (result1 == 0 || result2 == 0) {
                                               (*(c.valor.funcptr))((yyvsp[-1].cadena));
                                        } else {
                                            lanzar_error("El argumento no puede ser un comando");
                                            error = true;
                                            (yyval.numero) = NAN;
                                        }
                                        free((yyvsp[-3].cadena));
                                        free((yyvsp[-1].cadena));
                                       }
#line 1578 "bison.tab.c"
    break;

  case 33: /* comando: COMANDO1 '(' COMANDO1 ')'  */
#line 332 "bison.y"
                                       {
                                                c = buscar_elemento((yyvsp[-3].cadena));
                                                int result1 = strcmp(c.lexema, "help");
                                                int result2 = strcmp(c.lexema, "?");
                                                if (result1 == 0 || result2 == 0) {
                                                       (*(c.valor.funcptr))((yyvsp[-1].cadena));
                                                } else {
                                                    lanzar_error("El argumento no puede ser un comando");
                                                    error = true;
                                                    (yyval.numero) = NAN;
                                                }
                                                free((yyvsp[-3].cadena));
                                                free((yyvsp[-1].cadena));
                                               }
#line 1597 "bison.tab.c"
    break;

  case 34: /* comando: COMANDO1 COMANDO0  */
#line 346 "bison.y"
                                     {
                                        c = buscar_elemento((yyvsp[-1].cadena));
                                        int result1 = strcmp(c.lexema, "?");
                                        if (result1 == 0) {
                                            (*(c.valor.funcptr))((yyvsp[0].cadena));
                                        } else {
                                            lanzar_error("Sintaxis incorrecta: faltan los paréntesis");
                                            error = true;
                                            (yyval.numero) = NAN;
                                        }
                                        free((yyvsp[-1].cadena));
                                        free((yyvsp[0].cadena));
                                     }
#line 1615 "bison.tab.c"
    break;

  case 35: /* comando: COMANDO1 COMANDO1  */
#line 359 "bison.y"
                                     {
                                                c = buscar_elemento((yyvsp[-1].cadena));
                                                int result1 = strcmp(c.lexema, "?");
                                                if (result1 == 0) {
                                                    (*(c.valor.funcptr))((yyvsp[0].cadena));
                                                } else {
                                                    lanzar_error("Sintaxis incorrecta: faltan los paréntesis");
                                                    error = true;
                                                    (yyval.numero) = NAN;
                                                }
                                                free((yyvsp[-1].cadena));
                                                free((yyvsp[0].cadena));
                                             }
#line 1633 "bison.tab.c"
    break;

  case 36: /* comando: COMANDO1 '(' VARIABLE ')'  */
#line 372 "bison.y"
                                     {
                                         c = buscar_elemento((yyvsp[-3].cadena));
                                         int result1 = strcmp(c.lexema, "echo");
                                         if (c.lexema != NULL && c.valor.funcptr != NULL) {
                                             if (result1 == 0) {
                                                cambiar_echo((*(c.valor.funcptr))((yyvsp[-1].cadena)));
                                             } else {
                                                (yyval.numero) = (*(c.valor.funcptr))((yyvsp[-1].cadena));
                                             }
                                         } else {
                                             lanzar_error("No se encuentra el comando");
                                             error = true;
                                             (yyval.numero) = NAN;
                                         }
                                         free((yyvsp[-3].cadena));
                                      }
#line 1654 "bison.tab.c"
    break;

  case 37: /* comando: COMANDO1 ARCHIVO  */
#line 388 "bison.y"
                                        {
                                        c = buscar_elemento((yyvsp[-1].cadena));
                                        (*(c.valor.funcptr))((yyvsp[0].cadena));
                                        free((yyvsp[-1].cadena));
                                        free((yyvsp[0].cadena));
                                     }
#line 1665 "bison.tab.c"
    break;

  case 38: /* comando: COMANDO1 '(' ARCHIVO ')'  */
#line 394 "bison.y"
                                        {
                                        c = buscar_elemento((yyvsp[-3].cadena));
                                        (*(c.valor.funcptr))((yyvsp[-1].cadena));
                                        free((yyvsp[-3].cadena));
                                        free((yyvsp[-1].cadena));
                                     }
#line 1676 "bison.tab.c"
    break;

  case 39: /* funcion: FUNC1 '(' expresion ')'  */
#line 403 "bison.y"
                                 {
                                                c = buscar_elemento((yyvsp[-3].cadena));
                                                if (c.lexema != NULL && c.valor.funcptr != NULL) {
                                                    (yyval.numero) = (*(c.valor.funcptr))((yyvsp[-1].numero));
                                                } else {
                                                    lanzar_error("No se encuentra la función básica");
                                                    error = true;
                                                    (yyval.numero) = NAN;
                                                }
                                                free((yyvsp[-3].cadena));

                                          }
#line 1693 "bison.tab.c"
    break;

  case 40: /* funcion: LIB '/' VARIABLE '(' expresion ')'  */
#line 415 "bison.y"
                                              {
                                                /*
                                                c = buscar_elemento($1);

                                                char *libfunc = malloc(((strlen($1) + strlen($3) + 2) * sizeof(char)));
                                                strncpy(libfunc, $1, strlen($1));
                                                strncpy(libfunc + strlen($1), "/", 2);
                                                strncpy(libfunc + strlen($1) + 1, $3, strlen($3));
                                                libfunc[strlen($1) + strlen($3) + 1] = '\0';

                                                cLexico c_func = buscarFuncion(c.valor.libhandle, $3, libfunc);
                                                if (c_func.lexema != NULL) {
                                                    $$ = (*(c_func.valor.funcptr))($5);
                                                } else {
                                                    lanzar_error("FUNCION_NON_ATOPADA");
                                                    error = true;
                                                    $$ = NAN;
                                                }
                                                free(libfunc);
                                                free($1);
                                                free($3);
                                                */

                                            }
#line 1722 "bison.tab.c"
    break;

  case 41: /* funcion: LIB '/' VARIABLE '(' expresion ',' expresion ')'  */
#line 439 "bison.y"
                                                             {
                                                /*
                                                c = buscar_elemento($1);

                                                char *libfunc = malloc(((strlen($1) + strlen($3) + 2) * sizeof(char)));
                                                strncpy(libfunc, $1, strlen($1));
                                                strncpy(libfunc + strlen($1), "/", 2);
                                                strncpy(libfunc + strlen($1) + 1, $3, strlen($3));
                                                libfunc[strlen($1) + strlen($3) + 1] = '\0';

                                                cLexico c_func = buscarFuncion(c.valor.libhandle, $3, libfunc);
                                                if (c_func.lexema != NULL) {
                                                    $$ = (*(c_func.valor.funcptr))($5, $7);
                                                } else {
                                                    lanzar_error("FUNCION_NON_ATOPADA");
                                                    error = true;
                                                    $$ = NAN;
                                                }
                                                free(libfunc);
                                                free($1);
                                                free($3);
                                                */
                                            }
#line 1750 "bison.tab.c"
    break;

  case 42: /* funcion: LIB '/' VARIABLE '(' ')'  */
#line 462 "bison.y"
                                                 {
                                                /*
                                                lanzar_error("PARAMETROS_NON_INDICADOS");
                                                error = true;
                                                $$ = NAN;
                                                free($1);
                                                free($3);
                                                */
                                            }
#line 1764 "bison.tab.c"
    break;

  case 43: /* funcion: expresion '(' expresion ')'  */
#line 471 "bison.y"
                                                        {
                                                /*
                                                lanzar_error("LIBRERIA_NON_ATOPADA");
                                                error = true;
                                                $$ = NAN;
                                                */
                                            }
#line 1776 "bison.tab.c"
    break;

  case 44: /* funcion: expresion '(' expresion ',' expresion ')'  */
#line 478 "bison.y"
                                                              {
                                                /*
                                                lanzar_error("LIBRERIA_NON_ATOPADA");
                                                error = true;
                                                $$ = NAN;
                                                */
                                            }
#line 1788 "bison.tab.c"
    break;

  case 45: /* funcion: expresion '(' ')'  */
#line 485 "bison.y"
                                                  {
                                                /*
                                                lanzar_error("LIBRERIA_NON_ATOPADA");
                                                error = true;
                                                $$ = NAN;
                                                */
                                            }
#line 1800 "bison.tab.c"
    break;


#line 1804 "bison.tab.c"

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

#line 494 "bison.y"


void yyerror(char* s) {
    lanzar_error("Sintaxis no válida");
}

void cambiar_echo(double valor) {
    if (valor == 1) { hacerEcho = true; }
    else if (valor == 2) { hacerEcho = false; }
}

void ejecutar_script(int valor) {
    script = valor;
    if (!script) {
        printf("\n"AMARILLO"Script ejecutado correctamente."RESET"\n\n"CYAN">"RESET" ");
    }
}


