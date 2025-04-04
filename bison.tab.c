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

#include "flex.yy.h"
#include "tabla_simbolos.h"
#include "errores.h"
#include <stdbool.h>
# include "interprete.h"

// Variables globales
contenedor c;
bool hacerEcho = true;
bool script = false;
bool error = false;
double ANS = NAN;

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
  YYSYMBOL_FUNC2 = 8,                      /* FUNC2  */
  YYSYMBOL_COMANDO0 = 9,                   /* COMANDO0  */
  YYSYMBOL_COMANDO1 = 10,                  /* COMANDO1  */
  YYSYMBOL_ARCHIVO = 11,                   /* ARCHIVO  */
  YYSYMBOL_LIB = 12,                       /* LIB  */
  YYSYMBOL_RETURN = 13,                    /* RETURN  */
  YYSYMBOL_DEF = 14,                       /* DEF  */
  YYSYMBOL_15_ = 15,                       /* '-'  */
  YYSYMBOL_16_ = 16,                       /* '+'  */
  YYSYMBOL_17_ = 17,                       /* '*'  */
  YYSYMBOL_18_ = 18,                       /* '/'  */
  YYSYMBOL_19_ = 19,                       /* '%'  */
  YYSYMBOL_NEG = 20,                       /* NEG  */
  YYSYMBOL_21_ = 21,                       /* '^'  */
  YYSYMBOL_22_n_ = 22,                     /* '\n'  */
  YYSYMBOL_23_ = 23,                       /* ';'  */
  YYSYMBOL_24_ = 24,                       /* ','  */
  YYSYMBOL_25_ = 25,                       /* '('  */
  YYSYMBOL_26_ = 26,                       /* ')'  */
  YYSYMBOL_27_ = 27,                       /* '='  */
  YYSYMBOL_YYACCEPT = 28,                  /* $accept  */
  YYSYMBOL_entrada = 29,                   /* entrada  */
  YYSYMBOL_linea = 30,                     /* linea  */
  YYSYMBOL_lista_expresiones = 31,         /* lista_expresiones  */
  YYSYMBOL_expresion = 32,                 /* expresion  */
  YYSYMBOL_asignacion = 33,                /* asignacion  */
  YYSYMBOL_comando = 34,                   /* comando  */
  YYSYMBOL_funcion = 35                    /* funcion  */
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
#define YYLAST   199

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  28
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  8
/* YYNRULES -- Number of rules.  */
#define YYNRULES  51
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  96

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   270


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
      22,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    19,     2,     2,
      25,    26,    17,    16,    24,    15,     2,    18,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    23,
       2,    27,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    21,     2,     2,     2,     2,     2,
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
      20
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    47,    47,    52,    55,    56,    69,    80,    94,   105,
     114,   123,   136,   147,   156,   163,   175,   176,   181,   196,
     208,   213,   218,   230,   247,   252,   259,   266,   273,   280,
     293,   306,   313,   323,   338,   353,   359,   368,   373,   378,
     393,   408,   422,   436,   449,   462,   478,   484,   492,   493,
     517,   540
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
  "VARIABLE", "FUNC0", "FUNC1", "FUNC2", "COMANDO0", "COMANDO1", "ARCHIVO",
  "LIB", "RETURN", "DEF", "'-'", "'+'", "'*'", "'/'", "'%'", "NEG", "'^'",
  "'\\n'", "';'", "','", "'('", "')'", "'='", "$accept", "entrada",
  "linea", "lista_expresiones", "expresion", "asignacion", "comando",
  "funcion", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-20)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-49)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -20,    29,   -20,   -14,   -20,     8,    16,    23,    25,    30,
       6,    35,   107,   -20,   107,   -20,   169,   -19,    -9,    40,
     -20,    94,    94,    53,    66,    33,   -20,   -20,   -20,    -4,
      59,   -20,   -20,    45,   145,   107,   107,   107,   107,   107,
     107,   -20,    50,   -20,    63,   -20,    67,   -20,    68,   178,
     -20,   178,   -20,   -20,    -6,   109,   -20,    -5,   121,   -20,
      62,    69,    70,    74,   -20,    78,   -20,    28,    28,    21,
      21,    45,    45,   -20,   -20,   -20,   -20,   107,   -20,   107,
     -20,   -20,   -20,   -20,   -20,   -20,   -20,    79,   178,   178,
     -20,   133,   107,   -20,   157,   -20
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     1,     0,    16,    17,    18,     0,     0,    37,
      39,     0,     0,     4,     0,     3,     0,     0,     0,     0,
      13,    48,    48,     0,     0,     0,    43,    44,    46,     0,
       0,    17,    18,    25,     0,     0,     0,     0,     0,     0,
       0,     5,     0,     7,     0,     9,     0,    11,     0,    35,
      36,    33,    34,    20,     0,     0,    24,     0,     0,    38,
       0,     0,     0,     0,    40,     0,    32,    27,    26,    28,
      29,    30,    31,     6,     8,    10,    12,     0,    21,     0,
      19,    22,    23,    45,    41,    42,    47,     0,    15,    14,
      51,     0,     0,    49,     0,    50
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -20,   -20,   -20,    83,   -12,   -20,   -20,    55
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,    15,    54,    16,    17,    18,    19
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      33,    60,    34,    43,    44,    61,    62,    63,    20,    49,
      51,    55,    58,    45,    46,    26,    27,    28,    77,    77,
      78,    81,    64,    67,    68,    69,    70,    71,    72,     2,
       3,    29,     4,     5,     6,    21,     7,     8,     9,    10,
      39,    11,    40,    22,    12,    37,    38,    39,    23,    40,
      24,    13,   -48,    30,    14,    25,     4,    31,    32,    59,
       7,     8,    47,    48,    65,    88,    40,    89,    12,     4,
      31,    32,    73,     7,     8,    91,    50,    52,    14,    53,
      94,    12,     4,    31,    32,    74,     7,     8,    83,    75,
      76,    14,    56,     0,    12,    84,    85,     4,    31,    32,
      86,     7,     8,    87,    14,    90,    11,    57,     0,    12,
       4,    31,    32,     0,     7,     8,     0,     0,     0,    14,
       0,     0,    12,     0,    35,    36,    37,    38,    39,     0,
      40,     0,    14,    79,     0,    80,    35,    36,    37,    38,
      39,     0,    40,     0,     0,    79,     0,    82,    35,    36,
      37,    38,    39,     0,    40,     0,     0,    92,     0,    93,
      35,    36,    37,    38,    39,     0,    40,     0,     0,     0,
       0,    66,    35,    36,    37,    38,    39,     0,    40,     0,
       0,     0,     0,    95,    35,    36,    37,    38,    39,     0,
      40,    41,    42,    35,    36,    37,    38,    39,     0,    40
};

