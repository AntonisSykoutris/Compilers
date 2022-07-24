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
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "quads.h"
#include "symtable.h"
#include "symboltype.h"
#include "Variable.h"
#include "Function.h"

#define ERROR_OUT stderr
#define RULES_STREAM rules_out
#define SYMTAB_SC_OUT sym_sc_out
#define SYMTAB_BUC_OUT sym_buc_out
#define QUAD_STREAM quad_out

#define MAX_INNER_FUNC 50

int yydebug = 1;

int exit_flag = 0;

typedef enum error_t{
    error,
    warning
}error_t;
char error_msg[100];

struct forpr_s{
    int test;
    int enter;
};

struct break_s{
    struct list_s* breaklist;
};

struct cont_s{
    struct list_s* contlist;
};



int getCurrScope();
int getCurrLine();
void print_rules(char* rule1, char* rule2);
void print_error(error_t eror_type, char* msg);
void funcjumpsReset(int offset);

int yylex();
void yyerror();
extern int yylineno;
extern char *yytext;

extern FILE *yyin;
extern FILE *yyout;
FILE *rules_out;
FILE* quad_out;
FILE* sym_sc_out;
FILE* sym_buc_out;

int curr_scope = 0;
bool isLocal = false;

SymTable *table;

/* Variables used for funcdef */
struct func_node{
    int local_offset;
    struct func_node* next;
};

struct func_local_stack{
    struct func_node* tail;
    struct func_node* head;
    int nodes;
};
struct func_local_stack* functionLocalsStack;
struct func_local_stack* create_func_stack();
void func_push(struct func_local_stack* s, int cur_local_offset);
int func_pop(struct func_local_stack* s);
int func_top(struct func_local_stack* s);

quad *funcjumpQuad[MAX_INNER_FUNC];
quad *retjumpQuad[MAX_INNER_FUNC];
int functionOffset = -1;

/* Flags and variables for function calls */
int parserFlag = 0;
int libreturnCnt = 0;

/* return - break - continue flags */
struct stack_s* loopstack;
int returnCnt = 0;

/* -=-=-=- for/while flags and vars -=-=-=- */
quad* whileQuad;
int loopcounter = 0;


#line 169 "parser.c" /* yacc.c:339  */

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
   by #include "parser.h".  */
#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
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
    INT_CONST = 258,
    REAL_CONST = 259,
    ID = 260,
    KEYWORD = 261,
    OPERATOR = 262,
    PUNCTATION = 263,
    STRING = 264,
    TRUE = 265,
    FALSE = 266,
    AND = 267,
    OR = 268,
    NOT = 269,
    ASSIGN = 270,
    PLUS = 271,
    MINUS = 272,
    MULTIPLY = 273,
    DIVIDE = 274,
    MOD = 275,
    GREATER = 276,
    GREATER_EQ = 277,
    LESS = 278,
    LESS_EQ = 279,
    EQ = 280,
    NOT_EQ = 281,
    UMINUS = 282,
    INCREMENT = 283,
    DECREMENT = 284,
    OPEN_BRACKET = 285,
    CLOSE_BRACKET = 286,
    OPEN_SUBSCRIPT = 287,
    CLOSE_SUBSCRIPT = 288,
    OPEN_PAR = 289,
    CLOSE_PAR = 290,
    SEMICOLON = 291,
    COMMA = 292,
    COLON = 293,
    DOUBLE_COLON = 294,
    DOUBLE_DOT = 295,
    DOT = 296,
    WHILE = 297,
    FOR = 298,
    BREAK = 299,
    CONTINUE = 300,
    RETURN = 301,
    IF = 302,
    ELSE = 303,
    LOCAL = 304,
    NIL = 305,
    FUNCTION = 306,
    END_OF_FILE = 307,
    INF_COMMENT = 308,
    INF_STRING = 309
  };
#endif
/* Tokens.  */
#define INT_CONST 258
#define REAL_CONST 259
#define ID 260
#define KEYWORD 261
#define OPERATOR 262
#define PUNCTATION 263
#define STRING 264
#define TRUE 265
#define FALSE 266
#define AND 267
#define OR 268
#define NOT 269
#define ASSIGN 270
#define PLUS 271
#define MINUS 272
#define MULTIPLY 273
#define DIVIDE 274
#define MOD 275
#define GREATER 276
#define GREATER_EQ 277
#define LESS 278
#define LESS_EQ 279
#define EQ 280
#define NOT_EQ 281
#define UMINUS 282
#define INCREMENT 283
#define DECREMENT 284
#define OPEN_BRACKET 285
#define CLOSE_BRACKET 286
#define OPEN_SUBSCRIPT 287
#define CLOSE_SUBSCRIPT 288
#define OPEN_PAR 289
#define CLOSE_PAR 290
#define SEMICOLON 291
#define COMMA 292
#define COLON 293
#define DOUBLE_COLON 294
#define DOUBLE_DOT 295
#define DOT 296
#define WHILE 297
#define FOR 298
#define BREAK 299
#define CONTINUE 300
#define RETURN 301
#define IF 302
#define ELSE 303
#define LOCAL 304
#define NIL 305
#define FUNCTION 306
#define END_OF_FILE 307
#define INF_COMMENT 308
#define INF_STRING 309

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 104 "parser.y" /* yacc.c:355  */

    int integer;
    double num;
    char *str;
    char character;
    bool boolean;
    struct expr* exp;
    struct arguments_s* arg;
    struct call_s* call_type;
    struct indexed_elem* ind_elem;
    struct elements* elems;
    struct SymbolTableEntry* symbol;
    struct forpr_s* forpr_t;
    struct stmt_s* stmt_t;
    struct break_s* break_t;
    struct cont_s* cont_t;

#line 335 "parser.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 352 "parser.c" /* yacc.c:358  */

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   574

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  55
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  54
/* YYNRULES -- Number of rules.  */
#define YYNRULES  112
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  197

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   309

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   175,   175,   178,   186,   192,   196,   200,   210,   220,
     230,   236,   240,   246,   254,   257,   260,   264,   264,   274,
     274,   285,   285,   296,   296,   307,   311,   315,   319,   324,
     328,   332,   336,   340,   344,   350,   354,   364,   372,   407,
     448,   480,   519,   523,   522,   567,   571,   575,   578,   583,
     589,   614,   622,   650,   656,   661,   669,   673,   683,   699,
     725,   725,   740,   741,   744,   758,   771,   780,   786,   795,
     809,   822,   822,   841,   846,   851,   851,   870,   889,   913,
     913,   922,   930,   931,   934,   938,   942,   947,   952,   957,
     962,   966,   971,   979,   991,   991,  1005,  1012,  1018,  1024,
    1031,  1038,  1041,  1044,  1047,  1056,  1068,  1091,  1094,  1097,
    1112,  1137,  1148
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT_CONST", "REAL_CONST", "ID",
  "KEYWORD", "OPERATOR", "PUNCTATION", "STRING", "TRUE", "FALSE", "AND",
  "OR", "NOT", "ASSIGN", "PLUS", "MINUS", "MULTIPLY", "DIVIDE", "MOD",
  "GREATER", "GREATER_EQ", "LESS", "LESS_EQ", "EQ", "NOT_EQ", "UMINUS",
  "INCREMENT", "DECREMENT", "OPEN_BRACKET", "CLOSE_BRACKET",
  "OPEN_SUBSCRIPT", "CLOSE_SUBSCRIPT", "OPEN_PAR", "CLOSE_PAR",
  "SEMICOLON", "COMMA", "COLON", "DOUBLE_COLON", "DOUBLE_DOT", "DOT",
  "WHILE", "FOR", "BREAK", "CONTINUE", "RETURN", "IF", "ELSE", "LOCAL",
  "NIL", "FUNCTION", "END_OF_FILE", "INF_COMMENT", "INF_STRING", "$accept",
  "program", "stmt", "stmts", "M", "expr", "$@1", "$@2", "$@3", "$@4",
  "term", "assignexpr", "$@5", "primary", "lvalue", "member", "call",
  "$@6", "callsuffix", "normalcall", "methodcall", "elist", "objectdef",
  "indexedelem", "$@7", "indexed", "block", "$@8", "funcdef", "funcprefix",
  "funcargs", "$@9", "funcbody", "funcname", "idlist", "const", "ifprefix",
  "ifstmt", "$@10", "elsestmt", "elserpefix", "breakst", "continuest",
  "loopstart", "loopend", "loopstmt", "whilestart", "whilecond",
  "whilestmt", "K", "L", "forprefix", "forstmt", "returnstmt", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309
};
# endif

#define YYPACT_NINF -164

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-164)))

