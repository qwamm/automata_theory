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
		int line;
		int err_type;
		node *tree;
	};
	ast *syntax_tree;
	bool error = false;
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
  YYSYMBOL_CALL = 21,                      /* CALL  */
  YYSYMBOL_WHILE = 22,                     /* WHILE  */
  YYSYMBOL_EF = 23,                        /* EF  */
  YYSYMBOL_24_ = 24,                       /* '='  */
  YYSYMBOL_25_ = 25,                       /* '@'  */
  YYSYMBOL_26_ = 26,                       /* ','  */
  YYSYMBOL_27_ = 27,                       /* '>'  */
  YYSYMBOL_28_ = 28,                       /* '<'  */
  YYSYMBOL_29_ = 29,                       /* '+'  */
  YYSYMBOL_30_ = 30,                       /* '-'  */
  YYSYMBOL_31_ = 31,                       /* '?'  */
  YYSYMBOL_32_ = 32,                       /* '!'  */
  YYSYMBOL_33_ = 33,                       /* '*'  */
  YYSYMBOL_34_ = 34,                       /* '/'  */
  YYSYMBOL_35_ = 35,                       /* '^'  */
  YYSYMBOL_36_ = 36,                       /* '['  */
  YYSYMBOL_37_ = 37,                       /* ']'  */
  YYSYMBOL_UMINUS = 38,                    /* UMINUS  */
  YYSYMBOL_39_n_ = 39,                     /* '\n'  */
  YYSYMBOL_40_ = 40,                       /* '&'  */
  YYSYMBOL_41_ = 41,                       /* '{'  */
  YYSYMBOL_42_ = 42,                       /* '}'  */
  YYSYMBOL_43_ = 43,                       /* '('  */
  YYSYMBOL_44_ = 44,                       /* ')'  */
  YYSYMBOL_45_ = 45,                       /* '.'  */
  YYSYMBOL_46_ = 46,                       /* '|'  */
  YYSYMBOL_YYACCEPT = 47,                  /* $accept  */
  YYSYMBOL_program = 48,                   /* program  */
  YYSYMBOL_record = 49,                    /* record  */
  YYSYMBOL_block = 50,                     /* block  */
  YYSYMBOL_proc = 51,                      /* proc  */
  YYSYMBOL_declaration = 52,               /* declaration  */
  YYSYMBOL_sentence = 53,                  /* sentence  */
  YYSYMBOL_cond = 54,                      /* cond  */
  YYSYMBOL_group_comma = 55,               /* group_comma  */
  YYSYMBOL_conv_proc_set = 56,             /* conv_proc_set  */
  YYSYMBOL_arg_set = 57,                   /* arg_set  */
  YYSYMBOL_expr = 58                       /* expr  */
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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYLAST   371

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  12
/* YYNRULES -- Number of rules.  */
#define YYNRULES  59
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  135

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   279


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
      39,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    32,     2,     2,     2,     2,    40,     2,
      43,    44,    33,    29,    26,    30,    45,    34,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      28,    24,    27,    31,    25,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    36,     2,    37,    35,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    41,    46,    42,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    38
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    67,    67,    80,    92,   105,   118,   123,   124,   130,
     134,   138,   143,   149,   153,   160,   167,   169,   171,   172,
     173,   179,   180,   181,   182,   183,   184,   188,   192,   200,
     201,   205,   206,   210,   211,   212,   216,   217,   218,   219,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   235,   239,   240,   245,   250,   271,   292,   296
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
  "CALL", "WHILE", "EF", "'='", "'@'", "','", "'>'", "'<'", "'+'", "'-'",
  "'?'", "'!'", "'*'", "'/'", "'^'", "'['", "']'", "UMINUS", "'\\n'",
  "'&'", "'{'", "'}'", "'('", "')'", "'.'", "'|'", "$accept", "program",
  "record", "block", "proc", "declaration", "sentence", "cond",
  "group_comma", "conv_proc_set", "arg_set", "expr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-100)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -100,    58,  -100,   -27,  -100,  -100,    12,     7,  -100,    24,
      29,    16,    20,    21,    28,    32,    53,   145,  -100,    75,
     145,   145,   145,    45,    46,    47,    48,    50,    52,   209,
    -100,   -11,    74,    93,    92,    10,    89,   145,   145,   145,
     145,   145,    59,   162,   145,  -100,   193,   175,  -100,  -100,
    -100,   117,  -100,   117,   145,   145,   145,   145,   145,   145,
     145,   145,   145,   145,   145,   117,   145,   145,   145,  -100,
      67,   105,    87,    76,  -100,    99,   222,   236,   250,   264,
      71,   306,  -100,    72,   108,  -100,  -100,  -100,   329,   149,
     149,   335,   335,   -25,   -25,    -7,    -7,    90,   278,  -100,
     319,   292,   319,    10,    10,   108,  -100,  -100,  -100,  -100,
    -100,  -100,   145,  -100,  -100,  -100,  -100,    91,  -100,  -100,
    -100,    88,   118,    22,   126,   126,   108,  -100,   122,   101,
     129,   126,   126,  -100,  -100
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       8,     0,     1,     0,    38,    39,     0,    36,    37,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     7,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       6,    17,    16,     0,     0,     0,     0,     0,     0,     0,
       0,    35,    36,     0,    35,    50,     0,     0,     2,     3,
       4,    21,     5,    23,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    22,     0,     0,     0,    53,
       0,     0,    29,     0,    14,     0,     0,     0,     0,     0,
       0,    33,    28,     0,     0,    40,    24,    26,    52,    42,
      41,    43,    44,    45,    46,    47,    48,    49,     0,    25,
      18,     0,    19,     0,     0,     0,    13,    56,    57,    58,
      59,    55,    35,    54,    27,    51,    20,     0,    30,    15,
      34,     0,    12,     0,     0,     0,     0,    11,    10,     0,
       0,    31,     0,    32,     9
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -100,  -100,  -100,   -36,  -100,   -33,   -35,  -100,   -50,   -99,
     -38,   -17
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,    23,    24,    25,    26,    27,    28,    73,   127,
      80,    29
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      43,    75,    72,    45,    46,    47,    83,    82,    61,    62,
      63,    64,    30,    66,    32,     6,    86,    71,    87,    31,
      76,    77,    78,    79,    81,    67,   128,    81,    63,    64,
      99,    34,   133,   134,   124,   125,    35,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,   114,   100,
     101,   102,    33,   117,   118,    36,    37,    38,     2,     3,
      41,     4,     5,     6,    39,     7,     8,     9,    40,   119,
      72,    72,    10,    11,   120,    12,    13,    14,    15,    16,
      17,    18,    44,    19,    48,    49,    50,    51,    20,    52,
     129,    53,     4,     5,     6,    81,     7,     8,    68,    21,
      69,    22,    70,   103,    33,    74,    12,    13,    14,    15,
      16,    17,    32,   104,    19,   106,   105,   111,   113,    20,
       4,     5,     6,    11,     7,     8,    64,   122,   121,   123,
      21,   126,    22,   130,    12,    13,    14,    15,    16,    17,
     131,   132,    19,     0,     0,     0,     0,    20,     4,     5,
       0,     0,    42,     8,     0,     0,     0,     0,    21,     0,
      22,     0,    12,    13,    14,    15,    16,     0,     0,     0,
      19,     0,     0,     0,     0,    20,     0,    11,    57,    58,
      59,    60,    61,    62,    63,    64,    54,     0,    22,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    54,
       0,     0,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,     0,     0,     0,     0,     0,    54,     0,    85,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
       0,     0,     0,    54,     0,    84,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    54,     0,    65,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,   107,
      54,     0,     0,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,   108,    54,     0,     0,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,   109,    54,     0,
       0,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,   110,    54,     0,     0,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,   115,    54,     0,     0,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,   116,
      54,     0,   112,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    54,     0,     0,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    59,    60,    61,    62,
      63,    64
};