static const yytype_int8 yycheck[] =
{
      12,     5,    14,    22,    23,     9,    10,    11,    22,    21,
      22,    23,    24,    22,    23,     9,    10,    11,    24,    24,
      26,    26,    26,    35,    36,    37,    38,    39,    40,     0,
       1,    25,     3,     4,     5,    27,     7,     8,     9,    10,
      19,    12,    21,    27,    15,    17,    18,    19,    25,    21,
      25,    22,    23,    18,    25,    25,     3,     4,     5,    26,
       7,     8,    22,    23,     5,    77,    21,    79,    15,     3,
       4,     5,    22,     7,     8,    87,    21,    22,    25,    26,
      92,    15,     3,     4,     5,    22,     7,     8,    26,    22,
      22,    25,    26,    -1,    15,    26,    26,     3,     4,     5,
      26,     7,     8,    25,    25,    26,    12,    24,    -1,    15,
       3,     4,     5,    -1,     7,     8,    -1,    -1,    -1,    25,
      -1,    -1,    15,    -1,    15,    16,    17,    18,    19,    -1,
      21,    -1,    25,    24,    -1,    26,    15,    16,    17,    18,
      19,    -1,    21,    -1,    -1,    24,    -1,    26,    15,    16,
      17,    18,    19,    -1,    21,    -1,    -1,    24,    -1,    26,
      15,    16,    17,    18,    19,    -1,    21,    -1,    -1,    -1,
      -1,    26,    15,    16,    17,    18,    19,    -1,    21,    -1,
      -1,    -1,    -1,    26,    15,    16,    17,    18,    19,    -1,
      21,    22,    23,    15,    16,    17,    18,    19,    -1,    21
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    29,     0,     1,     3,     4,     5,     7,     8,     9,
      10,    12,    15,    22,    25,    30,    32,    33,    34,    35,
      22,    27,    27,    25,    25,    25,     9,    10,    11,    25,
      18,     4,     5,    32,    32,    15,    16,    17,    18,    19,
      21,    22,    23,    22,    23,    22,    23,    22,    23,    32,
      35,    32,    35,    26,    31,    32,    26,    31,    32,    26,
       5,     9,    10,    11,    26,     5,    26,    32,    32,    32,
      32,    32,    32,    22,    22,    22,    22,    24,    26,    24,
      26,    26,    26,    26,    26,    26,    26,    25,    32,    32,
      26,    32,    24,    26,    32,    26
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    28,    29,    29,    30,    30,    30,    30,    30,    30,
      30,    30,    30,    30,    31,    31,    32,    32,    32,    32,
      32,    32,    32,    32,    32,    32,    32,    32,    32,    32,
      32,    32,    32,    33,    33,    33,    33,    34,    34,    34,
      34,    34,    34,    34,    34,    34,    34,    34,    35,    35,
      35,    35
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     1,     2,     3,     2,     3,     2,
       3,     2,     3,     2,     3,     3,     1,     1,     1,     4,
       3,     4,     4,     4,     3,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     3,     1,
       3,     4,     4,     2,     2,     4,     2,     4,     0,     6,
       8,     5
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
#line 47 "bison.y"
                        {
                            if (!script) {
                                printf(CYAN">"RESET" ");
                            }
                        }
#line 1184 "bison.tab.c"
    break;

  case 4: /* linea: '\n'  */
#line 55 "bison.y"
                        { printf(CYAN">"RESET" "); }
#line 1190 "bison.tab.c"
    break;

  case 5: /* linea: expresion '\n'  */
#line 56 "bison.y"
                                      {
                                    if (!error) {
                                        if (isnan((yyvsp[-1].numero))) {
                                            lanzar_error("NAN_DETECTADO");
                                        }
                                        printf(VERDE"  %lf"RESET"\n\n", (yyvsp[-1].numero));
                                        ANS = (yyvsp[-1].numero);
                                    }
                                    if (!script && consultar_profundidad() <= 1) {
                                        printf(CYAN">"RESET" ");
                                    }
                                    error = false;
                                }
#line 1208 "bison.tab.c"
    break;

  case 6: /* linea: expresion ';' '\n'  */
#line 69 "bison.y"
                                      {
                                    if (!error) {
                                        if (isnan((yyvsp[-2].numero))) {
                                            lanzar_error("NAN_DETECTADO");
                                        }
                                    }
                                    if (!script && consultar_profundidad() <= 1) {
                                        printf(CYAN">"RESET" ");
                                    }
                                    error = false;
                                }
#line 1224 "bison.tab.c"
    break;

  case 7: /* linea: asignacion '\n'  */
#line 80 "bison.y"
                              {
                            if (!error) {
                                if (isnan((yyvsp[-1].numero))) {
                                    lanzar_error("NAN_DETECTADO");
                                } else if (hacerEcho) {
                                    printf(VERDE"  %lf"RESET"\n\n", (yyvsp[-1].numero));
                                }
                                ANS = (yyvsp[-1].numero);
                            }
                            if (!script && consultar_profundidad() <= 1) {
                                printf(CYAN">"RESET" ");
                            }
                            error = false;
                        }
#line 1243 "bison.tab.c"
    break;

  case 8: /* linea: asignacion ';' '\n'  */
#line 94 "bison.y"
                                      {
                                    if (!error) {
                                        if (isnan((yyvsp[-2].numero))) {
                                            lanzar_error("NAN_DETECTADO");
                                        }
                                    }
                                    if (!script && consultar_profundidad() <= 1) {
                                        printf(CYAN">"RESET" ");
                                    }
                                    error = false;
                                }
#line 1259 "bison.tab.c"
    break;

  case 9: /* linea: comando '\n'  */
#line 105 "bison.y"
                               {
                                if (isnan((yyvsp[-1].numero)) && !error) {
                                    lanzar_error("NAN_DETECTADO");
                                }
                                if (!script && consultar_profundidad() <= 1) {
                                    printf(CYAN">"RESET" ");
                                }
                                error = false;
                            }
#line 1273 "bison.tab.c"
    break;

  case 10: /* linea: comando ';' '\n'  */
#line 114 "bison.y"
                                   {
                                    if (isnan((yyvsp[-2].numero)) && !error) {
                                        lanzar_error("NAN_DETECTADO");
                                    }
                                    if (!script && consultar_profundidad() <= 1) {
                                        printf(CYAN">"RESET" ");
                                    }
                                    error = false;
                                }
#line 1287 "bison.tab.c"
    break;

  case 11: /* linea: funcion '\n'  */
#line 123 "bison.y"
                                {
                                if (!error) {
                                    if (isnan((yyvsp[-1].numero))) {
                                        lanzar_error("NAN_DETECTADO");
                                    }
                                    printf(VERDE"  %lf"RESET"\n\n", (yyvsp[-1].numero));
                                    ANS = (yyvsp[-1].numero);
                                }
                                if (!script && consultar_profundidad() <= 1) {
                                    printf(CYAN">"RESET" ");
                                }
                                error = false;
                            }
#line 1305 "bison.tab.c"
    break;

  case 12: /* linea: funcion ';' '\n'  */
#line 136 "bison.y"
                                 {
                                    if (!error) {
                                        if (isnan((yyvsp[-2].numero))) {
                                            lanzar_error("NAN_DETECTADO");
                                        }
                                    }
                                    if (!script && consultar_profundidad() <= 1) {
                                        printf(CYAN">"RESET" ");
                                    }
                                    error = false;
                                }
#line 1321 "bison.tab.c"
    break;

  case 13: /* linea: error '\n'  */
#line 147 "bison.y"
                            {
                                yyerrok;
                                if (!error) {
                                    printf(CYAN">"RESET" ");
                                }
                            }
#line 1332 "bison.tab.c"
    break;

  case 14: /* lista_expresiones: expresion ',' expresion  */
#line 156 "bison.y"
                            {
        // Crear un array con los dos primeros valores y agregar NAN al final
        (yyval.arr) = malloc(3 * sizeof(double));
        (yyval.arr)[0] = (yyvsp[-2].numero);
        (yyval.arr)[1] = (yyvsp[0].numero);
        (yyval.arr)[2] = NAN;  // Marcador de final
    }
#line 1344 "bison.tab.c"
    break;

  case 15: /* lista_expresiones: lista_expresiones ',' expresion  */
#line 163 "bison.y"
                                      {
        // Obtener tamaño actual del array (contando hasta NAN)
        int len = 0;
        while (!isnan((yyvsp[-2].arr)[len])) len++;

        // Ampliar el array para incluir una nueva expresión + NAN al final
        (yyval.arr) = realloc((yyvsp[-2].arr), (len + 2) * sizeof(double));
        (yyval.arr)[len] = (yyvsp[0].numero);
        (yyval.arr)[len + 1] = NAN;  // Mantener NAN al final
    }
#line 1359 "bison.tab.c"
    break;

  case 17: /* expresion: CONSTANTE  */
#line 176 "bison.y"
                            {
                            c = buscar_elemento((yyvsp[0].cadena));
                            (yyval.numero) = c.valor.var;
                            free((yyvsp[0].cadena));
                        }
#line 1369 "bison.tab.c"
    break;

  case 18: /* expresion: VARIABLE  */
#line 181 "bison.y"
                             {
                            if ((c = buscar_elemento((yyvsp[0].cadena))).lexema != NULL) {
                                (yyval.numero) = c.valor.var;
                            } else {
                                int result = strcmp((yyvsp[0].cadena), "ANS");
                                if (result == 0) {
                                    (yyval.numero) = ANS;
                                } else {
                                    lanzar_error("VARIABLE_NON_DEFINIDA");
                                    error = true;
                                    (yyval.numero) = NAN;
                                }
                            }
                            free((yyvsp[0].cadena));
                        }
#line 1389 "bison.tab.c"
    break;

  case 19: /* expresion: FUNC1 '(' expresion ')'  */
#line 196 "bison.y"
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
#line 1406 "bison.tab.c"
    break;

  case 20: /* expresion: FUNC1 '(' ')'  */
#line 208 "bison.y"
                                          {
                                                        lanzar_error("La función tiene un argumento");
                                                        error = true;
                                                        (yyval.numero) = NAN;
                                                  }
#line 1416 "bison.tab.c"
    break;

  case 21: /* expresion: FUNC1 '(' lista_expresiones ')'  */
#line 213 "bison.y"
                                                            {
                                                        lanzar_error("La función tiene un argumento");
                                                        error = true;
                                                        (yyval.numero) = NAN;
                                                  }
#line 1426 "bison.tab.c"
    break;

  case 22: /* expresion: FUNC2 '(' lista_expresiones ')'  */
#line 218 "bison.y"
                                          {
                                                        c = buscar_elemento((yyvsp[-3].cadena));
                                                        if (c.lexema != NULL && c.valor.funcptr != NULL) {
                                                            (yyval.numero) = (*(c.valor.funcptr))((yyvsp[-1].arr));
                                                        } else {
                                                            lanzar_error("No se encuentra la función básica");
                                                            error = true;
                                                            (yyval.numero) = NAN;
                                                        }
                                                        free((yyvsp[-3].cadena));
                                                        free((yyvsp[-1].arr));
                                                  }
#line 1443 "bison.tab.c"
    break;

  case 23: /* expresion: FUNC2 '(' expresion ')'  */
#line 230 "bison.y"
                                          {
                                                        double* array = (double *)malloc(2 * sizeof(double));
                                                        array[0] = (yyvsp[-1].numero);
                                                        array[1] = NAN;

                                                        c = buscar_elemento((yyvsp[-3].cadena));
                                                        if (c.lexema != NULL && c.valor.funcptr != NULL) {
                                                            (yyval.numero) = (*(c.valor.funcptr))(array);
                                                        } else {
                                                            lanzar_error("No se encuentra la función básica");
                                                            error = true;
                                                            (yyval.numero) = NAN;
                                                        }
                                                        free((yyvsp[-3].cadena));
                                                        free(array);

                                                  }
#line 1465 "bison.tab.c"
    break;

  case 24: /* expresion: FUNC2 '(' ')'  */
#line 247 "bison.y"
                                          {
                                                        lanzar_error("La función tiene argumentos");
                                                        error = true;
                                                        (yyval.numero) = NAN;
                                                  }
#line 1475 "bison.tab.c"
    break;

  case 25: /* expresion: '-' expresion  */
#line 252 "bison.y"
                                  {
                                 if (!isnan((yyvsp[0].numero))) {
                                     (yyval.numero) = -(yyvsp[0].numero);
                                 } else {
                                     (yyval.numero) = NAN;
                                 }
                            }
#line 1487 "bison.tab.c"
    break;

  case 26: /* expresion: expresion '+' expresion  */
#line 259 "bison.y"
                                    {
                            if (!isnan((yyvsp[-2].numero)) && !isnan((yyvsp[0].numero))) {
                                (yyval.numero) = (yyvsp[-2].numero) + (yyvsp[0].numero);
                            } else {
                                (yyval.numero) = NAN;
                            }
                        }
#line 1499 "bison.tab.c"
    break;

  case 27: /* expresion: expresion '-' expresion  */
#line 266 "bison.y"
                                    {
                            if (!isnan((yyvsp[-2].numero)) && !isnan((yyvsp[0].numero))) {
                                (yyval.numero) = (yyvsp[-2].numero) - (yyvsp[0].numero);
                            } else {
                                (yyval.numero) = NAN;
                            }
                        }
#line 1511 "bison.tab.c"
    break;

  case 28: /* expresion: expresion '*' expresion  */
#line 273 "bison.y"
                                    {
                            if (!isnan((yyvsp[-2].numero)) && !isnan((yyvsp[0].numero))) {
                                (yyval.numero) = (yyvsp[-2].numero) * (yyvsp[0].numero);
                            } else {
                                (yyval.numero) = NAN;
                            }
                        }
#line 1523 "bison.tab.c"
    break;

  case 29: /* expresion: expresion '/' expresion  */
#line 280 "bison.y"
                                    {
                            if (fabs((yyvsp[0].numero)) < TOLERANCIA) {
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
#line 1541 "bison.tab.c"
    break;

  case 30: /* expresion: expresion '%' expresion  */
#line 293 "bison.y"
                                    {
                            if (fabs((yyvsp[0].numero)) < TOLERANCIA) {
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
#line 1559 "bison.tab.c"
    break;

  case 31: /* expresion: expresion '^' expresion  */
#line 306 "bison.y"
                                    {
                            if (!isnan((yyvsp[-2].numero)) && !isnan((yyvsp[0].numero))) {
                                (yyval.numero) = pow((yyvsp[-2].numero), (yyvsp[0].numero));
                            } else {
                                (yyval.numero) = NAN;
                            }
                        }
#line 1571 "bison.tab.c"
    break;

  case 32: /* expresion: '(' expresion ')'  */
#line 313 "bison.y"
                              {
                                                       if (!isnan((yyvsp[-1].numero))) {
                                                           (yyval.numero) = (yyvsp[-1].numero);
                                                       } else {
                                                           (yyval.numero) = NAN;
                                                       }
                                                   }
#line 1583 "bison.tab.c"
    break;

  case 33: /* asignacion: VARIABLE '=' expresion  */
#line 323 "bison.y"
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
#line 1603 "bison.tab.c"
    break;

  case 34: /* asignacion: VARIABLE '=' funcion  */
#line 338 "bison.y"
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
#line 1623 "bison.tab.c"
    break;

  case 35: /* asignacion: CONSTANTE '=' expresion  */
#line 353 "bison.y"
                                  {
                            lanzar_error("CONSTANTE_NON_MODIFICABLE");
                            error = true;
                            (yyval.numero) = NAN;
                            free((yyvsp[-2].cadena));
                        }
#line 1634 "bison.tab.c"
    break;

  case 36: /* asignacion: CONSTANTE '=' funcion  */
#line 359 "bison.y"
                                {
                            lanzar_error("CONSTANTE_NON_MODIFICABLE");
                            error = true;
                            (yyval.numero) = NAN;
                            free((yyvsp[-2].cadena));
                        }
#line 1645 "bison.tab.c"
    break;

  case 37: /* comando: COMANDO0  */
#line 368 "bison.y"
                                    {
                                        c = buscar_elemento((yyvsp[0].cadena));
                                        free((yyvsp[0].cadena));
                                        (*(c.valor.funcptr))();
                                    }
#line 1655 "bison.tab.c"
    break;

  case 38: /* comando: COMANDO0 '(' ')'  */
#line 373 "bison.y"
                                       {
                                        c = buscar_elemento((yyvsp[-2].cadena));
                                        free((yyvsp[-2].cadena));
                                        (*(c.valor.funcptr))();
                                    }
#line 1665 "bison.tab.c"
    break;

  case 39: /* comando: COMANDO1  */
#line 378 "bison.y"
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
#line 1685 "bison.tab.c"
    break;

  case 40: /* comando: COMANDO1 '(' ')'  */
#line 393 "bison.y"
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
#line 1705 "bison.tab.c"
    break;

  case 41: /* comando: COMANDO1 '(' COMANDO0 ')'  */
#line 408 "bison.y"
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
#line 1724 "bison.tab.c"
    break;

  case 42: /* comando: COMANDO1 '(' COMANDO1 ')'  */
#line 422 "bison.y"
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
#line 1743 "bison.tab.c"
    break;

  case 43: /* comando: COMANDO1 COMANDO0  */
#line 436 "bison.y"
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
#line 1761 "bison.tab.c"
    break;

  case 44: /* comando: COMANDO1 COMANDO1  */
#line 449 "bison.y"
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
#line 1779 "bison.tab.c"
    break;

  case 45: /* comando: COMANDO1 '(' VARIABLE ')'  */
#line 462 "bison.y"
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
#line 1800 "bison.tab.c"
    break;

  case 46: /* comando: COMANDO1 ARCHIVO  */
#line 478 "bison.y"
                                        {
                                        c = buscar_elemento((yyvsp[-1].cadena));
                                        (*(c.valor.funcptr))((yyvsp[0].cadena));
                                        free((yyvsp[-1].cadena));
                                        free((yyvsp[0].cadena));
                                     }
#line 1811 "bison.tab.c"
    break;

  case 47: /* comando: COMANDO1 '(' ARCHIVO ')'  */
#line 484 "bison.y"
                                        {
                                        c = buscar_elemento((yyvsp[-3].cadena));
                                        (*(c.valor.funcptr))((yyvsp[-1].cadena));
                                        free((yyvsp[-3].cadena));
                                        free((yyvsp[-1].cadena));
                                     }
#line 1822 "bison.tab.c"
    break;

  case 49: /* funcion: LIB '/' VARIABLE '(' expresion ')'  */
#line 493 "bison.y"
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
#line 1851 "bison.tab.c"
    break;

  case 50: /* funcion: LIB '/' VARIABLE '(' expresion ',' expresion ')'  */
#line 517 "bison.y"
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
#line 1879 "bison.tab.c"
    break;

  case 51: /* funcion: LIB '/' VARIABLE '(' ')'  */
#line 540 "bison.y"
                                                 {
                                                /*
                                                lanzar_error("PARAMETROS_NON_INDICADOS");
                                                error = true;
                                                $$ = NAN;
                                                free($1);
                                                free($3);
                                                */
                                            }
#line 1893 "bison.tab.c"
    break;


#line 1897 "bison.tab.c"

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

#line 552 "bison.y"


void yyerror(char* s) {
    lanzar_error("ERROR SINTÁCTICO");
}

void cambiar_echo(double valor) {
    if (valor == 1) { hacerEcho = true; }
    else if (valor == 2) { hacerEcho = false; }
}

void ejecutar_script(int valor) {
    script = valor;
    if (script && hacerEcho == true) {
        printf("\n"AMARILLO"Script ejecutado correctamente."RESET"\n\n");
        if (consultar_profundidad() < 1) {
            printf(CYAN">"RESET" ");
        }
    }
}


