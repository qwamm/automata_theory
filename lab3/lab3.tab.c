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

	#ifndef AST
	#define AST
	#include "nodes.h"
	#include "robot.h"
	#endif
	#include "tree_parser.h"
	#define YYSTYPE val
	struct val
	{
		char *text;
		bool one = true;
		node *tree;
	};
	ast *syntax_tree;
	#include <iostream>
	#include <string>
	#include <fstream>
	#include <vector>
	#include <stdio.h>
	#include <stdbool.h>
	#include <math.h>
	int yylex(void);
	void yyerror(const char*);


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

#include "lab3.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INTNUM = 3,                     /* INTNUM  */
  YYSYMBOL_BOOLNUM = 4,                    /* BOOLNUM  */
  YYSYMBOL_TYPE = 5,                       /* TYPE  */
  YYSYMBOL_UNDEF = 6,                      /* UNDEF  */
  YYSYMBOL_SVAL = 7,                       /* SVAL  */
  YYSYMBOL_LITERAL = 8,                    /* LITERAL  */
  YYSYMBOL_RECORD = 9,                     /* RECORD  */
  YYSYMBOL_DATA = 10,                      /* DATA  */
  YYSYMBOL_CONVERSION = 11,                /* CONVERSION  */
  YYSYMBOL_TO = 12,                        /* TO  */
  YYSYMBOL_FROM = 13,                      /* FROM  */
  YYSYMBOL_PROC = 14,                      /* PROC  */
  YYSYMBOL_BLOCK = 15,                     /* BLOCK  */
  YYSYMBOL_UNBLOCK = 16,                   /* UNBLOCK  */
  YYSYMBOL_MOVE = 17,                      /* MOVE  */
  YYSYMBOL_PING = 18,                      /* PING  */
  YYSYMBOL_VISION = 19,                    /* VISION  */
  YYSYMBOL_VOICE = 20,                     /* VOICE  */
  YYSYMBOL_EF = 21,                        /* EF  */
  YYSYMBOL_22_ = 22,                       /* '='  */
  YYSYMBOL_23_ = 23,                       /* '@'  */
  YYSYMBOL_24_ = 24,                       /* ','  */
  YYSYMBOL_25_ = 25,                       /* '>'  */
  YYSYMBOL_26_ = 26,                       /* '<'  */
  YYSYMBOL_27_ = 27,                       /* '+'  */
  YYSYMBOL_28_ = 28,                       /* '-'  */
  YYSYMBOL_29_ = 29,                       /* '?'  */
  YYSYMBOL_30_ = 30,                       /* '!'  */
  YYSYMBOL_31_ = 31,                       /* '*'  */
  YYSYMBOL_32_ = 32,                       /* '/'  */
  YYSYMBOL_33_ = 33,                       /* '^'  */
  YYSYMBOL_34_ = 34,                       /* '['  */
  YYSYMBOL_35_ = 35,                       /* ']'  */
  YYSYMBOL_UMINUS = 36,                    /* UMINUS  */
  YYSYMBOL_37_n_ = 37,                     /* '\n'  */
  YYSYMBOL_38_ = 38,                       /* '&'  */
  YYSYMBOL_39_ = 39,                       /* '{'  */
  YYSYMBOL_40_ = 40,                       /* '}'  */
  YYSYMBOL_41_ = 41,                       /* '('  */
  YYSYMBOL_42_ = 42,                       /* ')'  */
  YYSYMBOL_43_ = 43,                       /* '.'  */
  YYSYMBOL_44_ = 44,                       /* '|'  */
  YYSYMBOL_YYACCEPT = 45,                  /* $accept  */
  YYSYMBOL_program = 46,                   /* program  */
  YYSYMBOL_record = 47,                    /* record  */
  YYSYMBOL_block = 48,                     /* block  */
  YYSYMBOL_proc = 49,                      /* proc  */
  YYSYMBOL_declaration = 50,               /* declaration  */
  YYSYMBOL_sentence = 51,                  /* sentence  */
  YYSYMBOL_cond = 52,                      /* cond  */
  YYSYMBOL_group_comma = 53,               /* group_comma  */
  YYSYMBOL_conv_proc_set = 54,             /* conv_proc_set  */
  YYSYMBOL_arg_set = 55,                   /* arg_set  */
  YYSYMBOL_expr = 56                       /* expr  */
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
#define YYLAST   304

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  12
/* YYNRULES -- Number of rules.  */
#define YYNRULES  53
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  123

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   277


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
      37,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    30,     2,     2,     2,     2,    38,     2,
      41,    42,    31,    27,    24,    28,    43,    32,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      26,    22,    25,    29,    23,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    34,     2,    35,    33,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    39,    44,    40,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    36
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    61,    61,    67,    72,    78,    84,    90,    94,    98,
     102,   108,   116,   123,   125,   127,   129,   135,   136,   137,
     138,   139,   140,   144,   151,   152,   156,   157,   160,   161,
     165,   166,   167,   168,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   185,   189,   190,
     195,   216,   237,   241
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
  "\"end of file\"", "error", "\"invalid token\"", "INTNUM", "BOOLNUM",
  "TYPE", "UNDEF", "SVAL", "LITERAL", "RECORD", "DATA", "CONVERSION", "TO",
  "FROM", "PROC", "BLOCK", "UNBLOCK", "MOVE", "PING", "VISION", "VOICE",
  "EF", "'='", "'@'", "','", "'>'", "'<'", "'+'", "'-'", "'?'", "'!'",
  "'*'", "'/'", "'^'", "'['", "']'", "UMINUS", "'\\n'", "'&'", "'{'",
  "'}'", "'('", "')'", "'.'", "'|'", "$accept", "program", "record",
  "block", "proc", "declaration", "sentence", "cond", "group_comma",
  "conv_proc_set", "arg_set", "expr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-109)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -109,    52,  -109,  -109,  -109,     0,    -1,  -109,     8,    44,
      16,    20,    24,    28,    34,  -109,    67,   104,   104,   104,
      40,    42,    50,    51,    55,    57,   142,   -13,  -109,    82,
      90,     3,    78,   104,   104,   104,   104,   104,    59,  -109,
     126,   108,  -109,  -109,  -109,    78,  -109,    78,   104,   104,
     104,   104,   104,   104,   104,   104,   104,   104,   104,    78,
     104,   104,  -109,    69,    97,    81,    71,    94,   155,   169,
     183,   197,    70,   239,    98,  -109,  -109,  -109,   262,   270,
     270,    -4,    -4,    14,    14,   -20,   -20,    84,   211,  -109,
     252,   225,     3,     3,    98,  -109,  -109,  -109,  -109,  -109,
    -109,   104,  -109,  -109,  -109,    80,  -109,  -109,  -109,    79,
     109,    10,   121,   121,   113,  -109,   118,   106,   119,   121,
     121,  -109,  -109
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       6,     0,     1,    32,    33,     0,    30,    31,     0,     0,
       0,     0,     0,     0,     0,    34,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    14,    13,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    30,    45,
       0,     0,     2,     3,     4,    17,     5,    19,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    18,
       0,     0,    48,     0,     0,    24,     0,     0,     0,     0,
       0,     0,     0,    28,     0,    35,    20,    22,    47,    37,
      36,    38,    39,    40,    41,    42,    43,    44,     0,    21,
      15,     0,     0,     0,     0,    11,    50,    51,    52,    53,
      49,     0,    23,    46,    16,     0,    25,    12,    29,     0,
      10,     0,     0,     0,     0,     9,     8,     0,     0,    26,
       0,    27,     7
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -109,  -109,  -109,   -70,  -109,   -28,    31,  -109,   -43,  -108,
      43,   -17
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,    20,    21,    22,    23,    24,    25,    66,   115,
      72,    26
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      39,    40,    41,    65,   102,   116,    28,    27,     5,    60,
      64,   121,   122,    57,    58,    30,    68,    69,    70,    71,
      73,    61,   112,   113,   107,    53,    54,    55,    56,    57,
      58,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    29,    90,    91,    55,    56,    57,    58,   105,
     106,    31,     2,    32,    33,     3,     4,     5,    34,     6,
       7,     8,    35,    67,    65,    65,     9,    10,    36,    11,
      12,    13,    14,    15,    37,    16,    76,    42,    77,    43,
      17,     3,     4,     5,    73,     6,     7,    44,    45,    62,
      89,    18,    46,    19,    47,    11,    12,    13,    14,    15,
      63,    16,    29,    92,    28,    93,    17,     3,     4,    94,
      95,    38,     7,    10,   100,   109,   110,    18,    58,    19,
     111,    11,    12,    13,    14,    15,   114,    16,   117,   118,
      48,   120,    17,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,   119,   108,    19,     0,     0,    48,     0,
      75,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,     0,     0,     0,    48,     0,    74,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    48,     0,    59,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      96,    48,     0,     0,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    97,    48,     0,     0,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    98,    48,
       0,     0,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    99,    48,     0,     0,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,   103,    48,     0,     0,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
     104,    48,     0,   101,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    48,     0,     0,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    51,    52,    53,
      54,    55,    56,    57,    58
};