#define YYTABLE_NINF -61

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-61)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -164,    22,   156,  -164,  -164,  -164,  -164,  -164,  -164,  -164,
     322,   322,    20,    20,  -164,   248,   205,  -164,    -3,  -164,
       3,     7,    14,   285,    66,    96,  -164,    98,  -164,   102,
    -164,  -164,  -164,    76,  -164,   -17,  -164,  -164,  -164,    78,
    -164,   156,  -164,  -164,  -164,    79,  -164,  -164,  -164,  -164,
    -164,  -164,    80,   -14,   -17,   -14,  -164,   322,   511,    25,
    -164,    27,   399,    52,  -164,   322,  -164,  -164,  -164,   357,
     322,  -164,  -164,  -164,  -164,  -164,   322,   322,   322,   322,
     322,   322,   322,   322,   322,  -164,  -164,  -164,  -164,  -164,
    -164,   322,   322,   124,   129,  -164,  -164,  -164,   322,   322,
     130,  -164,   103,  -164,   322,  -164,   322,   101,     2,   511,
    -164,   322,  -164,   107,  -164,   105,    56,  -164,   419,  -164,
    -164,    47,    47,  -164,  -164,  -164,   128,   128,   128,   128,
    -164,  -164,   322,   459,    26,   106,  -164,   477,    35,  -164,
     136,  -164,  -164,    94,   439,   156,  -164,    36,  -164,  -164,
     115,   511,  -164,   135,  -164,  -164,   322,   322,   322,   322,
     511,  -164,  -164,   322,  -164,  -164,  -164,    48,  -164,  -164,
     156,  -164,  -164,  -164,   322,   322,   322,   537,   526,   548,
     548,    49,  -164,   153,  -164,  -164,  -164,   495,    53,   378,
    -164,  -164,  -164,  -164,  -164,  -164,  -164
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      14,     0,     2,     1,    88,    87,    50,    89,    91,    92,
       0,     0,     0,     0,    75,    68,     0,    12,     0,   104,
       0,     0,     0,     0,     0,     0,    90,    83,    13,     0,
      34,    16,    42,    45,    53,    46,    47,    10,    11,     0,
      49,     0,     4,     8,     9,     0,     5,   107,     6,     7,
      37,    36,     0,    38,     0,    40,    14,     0,    66,     0,
      73,     0,     0,     0,    52,    68,    99,   100,   112,     0,
       0,    51,    82,    78,    19,    17,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    15,    15,     3,    43,    39,
      41,     0,    68,     0,     0,    59,    62,    63,     0,    68,
       0,    79,     0,    94,     0,   101,    68,     0,     0,    71,
      69,     0,    70,     0,    35,    48,     0,   111,     0,    15,
      15,    29,    30,    31,    32,    33,    25,    26,    27,    28,
      21,    23,     0,     0,     0,     0,    54,     0,     0,    56,
      86,    81,    77,    97,     0,     0,   106,     0,    60,    76,
       0,    67,    74,     0,   108,    93,     0,     0,     0,     0,
      44,    55,    64,    68,    57,    58,    84,     0,    98,    95,
       0,   105,   102,   107,     0,    68,     0,    20,    18,    22,
      24,     0,    80,     0,    96,   103,   101,     0,     0,     0,
      65,    85,   107,    72,    61,   109,   110
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -164,  -164,   -38,   108,   -63,    -2,  -164,  -164,  -164,  -164,
    -164,  -164,  -164,  -164,    82,  -164,    85,  -164,  -164,  -164,
    -164,   -64,  -164,    50,  -164,  -164,    60,  -164,   -12,  -164,
    -164,  -164,  -164,  -164,  -164,  -164,  -164,  -164,  -164,  -164,
    -164,  -164,  -164,  -164,  -164,   -15,  -164,  -164,  -164,  -163,
    -164,  -164,  -164,  -164
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    28,     2,   130,    58,   120,   119,   158,   159,
      30,    31,   132,    32,    33,    34,    35,   153,    95,    96,
      97,    59,    36,    60,   150,    61,    37,    56,    38,    39,
     102,   140,   142,    73,   167,    40,    41,    42,   143,   169,
     170,    43,    44,   145,   185,   146,    45,   105,    46,   106,
     176,    47,    48,    49
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      29,   116,    64,   103,    63,     4,     5,     6,    50,    51,
     186,     7,     8,     9,    62,    98,    10,    99,    91,    11,
      92,    69,     3,   131,   100,     6,    93,    94,   134,   196,
      12,    13,    14,   149,    15,   138,    16,    65,    17,    29,
     107,    18,   147,    66,    19,    20,    21,    22,    23,    24,
      67,    25,    26,    27,    52,   109,   156,   157,   110,    18,
     112,   162,   111,   111,   113,    78,    79,    80,   118,    25,
     165,   173,   111,   111,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   182,   190,   183,   111,   115,   194,   133,
     111,    88,   154,   111,    53,    55,   137,    54,    54,   181,
      70,    71,   144,    72,    89,    90,    29,   172,    91,   151,
      92,   188,   101,   104,    74,    75,    93,    94,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,   135,
     160,    27,   184,    14,   136,   139,   148,    57,    87,   -60,
     163,   166,   168,    29,    76,    77,    78,    79,    80,   -61,
     -61,   -61,   -61,   174,   177,   178,   179,   180,   191,     4,
       5,     6,   141,   152,   108,     7,     8,     9,    29,   175,
      10,   192,   187,    11,   189,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    12,    13,    14,     0,    15,     0,
      16,     0,    17,     0,     0,    18,     0,     0,    19,    20,
      21,    22,    23,    24,     0,    25,    26,    27,     4,     5,
       6,     0,     0,     0,     7,     8,     9,     0,     0,    10,
       0,     0,    11,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    12,    13,     0,     0,    15,     0,    16,
       0,     0,     0,     0,    18,     0,     0,     0,     0,     0,
       0,     4,     5,     6,    25,    26,    27,     7,     8,     9,
       0,     0,    10,     0,     0,    11,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    12,    13,    57,     0,
      15,     0,    16,     0,     0,     0,     0,    18,     4,     5,
       6,     0,     0,     0,     7,     8,     9,    25,    26,    10,
       0,     0,    11,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    12,    13,     0,     0,    15,     0,    16,
       0,    68,     0,     0,    18,     4,     5,     6,     0,     0,
       0,     7,     8,     9,    25,    26,    10,     0,     0,    11,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      12,    13,     0,     0,    15,     0,    16,     0,     0,     0,
       0,    18,     0,     0,     0,     0,     0,     0,     0,    74,
      75,    25,    26,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,     0,     0,     0,     0,     0,     0,
      74,    75,     0,   117,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,     0,     0,     0,     0,     0,
       0,    74,    75,     0,   195,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,     0,     0,     0,     0,
       0,    74,    75,     0,   114,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,     0,     0,     0,     0,
       0,    74,    75,     0,   155,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,     0,     0,     0,     0,
       0,    74,    75,     0,   171,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,     0,     0,     0,    74,
      75,     0,   161,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,     0,     0,     0,    74,    75,     0,
     164,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,     0,    74,    75,     0,   193,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    74,     0,
       0,     0,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    76,    77,    78,    79,    80,    81,
      82,    83,    84,   -61,   -61
};