static const yytype_int16 yycheck[] =
{
      17,    36,    35,    20,    21,    22,    44,    43,    33,    34,
      35,    36,    39,    24,     7,     5,    51,     7,    53,     7,
      37,    38,    39,    40,    41,    36,   125,    44,    35,    36,
      65,     7,   131,   132,    12,    13,     7,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    84,    66,
      67,    68,    45,   103,   104,    39,    36,    36,     0,     1,
       7,     3,     4,     5,    36,     7,     8,     9,    36,   105,
     103,   104,    14,    15,   112,    17,    18,    19,    20,    21,
      22,    23,     7,    25,    39,    39,    39,    39,    30,    39,
     126,    39,     3,     4,     5,   112,     7,     8,    24,    41,
       7,    43,    10,    36,    45,    16,    17,    18,    19,    20,
      21,    22,     7,    26,    25,    16,    40,    46,    46,    30,
       3,     4,     5,    15,     7,     8,    36,    39,    37,    11,
      41,     5,    43,    11,    17,    18,    19,    20,    21,    22,
      39,    12,    25,    -1,    -1,    -1,    -1,    30,     3,     4,
      -1,    -1,     7,     8,    -1,    -1,    -1,    -1,    41,    -1,
      43,    -1,    17,    18,    19,    20,    21,    -1,    -1,    -1,
      25,    -1,    -1,    -1,    -1,    30,    -1,    15,    29,    30,
      31,    32,    33,    34,    35,    36,    24,    -1,    43,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    24,
      -1,    -1,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,    -1,    -1,    -1,    24,    -1,    44,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    -1,    24,    -1,    42,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    24,    -1,    39,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      24,    -1,    -1,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    24,    -1,    -1,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    24,    -1,
      -1,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    24,    -1,    -1,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    24,    -1,    -1,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      24,    -1,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    24,    -1,    -1,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    31,    32,    33,    34,
      35,    36
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    48,     0,     1,     3,     4,     5,     7,     8,     9,
      14,    15,    17,    18,    19,    20,    21,    22,    23,    25,
      30,    41,    43,    49,    50,    51,    52,    53,    54,    58,
      39,     7,     7,    45,     7,     7,    39,    36,    36,    36,
      36,     7,     7,    58,     7,    58,    58,    58,    39,    39,
      39,    39,    39,    39,    24,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    39,    24,    36,    24,     7,
      10,     7,    52,    55,    16,    53,    58,    58,    58,    58,
      57,    58,    50,    57,    42,    44,    53,    53,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    53,
      58,    58,    58,    36,    26,    40,    16,    37,    37,    37,
      37,    46,    26,    46,    50,    37,    37,    55,    55,    50,
      57,    37,    39,    11,    12,    13,     5,    56,    56,    50,
      11,    39,    12,    56,    56
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    47,    48,    48,    48,    48,    48,    48,    48,    49,
      49,    49,    49,    50,    50,    51,    52,    52,    52,    52,
      52,    53,    53,    53,    53,    53,    53,    54,    54,    55,
      55,    56,    56,    57,    57,    57,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     3,     3,     3,     3,     2,     0,    13,
      10,    10,     7,     4,     3,     5,     2,     2,     4,     4,
       5,     2,     2,     2,     3,     3,     3,     4,     3,     1,
       3,     3,     4,     1,     3,     0,     1,     1,     1,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     4,     3,     3,     4,     4,     4,     4,     4,     4
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

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
}

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
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
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]));
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
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
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
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
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
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

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
      yyerror_range[1] = yylloc;
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
  *++yylsp = yylloc;

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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: program record '\n'  */
                            {
		std::cout << "HERE RECORD\n";
		if (!error)
		{
			std::cout << "SYNTAX TREE:\n";
			if (yyvsp[-1].tree) {syntax_tree->add(yyvsp[-1].tree);}
			syntax_tree->put_tree(syntax_tree->root, 0);
		}
		else
		{
			std::cout << "some errors occured, semantic analysis isn't possible\n";
		}
	}
    break;

  case 3: /* program: program block '\n'  */
                             {
		std::cout << "HERE BLOCK\n";
		if (!error)
		{
			std::cout << "SYNTAX TREE:\n";
			syntax_tree->put_tree(syntax_tree->root, 0);
		}
		else
		{
			std::cout << "some errors occured, semantic analysis isn't possible\n";
		}
	}
    break;

  case 4: /* program: program proc '\n'  */
                            {
		std::cout << "HERE PROC\n";
		if (!error)
		{
			std::cout << "SYNTAX TREE:\n";
			if (yyvsp[-1].tree) {syntax_tree->add(yyvsp[-1].tree);}
			syntax_tree->put_tree(syntax_tree->root, 0);
		}
		else
		{
			std::cout << "some errors occured, semantic analysis isn't possible\n";
		}
	}
    break;

  case 5: /* program: program sentence '\n'  */
                                {
		std::cout << "HERE SENTENCE\n";
		if (!error)
		{
			std::cout << "SYNTAX TREE:\n";
			if (yyvsp[-1].tree) {syntax_tree->add(yyvsp[-1].tree);}
			syntax_tree->put_tree(syntax_tree->root, 0);
		}
		else
		{
			std::cout << "some errors occured, semantic analysis isn't possible\n";
		}
	}
    break;

  case 6: /* program: program error '\n'  */
                             {
		error = true;
		std::cout << "Some error in line " << yyvsp[-1].line << "\n";		
		yyerrok;
	}
    break;

  case 7: /* program: program EF  */
                     {printf("Programm finished successfully!\n"); error = false; return 0;}
    break;

  case 8: /* program: %empty  */
          {
		syntax_tree = new ast();
		printf("enter a expression:\n");
	}
    break;

  case 9: /* record: RECORD SVAL DATA '[' group_comma ']' '\n' CONVERSION FROM conv_proc_set CONVERSION TO conv_proc_set  */
        {
		yyval.tree = new record_node(std::string(yyvsp[-11].text), yyvsp[-8].tree, yyvsp[-3].tree, yyvsp[0].tree , RECORDN, yyvsp[-12].line);
	}
    break;

  case 10: /* record: RECORD SVAL DATA '[' group_comma ']' '\n' CONVERSION FROM conv_proc_set  */
        {
		yyval.tree = new record_node(std::string(yyvsp[-8].text), yyvsp[-5].tree, yyvsp[0].tree, nullptr, RECORDN, yyvsp[-9].line);
	}
    break;

  case 11: /* record: RECORD SVAL DATA '[' group_comma ']' '\n' CONVERSION TO conv_proc_set  */
        {
		std::cout <<"$2 TEXT: " << yyvsp[-8].text << "\n";
		yyval.tree = new record_node(std::string(yyvsp[-8].text), yyvsp[-5].tree, nullptr, yyvsp[0].tree , RECORDN, yyvsp[-9].line);
	}
    break;

  case 12: /* record: RECORD SVAL DATA '[' group_comma ']' '\n'  */
        {
		yyval.tree = new record_node(std::string(yyvsp[-5].text), yyvsp[-2].tree, nullptr, nullptr , RECORDN, yyvsp[-6].line);
	}
    break;

  case 13: /* block: BLOCK '\n' sentence UNBLOCK  */
        {
		yyval.tree = new block_node(yyvsp[-1].tree, BLOCKN, yyvsp[-1].line);
	}
    break;

  case 14: /* block: BLOCK '\n' UNBLOCK  */
        {
		yyval.tree = new block_node(nullptr, BLOCKN, yyvsp[-2].line);
	}
    break;

  case 15: /* proc: PROC SVAL group_comma '&' block  */
        {
			yyval.tree = new proc_node(std::string(yyvsp[-3].text), yyvsp[-2].tree, yyvsp[0].tree, PROCN, yyvsp[-4].line);
	}
    break;

  case 16: /* declaration: SVAL SVAL  */
                  {yyval.tree = new decl_node(std::string(yyvsp[-1].text), std::string(yyvsp[0].text), nullptr, nullptr, UNDEFVARN, yyvsp[-1].line);
	syntax_tree->put_tree(yyval.tree, 0);}
    break;

  case 17: /* declaration: TYPE SVAL  */
                    {yyval.tree = new decl_node(std::string(yyvsp[-1].text), std::string(yyvsp[0].text), nullptr, nullptr, UNDEFVARN, yyvsp[-1].line);
	syntax_tree->put_tree(yyval.tree, 0);}
    break;

  case 18: /* declaration: TYPE SVAL '=' expr  */
                                {yyval.tree = new decl_node(std::string(yyvsp[-3].text), std::string(yyvsp[-2].text), nullptr, yyvsp[0].tree, VARN, yyvsp[-3].line);  printf("NAME: %s\n", yyvsp[-2].text); printf("TYPE: %s\n", yyvsp[-3].text); syntax_tree->put_tree(yyval.tree, 0);}
    break;

  case 19: /* declaration: SVAL SVAL '=' expr  */
                                {yyval.tree = new decl_node(std::string(yyvsp[-3].text), std::string(yyvsp[-2].text), nullptr, yyvsp[0].tree, VARN, yyvsp[-3].line);  printf("NAME: %s\n", yyvsp[-2].text); printf("TYPE: %s\n", yyvsp[-3].text); syntax_tree->put_tree(yyval.tree, 0);}
    break;

  case 20: /* declaration: TYPE SVAL '[' expr ']'  */
                                 {
		yyval.tree = new decl_node(std::string(yyvsp[-4].text), std::string(yyvsp[-3].text), yyvsp[-1].tree, nullptr, UNDEFVARN, yyvsp[-4].line); syntax_tree->put_tree(yyval.tree, 0);  
	}
    break;

  case 21: /* sentence: declaration '\n'  */
                          {yyval = yyvsp[-1]; }
    break;

  case 22: /* sentence: expr '\n'  */
                    {yyval = yyvsp[-1]; }
    break;

  case 23: /* sentence: cond '\n'  */
                    {yyval = yyvsp[-1];}
    break;

  case 24: /* sentence: declaration '\n' sentence  */
                                    {if (yyvsp[-2].tree && yyvsp[0].tree) {yyvsp[0].tree->set_left(yyvsp[-2].tree); yyval = yyvsp[0]; syntax_tree->put_tree(yyval.tree, 0);} std::cout << "SENTENCE AND GROUP SET\n"; }
    break;

  case 25: /* sentence: expr '\n' sentence  */
                             {if (yyvsp[-2].tree && yyvsp[0].tree) {yyvsp[0].tree->set_left(yyvsp[-2].tree); yyval = yyvsp[0]; syntax_tree->put_tree(yyval.tree, 0);} std::cout << "EXPR AND GROUP SET\n"; }
    break;

  case 26: /* sentence: cond '\n' sentence  */
                             {if (yyvsp[-2].tree && yyvsp[0].tree) {yyvsp[0].tree->set_left(yyvsp[-2].tree); yyval = yyvsp[0]; syntax_tree->put_tree(yyval.tree, 0);} std::cout << "BLOCK AND GROUP SET\n";}
    break;

  case 27: /* cond: '{' expr '}' block  */
        {
		yyval.tree = new cond_node(yyvsp[-2].tree, yyvsp[0].tree, CONDN, yyvsp[-3].line);
	}
    break;

  case 28: /* cond: WHILE expr block  */
        {
		std::cout << "Wrong loop declaration in line " << yyvsp[-1].line << "\n";
		error = true;
	}
    break;

  case 29: /* group_comma: declaration  */
                    {yyval = yyvsp[0];}
    break;

  case 30: /* group_comma: declaration ',' group_comma  */
                                      {yyvsp[0].tree->set_left(yyvsp[-2].tree); yyval = yyvsp[0]; std::cout << "DECLARATION GROUP COMMA\n"; syntax_tree->put_tree(yyval.tree, 0);}
    break;

  case 31: /* conv_proc_set: TYPE block '\n'  */
                        {yyval.tree = new conv_node(std::string(yyvsp[-2].text), yyvsp[-1].tree, CONVPROCN, yyvsp[-2].line);}
    break;

  case 32: /* conv_proc_set: TYPE block '\n' conv_proc_set  */
                                        {yyvsp[-1].tree->set_left(yyvsp[-3].tree); yyval = yyvsp[-1]; std::cout << "CONV_PROC AND CONV_PROC SET\n"; syntax_tree->put_tree(yyval.tree, 0);}
    break;

  case 33: /* arg_set: expr  */
             { yyval = yyvsp[0];}
    break;

  case 34: /* arg_set: expr ',' arg_set  */
                           {yyvsp[0].tree->set_left(yyvsp[-2].tree); yyval = yyvsp[0]; std::cout << "EXPR AND ARG_SET\n"; syntax_tree->put_tree(yyval.tree, 0);}
    break;

  case 35: /* arg_set: %empty  */
          {yyval.tree = nullptr;}
    break;

  case 36: /* expr: SVAL  */
             {yyval.tree = new str_node(std::string(yyvsp[0].text), STRN, yyvsp[0].line); printf("SVAL WITH VAL = \"%s\"\n", yyvsp[0].text);}
    break;

  case 37: /* expr: LITERAL  */
                  {yyval.tree = new str_node(std::string(yyvsp[0].text), LITERALN, yyvsp[0].line);  printf("LITERAL WITH VAL = \"%s\"\n", yyvsp[0].text);}
    break;

  case 38: /* expr: INTNUM  */
                 {yyval.tree = new int_node(atoi(yyvsp[0].text), INTN, yyvsp[0].line); printf("INTNUM WITH LINE: %d\n", yyvsp[0].line); printf("INTNUM %d\n", atoi(yyvsp[0].text));}
    break;

  case 39: /* expr: BOOLNUM  */
                  {bool buf; if (strcmp(yyvsp[0].text, "TRUE") == 0) {buf = true;} else {buf = false;} yyval.tree = new bool_node(buf,
	 BOOLN, yyvsp[0].line); printf("BOOLNUM %d\n", buf);}
    break;

  case 40: /* expr: '(' expr ')'  */
                       {yyval.tree = yyvsp[-1].tree;}
    break;

  case 41: /* expr: expr '<' expr  */
                        {yyval.tree = new operation_node(yyvsp[-2].tree, yyvsp[0].tree, LESSN, yyvsp[-2].line); }
    break;

  case 42: /* expr: expr '>' expr  */
                        {yyval.tree = new operation_node(yyvsp[-2].tree, yyvsp[0].tree, GREATERN, yyvsp[-2].line); }
    break;

  case 43: /* expr: expr '+' expr  */
                        {yyval.tree = new operation_node(yyvsp[-2].tree, yyvsp[0].tree, PLUSN, yyvsp[-2].line); }
    break;

  case 44: /* expr: expr '-' expr  */
                        {yyval.tree = new operation_node(yyvsp[-2].tree, yyvsp[0].tree, NEGN, yyvsp[-2].line); }
    break;

  case 45: /* expr: expr '?' expr  */
                        {yyval.tree = new operation_node(yyvsp[-2].tree, yyvsp[0].tree, EQUN, yyvsp[-2].line); }
    break;

  case 46: /* expr: expr '!' expr  */
                        {yyval.tree = new operation_node(yyvsp[-2].tree, yyvsp[0].tree, NOTEQUN, yyvsp[-2].line); }
    break;

  case 47: /* expr: expr '*' expr  */
                        {yyval.tree = new operation_node(yyvsp[-2].tree, yyvsp[0].tree, MULN, yyvsp[-2].line); }
    break;

  case 48: /* expr: expr '/' expr  */
                        {yyval.tree = new operation_node(yyvsp[-2].tree, yyvsp[0].tree, DIVN, yyvsp[-2].line); }
    break;

  case 49: /* expr: expr '^' expr  */
                        {yyval.tree = new operation_node(yyvsp[-2].tree, yyvsp[0].tree, EXPN, yyvsp[-2].line); }
    break;

  case 50: /* expr: '-' expr  */
                                {yyval.tree = new unary_node(yyvsp[-1].tree, UMINN, yyvsp[-1].line);}
    break;

  case 51: /* expr: expr '[' expr ']'  */
                            {
		yyval.tree = new arr_node(yyvsp[-3].tree, yyvsp[-1].tree, ARRASSIGNN, yyvsp[-3].line);
	}
    break;

  case 52: /* expr: expr '=' expr  */
                        {
            yyval.tree = new assign_node(yyvsp[-2].tree, yyvsp[0].tree, ASSIGNN, yyvsp[-2].line);
             syntax_tree->put_tree(yyval.tree, 0); 
	}
    break;

  case 53: /* expr: SVAL '.' SVAL  */
                        {yyval.tree = new struct_ref_node(std::string(yyvsp[-2].text), std::string (yyvsp[0].text), STRUCTREFN, yyvsp[-2].line);}
    break;

  case 54: /* expr: '@' SVAL arg_set '|'  */
        {
	    		std::cout << "CALL HERE!\n";
	            yyval.tree = new proc_node(std::string(yyvsp[-2].text), yyvsp[-1].tree, nullptr, CALLN, yyvsp[-3].line);
	}
    break;

  case 55: /* expr: CALL SVAL arg_set '|'  */
        {
		std::cout << "Wrong calling of function in line " << yyvsp[-3].line << "\n";
		error = true;
	}
    break;

  case 56: /* expr: MOVE '[' expr ']'  */
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
		yyval.tree = new move_node(yyvsp[-1].tree, op, yyvsp[-3].line);
	}
    break;

  case 57: /* expr: PING '[' expr ']'  */
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
                yyval.tree = new ping_node(yyvsp[-1].tree, op, yyvsp[-3].line);
	}
    break;

  case 58: /* expr: VISION '[' expr ']'  */
        {
                yyval.tree = new vision_node(yyvsp[-1].tree, VISIONN, yyvsp[-3].line);
	}
    break;

  case 59: /* expr: VOICE '[' expr ']'  */
    {
            yyval.tree = new voice_node(yyvsp[-1].tree, VOICEN, yyvsp[-3].line);
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
  *++yylsp = yyloc;

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

  yyerror_range[1] = yylloc;
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
                      yytoken, &yylval, &yylloc);
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

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
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}



#include <stdbool.h>

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
	if (!error)
	{
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
	}
	return 0;
}