static const yytype_int8 yycheck[] =
{
      17,    18,    19,    31,    74,   113,     7,     7,     5,    22,
       7,   119,   120,    33,    34,     7,    33,    34,    35,    36,
      37,    34,    12,    13,    94,    29,    30,    31,    32,    33,
      34,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    43,    60,    61,    31,    32,    33,    34,    92,
      93,     7,     0,    37,    34,     3,     4,     5,    34,     7,
       8,     9,    34,    32,    92,    93,    14,    15,    34,    17,
      18,    19,    20,    21,     7,    23,    45,    37,    47,    37,
      28,     3,     4,     5,   101,     7,     8,    37,    37,     7,
      59,    39,    37,    41,    37,    17,    18,    19,    20,    21,
      10,    23,    43,    34,     7,    24,    28,     3,     4,    38,
      16,     7,     8,    15,    44,    35,    37,    39,    34,    41,
      11,    17,    18,    19,    20,    21,     5,    23,    15,    11,
      22,    12,    28,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    37,   101,    41,    -1,    -1,    22,    -1,
      42,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    -1,    -1,    -1,    22,    -1,    40,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    22,    -1,    37,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    22,    -1,    -1,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    22,    -1,    -1,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    22,
      -1,    -1,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    22,    -1,    -1,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    22,    -1,    -1,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    22,    -1,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    22,    -1,    -1,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    27,    28,    29,
      30,    31,    32,    33,    34
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    46,     0,     3,     4,     5,     7,     8,     9,    14,
      15,    17,    18,    19,    20,    21,    23,    28,    39,    41,
      47,    48,    49,    50,    51,    52,    56,     7,     7,    43,
       7,     7,    37,    34,    34,    34,    34,     7,     7,    56,
      56,    56,    37,    37,    37,    37,    37,    37,    22,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    37,
      22,    34,     7,    10,     7,    50,    53,    51,    56,    56,
      56,    56,    55,    56,    40,    42,    51,    51,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    51,
      56,    56,    34,    24,    38,    16,    35,    35,    35,    35,
      44,    24,    48,    35,    35,    53,    53,    48,    55,    35,
      37,    11,    12,    13,     5,    54,    54,    15,    11,    37,
      12,    54,    54
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    45,    46,    46,    46,    46,    46,    47,    47,    47,
      47,    48,    49,    50,    50,    50,    50,    51,    51,    51,
      51,    51,    51,    52,    53,    53,    54,    54,    55,    55,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     3,     3,     3,     0,    13,    10,    10,
       7,     4,     5,     2,     2,     4,     5,     2,     2,     2,
       3,     3,     3,     4,     1,     3,     3,     4,     1,     3,
       1,     1,     1,     1,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     4,     3,     3,     4,
       4,     4,     4,     4
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
  case 2: /* program: program record '\n'  */
                            {
		std::cout << "HERE RECORD\n";
		std::cout << "SYNTAX TREE:\n";
		if (yyvsp[-1].tree) {syntax_tree->add(yyvsp[-1].tree);}
		syntax_tree->put_tree(syntax_tree->root, 0);
	}
    break;

  case 3: /* program: program block '\n'  */
                             {
		std::cout << "HERE BLOCK\n";
		std::cout << "SYNTAX TREE:\n";
		syntax_tree->put_tree(syntax_tree->root, 0);
	}
    break;

  case 4: /* program: program proc '\n'  */
                            {
		std::cout << "HERE PROC\n";
		std::cout << "SYNTAX TREE:\n";
		if (yyvsp[-1].tree) {syntax_tree->add(yyvsp[-1].tree);}
		syntax_tree->put_tree(syntax_tree->root, 0);
	}
    break;

  case 5: /* program: program sentence '\n'  */
                                {
		std::cout << "HERE SENTENCE\n";
		std::cout << "SYNTAX TREE:\n";
		if (yyvsp[-1].tree) {syntax_tree->add(yyvsp[-1].tree);}
		syntax_tree->put_tree(syntax_tree->root, 0);
	}
    break;

  case 6: /* program: %empty  */
          {
		syntax_tree = new ast();
		printf("enter a expression:\n");
	}
    break;

  case 7: /* record: RECORD SVAL DATA '[' group_comma ']' '\n' CONVERSION FROM conv_proc_set CONVERSION TO conv_proc_set  */
        {
		yyval.tree = new record_node(std::string(yyvsp[-11].text), yyvsp[-8].tree, yyvsp[-3].tree, yyvsp[0].tree , RECORDN);
	}
    break;

  case 8: /* record: RECORD SVAL DATA '[' group_comma ']' '\n' CONVERSION FROM conv_proc_set  */
        {
		yyval.tree = new record_node(std::string(yyvsp[-8].text), yyvsp[-5].tree, yyvsp[0].tree, nullptr, RECORDN);
	}
    break;

  case 9: /* record: RECORD SVAL DATA '[' group_comma ']' '\n' CONVERSION TO conv_proc_set  */
        {
		yyval.tree = new record_node(std::string(yyvsp[-8].text), yyvsp[-5].tree, nullptr, yyvsp[0].tree , RECORDN);
	}
    break;

  case 10: /* record: RECORD SVAL DATA '[' group_comma ']' '\n'  */
        {
		yyval.tree = new record_node(std::string(yyvsp[-5].text), yyvsp[-2].tree, nullptr, nullptr , RECORDN);
	}
    break;

  case 11: /* block: BLOCK '\n' sentence UNBLOCK  */
        {
		yyval.tree = new block_node(yyvsp[-1].tree, BLOCKN);
		//if ($$.tree) {syntax_tree->add($$.tree);}
	}
    break;

  case 12: /* proc: PROC SVAL group_comma '&' block  */
        {
			yyval.tree = new proc_node(std::string(yyvsp[-3].text), yyvsp[-2].tree, yyvsp[0].tree, PROCN);
	}
    break;

  case 13: /* declaration: SVAL SVAL  */
                  {yyval.tree = new decl_node(std::string(yyvsp[-1].text), std::string(yyvsp[0].text), nullptr, nullptr, UNDEFVARN);
	syntax_tree->put_tree(yyval.tree, 0);}
    break;

  case 14: /* declaration: TYPE SVAL  */
                    {yyval.tree = new decl_node(std::string(yyvsp[-1].text), std::string(yyvsp[0].text), nullptr, nullptr, UNDEFVARN);
	syntax_tree->put_tree(yyval.tree, 0);}
    break;

  case 15: /* declaration: TYPE SVAL '=' expr  */
                                {yyval.tree = new decl_node(std::string(yyvsp[-3].text), std::string(yyvsp[-2].text), nullptr, yyvsp[0].tree, VARN);
	 printf("NAME: %s\n", yyvsp[-2].text); printf("TYPE: %s\n", yyvsp[-3].text); syntax_tree->put_tree(yyval.tree, 0);}
    break;

  case 16: /* declaration: TYPE SVAL '[' expr ']'  */
                                 {
		yyval.tree = new decl_node(std::string(yyvsp[-4].text), std::string(yyvsp[-3].text), yyvsp[-1].tree, nullptr, UNDEFVARN); syntax_tree->put_tree(yyval.tree, 0);  
	}
    break;

  case 17: /* sentence: declaration '\n'  */
                          {yyval = yyvsp[-1]; }
    break;

  case 18: /* sentence: expr '\n'  */
                    {yyval = yyvsp[-1]; }
    break;

  case 19: /* sentence: cond '\n'  */
                    {yyval = yyvsp[-1];}
    break;

  case 20: /* sentence: declaration '\n' sentence  */
                                    {yyvsp[0].tree->set_left(yyvsp[-2].tree); yyval = yyvsp[0]; std::cout << "SENTENCE AND GROUP SET\n"; syntax_tree->put_tree(yyval.tree, 0);}
    break;

  case 21: /* sentence: expr '\n' sentence  */
                             {yyvsp[0].tree->set_left(yyvsp[-2].tree); yyval = yyvsp[0]; std::cout << "EXPR AND GROUP SET\n"; syntax_tree->put_tree(yyval.tree, 0);}
    break;

  case 22: /* sentence: cond '\n' sentence  */
                             {yyvsp[0].tree->set_left(yyvsp[-2].tree); yyval = yyvsp[0]; std::cout << "BLOCK AND GROUP SET\n"; syntax_tree->put_tree(yyval.tree, 0);}
    break;

  case 23: /* cond: '{' expr '}' block  */
        {
		yyval.tree = new cond_node(yyvsp[-2].tree, yyvsp[0].tree, CONDN);
	}
    break;

  case 24: /* group_comma: declaration  */
                    {yyval = yyvsp[0];}
    break;

  case 25: /* group_comma: declaration ',' group_comma  */
                                      {yyvsp[0].tree->set_left(yyvsp[-2].tree); yyval = yyvsp[0]; std::cout << "DECLARATION GROUP COMMA\n"; syntax_tree->put_tree(yyval.tree, 0);}
    break;

  case 26: /* conv_proc_set: TYPE BLOCK '\n'  */
                        {yyval.tree = new conv_node(std::string(yyvsp[-2].text), yyvsp[-1].tree, CONVPROCN);}
    break;

  case 27: /* conv_proc_set: TYPE BLOCK '\n' conv_proc_set  */
                                        {yyvsp[-1].tree->set_left(yyvsp[-3].tree); yyval = yyvsp[-1]; std::cout << "CONV_PROC AND CONV_PROC SET\n"; syntax_tree->put_tree(yyval.tree, 0);}
    break;

  case 28: /* arg_set: expr  */
             { yyval = yyvsp[0];}
    break;

  case 29: /* arg_set: expr ',' arg_set  */
                           {yyvsp[0].tree->set_left(yyvsp[-2].tree); yyval = yyvsp[0]; std::cout << "EXPR AND ARG_SET\n"; syntax_tree->put_tree(yyval.tree, 0);}
    break;

  case 30: /* expr: SVAL  */
             {yyval.tree = new str_node(std::string(yyvsp[0].text), STRN); printf("SVAL WITH VAL = \"%s\"\n", yyvsp[0].text);}
    break;

  case 31: /* expr: LITERAL  */
                  {yyval.tree = new str_node(std::string(yyvsp[0].text), LITERALN);  printf("LITERAL WITH VAL = \"%s\"\n", yyvsp[0].text);}
    break;

  case 32: /* expr: INTNUM  */
                 {yyval.tree = new int_node(atoi(yyvsp[0].text), INTN); printf("INTNUM %d\n", atoi(yyvsp[0].text));}
    break;

  case 33: /* expr: BOOLNUM  */
                  {bool buf; if (strcmp(yyvsp[0].text, "TRUE") == 0) {buf = true;} else {buf = false;} yyval.tree = new bool_node(buf,
	 BOOLN); printf("BOOLNUM %d\n", buf);}
    break;

  case 34: /* expr: EF  */
             {printf("Programm finished successfully!\n");}
    break;

  case 35: /* expr: '(' expr ')'  */
                       {yyval.tree = yyvsp[-1].tree;}
    break;

  case 36: /* expr: expr '<' expr  */
                        {yyval.tree = new operation_node(yyvsp[-2].tree, yyvsp[0].tree, LESSN); }
    break;

  case 37: /* expr: expr '>' expr  */
                        {yyval.tree = new operation_node(yyvsp[-2].tree, yyvsp[0].tree, GREATERN); }
    break;

  case 38: /* expr: expr '+' expr  */
                        {yyval.tree = new operation_node(yyvsp[-2].tree, yyvsp[0].tree, PLUSN); }
    break;

  case 39: /* expr: expr '-' expr  */
                        {yyval.tree = new operation_node(yyvsp[-2].tree, yyvsp[0].tree, NEGN); }
    break;

  case 40: /* expr: expr '?' expr  */
                        {yyval.tree = new operation_node(yyvsp[-2].tree, yyvsp[0].tree, EQUN); }
    break;

  case 41: /* expr: expr '!' expr  */
                        {yyval.tree = new operation_node(yyvsp[-2].tree, yyvsp[0].tree, NOTEQUN); }
    break;

  case 42: /* expr: expr '*' expr  */
                        {yyval.tree = new operation_node(yyvsp[-2].tree, yyvsp[0].tree, MULN); }
    break;

  case 43: /* expr: expr '/' expr  */
                        {yyval.tree = new operation_node(yyvsp[-2].tree, yyvsp[0].tree, DIVN); }
    break;

  case 44: /* expr: expr '^' expr  */
                        {yyval.tree = new operation_node(yyvsp[-2].tree, yyvsp[0].tree, EXPN); }
    break;

  case 45: /* expr: '-' expr  */
                                {yyval.tree = new unary_node(yyvsp[-1].tree, UMINN);}
    break;

  case 46: /* expr: expr '[' expr ']'  */
                            {
		yyval.tree = new arr_node(yyvsp[-3].tree, yyvsp[-1].tree, ARRASSIGNN);
	}
    break;

  case 47: /* expr: expr '=' expr  */
                        {
            yyval.tree = new assign_node(yyvsp[-2].tree, yyvsp[0].tree, ASSIGNN);
             syntax_tree->put_tree(yyval.tree, 0); 
	}
    break;

  case 48: /* expr: SVAL '.' SVAL  */
                        {yyval.tree = new struct_ref_node(std::string(yyvsp[-2].text), std::string (yyvsp[0].text), STRUCTREFN);}
    break;

  case 49: /* expr: '@' SVAL arg_set '|'  */
        {
	    		std::cout << "CALL HERE!\n";
	            yyval.tree = new proc_node(std::string(yyvsp[-2].text), yyvsp[-1].tree, nullptr, CALLN);
	}
    break;

  case 50: /* expr: MOVE '[' expr ']'  */
        {
		int op;
		if (strcmp(yyvsp[-3].text, "MOVERIGHT") == 0)
		{
			op = MOVERIGHT;
		}
		else if (strcmp(yyvsp[-3].text, "MOVELEFT") == 0)
		{
			op = MOVELEFT;
		}
		else if (strcmp(yyvsp[-3].text, "MOVEUP") == 0)
		{
			op = MOVEUP;
		}
		else
		{
			op = MOVEDOWN;
		}
		yyval.tree = new move_node(yyvsp[-1].tree, op);
	}
    break;

  case 51: /* expr: PING '[' expr ']'  */
        {
                int op;
                if (strcmp(yyvsp[-3].text, "PINGRIGHT") == 0)
                {
                        op = PINGRIGHT;
                }
                else if (strcmp(yyvsp[-3].text, "PINGLEFT") == 0)
                {
                        op = PINGLEFT;
                }
                else if (strcmp(yyvsp[-3].text, "PINGUP") == 0)
                {
                        op = PINGUP;
                }
                else
                {
                        op = PINGDOWN;
                }
                yyval.tree = new ping_node(yyvsp[-1].tree, op);
	}
    break;

  case 52: /* expr: VISION '[' expr ']'  */
        {
                yyval.tree = new vision_node(yyvsp[-1].tree, VISIONN);
	}
    break;

  case 53: /* expr: VOICE '[' expr ']'  */
    {
            yyval.tree = new voice_node(yyvsp[-1].tree, VOICEN);
    }
    break;



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



#include <stdbool.h>

void yyerror(const char *s)
{
	fprintf(stderr, "%s\n", s);
}

/*int yylex(void)
{
	int c;
	while ((c = getchar()) == ' '|| c == '\t')
	;
	if (isdigit(c) && (c == '0' || c == '1'))
	{
		ungetc (c, stdin);
		scanf ("%d", &yylval);
		return BOOLNUM;
	}
	else if (isdigit(c))
	{
		ungetc (c, stdin);
		scanf ("%d", &yylval);
		return INTNUM;
	}
	if (c == EOF)
		return 0;
	return c;  
}*/

int main(void)
{
	yyparse();
	std::string line;
	std::vector<std::string> v;
	std::ifstream in;
	in.open("maze.txt");
	if (in.is_open())
	{
		while(std::getline(in,line))
		{
			v.push_back(line);
		}
		in.close();
	}
	robot *r = new cell_robot(v);
	//std::cout << "BEFORE\n";
	//r.print_field();
	if (syntax_tree->root)
	{
		std::cout << "GLOBAL\n";
		tree_parser x;
		x.parse(syntax_tree->root, x.global, r);
		x.global.print();
	}
	//std::cout << "AFTER\n";
	//r.print_field();
	return 0;
}