static const yytype_int16 yycheck[] =
{
       2,    65,     5,    41,    16,     3,     4,     5,    10,    11,
     173,     9,    10,    11,    16,    32,    14,    34,    32,    17,
      34,    23,     0,    86,    41,     5,    40,    41,    92,   192,
      28,    29,    30,    31,    32,    99,    34,    34,    36,    41,
      52,    39,   106,    36,    42,    43,    44,    45,    46,    47,
      36,    49,    50,    51,    34,    57,   119,   120,    33,    39,
      33,    35,    37,    37,    37,    18,    19,    20,    70,    49,
      35,    35,    37,    37,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    35,    35,    37,    37,    35,    35,    91,
      37,    15,    36,    37,    12,    13,    98,    12,    13,   163,
      34,     5,   104,     5,    28,    29,   108,   145,    32,   111,
      34,   175,    34,    34,    12,    13,    40,    41,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,     5,
     132,    51,   170,    30,     5,     5,    35,    30,    36,    34,
      34,     5,    48,   145,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    38,   156,   157,   158,   159,     5,     3,
       4,     5,   102,   113,    56,     9,    10,    11,   170,    34,
      14,   186,   174,    17,   176,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    28,    29,    30,    -1,    32,    -1,
      34,    -1,    36,    -1,    -1,    39,    -1,    -1,    42,    43,
      44,    45,    46,    47,    -1,    49,    50,    51,     3,     4,
       5,    -1,    -1,    -1,     9,    10,    11,    -1,    -1,    14,
      -1,    -1,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    28,    29,    -1,    -1,    32,    -1,    34,
      -1,    -1,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,    49,    50,    51,     9,    10,    11,
      -1,    -1,    14,    -1,    -1,    17,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    28,    29,    30,    -1,
      32,    -1,    34,    -1,    -1,    -1,    -1,    39,     3,     4,
       5,    -1,    -1,    -1,     9,    10,    11,    49,    50,    14,
      -1,    -1,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    28,    29,    -1,    -1,    32,    -1,    34,
      -1,    36,    -1,    -1,    39,     3,     4,     5,    -1,    -1,
      -1,     9,    10,    11,    49,    50,    14,    -1,    -1,    17,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      28,    29,    -1,    -1,    32,    -1,    34,    -1,    -1,    -1,
      -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    12,
      13,    49,    50,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,
      12,    13,    -1,    36,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    -1,    -1,    -1,    -1,    -1,
      -1,    12,    13,    -1,    36,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    -1,    -1,    -1,    -1,
      -1,    12,    13,    -1,    35,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    -1,    -1,    -1,    -1,
      -1,    12,    13,    -1,    35,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    -1,    -1,    -1,    -1,
      -1,    12,    13,    -1,    35,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    -1,    -1,    -1,    12,
      13,    -1,    33,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    -1,    -1,    -1,    12,    13,    -1,
      33,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    -1,    12,    13,    -1,    31,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    12,    -1,
      -1,    -1,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    56,    58,     0,     3,     4,     5,     9,    10,    11,
      14,    17,    28,    29,    30,    32,    34,    36,    39,    42,
      43,    44,    45,    46,    47,    49,    50,    51,    57,    60,
      65,    66,    68,    69,    70,    71,    77,    81,    83,    84,
      90,    91,    92,    96,    97,   101,   103,   106,   107,   108,
      60,    60,    34,    69,    71,    69,    82,    30,    60,    76,
      78,    80,    60,    83,     5,    34,    36,    36,    36,    60,
      34,     5,     5,    88,    12,    13,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    36,    15,    28,
      29,    32,    34,    40,    41,    73,    74,    75,    32,    34,
      41,    34,    85,    57,    34,   102,   104,    83,    58,    60,
      33,    37,    33,    37,    35,    35,    76,    36,    60,    62,
      61,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      59,    59,    67,    60,    76,     5,     5,    60,    76,     5,
      86,    81,    87,    93,    60,    98,   100,    76,    35,    31,
      79,    60,    78,    72,    36,    35,    59,    59,    63,    64,
      60,    33,    35,    34,    33,    35,     5,    89,    48,    94,
      95,    35,    57,    35,    38,    34,   105,    60,    60,    60,
      60,    76,    35,    37,    57,    99,   104,    60,    76,    60,
      35,     5,   100,    31,    35,    36,   104
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    55,    56,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    58,    58,    59,    60,    61,    60,    62,
      60,    63,    60,    64,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    65,    65,    65,    65,    65,
      65,    65,    65,    67,    66,    68,    68,    68,    68,    68,
      69,    69,    69,    69,    70,    70,    70,    70,    71,    71,
      72,    71,    73,    73,    74,    75,    76,    76,    76,    77,
      77,    79,    78,    80,    80,    82,    81,    83,    84,    86,
      85,    87,    88,    88,    89,    89,    89,    90,    90,    90,
      90,    90,    90,    91,    93,    92,    94,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   108
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     0,     0,     1,     0,     5,     0,
       5,     0,     5,     0,     5,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     3,     2,     2,     2,     2,
       2,     2,     1,     0,     4,     1,     1,     1,     3,     1,
       1,     2,     2,     1,     3,     4,     3,     4,     4,     2,
       0,     7,     1,     1,     3,     5,     1,     3,     0,     3,
       3,     0,     6,     1,     3,     0,     4,     3,     2,     0,
       4,     1,     1,     0,     1,     3,     0,     1,     1,     1,
       1,     1,     1,     4,     0,     4,     2,     0,     1,     2,
       2,     0,     0,     3,     1,     3,     3,     0,     0,     7,
       7,     3,     2
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
#line 175 "parser.y" /* yacc.c:1646  */
    {print_rules("program","stmts");}
#line 1656 "parser.c" /* yacc.c:1646  */
    break;

  case 3:
#line 178 "parser.y" /* yacc.c:1646  */
    {
                                            print_rules("stmt","expr;");
                                            if((yyvsp[-1].exp)->type == boolexpr_e)
                                                (yyvsp[-1].exp) = bool_expr((yyvsp[-1].exp));
                                            (yyval.stmt_t) = new_stmt();
                                            (yyval.stmt_t)->exp = (yyvsp[-1].exp);
                                            
                                        }
#line 1669 "parser.c" /* yacc.c:1646  */
    break;

  case 4:
#line 186 "parser.y" /* yacc.c:1646  */
    {
                                            print_rules("stmt","ifstmt");
                                            (yyval.stmt_t) = new_stmt();
                                            (yyval.stmt_t)->breaklist = (yyvsp[0].stmt_t)->breaklist; 
                                            (yyval.stmt_t)->contlist = (yyvsp[0].stmt_t)->contlist;
                                        }
#line 1680 "parser.c" /* yacc.c:1646  */
    break;

  case 5:
#line 192 "parser.y" /* yacc.c:1646  */
    {
                                            print_rules("stmt","whilestmt");
                                            (yyval.stmt_t) = new_stmt();
                                        }
#line 1689 "parser.c" /* yacc.c:1646  */
    break;

  case 6:
#line 196 "parser.y" /* yacc.c:1646  */
    {
                                            print_rules("stmt","forstmt");
                                            (yyval.stmt_t) = new_stmt(); 
                                        }
#line 1698 "parser.c" /* yacc.c:1646  */
    break;

  case 7:
#line 200 "parser.y" /* yacc.c:1646  */
    {
                                            print_rules("stmt","returnstmt;");
                                            (yyval.stmt_t) = new_stmt();
                                            (yyval.stmt_t)->exp = (yyvsp[0].exp);
                                            if(returnCnt == 0){
                                                fprintf(stderr, "Error, return statement at line <%d>, outside of function\n", yylineno);
                                                exit_flag = 1;
                                            }
                                                
                                        }
#line 1713 "parser.c" /* yacc.c:1646  */
    break;

  case 8:
#line 210 "parser.y" /* yacc.c:1646  */
    {
                                            print_rules("stmt","break;");
                                            (yyval.stmt_t) = new_stmt();
                                            (yyval.stmt_t)->breaklist = (yyvsp[0].break_t)->breaklist;                                            
                                            if(top(loopstack) == false){
                                                fprintf(stderr, "Error, break statement at line <%d>, outside of loop\n", yylineno);
                                                exit_flag = 1;
                                            }
                                                
                                        }
#line 1728 "parser.c" /* yacc.c:1646  */
    break;

  case 9:
#line 220 "parser.y" /* yacc.c:1646  */
    {
                                            print_rules("stmt","continue;");
                                            (yyval.stmt_t) = new_stmt();
                                            (yyval.stmt_t)->contlist = (yyvsp[0].cont_t)->contlist;
                                            if(top(loopstack) == false){
                                                fprintf(stderr, "Error, continue statement at line <%d>, outside of loop\n", yylineno);
                                                exit_flag = 1;
                                            }
                                                
                                        }
#line 1743 "parser.c" /* yacc.c:1646  */
    break;

  case 10:
#line 230 "parser.y" /* yacc.c:1646  */
    {
                                            print_rules("stmt","block");
                                            (yyval.stmt_t) = new_stmt(); 
                                            (yyval.stmt_t)->breaklist = (yyvsp[0].stmt_t)->breaklist; 
                                            (yyval.stmt_t)->contlist = (yyvsp[0].stmt_t)->contlist; 
                                        }
#line 1754 "parser.c" /* yacc.c:1646  */
    break;

  case 11:
#line 236 "parser.y" /* yacc.c:1646  */
    {
                                            print_rules("stmt","funcdef;");
                                            (yyval.stmt_t) = new_stmt();
                                        }
#line 1763 "parser.c" /* yacc.c:1646  */
    break;

  case 12:
#line 240 "parser.y" /* yacc.c:1646  */
    {
                                            print_rules("stmt",";");
                                            (yyval.stmt_t) = new_stmt(); 
                                        }
#line 1772 "parser.c" /* yacc.c:1646  */
    break;

  case 13:
#line 246 "parser.y" /* yacc.c:1646  */
    {
                                print_rules("stmt","stmts stmt");
                                (yyval.stmt_t) = new_stmt();
                                (yyval.stmt_t)->breaklist = merge_list((yyval.stmt_t)->breaklist, (yyvsp[-1].stmt_t)->breaklist, (yyvsp[0].stmt_t)->breaklist);
                                (yyval.stmt_t)->contlist = merge_list((yyval.stmt_t)->contlist, (yyvsp[-1].stmt_t)->contlist, (yyvsp[0].stmt_t)->contlist);
                                /*hide_tmp_var(table, curr_scope);*/
                                resetTempVar();
                            }
#line 1785 "parser.c" /* yacc.c:1646  */
    break;

  case 14:
#line 254 "parser.y" /* yacc.c:1646  */
    {(yyval.stmt_t) = new_stmt();}
#line 1791 "parser.c" /* yacc.c:1646  */
    break;

  case 15:
#line 257 "parser.y" /* yacc.c:1646  */
    {(yyval.integer) = nextQuad();}
#line 1797 "parser.c" /* yacc.c:1646  */
    break;

  case 16:
#line 260 "parser.y" /* yacc.c:1646  */
    {
                                print_rules("expr","assignexpr");
                                (yyval.exp) = (yyvsp[0].exp);
                            }
#line 1806 "parser.c" /* yacc.c:1646  */
    break;

  case 17:
#line 264 "parser.y" /* yacc.c:1646  */
    {(yyvsp[-1].exp) = boolQuads((yyvsp[-1].exp));}
#line 1812 "parser.c" /* yacc.c:1646  */
    break;

  case 18:
#line 265 "parser.y" /* yacc.c:1646  */
    {
                                                        print_rules("expr","expr or expr");
                                                        (yyvsp[0].exp) = boolQuads((yyvsp[0].exp));

                                                        (yyval.exp) = newExpr(boolexpr_e);
                                                        backpatch((yyvsp[-4].exp)->falselist_head, (yyvsp[-1].integer));
                                                        (yyval.exp)->truelist_head = merge_list((yyval.exp)->truelist_head, (yyvsp[-4].exp)->truelist_head, (yyvsp[0].exp)->truelist_head);
                                                        (yyval.exp)->falselist_head = (yyvsp[0].exp)->falselist_head;
                                                    }
#line 1826 "parser.c" /* yacc.c:1646  */
    break;

  case 19:
#line 274 "parser.y" /* yacc.c:1646  */
    {(yyvsp[-1].exp) = boolQuads((yyvsp[-1].exp));}
#line 1832 "parser.c" /* yacc.c:1646  */
    break;

  case 20:
#line 275 "parser.y" /* yacc.c:1646  */
    {
                                                        print_rules("expr","expr and expr");
                                                        
                                                        (yyvsp[0].exp) = boolQuads((yyvsp[0].exp));

                                                        (yyval.exp) = newExpr(boolexpr_e);
                                                        backpatch((yyvsp[-4].exp)->truelist_head, (yyvsp[-1].integer));
                                                        (yyval.exp)->truelist_head = (yyvsp[0].exp)->truelist_head;
                                                        (yyval.exp)->falselist_head = merge_list((yyval.exp)->falselist_head, (yyvsp[-4].exp)->falselist_head, (yyvsp[0].exp)->falselist_head);
                                                    }
#line 1847 "parser.c" /* yacc.c:1646  */
    break;

  case 21:
#line 285 "parser.y" /* yacc.c:1646  */
    {
                                if((yyvsp[-2].exp)->type == boolexpr_e)
                                    (yyvsp[-2].exp) = bool_expr((yyvsp[-2].exp));
                            }
#line 1856 "parser.c" /* yacc.c:1646  */
    break;

  case 22:
#line 289 "parser.y" /* yacc.c:1646  */
    {
                                print_rules("expr","expr == expr");
                                if((yyvsp[0].exp)->type == boolexpr_e)
                                    (yyvsp[0].exp) = bool_expr((yyvsp[0].exp));
                 
                                (yyval.exp) = releational_ops((yyvsp[-4].exp), if_eq, (yyvsp[0].exp));  
                            }
#line 1868 "parser.c" /* yacc.c:1646  */
    break;

  case 23:
#line 296 "parser.y" /* yacc.c:1646  */
    {
                                    if((yyvsp[-2].exp)->type == boolexpr_e)
                                        (yyvsp[-2].exp) = bool_expr((yyvsp[-2].exp));
                                }
#line 1877 "parser.c" /* yacc.c:1646  */
    break;

  case 24:
#line 300 "parser.y" /* yacc.c:1646  */
    {
                                print_rules("expr","expr == expr");
                                if((yyvsp[0].exp)->type == boolexpr_e)
                                    (yyvsp[0].exp) = bool_expr((yyvsp[0].exp));
                                
                                (yyval.exp) = releational_ops((yyvsp[-4].exp), if_noteq, (yyvsp[0].exp));  
                            }
#line 1889 "parser.c" /* yacc.c:1646  */
    break;

  case 25:
#line 307 "parser.y" /* yacc.c:1646  */
    {
                                            print_rules("expr","expr > expr");
                                            (yyval.exp) = releational_ops((yyvsp[-2].exp), if_greater, (yyvsp[0].exp));  
                                        }
#line 1898 "parser.c" /* yacc.c:1646  */
    break;

  case 26:
#line 311 "parser.y" /* yacc.c:1646  */
    {
                                            print_rules("expr","expr >= expr");
                                            (yyval.exp) = releational_ops((yyvsp[-2].exp), if_greatereq, (yyvsp[0].exp)); 
                                        }
#line 1907 "parser.c" /* yacc.c:1646  */
    break;

  case 27:
#line 315 "parser.y" /* yacc.c:1646  */
    {
                                            print_rules("expr","expr < expr");
                                            (yyval.exp) = releational_ops((yyvsp[-2].exp), if_less, (yyvsp[0].exp));
                                        }
#line 1916 "parser.c" /* yacc.c:1646  */
    break;

  case 28:
#line 319 "parser.y" /* yacc.c:1646  */
    {
                                            print_rules("expr","expr <= expr");
                                            (yyval.exp) = releational_ops((yyvsp[-2].exp), if_lesseq, (yyvsp[0].exp)); 
                                        }
#line 1925 "parser.c" /* yacc.c:1646  */
    break;

  case 29:
#line 324 "parser.y" /* yacc.c:1646  */
    {   /*                  PLUS(+)                    */
                                            print_rules("expr","expr + expr");  
                                            (yyval.exp) = arithmetic_ops((yyvsp[-2].exp), add, (yyvsp[0].exp));
                                        }
#line 1934 "parser.c" /* yacc.c:1646  */
    break;

  case 30:
#line 328 "parser.y" /* yacc.c:1646  */
    {   /*                  MINUS(-)                     */
                                            print_rules("expr","expr - expr");
                                            (yyval.exp) = arithmetic_ops((yyvsp[-2].exp), sub, (yyvsp[0].exp));
                                        }
#line 1943 "parser.c" /* yacc.c:1646  */
    break;

  case 31:
#line 332 "parser.y" /* yacc.c:1646  */
    {   /*                  MULTIPLY(*)                     */
                                            print_rules("expr","expr * expr");
                                            (yyval.exp) = arithmetic_ops((yyvsp[-2].exp), mul, (yyvsp[0].exp));
                                        }
#line 1952 "parser.c" /* yacc.c:1646  */
    break;

  case 32:
#line 336 "parser.y" /* yacc.c:1646  */
    {   /*                  DIVIDE(/)                     */
                                            print_rules("expr","expr / expr");
                                            (yyval.exp) = arithmetic_ops((yyvsp[-2].exp), divide, (yyvsp[0].exp));
                                        }
#line 1961 "parser.c" /* yacc.c:1646  */
    break;

  case 33:
#line 340 "parser.y" /* yacc.c:1646  */
    {   /*                  MOD(%)                     */
                                            print_rules("expr","expr % expr");
                                            (yyval.exp) = arithmetic_ops((yyvsp[-2].exp), mod, (yyvsp[0].exp));
                                        }
#line 1970 "parser.c" /* yacc.c:1646  */
    break;

  case 34:
#line 344 "parser.y" /* yacc.c:1646  */
    {
                                            print_rules("expr","term");
                                            (yyval.exp) = (yyvsp[0].exp);
                                        }
#line 1979 "parser.c" /* yacc.c:1646  */
    break;

  case 35:
#line 350 "parser.y" /* yacc.c:1646  */
    {
                                            print_rules("term","( expr )");
                                            (yyval.exp) = (yyvsp[-1].exp);
                                        }
#line 1988 "parser.c" /* yacc.c:1646  */
    break;

  case 36:
#line 354 "parser.y" /* yacc.c:1646  */
    {
                                            print_rules("term","- expr");
                                            allowed_operations((yyvsp[0].exp), NULL);
                                            (yyval.exp) = newExpr(arithexpr_e);
                                            (yyval.exp)->sym = istempexpr((yyvsp[0].exp)) ? (yyvsp[0].exp)->sym : newTempVar();

                                            (yyval.exp)->numConst = -(yyvsp[0].exp)->numConst;
                                            emit(uminus, (yyval.exp), (yyvsp[0].exp), NULL, 0, yylineno);

                                        }
#line 2003 "parser.c" /* yacc.c:1646  */
    break;

  case 37:
#line 364 "parser.y" /* yacc.c:1646  */
    {
                                            print_rules("term","not expr");
                                            (yyvsp[0].exp) = boolQuads((yyvsp[0].exp));

                                            (yyval.exp) = newExpr(boolexpr_e);
                                            (yyval.exp)->truelist_head = (yyvsp[0].exp)->falselist_head;
                                            (yyval.exp)->falselist_head = (yyvsp[0].exp)->truelist_head;
                                        }
#line 2016 "parser.c" /* yacc.c:1646  */
    break;

  case 38:
#line 372 "parser.y" /* yacc.c:1646  */
    {

                                            if(isLocal == false && (yyvsp[0].exp)->sym->value.varVal->name != NULL){
                                                if(distinguish_lookup(table, (yyvsp[0].exp)->sym->value.varVal->name, curr_scope) != GENERAL){
                                                    fprintf(stderr, "Error, cannot change value of \"%s\" at line <%d>, functions are constant\n", (yyvsp[0].exp)->sym->value.varVal->name, yylineno);
                                                    parserFlag = 1;
                                                    exit_flag = 1;
                                                }
                                            }

                                            libreturnCnt = 0;
                                            print_rules("term","++lvalue");
                                            if(parserFlag == 0){
                                                if((yyvsp[0].exp)->type == tableitem_e){
                                                    expr* tmp_exp = emit_iftableitem((yyvsp[0].exp));
                                                    expr* num_expr = newExpr(constint_e);
                                                    num_expr->numConst = 1;
                                                    emit(add, tmp_exp, tmp_exp, num_expr, 0, yylineno);
                                                    emit(tablesetelem, (yyvsp[0].exp), (yyvsp[0].exp)->index, tmp_exp, 0, yylineno);
                                                }else{
                                                    expr* temp_expr = newExpr(constint_e);
                                                    temp_expr->numConst = 1;
                                                    (yyvsp[0].exp)->numConst += temp_expr->numConst; /* ?? */
                                                    emit(add, (yyvsp[0].exp), (yyvsp[0].exp), temp_expr, 0, yylineno);
                                                    SymbolTableEntry *temp = newTempVar();
                                                    (yyval.exp) = newExpr(var_e);
                                                    (yyval.exp)->sym = temp;
                                                    (yyval.exp)->numConst = (yyvsp[0].exp)->numConst; /* ?? */
                                                    emit(assign, (yyval.exp), (yyvsp[0].exp), NULL, 0, yylineno);
                                                }
                                            }
                                            
                                            parserFlag = 0;

                                        }
#line 2056 "parser.c" /* yacc.c:1646  */
    break;

  case 39:
#line 407 "parser.y" /* yacc.c:1646  */
    {
                                            if(isLocal == false && (yyvsp[-1].exp)->sym->value.varVal->name != NULL){
                                                if(distinguish_lookup(table, (yyvsp[-1].exp)->sym->value.varVal->name, curr_scope) != GENERAL){
                                                    fprintf(stderr, "Error, cannot change value of \"%s\" at line <%d>, functions are constant\n", (yyvsp[-1].exp)->sym->value.varVal->name, yylineno);
                                                    exit_flag = 1;
                                                    parserFlag = 1;
                                                }
                                            }
                                            libreturnCnt = 0;

                                            print_rules("term","lvalue++");

                                            if(parserFlag == 0){
                                                
                                                if((yyvsp[-1].exp)->type == tableitem_e){
                                                    SymbolTableEntry *temp = newTempVar();
                                                    (yyval.exp) = newExpr(var_e);
                                                    (yyval.exp)->sym = temp;
                                                    expr* tmp_exp = emit_iftableitem((yyvsp[-1].exp));
                                                    emit(assign, (yyval.exp), tmp_exp, NULL, 0, yylineno);
                                                    expr* num_expr = newExpr(constint_e);
                                                    num_expr->numConst = 1;
                                                    emit(add, tmp_exp, tmp_exp, num_expr, 0, yylineno);
                                                    emit(tablesetelem, (yyvsp[-1].exp), (yyvsp[-1].exp)->index, tmp_exp, 0, yylineno);
                                                }else{
                                                    SymbolTableEntry *temp = newTempVar();
                                                    (yyval.exp) = newExpr(var_e);
                                                    (yyval.exp)->sym = temp;
                                                    (yyval.exp)->numConst = (yyvsp[-1].exp)->numConst; 
                                                    emit(assign, (yyval.exp), (yyvsp[-1].exp), NULL, 0, yylineno);

                                                    expr* temp_expr = newExpr(constint_e);
                                                    temp_expr->numConst = 1;
                                                    (yyvsp[-1].exp)->numConst += temp_expr->numConst;
                                                    emit(add, (yyvsp[-1].exp), (yyvsp[-1].exp), temp_expr, 0, yylineno);
                                                }
                                            }
                                            parserFlag = 0;

                                            
                                        }
#line 2102 "parser.c" /* yacc.c:1646  */
    break;

  case 40:
#line 448 "parser.y" /* yacc.c:1646  */
    {
                                            if(isLocal == false && (yyvsp[0].exp)->sym->value.varVal->name != NULL){
                                                if(distinguish_lookup(table, (yyvsp[0].exp)->sym->value.varVal->name, curr_scope) != GENERAL){
                                                    fprintf(stderr, "Error, cannot change value of \"%s\" at line <%d>, functions are constant\n", (yyvsp[0].exp)->sym->value.varVal->name, yylineno);
                                                    exit_flag = 1;
                                                    parserFlag = 1;
                                                }
                                            }
                                            libreturnCnt = 0;
                                            print_rules("term","--lvalue");

                                            if(parserFlag == 0){
                                                if((yyvsp[0].exp)->type == tableitem_e){
                                                    expr* tmp_exp = emit_iftableitem((yyvsp[0].exp));
                                                    expr* num_expr = newExpr(constint_e);
                                                    num_expr->numConst = 1;
                                                    emit(sub, tmp_exp, tmp_exp, num_expr, 0, yylineno);
                                                    emit(tablesetelem, (yyvsp[0].exp), (yyvsp[0].exp)->index, tmp_exp, 0, yylineno);
                                                }else{
                                                    expr* temp_expr = newExpr(constint_e);
                                                    temp_expr->numConst = 1;
                                                    (yyvsp[0].exp)->numConst -= temp_expr->numConst; /* ?? */
                                                    emit(add, (yyvsp[0].exp), (yyvsp[0].exp), temp_expr, 0, yylineno);
                                                    SymbolTableEntry *temp = newTempVar();
                                                    (yyval.exp) = newExpr(var_e);
                                                    (yyval.exp)->sym = temp;
                                                    (yyval.exp)->numConst = (yyvsp[0].exp)->numConst; /* ?? */
                                                    emit(assign, (yyval.exp), (yyvsp[0].exp), NULL, 0, yylineno);
                                                }
                                            }
                                            parserFlag = 0;
                                        }
#line 2139 "parser.c" /* yacc.c:1646  */
    break;

  case 41:
#line 480 "parser.y" /* yacc.c:1646  */
    {
                                            print_rules("term","lvalue--");

                                            if(isLocal == false && (yyvsp[-1].exp)->sym->value.varVal->name != NULL){
                                                if(distinguish_lookup(table, (yyvsp[-1].exp)->sym->value.varVal->name, curr_scope) != GENERAL){
                                                    fprintf(stderr, "Error, cannot change value of \"%s\" at line <%d>, functions are constant\n", (yyvsp[-1].exp)->sym->value.varVal->name, yylineno);
                                                    exit_flag = 1;
                                                    parserFlag = 1;
                                                }
                                            }
                                            libreturnCnt = 0;
                                            

                                            if(parserFlag == 0){
                                                if((yyvsp[-1].exp)->type == tableitem_e){
                                                    SymbolTableEntry *temp = newTempVar();
                                                    (yyval.exp) = newExpr(var_e);
                                                    (yyval.exp)->sym = temp;
                                                    expr* tmp_exp = emit_iftableitem((yyvsp[-1].exp));
                                                    emit(assign, (yyval.exp), tmp_exp, NULL, 0, yylineno);
                                                    expr* num_expr = newExpr(constint_e);
                                                    num_expr->numConst = 1;
                                                    emit(sub, tmp_exp, tmp_exp, num_expr, 0, yylineno);
                                                    emit(tablesetelem, (yyvsp[-1].exp), (yyvsp[-1].exp)->index, tmp_exp, 0, yylineno);
                                                }else{
                                                    SymbolTableEntry *temp = newTempVar();
                                                    (yyval.exp) = newExpr(var_e);
                                                    (yyval.exp)->sym = temp;
                                                    (yyval.exp)->numConst = (yyvsp[-1].exp)->numConst; 
                                                    emit(assign, (yyval.exp), (yyvsp[-1].exp), NULL, 0, yylineno);

                                                    expr* temp_expr = newExpr(constint_e);
                                                    temp_expr->numConst = 1;
                                                    (yyvsp[-1].exp)->numConst += temp_expr->numConst;
                                                    emit(sub, (yyvsp[-1].exp), (yyvsp[-1].exp), temp_expr, 0, yylineno);
                                                }
                                            }
                                            parserFlag = 0;
                                        }
#line 2183 "parser.c" /* yacc.c:1646  */
    break;

  case 42:
#line 519 "parser.y" /* yacc.c:1646  */
    {(yyval.exp) = (yyvsp[0].exp);print_rules("term","primary");}
#line 2189 "parser.c" /* yacc.c:1646  */
    break;

  case 43:
#line 523 "parser.y" /* yacc.c:1646  */
    {
                            if(isLocal == false && (yyvsp[-1].exp)->sym->value.varVal->name != NULL){
                                if(distinguish_lookup(table, (yyvsp[-1].exp)->sym->value.varVal->name, curr_scope) != GENERAL){
                                    fprintf(stderr, "Error, cannot change value of \"%s\" at line <%d>, functions are constant\n", (yyvsp[-1].exp)->sym->value.varVal->name, yylineno);
                                    exit_flag = 1;
                                    parserFlag = 1;
                                }
                            }
                            
                            libreturnCnt = 0;
                        }
#line 2205 "parser.c" /* yacc.c:1646  */
    break;

  case 44:
#line 534 "parser.y" /* yacc.c:1646  */
    {
                            print_rules("assignexpr","lvalue = expr");
                            if((yyvsp[0].exp)->type == boolexpr_e)
                                (yyvsp[0].exp) = bool_expr((yyvsp[0].exp));
                            if(parserFlag == 0){
                                if((yyvsp[-3].exp)->type == tableitem_e){
                                    emit(tablesetelem, (yyvsp[-3].exp), (yyvsp[-3].exp)->index, (yyvsp[0].exp), 0, yylineno);
                                    (yyval.exp) = newExpr(tableitem_e);
                                    (yyval.exp)->sym = newTempVar();
                                    emit(tablegetelem, (yyval.exp), (yyvsp[-3].exp), (yyvsp[-3].exp)->index, 0, yylineno); 

                                }else {
                                    (yyvsp[-3].exp)->numConst = (yyvsp[0].exp)->numConst;
                                    (yyvsp[-3].exp)->strConst = (yyvsp[0].exp)->strConst;
                                    (yyvsp[-3].exp)->boolConst = (yyvsp[0].exp)->boolConst;
                                    emit(assign, (yyvsp[-3].exp), (yyvsp[0].exp), NULL, 0, yylineno);

                                    SymbolTableEntry *temp = newTempVar();
                                    (yyval.exp) = newExpr(var_e);
                                    (yyval.exp)->sym = temp;
                                    (yyval.exp)->numConst = (yyvsp[-3].exp)->numConst;
                                    (yyval.exp)->strConst = (yyvsp[-3].exp)->strConst;
                                    (yyval.exp)->boolConst = (yyvsp[-3].exp)->boolConst;
                                    emit(assign, (yyval.exp), (yyvsp[-3].exp), NULL, 0, yylineno);
                                    /*printf("%s = %f\n", $$->sym->value.varVal->name, $$->numConst);*/ /* print_tag */
                                }
                            }
                            parserFlag = 0;

                            
                        }
#line 2241 "parser.c" /* yacc.c:1646  */
    break;

  case 45:
#line 567 "parser.y" /* yacc.c:1646  */
    {
                                                    print_rules("primary","lvalue");
                                                    (yyval.exp) = emit_iftableitem((yyvsp[0].exp));
                                                }
#line 2250 "parser.c" /* yacc.c:1646  */
    break;

  case 46:
#line 571 "parser.y" /* yacc.c:1646  */
    {
                                                    (yyval.exp) = (yyvsp[0].exp);
                                                    print_rules("primary","call");
                                                }
#line 2259 "parser.c" /* yacc.c:1646  */
    break;

  case 47:
#line 575 "parser.y" /* yacc.c:1646  */
    {
                                                    print_rules("primary","objectdef");
                                                }
#line 2267 "parser.c" /* yacc.c:1646  */
    break;

  case 48:
#line 578 "parser.y" /* yacc.c:1646  */
    {   
                                                    (yyval.exp) = (yyvsp[-1].exp);
                                                    print_rules("primary","( funcdef )");
                                                    restoretmpvarOffset(curr_scope);
                                                }
#line 2277 "parser.c" /* yacc.c:1646  */
    break;

  case 49:
#line 583 "parser.y" /* yacc.c:1646  */
    {
                                                    (yyval.exp) = (yyvsp[0].exp);
                                                    print_rules("primary","const");
                                                }
#line 2286 "parser.c" /* yacc.c:1646  */
    break;

  case 50:
#line 589 "parser.y" /* yacc.c:1646  */
    {
                                    isLocal = false;
                                    if(distinguish_lookup(table, yytext, curr_scope) == GENERAL){
                                        /*fprintf(stderr, "variable ID: %s\n", yytext);*/
                                        (yyval.exp) = newExpr(var_e);
                                        (yyval.exp)->sym = variable_lookup(table, create_variable(yytext, curr_scope, yylineno), GENERAL, curr_scope);

                                    }
                                    else{
                                        /*fprintf(stderr, "func call ID: %s\n", yytext);*/
                                        SymbolTableEntry *temp = function_lookup(table, create_function(yytext, curr_scope, yylineno), GLOBAL, curr_scope, true);
                                        if(temp != NULL){
                                            (yyval.exp) = newExpr(var_e);
                                            (yyval.exp)->sym = temp;
                                        }
                                        else{
                                            SymbolTableEntry *temp = libfunc_lookup(table, yytext);
                                            (yyval.exp) = newExpr(var_e);
                                            (yyval.exp)->sym = temp;
                                            libreturnCnt = 1;
                                        }
                                    }
                                    print_rules("lvalue","ID");
                                }
#line 2315 "parser.c" /* yacc.c:1646  */
    break;

  case 51:
#line 614 "parser.y" /* yacc.c:1646  */
    {
                                    isLocal = true;
                                    /*fprintf(stderr, "local ID: %s\n", yytext);*/
                                    (yyval.exp) = newExpr(var_e);
                                    (yyval.exp)->sym = variable_lookup(table, create_variable(yytext, curr_scope, yylineno), LOCAL_t, curr_scope);
                                    print_rules("lvalue","local ID");
                                }
#line 2327 "parser.c" /* yacc.c:1646  */
    break;

  case 52:
#line 622 "parser.y" /* yacc.c:1646  */
    {
                                    isLocal = false;
                                    if(distinguish_lookup(table, yytext, curr_scope) == GENERAL){
                                        /*fprintf(stderr, "global ID: %s\n", yytext);*/
                                        SymbolTableEntry *temp = variable_lookup(table, create_variable(yytext, curr_scope, yylineno), GLOBAL, curr_scope);
                                        (yyval.exp) = exprLookup(temp);
                                        if((yyval.exp) == NULL){
                                            exit(0);
                                        }

                                    }
                                    else{
                                        /*fprintf(stderr, "func call ID: %s\n", yytext);*/
                                        SymbolTableEntry *temp = function_lookup(table, create_function(yytext, curr_scope, yylineno), GLOBAL, curr_scope, true);
                                        if(temp != NULL){
                                            (yyval.exp) = newExpr(var_e);
                                            (yyval.exp)->sym = temp;
                                        }
                                        else{
                                            (yyval.exp) = newExpr(var_e);
                                            (yyval.exp)->sym = libfunc_lookup(table, yytext);
                                            libreturnCnt = 1;
                                        }

                                    }
                                    print_rules("lvalue","::ID");
                                }
#line 2359 "parser.c" /* yacc.c:1646  */
    break;

  case 53:
#line 650 "parser.y" /* yacc.c:1646  */
    {
                                    print_rules("lvalue","member");
                                    (yyval.exp) = (yyvsp[0].exp);                                    
                                }
#line 2368 "parser.c" /* yacc.c:1646  */
    break;

  case 54:
#line 656 "parser.y" /* yacc.c:1646  */
    {
                                    print_rules("member",".ID");
                                    (yyval.exp) = member_item((yyvsp[-2].exp), (yyvsp[0].str));

                                }
#line 2378 "parser.c" /* yacc.c:1646  */
    break;

  case 55:
#line 661 "parser.y" /* yacc.c:1646  */
    {
                                                                print_rules("member","lvalue [ expr ]");
                                                                (yyvsp[-3].exp) = emit_iftableitem((yyvsp[-3].exp));
                                                                (yyval.exp) = newExpr(tableitem_e);
                                                                (yyval.exp)->sym = (yyvsp[-3].exp)->sym;
                                                                (yyval.exp)->index = (expr*) malloc(sizeof(expr));
                                                                (yyval.exp)->index = (yyvsp[-1].exp);
                                                            }
#line 2391 "parser.c" /* yacc.c:1646  */
    break;

  case 56:
#line 669 "parser.y" /* yacc.c:1646  */
    {
                                print_rules("member","call.ID");
                                (yyval.exp) = member_item((yyvsp[-2].exp), (yyvsp[0].str));
                            }
#line 2400 "parser.c" /* yacc.c:1646  */
    break;

  case 57:
#line 673 "parser.y" /* yacc.c:1646  */
    {
                                                                print_rules("member","call[ expr ]");
                                                                (yyvsp[-3].exp) = emit_iftableitem((yyvsp[-3].exp));
                                                                (yyval.exp) = newExpr(tableitem_e);
                                                                (yyval.exp)->sym = (yyvsp[-3].exp)->sym;
                                                                (yyval.exp)->index = (expr*) malloc(sizeof(expr));
                                                                (yyval.exp)->index = (yyvsp[-1].exp);
                                                            }
#line 2413 "parser.c" /* yacc.c:1646  */
    break;

  case 58:
#line 683 "parser.y" /* yacc.c:1646  */
    {
                                                    print_rules("call","call ( elist )");
                                                    if((yyvsp[-3].exp)->sym->isVariable == true){
                                                        (yyval.exp) = make_call((yyvsp[-3].exp), (yyvsp[-1].arg)->arguments, (yyvsp[-1].arg)->nargs);
                                                    }
                                                    else{
                                                        if((yyvsp[-1].arg)->nargs >= (yyvsp[-3].exp)->sym->value.funcVal->totalArgs){
                                                            (yyval.exp) = make_call((yyvsp[-3].exp), (yyvsp[-1].arg)->arguments, (yyvsp[-1].arg)->nargs);
                                                        }
                                                        else{
                                                            fprintf(stderr, "Error, too few arguments to function \"%s\", at line <%d>\n", (yyvsp[-3].exp)->sym->value.funcVal->name, yylineno);
                                                            exit_flag = 1;
                                                        }
                                                    }

                                                }
#line 2434 "parser.c" /* yacc.c:1646  */
    break;

  case 59:
#line 699 "parser.y" /* yacc.c:1646  */
    {
                                        print_rules("call","lvalue callsuffix");
                                        if((yyvsp[0].call_type)->isMethod == true){
                                            expr* self = (yyvsp[-1].exp);
                                            (yyvsp[-1].exp) = emit_iftableitem(member_item(self, (yyvsp[0].call_type)->name));
                                            int i;
                                            for(i = (yyvsp[0].call_type)->nargs; i >= 0; i--)
                                                (yyvsp[0].call_type)->arguments[i+1] = (yyvsp[0].call_type)->arguments[i]; 
                                            
                                            (yyvsp[0].call_type)->arguments[0] = self;
                                            (yyvsp[0].call_type)->nargs++;
                                        }
                                        if((yyvsp[-1].exp)->sym->isVariable == true){
                                            (yyval.exp) = make_call((yyvsp[-1].exp), (yyvsp[0].call_type)->arguments, (yyvsp[0].call_type)->nargs);
                                        }
                                        else{
                                            if((yyvsp[0].call_type)->nargs >= (yyvsp[-1].exp)->sym->value.funcVal->totalArgs){
                                                (yyval.exp) = make_call((yyvsp[-1].exp), (yyvsp[0].call_type)->arguments, (yyvsp[0].call_type)->nargs);
                                            } else {
                                                printf("%s : %d\n", (yyvsp[-1].exp)->sym->value.funcVal->name, (yyvsp[-1].exp)->sym->value.funcVal->totalArgs);
                                                fprintf(stderr, "Error, too few arguments to function \"%s\", at line <%d>\n", (yyvsp[-1].exp)->sym->value.funcVal->name, yylineno);
                                                exit_flag = 1;
                                            }
                                        }

                                    }
#line 2465 "parser.c" /* yacc.c:1646  */
    break;

  case 60:
#line 725 "parser.y" /* yacc.c:1646  */
    {restoretmpvarOffset(curr_scope);}
#line 2471 "parser.c" /* yacc.c:1646  */
    break;

  case 61:
#line 725 "parser.y" /* yacc.c:1646  */
    {   
                                                                            print_rules("call","( funcdef ) ( elist )");
                                                                            
                                                                            if((yyvsp[-1].arg)->nargs >= (yyvsp[-5].exp)->sym->value.funcVal->totalArgs){
                                                                                expr* func = newExpr(programmfunc_e);
                                                                                func->sym = (yyvsp[-5].exp)->sym;
                                                                                (yyval.exp) = make_call(func, (yyvsp[-1].arg)->arguments, (yyvsp[-1].arg)->nargs);
                                                                            }
                                                                            else{
                                                                                fprintf(stderr, "Error, too few arguments to function \"%s\", at line <%d>\n", (yyvsp[-5].exp)->sym->value.funcVal->name, yylineno);
                                                                                exit_flag = 1;
                                                                            }
                                                                        }
#line 2489 "parser.c" /* yacc.c:1646  */
    break;

  case 62:
#line 740 "parser.y" /* yacc.c:1646  */
    {(yyval.call_type) = (yyvsp[0].call_type); print_rules("callsuffix","normalcall");}
#line 2495 "parser.c" /* yacc.c:1646  */
    break;

  case 63:
#line 741 "parser.y" /* yacc.c:1646  */
    {(yyval.call_type) = (yyvsp[0].call_type); print_rules("callsuffix","methodcall");}
#line 2501 "parser.c" /* yacc.c:1646  */
    break;

  case 64:
#line 744 "parser.y" /* yacc.c:1646  */
    {
                                                print_rules("normalcall","( elist )");
                                                (yyval.call_type) = (call_t*)malloc(sizeof(call_t));
                                                (yyval.call_type)->nargs = 0;
                                                int i;
                                                for(i = 0; i < 100; i++){
                                                    (yyval.call_type)->arguments[i] = (yyvsp[-1].arg)->arguments[i];
                                                }
                                                (yyval.call_type)->nargs = (yyvsp[-1].arg)->nargs;
                                                (yyval.call_type)->isMethod = false;                                           
                                                (yyval.call_type)->name = NULL;
                                            }
#line 2518 "parser.c" /* yacc.c:1646  */
    break;

  case 65:
#line 758 "parser.y" /* yacc.c:1646  */
    {
                                                            print_rules("methodcall","..ID ( elist )");
                                                            (yyval.call_type) = (call_t*)malloc(sizeof(call_t));
                                                            int i;
                                                            for(i = 0; i < 100; i++){
                                                                (yyval.call_type)->arguments[i] = (yyvsp[-1].arg)->arguments[i];
                                                            }
                                                            (yyval.call_type)->nargs = (yyvsp[-1].arg)->nargs;
                                                            (yyval.call_type)->isMethod = true;
                                                            (yyval.call_type)->name = strdup((yyvsp[-3].str));
                                                        }
#line 2534 "parser.c" /* yacc.c:1646  */
    break;

  case 66:
#line 771 "parser.y" /* yacc.c:1646  */
    {
                                print_rules("elist","expr");

                                if((yyvsp[0].exp)->type == boolexpr_e)
                                    (yyvsp[0].exp) = bool_expr((yyvsp[0].exp));
                                (yyval.arg) = (arguments_t*)malloc(sizeof(arguments_t));
                                (yyval.arg)->nargs = 0;
                                (yyval.arg)->arguments[(yyval.arg)->nargs++] = (yyvsp[0].exp);
                            }
#line 2548 "parser.c" /* yacc.c:1646  */
    break;

  case 67:
#line 780 "parser.y" /* yacc.c:1646  */
    {
                                        print_rules("elist",", expr");
                                        if((yyvsp[0].exp)->type == boolexpr_e)
                                            (yyvsp[0].exp) = bool_expr((yyvsp[0].exp));
                                        (yyvsp[-2].arg)->arguments[(yyvsp[-2].arg)->nargs++] = (yyvsp[0].exp);
                                    }
#line 2559 "parser.c" /* yacc.c:1646  */
    break;

  case 68:
#line 786 "parser.y" /* yacc.c:1646  */
    {
                                (yyval.arg) = (arguments_t*)malloc(sizeof(arguments_t));
                                (yyval.arg)->nargs = 0;
                                print_rules("elist"," ");
                            }
#line 2569 "parser.c" /* yacc.c:1646  */
    break;

  case 69:
#line 795 "parser.y" /* yacc.c:1646  */
    {
                                                                print_rules("objectdef","[ elist ]");
                                                                expr *t = newExpr(newtable_e);
                                                                t->sym = newTempVar();
                                                                emit(tablecreate, t, NULL, NULL, 0, yylineno);
                                                                int i;
                                                                for(i = 0; i < (yyvsp[-1].arg)->nargs; i++){
                                                                    expr *num_tmp = (expr*)malloc(sizeof(expr));
                                                                    num_tmp->numConst = i;
                                                                    num_tmp->type = constint_e;
                                                                    emit(tablesetelem, t, num_tmp, (yyvsp[-1].arg)->arguments[i], 0, yylineno);
                                                                }
                                                                (yyval.exp) = t;
                                                            }
#line 2588 "parser.c" /* yacc.c:1646  */
    break;

  case 70:
#line 809 "parser.y" /* yacc.c:1646  */
    {
                                                                print_rules("objectdef","[ indexed ]");
                                                                expr *t = newExpr(newtable_e);
                                                                t->sym = newTempVar();
                                                                emit(tablecreate, t, NULL, NULL, 0, yylineno);
                                                                int i;
                                                                for(i = 0; i < (yyvsp[-1].elems)->no_of_elems; i++){
                                                                    emit(tablesetelem, t, (yyvsp[-1].elems)->elems[i]->index, (yyvsp[-1].elems)->elems[i]->element, 0, yylineno);
                                                                }
                                                                (yyval.exp) = t;
                                                            }
#line 2604 "parser.c" /* yacc.c:1646  */
    break;

  case 71:
#line 822 "parser.y" /* yacc.c:1646  */
    {
                                                if((yyvsp[0].exp)->type == boolexpr_e)
                                                    (yyvsp[0].exp) = bool_expr((yyvsp[0].exp));
                                            }
#line 2613 "parser.c" /* yacc.c:1646  */
    break;

  case 72:
#line 826 "parser.y" /* yacc.c:1646  */
    {
                                                print_rules("indexedelem","{ expr; expr }");
                                                if((yyvsp[-1].exp)->type == boolexpr_e)
                                                    (yyvsp[-1].exp) = bool_expr((yyvsp[-1].exp));

                                                (yyval.ind_elem) = (indexed_elem*)malloc(sizeof(indexed_elem));
                                                (yyval.ind_elem)->index = (yyvsp[-4].exp);
                                                (yyval.ind_elem)->element = (yyvsp[-1].exp);
                                                /*
                                                table_elem_index[table_elem_offset] = $2;
                                                table_elems[table_elem_offset++] = $5;
                                                */
                                            }
#line 2631 "parser.c" /* yacc.c:1646  */
    break;

  case 73:
#line 841 "parser.y" /* yacc.c:1646  */
    {
                                                (yyval.elems) = (elements*)malloc(sizeof(elements));
                                                (yyval.elems)->no_of_elems = 0;
                                                (yyval.elems)->elems[(yyval.elems)->no_of_elems++] = (yyvsp[0].ind_elem);
                                            }
#line 2641 "parser.c" /* yacc.c:1646  */
    break;

  case 74:
#line 846 "parser.y" /* yacc.c:1646  */
    {
                                                (yyvsp[-2].elems)->elems[(yyvsp[-2].elems)->no_of_elems++] = (yyvsp[0].ind_elem);
                                            }
#line 2649 "parser.c" /* yacc.c:1646  */
    break;

  case 75:
#line 851 "parser.y" /* yacc.c:1646  */
    {savetmpvarOffset(curr_scope); curr_scope++; }
#line 2655 "parser.c" /* yacc.c:1646  */
    break;

  case 76:
#line 853 "parser.y" /* yacc.c:1646  */
    {
                                    print_rules("block","{ stmts }");

                                    (yyval.stmt_t) = new_stmt();

                                    if((yyvsp[-1].stmt_t)->breaklist != NULL)
                                        (yyval.stmt_t)->breaklist = merge_list((yyval.stmt_t)->breaklist, (yyvsp[-1].stmt_t)->breaklist, NULL);

                                    if((yyvsp[-1].stmt_t)->contlist != NULL)
                                        (yyval.stmt_t)->contlist = merge_list((yyval.stmt_t)->contlist, (yyvsp[-1].stmt_t)->contlist, NULL);
                                        
                                    hide(table, curr_scope);
                                    curr_scope--;
                                    
                                }
#line 2675 "parser.c" /* yacc.c:1646  */
    break;

  case 77:
#line 870 "parser.y" /* yacc.c:1646  */
    {
                                                    exitscopespace();
                                                    (yyvsp[-2].symbol)->value.funcVal->totalLocals = functionLocalOffset;
                                                    functionLocalOffset = func_pop(functionLocalsStack);
                                                    (yyvsp[-2].symbol)->value.funcVal->totalArgs = formalArgOffset;
                                                    (yyval.exp) = newExpr(programmfunc_e);
                                                    (yyval.exp)->sym = (yyvsp[-2].symbol);
                                                    emit(funcend, (yyval.exp), NULL, NULL, 0, yylineno);

                                                    if(retjumpQuad[functionOffset+1] != NULL)
                                                        retjumpQuad[functionOffset+1]->label = (yyvsp[0].integer);

                                                    funcjumpQuad[functionOffset+1]->label = (yyvsp[0].integer) + 1;

                                                    funcjumpsReset(functionOffset+1);
                                                    pop(loopstack);
                                                }
#line 2697 "parser.c" /* yacc.c:1646  */
    break;

  case 78:
#line 889 "parser.y" /* yacc.c:1646  */
    {
                                        push(loopstack);
                                        functionOffset++;
                                        funcjumpQuad[functionOffset] = emit(jump, NULL, NULL, NULL, 0, yylineno);
                                        if((yyvsp[0].str) != NULL){
                                            (yyval.symbol) = function_lookup(table, create_function((yyvsp[0].str), curr_scope, yylineno), USERFUNC, curr_scope, false);
                                            if((yyval.symbol) == NULL){
                                                exit(0);
                                            }
                                        }
                                        else{
                                            (yyval.symbol) = newTempFuncVar();
                                        }
                                        (yyval.symbol)->value.funcVal->funcAddress = nextQuad();    
                                        expr *func_expr = newExpr(programmfunc_e);
                                        func_expr->sym = (yyval.symbol);
                                        emit(funcstart, func_expr, NULL, NULL, 0, yylineno);
                                        func_push(functionLocalsStack, functionLocalOffset);
                                        enterscopespace();
                                        resetformalargsOffset();
                                        returnCnt++;
                                    }
#line 2724 "parser.c" /* yacc.c:1646  */
    break;

  case 79:
#line 913 "parser.y" /* yacc.c:1646  */
    { curr_scope++; }
#line 2730 "parser.c" /* yacc.c:1646  */
    break;

  case 80:
#line 915 "parser.y" /* yacc.c:1646  */
    {
                                curr_scope--;
                                enterscopespace();
                                resetfunctionlocalsOffset();
                            }
#line 2740 "parser.c" /* yacc.c:1646  */
    break;

  case 81:
#line 922 "parser.y" /* yacc.c:1646  */
    {
                            (yyval.integer) = nextQuad();
                            exitscopespace();
                            returnCnt--;
                            functionOffset--;
                        }
#line 2751 "parser.c" /* yacc.c:1646  */
    break;

  case 82:
#line 930 "parser.y" /* yacc.c:1646  */
    {(yyval.str) = (yyvsp[0].str);}
#line 2757 "parser.c" /* yacc.c:1646  */
    break;

  case 83:
#line 931 "parser.y" /* yacc.c:1646  */
    {(yyval.str) = NULL;}
#line 2763 "parser.c" /* yacc.c:1646  */
    break;

  case 84:
#line 934 "parser.y" /* yacc.c:1646  */
    {
                                        print_rules("idlist","ID");
                                        formal_lookup(table, create_variable((yyvsp[0].str), curr_scope, yylineno), FORMAL, curr_scope);
                                    }
#line 2772 "parser.c" /* yacc.c:1646  */
    break;

  case 85:
#line 938 "parser.y" /* yacc.c:1646  */
    {
                                        print_rules("idlist","idlist COMMA ID");
                                        formal_lookup(table, create_variable((yyvsp[0].str), curr_scope, yylineno), FORMAL, curr_scope);
                                    }
#line 2781 "parser.c" /* yacc.c:1646  */
    break;

  case 86:
#line 942 "parser.y" /* yacc.c:1646  */
    {print_rules("idlist"," ");}
#line 2787 "parser.c" /* yacc.c:1646  */
    break;

  case 87:
#line 947 "parser.y" /* yacc.c:1646  */
    {
                                print_rules("const","REAL_CONST");
                                (yyval.exp) = newExpr(constdouble_e);
                                (yyval.exp)->numConst = (yyvsp[0].num);
                            }
#line 2797 "parser.c" /* yacc.c:1646  */
    break;

  case 88:
#line 952 "parser.y" /* yacc.c:1646  */
    {
                                print_rules("const","INT_CONST");
                                (yyval.exp) = newExpr(constint_e);
                                (yyval.exp)->numConst = (yyvsp[0].num);
                            }
#line 2807 "parser.c" /* yacc.c:1646  */
    break;

  case 89:
#line 957 "parser.y" /* yacc.c:1646  */
    {
                                print_rules("const","STRING");
                                (yyval.exp) = newExpr(conststring_e);
                                (yyval.exp)->strConst = (yyvsp[0].str);
                            }
#line 2817 "parser.c" /* yacc.c:1646  */
    break;

  case 90:
#line 962 "parser.y" /* yacc.c:1646  */
    {
                                print_rules("const","NIL");
                                (yyval.exp) = newExpr(nil_e);
                            }
#line 2826 "parser.c" /* yacc.c:1646  */
    break;

  case 91:
#line 966 "parser.y" /* yacc.c:1646  */
    {
                                print_rules("const","TRUE");
                                (yyval.exp) = newExpr(constbool_e);
                                (yyval.exp)->boolConst = (yyvsp[0].character);
                            }
#line 2836 "parser.c" /* yacc.c:1646  */
    break;

  case 92:
#line 971 "parser.y" /* yacc.c:1646  */
    {
                                print_rules("const","FALSE");
                                (yyval.exp) = newExpr(constbool_e);
                                (yyval.exp)->boolConst = (yyvsp[0].character);
                            }
#line 2846 "parser.c" /* yacc.c:1646  */
    break;

  case 93:
#line 979 "parser.y" /* yacc.c:1646  */
    {
                                                if((yyvsp[-1].exp)->type == boolexpr_e)
                                                    (yyvsp[-1].exp) = bool_expr((yyvsp[-1].exp));

                                                expr* true_expr = newExpr(constbool_e);
                                                true_expr->boolConst = 't';
                                                
                                                emit(if_eq, NULL, (yyvsp[-1].exp), true_expr, nextQuad()+2 , yylineno);
                                                (yyval.integer) = nextQuad();
                                                emit(jump, NULL, NULL, NULL, -1, yylineno);
                                            }
#line 2862 "parser.c" /* yacc.c:1646  */
    break;

  case 94:
#line 991 "parser.y" /* yacc.c:1646  */
    {
                                    patchlabel((yyvsp[-1].integer), nextQuad());
                                    resetTempVar();
                                }
#line 2871 "parser.c" /* yacc.c:1646  */
    break;

  case 95:
#line 995 "parser.y" /* yacc.c:1646  */
    {
                                    if((yyvsp[0].stmt_t)->else_quad != -2){
                                        patchlabel((yyvsp[-3].integer), (yyvsp[0].stmt_t)->else_quad + 1);
                                        patchlabel((yyvsp[0].stmt_t)->else_quad, nextQuad()); 
                                    }
                                    (yyval.stmt_t) = new_stmt();
                                    (yyval.stmt_t)->breaklist = merge_list((yyval.stmt_t)->breaklist, (yyvsp[-2].stmt_t)->breaklist, (yyvsp[0].stmt_t)->breaklist);
                                    (yyval.stmt_t)->contlist = merge_list((yyval.stmt_t)->contlist, (yyvsp[-2].stmt_t)->contlist, (yyvsp[0].stmt_t)->contlist);
                                }
#line 2885 "parser.c" /* yacc.c:1646  */
    break;

  case 96:
#line 1005 "parser.y" /* yacc.c:1646  */
    {
                                    resetTempVar();
                                    (yyval.stmt_t) = new_stmt();
                                    (yyval.stmt_t)->else_quad = (yyvsp[-1].integer);
                                    (yyval.stmt_t)->breaklist = (yyvsp[0].stmt_t)->breaklist;
                                    (yyval.stmt_t)->contlist = (yyvsp[0].stmt_t)->contlist;
                                }
#line 2897 "parser.c" /* yacc.c:1646  */
    break;

  case 97:
#line 1012 "parser.y" /* yacc.c:1646  */
    {
                                    (yyval.stmt_t) = new_stmt();
                                    (yyval.stmt_t)->else_quad = -2;
                                }
#line 2906 "parser.c" /* yacc.c:1646  */
    break;

  case 98:
#line 1018 "parser.y" /* yacc.c:1646  */
    {
                            (yyval.integer) = nextQuad();
                            emit(jump, NULL, NULL, NULL, -1, yylineno);
                        }
#line 2915 "parser.c" /* yacc.c:1646  */
    break;

  case 99:
#line 1024 "parser.y" /* yacc.c:1646  */
    {
                                    (yyval.break_t) = (struct break_s*)malloc(sizeof(struct break_s));
                                    (yyval.break_t)->breaklist = insert_list((yyval.break_t)->breaklist, nextQuad());
                                    emit(jump, NULL, NULL, NULL, -1, yylineno);
                                }
#line 2925 "parser.c" /* yacc.c:1646  */
    break;

  case 100:
#line 1031 "parser.y" /* yacc.c:1646  */
    {
                                        (yyval.cont_t) = (struct cont_s*)malloc(sizeof(struct cont_s));
                                        (yyval.cont_t)->contlist = insert_list((yyval.cont_t)->contlist, nextQuad());
                                        emit(jump, NULL, NULL, NULL, -1, yylineno);
                                    }
#line 2935 "parser.c" /* yacc.c:1646  */
    break;

  case 101:
#line 1038 "parser.y" /* yacc.c:1646  */
    {}
#line 2941 "parser.c" /* yacc.c:1646  */
    break;

  case 102:
#line 1041 "parser.y" /* yacc.c:1646  */
    {}
#line 2947 "parser.c" /* yacc.c:1646  */
    break;

  case 103:
#line 1044 "parser.y" /* yacc.c:1646  */
    {(yyval.stmt_t) = (yyvsp[-1].stmt_t);}
#line 2953 "parser.c" /* yacc.c:1646  */
    break;

  case 104:
#line 1047 "parser.y" /* yacc.c:1646  */
    {
                            loopcounter++;
                            (yyval.integer) = nextQuad();
                            if(loopcounter > 1)
                                push(loopstack);
                            modify_tail(loopstack, true);
                        }
#line 2965 "parser.c" /* yacc.c:1646  */
    break;

  case 105:
#line 1056 "parser.y" /* yacc.c:1646  */
    {
                                            if((yyvsp[-1].exp)->type == boolexpr_e)
                                                (yyvsp[-1].exp) = bool_expr((yyvsp[-1].exp));

                                            expr* true_expr = newExpr(constbool_e);
                                            true_expr->boolConst = 't';
                                            emit(if_eq, NULL, (yyvsp[-1].exp), true_expr, nextQuad()+2, yylineno);
                                            (yyval.integer) = nextQuad();
                                            whileQuad = emit(jump, NULL, NULL, NULL, -1, yylineno);
                                        }
#line 2980 "parser.c" /* yacc.c:1646  */
    break;

  case 106:
#line 1068 "parser.y" /* yacc.c:1646  */
    {
                                                    print_rules("whilestmt","while(expr) stmt");
                                                    emit(jump, NULL, NULL, NULL, (yyvsp[-2].integer), yylineno);
                                                    patchlabel((yyvsp[-1].integer), nextQuad());

                                                    struct list_s* tmp;
                                                    tmp = (yyvsp[0].stmt_t)->breaklist;
                                                    while(tmp != NULL){
                                                        patchlabel(tmp->quadNo, nextQuad());
                                                        tmp = tmp->next;
                                                    }
                                                    tmp = (yyvsp[0].stmt_t)->contlist;
                                                    while(tmp != NULL){
                                                        patchlabel(tmp->quadNo, (yyvsp[-2].integer));
                                                        tmp = tmp->next;
                                                    }
                                                    modify_tail(loopstack, false);
                                                    if(loopcounter > 1)
                                                        pop(loopstack);
                                                    loopcounter--;
                                                }
#line 3006 "parser.c" /* yacc.c:1646  */
    break;

  case 107:
#line 1091 "parser.y" /* yacc.c:1646  */
    {(yyval.integer) = nextQuad(); emit(jump, NULL, NULL, NULL, -1, yylineno);}
#line 3012 "parser.c" /* yacc.c:1646  */
    break;

  case 108:
#line 1094 "parser.y" /* yacc.c:1646  */
    {(yyval.integer) = nextQuad();}
#line 3018 "parser.c" /* yacc.c:1646  */
    break;

  case 109:
#line 1097 "parser.y" /* yacc.c:1646  */
    {
                                                                    loopcounter++;
                                                                    if(loopcounter > 1)
                                                                        push(loopstack);
                                                                    modify_tail(loopstack, true);
                                                                    if((yyvsp[-1].exp)->type == boolexpr_e)
                                                                        (yyvsp[-1].exp) = bool_expr((yyvsp[-1].exp));

                                                                    (yyval.forpr_t) = (struct forpr_s*)malloc(sizeof(struct forpr_s));
                                                                    expr* true_expr = newExpr(constbool_e);
                                                                    true_expr->boolConst = 't';
                                                                    (yyval.forpr_t)->test = (yyvsp[-2].integer);
                                                                    (yyval.forpr_t)->enter = nextQuad();
                                                                    emit(if_eq, NULL, (yyvsp[-1].exp), true_expr, -1, yylineno);
                                                                }
#line 3038 "parser.c" /* yacc.c:1646  */
    break;

  case 110:
#line 1112 "parser.y" /* yacc.c:1646  */
    {
                                                                    print_rules("forstmt","for(elist; expr; elist) stmt");
                                                                    patchlabel((yyvsp[-6].forpr_t)->enter, (yyvsp[-2].integer)+1);
                                                                    patchlabel((yyvsp[-5].integer), nextQuad());
                                                                    patchlabel((yyvsp[-2].integer), (yyvsp[-6].forpr_t)->test);
                                                                    patchlabel((yyvsp[0].integer), (yyvsp[-5].integer)+1);

                                                                    struct list_s* tmp;
                                                                    tmp = (yyvsp[-1].stmt_t)->breaklist;
                                                                    while(tmp != NULL){
                                                                        patchlabel(tmp->quadNo, nextQuad());
                                                                        tmp = tmp->next;
                                                                    }
                                                                    tmp = (yyvsp[-1].stmt_t)->contlist;
                                                                    while(tmp != NULL){
                                                                        patchlabel(tmp->quadNo, (yyvsp[-5].integer)+1);
                                                                        tmp = tmp->next;
                                                                    }
                                                                    modify_tail(loopstack, false);
                                                                    if(loopcounter > 1)
                                                                        pop(loopstack);
                                                                    loopcounter--;
                                                                }
#line 3066 "parser.c" /* yacc.c:1646  */
    break;

  case 111:
#line 1137 "parser.y" /* yacc.c:1646  */
    {
                                            print_rules("returnstmt","return expr;");
                                            if((yyvsp[-1].exp)->type == boolexpr_e)
                                                (yyvsp[-1].exp) = bool_expr((yyvsp[-1].exp));
                                            
                                            if(returnCnt != 0){
                                                (yyval.exp) = (yyvsp[-1].exp);
                                                emit(ret, (yyvsp[-1].exp), NULL, NULL, 0, yylineno);
                                                retjumpQuad[functionOffset] = emit(jump, NULL, NULL, NULL, 0, yylineno);
                                            }
                                        }
#line 3082 "parser.c" /* yacc.c:1646  */
    break;

  case 112:
#line 1148 "parser.y" /* yacc.c:1646  */
    {
                                        print_rules("returnstmt","return;");
                                        if(returnCnt != 0){
                                            emit(ret, NULL, NULL, NULL, 0, yylineno);
                                            retjumpQuad[functionOffset] = emit(jump, NULL, NULL, NULL, 0, yylineno);
                                        }
                                    }
#line 3094 "parser.c" /* yacc.c:1646  */
    break;


#line 3098 "parser.c" /* yacc.c:1646  */
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
#line 1157 "parser.y" /* yacc.c:1906  */


int getCurrScope(){ return curr_scope; }

int getCurrLine(){ return yylineno; }

void print_rules(char* rule1, char* rule2){
    char* final_rule = (char *)malloc(250*sizeof(char));
    memset (final_rule,'0',250);

    strcpy(final_rule, rule1);
    strcat(final_rule, " -> ");
    strcat(final_rule, rule2);
    strcat(final_rule, "\n");

    fputs(final_rule, RULES_STREAM);
}

void print_error(error_t type, char* msg){
    if(type == error)
        fprintf(ERROR_OUT, "\033[0;31mError:\033[0m %s\n", msg);
    else if(type == warning)
        fprintf(ERROR_OUT, "\033[0;35mWarning:\033[0m %s\n", msg);
}

struct func_local_stack* create_func_stack(){
    struct func_local_stack* ret = (struct func_local_stack*)malloc(sizeof(struct func_local_stack));
    ret->head = NULL;
    ret->tail = NULL;
    ret->nodes = 0;

    return ret;
}

void func_push(struct func_local_stack* s, int cur_local_offset){
    struct func_node* new = (struct func_node *)malloc(sizeof(struct func_node));
    new->local_offset = cur_local_offset;
    new->next = NULL;
    
    if(s->head == NULL){
        s->head = new;
        s->tail = new;
    }   
    else{
        s->tail->next = new;
        s->tail = new;
    }
    s->nodes++;
}

int func_pop(struct func_local_stack* s){
    int ret = s->tail->local_offset;
    struct func_node* tmp = s->head;

    if(s->nodes == 1){
        free(s->head);
        s->head = NULL;
        s->tail = NULL;
        s->nodes--;
        return ret;
    }

    while(tmp->next != s->tail){
        tmp = tmp->next;
    }
    s->tail = tmp;
    free(tmp->next);
    s->tail->next = NULL;
    s->nodes--;
    return ret;
}

int func_top(struct func_local_stack* s){
    return s->tail->local_offset;
}

void funcjumpsReset(int offset){
    funcjumpQuad[offset] = NULL;
    retjumpQuad[offset] = NULL;
}

int main(int argc, char *argv[]){
    table = create_table();
    loopstack = new_stack();
    functionLocalsStack = create_func_stack();

    if(argv[1] != NULL)
        yyin = fopen(argv[1], "r");

    if(argv[2] != NULL){
        yyout = fopen(argv[2], "w+");
    }else{
        yyout = stdout;
    }

    rules_out = fopen("../output/rules.out","w+");
    sym_sc_out = fopen("../output/symtab_scopes.out","w+");
    sym_buc_out = fopen("../output/symtab_buckets.out","w+");
    quad_out = fopen("../output/quads.aic", "w+");

    push(loopstack);
    yyparse();
    
    if(exit_flag == 1){
        fprintf(stderr, "Intermediate Code generation failed\n");
        print_table_scopes(table, sym_sc_out);
        print_table_buckets(table, sym_buc_out);
        exit(1);
    }

    print_table_scopes(table, sym_sc_out);
    print_table_buckets(table, sym_buc_out);
    printQuads(quad_out);


    return 1;
}
