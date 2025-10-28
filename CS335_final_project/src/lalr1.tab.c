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
#line 1 "lalr1.y"

    #include "lalr1.tab.h"
    #include<bits/stdc++.h>
    #include<fstream>
    #include "symtab.h"
    #include "tac_convert.h"
    using namespace std;
    extern int yylex();
    extern FILE *yyin;
    extern FILE *yyout;
    int yyerror(const char*msg);
    extern int yylineno;
    astnode *theprogram;
    int verb=0;
    map< string, symtab_t* > symtab_top;
    symtab_t *symtab =  init_symtab_top();
    int currscope = 0;
    string fullscope = "0";
    int curr_fcnscope = 0;
    string s1,s2;
    ofstream symbolTable;
    ofstream tac;
    //splitting strings separated by comma
    vector<string> split(const string &s, char delim) {
        stringstream ss(s);
        string item;
        vector<string> tokens;
        while (getline(ss, item, delim)) {
            tokens.push_back(item);
        }
        return tokens;
    }
    map<string,string>buffer;// a,int type;
    vector<string>prog;
    int tempno=0;
    int labelno = 0;
    int line=0;
    string get_tempvar(){
        string str_t = "t";
        string ans =  str_t.append(to_string(tempno));
        tempno++;
        return ans;
    }
    string get_label(){
        string str_l = "label";
        string ans =  str_l.append(to_string(labelno));
        labelno++;
        return ans;
    }

    stack <string> if_endlabels;
    stack <string> if_bwlabels;
    stack <string> while_bwlabels;
    stack <string> while_endlabels;
    stack <string> while_exp;
    stack <string> do_bwlabels;
    stack <string> for_initlabels;
    stack <string> for_endlabels;
    stack <string> for_statlabels;
    stack <string> for_updlabels;
    stack <string> cond_bwlabels;
    stack <string> cond_endlabels;
    stack <string> cond_inlabels;
    stack <string> class_labels;
    // stack <string> for_breaklabels;	//not used
    // stack <string> for_continuelabels;

    string cname="class";
    string fname="fname";
    string temp_type="";
    string temp="";
    // string gpara="ud";
    map<string,string>m;//identifier vs label;
    map<string,string>m1;//class vs scope;

#line 147 "lalr1.tab.c"

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

#include "lalr1.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_OPERATOR = 3,                   /* OPERATOR  */
  YYSYMBOL_OPEN_SQ = 4,                    /* OPEN_SQ  */
  YYSYMBOL_CLOSE_SQ = 5,                   /* CLOSE_SQ  */
  YYSYMBOL_OPEN_BR = 6,                    /* OPEN_BR  */
  YYSYMBOL_CLOSE_BR = 7,                   /* CLOSE_BR  */
  YYSYMBOL_OPEN_CR = 8,                    /* OPEN_CR  */
  YYSYMBOL_CLOSE_CR = 9,                   /* CLOSE_CR  */
  YYSYMBOL_SEPERATOR = 10,                 /* SEPERATOR  */
  YYSYMBOL_INT_LIT = 11,                   /* INT_LIT  */
  YYSYMBOL_FLOAT_LIT = 12,                 /* FLOAT_LIT  */
  YYSYMBOL_CHAR_LIT = 13,                  /* CHAR_LIT  */
  YYSYMBOL_STR_LIT = 14,                   /* STR_LIT  */
  YYSYMBOL_TXT_BLK = 15,                   /* TXT_BLK  */
  YYSYMBOL_BOOL_LIT = 16,                  /* BOOL_LIT  */
  YYSYMBOL_NULL_LIT = 17,                  /* NULL_LIT  */
  YYSYMBOL_KEYWORD = 18,                   /* KEYWORD  */
  YYSYMBOL_ABSTRACT = 19,                  /* ABSTRACT  */
  YYSYMBOL_CONTINUE = 20,                  /* CONTINUE  */
  YYSYMBOL_FOR = 21,                       /* FOR  */
  YYSYMBOL_NEW = 22,                       /* NEW  */
  YYSYMBOL_SWITCH = 23,                    /* SWITCH  */
  YYSYMBOL_ASSERT = 24,                    /* ASSERT  */
  YYSYMBOL_DEFAULT = 25,                   /* DEFAULT  */
  YYSYMBOL_IF = 26,                        /* IF  */
  YYSYMBOL_PACKAGE = 27,                   /* PACKAGE  */
  YYSYMBOL_SYNCHRONIZED = 28,              /* SYNCHRONIZED  */
  YYSYMBOL_BOOLEAN = 29,                   /* BOOLEAN  */
  YYSYMBOL_DO = 30,                        /* DO  */
  YYSYMBOL_GOTO = 31,                      /* GOTO  */
  YYSYMBOL_PRIVATE = 32,                   /* PRIVATE  */
  YYSYMBOL_THIS = 33,                      /* THIS  */
  YYSYMBOL_BREAK = 34,                     /* BREAK  */
  YYSYMBOL_DOUBLE = 35,                    /* DOUBLE  */
  YYSYMBOL_IMPLEMENTS = 36,                /* IMPLEMENTS  */
  YYSYMBOL_PROTECTED = 37,                 /* PROTECTED  */
  YYSYMBOL_THROW = 38,                     /* THROW  */
  YYSYMBOL_BYTE = 39,                      /* BYTE  */
  YYSYMBOL_ELSE = 40,                      /* ELSE  */
  YYSYMBOL_IMPORT = 41,                    /* IMPORT  */
  YYSYMBOL_PUBLIC = 42,                    /* PUBLIC  */
  YYSYMBOL_THROWS = 43,                    /* THROWS  */
  YYSYMBOL_CASE = 44,                      /* CASE  */
  YYSYMBOL_ENUM = 45,                      /* ENUM  */
  YYSYMBOL_INSTANCEOF = 46,                /* INSTANCEOF  */
  YYSYMBOL_RETURN = 47,                    /* RETURN  */
  YYSYMBOL_TRANSIENT = 48,                 /* TRANSIENT  */
  YYSYMBOL_CATCH = 49,                     /* CATCH  */
  YYSYMBOL_EXTENDS = 50,                   /* EXTENDS  */
  YYSYMBOL_INT = 51,                       /* INT  */
  YYSYMBOL_SHORT = 52,                     /* SHORT  */
  YYSYMBOL_TRY = 53,                       /* TRY  */
  YYSYMBOL_CHAR = 54,                      /* CHAR  */
  YYSYMBOL_FINAL = 55,                     /* FINAL  */
  YYSYMBOL_INTERFACE = 56,                 /* INTERFACE  */
  YYSYMBOL_STATIC = 57,                    /* STATIC  */
  YYSYMBOL_VOID = 58,                      /* VOID  */
  YYSYMBOL_CLASS = 59,                     /* CLASS  */
  YYSYMBOL_FINALLY = 60,                   /* FINALLY  */
  YYSYMBOL_LONG = 61,                      /* LONG  */
  YYSYMBOL_STRICTFP = 62,                  /* STRICTFP  */
  YYSYMBOL_VOLATILE = 63,                  /* VOLATILE  */
  YYSYMBOL_CONST = 64,                     /* CONST  */
  YYSYMBOL_FLOAT = 65,                     /* FLOAT  */
  YYSYMBOL_NATIVE = 66,                    /* NATIVE  */
  YYSYMBOL_SUPER = 67,                     /* SUPER  */
  YYSYMBOL_WHILE = 68,                     /* WHILE  */
  YYSYMBOL__ = 69,                         /* _  */
  YYSYMBOL_EXPORTS = 70,                   /* EXPORTS  */
  YYSYMBOL_OPENS = 71,                     /* OPENS  */
  YYSYMBOL_REQUIRES = 72,                  /* REQUIRES  */
  YYSYMBOL_USES = 73,                      /* USES  */
  YYSYMBOL_MODULE = 74,                    /* MODULE  */
  YYSYMBOL_PERMITS = 75,                   /* PERMITS  */
  YYSYMBOL_SEALED = 76,                    /* SEALED  */
  YYSYMBOL_VAR = 77,                       /* VAR  */
  YYSYMBOL_78_NON_SEALED = 78,             /* NON-SEALED  */
  YYSYMBOL_PROVIDES = 79,                  /* PROVIDES  */
  YYSYMBOL_TO = 80,                        /* TO  */
  YYSYMBOL_WITH = 81,                      /* WITH  */
  YYSYMBOL_OPEN = 82,                      /* OPEN  */
  YYSYMBOL_RECORD = 83,                    /* RECORD  */
  YYSYMBOL_TRANSITIVE = 84,                /* TRANSITIVE  */
  YYSYMBOL_YIELD = 85,                     /* YIELD  */
  YYSYMBOL_IDENTIFIER = 86,                /* IDENTIFIER  */
  YYSYMBOL_ADD = 87,                       /* ADD  */
  YYSYMBOL_SUB = 88,                       /* SUB  */
  YYSYMBOL_MUL = 89,                       /* MUL  */
  YYSYMBOL_QUO = 90,                       /* QUO  */
  YYSYMBOL_REM = 91,                       /* REM  */
  YYSYMBOL_AND = 92,                       /* AND  */
  YYSYMBOL_OR = 93,                        /* OR  */
  YYSYMBOL_XOR = 94,                       /* XOR  */
  YYSYMBOL_SHL = 95,                       /* SHL  */
  YYSYMBOL_SHR = 96,                       /* SHR  */
  YYSYMBOL_GR = 97,                        /* GR  */
  YYSYMBOL_ADD_ASSIGN = 98,                /* ADD_ASSIGN  */
  YYSYMBOL_SUB_ASSIGN = 99,                /* SUB_ASSIGN  */
  YYSYMBOL_MUL_ASSIGN = 100,               /* MUL_ASSIGN  */
  YYSYMBOL_QUO_ASSIGN = 101,               /* QUO_ASSIGN  */
  YYSYMBOL_REM_ASSIGN = 102,               /* REM_ASSIGN  */
  YYSYMBOL_AND_ASSIGN = 103,               /* AND_ASSIGN  */
  YYSYMBOL_OR_ASSIGN = 104,                /* OR_ASSIGN  */
  YYSYMBOL_XOR_ASSIGN = 105,               /* XOR_ASSIGN  */
  YYSYMBOL_SHL_ASSIGN = 106,               /* SHL_ASSIGN  */
  YYSYMBOL_SHR_ASSIGN = 107,               /* SHR_ASSIGN  */
  YYSYMBOL_GEQUAL = 108,                   /* GEQUAL  */
  YYSYMBOL_LAND = 109,                     /* LAND  */
  YYSYMBOL_LOR = 110,                      /* LOR  */
  YYSYMBOL_INC = 111,                      /* INC  */
  YYSYMBOL_DEC = 112,                      /* DEC  */
  YYSYMBOL_EQL = 113,                      /* EQL  */
  YYSYMBOL_NEQ = 114,                      /* NEQ  */
  YYSYMBOL_LEQ = 115,                      /* LEQ  */
  YYSYMBOL_GEQ = 116,                      /* GEQ  */
  YYSYMBOL_ASSIGN = 117,                   /* ASSIGN  */
  YYSYMBOL_ARROW = 118,                    /* ARROW  */
  YYSYMBOL_GTR = 119,                      /* GTR  */
  YYSYMBOL_LSS = 120,                      /* LSS  */
  YYSYMBOL_NOT = 121,                      /* NOT  */
  YYSYMBOL_TILDE = 122,                    /* TILDE  */
  YYSYMBOL_QMARK = 123,                    /* QMARK  */
  YYSYMBOL_ELLIPSIS = 124,                 /* ELLIPSIS  */
  YYSYMBOL_COMMA = 125,                    /* COMMA  */
  YYSYMBOL_SEMICOLON = 126,                /* SEMICOLON  */
  YYSYMBOL_DCOLON = 127,                   /* DCOLON  */
  YYSYMBOL_COLON = 128,                    /* COLON  */
  YYSYMBOL_PERIOD = 129,                   /* PERIOD  */
  YYSYMBOL_AMPERSAT = 130,                 /* AMPERSAT  */
  YYSYMBOL_PRINTLN = 131,                  /* PRINTLN  */
  YYSYMBOL_YYACCEPT = 132,                 /* $accept  */
  YYSYMBOL_input = 133,                    /* input  */
  YYSYMBOL_SYMTABS = 134,                  /* SYMTABS  */
  YYSYMBOL_SYMTABE = 135,                  /* SYMTABE  */
  YYSYMBOL_IFMARK1 = 136,                  /* IFMARK1  */
  YYSYMBOL_IFEND1 = 137,                   /* IFEND1  */
  YYSYMBOL_IFEND2 = 138,                   /* IFEND2  */
  YYSYMBOL_ELSEMARK1 = 139,                /* ELSEMARK1  */
  YYSYMBOL_ELSEEND1 = 140,                 /* ELSEEND1  */
  YYSYMBOL_WHILEMARK2 = 141,               /* WHILEMARK2  */
  YYSYMBOL_WHILEMARK1 = 142,               /* WHILEMARK1  */
  YYSYMBOL_WHILEEND1 = 143,                /* WHILEEND1  */
  YYSYMBOL_DOMARK1 = 144,                  /* DOMARK1  */
  YYSYMBOL_DOEND1 = 145,                   /* DOEND1  */
  YYSYMBOL_FORMARK1 = 146,                 /* FORMARK1  */
  YYSYMBOL_FORMARK2 = 147,                 /* FORMARK2  */
  YYSYMBOL_FORMARK3 = 148,                 /* FORMARK3  */
  YYSYMBOL_FOREND1 = 149,                  /* FOREND1  */
  YYSYMBOL_CONDMARK1 = 150,                /* CONDMARK1  */
  YYSYMBOL_CONDMARK2 = 151,                /* CONDMARK2  */
  YYSYMBOL_CONDMARK3 = 152,                /* CONDMARK3  */
  YYSYMBOL_PrintStatement = 153,           /* PrintStatement  */
  YYSYMBOL_PrintArgs = 154,                /* PrintArgs  */
  YYSYMBOL_PrintArg = 155,                 /* PrintArg  */
  YYSYMBOL_Literal = 156,                  /* Literal  */
  YYSYMBOL_Type = 157,                     /* Type  */
  YYSYMBOL_PrimitiveType = 158,            /* PrimitiveType  */
  YYSYMBOL_NumericType = 159,              /* NumericType  */
  YYSYMBOL_IntegralType = 160,             /* IntegralType  */
  YYSYMBOL_FloatingPointType = 161,        /* FloatingPointType  */
  YYSYMBOL_ReferenceType = 162,            /* ReferenceType  */
  YYSYMBOL_ClassOrInterfaceType = 163,     /* ClassOrInterfaceType  */
  YYSYMBOL_ClassType = 164,                /* ClassType  */
  YYSYMBOL_InterfaceType = 165,            /* InterfaceType  */
  YYSYMBOL_ArrayType = 166,                /* ArrayType  */
  YYSYMBOL_Name = 167,                     /* Name  */
  YYSYMBOL_SingularName = 168,             /* SingularName  */
  YYSYMBOL_ComplexName = 169,              /* ComplexName  */
  YYSYMBOL_CompilationUnit = 170,          /* CompilationUnit  */
  YYSYMBOL_ImportDeclarations = 171,       /* ImportDeclarations  */
  YYSYMBOL_TypeDeclarations = 172,         /* TypeDeclarations  */
  YYSYMBOL_PackageDeclaration = 173,       /* PackageDeclaration  */
  YYSYMBOL_ImportDeclaration = 174,        /* ImportDeclaration  */
  YYSYMBOL_SingleTypeImportDeclaration = 175, /* SingleTypeImportDeclaration  */
  YYSYMBOL_TypeImportOnDemandDeclaration = 176, /* TypeImportOnDemandDeclaration  */
  YYSYMBOL_TypeDeclaration = 177,          /* TypeDeclaration  */
  YYSYMBOL_Modifiers = 178,                /* Modifiers  */
  YYSYMBOL_Modifier = 179,                 /* Modifier  */
  YYSYMBOL_ClassName = 180,                /* ClassName  */
  YYSYMBOL_ClassDeclaration = 181,         /* ClassDeclaration  */
  YYSYMBOL_Super = 182,                    /* Super  */
  YYSYMBOL_Interfaces = 183,               /* Interfaces  */
  YYSYMBOL_InterfaceTypeList = 184,        /* InterfaceTypeList  */
  YYSYMBOL_CLASSMARK1 = 185,               /* CLASSMARK1  */
  YYSYMBOL_ClassBody = 186,                /* ClassBody  */
  YYSYMBOL_ClassBodyDeclarations = 187,    /* ClassBodyDeclarations  */
  YYSYMBOL_ClassBodyDeclaration = 188,     /* ClassBodyDeclaration  */
  YYSYMBOL_ClassMemberDeclaration = 189,   /* ClassMemberDeclaration  */
  YYSYMBOL_FieldDeclaration = 190,         /* FieldDeclaration  */
  YYSYMBOL_VariableDeclarators = 191,      /* VariableDeclarators  */
  YYSYMBOL_VariableDeclarator = 192,       /* VariableDeclarator  */
  YYSYMBOL_VariableDeclaratorId = 193,     /* VariableDeclaratorId  */
  YYSYMBOL_VariableInitializer = 194,      /* VariableInitializer  */
  YYSYMBOL_MethodDeclaration = 195,        /* MethodDeclaration  */
  YYSYMBOL_MethodHeader = 196,             /* MethodHeader  */
  YYSYMBOL_MethodDeclarator = 197,         /* MethodDeclarator  */
  YYSYMBOL_FunctionName = 198,             /* FunctionName  */
  YYSYMBOL_FormalParameterLists = 199,     /* FormalParameterLists  */
  YYSYMBOL_FormalParameterList = 200,      /* FormalParameterList  */
  YYSYMBOL_FormalParameter = 201,          /* FormalParameter  */
  YYSYMBOL_Throws = 202,                   /* Throws  */
  YYSYMBOL_ClassTypeList = 203,            /* ClassTypeList  */
  YYSYMBOL_MethodBody = 204,               /* MethodBody  */
  YYSYMBOL_StaticInitializer = 205,        /* StaticInitializer  */
  YYSYMBOL_ConstructorDeclaration = 206,   /* ConstructorDeclaration  */
  YYSYMBOL_ConstructorDeclarator = 207,    /* ConstructorDeclarator  */
  YYSYMBOL_ConstructorName = 208,          /* ConstructorName  */
  YYSYMBOL_ConstructorBody = 209,          /* ConstructorBody  */
  YYSYMBOL_ExplicitConstructorInvocation = 210, /* ExplicitConstructorInvocation  */
  YYSYMBOL_InterfaceDeclaration = 211,     /* InterfaceDeclaration  */
  YYSYMBOL_ExtendsInterfaces = 212,        /* ExtendsInterfaces  */
  YYSYMBOL_InterfaceBody = 213,            /* InterfaceBody  */
  YYSYMBOL_InterfaceMemberDeclarations = 214, /* InterfaceMemberDeclarations  */
  YYSYMBOL_InterfaceMemberDeclaration = 215, /* InterfaceMemberDeclaration  */
  YYSYMBOL_ConstantDeclaration = 216,      /* ConstantDeclaration  */
  YYSYMBOL_AbstractMethodDeclaration = 217, /* AbstractMethodDeclaration  */
  YYSYMBOL_ArrayInitializer = 218,         /* ArrayInitializer  */
  YYSYMBOL_VariableInitializers = 219,     /* VariableInitializers  */
  YYSYMBOL_Block = 220,                    /* Block  */
  YYSYMBOL_BlockStatements = 221,          /* BlockStatements  */
  YYSYMBOL_BlockStatement = 222,           /* BlockStatement  */
  YYSYMBOL_LocalVariableDeclarationStatement = 223, /* LocalVariableDeclarationStatement  */
  YYSYMBOL_LocalVariableDeclaration = 224, /* LocalVariableDeclaration  */
  YYSYMBOL_Statement = 225,                /* Statement  */
  YYSYMBOL_StatementNoShortIf = 226,       /* StatementNoShortIf  */
  YYSYMBOL_StatementWithoutTrailingSubstatement = 227, /* StatementWithoutTrailingSubstatement  */
  YYSYMBOL_EmptyStatement = 228,           /* EmptyStatement  */
  YYSYMBOL_LabeledStatement = 229,         /* LabeledStatement  */
  YYSYMBOL_LabeledStatementNoShortIf = 230, /* LabeledStatementNoShortIf  */
  YYSYMBOL_ExpressionStatement = 231,      /* ExpressionStatement  */
  YYSYMBOL_StatementExpression = 232,      /* StatementExpression  */
  YYSYMBOL_IfThenStatement = 233,          /* IfThenStatement  */
  YYSYMBOL_IfThenElseStatement = 234,      /* IfThenElseStatement  */
  YYSYMBOL_IfThenElseStatementNoShortIf = 235, /* IfThenElseStatementNoShortIf  */
  YYSYMBOL_SwitchStatement = 236,          /* SwitchStatement  */
  YYSYMBOL_SwitchBlock = 237,              /* SwitchBlock  */
  YYSYMBOL_SwitchBlockStatementGroups = 238, /* SwitchBlockStatementGroups  */
  YYSYMBOL_SwitchBlockStatementGroup = 239, /* SwitchBlockStatementGroup  */
  YYSYMBOL_SwitchLabels = 240,             /* SwitchLabels  */
  YYSYMBOL_SwitchLabel = 241,              /* SwitchLabel  */
  YYSYMBOL_WhileStatement = 242,           /* WhileStatement  */
  YYSYMBOL_WhileStatementNoShortIf = 243,  /* WhileStatementNoShortIf  */
  YYSYMBOL_DoStatement = 244,              /* DoStatement  */
  YYSYMBOL_ForStatement = 245,             /* ForStatement  */
  YYSYMBOL_ForStatementNoShortIf = 246,    /* ForStatementNoShortIf  */
  YYSYMBOL_ForInit = 247,                  /* ForInit  */
  YYSYMBOL_ForUpdate = 248,                /* ForUpdate  */
  YYSYMBOL_StatementExpressionList = 249,  /* StatementExpressionList  */
  YYSYMBOL_BreakStatement = 250,           /* BreakStatement  */
  YYSYMBOL_ContinueStatement = 251,        /* ContinueStatement  */
  YYSYMBOL_ReturnStatement = 252,          /* ReturnStatement  */
  YYSYMBOL_ThrowStatement = 253,           /* ThrowStatement  */
  YYSYMBOL_SynchronizedStatement = 254,    /* SynchronizedStatement  */
  YYSYMBOL_TryStatement = 255,             /* TryStatement  */
  YYSYMBOL_Catches = 256,                  /* Catches  */
  YYSYMBOL_CatchClause = 257,              /* CatchClause  */
  YYSYMBOL_Finally = 258,                  /* Finally  */
  YYSYMBOL_Primary = 259,                  /* Primary  */
  YYSYMBOL_PrimaryNoNewArray = 260,        /* PrimaryNoNewArray  */
  YYSYMBOL_ClassInstanceCreationExpression = 261, /* ClassInstanceCreationExpression  */
  YYSYMBOL_ArgumentList = 262,             /* ArgumentList  */
  YYSYMBOL_ArrayCreationExpression = 263,  /* ArrayCreationExpression  */
  YYSYMBOL_DimExprs = 264,                 /* DimExprs  */
  YYSYMBOL_DimExpr = 265,                  /* DimExpr  */
  YYSYMBOL_Dims = 266,                     /* Dims  */
  YYSYMBOL_FieldAccess = 267,              /* FieldAccess  */
  YYSYMBOL_MethodInvocation = 268,         /* MethodInvocation  */
  YYSYMBOL_ArrayAccess = 269,              /* ArrayAccess  */
  YYSYMBOL_PostfixExpression = 270,        /* PostfixExpression  */
  YYSYMBOL_PostIncrementExpression = 271,  /* PostIncrementExpression  */
  YYSYMBOL_PostDecrementExpression = 272,  /* PostDecrementExpression  */
  YYSYMBOL_UnaryExpression = 273,          /* UnaryExpression  */
  YYSYMBOL_PreIncrementExpression = 274,   /* PreIncrementExpression  */
  YYSYMBOL_PreDecrementExpression = 275,   /* PreDecrementExpression  */
  YYSYMBOL_UnaryExpressionNotPlusMinus = 276, /* UnaryExpressionNotPlusMinus  */
  YYSYMBOL_CastExpression = 277,           /* CastExpression  */
  YYSYMBOL_MultiplicativeExpression = 278, /* MultiplicativeExpression  */
  YYSYMBOL_AdditiveExpression = 279,       /* AdditiveExpression  */
  YYSYMBOL_ShiftExpression = 280,          /* ShiftExpression  */
  YYSYMBOL_RelationalExpression = 281,     /* RelationalExpression  */
  YYSYMBOL_EqualityExpression = 282,       /* EqualityExpression  */
  YYSYMBOL_AndExpression = 283,            /* AndExpression  */
  YYSYMBOL_ExclusiveOrExpression = 284,    /* ExclusiveOrExpression  */
  YYSYMBOL_InclusiveOrExpression = 285,    /* InclusiveOrExpression  */
  YYSYMBOL_ConditionalAndExpression = 286, /* ConditionalAndExpression  */
  YYSYMBOL_ConditionalOrExpression = 287,  /* ConditionalOrExpression  */
  YYSYMBOL_ConditionalExpression = 288,    /* ConditionalExpression  */
  YYSYMBOL_AssignmentExpression = 289,     /* AssignmentExpression  */
  YYSYMBOL_Assignment = 290,               /* Assignment  */
  YYSYMBOL_LeftHandSide = 291,             /* LeftHandSide  */
  YYSYMBOL_AssignmentOperator = 292,       /* AssignmentOperator  */
  YYSYMBOL_Expression = 293,               /* Expression  */
  YYSYMBOL_ConstantExpression = 294        /* ConstantExpression  */
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
typedef yytype_int16 yy_state_t;

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

#if 1

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
#endif /* 1 */

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
#define YYFINAL  37
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   3478

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  132
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  163
/* YYNRULES -- Number of rules.  */
#define YYNRULES  383
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  720

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   386


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   102,   102,   120,   152,   187,   204,   213,   222,   231,
     241,   251,   265,   281,   290,   299,   308,   325,   338,   351,
     363,   375,   383,   398,   409,   422,   433,   444,   455,   461,
     473,   484,   495,   506,   517,   531,   541,   553,   562,   573,
     582,   593,   602,   611,   620,   629,   640,   649,   660,   671,
     683,   696,   708,   721,   732,   743,   757,   769,   783,   801,
     830,   838,   846,   855,   864,   874,   883,   891,   901,   909,
     920,   928,   939,   951,   960,   971,   984,   999,  1008,  1017,
    1027,  1036,  1048,  1056,  1064,  1073,  1081,  1089,  1097,  1105,
    1113,  1121,  1132,  1146,  1161,  1175,  1189,  1202,  1216,  1229,
    1242,  1256,  1268,  1280,  1289,  1302,  1310,  1321,  1332,  1340,
    1351,  1360,  1369,  1380,  1389,  1401,  1418,  1436,  1452,  1471,
    1484,  1544,  1564,  1595,  1609,  1628,  1655,  1669,  1681,  1693,
    1704,  1717,  1729,  1741,  1754,  1767,  1778,  1792,  1825,  1846,
    1857,  1872,  1888,  1899,  1907,  1919,  1927,  1938,  1950,  1961,
    1971,  1981,  1993,  2005,  2018,  2038,  2054,  2069,  2084,  2100,
    2112,  2123,  2135,  2149,  2161,  2172,  2183,  2195,  2204,  2216,
    2226,  2237,  2245,  2256,  2264,  2274,  2284,  2296,  2323,  2348,
    2368,  2389,  2406,  2438,  2447,  2459,  2467,  2478,  2494,  2505,
    2520,  2538,  2547,  2555,  2563,  2571,  2579,  2589,  2597,  2605,
    2613,  2621,  2631,  2639,  2647,  2656,  2664,  2672,  2680,  2688,
    2696,  2704,  2712,  2722,  2732,  2748,  2764,  2777,  2787,  2797,
    2807,  2817,  2827,  2842,  2852,  2865,  2879,  2895,  2911,  2925,
    2934,  2944,  2954,  2967,  2975,  2986,  2997,  3005,  3016,  3026,
    3037,  3051,  3065,  3081,  3094,  3108,  3122,  3137,  3151,  3166,
    3181,  3199,  3212,  3226,  3240,  3255,  3269,  3284,  3299,  3317,
    3326,  3342,  3353,  3362,  3375,  3388,  3400,  3413,  3429,  3441,
    3460,  3472,  3486,  3496,  3506,  3519,  3527,  3538,  3552,  3566,
    3586,  3600,  3612,  3622,  3639,  3650,  3661,  3674,  3690,  3721,
    3761,  3771,  3785,  3802,  3819,  3836,  3856,  3867,  3881,  3899,
    3909,  3922,  3943,  3957,  4032,  4130,  4158,  4190,  4210,  4243,
    4275,  4306,  4319,  4331,  4342,  4355,  4376,  4397,  4409,  4420,
    4437,  4454,  4469,  4490,  4511,  4524,  4541,  4558,  4570,  4586,
    4603,  4615,  4633,  4646,  4682,  4718,  4756,  4769,  4806,  4844,
    4857,  4893,  4929,  4967,  4980,  5016,  5052,  5088,  5124,  5146,
    5159,  5195,  5233,  5246,  5284,  5297,  5335,  5348,  5386,  5399,
    5437,  5450,  5488,  5501,  5526,  5539,  5552,  5634,  5645,  5655,
    5671,  5680,  5689,  5698,  5707,  5716,  5725,  5734,  5743,  5752,
    5761,  5770,  5781,  5796
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "OPERATOR", "OPEN_SQ",
  "CLOSE_SQ", "OPEN_BR", "CLOSE_BR", "OPEN_CR", "CLOSE_CR", "SEPERATOR",
  "INT_LIT", "FLOAT_LIT", "CHAR_LIT", "STR_LIT", "TXT_BLK", "BOOL_LIT",
  "NULL_LIT", "KEYWORD", "ABSTRACT", "CONTINUE", "FOR", "NEW", "SWITCH",
  "ASSERT", "DEFAULT", "IF", "PACKAGE", "SYNCHRONIZED", "BOOLEAN", "DO",
  "GOTO", "PRIVATE", "THIS", "BREAK", "DOUBLE", "IMPLEMENTS", "PROTECTED",
  "THROW", "BYTE", "ELSE", "IMPORT", "PUBLIC", "THROWS", "CASE", "ENUM",
  "INSTANCEOF", "RETURN", "TRANSIENT", "CATCH", "EXTENDS", "INT", "SHORT",
  "TRY", "CHAR", "FINAL", "INTERFACE", "STATIC", "VOID", "CLASS",
  "FINALLY", "LONG", "STRICTFP", "VOLATILE", "CONST", "FLOAT", "NATIVE",
  "SUPER", "WHILE", "_", "EXPORTS", "OPENS", "REQUIRES", "USES", "MODULE",
  "PERMITS", "SEALED", "VAR", "NON-SEALED", "PROVIDES", "TO", "WITH",
  "OPEN", "RECORD", "TRANSITIVE", "YIELD", "IDENTIFIER", "ADD", "SUB",
  "MUL", "QUO", "REM", "AND", "OR", "XOR", "SHL", "SHR", "GR",
  "ADD_ASSIGN", "SUB_ASSIGN", "MUL_ASSIGN", "QUO_ASSIGN", "REM_ASSIGN",
  "AND_ASSIGN", "OR_ASSIGN", "XOR_ASSIGN", "SHL_ASSIGN", "SHR_ASSIGN",
  "GEQUAL", "LAND", "LOR", "INC", "DEC", "EQL", "NEQ", "LEQ", "GEQ",
  "ASSIGN", "ARROW", "GTR", "LSS", "NOT", "TILDE", "QMARK", "ELLIPSIS",
  "COMMA", "SEMICOLON", "DCOLON", "COLON", "PERIOD", "AMPERSAT", "PRINTLN",
  "$accept", "input", "SYMTABS", "SYMTABE", "IFMARK1", "IFEND1", "IFEND2",
  "ELSEMARK1", "ELSEEND1", "WHILEMARK2", "WHILEMARK1", "WHILEEND1",
  "DOMARK1", "DOEND1", "FORMARK1", "FORMARK2", "FORMARK3", "FOREND1",
  "CONDMARK1", "CONDMARK2", "CONDMARK3", "PrintStatement", "PrintArgs",
  "PrintArg", "Literal", "Type", "PrimitiveType", "NumericType",
  "IntegralType", "FloatingPointType", "ReferenceType",
  "ClassOrInterfaceType", "ClassType", "InterfaceType", "ArrayType",
  "Name", "SingularName", "ComplexName", "CompilationUnit",
  "ImportDeclarations", "TypeDeclarations", "PackageDeclaration",
  "ImportDeclaration", "SingleTypeImportDeclaration",
  "TypeImportOnDemandDeclaration", "TypeDeclaration", "Modifiers",
  "Modifier", "ClassName", "ClassDeclaration", "Super", "Interfaces",
  "InterfaceTypeList", "CLASSMARK1", "ClassBody", "ClassBodyDeclarations",
  "ClassBodyDeclaration", "ClassMemberDeclaration", "FieldDeclaration",
  "VariableDeclarators", "VariableDeclarator", "VariableDeclaratorId",
  "VariableInitializer", "MethodDeclaration", "MethodHeader",
  "MethodDeclarator", "FunctionName", "FormalParameterLists",
  "FormalParameterList", "FormalParameter", "Throws", "ClassTypeList",
  "MethodBody", "StaticInitializer", "ConstructorDeclaration",
  "ConstructorDeclarator", "ConstructorName", "ConstructorBody",
  "ExplicitConstructorInvocation", "InterfaceDeclaration",
  "ExtendsInterfaces", "InterfaceBody", "InterfaceMemberDeclarations",
  "InterfaceMemberDeclaration", "ConstantDeclaration",
  "AbstractMethodDeclaration", "ArrayInitializer", "VariableInitializers",
  "Block", "BlockStatements", "BlockStatement",
  "LocalVariableDeclarationStatement", "LocalVariableDeclaration",
  "Statement", "StatementNoShortIf",
  "StatementWithoutTrailingSubstatement", "EmptyStatement",
  "LabeledStatement", "LabeledStatementNoShortIf", "ExpressionStatement",
  "StatementExpression", "IfThenStatement", "IfThenElseStatement",
  "IfThenElseStatementNoShortIf", "SwitchStatement", "SwitchBlock",
  "SwitchBlockStatementGroups", "SwitchBlockStatementGroup",
  "SwitchLabels", "SwitchLabel", "WhileStatement",
  "WhileStatementNoShortIf", "DoStatement", "ForStatement",
  "ForStatementNoShortIf", "ForInit", "ForUpdate",
  "StatementExpressionList", "BreakStatement", "ContinueStatement",
  "ReturnStatement", "ThrowStatement", "SynchronizedStatement",
  "TryStatement", "Catches", "CatchClause", "Finally", "Primary",
  "PrimaryNoNewArray", "ClassInstanceCreationExpression", "ArgumentList",
  "ArrayCreationExpression", "DimExprs", "DimExpr", "Dims", "FieldAccess",
  "MethodInvocation", "ArrayAccess", "PostfixExpression",
  "PostIncrementExpression", "PostDecrementExpression", "UnaryExpression",
  "PreIncrementExpression", "PreDecrementExpression",
  "UnaryExpressionNotPlusMinus", "CastExpression",
  "MultiplicativeExpression", "AdditiveExpression", "ShiftExpression",
  "RelationalExpression", "EqualityExpression", "AndExpression",
  "ExclusiveOrExpression", "InclusiveOrExpression",
  "ConditionalAndExpression", "ConditionalOrExpression",
  "ConditionalExpression", "AssignmentExpression", "Assignment",
  "LeftHandSide", "AssignmentOperator", "Expression", "ConstantExpression", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-469)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-370)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     776,  -469,   -44,  -469,  -469,  -469,   -44,  -469,  -469,  -469,
     -39,  -469,    13,  -469,  -469,  -469,    84,  -469,  1370,  1010,
    1370,  -469,  -469,  -469,  -469,  3392,  -469,  -469,  -469,  -469,
       0,  -469,  -469,    97,    32,  -469,    52,  -469,  1010,  -469,
    -469,  1370,  1010,    47,    13,  -469,  -469,    99,  -469,   139,
     222,   -44,    58,  -469,   235,   -44,   -44,    55,   254,  -469,
    1010,    32,    52,  -469,   142,  -469,  3272,  -469,  -469,   145,
     -44,  -469,  -469,  -469,  -469,   192,  -469,  -469,   254,  -469,
    -469,    58,  -469,    55,   254,  -469,  -469,  -469,  -469,  -469,
    -469,  -469,  -469,   233,  -469,  -469,   241,   332,  -469,  -469,
    -469,  -469,  -469,   335,    -1,  3312,  -469,   218,  3192,  -469,
    -469,  -469,  -469,  3352,   -44,  -469,  -469,   254,  -469,  -469,
    -469,    74,   344,   346,   205,  -469,    65,    74,   353,   359,
     361,   233,   241,  -469,  -469,  -469,   373,   363,  3312,  3232,
    -469,  -469,  -469,  -469,     8,  -469,  -469,    81,   384,  -469,
    -469,   387,   -44,  -469,  1049,   340,  -469,   398,  2853,  -469,
    -469,  -469,  -469,    74,   246,    74,  -469,   419,  -469,    81,
    -469,  -469,  -469,  -469,  -469,   422,   424,  -469,  1166,  -469,
    -469,   313,  -469,   340,   433,   316,  -469,  -469,  -469,  -469,
    2762,    10,  -469,  -469,  -469,  -469,  -469,  -469,  1349,  -469,
     321,  3075,  3075,  3075,  3075,  3075,  3075,  -469,   134,  -469,
    -469,   323,   441,  -469,  -469,  2704,  -469,  3076,   230,  -469,
    -469,  -469,  -469,  -469,  -469,  -469,   101,   300,   317,   -19,
     282,   319,   352,   365,   355,    71,  -469,  -469,  -469,  3361,
    -469,  -469,  -469,  -469,  -469,  2304,   424,  -469,  -469,  -469,
    2371,  -469,  -469,   461,   -44,   465,  -469,  1349,   262,  1528,
     463,  -469,   467,  2853,   474,   474,   478,   401,    28,  -469,
    -469,  -469,  -469,  -469,  -469,  -469,  -469,  3075,  2865,   402,
    3075,  -469,  -469,  3075,  3075,  3075,  3075,  3075,  3075,  3075,
    3075,  1349,  3075,  3075,  3075,  3075,  3075,  3075,  3075,  3075,
    3075,  3075,  3075,   367,  -469,  -469,  -469,  -469,  -469,  -469,
    -469,  -469,  -469,  -469,  -469,  -469,  3075,  3075,   -28,   485,
     486,   489,   494,  -469,    -5,  3075,  2611,   373,  -469,   374,
    -469,  1268,  -469,   340,    19,  -469,  2036,  -469,  -469,   375,
    -469,  -469,  -469,  -469,  -469,   378,  -469,  -469,  -469,  -469,
    -469,  -469,  -469,  -469,  -469,  -469,  -469,  -469,    34,    37,
     230,   296,   312,  -469,  -469,  -469,  -469,   502,    29,  2103,
    2170,  -469,  -469,  -469,   506,  3075,   271,  2641,   304,   911,
    -469,  -469,    36,  3075,   508,  -469,   508,  2905,   511,   509,
    -469,    24,  -469,   512,   515,  -469,  -469,  -469,   101,   101,
     300,   300,   300,   332,  -469,   317,   317,   317,   317,   -19,
     -19,   282,   319,   352,   365,   355,  3075,  -469,   518,   396,
    -469,  2554,  3075,  3075,  3075,  2438,   400,  -469,   403,  -469,
     405,   216,   521,  2438,    23,    31,  -469,    14,    28,   323,
      18,   407,  2678,  -469,  -469,  -469,  -469,  2988,  3017,  -469,
    2237,  -469,  -469,  -469,   523,  3075,   911,  -469,  -469,  2822,
     528,  2641,  -469,   530,   530,  -469,    26,  3029,  -469,  -469,
    3075,  3047,  -469,  -469,  -469,  -469,   410,  -469,  -469,  -469,
     412,   532,   534,   537,   481,  -469,  -469,  -469,   544,   373,
     216,  -469,  -469,  3075,  -469,  -469,  1268,  -469,   425,    39,
     426,    44,  -469,  -469,  -469,  -469,  -469,  -469,  -469,  -469,
    -469,  -469,  -469,  -469,    48,  -469,  -469,    54,   427,  3075,
     431,  2525,   545,  -469,   373,   552,  1349,  -469,  -469,  -469,
     555,  -469,  -469,   437,  -469,   440,  -469,  -469,  -469,  -469,
    3075,   443,  -469,  3075,  -469,   558,  -469,  2487,  -469,  3075,
     565,  -469,  -469,  -469,  -469,   449,   447,   448,  -469,  -469,
      27,   569,   570,  -469,   450,  -469,  -469,   539,  -469,  -469,
    -469,  -469,   574,   373,  2438,  -469,  -469,   578,   412,   660,
     974,   451,   459,  3075,    70,  -469,  1862,  -469,  2554,  3075,
     585,  2487,  -469,   553,   466,  -469,  -469,  2438,  -469,  -469,
     587,  -469,   589,  1254,  -469,  -469,   473,  -469,  -469,  1969,
    -469,  2304,  -469,   477,  -469,   592,  3075,  -469,  -469,  -469,
    -469,  -469,  2438,  2438,  -469,  2438,  -469,  -469,   597,  -469,
    -469,  -469,  -469,  3075,   479,  -469,   601,  2438,  -469,  -469,
    -469,  -469,  2438,  -469,  2438,  2438,  -469,  -469,   487,  -469,
    3075,  2487,  -469,  -469,  -469,  -469,  -469,  -469,  -469,  -469,
    2438,  1653,   488,   491,  -469,  -469,  2487,  -469,  -469,  -469,
    -469,  -469,  -469,   604,  1746,  1813,   493,   575,  -469,  -469,
    2487,  -469,  -469,   614,  -469,   615,  1929,  -469,  -469,  -469,
    2487,  2487,  -469,  2487,  -469,  -469,   616,  2487,  -469,  -469,
    -469,  2487,  -469,  2487,  2487,  -469,  -469,  -469,  -469,  -469,
    -469,  -469,  -469,  2487,  -469,  -469,  -469,  -469,  -469,  -469
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
      60,    86,     0,    89,    84,    83,     0,    82,    90,    87,
       0,    85,     0,    91,    88,    79,     0,     2,    66,    67,
      61,    68,    73,    74,    70,     0,    80,    77,    78,    58,
       0,    56,    57,     0,     0,    92,     0,     1,    65,    69,
      71,    62,    63,     0,     0,    81,    72,     0,    75,     0,
       3,     0,     0,   166,     3,     0,     0,     0,     0,   100,
      64,     0,     0,    59,     0,   170,     0,    52,   167,    50,
       0,   165,   107,   105,   103,   102,    51,   101,     0,    98,
      99,     0,   164,     0,     0,    96,    76,    38,    47,    41,
      43,    42,    45,     0,    44,    46,     0,    35,    37,    39,
      40,    36,    48,    49,    50,     0,   175,     0,     0,   171,
     173,   174,   168,     0,     0,    97,   163,     0,    94,    95,
     137,   133,     0,   121,     0,   117,   119,   129,     0,     0,
       0,     0,     0,   176,     4,   172,    85,    56,     0,     0,
     108,   110,   113,   114,     0,   111,   112,     0,     0,   104,
      93,     0,     0,   132,     0,     0,   116,     0,     0,   128,
      53,    55,    54,   131,     0,   127,   169,     3,   147,     0,
       4,   109,   146,   125,   145,     3,     0,   151,     0,   136,
     143,   142,   135,     0,     0,   138,   139,   121,   118,   122,
       0,     3,    29,    30,    32,    33,    31,    34,     0,   282,
       0,     0,     0,     0,     0,     0,     0,   281,   312,   120,
     124,   311,   279,   284,   280,   285,   286,   287,   324,   313,
     314,   332,   317,   318,   321,   327,   336,   339,   343,   349,
     352,   354,   356,   358,   360,   362,   364,   382,   365,     0,
     123,   130,   115,   126,   183,     0,     0,   149,   106,   158,
       0,   150,   153,     0,     0,   141,   134,     0,     0,   312,
       0,   180,     0,     0,     0,    51,     0,     0,   312,   285,
     287,   319,   320,   322,   323,   326,   325,     0,     0,     0,
       0,   315,   316,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   374,   375,   371,   372,   373,   379,
     381,   380,   376,   377,   378,   370,     0,     0,     0,     0,
       0,     0,     0,    13,     0,     0,     0,     0,    10,    58,
     213,    28,   224,     0,   367,   202,     0,   185,   187,     0,
     188,   191,   203,   192,   204,     0,   193,   194,   205,   195,
     206,   196,   207,   208,   209,   211,   210,   212,   284,   286,
       0,   220,   221,   218,   219,   217,   148,   282,     0,     0,
       0,   152,   144,   140,     0,     0,     0,     0,     0,   283,
     179,   181,     0,     0,   292,   296,   294,     0,   302,     0,
     303,     0,   290,   301,     0,   333,   334,   335,   337,   338,
     340,   341,   342,     0,   348,   346,   347,   345,   344,   350,
     351,   353,   355,   357,   359,   361,     0,   366,     0,     0,
     266,    15,     0,     0,     0,     0,     0,   264,     0,   268,
       0,     0,     0,     0,    58,     0,    23,    26,     0,     0,
      27,   190,     0,     4,   186,   189,   216,     0,     0,     4,
       0,     4,   299,   328,     0,     0,     0,   330,     4,     0,
       0,     0,   297,   293,   295,   288,     0,     0,   309,   304,
       0,     0,   310,    20,   283,   267,     0,   260,   262,    15,
     259,     0,     0,     0,     0,   265,   270,   269,     0,     0,
     272,   275,   273,     0,   214,    22,    28,   184,     0,     0,
       0,     0,   156,     4,   157,   300,   329,   331,   178,     4,
     182,   298,   289,   307,     0,   291,   305,     0,     0,    16,
       0,     0,     0,     5,     0,     0,     0,   278,   276,   274,
       0,    24,   160,     0,   162,     0,   155,   177,   308,   306,
       0,     0,    16,    16,   263,     3,   228,     0,   271,     0,
       0,    11,   159,   161,    21,     0,     0,     0,    16,   229,
       0,     0,     0,    10,    58,     6,     7,   191,   198,   199,
     200,   201,     0,     0,     0,   363,    17,     0,   261,     0,
       0,     0,     0,     0,     0,   233,     0,   236,    15,     0,
       0,     0,   225,     0,     0,   277,    12,     0,    17,    17,
       0,    17,     0,     0,   239,   383,     0,     4,   234,     0,
       4,   235,   237,     0,    15,     0,     0,   215,     8,    14,
     240,    18,     0,     0,    17,     0,    17,    17,     0,   238,
     230,     4,   231,    16,     0,     5,     0,     0,   242,   243,
      18,    18,     0,    18,     0,     0,    17,   232,     0,    16,
      16,     0,    11,     9,   244,   245,    18,   247,    18,    18,
       0,     0,     0,     0,    16,     7,     0,   226,   246,   248,
     249,    18,    17,     0,     0,     0,     0,     0,    12,   250,
       0,    17,    17,     0,    17,     0,     0,     8,   241,    18,
       0,     0,    17,     0,    17,    17,     0,     0,   251,    18,
      18,     0,    18,     0,     0,    17,     9,   252,   253,    18,
     255,    18,    18,     0,   227,   254,   256,   257,    18,   258
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -469,  -469,   -52,  -133,   -11,  -469,   -36,   -57,   -73,    72,
     -15,   -38,  -469,  -469,  -468,  -329,   -56,  2514,  -469,  -469,
    -469,  -469,  -469,   146,  -318,   -46,  -104,  -469,  -469,  -469,
     350,   -27,   -82,   150,  -469,    -2,    80,  -469,  -469,   623,
     287,  -469,   212,  -469,  -469,   305,   267,    79,   600,  -469,
     588,   188,  -469,  -469,   327,  -469,   513,  -469,   -30,  -123,
     492,   472,  -251,  -469,    85,    90,  -469,   480,  -469,  -256,
     320,  -469,  -469,  -469,  -469,   519,  -469,  -119,  -469,  -469,
     595,     4,  -469,   551,  -469,  -469,  -469,  -469,  -130,  -224,
    -331,  -469,  -413,  1151,    57,  -194,  -469,  -469,  -469,  -469,
    -414,  -469,  -469,  -469,  -469,  -469,  -469,    77,    78,  -330,
    -469,  -469,  -469,  -469,  -469,    75,  -257,  -411,  -469,  -469,
    -469,  -469,  -469,  -469,  -469,   174,   175,  -316,  -469,   177,
     -85,  -469,   415,   -83,  -242,  1354,     9,  1407,   309,   471,
     603,  -129,   771,   903,  -343,  -469,   129,   147,   106,   124,
     370,   382,   385,   386,   388,  -469,   148,   376,  -110,  -469,
    -469,   -68,  -469
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    16,    66,   166,   547,   592,   593,   637,   667,   432,
     574,   620,   425,   638,   476,   541,   597,   639,   303,   518,
     575,   332,   435,   436,   207,   333,    97,    98,    99,   100,
     101,   102,    77,    68,   103,   208,    31,    32,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    36,    27,
      57,    58,    75,   113,    59,   139,   140,   141,   106,   124,
     125,   126,   209,   143,   107,   121,   122,   184,   185,   186,
     153,   181,   173,   145,   146,   147,   148,   177,   369,    28,
      52,    53,   108,   109,   110,   111,   210,   382,   335,   611,
     337,   338,   339,   340,   566,   341,   342,   343,   568,   344,
     345,   346,   347,   569,   348,   546,   584,   585,   586,   587,
     349,   570,   350,   351,   571,   479,   577,   578,   352,   353,
     354,   355,   356,   357,   490,   491,   492,   211,   212,   213,
     391,   214,   384,   385,   376,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   365,   239,
     316,   392,   606
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      30,   373,    73,   130,    33,   444,   168,   478,   477,   164,
     480,   520,   381,   437,   174,   439,   167,   378,  -281,   261,
      96,   336,  -286,   442,    67,   278,   370,   291,    67,    76,
     -25,   469,   277,   512,   278,   448,   457,   248,   495,   444,
      50,  -223,    29,    67,  -222,   458,   533,    34,   238,    69,
     247,   535,   582,    69,    69,   538,    71,   251,   419,   132,
      54,   539,    96,    54,   104,    82,    50,    96,    69,   157,
     180,   583,   271,   272,   273,   274,   275,   276,   151,   607,
     238,   426,    51,   142,    37,   116,   258,    67,    55,   175,
     240,    55,   132,    96,   264,   582,   292,   293,   420,    35,
     294,   295,    56,   104,    45,   -50,   104,   544,   183,   142,
     -25,   104,    69,   507,   583,   245,   266,   152,   496,   444,
     613,   427,   260,   250,   152,    76,    46,   366,    47,    47,
    -312,  -312,   183,    61,   172,   262,   104,   104,   277,   263,
     278,   478,   463,  -281,   464,   450,   634,  -286,    47,   470,
      69,   470,   104,   238,   395,   396,   397,    47,   267,  -223,
    -223,   459,  -222,  -222,   470,   478,   478,   238,   238,   470,
     238,   265,   372,   470,   478,   477,   104,   480,   437,   470,
     439,   302,   158,    70,    45,    63,   127,   403,   259,   478,
     283,   284,   285,   137,   -19,   240,    69,   431,   144,   268,
     268,   268,   268,   268,   268,    74,   238,   238,   510,   389,
     441,   183,   394,   556,   557,   238,   238,    45,   137,   137,
     112,   163,   165,    48,   144,    63,    49,    76,    64,   581,
      39,    65,  -367,  -367,  -367,  -367,  -367,  -367,  -367,  -367,
    -367,  -367,  -367,   334,    72,    78,   453,   478,   334,   418,
      84,  -367,    69,    39,   359,   104,   612,   428,   430,   359,
     478,   478,    54,    47,   149,   488,   374,   238,    86,   375,
     550,   117,   478,   238,    47,   454,   489,   238,   455,   612,
     444,   268,   268,   268,   268,   268,   268,   268,   268,   104,
     268,   268,   268,   268,   268,   268,   268,   268,   268,   268,
     268,   462,   466,   462,   648,    38,   238,    42,   454,   389,
     497,   456,   238,   238,   238,   460,   502,   114,   504,   120,
     662,   663,   600,   602,    40,   508,   506,   123,    60,   438,
     155,   156,   238,   105,   334,   676,   128,   238,   238,   129,
     440,   281,   282,    40,   133,   359,   628,    40,   473,   238,
     154,   238,  -137,   567,   481,   482,   483,   238,   160,   527,
     238,   238,   499,   501,   161,    40,   162,   334,   334,  -154,
     536,   155,   242,   268,   389,   105,   537,   268,   359,   359,
     138,   167,   514,   238,    79,    80,   517,   286,   287,    85,
     178,   240,   179,   460,   548,   296,   297,   567,   405,   406,
     407,   408,   515,   189,   673,   115,   138,  -313,  -313,   238,
     118,   119,   288,   289,   290,   398,   399,   683,   685,   334,
     409,   410,   358,  -314,  -314,   530,   187,   358,   244,   696,
     359,   249,   175,   238,   359,   400,   401,   402,   254,   238,
     256,   257,   359,   595,   150,   280,   299,   159,   334,   298,
     267,   542,   279,   268,   268,   317,   576,   567,   300,   359,
     192,   193,   194,   195,   301,   196,   197,   176,   371,   157,
     379,   198,   567,   238,   630,   558,   380,   632,   383,   238,
     183,   572,   199,   241,   387,   243,   567,   388,   393,   246,
     416,   421,   422,   560,   438,   423,   567,   567,   647,   567,
     424,   445,   433,   567,   446,   440,   238,   567,   447,   567,
     567,   452,   461,   358,   468,   605,   200,   467,   471,   567,
     472,   615,   475,   238,   104,   474,   485,   493,   505,   486,
     359,   487,   155,   511,   454,    29,   519,   521,   268,   522,
     238,   523,   622,   623,   524,   625,   358,   358,   636,   525,
     526,   532,   534,   545,   360,   540,   359,   543,   549,   360,
     203,   204,   551,   552,   359,   649,   553,   559,   642,   555,
     644,   645,   573,   579,   580,   588,   589,   603,   591,  -197,
     331,   594,   664,   359,   334,   598,   334,   604,   359,   359,
     660,   616,   619,   618,   624,   359,   626,   359,   358,   635,
     359,   629,   358,   633,   646,   650,   359,   334,   652,   334,
     358,   681,   359,   661,   674,   687,   680,   675,   359,   686,
     359,   692,   694,   705,   651,   690,   691,   358,   693,   677,
     697,   359,   359,   714,   359,   590,   701,   666,   703,   704,
     688,   404,   531,    41,    62,   360,   359,   188,   617,   713,
      83,   359,   171,   359,   359,   255,    81,   169,   253,   135,
     359,   608,   609,   614,   528,   529,   317,   599,   411,   359,
     359,   192,   193,   194,   195,   359,   196,   197,   360,   360,
     386,   412,   198,   359,   359,   413,     0,   414,   554,   359,
     415,     0,   417,   199,     0,   359,     0,     0,   358,   359,
     359,     0,   359,     0,     0,     0,   359,     0,   665,     0,
     359,     0,   359,   359,     0,     0,   361,     0,     0,     0,
       0,   361,   359,   678,   358,     0,     0,   200,     0,     0,
     360,     0,   358,     0,   360,     0,     0,   689,     0,     0,
       0,     0,   360,     0,     0,     0,    29,   699,   700,     0,
     702,   358,     0,     0,   706,     0,   358,   358,   709,   360,
     711,   712,     0,   358,     0,   358,     0,     0,   358,     0,
     718,   203,   204,     0,   358,     0,     0,     0,     0,     0,
     358,     0,     0,     0,     0,     0,   358,     0,   358,     0,
       0,   331,     0,     0,     0,     1,     0,     0,     0,   358,
     358,     0,   358,     2,     3,     0,     0,   361,     4,     0,
       0,     0,     0,     5,   358,     0,     0,     6,     7,   358,
       0,   358,   358,     0,     8,     0,     0,     0,   358,     0,
     360,     9,    10,    11,     0,    12,     0,   358,   358,    13,
     361,   361,    14,   358,     0,     0,     0,     0,   362,     0,
       0,   358,   358,   362,     0,     0,   360,   358,     0,     0,
       0,     0,     0,   358,   360,     0,     0,   358,   358,     0,
     358,     0,     0,     0,   358,     0,     0,     0,   358,     0,
     358,   358,     0,   360,     0,     0,     0,     0,   360,   360,
     358,     0,   361,     0,     0,   360,   361,   360,     0,     0,
     360,     0,    15,     0,   361,     0,   360,     0,     0,     0,
       0,     0,   360,     0,     0,     0,     0,   190,   360,     0,
     360,   361,   192,   193,   194,   195,     0,   196,   197,     0,
       0,   360,   360,   198,   360,     0,     0,     0,     0,   362,
       0,     0,     0,     0,   199,     0,   360,     0,     0,     0,
       0,   360,     0,   360,   360,     0,     0,     0,     0,     0,
     360,     0,     0,     0,     0,     0,     0,     0,     0,   360,
     360,     0,   362,   362,     0,   360,     0,     0,   200,     0,
     317,   601,     0,   360,   360,   192,   193,   194,   195,   360,
     196,   197,   361,     0,     0,   360,   198,    29,     0,   360,
     360,     0,   360,     0,     0,     0,   360,   199,     0,     0,
     360,     0,   360,   360,     0,     0,   363,     0,   361,     0,
       0,   363,   360,     0,   362,     0,   361,     0,   362,     1,
       0,     0,   205,   206,     0,     0,   362,     0,     3,     0,
       0,   200,     4,     0,     0,   361,     0,     5,     0,     0,
     361,   361,     7,   362,     0,     0,   182,   361,     8,   361,
      29,     0,   361,     0,     0,     9,    10,    11,   361,    12,
       0,     0,     0,    13,   361,     0,    14,     0,    87,     0,
     361,     0,   361,     0,    88,   203,   204,     0,    89,     0,
       0,     0,     0,   361,   361,     0,   361,     0,     0,     0,
      90,    91,     0,    92,     0,   331,     0,   363,   361,     0,
      94,     0,     0,   361,    95,   361,   361,     0,     0,     0,
       0,     0,   361,     0,   362,     0,     0,     0,     0,     0,
       0,   361,   361,     0,     0,    29,    15,   361,     0,     0,
     363,   363,     0,     0,     0,   361,   361,     0,   364,     0,
     362,   361,     0,   364,     0,     0,     0,   361,   362,     0,
       0,   361,   361,     0,   361,     0,     0,     0,   361,     0,
       0,     0,   361,   252,   361,   361,     0,   362,     0,     0,
       0,     0,   362,   362,   361,     0,     0,     0,     0,   362,
       0,   362,   363,     0,   362,    87,   363,     0,     0,     0,
     362,    88,     0,     0,   363,    89,   362,     0,     0,     0,
       0,     0,   362,     0,   362,     0,     0,    90,    91,     0,
      92,   363,     0,     0,     0,   362,   362,    94,   362,     0,
       0,    95,     0,     0,     0,     0,     0,     0,     0,   364,
     362,     0,     0,     0,     0,   362,     0,   362,   362,     0,
       0,     0,    29,     0,   362,     0,     0,     0,     0,     0,
     317,   627,     0,   362,   362,   192,   193,   194,   195,   362,
     196,   197,   364,   364,   317,     0,   198,   362,   362,   192,
     193,   194,   195,   362,   196,   197,     0,   199,     0,   362,
     198,     0,   363,   362,   362,     0,   362,     0,     0,     0,
     362,   199,     0,     0,   362,     0,   362,   362,     0,     0,
       0,     0,     0,     0,     0,     0,   362,     0,   363,     0,
       0,   200,     0,     0,   364,     0,   363,     0,   364,     0,
       0,     0,     0,     0,     0,   200,   364,     0,     0,     0,
      29,     0,     0,     0,     0,   363,     0,     0,     0,     0,
     363,   363,     0,   364,   434,     0,     0,   363,     0,   363,
       0,     0,   363,     0,     0,   203,   204,     0,   363,     0,
       0,     0,     0,     0,   363,     0,     0,     0,    87,     0,
     363,     0,   363,     0,    88,   331,     0,     0,    89,     1,
       0,     0,     0,   363,   363,     0,   363,     0,     3,     0,
      90,    91,     4,    92,     0,     0,     0,     5,   363,     0,
      94,     6,     7,   363,    95,   363,   363,     0,     8,     0,
       0,     0,   363,     0,   364,     9,    10,    11,     0,    12,
       0,   363,   363,    13,     0,    29,    14,   363,     0,     0,
       0,     0,     0,     0,     0,   363,   363,     0,     0,     0,
     364,   363,     0,     0,     0,     0,     0,   363,   364,     0,
       0,   363,   363,     0,   363,     0,     0,     0,   363,     0,
       0,     0,   363,     0,   363,   363,     0,   364,     0,     0,
       0,     0,   364,   364,   363,     0,     0,     0,     0,   364,
       0,   364,     0,     0,   364,     0,    15,     0,     0,     0,
     364,     0,     0,     0,     0,     0,   364,     0,     0,     0,
       0,     0,   364,     0,   364,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   364,   364,     0,   364,     0,
       0,     0,   377,     0,   278,     0,     0,     0,     0,     0,
     364,     0,     0,     0,     0,   364,     0,   364,   364,     0,
       0,     0,     0,     0,   364,   269,   269,   269,   269,   269,
     269,     0,     0,   364,   364,     0,     0,     0,     0,   364,
       0,     0,     0,     0,     0,     0,   484,   364,   364,     0,
       0,     0,     0,   364,   494,     0,     0,     0,     0,   364,
       0,     0,     0,   364,   364,     0,   364,     0,     0,     0,
     364,     0,     0,     0,   364,     0,   364,   364,   270,   270,
     270,   270,   270,   270,     0,     0,   364,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  -367,  -367,  -367,  -367,
    -367,  -367,  -367,  -367,  -367,  -367,  -367,   269,   269,   269,
     269,   269,   269,   269,   269,  -367,   269,   269,   269,   269,
     269,   269,   269,   269,   269,   269,   269,    47,     0,   317,
     672,     0,     0,     0,   192,   193,   194,   195,     0,   196,
     197,     0,     0,     0,     0,   198,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   269,   199,     0,     0,     0,
     270,   270,   270,   270,   270,   270,   270,   270,   565,   270,
     270,   270,   270,   270,   270,   270,   270,   270,   270,   270,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     200,     0,     0,     0,     0,   596,     0,     0,     0,   269,
       0,     0,     0,   269,     0,     0,     0,     0,   270,    29,
       0,     0,   494,     0,     0,     0,     0,     0,   621,     0,
       0,     0,   317,   682,     0,     0,     0,   192,   193,   194,
     195,     0,   196,   197,   203,   204,     0,     0,   198,     0,
       0,     0,     0,   640,   641,     0,   643,     0,     0,   199,
       0,     0,   270,     0,   331,     0,   270,     0,   653,     0,
       0,     0,     0,   656,     0,   658,   659,     0,     0,     0,
       0,     0,   565,     0,     0,     0,     0,     0,     0,   269,
     269,   671,     0,   200,     0,     0,     0,   596,     0,   317,
     684,     0,     0,     0,   192,   193,   194,   195,     0,   196,
     197,   621,    29,     0,     0,   198,     0,     0,     0,     0,
       0,   640,   641,     0,   643,     0,   199,     0,   653,     0,
     269,     0,   656,     0,   658,   659,     0,   203,   204,     0,
       0,     0,   270,   270,   671,     0,     0,     0,   317,     0,
     167,   610,     0,   192,   193,   194,   195,   331,   196,   197,
     200,     0,   318,   319,   198,   320,     0,   582,   321,     0,
     322,    87,   323,     0,   269,   199,   324,    88,     0,    29,
     325,    89,     0,   270,     0,     0,   583,     0,     0,   326,
       0,     0,     0,    90,    91,   327,    92,     0,     0,     0,
       0,     0,     0,    94,   203,   204,     0,    95,     0,   200,
     328,     0,     0,     0,     0,   317,   695,     0,     0,     0,
     192,   193,   194,   195,   331,   196,   197,   270,   329,     0,
       0,   198,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   199,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   203,   204,   317,     0,   167,   631,     0,
     192,   193,   194,   195,     0,   196,   197,     0,   330,   318,
     319,   198,   320,   331,   582,   321,   200,   322,    87,   323,
       0,     0,   199,   324,    88,     0,     0,   325,    89,     0,
       0,     0,     0,   583,     0,    29,   326,     0,     0,     0,
      90,    91,   327,    92,     0,     0,     0,     0,     0,     0,
      94,     0,     0,     0,    95,     0,   200,   328,     0,     0,
     203,   204,   317,     0,   167,   443,     0,   192,   193,   194,
     195,     0,   196,   197,     0,   329,   318,   319,   198,   320,
     331,     0,   321,     0,   322,    87,   323,     0,     0,   199,
     324,    88,     0,     0,   325,    89,     0,     0,     0,     0,
     203,   204,     0,   326,     0,     0,     0,    90,    91,   327,
      92,     0,     0,     0,     0,   330,     0,    94,     0,     0,
     331,    95,     0,   200,   328,     0,     0,     0,     0,   317,
       0,   167,   449,     0,   192,   193,   194,   195,     0,   196,
     197,     0,   329,   318,   319,   198,   320,     0,     0,   321,
       0,   322,    87,   323,     0,     0,   199,   324,    88,     0,
       0,   325,    89,     0,     0,     0,     0,   203,   204,     0,
     326,     0,     0,     0,    90,    91,   327,    92,     0,     0,
       0,     0,   330,     0,    94,     0,     0,   331,    95,     0,
     200,   328,     0,     0,     0,     0,   317,     0,   167,   451,
       0,   192,   193,   194,   195,     0,   196,   197,     0,   329,
     318,   319,   198,   320,     0,     0,   321,     0,   322,    87,
     323,     0,     0,   199,   324,    88,     0,     0,   325,    89,
       0,     0,     0,     0,   203,   204,     0,   326,     0,     0,
       0,    90,    91,   327,    92,     0,     0,     0,     0,   330,
       0,    94,     0,     0,   331,    95,     0,   200,   328,     0,
       0,     0,     0,   317,     0,   167,   503,     0,   192,   193,
     194,   195,     0,   196,   197,     0,   329,   318,   319,   198,
     320,     0,     0,   321,     0,   322,    87,   323,     0,     0,
     199,   324,    88,     0,     0,   325,    89,     0,     0,     0,
       0,   203,   204,     0,   326,     0,     0,     0,    90,    91,
     327,    92,     0,     0,     0,     0,   330,     0,    94,     0,
       0,   331,    95,     0,   200,   328,     0,     0,     0,     0,
     317,     0,   167,     0,     0,   192,   193,   194,   195,     0,
     196,   197,     0,   329,   318,   319,   198,   320,     0,     0,
     321,     0,   322,    87,   323,     0,     0,   199,   324,    88,
       0,     0,   325,    89,     0,     0,     0,     0,   203,   204,
       0,   326,     0,     0,     0,    90,    91,   327,    92,     0,
       0,     0,     0,   330,     0,    94,     0,     0,   331,    95,
       0,   200,   328,     0,     0,     0,     0,   317,     0,   167,
       0,     0,   192,   193,   194,   195,     0,   196,   197,     0,
     329,   318,   319,   198,   320,     0,     0,   321,     0,   322,
      87,   323,     0,     0,   367,   324,    88,     0,     0,   325,
      89,     0,     0,     0,     0,   203,   204,     0,   326,     0,
       0,     0,    90,    91,   327,    92,     0,     0,     0,     0,
     330,     0,    94,     0,     0,   331,    95,     0,   368,   328,
       0,     0,     0,     0,   317,     0,   167,     0,     0,   192,
     193,   194,   195,     0,   196,   197,     0,   329,   318,   319,
     198,   320,     0,     0,   321,     0,   322,     0,   323,     0,
       0,   199,   324,     0,     0,     0,   325,     0,     0,     0,
       0,     0,   203,   204,     0,   326,     0,     0,     0,     0,
       0,   327,     0,   317,     0,   167,     0,   330,   192,   193,
     194,   195,   331,   196,   197,   200,   328,   318,   561,   198,
     320,     0,     0,   562,     0,   322,     0,   323,     0,     0,
     199,   324,     0,     0,   329,   325,     0,     0,     0,     0,
       0,   317,     0,     0,   326,     0,   192,   193,   194,   195,
     327,   196,   197,     0,     0,     0,     0,   198,     0,   203,
     204,     0,     0,     0,   200,   563,     0,     0,   199,     0,
     317,     0,     0,     0,   330,   192,   193,   194,   195,   331,
     196,   197,     0,   564,     0,     0,   198,     0,     0,     0,
       0,     0,     0,    87,     0,     0,     0,   199,     0,    88,
       0,     0,   200,    89,     0,     0,     0,     0,   203,   204,
       0,     0,     0,     0,     0,    90,    91,     0,    92,     0,
       0,    29,     0,   330,     0,    94,     0,   190,   331,    95,
       0,   200,   192,   193,   194,   195,     0,   196,   197,     0,
       0,     0,     0,   198,     0,     0,   203,   204,     0,     0,
      29,     0,     0,     0,   199,     0,   452,   190,     0,     0,
       0,     0,   192,   193,   194,   195,   331,   196,   197,     0,
       0,     0,     0,   198,     0,   203,   204,     0,     0,     0,
       0,     0,     0,     0,   199,     0,     0,     0,   200,     0,
       0,     0,     0,   162,   190,   331,     0,     0,     0,   192,
     193,   194,   195,     0,   196,   197,     0,    29,   201,   202,
     198,     0,     0,     0,     0,     0,     0,     0,   200,     0,
       0,   199,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   203,   204,     0,     0,     0,    29,   201,   202,
       0,     0,   205,   206,     0,     0,     0,   429,     0,     0,
       0,     0,     0,     0,     0,   200,     0,     0,     0,     0,
       0,     0,   203,   204,     0,     0,     0,     0,     0,     0,
       0,     0,   205,   206,    29,   201,   202,     0,   190,     0,
       0,     0,     0,   192,   193,   194,   195,     0,   196,   197,
       0,     0,     0,     0,   198,     0,     0,     0,     0,   203,
     204,    87,     0,     0,     0,   199,     0,    88,     0,   205,
     206,    89,  -368,  -368,  -368,  -368,  -368,  -368,  -368,  -368,
    -368,  -368,  -368,    90,    91,     0,    92,     0,     0,     0,
       0,  -368,     0,    94,     0,     0,     0,    95,   190,   200,
     191,   509,     0,   192,   193,   194,   195,     0,   196,   197,
       0,     0,     0,     0,   198,     0,     0,     0,    29,   201,
     202,     0,     0,     0,     0,   199,     0,     0,     0,   190,
       0,   191,     0,     0,   192,   193,   194,   195,     0,   196,
     197,   190,   390,   203,   204,   198,   192,   193,   194,   195,
       0,   196,   197,   205,   206,     0,   199,   198,     0,   200,
       0,     0,     0,     0,     0,     0,     0,     0,   199,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    29,   201,
     202,   190,   465,     0,     0,     0,   192,   193,   194,   195,
     200,   196,   197,     0,     0,     0,     0,   198,     0,     0,
       0,     0,   200,   203,   204,     0,     0,     0,   199,    29,
     201,   202,     0,   205,   206,     0,     0,     0,     0,     0,
       0,    29,   201,   202,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   203,   204,     0,     0,     0,     0,
       0,     0,   200,     0,   205,   206,   203,   204,     0,     0,
       0,     0,     0,     0,     0,     0,   205,   206,     0,     0,
       0,    29,   201,   202,   190,   498,     0,     0,     0,   192,
     193,   194,   195,     0,   196,   197,     0,     0,     0,     0,
     198,     0,     0,     0,     0,     0,   203,   204,     0,     0,
       0,   199,     0,   190,   500,     0,   205,   206,   192,   193,
     194,   195,     0,   196,   197,   190,   513,     0,     0,   198,
     192,   193,   194,   195,     0,   196,   197,     0,     0,     0,
     199,   198,     0,   190,   516,   200,     0,     0,   192,   193,
     194,   195,   199,   196,   197,     0,     0,     0,     0,   198,
       0,     0,     0,     0,    29,   201,   202,     0,     0,     0,
     199,   190,     0,     0,   200,     0,   192,   193,   194,   195,
       0,   196,   197,     0,     0,     0,   200,   198,     0,   203,
     204,     0,     0,    29,   201,   202,     0,     0,   199,   205,
     206,     0,     0,     0,   200,    29,   201,   202,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   203,   204,
       0,     0,     0,    29,   201,   202,     0,     0,   205,   206,
     203,   204,   200,     0,     0,     0,     0,     0,     0,     0,
     205,   206,     0,     0,   654,   655,     0,   657,   203,   204,
       0,    29,   201,   202,     0,     0,     0,     0,   205,   206,
     668,     0,   669,   670,  -369,  -369,  -369,  -369,  -369,  -369,
    -369,  -369,  -369,  -369,  -369,   679,   203,   204,     0,     0,
       0,     0,     0,  -369,     0,     0,   205,   206,     0,     0,
       0,   134,     0,   698,     0,     0,     0,     0,     0,     0,
       0,     1,     0,   707,   708,     0,   710,     0,     0,     0,
       3,    87,     0,   715,     4,   716,   717,    88,     0,     5,
       0,    89,   719,     0,     7,     0,     0,     0,     0,     0,
       8,   170,     0,    90,    91,     0,    92,     9,     0,    11,
      93,     1,     0,    94,     0,    13,     0,    95,    14,     0,
       3,    87,     0,     0,     4,     0,     0,    88,     0,     5,
       0,    89,     0,     0,     7,     0,     0,     0,    29,     0,
       8,     0,     0,    90,    91,     0,    92,     9,     0,   136,
      93,     1,     0,    94,     0,    13,     0,    95,    14,     0,
       3,    87,     0,     0,     4,     0,     0,    88,     0,     5,
       0,    89,     0,     0,     7,     0,     0,     0,    29,     0,
       8,     0,     0,    90,    91,     0,    92,     9,     0,    11,
      93,     1,     0,    94,     0,    13,     0,    95,    14,     0,
       3,    87,     0,     0,     4,     0,     0,    88,     0,     5,
       0,    89,     0,     0,     7,     0,     0,     0,    29,     0,
       8,     0,     0,    90,    91,     0,    92,     9,     0,    11,
     131,     1,     0,    94,     0,    13,     0,    95,    14,     0,
       3,    87,     0,     0,     4,     0,     0,    88,     0,     5,
       0,    89,     0,     0,     7,     0,     0,     0,    29,     0,
       8,     0,     0,    90,    91,     0,    92,     9,     0,   136,
      93,     1,     0,    94,     0,    13,     0,    95,    14,     0,
       3,     0,     0,     0,     4,     0,     0,     0,     0,     5,
       0,     0,     0,     0,     7,     0,     0,     0,    29,     0,
       8,     0,     0,     0,     0,     0,     0,     9,    43,    11,
       0,    44,     0,     0,     0,    13,     0,     0,    14,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
       0,     0,     0,     0,     0,     0,     0,     0,   315
};

static const yytype_int16 yycheck[] =
{
       2,   257,    54,     4,     6,   336,   136,   421,   421,   132,
     421,   479,   263,   331,   144,   331,     8,   259,     4,     9,
      66,   245,     4,     4,    51,     6,   250,    46,    55,    56,
       7,     7,     4,     7,     6,     6,   379,   170,     7,   370,
       8,     7,    86,    70,     7,     9,     7,    86,   158,    51,
     169,     7,    25,    55,    56,     7,    52,   176,    86,   105,
       8,     7,   108,     8,    66,    61,     8,   113,    70,     4,
     152,    44,   201,   202,   203,   204,   205,   206,     4,     9,
     190,    86,    50,   113,     0,    81,   190,   114,    36,     8,
     158,    36,   138,   139,   198,    25,   115,   116,   126,    86,
     119,   120,    50,   105,    25,    86,   108,   521,   154,   139,
      87,   113,   114,   456,    44,   167,   198,    43,    87,   450,
     588,   126,   190,   175,    43,   152,   126,   246,   129,   129,
     111,   112,   178,    86,   126,   125,   138,   139,     4,   191,
       6,   555,   384,   129,   386,   369,   614,   129,   129,   125,
     152,   125,   154,   263,   283,   284,   285,   129,   129,   125,
     126,   125,   125,   126,   125,   579,   580,   277,   278,   125,
     280,   198,   254,   125,   588,   588,   178,   588,   496,   125,
     496,   110,   117,   125,   105,    86,    96,   291,   190,   603,
      89,    90,    91,   113,   123,   263,   198,   327,   113,   201,
     202,   203,   204,   205,   206,    55,   316,   317,   459,   277,
     333,   257,   280,   542,   543,   325,   326,   138,   138,   139,
      70,   131,   132,   126,   139,    86,   129,   254,    89,   558,
      18,     9,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   245,     9,    57,   375,   661,   250,   317,
      62,   117,   254,    41,   245,   257,   586,   325,   326,   250,
     674,   675,     8,   129,   114,    49,     4,   377,   126,     7,
     526,    83,   686,   383,   129,     4,    60,   387,     7,   609,
     611,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   384,   387,   386,   633,    18,   416,    20,     4,   377,
     443,     7,   422,   423,   424,   383,   449,   125,   451,    86,
     649,   650,   579,   580,    19,   458,   455,    86,    41,   331,
     125,   126,   442,    66,   336,   664,     4,   447,   448,     4,
     331,   111,   112,    38,   126,   336,   603,    42,   416,   459,
       6,   461,     6,   547,   422,   423,   424,   467,     5,   489,
     470,   471,   447,   448,     5,    60,     5,   369,   370,     6,
     503,   125,   126,   375,   442,   108,   509,   379,   369,   370,
     113,     8,   467,   493,    57,    58,   471,    87,    88,    62,
       6,   459,     5,   461,   524,   113,   114,   591,   292,   293,
     294,   295,   470,     5,   661,    78,   139,   111,   112,   519,
      83,    84,    95,    96,    97,   286,   287,   674,   675,   421,
     296,   297,   245,   111,   112,   493,    86,   250,     9,   686,
     421,     9,     8,   543,   425,   288,   289,   290,   125,   549,
       7,   125,   433,   573,   117,     4,    94,   127,   450,   130,
     129,   519,   129,   455,   456,     6,     7,   651,    93,   450,
      11,    12,    13,    14,   109,    16,    17,   147,     7,     4,
       7,    22,   666,   583,   607,   543,     9,   610,     4,   589,
     526,   549,    33,   163,     6,   165,   680,    86,    86,   169,
     123,     6,     6,   545,   496,     6,   690,   691,   631,   693,
       6,   126,   128,   697,   126,   496,   616,   701,     6,   703,
     704,     5,     4,   336,     5,   583,    67,     6,     6,   713,
       5,   589,   126,   633,   526,     7,   126,     6,     5,   126,
     521,   126,   125,     5,     4,    86,   126,   125,   540,     7,
     650,     7,   598,   599,     7,   601,   369,   370,   616,    68,
       6,   126,   126,     8,   245,   128,   547,   126,     6,   250,
     111,   112,     7,   126,   555,   633,   126,     9,   624,   126,
     626,   627,     7,   126,   126,     6,     6,   126,   128,    40,
     131,     7,   650,   574,   586,     7,   588,   128,   579,   580,
     646,     6,   126,    40,     7,   586,     7,   588,   421,     7,
     591,   128,   425,   126,     7,   126,   597,   609,     7,   611,
     433,     7,   603,   126,   126,    40,   672,   126,   609,   126,
     611,     7,     7,     7,   635,   681,   682,   450,   684,   665,
     687,   622,   623,   706,   625,   563,   692,   652,   694,   695,
     678,   291,   496,    20,    44,   336,   637,   155,   591,   705,
      62,   642,   139,   644,   645,   183,    61,   138,   178,   108,
     651,   584,   584,   588,   490,   490,     6,     7,   298,   660,
     661,    11,    12,    13,    14,   666,    16,    17,   369,   370,
     265,   299,    22,   674,   675,   300,    -1,   301,   540,   680,
     302,    -1,   316,    33,    -1,   686,    -1,    -1,   521,   690,
     691,    -1,   693,    -1,    -1,    -1,   697,    -1,   651,    -1,
     701,    -1,   703,   704,    -1,    -1,   245,    -1,    -1,    -1,
      -1,   250,   713,   666,   547,    -1,    -1,    67,    -1,    -1,
     421,    -1,   555,    -1,   425,    -1,    -1,   680,    -1,    -1,
      -1,    -1,   433,    -1,    -1,    -1,    86,   690,   691,    -1,
     693,   574,    -1,    -1,   697,    -1,   579,   580,   701,   450,
     703,   704,    -1,   586,    -1,   588,    -1,    -1,   591,    -1,
     713,   111,   112,    -1,   597,    -1,    -1,    -1,    -1,    -1,
     603,    -1,    -1,    -1,    -1,    -1,   609,    -1,   611,    -1,
      -1,   131,    -1,    -1,    -1,    19,    -1,    -1,    -1,   622,
     623,    -1,   625,    27,    28,    -1,    -1,   336,    32,    -1,
      -1,    -1,    -1,    37,   637,    -1,    -1,    41,    42,   642,
      -1,   644,   645,    -1,    48,    -1,    -1,    -1,   651,    -1,
     521,    55,    56,    57,    -1,    59,    -1,   660,   661,    63,
     369,   370,    66,   666,    -1,    -1,    -1,    -1,   245,    -1,
      -1,   674,   675,   250,    -1,    -1,   547,   680,    -1,    -1,
      -1,    -1,    -1,   686,   555,    -1,    -1,   690,   691,    -1,
     693,    -1,    -1,    -1,   697,    -1,    -1,    -1,   701,    -1,
     703,   704,    -1,   574,    -1,    -1,    -1,    -1,   579,   580,
     713,    -1,   421,    -1,    -1,   586,   425,   588,    -1,    -1,
     591,    -1,   126,    -1,   433,    -1,   597,    -1,    -1,    -1,
      -1,    -1,   603,    -1,    -1,    -1,    -1,     6,   609,    -1,
     611,   450,    11,    12,    13,    14,    -1,    16,    17,    -1,
      -1,   622,   623,    22,   625,    -1,    -1,    -1,    -1,   336,
      -1,    -1,    -1,    -1,    33,    -1,   637,    -1,    -1,    -1,
      -1,   642,    -1,   644,   645,    -1,    -1,    -1,    -1,    -1,
     651,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   660,
     661,    -1,   369,   370,    -1,   666,    -1,    -1,    67,    -1,
       6,     7,    -1,   674,   675,    11,    12,    13,    14,   680,
      16,    17,   521,    -1,    -1,   686,    22,    86,    -1,   690,
     691,    -1,   693,    -1,    -1,    -1,   697,    33,    -1,    -1,
     701,    -1,   703,   704,    -1,    -1,   245,    -1,   547,    -1,
      -1,   250,   713,    -1,   421,    -1,   555,    -1,   425,    19,
      -1,    -1,   121,   122,    -1,    -1,   433,    -1,    28,    -1,
      -1,    67,    32,    -1,    -1,   574,    -1,    37,    -1,    -1,
     579,   580,    42,   450,    -1,    -1,     7,   586,    48,   588,
      86,    -1,   591,    -1,    -1,    55,    56,    57,   597,    59,
      -1,    -1,    -1,    63,   603,    -1,    66,    -1,    29,    -1,
     609,    -1,   611,    -1,    35,   111,   112,    -1,    39,    -1,
      -1,    -1,    -1,   622,   623,    -1,   625,    -1,    -1,    -1,
      51,    52,    -1,    54,    -1,   131,    -1,   336,   637,    -1,
      61,    -1,    -1,   642,    65,   644,   645,    -1,    -1,    -1,
      -1,    -1,   651,    -1,   521,    -1,    -1,    -1,    -1,    -1,
      -1,   660,   661,    -1,    -1,    86,   126,   666,    -1,    -1,
     369,   370,    -1,    -1,    -1,   674,   675,    -1,   245,    -1,
     547,   680,    -1,   250,    -1,    -1,    -1,   686,   555,    -1,
      -1,   690,   691,    -1,   693,    -1,    -1,    -1,   697,    -1,
      -1,    -1,   701,     7,   703,   704,    -1,   574,    -1,    -1,
      -1,    -1,   579,   580,   713,    -1,    -1,    -1,    -1,   586,
      -1,   588,   421,    -1,   591,    29,   425,    -1,    -1,    -1,
     597,    35,    -1,    -1,   433,    39,   603,    -1,    -1,    -1,
      -1,    -1,   609,    -1,   611,    -1,    -1,    51,    52,    -1,
      54,   450,    -1,    -1,    -1,   622,   623,    61,   625,    -1,
      -1,    65,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   336,
     637,    -1,    -1,    -1,    -1,   642,    -1,   644,   645,    -1,
      -1,    -1,    86,    -1,   651,    -1,    -1,    -1,    -1,    -1,
       6,     7,    -1,   660,   661,    11,    12,    13,    14,   666,
      16,    17,   369,   370,     6,    -1,    22,   674,   675,    11,
      12,    13,    14,   680,    16,    17,    -1,    33,    -1,   686,
      22,    -1,   521,   690,   691,    -1,   693,    -1,    -1,    -1,
     697,    33,    -1,    -1,   701,    -1,   703,   704,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   713,    -1,   547,    -1,
      -1,    67,    -1,    -1,   421,    -1,   555,    -1,   425,    -1,
      -1,    -1,    -1,    -1,    -1,    67,   433,    -1,    -1,    -1,
      86,    -1,    -1,    -1,    -1,   574,    -1,    -1,    -1,    -1,
     579,   580,    -1,   450,    86,    -1,    -1,   586,    -1,   588,
      -1,    -1,   591,    -1,    -1,   111,   112,    -1,   597,    -1,
      -1,    -1,    -1,    -1,   603,    -1,    -1,    -1,    29,    -1,
     609,    -1,   611,    -1,    35,   131,    -1,    -1,    39,    19,
      -1,    -1,    -1,   622,   623,    -1,   625,    -1,    28,    -1,
      51,    52,    32,    54,    -1,    -1,    -1,    37,   637,    -1,
      61,    41,    42,   642,    65,   644,   645,    -1,    48,    -1,
      -1,    -1,   651,    -1,   521,    55,    56,    57,    -1,    59,
      -1,   660,   661,    63,    -1,    86,    66,   666,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   674,   675,    -1,    -1,    -1,
     547,   680,    -1,    -1,    -1,    -1,    -1,   686,   555,    -1,
      -1,   690,   691,    -1,   693,    -1,    -1,    -1,   697,    -1,
      -1,    -1,   701,    -1,   703,   704,    -1,   574,    -1,    -1,
      -1,    -1,   579,   580,   713,    -1,    -1,    -1,    -1,   586,
      -1,   588,    -1,    -1,   591,    -1,   126,    -1,    -1,    -1,
     597,    -1,    -1,    -1,    -1,    -1,   603,    -1,    -1,    -1,
      -1,    -1,   609,    -1,   611,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   622,   623,    -1,   625,    -1,
      -1,    -1,     4,    -1,     6,    -1,    -1,    -1,    -1,    -1,
     637,    -1,    -1,    -1,    -1,   642,    -1,   644,   645,    -1,
      -1,    -1,    -1,    -1,   651,   201,   202,   203,   204,   205,
     206,    -1,    -1,   660,   661,    -1,    -1,    -1,    -1,   666,
      -1,    -1,    -1,    -1,    -1,    -1,   425,   674,   675,    -1,
      -1,    -1,    -1,   680,   433,    -1,    -1,    -1,    -1,   686,
      -1,    -1,    -1,   690,   691,    -1,   693,    -1,    -1,    -1,
     697,    -1,    -1,    -1,   701,    -1,   703,   704,   201,   202,
     203,   204,   205,   206,    -1,    -1,   713,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   283,   284,   285,
     286,   287,   288,   289,   290,   117,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   129,    -1,     6,
       7,    -1,    -1,    -1,    11,    12,    13,    14,    -1,    16,
      17,    -1,    -1,    -1,    -1,    22,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   331,    33,    -1,    -1,    -1,
     283,   284,   285,   286,   287,   288,   289,   290,   547,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      67,    -1,    -1,    -1,    -1,   574,    -1,    -1,    -1,   375,
      -1,    -1,    -1,   379,    -1,    -1,    -1,    -1,   331,    86,
      -1,    -1,   591,    -1,    -1,    -1,    -1,    -1,   597,    -1,
      -1,    -1,     6,     7,    -1,    -1,    -1,    11,    12,    13,
      14,    -1,    16,    17,   111,   112,    -1,    -1,    22,    -1,
      -1,    -1,    -1,   622,   623,    -1,   625,    -1,    -1,    33,
      -1,    -1,   375,    -1,   131,    -1,   379,    -1,   637,    -1,
      -1,    -1,    -1,   642,    -1,   644,   645,    -1,    -1,    -1,
      -1,    -1,   651,    -1,    -1,    -1,    -1,    -1,    -1,   455,
     456,   660,    -1,    67,    -1,    -1,    -1,   666,    -1,     6,
       7,    -1,    -1,    -1,    11,    12,    13,    14,    -1,    16,
      17,   680,    86,    -1,    -1,    22,    -1,    -1,    -1,    -1,
      -1,   690,   691,    -1,   693,    -1,    33,    -1,   697,    -1,
     496,    -1,   701,    -1,   703,   704,    -1,   111,   112,    -1,
      -1,    -1,   455,   456,   713,    -1,    -1,    -1,     6,    -1,
       8,     9,    -1,    11,    12,    13,    14,   131,    16,    17,
      67,    -1,    20,    21,    22,    23,    -1,    25,    26,    -1,
      28,    29,    30,    -1,   540,    33,    34,    35,    -1,    86,
      38,    39,    -1,   496,    -1,    -1,    44,    -1,    -1,    47,
      -1,    -1,    -1,    51,    52,    53,    54,    -1,    -1,    -1,
      -1,    -1,    -1,    61,   111,   112,    -1,    65,    -1,    67,
      68,    -1,    -1,    -1,    -1,     6,     7,    -1,    -1,    -1,
      11,    12,    13,    14,   131,    16,    17,   540,    86,    -1,
      -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   111,   112,     6,    -1,     8,     9,    -1,
      11,    12,    13,    14,    -1,    16,    17,    -1,   126,    20,
      21,    22,    23,   131,    25,    26,    67,    28,    29,    30,
      -1,    -1,    33,    34,    35,    -1,    -1,    38,    39,    -1,
      -1,    -1,    -1,    44,    -1,    86,    47,    -1,    -1,    -1,
      51,    52,    53,    54,    -1,    -1,    -1,    -1,    -1,    -1,
      61,    -1,    -1,    -1,    65,    -1,    67,    68,    -1,    -1,
     111,   112,     6,    -1,     8,     9,    -1,    11,    12,    13,
      14,    -1,    16,    17,    -1,    86,    20,    21,    22,    23,
     131,    -1,    26,    -1,    28,    29,    30,    -1,    -1,    33,
      34,    35,    -1,    -1,    38,    39,    -1,    -1,    -1,    -1,
     111,   112,    -1,    47,    -1,    -1,    -1,    51,    52,    53,
      54,    -1,    -1,    -1,    -1,   126,    -1,    61,    -1,    -1,
     131,    65,    -1,    67,    68,    -1,    -1,    -1,    -1,     6,
      -1,     8,     9,    -1,    11,    12,    13,    14,    -1,    16,
      17,    -1,    86,    20,    21,    22,    23,    -1,    -1,    26,
      -1,    28,    29,    30,    -1,    -1,    33,    34,    35,    -1,
      -1,    38,    39,    -1,    -1,    -1,    -1,   111,   112,    -1,
      47,    -1,    -1,    -1,    51,    52,    53,    54,    -1,    -1,
      -1,    -1,   126,    -1,    61,    -1,    -1,   131,    65,    -1,
      67,    68,    -1,    -1,    -1,    -1,     6,    -1,     8,     9,
      -1,    11,    12,    13,    14,    -1,    16,    17,    -1,    86,
      20,    21,    22,    23,    -1,    -1,    26,    -1,    28,    29,
      30,    -1,    -1,    33,    34,    35,    -1,    -1,    38,    39,
      -1,    -1,    -1,    -1,   111,   112,    -1,    47,    -1,    -1,
      -1,    51,    52,    53,    54,    -1,    -1,    -1,    -1,   126,
      -1,    61,    -1,    -1,   131,    65,    -1,    67,    68,    -1,
      -1,    -1,    -1,     6,    -1,     8,     9,    -1,    11,    12,
      13,    14,    -1,    16,    17,    -1,    86,    20,    21,    22,
      23,    -1,    -1,    26,    -1,    28,    29,    30,    -1,    -1,
      33,    34,    35,    -1,    -1,    38,    39,    -1,    -1,    -1,
      -1,   111,   112,    -1,    47,    -1,    -1,    -1,    51,    52,
      53,    54,    -1,    -1,    -1,    -1,   126,    -1,    61,    -1,
      -1,   131,    65,    -1,    67,    68,    -1,    -1,    -1,    -1,
       6,    -1,     8,    -1,    -1,    11,    12,    13,    14,    -1,
      16,    17,    -1,    86,    20,    21,    22,    23,    -1,    -1,
      26,    -1,    28,    29,    30,    -1,    -1,    33,    34,    35,
      -1,    -1,    38,    39,    -1,    -1,    -1,    -1,   111,   112,
      -1,    47,    -1,    -1,    -1,    51,    52,    53,    54,    -1,
      -1,    -1,    -1,   126,    -1,    61,    -1,    -1,   131,    65,
      -1,    67,    68,    -1,    -1,    -1,    -1,     6,    -1,     8,
      -1,    -1,    11,    12,    13,    14,    -1,    16,    17,    -1,
      86,    20,    21,    22,    23,    -1,    -1,    26,    -1,    28,
      29,    30,    -1,    -1,    33,    34,    35,    -1,    -1,    38,
      39,    -1,    -1,    -1,    -1,   111,   112,    -1,    47,    -1,
      -1,    -1,    51,    52,    53,    54,    -1,    -1,    -1,    -1,
     126,    -1,    61,    -1,    -1,   131,    65,    -1,    67,    68,
      -1,    -1,    -1,    -1,     6,    -1,     8,    -1,    -1,    11,
      12,    13,    14,    -1,    16,    17,    -1,    86,    20,    21,
      22,    23,    -1,    -1,    26,    -1,    28,    -1,    30,    -1,
      -1,    33,    34,    -1,    -1,    -1,    38,    -1,    -1,    -1,
      -1,    -1,   111,   112,    -1,    47,    -1,    -1,    -1,    -1,
      -1,    53,    -1,     6,    -1,     8,    -1,   126,    11,    12,
      13,    14,   131,    16,    17,    67,    68,    20,    21,    22,
      23,    -1,    -1,    26,    -1,    28,    -1,    30,    -1,    -1,
      33,    34,    -1,    -1,    86,    38,    -1,    -1,    -1,    -1,
      -1,     6,    -1,    -1,    47,    -1,    11,    12,    13,    14,
      53,    16,    17,    -1,    -1,    -1,    -1,    22,    -1,   111,
     112,    -1,    -1,    -1,    67,    68,    -1,    -1,    33,    -1,
       6,    -1,    -1,    -1,   126,    11,    12,    13,    14,   131,
      16,    17,    -1,    86,    -1,    -1,    22,    -1,    -1,    -1,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    33,    -1,    35,
      -1,    -1,    67,    39,    -1,    -1,    -1,    -1,   111,   112,
      -1,    -1,    -1,    -1,    -1,    51,    52,    -1,    54,    -1,
      -1,    86,    -1,   126,    -1,    61,    -1,     6,   131,    65,
      -1,    67,    11,    12,    13,    14,    -1,    16,    17,    -1,
      -1,    -1,    -1,    22,    -1,    -1,   111,   112,    -1,    -1,
      86,    -1,    -1,    -1,    33,    -1,     5,     6,    -1,    -1,
      -1,    -1,    11,    12,    13,    14,   131,    16,    17,    -1,
      -1,    -1,    -1,    22,    -1,   111,   112,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    33,    -1,    -1,    -1,    67,    -1,
      -1,    -1,    -1,     5,     6,   131,    -1,    -1,    -1,    11,
      12,    13,    14,    -1,    16,    17,    -1,    86,    87,    88,
      22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,    -1,
      -1,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   111,   112,    -1,    -1,    -1,    86,    87,    88,
      -1,    -1,   121,   122,    -1,    -1,    -1,   126,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    67,    -1,    -1,    -1,    -1,
      -1,    -1,   111,   112,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   121,   122,    86,    87,    88,    -1,     6,    -1,
      -1,    -1,    -1,    11,    12,    13,    14,    -1,    16,    17,
      -1,    -1,    -1,    -1,    22,    -1,    -1,    -1,    -1,   111,
     112,    29,    -1,    -1,    -1,    33,    -1,    35,    -1,   121,
     122,    39,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,    51,    52,    -1,    54,    -1,    -1,    -1,
      -1,   117,    -1,    61,    -1,    -1,    -1,    65,     6,    67,
       8,     9,    -1,    11,    12,    13,    14,    -1,    16,    17,
      -1,    -1,    -1,    -1,    22,    -1,    -1,    -1,    86,    87,
      88,    -1,    -1,    -1,    -1,    33,    -1,    -1,    -1,     6,
      -1,     8,    -1,    -1,    11,    12,    13,    14,    -1,    16,
      17,     6,     7,   111,   112,    22,    11,    12,    13,    14,
      -1,    16,    17,   121,   122,    -1,    33,    22,    -1,    67,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,    87,
      88,     6,     7,    -1,    -1,    -1,    11,    12,    13,    14,
      67,    16,    17,    -1,    -1,    -1,    -1,    22,    -1,    -1,
      -1,    -1,    67,   111,   112,    -1,    -1,    -1,    33,    86,
      87,    88,    -1,   121,   122,    -1,    -1,    -1,    -1,    -1,
      -1,    86,    87,    88,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   111,   112,    -1,    -1,    -1,    -1,
      -1,    -1,    67,    -1,   121,   122,   111,   112,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   121,   122,    -1,    -1,
      -1,    86,    87,    88,     6,     7,    -1,    -1,    -1,    11,
      12,    13,    14,    -1,    16,    17,    -1,    -1,    -1,    -1,
      22,    -1,    -1,    -1,    -1,    -1,   111,   112,    -1,    -1,
      -1,    33,    -1,     6,     7,    -1,   121,   122,    11,    12,
      13,    14,    -1,    16,    17,     6,     7,    -1,    -1,    22,
      11,    12,    13,    14,    -1,    16,    17,    -1,    -1,    -1,
      33,    22,    -1,     6,     7,    67,    -1,    -1,    11,    12,
      13,    14,    33,    16,    17,    -1,    -1,    -1,    -1,    22,
      -1,    -1,    -1,    -1,    86,    87,    88,    -1,    -1,    -1,
      33,     6,    -1,    -1,    67,    -1,    11,    12,    13,    14,
      -1,    16,    17,    -1,    -1,    -1,    67,    22,    -1,   111,
     112,    -1,    -1,    86,    87,    88,    -1,    -1,    33,   121,
     122,    -1,    -1,    -1,    67,    86,    87,    88,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,   112,
      -1,    -1,    -1,    86,    87,    88,    -1,    -1,   121,   122,
     111,   112,    67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     121,   122,    -1,    -1,   640,   641,    -1,   643,   111,   112,
      -1,    86,    87,    88,    -1,    -1,    -1,    -1,   121,   122,
     656,    -1,   658,   659,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   671,   111,   112,    -1,    -1,
      -1,    -1,    -1,   117,    -1,    -1,   121,   122,    -1,    -1,
      -1,     9,    -1,   689,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    19,    -1,   699,   700,    -1,   702,    -1,    -1,    -1,
      28,    29,    -1,   709,    32,   711,   712,    35,    -1,    37,
      -1,    39,   718,    -1,    42,    -1,    -1,    -1,    -1,    -1,
      48,     9,    -1,    51,    52,    -1,    54,    55,    -1,    57,
      58,    19,    -1,    61,    -1,    63,    -1,    65,    66,    -1,
      28,    29,    -1,    -1,    32,    -1,    -1,    35,    -1,    37,
      -1,    39,    -1,    -1,    42,    -1,    -1,    -1,    86,    -1,
      48,    -1,    -1,    51,    52,    -1,    54,    55,    -1,    57,
      58,    19,    -1,    61,    -1,    63,    -1,    65,    66,    -1,
      28,    29,    -1,    -1,    32,    -1,    -1,    35,    -1,    37,
      -1,    39,    -1,    -1,    42,    -1,    -1,    -1,    86,    -1,
      48,    -1,    -1,    51,    52,    -1,    54,    55,    -1,    57,
      58,    19,    -1,    61,    -1,    63,    -1,    65,    66,    -1,
      28,    29,    -1,    -1,    32,    -1,    -1,    35,    -1,    37,
      -1,    39,    -1,    -1,    42,    -1,    -1,    -1,    86,    -1,
      48,    -1,    -1,    51,    52,    -1,    54,    55,    -1,    57,
      58,    19,    -1,    61,    -1,    63,    -1,    65,    66,    -1,
      28,    29,    -1,    -1,    32,    -1,    -1,    35,    -1,    37,
      -1,    39,    -1,    -1,    42,    -1,    -1,    -1,    86,    -1,
      48,    -1,    -1,    51,    52,    -1,    54,    55,    -1,    57,
      58,    19,    -1,    61,    -1,    63,    -1,    65,    66,    -1,
      28,    -1,    -1,    -1,    32,    -1,    -1,    -1,    -1,    37,
      -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,    86,    -1,
      48,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,
      -1,    59,    -1,    -1,    -1,    63,    -1,    -1,    66,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   117
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,    19,    27,    28,    32,    37,    41,    42,    48,    55,
      56,    57,    59,    63,    66,   126,   133,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   181,   211,    86,
     167,   168,   169,   167,    86,    86,   180,     0,   172,   174,
     177,   171,   172,    56,    59,   179,   126,   129,   126,   129,
       8,    50,   212,   213,     8,    36,    50,   182,   183,   186,
     172,    86,   180,    86,    89,     9,   134,   163,   165,   167,
     125,   213,     9,   134,   165,   184,   163,   164,   183,   186,
     186,   212,   213,   182,   183,   186,   126,    29,    35,    39,
      51,    52,    54,    58,    61,    65,   157,   158,   159,   160,
     161,   162,   163,   166,   167,   178,   190,   196,   214,   215,
     216,   217,   165,   185,   125,   186,   213,   183,   186,   186,
      86,   197,   198,    86,   191,   192,   193,   197,     4,     4,
       4,    58,   157,   126,     9,   215,    57,   168,   178,   187,
     188,   189,   190,   195,   196,   205,   206,   207,   208,   165,
     186,     4,    43,   202,     6,   125,   126,     4,   117,   202,
       5,     5,     5,   197,   191,   197,   135,     8,   220,   207,
       9,   188,   126,   204,   220,     8,   202,   209,     6,     5,
     164,   203,     7,   157,   199,   200,   201,    86,   192,     5,
       6,     8,    11,    12,    13,    14,    16,    17,    22,    33,
      67,    87,    88,   111,   112,   121,   122,   156,   167,   194,
     218,   259,   260,   261,   263,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     293,   202,   126,   202,     9,   134,   202,   209,   135,     9,
     134,   209,     7,   199,   125,   193,     7,   125,   158,   167,
     293,     9,   125,   134,   158,   163,   164,   129,   167,   267,
     269,   273,   273,   273,   273,   273,   273,     4,     6,   129,
       4,   111,   112,    89,    90,    91,    87,    88,    95,    96,
      97,    46,   115,   116,   119,   120,   113,   114,   130,    94,
      93,   109,   110,   150,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   117,   292,     6,    20,    21,
      23,    26,    28,    30,    34,    38,    47,    53,    68,    86,
     126,   131,   153,   157,   167,   220,   221,   222,   223,   224,
     225,   227,   228,   229,   231,   232,   233,   234,   236,   242,
     244,   245,   250,   251,   252,   253,   254,   255,   261,   268,
     270,   271,   272,   274,   275,   290,   209,    33,    67,   210,
     221,     7,   164,   201,     4,     7,   266,     4,   266,     7,
       9,   194,   219,     4,   264,   265,   264,     6,    86,   293,
       7,   262,   293,    86,   293,   273,   273,   273,   278,   278,
     279,   279,   279,   158,   162,   280,   280,   280,   280,   281,
     281,   282,   283,   284,   285,   286,   123,   289,   293,    86,
     126,     6,     6,     6,     6,   144,    86,   126,   293,   126,
     293,   220,   141,   128,    86,   154,   155,   156,   167,   259,
     268,   191,     4,     9,   222,   126,   126,     6,     6,     9,
     221,     9,     5,   273,     4,     7,     7,   276,     9,   125,
     293,     4,   265,   266,   266,     7,   262,     6,     5,     7,
     125,     6,     5,   293,     7,   126,   146,   224,   232,   247,
     249,   293,   293,   293,   225,   126,   126,   126,    49,    60,
     256,   257,   258,     6,   225,     7,    87,   135,     7,   262,
       7,   262,   135,     9,   135,     5,   273,   276,   135,     9,
     194,     5,     7,     7,   262,   293,     7,   262,   151,   126,
     146,   125,     7,     7,     7,    68,     6,   220,   257,   258,
     293,   155,   126,     7,   126,     7,   135,   135,     7,     7,
     128,   147,   293,   126,   232,     8,   237,   136,   220,     6,
     201,     7,   126,   126,   288,   126,   147,   147,   293,     9,
     134,    21,    26,    68,    86,   225,   226,   227,   230,   235,
     243,   246,   293,     7,   142,   152,     7,   248,   249,   126,
     126,   147,    25,    44,   238,   239,   240,   241,     6,     6,
     141,   128,   137,   138,     7,   220,   225,   148,     7,     7,
     248,     7,   248,   126,   128,   293,   294,     9,   239,   240,
       9,   221,   241,   146,   247,   293,     6,   226,    40,   126,
     143,   225,   148,   148,     7,   148,     7,     7,   248,   128,
     135,     9,   135,   126,   146,     7,   293,   139,   145,   149,
     225,   225,   148,   225,   148,   148,     7,   135,   147,   293,
     126,   136,     7,   225,   149,   149,   225,   149,   225,   225,
     148,   126,   147,   147,   293,   226,   142,   140,   149,   149,
     149,   225,     7,   248,   126,   126,   147,   138,   226,   149,
     148,     7,     7,   248,     7,   248,   126,    40,   143,   226,
     148,   148,     7,   148,     7,     7,   248,   139,   149,   226,
     226,   148,   226,   148,   148,     7,   226,   149,   149,   226,
     149,   226,   226,   148,   140,   149,   149,   149,   226,   149
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   154,   155,   155,   155,   155,   156,
     156,   156,   156,   156,   156,   157,   157,   158,   158,   159,
     159,   160,   160,   160,   160,   160,   161,   161,   162,   162,
     163,   164,   165,   166,   166,   166,   167,   167,   168,   169,
     170,   170,   170,   170,   170,   170,   170,   170,   171,   171,
     172,   172,   173,   174,   174,   175,   176,   177,   177,   177,
     178,   178,   179,   179,   179,   179,   179,   179,   179,   179,
     179,   179,   180,   181,   181,   181,   181,   181,   181,   181,
     181,   182,   183,   184,   184,   185,   186,   186,   187,   187,
     188,   188,   188,   189,   189,   190,   190,   191,   191,   192,
     192,   193,   193,   194,   194,   195,   196,   196,   196,   196,
     196,   196,   196,   196,   197,   197,   197,   198,   199,   200,
     200,   201,   202,   203,   203,   204,   204,   205,   206,   206,
     206,   206,   207,   207,   208,   209,   209,   209,   209,   210,
     210,   210,   210,   211,   211,   211,   211,   212,   212,   213,
     213,   214,   214,   215,   215,   216,   217,   218,   218,   218,
     218,   219,   219,   220,   220,   221,   221,   222,   222,   223,
     224,   225,   225,   225,   225,   225,   225,   226,   226,   226,
     226,   226,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   228,   229,   230,   231,   232,   232,   232,
     232,   232,   232,   232,   232,   233,   234,   235,   236,   237,
     237,   237,   237,   238,   238,   239,   240,   240,   241,   241,
     242,   243,   244,   245,   245,   245,   245,   245,   245,   245,
     245,   246,   246,   246,   246,   246,   246,   246,   246,   247,
     247,   248,   249,   249,   250,   250,   251,   251,   252,   252,
     253,   254,   255,   255,   255,   256,   256,   257,   258,   259,
     259,   260,   260,   260,   260,   260,   260,   260,   261,   261,
     262,   262,   263,   263,   263,   263,   264,   264,   265,   266,
     266,   267,   267,   268,   268,   268,   268,   268,   268,   269,
     269,   270,   270,   270,   270,   271,   272,   273,   273,   273,
     273,   273,   274,   275,   276,   276,   276,   276,   277,   277,
     277,   277,   278,   278,   278,   278,   279,   279,   279,   280,
     280,   280,   280,   281,   281,   281,   281,   281,   281,   282,
     282,   282,   283,   283,   284,   284,   285,   285,   286,   286,
     287,   287,   288,   288,   289,   289,   290,   291,   291,   291,
     292,   292,   292,   292,   292,   292,   292,   292,   292,   292,
     292,   292,   293,   294
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     3,     1,     3,     1,     1,     1,     0,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     3,     3,     1,     1,     1,     3,
       0,     1,     2,     2,     3,     2,     1,     1,     1,     2,
       1,     2,     3,     1,     1,     3,     5,     1,     1,     1,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     6,     5,     5,     4,     5,     4,     4,
       3,     2,     2,     1,     3,     0,     6,     2,     1,     2,
       1,     1,     1,     1,     1,     4,     3,     1,     3,     1,
       3,     1,     3,     1,     1,     2,     4,     3,     3,     2,
       4,     3,     3,     2,     4,     3,     3,     1,     1,     1,
       3,     2,     2,     1,     3,     1,     1,     2,     4,     3,
       3,     2,     4,     3,     1,     6,     5,     5,     2,     5,
       4,     5,     4,     5,     4,     4,     3,     2,     3,     5,
       2,     1,     2,     1,     1,     1,     2,     6,     5,     3,
       2,     1,     3,     2,     5,     1,     2,     1,     1,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     7,    11,    11,     5,     2,
       5,     5,     6,     1,     2,     2,     1,     2,     3,     2,
       8,     8,     9,    10,    11,    11,    12,    11,    12,    12,
      13,    10,    11,    11,    12,    11,    12,    12,    13,     1,
       1,     1,     1,     3,     2,     3,     2,     3,     2,     3,
       3,     5,     3,     3,     4,     1,     2,     5,     2,     1,
       1,     1,     1,     3,     1,     1,     1,     1,     4,     5,
       1,     3,     3,     4,     3,     4,     1,     2,     3,     2,
       3,     3,     3,     3,     4,     5,     6,     5,     6,     4,
       4,     1,     1,     1,     1,     2,     2,     1,     1,     2,
       2,     1,     2,     2,     1,     2,     2,     1,     4,     5,
       4,     5,     1,     3,     3,     3,     1,     3,     3,     1,
       3,     3,     3,     1,     3,     3,     3,     3,     3,     1,
       3,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     8,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
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
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
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
# endif
#endif

#ifndef yytnamerr
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
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
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
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
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
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
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
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
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

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

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
  case 2: /* input: CompilationUnit  */
#line 102 "lalr1.y"
                       {
    theprogram=new astnode;
    theprogram->token="input";
    vector<astnode*>v;
    v.push_back((yyvsp[0].node));
    theprogram->children=v;
    // if(symtab!=nullptr)
    // delete symtab;
    // cout<<"in input";
    // cout<<endl;
    // exit(0);
    // prettyPrint($$);
    // cout<<$$->token<<" "<<(($$->children)[0])->token;
}
#line 2830 "lalr1.tab.c"
    break;

  case 3: /* SYMTABS: %empty  */
#line 120 "lalr1.y"
                  {
        // cout<<"in symtabs"<<endl;
		currscope++;
		fullscope = fullscope + "/" + to_string(currscope);

		curr_fcnscope = currscope;
		// symtab = new symtab_t;
		// symtab_top[fullscope] = symtab;
        // symtab_top.insert({fullscope,symtab});
        // symtab_top.insert(make_pair(fullscope,symtab));
        if(symtab_top.find(fullscope)==symtab_top.end()) {
            symtab = new symtab_t;
            symtab_top[fullscope]=symtab;

            // symtab_top.insert({fullscope,symtab});
        }
        // if(buffer.size()!=0) {
        //     symadd(buffer)
        // }
        for(auto i:buffer){
            symadd_para(i.first,i.second,1);
        }
        buffer.clear();
        // string s=$3->value;
        // vector<string>tokens=split(s,',');
        // // cout<<"\n executing symadd_list\n";
        // symadd_list(tokens,$2->type);
		// cout<<fullscope<<endl;
}
#line 2864 "lalr1.tab.c"
    break;

  case 4: /* SYMTABE: %empty  */
#line 152 "lalr1.y"
                  {
        // cout<<"in symtabe"<<endl;
		// fullscope = fullscope +"/"+ to_string(curr_fcnscope);	//$$ = new astnode($1->type,"Function", false, {$1, $3});

		// //Type* a = symtype("a");
		// //if( a==NULL ) *fp<<fullscope<<"-NULL-"<<endl;
		// print_symtab();
		// delete symtab;
		// symtab = symtab_top["0"];
		// fullscope = "0";
        // cout<<"executing substr"<<endl;
        fullscope = fullscope.substr(0, fullscope.find_last_of("/") );
        // cout<<fullscope<<endl;
        // cout<<"success ";
        // if(symtab!=nullptr){
        //     delete symtab;
        // }
        if(symtab_top.find(fullscope)!=symtab_top.end()) {
            // cout<<"in if ";
            symtab = symtab_top[fullscope];
        }
        else {
            // cout<<"in else";
            symtab=symtab_top["0"];
            fullscope="0";
        }
        // if(fullscope=="0"){ delete symtab;}
        // cout<<fullscope<<endl;
        // cout<<"leaved symtabe ";
        // print_symtab(symbolTable);
}
#line 2900 "lalr1.tab.c"
    break;

  case 5: /* IFMARK1: %empty  */
#line 187 "lalr1.y"
    {
        string tac,togo_label;
        togo_label=get_label();
        tac="if (t"+to_string(tempno-1)+"=1) goto "+togo_label;
         prog.push_back(tac);

        string topush_label=get_label();
        tac="goto "+topush_label;
         prog.push_back(tac);
        if_bwlabels.push(topush_label);

        tac=togo_label+":";
         prog.push_back(tac);

    }
#line 2920 "lalr1.tab.c"
    break;

  case 6: /* IFEND1: %empty  */
#line 204 "lalr1.y"
    {
        string tac,toget_label;
        toget_label=if_bwlabels.top();
        if_bwlabels.pop();
	    tac = toget_label+":";
	     prog.push_back(tac);
    }
#line 2932 "lalr1.tab.c"
    break;

  case 7: /* IFEND2: %empty  */
#line 213 "lalr1.y"
    {
        string tac,topush_label;
        topush_label=get_label();
        tac="goto "+topush_label;
         prog.push_back(tac);
        if_endlabels.push(topush_label);
    }
#line 2944 "lalr1.tab.c"
    break;

  case 8: /* ELSEMARK1: %empty  */
#line 222 "lalr1.y"
    {
        string tac,toget_label;
        toget_label=if_bwlabels.top();
        if_bwlabels.pop();
	    tac = toget_label+":";
	     prog.push_back(tac);
    }
#line 2956 "lalr1.tab.c"
    break;

  case 9: /* ELSEEND1: %empty  */
#line 231 "lalr1.y"
    {
        string tac,toget_label;
        toget_label=if_endlabels.top();
        if_endlabels.pop();
	    tac = toget_label+":";
	     prog.push_back(tac);
    }
#line 2968 "lalr1.tab.c"
    break;

  case 10: /* WHILEMARK2: %empty  */
#line 241 "lalr1.y"
    {
        string tac,topush_label;
        topush_label=get_label();
        tac=topush_label+":";
         prog.push_back(tac);
        while_bwlabels.push(topush_label);
   }
#line 2980 "lalr1.tab.c"
    break;

  case 11: /* WHILEMARK1: %empty  */
#line 251 "lalr1.y"
    {
        string tac,topush_label;
        topush_label=get_label();
        tac="if (t"+to_string(tempno-1)+"=0) goto "+topush_label;
        // while_exp.push("t"+to_string(tempno-1));
         prog.push_back(tac);
        while_endlabels.push(topush_label);
        // topush_label=get_label();
        // tac=topush_label+":";
        //  prog.push_back(tac);
        // while_endlabels.push(topush_label);
    }
#line 2997 "lalr1.tab.c"
    break;

  case 12: /* WHILEEND1: %empty  */
#line 265 "lalr1.y"
    {
        string tac,toget_label,exp;
        toget_label=while_bwlabels.top();
        while_bwlabels.pop();
        // exp=while_exp.top();
        // while_exp.pop();
        // tac="if ("+exp+"=1) goto "+toget_label;
        tac="goto "+toget_label;
         prog.push_back(tac);
        toget_label=while_endlabels.top();
        while_endlabels.pop();
        tac=toget_label+":";
         prog.push_back(tac);
    }
#line 3016 "lalr1.tab.c"
    break;

  case 13: /* DOMARK1: %empty  */
#line 281 "lalr1.y"
    {
        string tac,topush_label;
        topush_label=get_label();
        do_bwlabels.push(topush_label);
        tac=topush_label+":";
         prog.push_back(tac);
    }
#line 3028 "lalr1.tab.c"
    break;

  case 14: /* DOEND1: %empty  */
#line 290 "lalr1.y"
    {
        string tac,toget_label;
        toget_label=do_bwlabels.top();
        do_bwlabels.pop();
        tac="if (t"+to_string(tempno-1)+"=1) goto "+toget_label;
         prog.push_back(tac);
    }
#line 3040 "lalr1.tab.c"
    break;

  case 15: /* FORMARK1: %empty  */
#line 299 "lalr1.y"
    {
        string tac,topush_label;
        topush_label=get_label();
        for_initlabels.push(topush_label);
        tac=topush_label+":";
         prog.push_back(tac);
    }
#line 3052 "lalr1.tab.c"
    break;

  case 16: /* FORMARK2: %empty  */
#line 308 "lalr1.y"
    {
        string tac,topush_label;
        topush_label=get_label();
        for_statlabels.push(topush_label);
        tac="if (t"+to_string(tempno-1)+"=1) goto "+topush_label;
         prog.push_back(tac);
        topush_label=get_label();
        for_endlabels.push(topush_label);
        tac="goto "+topush_label;
         prog.push_back(tac);
        topush_label=get_label();
        for_updlabels.push(topush_label);
        tac=topush_label+":";
         prog.push_back(tac);
    }
#line 3072 "lalr1.tab.c"
    break;

  case 17: /* FORMARK3: %empty  */
#line 325 "lalr1.y"
    {
        string tac,toget_label;
        toget_label=for_initlabels.top();
        for_initlabels.pop();
        tac="goto "+toget_label;
         prog.push_back(tac);
        toget_label=for_statlabels.top();
        for_statlabels.pop();
        tac=toget_label+":";
         prog.push_back(tac);
    }
#line 3088 "lalr1.tab.c"
    break;

  case 18: /* FOREND1: %empty  */
#line 338 "lalr1.y"
    {
        string tac,toget_label;
        toget_label=for_updlabels.top();
        for_updlabels.pop();
        tac="goto "+toget_label;
         prog.push_back(tac);
        toget_label=for_endlabels.top();
        for_endlabels.pop();
        tac=toget_label+":";
         prog.push_back(tac);
    }
#line 3104 "lalr1.tab.c"
    break;

  case 19: /* CONDMARK1: %empty  */
#line 351 "lalr1.y"
    {
        string tac,topush_label=get_label();
        tac="if (t"+to_string(tempno-1)+"=0) goto "+topush_label;
         prog.push_back(tac);
        cond_bwlabels.push(topush_label);
        topush_label=get_label();
        cond_inlabels.push(topush_label);
        tac=topush_label+":";
         prog.push_back(tac);
    }
#line 3119 "lalr1.tab.c"
    break;

  case 20: /* CONDMARK2: %empty  */
#line 363 "lalr1.y"
    {
        string tac,topush_label=get_label();
        tac="goto "+topush_label;
         prog.push_back(tac);
        cond_endlabels.push(topush_label);
        topush_label=cond_bwlabels.top();
        cond_bwlabels.pop();
        tac=topush_label+":";
         prog.push_back(tac);
    }
#line 3134 "lalr1.tab.c"
    break;

  case 21: /* CONDMARK3: %empty  */
#line 375 "lalr1.y"
    {
        string tac,toget_label=cond_endlabels.top();
        cond_endlabels.pop();
        tac=toget_label+":";
         prog.push_back(tac);
    }
#line 3145 "lalr1.tab.c"
    break;

  case 22: /* PrintStatement: PRINTLN PrintArgs CLOSE_BR  */
#line 383 "lalr1.y"
                                           {
    (yyval.node)=new astnode;
    (yyval.node)->token="PrintStatement";
    vector<astnode*>v;
    v.push_back((yyvsp[-2].node));
    v.push_back((yyvsp[-1].node));
    v.push_back((yyvsp[0].node));
    (yyval.node)->children=v;
    // cout<<"in"<<$$->token;
    (yyval.node)->tac_val="sys.print "+(yyvsp[-1].node)->tac_val;
    (yyval.node)->type=(yyvsp[-2].node)->type;
    prog.push_back((yyval.node)->tac_val);
    // cout<<$$->tac_val;
    // cout<<"in PrintStatement";
}
#line 3165 "lalr1.tab.c"
    break;

  case 23: /* PrintArgs: PrintArg  */
#line 398 "lalr1.y"
                   {
        (yyval.node)=new astnode;
        (yyval.node)->token="PrintArgs";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        (yyval.node)->type=(yyvsp[0].node)->type;
        // cout<<"in PrintArgs";
        }
#line 3181 "lalr1.tab.c"
    break;

  case 24: /* PrintArgs: PrintArgs ADD PrintArg  */
#line 409 "lalr1.y"
                                {
        (yyval.node)=new astnode;
        (yyval.node)->token="PrintArgs";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        (yyval.node)->tac_val=(yyvsp[-2].node)->tac_val+(yyvsp[-1].node)->lexeme+(yyvsp[0].node)->tac_val;
        (yyval.node)->type=(yyvsp[-2].node)->type;
        // cout<<"in PrintArgs";
}
#line 3199 "lalr1.tab.c"
    break;

  case 25: /* PrintArg: IDENTIFIER  */
#line 422 "lalr1.y"
                    {
        (yyval.node)=new astnode;
        (yyval.node)->token="PrintArgs";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        (yyval.node)->tac_val=(yyvsp[0].node)->lexeme;
        (yyval.node)->type=(yyvsp[0].node)->type;
        // cout<<"in PrintArg";
        }
#line 3215 "lalr1.tab.c"
    break;

  case 26: /* PrintArg: Literal  */
#line 433 "lalr1.y"
                 {
            (yyval.node)=new astnode;
            (yyval.node)->token="PrintArgs";
            vector<astnode*>v;
            v.push_back((yyvsp[0].node));
            (yyval.node)->children=v;
            // cout<<"in"<<$$->token;
            (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
            (yyval.node)->type=(yyvsp[0].node)->type;
        // cout<<"in PrintArg";
        }
#line 3231 "lalr1.tab.c"
    break;

  case 27: /* PrintArg: MethodInvocation  */
#line 444 "lalr1.y"
                          {
            (yyval.node)=new astnode;
            (yyval.node)->token="PrintArgs";
            vector<astnode*>v;
            v.push_back((yyvsp[0].node));
            (yyval.node)->children=v;
            // cout<<"in"<<$$->token;
            (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
            (yyval.node)->type=(yyvsp[0].node)->type;
        // cout<<"in PrintArg";
        }
#line 3247 "lalr1.tab.c"
    break;

  case 28: /* PrintArg: %empty  */
#line 455 "lalr1.y"
          {
        // cout<<"in PrintArg";
        }
#line 3255 "lalr1.tab.c"
    break;

  case 29: /* Literal: INT_LIT  */
#line 461 "lalr1.y"
               {
        (yyval.node)=new astnode;
        (yyval.node)->token="Literal";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->tac_val=(yyvsp[0].node)->lexeme;
        // cout<<"in"<<$$->token;
        (yyval.node)->flag=0;
        (yyval.node)->type="int";
        // cout<<$$->token;
    }
#line 3272 "lalr1.tab.c"
    break;

  case 30: /* Literal: FLOAT_LIT  */
#line 473 "lalr1.y"
                  {
        (yyval.node)=new astnode;
        (yyval.node)->token="Literal";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->tac_val=(yyvsp[0].node)->lexeme;
        // cout<<"in"<<$$->token;
        (yyval.node)->flag=0;
        (yyval.node)->type="float";
    }
#line 3288 "lalr1.tab.c"
    break;

  case 31: /* Literal: BOOL_LIT  */
#line 484 "lalr1.y"
                 {
        (yyval.node)=new astnode;
        (yyval.node)->token="Literal";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->tac_val=(yyvsp[0].node)->lexeme;
        // cout<<"in"<<$$->token;
        (yyval.node)->flag=0;
        (yyval.node)->type="boolean";
    }
#line 3304 "lalr1.tab.c"
    break;

  case 32: /* Literal: CHAR_LIT  */
#line 495 "lalr1.y"
                 {
        (yyval.node)=new astnode;
        (yyval.node)->token="Literal";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->tac_val=(yyvsp[0].node)->lexeme;
        // cout<<"in"<<$$->token;
        (yyval.node)->flag=0;
        (yyval.node)->type="char";
    }
#line 3320 "lalr1.tab.c"
    break;

  case 33: /* Literal: STR_LIT  */
#line 506 "lalr1.y"
                {
        (yyval.node)=new astnode;
        (yyval.node)->token="Literal";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->tac_val=(yyvsp[0].node)->lexeme;
        // cout<<"in"<<$$->token;
        (yyval.node)->flag=0;
        (yyval.node)->type="String";
    }
#line 3336 "lalr1.tab.c"
    break;

  case 34: /* Literal: NULL_LIT  */
#line 517 "lalr1.y"
                 {
        (yyval.node)=new astnode;
        (yyval.node)->token="Literal";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->tac_val=(yyvsp[0].node)->lexeme;
        // cout<<"in"<<$$->token;
        (yyval.node)->flag=0;
        (yyval.node)->type="NULL";
    }
#line 3352 "lalr1.tab.c"
    break;

  case 35: /* Type: PrimitiveType  */
#line 531 "lalr1.y"
                     {
    (yyval.node)=new astnode;
    (yyval.node)->token="Type";
    (yyval.node)->type=(yyvsp[0].node)->type;
    temp_type=(yyval.node)->type;
    vector<astnode*>v;
    v.push_back((yyvsp[0].node));
    (yyval.node)->children=v;
    // cout<<"in"<<$$->token;
}
#line 3367 "lalr1.tab.c"
    break;

  case 36: /* Type: ReferenceType  */
#line 541 "lalr1.y"
                      {
    (yyval.node)=new astnode;
    (yyval.node)->token="Type";
    (yyval.node)->type=(yyvsp[0].node)->type;
    temp_type=(yyval.node)->type;
    vector<astnode*>v;
    v.push_back((yyvsp[0].node));
    (yyval.node)->children=v;
    // cout<<"in"<<$$->token;
}
#line 3382 "lalr1.tab.c"
    break;

  case 37: /* PrimitiveType: NumericType  */
#line 553 "lalr1.y"
                   {
        (yyval.node)=new astnode;
        (yyval.node)->token="PrimitiveType";
        (yyval.node)->type=(yyvsp[0].node)->type;
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 3396 "lalr1.tab.c"
    break;

  case 38: /* PrimitiveType: BOOLEAN  */
#line 562 "lalr1.y"
                {
        (yyval.node)=new astnode;
        (yyval.node)->token="PrimitiveType";
        (yyval.node)->type=(yyvsp[0].node)->lexeme;
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 3410 "lalr1.tab.c"
    break;

  case 39: /* NumericType: IntegralType  */
#line 573 "lalr1.y"
                    {
        (yyval.node)=new astnode;
        (yyval.node)->token="NumericType";
        (yyval.node)->type=(yyvsp[0].node)->type;
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 3424 "lalr1.tab.c"
    break;

  case 40: /* NumericType: FloatingPointType  */
#line 582 "lalr1.y"
                          {
        (yyval.node)=new astnode;
        (yyval.node)->token="NumericType";
        (yyval.node)->type=(yyvsp[0].node)->type;
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 3438 "lalr1.tab.c"
    break;

  case 41: /* IntegralType: BYTE  */
#line 593 "lalr1.y"
            {
        (yyval.node)=new astnode;
        (yyval.node)->token="IntegralType";
        (yyval.node)->type="byte";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 3452 "lalr1.tab.c"
    break;

  case 42: /* IntegralType: SHORT  */
#line 602 "lalr1.y"
          {
        (yyval.node)=new astnode;
        (yyval.node)->token="IntegralType";
        (yyval.node)->type="short";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 3466 "lalr1.tab.c"
    break;

  case 43: /* IntegralType: INT  */
#line 611 "lalr1.y"
        {
        (yyval.node)=new astnode;
        (yyval.node)->token="IntegralType";
        (yyval.node)->type="int";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 3480 "lalr1.tab.c"
    break;

  case 44: /* IntegralType: LONG  */
#line 620 "lalr1.y"
         {
        (yyval.node)=new astnode;
        (yyval.node)->token="IntegralType";
        (yyval.node)->type="long";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 3494 "lalr1.tab.c"
    break;

  case 45: /* IntegralType: CHAR  */
#line 629 "lalr1.y"
         {
        (yyval.node)=new astnode;
        (yyval.node)->token="IntegralType";
        (yyval.node)->type="char";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 3508 "lalr1.tab.c"
    break;

  case 46: /* FloatingPointType: FLOAT  */
#line 640 "lalr1.y"
         {
        (yyval.node)=new astnode;
        (yyval.node)->token="FloatingPointType";
        (yyval.node)->type="float";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 3522 "lalr1.tab.c"
    break;

  case 47: /* FloatingPointType: DOUBLE  */
#line 649 "lalr1.y"
           {
        (yyval.node)=new astnode;
        (yyval.node)->token="FloatingPointType";
        (yyval.node)->type="double";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 3536 "lalr1.tab.c"
    break;

  case 48: /* ReferenceType: ClassOrInterfaceType  */
#line 660 "lalr1.y"
                            {
        (yyval.node)=new astnode;
        (yyval.node)->token="ReferenceType";
        // $$->type="Classorinterface";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        (yyval.node)->type=(yyvsp[0].node)->type;
    }
#line 3552 "lalr1.tab.c"
    break;

  case 49: /* ReferenceType: ArrayType  */
#line 671 "lalr1.y"
                  {
        (yyval.node)=new astnode;
        (yyval.node)->token="ReferenceType";
        // $$->type="array";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        (yyval.node)->type=(yyvsp[0].node)->type;
    }
#line 3567 "lalr1.tab.c"
    break;

  case 50: /* ClassOrInterfaceType: Name  */
#line 683 "lalr1.y"
            {
        (yyval.node)=new astnode;
        (yyval.node)->token="ClassOrInterfaceType";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->value=(yyvsp[0].node)->value;
        // cout<<"in"<<$$->token;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        (yyval.node)->type=(yyvsp[0].node)->type;
    }
#line 3583 "lalr1.tab.c"
    break;

  case 51: /* ClassType: ClassOrInterfaceType  */
#line 696 "lalr1.y"
                            {
        (yyval.node)=new astnode;
        (yyval.node)->token="ClassType";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        (yyval.node)->type=(yyvsp[0].node)->type;
    }
#line 3598 "lalr1.tab.c"
    break;

  case 52: /* InterfaceType: ClassOrInterfaceType  */
#line 708 "lalr1.y"
                            {
        (yyval.node)=new astnode;
        (yyval.node)->token="InterfaceType";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->value=(yyvsp[0].node)->value;
        // cout<<"in"<<$$->token;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        (yyval.node)->type=(yyvsp[0].node)->type;
    }
#line 3614 "lalr1.tab.c"
    break;

  case 53: /* ArrayType: PrimitiveType OPEN_SQ CLOSE_SQ  */
#line 721 "lalr1.y"
                                      {
        (yyval.node)=new astnode;
        (yyval.node)->token="ArrayType";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        (yyval.node)->type=(yyvsp[-2].node)->type;
    }
#line 3630 "lalr1.tab.c"
    break;

  case 54: /* ArrayType: Name OPEN_SQ CLOSE_SQ  */
#line 732 "lalr1.y"
                              {
        (yyval.node)=new astnode;
        (yyval.node)->token="ArrayType";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        (yyval.node)->type=(yyvsp[-2].node)->type;
    }
#line 3646 "lalr1.tab.c"
    break;

  case 55: /* ArrayType: ArrayType OPEN_SQ CLOSE_SQ  */
#line 743 "lalr1.y"
                                   {
        (yyval.node)=new astnode;
        (yyval.node)->token="ArrayType";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        (yyval.node)->type=(yyvsp[-2].node)->type;
    }
#line 3662 "lalr1.tab.c"
    break;

  case 56: /* Name: SingularName  */
#line 757 "lalr1.y"
                    {
        (yyval.node)=new astnode;
        (yyval.node)->token="Name";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->value=(yyvsp[0].node)->value;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        // cout<<"in"<<$$->token;
        (yyval.node)->flag=(yyvsp[0].node)->flag;
        (yyval.node)->type=(yyvsp[0].node)->type;
    }
#line 3679 "lalr1.tab.c"
    break;

  case 57: /* Name: ComplexName  */
#line 769 "lalr1.y"
                    {
        (yyval.node)=new astnode;
        (yyval.node)->token="Name";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->value=(yyvsp[0].node)->value;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        // cout<<"in"<<$$->token;
        (yyval.node)->flag=(yyvsp[0].node)->flag;
        (yyval.node)->type=(yyvsp[0].node)->type;
    }
#line 3696 "lalr1.tab.c"
    break;

  case 58: /* SingularName: IDENTIFIER  */
#line 783 "lalr1.y"
                  {
        (yyval.node)=new astnode;
        (yyval.node)->token="SingularName";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->value=(yyvsp[0].node)->lexeme;
        (yyval.node)->tac_val=(yyvsp[0].node)->lexeme;
        // cout<<"in"<<$$->token;
        (yyval.node)->flag=0;
        // symtab_t* t=symtab_top[fullscope];
        (yyval.node)->type=symtabGetType(fullscope,(yyval.node)->value);
        if((yyval.node)->type=="0"||(yyval.node)->type=="constructor"){
            (yyval.node)->type=(yyvsp[0].node)->lexeme;
        }
    }
#line 3717 "lalr1.tab.c"
    break;

  case 59: /* ComplexName: Name PERIOD IDENTIFIER  */
#line 801 "lalr1.y"
                              {
        (yyval.node)=new astnode;
        (yyval.node)->token="ComplexName";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->value=(yyvsp[-2].node)->value+"."+(yyvsp[0].node)->lexeme;    //changed
        (yyval.node)->tac_val=(yyvsp[-2].node)->tac_val+"."+(yyvsp[0].node)->lexeme;
        // cout<<"in"<<$$->token;
        (yyval.node)->flag=0;
        (yyval.node)->type=symtabGetType(fullscope,(yyval.node)->tac_val);
        if((yyval.node)->type=="0"){
            // cout<<fullscope;
            string s=symtabGetType(fullscope,(yyvsp[-2].node)->value);
            // if(s=="0") cout<<"no object created";
            // cout<<s;
            if(s!="0"){
                symtab_t*t=symtab_top[m1[s]];
                Type*t1=(*t)[(yyvsp[0].node)->lexeme];
                (yyval.node)->type=t1->type;
            }
            // cout<<$$->type;
        }
         else (yyval.node)->type=(yyvsp[-2].node)->lexeme;
    }
#line 3749 "lalr1.tab.c"
    break;

  case 60: /* CompilationUnit: %empty  */
#line 830 "lalr1.y"
                {
        (yyval.node)=new astnode;
        (yyval.node)->token="CompilationUnit";
        vector<astnode*>v;
        v.push_back(NULL);
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 3762 "lalr1.tab.c"
    break;

  case 61: /* CompilationUnit: PackageDeclaration  */
#line 838 "lalr1.y"
                       {
        (yyval.node)=new astnode;
        (yyval.node)->token="CompilationUnit";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 3775 "lalr1.tab.c"
    break;

  case 62: /* CompilationUnit: PackageDeclaration ImportDeclarations  */
#line 846 "lalr1.y"
                                          {
        (yyval.node)=new astnode;
        (yyval.node)->token="CompilationUnit";
        vector<astnode*>v;
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 3789 "lalr1.tab.c"
    break;

  case 63: /* CompilationUnit: PackageDeclaration TypeDeclarations  */
#line 855 "lalr1.y"
                                        {
        (yyval.node)=new astnode;
        (yyval.node)->token="CompilationUnit";
        vector<astnode*>v;
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 3803 "lalr1.tab.c"
    break;

  case 64: /* CompilationUnit: PackageDeclaration ImportDeclarations TypeDeclarations  */
#line 864 "lalr1.y"
                                                           {
        (yyval.node)=new astnode;
        (yyval.node)->token="CompilationUnit";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 3818 "lalr1.tab.c"
    break;

  case 65: /* CompilationUnit: ImportDeclarations TypeDeclarations  */
#line 874 "lalr1.y"
                                        {
        (yyval.node)=new astnode;
        (yyval.node)->token="CompilationUnit";
        vector<astnode*>v;
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 3832 "lalr1.tab.c"
    break;

  case 66: /* CompilationUnit: ImportDeclarations  */
#line 883 "lalr1.y"
                       {
        (yyval.node)=new astnode;
        (yyval.node)->token="SingularName";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 3845 "lalr1.tab.c"
    break;

  case 67: /* CompilationUnit: TypeDeclarations  */
#line 891 "lalr1.y"
                     {
        (yyval.node)=new astnode;
        (yyval.node)->token="CompilationUnit";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 3858 "lalr1.tab.c"
    break;

  case 68: /* ImportDeclarations: ImportDeclaration  */
#line 901 "lalr1.y"
                         {
        (yyval.node)=new astnode;
        (yyval.node)->token="ImportDeclarations";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 3871 "lalr1.tab.c"
    break;

  case 69: /* ImportDeclarations: ImportDeclarations ImportDeclaration  */
#line 909 "lalr1.y"
                                             {
        (yyval.node)=new astnode;
        (yyval.node)->token="ImportDeclarations";
        vector<astnode*>v;
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 3885 "lalr1.tab.c"
    break;

  case 70: /* TypeDeclarations: TypeDeclaration  */
#line 920 "lalr1.y"
                   {
        (yyval.node)=new astnode;
        (yyval.node)->token="TypeDeclarations";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 3898 "lalr1.tab.c"
    break;

  case 71: /* TypeDeclarations: TypeDeclarations TypeDeclaration  */
#line 928 "lalr1.y"
                                         {
        (yyval.node)=new astnode;
        (yyval.node)->token="TypeDeclarations";
        vector<astnode*>v;
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 3912 "lalr1.tab.c"
    break;

  case 72: /* PackageDeclaration: PACKAGE Name SEMICOLON  */
#line 939 "lalr1.y"
                              {
        (yyval.node)=new astnode;
        (yyval.node)->token="PackageDeclaration";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 3927 "lalr1.tab.c"
    break;

  case 73: /* ImportDeclaration: SingleTypeImportDeclaration  */
#line 951 "lalr1.y"
                                   {
        (yyval.node)=new astnode;
        (yyval.node)->token="ImportDeclaration";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        symaddimp((yyvsp[0].node)->tac_val);
        // cout<<"in"<<$$->token;
    }
#line 3941 "lalr1.tab.c"
    break;

  case 74: /* ImportDeclaration: TypeImportOnDemandDeclaration  */
#line 960 "lalr1.y"
                                      {
        (yyval.node)=new astnode;
        (yyval.node)->token="ImportDeclaration";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        symaddimp((yyvsp[0].node)->tac_val);
        // cout<<"in"<<$$->token;
    }
#line 3955 "lalr1.tab.c"
    break;

  case 75: /* SingleTypeImportDeclaration: IMPORT Name SEMICOLON  */
#line 971 "lalr1.y"
                             {
        (yyval.node)=new astnode;
        (yyval.node)->token="SingleTypeImportDeclaration";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->tac_val=(yyvsp[-1].node)->tac_val;
        // cout<<"in"<<$$->token;
    }
#line 3971 "lalr1.tab.c"
    break;

  case 76: /* TypeImportOnDemandDeclaration: IMPORT Name PERIOD MUL SEMICOLON  */
#line 984 "lalr1.y"
                                        {
        (yyval.node)=new astnode;
        (yyval.node)->token="TypeImportOnDemandDeclaration";
        vector<astnode*>v;
        v.push_back((yyvsp[-4].node));
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->tac_val=(yyvsp[-3].node)->tac_val+(yyvsp[-2].node)->lexeme+(yyvsp[-1].node)->lexeme;
        // cout<<"in"<<$$->token;
    }
#line 3989 "lalr1.tab.c"
    break;

  case 77: /* TypeDeclaration: ClassDeclaration  */
#line 999 "lalr1.y"
                        {
        (yyval.node)=new astnode;
        (yyval.node)->token="TypeDeclaration";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->type=(yyvsp[0].node)->type;
        // cout<<"in"<<$$->token;
    }
#line 4003 "lalr1.tab.c"
    break;

  case 78: /* TypeDeclaration: InterfaceDeclaration  */
#line 1008 "lalr1.y"
                             {
        (yyval.node)=new astnode;
        (yyval.node)->token="TypeDeclaration";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->type=(yyvsp[0].node)->type;
        // cout<<"in"<<$$->token;
    }
#line 4017 "lalr1.tab.c"
    break;

  case 79: /* TypeDeclaration: SEMICOLON  */
#line 1017 "lalr1.y"
                  {
        (yyval.node)=new astnode;
        (yyval.node)->token="TypeDeclaration";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 4030 "lalr1.tab.c"
    break;

  case 80: /* Modifiers: Modifier  */
#line 1027 "lalr1.y"
                {
        (yyval.node)=new astnode;
        (yyval.node)->token="Modifiers";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->access_specifier=(yyvsp[0].node)->access_specifier;
        // cout<<"in"<<$$->token;
    }
#line 4044 "lalr1.tab.c"
    break;

  case 81: /* Modifiers: Modifiers Modifier  */
#line 1036 "lalr1.y"
                           {
        (yyval.node)=new astnode;
        (yyval.node)->token="Modifiers";
        vector<astnode*>v;
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        if((yyvsp[-1].node)->access_specifier==0||(yyvsp[0].node)->access_specifier==0) (yyval.node)->access_specifier=0;
        // cout<<"in"<<$$->token;
    }
#line 4059 "lalr1.tab.c"
    break;

  case 82: /* Modifier: PUBLIC  */
#line 1048 "lalr1.y"
              {
        (yyval.node)=new astnode;
        (yyval.node)->token="Modifier";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 4072 "lalr1.tab.c"
    break;

  case 83: /* Modifier: PROTECTED  */
#line 1056 "lalr1.y"
                  {
        (yyval.node)=new astnode;
        (yyval.node)->token="Modifier";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 4085 "lalr1.tab.c"
    break;

  case 84: /* Modifier: PRIVATE  */
#line 1064 "lalr1.y"
                {
        (yyval.node)=new astnode;
        (yyval.node)->token="Modifier";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->access_specifier=0;
        // cout<<"in"<<$$->token;
    }
#line 4099 "lalr1.tab.c"
    break;

  case 85: /* Modifier: STATIC  */
#line 1073 "lalr1.y"
               {
        (yyval.node)=new astnode;
        (yyval.node)->token="Modifier";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 4112 "lalr1.tab.c"
    break;

  case 86: /* Modifier: ABSTRACT  */
#line 1081 "lalr1.y"
                 {
        (yyval.node)=new astnode;
        (yyval.node)->token="Modifier";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 4125 "lalr1.tab.c"
    break;

  case 87: /* Modifier: FINAL  */
#line 1089 "lalr1.y"
              {
        (yyval.node)=new astnode;
        (yyval.node)->token="Modifier";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 4138 "lalr1.tab.c"
    break;

  case 88: /* Modifier: NATIVE  */
#line 1097 "lalr1.y"
               {
        (yyval.node)=new astnode;
        (yyval.node)->token="Modifier";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 4151 "lalr1.tab.c"
    break;

  case 89: /* Modifier: SYNCHRONIZED  */
#line 1105 "lalr1.y"
                     {
        (yyval.node)=new astnode;
        (yyval.node)->token="Modifier";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 4164 "lalr1.tab.c"
    break;

  case 90: /* Modifier: TRANSIENT  */
#line 1113 "lalr1.y"
                  {
        (yyval.node)=new astnode;
        (yyval.node)->token="Modifier";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 4177 "lalr1.tab.c"
    break;

  case 91: /* Modifier: VOLATILE  */
#line 1121 "lalr1.y"
                 {
        (yyval.node)=new astnode;
        (yyval.node)->token="Modifier";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 4190 "lalr1.tab.c"
    break;

  case 92: /* ClassName: IDENTIFIER  */
#line 1132 "lalr1.y"
               {
        (yyval.node)=new astnode;
        (yyval.node)->token="ClassName";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        cname=(yyvsp[0].node)->lexeme;
        fname=cname;
        (yyval.node)->value=(yyvsp[0].node)->lexeme;
        (yyval.node)->type=(yyvsp[0].node)->type;
        class_labels.push((yyvsp[0].node)->lexeme);
    }
#line 4207 "lalr1.tab.c"
    break;

  case 93: /* ClassDeclaration: Modifiers CLASS ClassName Super Interfaces ClassBody  */
#line 1146 "lalr1.y"
                                                            {
        (yyval.node)=new astnode;
        (yyval.node)->token="ClassDeclaration";
        vector<astnode*>v;
        v.push_back((yyvsp[-5].node));
        v.push_back((yyvsp[-4].node));
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        symadd((yyvsp[-3].node)->value,"class_"+(yyvsp[-3].node)->value,(yyvsp[-1].node)->value);
        (yyval.node)->type=(yyvsp[-3].node)->type;
        // cout<<"in"<<$$->token;
    }
#line 4227 "lalr1.tab.c"
    break;

  case 94: /* ClassDeclaration: Modifiers CLASS ClassName Super ClassBody  */
#line 1161 "lalr1.y"
                                                  {
        (yyval.node)=new astnode;
        (yyval.node)->token="ClassDeclaration";
        vector<astnode*>v;
        v.push_back((yyvsp[-4].node));
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        symadd((yyvsp[-2].node)->value,"class_"+(yyvsp[-2].node)->value,"NULL");
        (yyval.node)->type=(yyvsp[-2].node)->type;
        // cout<<"in"<<$$->token;
    }
#line 4246 "lalr1.tab.c"
    break;

  case 95: /* ClassDeclaration: Modifiers CLASS ClassName Interfaces ClassBody  */
#line 1175 "lalr1.y"
                                                       {
        (yyval.node)=new astnode;
        (yyval.node)->token="ClassDeclaration";
        vector<astnode*>v;
        v.push_back((yyvsp[-4].node));
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        symadd((yyvsp[-2].node)->value,"class_"+(yyvsp[-2].node)->value,(yyvsp[-1].node)->value);
        (yyval.node)->type=(yyvsp[-2].node)->type;
        // cout<<"in"<<$$->token;
    }
#line 4265 "lalr1.tab.c"
    break;

  case 96: /* ClassDeclaration: Modifiers CLASS ClassName ClassBody  */
#line 1189 "lalr1.y"
                                            {
        (yyval.node)=new astnode;
        (yyval.node)->token="ClassDeclaration";
        vector<astnode*>v;
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        symadd((yyvsp[-1].node)->value,"class_"+(yyvsp[-1].node)->value,"NULL");
        (yyval.node)->type=(yyvsp[-1].node)->type;
        // cout<<"in"<<$$->token;
    }
#line 4283 "lalr1.tab.c"
    break;

  case 97: /* ClassDeclaration: CLASS ClassName Super Interfaces ClassBody  */
#line 1202 "lalr1.y"
                                                   {
        (yyval.node)=new astnode;
        (yyval.node)->token="ClassDeclaration";
        vector<astnode*>v;
        v.push_back((yyvsp[-4].node));
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        symadd((yyvsp[-3].node)->value,"class_"+(yyvsp[-3].node)->value,(yyvsp[-1].node)->value);
        (yyval.node)->type=(yyvsp[-3].node)->type;
        // cout<<"in"<<$$->token;
    }
#line 4302 "lalr1.tab.c"
    break;

  case 98: /* ClassDeclaration: CLASS ClassName Super ClassBody  */
#line 1216 "lalr1.y"
                                        {
        (yyval.node)=new astnode;
        (yyval.node)->token="ClassDeclaration";
        vector<astnode*>v;
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        symadd((yyvsp[-2].node)->value,"class_"+(yyvsp[-2].node)->value,"NULL");
        (yyval.node)->type=(yyvsp[-2].node)->type;
        // cout<<"in"<<$$->token;
    }
#line 4320 "lalr1.tab.c"
    break;

  case 99: /* ClassDeclaration: CLASS ClassName Interfaces ClassBody  */
#line 1229 "lalr1.y"
                                             {
        (yyval.node)=new astnode;
        (yyval.node)->token="ClassDeclaration";
        vector<astnode*>v;
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        symadd((yyvsp[-2].node)->value,"class_"+(yyvsp[-2].node)->value,(yyvsp[-1].node)->value);
        (yyval.node)->type=(yyvsp[-2].node)->type;
        // cout<<"in"<<$$->token;
    }
#line 4338 "lalr1.tab.c"
    break;

  case 100: /* ClassDeclaration: CLASS ClassName ClassBody  */
#line 1242 "lalr1.y"
                                  {
        (yyval.node)=new astnode;
        (yyval.node)->token="ClassDeclaration";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        symadd((yyvsp[-1].node)->value,"class_"+(yyvsp[-1].node)->value,"NULL");
        (yyval.node)->type=(yyvsp[-1].node)->type;
        // cout<<"in"<<$$->token;
    }
#line 4355 "lalr1.tab.c"
    break;

  case 101: /* Super: EXTENDS ClassType  */
#line 1256 "lalr1.y"
                         {
        (yyval.node)=new astnode;
        (yyval.node)->token="Super";
        vector<astnode*>v;
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        (yyval.node)->type=(yyvsp[0].node)->type;
    }
#line 4370 "lalr1.tab.c"
    break;

  case 102: /* Interfaces: IMPLEMENTS InterfaceTypeList  */
#line 1268 "lalr1.y"
                                    {
        (yyval.node)=new astnode;
        (yyval.node)->token="Interfaces";
        vector<astnode*>v;
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->value=(yyvsp[0].node)->value;
        // cout<<"in"<<$$->token;
    }
#line 4385 "lalr1.tab.c"
    break;

  case 103: /* InterfaceTypeList: InterfaceType  */
#line 1280 "lalr1.y"
                     {
        (yyval.node)=new astnode;
        (yyval.node)->token="InterfaceTypeList";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->value=(yyvsp[0].node)->value;
        // cout<<"in"<<$$->token;
    }
#line 4399 "lalr1.tab.c"
    break;

  case 104: /* InterfaceTypeList: InterfaceTypeList COMMA InterfaceType  */
#line 1289 "lalr1.y"
                                              {
        (yyval.node)=new astnode;
        (yyval.node)->token="InterfaceTypeList";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->value=(yyvsp[-2].node)->value+","+(yyvsp[0].node)->value;
        // cout<<"in"<<$$->token;
    }
#line 4415 "lalr1.tab.c"
    break;

  case 105: /* CLASSMARK1: %empty  */
#line 1302 "lalr1.y"
    {
        string n=class_labels.top();
        class_labels.pop();
        m1[n]=fullscope;
        // cout<<fullscope<<" ";
    }
#line 4426 "lalr1.tab.c"
    break;

  case 106: /* ClassBody: OPEN_CR SYMTABS CLASSMARK1 ClassBodyDeclarations CLOSE_CR SYMTABE  */
#line 1310 "lalr1.y"
                                                                         {
        // cout<<"entered in classBody ";
        (yyval.node)=new astnode;
        (yyval.node)->token="ClassBody";
        vector<astnode*>v;
        v.push_back((yyvsp[-5].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 4442 "lalr1.tab.c"
    break;

  case 107: /* ClassBody: OPEN_CR CLOSE_CR  */
#line 1321 "lalr1.y"
                         {
        (yyval.node)=new astnode;
        (yyval.node)->token="ClassBody";
        vector<astnode*>v;
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 4456 "lalr1.tab.c"
    break;

  case 108: /* ClassBodyDeclarations: ClassBodyDeclaration  */
#line 1332 "lalr1.y"
                            {
        (yyval.node)=new astnode;
        (yyval.node)->token="ClassBodyDeclarations";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 4469 "lalr1.tab.c"
    break;

  case 109: /* ClassBodyDeclarations: ClassBodyDeclarations ClassBodyDeclaration  */
#line 1340 "lalr1.y"
                                                   {
        (yyval.node)=new astnode;
        (yyval.node)->token="ClassBodyDeclarations";
        vector<astnode*>v;
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 4483 "lalr1.tab.c"
    break;

  case 110: /* ClassBodyDeclaration: ClassMemberDeclaration  */
#line 1351 "lalr1.y"
                              {
        (yyval.node)=new astnode;
        (yyval.node)->token="ClassBodyDeclaration";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->type=(yyvsp[0].node)->type;
        // cout<<"in"<<$$->token;
    }
#line 4497 "lalr1.tab.c"
    break;

  case 111: /* ClassBodyDeclaration: StaticInitializer  */
#line 1360 "lalr1.y"
                          {
        (yyval.node)=new astnode;
        (yyval.node)->token="ClassBodyDeclaration";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->type=(yyvsp[0].node)->type;
        // cout<<"in"<<$$->token;
    }
#line 4511 "lalr1.tab.c"
    break;

  case 112: /* ClassBodyDeclaration: ConstructorDeclaration  */
#line 1369 "lalr1.y"
                               {
        (yyval.node)=new astnode;
        (yyval.node)->token="ClassBodyDeclaration";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->type=(yyvsp[0].node)->type;
        // cout<<"in"<<$$->token;
    }
#line 4525 "lalr1.tab.c"
    break;

  case 113: /* ClassMemberDeclaration: FieldDeclaration  */
#line 1380 "lalr1.y"
                        {
        (yyval.node)=new astnode;
        (yyval.node)->token="ClassMemberDeclarations";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->type=(yyvsp[0].node)->type;
        // cout<<"in"<<$$->token;
    }
#line 4539 "lalr1.tab.c"
    break;

  case 114: /* ClassMemberDeclaration: MethodDeclaration  */
#line 1389 "lalr1.y"
                          {
        (yyval.node)=new astnode;
        (yyval.node)->token="ClassMemberDeclarations";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->type=(yyvsp[0].node)->type;
        // cout<<"in"<<$$->token;
    }
#line 4553 "lalr1.tab.c"
    break;

  case 115: /* FieldDeclaration: Modifiers Type VariableDeclarators SEMICOLON  */
#line 1401 "lalr1.y"
                                                    {
        (yyval.node)=new astnode;
        (yyval.node)->token="FieldDeclaration";
        vector<astnode*>v;
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        string s=(yyvsp[-1].node)->value;
        vector<string>tokens=split(s,',');
        // cout<<"\n executing symadd_list\n";
        symadd_list(tokens,(yyvsp[-2].node)->type);
        // cout<<"in"<<$$->token;
        (yyvsp[-1].node)->type=(yyvsp[-2].node)->type;
        temp_type="";
    }
#line 4575 "lalr1.tab.c"
    break;

  case 116: /* FieldDeclaration: Type VariableDeclarators SEMICOLON  */
#line 1418 "lalr1.y"
                                           {
        (yyval.node)=new astnode;
        (yyval.node)->token="FieldDeclaration";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        string s=(yyvsp[-1].node)->value;
        vector<string>tokens=split(s,',');
        // cout<<"\n executing symadd_list\n";
        symadd_list(tokens,(yyvsp[-2].node)->type);
        // cout<<"in"<<$$->token;
        (yyvsp[-1].node)->type=(yyvsp[-2].node)->type;
        temp_type="";
    }
#line 4596 "lalr1.tab.c"
    break;

  case 117: /* VariableDeclarators: VariableDeclarator  */
#line 1436 "lalr1.y"
                          {
        (yyval.node)=new astnode;
        (yyval.node)->token="VariableDeclarators";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->value=(yyvsp[0].node)->value;
        // cout<<"in"<<$$->token;
        (yyval.node)->type=temp_type;
        (yyval.node)->flag=(yyvsp[0].node)->flag;
        if((yyvsp[0].node)->flag==4) {
            // $$->tuples=$1->tuples;
            (yyval.node)->length=(yyvsp[0].node)->length;
        }
        (yyval.node)->dims=(yyvsp[0].node)->dims;
    }
#line 4617 "lalr1.tab.c"
    break;

  case 118: /* VariableDeclarators: VariableDeclarators COMMA VariableDeclarator  */
#line 1452 "lalr1.y"
                                                     {
        (yyval.node)=new astnode;
        (yyval.node)->token="VariableDeclarators";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->value = (yyvsp[-2].node)->value+","+(yyvsp[0].node)->value;
        // cout<<"in"<<$$->token;
        temp=symtypeEvaluate((yyvsp[-2].node)->type,(yyvsp[0].node)->type);
        if(temp=="0")
        {
            cout<<"Not all variables are of same type";
        }
        (yyval.node)->type=temp;
    }
#line 4639 "lalr1.tab.c"
    break;

  case 119: /* VariableDeclarator: VariableDeclaratorId  */
#line 1471 "lalr1.y"
                            {
        (yyval.node)=new astnode;
        (yyval.node)->token="VariableDeclarator";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->value=(yyvsp[0].node)->value;
        // cout<<"in"<<$$->token;
        (yyval.node)->flag=(yyvsp[0].node)->flag;
        (yyval.node)->dims=(yyvsp[0].node)->dims;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        (yyval.node)->type=(yyvsp[0].node)->type;
    }
#line 4657 "lalr1.tab.c"
    break;

  case 120: /* VariableDeclarator: VariableDeclaratorId ASSIGN VariableInitializer  */
#line 1484 "lalr1.y"
                                                        {
        (yyval.node)=new astnode;
        (yyval.node)->token="VariableDeclarator";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->value=(yyvsp[-2].node)->value;
        // cout<<"in"<<$$->token;
        (yyval.node)->tac_val=(yyvsp[-2].node)->tac_val;
        string tac;
        temp=symAssignment((yyvsp[-2].node)->type,(yyvsp[0].node)->type);
        // cout<<$1->type<<" "<<$3->type;
        if(temp=="0")
        {
            cout<<"type mismatch";
            //uncomment
        }
        if((yyvsp[-2].node)->type != (yyvsp[0].node)->type)
        {    string t=get_tempvar();
             s1=t+" =cast_to_"+temp+" "+(yyvsp[0].node)->tac_val;
            prog.push_back(s1);
        }
        
        (yyval.node)->type=temp;
        if(fname==cname)
        tac=fname+"."+(yyvsp[-2].node)->tac_val+" = "+(yyvsp[0].node)->tac_val;
        else if((yyvsp[0].node)->flag==1) tac=(yyvsp[-2].node)->tac_val+" = t"+to_string(tempno-1);
        else tac=(yyvsp[-2].node)->tac_val+" = "+(yyvsp[0].node)->tac_val;
         prog.push_back(tac);
        if((yyvsp[0].node)->flag==3) {
            tac="*"+(yyvsp[-2].node)->tac_val+" = t"+to_string(tempno-1);
             prog.push_back(tac);
        }
        if((yyvsp[0].node)->flag==4) {
            tac=(yyvsp[-2].node)->tac_val+" = "+"&t"+to_string(tempno-1);
             prog.push_back(tac);
            vector<string>v1=split((yyvsp[0].node)->value,',');
            int l=(yyvsp[0].node)->length;
            for(int i=0;i<l;i++) {
                string s1="*(";
                string s2="+";
                string s3=") = ";
                tac=s1+(yyvsp[-2].node)->tac_val+s2+to_string(i*4)+s3+v1[i];
                 prog.push_back(tac);
            }
            (yyval.node)->length=(yyvsp[0].node)->length;
            // $$->tuples=$3->tuples;
            if((yyvsp[-2].node)->dims!=(yyvsp[0].node)->dims && (yyvsp[-2].node)->flag==4){
            cout<<"Arrays not of same dimension";
        }
        }
        // cout<<"\n"<<$1->dims<<" "<<$3->dims;
        
        (yyval.node)->flag=(yyvsp[-2].node)->flag;
        (yyval.node)->dims=(yyvsp[-2].node)->dims;
    }
#line 4720 "lalr1.tab.c"
    break;

  case 121: /* VariableDeclaratorId: IDENTIFIER  */
#line 1544 "lalr1.y"
                  {
        (yyval.node)=new astnode;
        (yyval.node)->token="VariableDeclaratorId";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->value=(yyvsp[0].node)->lexeme;
        // cout<<"in"<<$$->token;
        (yyval.node)->tac_val=(yyvsp[0].node)->lexeme;
        // gpara=$1->lexeme;
        (yyval.node)->flag=(yyvsp[0].node)->flag;
        (yyval.node)->dims=(yyvsp[0].node)->dims;
        if(temp_type!="")
            (yyval.node)->type=temp_type;
        // else
        // {
        //     symtab_t* t=symtab_top[fullscope];
        //     $$->type=symtabGetType(t,$$->value);
        // }
    }
#line 4745 "lalr1.tab.c"
    break;

  case 122: /* VariableDeclaratorId: VariableDeclaratorId OPEN_SQ CLOSE_SQ  */
#line 1564 "lalr1.y"
                                              {
        (yyval.node)=new astnode;
        (yyval.node)->token="VariableDeclaratorId";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->value=(yyvsp[-2].node)->value;
        // cout<<"in"<<$$->token;
        (yyval.node)->tac_val=(yyvsp[-2].node)->tac_val+"[]";
        (yyval.node)->dims=(yyvsp[-2].node)->dims+1;
        // gpara=$$->tac;
        if((yyval.node)->value!="args")
        {
            if(temp_type!="")
            (yyval.node)->type=temp_type;
            // else
            // {
            //     symtab_t* t=symtab_top[fullscope];
            //     $$->type=symtabGetType(t,$$->value);
            // }
        }
        else
        {
            (yyval.node)->type="String";
        }
        (yyval.node)->flag=4;
    }
#line 4779 "lalr1.tab.c"
    break;

  case 123: /* VariableInitializer: Expression  */
#line 1595 "lalr1.y"
                  {
        (yyval.node)=new astnode;
        (yyval.node)->token="VariableInitializer";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        (yyval.node)->flag=(yyvsp[0].node)->flag;
        (yyval.node)->type=(yyvsp[0].node)->type;
        (yyval.node)->dims=(yyvsp[0].node)->dims;
        (yyval.node)->space=(yyvsp[0].node)->space;
        (yyval.node)->value=(yyvsp[0].node)->tac_val;
    }
#line 4798 "lalr1.tab.c"
    break;

  case 124: /* VariableInitializer: ArrayInitializer  */
#line 1609 "lalr1.y"
                         {
        (yyval.node)=new astnode;
        (yyval.node)->token="VariableInitializer";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        (yyval.node)->flag=(yyvsp[0].node)->flag;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        // $$->tuples=$1->tuples;
        (yyval.node)->length=(yyvsp[0].node)->length;
        (yyval.node)->type=(yyvsp[0].node)->type;
        (yyval.node)->dims=(yyvsp[0].node)->dims;
        (yyval.node)->space=(yyvsp[0].node)->space;
        (yyval.node)->value=(yyvsp[0].node)->value;
    }
#line 4819 "lalr1.tab.c"
    break;

  case 125: /* MethodDeclaration: MethodHeader MethodBody  */
#line 1628 "lalr1.y"
                               {
        (yyval.node)=new astnode;
        (yyval.node)->token="MethodDeclaration";
        vector<astnode*>v;
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        (yyval.node)->type=(yyvsp[-1].node)->type;
        fname=cname;
        string tac;
        // string scope;
        // scope=fullscope+"/"+to_string(currscope);
        // cout<<scope<<endl;
        // symtab_t* tab=symtab_top[scope];
        // tac="SP = SP +"+getoffset(tab,0); prog.push_back(tac);
        tac="Pop BP_old";
         prog.push_back(tac);
        tac="BP = BP_old";
         prog.push_back(tac);
        tac="return";
         prog.push_back(tac);
        tac="endfunc";
        prog.push_back(tac);
    }
#line 4849 "lalr1.tab.c"
    break;

  case 126: /* MethodHeader: Modifiers Type MethodDeclarator Throws  */
#line 1655 "lalr1.y"
                                              {
        (yyval.node)=new astnode;
        (yyval.node)->token="MethodHeader";
        vector<astnode*>v;
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        symadd((yyvsp[-1].node)->name,(yyvsp[-2].node)->type,(yyvsp[-1].node)->value,(yyvsp[-3].node)->access_specifier);
        (yyval.node)->type=(yyvsp[-2].node)->type;
        // cout<<"in"<<$$->token;

    }
#line 4868 "lalr1.tab.c"
    break;

  case 127: /* MethodHeader: Modifiers Type MethodDeclarator  */
#line 1669 "lalr1.y"
                                        {
        (yyval.node)=new astnode;
        (yyval.node)->token="MethodHeader";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        symadd((yyvsp[0].node)->name,(yyvsp[-1].node)->type,(yyvsp[0].node)->value,(yyvsp[-2].node)->access_specifier);
        (yyval.node)->type=(yyvsp[-1].node)->type;
        // cout<<"in"<<$$->token;
    }
#line 4885 "lalr1.tab.c"
    break;

  case 128: /* MethodHeader: Type MethodDeclarator Throws  */
#line 1681 "lalr1.y"
                                     {
        (yyval.node)=new astnode;
        (yyval.node)->token="MethodHeader";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        symadd((yyvsp[-1].node)->name,(yyvsp[-2].node)->type,(yyvsp[-1].node)->value);
        (yyval.node)->type=(yyvsp[-2].node)->type;
        // cout<<"in"<<$$->token;
    }
#line 4902 "lalr1.tab.c"
    break;

  case 129: /* MethodHeader: Type MethodDeclarator  */
#line 1693 "lalr1.y"
                              {
        (yyval.node)=new astnode;
        (yyval.node)->token="MethodHeader";
        vector<astnode*>v;
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        symadd((yyvsp[0].node)->name,(yyvsp[-1].node)->type,(yyvsp[0].node)->value);
        (yyval.node)->type=(yyvsp[-1].node)->type;
        // cout<<"in"<<$$->token;
    }
#line 4918 "lalr1.tab.c"
    break;

  case 130: /* MethodHeader: Modifiers VOID MethodDeclarator Throws  */
#line 1704 "lalr1.y"
                                               {
        (yyval.node)=new astnode;
        (yyval.node)->token="MethodHeader";
        vector<astnode*>v;
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        symadd((yyvsp[-1].node)->name,"void",(yyvsp[-1].node)->value,(yyvsp[-3].node)->access_specifier);
        (yyval.node)->type="void";
        // cout<<"in"<<$$->token;
    }
#line 4936 "lalr1.tab.c"
    break;

  case 131: /* MethodHeader: Modifiers VOID MethodDeclarator  */
#line 1717 "lalr1.y"
                                        {
        (yyval.node)=new astnode;
        (yyval.node)->token="MethodHeader";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        symadd((yyvsp[0].node)->name,"void",(yyvsp[0].node)->value,(yyvsp[-2].node)->access_specifier);
        (yyval.node)->type="void";
        // cout<<"in"<<$$->token;
    }
#line 4953 "lalr1.tab.c"
    break;

  case 132: /* MethodHeader: VOID MethodDeclarator Throws  */
#line 1729 "lalr1.y"
                                     {
        (yyval.node)=new astnode;
        (yyval.node)->token="MethodHeader";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        symadd((yyvsp[-1].node)->name,"void",(yyvsp[-1].node)->value);
        (yyval.node)->type="void";
        // cout<<"in"<<$$->token;
    }
#line 4970 "lalr1.tab.c"
    break;

  case 133: /* MethodHeader: VOID MethodDeclarator  */
#line 1741 "lalr1.y"
                              {
        (yyval.node)=new astnode;
        (yyval.node)->token="MethodHeader";
        vector<astnode*>v;
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        symadd((yyvsp[0].node)->name,"void",(yyvsp[0].node)->value);
        (yyval.node)->type="void";
        // cout<<"in"<<$$->token;
    }
#line 4986 "lalr1.tab.c"
    break;

  case 134: /* MethodDeclarator: FunctionName OPEN_BR FormalParameterLists CLOSE_BR  */
#line 1754 "lalr1.y"
                                                          {
        (yyval.node)=new astnode;
        (yyval.node)->token="MethodDeclarator";
        vector<astnode*>v;
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->name=(yyvsp[-3].node)->name;
        (yyval.node)->value=(yyvsp[-1].node)->type;
        // cout<<"in"<<$$->token;
    }
#line 5004 "lalr1.tab.c"
    break;

  case 135: /* MethodDeclarator: FunctionName OPEN_BR CLOSE_BR  */
#line 1767 "lalr1.y"
                                      {
        (yyval.node)=new astnode;
        (yyval.node)->token="MethodDeclarator";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->name=(yyvsp[-2].node)->name;
        // cout<<"in"<<$$->token;
    }
#line 5020 "lalr1.tab.c"
    break;

  case 136: /* MethodDeclarator: MethodDeclarator OPEN_SQ CLOSE_SQ  */
#line 1778 "lalr1.y"
                                          {
        (yyval.node)=new astnode;
        (yyval.node)->token="MethodDeclarator";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->name=(yyvsp[-2].node)->name;
        (yyval.node)->value=(yyvsp[-2].node)->type;
        // cout<<"in"<<$$->token;
    }
#line 5037 "lalr1.tab.c"
    break;

  case 137: /* FunctionName: IDENTIFIER  */
#line 1792 "lalr1.y"
              {
        (yyval.node)=new astnode;
        (yyval.node)->token="FunctionName";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->name=(yyvsp[0].node)->lexeme;
        (yyval.node)->value=(yyvsp[0].node)->type;
        // cout<<"in"<<$$->token;
        string tac;
        if((yyvsp[0].node)->lexeme!="main")
        tac="define "+cname+"."+(yyvsp[0].node)->lexeme+":";
        else tac="define "+(yyvsp[0].node)->lexeme+":";
         prog.push_back(tac);
        fname="fname";
        tac="beginfunc";
        prog.push_back(tac);
        // string tac;
        tac="obj_ref = popparam";
        prog.push_back(tac);
        tac="return_addr = SP + 4";
        
        prog.push_back(tac);
        tac="push BP";
        
        prog.push_back(tac);
        tac="BP = SP";
        
        prog.push_back(tac);

    }
#line 5073 "lalr1.tab.c"
    break;

  case 138: /* FormalParameterLists: FormalParameterList  */
#line 1825 "lalr1.y"
                       {
        (yyval.node)=new astnode;
        (yyval.node)->token="FormalParameterLists";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->type=(yyvsp[0].node)->type;
        (yyval.node)->value=(yyvsp[0].node)->value;
        // cout<<"in"<<$$->token;
        string s=(yyvsp[0].node)->tac_val,tac;
        vector<string>token=split(s,',');
        tac="args_num "+to_string(token.size());
         prog.push_back(tac);
        for(int i=token.size()-1;i>=0;i--) {
            tac="pop "+fullscope+"/"+to_string(currscope+1)+" "+token[i];
             prog.push_back(tac);
        }
        
    }
#line 5097 "lalr1.tab.c"
    break;

  case 139: /* FormalParameterList: FormalParameter  */
#line 1846 "lalr1.y"
                       {
        (yyval.node)=new astnode;
        (yyval.node)->token="FormalParameterList";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->type=(yyvsp[0].node)->type;
        (yyval.node)->value=(yyvsp[0].node)->value;
        // cout<<"in"<<$$->token;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
    }
#line 5113 "lalr1.tab.c"
    break;

  case 140: /* FormalParameterList: FormalParameterList COMMA FormalParameter  */
#line 1857 "lalr1.y"
                                                  {
        (yyval.node)=new astnode;
        (yyval.node)->token="FormalParameterList";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->type=(yyvsp[-2].node)->type+","+(yyvsp[0].node)->type;
        (yyval.node)->value=(yyvsp[-2].node)->value+","+(yyvsp[0].node)->value;
        // cout<<"in"<<$$->token;
        (yyval.node)->tac_val=(yyvsp[-2].node)->tac_val+","+(yyvsp[0].node)->tac_val;
    }
#line 5131 "lalr1.tab.c"
    break;

  case 141: /* FormalParameter: Type VariableDeclaratorId  */
#line 1872 "lalr1.y"
                                 {
        (yyval.node)=new astnode;
        (yyval.node)->token="FormalParameter";
        vector<astnode*>v;
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->type=(yyvsp[-1].node)->type;
        (yyval.node)->value=(yyvsp[0].node)->value;
        buffer[(yyvsp[0].node)->value]=(yyvsp[-1].node)->type;
        // cout<<"in"<<$$->token;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        (yyvsp[0].node)->type=(yyvsp[-1].node)->type;
    }
#line 5150 "lalr1.tab.c"
    break;

  case 142: /* Throws: THROWS ClassTypeList  */
#line 1888 "lalr1.y"
                            {
        (yyval.node)=new astnode;
        (yyval.node)->token="Throws";
        vector<astnode*>v;
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 5164 "lalr1.tab.c"
    break;

  case 143: /* ClassTypeList: ClassType  */
#line 1899 "lalr1.y"
                 {
        (yyval.node)=new astnode;
        (yyval.node)->token="ClassTypeList";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 5177 "lalr1.tab.c"
    break;

  case 144: /* ClassTypeList: ClassTypeList COMMA ClassType  */
#line 1907 "lalr1.y"
                                      {
        (yyval.node)=new astnode;
        (yyval.node)->token="ClassTypeList";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 5192 "lalr1.tab.c"
    break;

  case 145: /* MethodBody: Block  */
#line 1919 "lalr1.y"
              {
        (yyval.node)=new astnode;
        (yyval.node)->token="MethodBody";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 5205 "lalr1.tab.c"
    break;

  case 146: /* MethodBody: SEMICOLON  */
#line 1927 "lalr1.y"
                  {
        (yyval.node)=new astnode;
        (yyval.node)->token="MethodBody";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 5218 "lalr1.tab.c"
    break;

  case 147: /* StaticInitializer: STATIC Block  */
#line 1938 "lalr1.y"
                    {
        (yyval.node)=new astnode;
        (yyval.node)->token="StaticInitializer";
        vector<astnode*>v;
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 5232 "lalr1.tab.c"
    break;

  case 148: /* ConstructorDeclaration: Modifiers ConstructorDeclarator Throws ConstructorBody  */
#line 1950 "lalr1.y"
                                                              {
        (yyval.node)=new astnode;
        (yyval.node)->token="ConstructorDeclaration";
        vector<astnode*>v;
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 5248 "lalr1.tab.c"
    break;

  case 149: /* ConstructorDeclaration: Modifiers ConstructorDeclarator ConstructorBody  */
#line 1961 "lalr1.y"
                                                        {
        (yyval.node)=new astnode;
        (yyval.node)->token="ConstructorDeclaration";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 5263 "lalr1.tab.c"
    break;

  case 150: /* ConstructorDeclaration: ConstructorDeclarator Throws ConstructorBody  */
#line 1971 "lalr1.y"
                                                     {
        (yyval.node)=new astnode;
        (yyval.node)->token="ConstructorDeclaration";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 5278 "lalr1.tab.c"
    break;

  case 151: /* ConstructorDeclaration: ConstructorDeclarator ConstructorBody  */
#line 1981 "lalr1.y"
                                              {
        (yyval.node)=new astnode;
        (yyval.node)->token="ConstructorDeclaration";
        vector<astnode*>v;
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 5292 "lalr1.tab.c"
    break;

  case 152: /* ConstructorDeclarator: ConstructorName OPEN_BR FormalParameterLists CLOSE_BR  */
#line 1993 "lalr1.y"
                                                             {
        (yyval.node)=new astnode;
        (yyval.node)->token="ConstructorDeclarator";
        vector<astnode*>v;
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        symadd((yyvsp[-3].node)->name,"constructor",(yyvsp[-1].node)->type);
        // cout<<"in"<<$$->token;
    }
#line 5309 "lalr1.tab.c"
    break;

  case 153: /* ConstructorDeclarator: ConstructorName OPEN_BR CLOSE_BR  */
#line 2005 "lalr1.y"
                                         {
        (yyval.node)=new astnode;
        (yyval.node)->token="ConstructorDeclarator";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        symadd((yyvsp[-2].node)->name,"constructor");
        // cout<<"in"<<$$->token;
    }
#line 5325 "lalr1.tab.c"
    break;

  case 154: /* ConstructorName: SingularName  */
#line 2018 "lalr1.y"
                {
        (yyval.node)=new astnode;
        (yyval.node)->token="ConstructorName";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->name=(yyvsp[0].node)->value;
        // $$->value=$1->type;
        // cout<<"in"<<$$->token;
        if(cname!=(yyvsp[0].node)->tac_val) cout<<"Invalid cunstructor name";
        string tac;
        tac="define "+cname+"."+"ctor"+":";
         prog.push_back(tac);
         tac="begin_func";
        prog.push_back(tac);
        tac="obj_ref = popparam";
        prog.push_back(tac);
    }
#line 5348 "lalr1.tab.c"
    break;

  case 155: /* ConstructorBody: OPEN_CR SYMTABS ExplicitConstructorInvocation BlockStatements CLOSE_CR SYMTABE  */
#line 2038 "lalr1.y"
                                                                                      {
        (yyval.node)=new astnode;
        (yyval.node)->token="ConstructorBody";
        vector<astnode*>v;
        v.push_back((yyvsp[-5].node));
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        (yyval.node)->children=v;
        string tac;
        tac="push obj_ref";
        prog.push_back(tac);
        tac="endfunc";
        prog.push_back(tac);
        // cout<<"in"<<$$->token;
    }
#line 5369 "lalr1.tab.c"
    break;

  case 156: /* ConstructorBody: OPEN_CR SYMTABS ExplicitConstructorInvocation CLOSE_CR SYMTABE  */
#line 2054 "lalr1.y"
                                                                       {
        (yyval.node)=new astnode;
        (yyval.node)->token="ConstructorBody";
        vector<astnode*>v;
        v.push_back((yyvsp[-4].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        (yyval.node)->children=v;
        string tac;
        tac="push obj_ref";
        prog.push_back(tac);
        tac="endfunc";
        prog.push_back(tac);
        // cout<<"in"<<$$->token;
    }
#line 5389 "lalr1.tab.c"
    break;

  case 157: /* ConstructorBody: OPEN_CR SYMTABS BlockStatements CLOSE_CR SYMTABE  */
#line 2069 "lalr1.y"
                                                         {
        (yyval.node)=new astnode;
        (yyval.node)->token="ConstructorBody";
        vector<astnode*>v;
        v.push_back((yyvsp[-4].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        (yyval.node)->children=v;
        string tac;
        tac="push obj_ref";
        prog.push_back(tac);
        tac="endfunc";
        prog.push_back(tac);
        // cout<<"in"<<$$->token;
    }
#line 5409 "lalr1.tab.c"
    break;

  case 158: /* ConstructorBody: OPEN_CR CLOSE_CR  */
#line 2084 "lalr1.y"
                          {
        (yyval.node)=new astnode;
        (yyval.node)->token="ConstructorBody";
        vector<astnode*>v;
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        string tac;
        tac="push obj_ref";
        prog.push_back(tac);
        tac="endfunc";
        prog.push_back(tac);
        // cout<<"in"<<$$->token;
    }
#line 5428 "lalr1.tab.c"
    break;

  case 159: /* ExplicitConstructorInvocation: THIS OPEN_BR ArgumentList CLOSE_BR SEMICOLON  */
#line 2100 "lalr1.y"
                                                    {
        (yyval.node)=new astnode;
        (yyval.node)->token="ExplicitConstructorInvocation";
        vector<astnode*>v;
        v.push_back((yyvsp[-4].node));
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 5445 "lalr1.tab.c"
    break;

  case 160: /* ExplicitConstructorInvocation: THIS OPEN_BR CLOSE_BR SEMICOLON  */
#line 2112 "lalr1.y"
                                        {
        (yyval.node)=new astnode;
        (yyval.node)->token="ExplicitConstructorInvocation";
        vector<astnode*>v;
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 5461 "lalr1.tab.c"
    break;

  case 161: /* ExplicitConstructorInvocation: SUPER OPEN_BR ArgumentList CLOSE_BR SEMICOLON  */
#line 2123 "lalr1.y"
                                                      {
        (yyval.node)=new astnode;
        (yyval.node)->token="ExplicitConstructorInvocation";
        vector<astnode*>v;
        v.push_back((yyvsp[-4].node));
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 5478 "lalr1.tab.c"
    break;

  case 162: /* ExplicitConstructorInvocation: SUPER OPEN_BR CLOSE_BR SEMICOLON  */
#line 2135 "lalr1.y"
                                         {
        (yyval.node)=new astnode;
        (yyval.node)->token="ExplicitConstructorInvocation";
        vector<astnode*>v;
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 5494 "lalr1.tab.c"
    break;

  case 163: /* InterfaceDeclaration: Modifiers INTERFACE IDENTIFIER ExtendsInterfaces InterfaceBody  */
#line 2149 "lalr1.y"
                                                                      {
        (yyval.node)=new astnode;
        (yyval.node)->token="InterfaceDeclaration";
        vector<astnode*>v;
        v.push_back((yyvsp[-4].node));
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 5511 "lalr1.tab.c"
    break;

  case 164: /* InterfaceDeclaration: Modifiers INTERFACE IDENTIFIER InterfaceBody  */
#line 2161 "lalr1.y"
                                                     {
        (yyval.node)=new astnode;
        (yyval.node)->token="InterfaceDeclaration";
        vector<astnode*>v;
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 5527 "lalr1.tab.c"
    break;

  case 165: /* InterfaceDeclaration: INTERFACE IDENTIFIER ExtendsInterfaces InterfaceBody  */
#line 2172 "lalr1.y"
                                                             {
        (yyval.node)=new astnode;
        (yyval.node)->token="InterfaceDeclaration";
        vector<astnode*>v;
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 5543 "lalr1.tab.c"
    break;

  case 166: /* InterfaceDeclaration: INTERFACE IDENTIFIER InterfaceBody  */
#line 2183 "lalr1.y"
                                           {
        (yyval.node)=new astnode;
        (yyval.node)->token="InterfaceDeclaration";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 5558 "lalr1.tab.c"
    break;

  case 167: /* ExtendsInterfaces: EXTENDS InterfaceType  */
#line 2195 "lalr1.y"
                             {
        (yyval.node)=new astnode;
        (yyval.node)->token="ExtendsInterfaces";
        vector<astnode*>v;
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 5572 "lalr1.tab.c"
    break;

  case 168: /* ExtendsInterfaces: ExtendsInterfaces COMMA InterfaceType  */
#line 2204 "lalr1.y"
                                              {
        (yyval.node)=new astnode;
        (yyval.node)->token="ExtendsInterfaces";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 5587 "lalr1.tab.c"
    break;

  case 169: /* InterfaceBody: OPEN_CR SYMTABS InterfaceMemberDeclarations CLOSE_CR SYMTABE  */
#line 2216 "lalr1.y"
                                                                    {
        (yyval.node)=new astnode;
        (yyval.node)->token="InterfaceBody";
        vector<astnode*>v;
        v.push_back((yyvsp[-4].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 5602 "lalr1.tab.c"
    break;

  case 170: /* InterfaceBody: OPEN_CR CLOSE_CR  */
#line 2226 "lalr1.y"
                          {
        (yyval.node)=new astnode;
        (yyval.node)->token="InterfaceBody";
        vector<astnode*>v;
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 5616 "lalr1.tab.c"
    break;

  case 171: /* InterfaceMemberDeclarations: InterfaceMemberDeclaration  */
#line 2237 "lalr1.y"
                                  {
        (yyval.node)=new astnode;
        (yyval.node)->token="InterfaceMemberDeclarations";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 5629 "lalr1.tab.c"
    break;

  case 172: /* InterfaceMemberDeclarations: InterfaceMemberDeclarations InterfaceMemberDeclaration  */
#line 2245 "lalr1.y"
                                                               {
        (yyval.node)=new astnode;
        (yyval.node)->token="InterfaceMemberDeclarations";
        vector<astnode*>v;
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 5643 "lalr1.tab.c"
    break;

  case 173: /* InterfaceMemberDeclaration: ConstantDeclaration  */
#line 2256 "lalr1.y"
                           {
        (yyval.node)=new astnode;
        (yyval.node)->token="InterfaceMemberDeclaration";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 5656 "lalr1.tab.c"
    break;

  case 174: /* InterfaceMemberDeclaration: AbstractMethodDeclaration  */
#line 2264 "lalr1.y"
                                  {
        (yyval.node)=new astnode;
        (yyval.node)->token="InterfaceMemberDeclaration";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 5669 "lalr1.tab.c"
    break;

  case 175: /* ConstantDeclaration: FieldDeclaration  */
#line 2274 "lalr1.y"
                        {
        (yyval.node)=new astnode;
        (yyval.node)->token="ConstantDeclaration";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 5682 "lalr1.tab.c"
    break;

  case 176: /* AbstractMethodDeclaration: MethodHeader SEMICOLON  */
#line 2284 "lalr1.y"
                              {
        (yyval.node)=new astnode;
        (yyval.node)->token="AbstractMethodDeclaration";
        vector<astnode*>v;
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 5696 "lalr1.tab.c"
    break;

  case 177: /* ArrayInitializer: OPEN_CR SYMTABS VariableInitializers COMMA CLOSE_CR SYMTABE  */
#line 2296 "lalr1.y"
                                                                   {
        (yyval.node)=new astnode;
        (yyval.node)->token="ArrayInitializer";
        vector<astnode*>v;
        v.push_back((yyvsp[-5].node));
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        string s=(yyvsp[-3].node)->tac_val;
        if(temp_type=="ud") temp_type=(yyvsp[-3].node)->type;
        vector<string>token=split(s,',');
        string tac,temp1=get_tempvar();
        tac="Lcall_Alloc\n"; 
        tac=tac+temp1+" = "+temp_type+"["+to_string(token.size())+"]";
        (yyval.node)->tac_val=tac;
        (yyval.node)->flag=4;
        (yyval.node)->length=token.size();
        (yyval.node)->value=(yyvsp[-3].node)->value;
        // $$->tuples=token;
        (yyval.node)->type=(yyvsp[-3].node)->type;
        (yyval.node)->dims=(yyvsp[-3].node)->dims+1;
        (yyval.node)->space=(yyvsp[-3].node)->space;
        // cout<<"Dims: "<<$$->dims;
// Type check kardo idhar
    }
#line 5728 "lalr1.tab.c"
    break;

  case 178: /* ArrayInitializer: OPEN_CR SYMTABS VariableInitializers CLOSE_CR SYMTABE  */
#line 2323 "lalr1.y"
                                                              {
        (yyval.node)=new astnode;
        (yyval.node)->token="ArrayInitializer";
        vector<astnode*>v;
        v.push_back((yyvsp[-4].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        string s=(yyvsp[-2].node)->tac_val;
        vector<string>token=split(s,',');
        if(temp_type=="ud") temp_type=(yyvsp[-2].node)->type;
        string tac,temp=get_tempvar();
        tac="Lcall_Alloc\n"; 
        tac=tac+temp+" = "+temp_type+"["+to_string(token.size())+"]";
        (yyval.node)->tac_val=tac;
        (yyval.node)->flag=4;
        (yyval.node)->length=token.size();
        (yyval.node)->value=(yyvsp[-2].node)->value;
        // $$->tuples=token;
        (yyval.node)->type=(yyvsp[-2].node)->type;
        (yyval.node)->dims=(yyvsp[-2].node)->dims+1;
        (yyval.node)->space=(yyvsp[-2].node)->space;
        // cout<<"Dims: "<<$$->dims;
    }
#line 5758 "lalr1.tab.c"
    break;

  case 179: /* ArrayInitializer: OPEN_CR COMMA CLOSE_CR  */
#line 2348 "lalr1.y"
                               {
        (yyval.node)=new astnode;
        (yyval.node)->token="ArrayInitializer";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        string tac,temp=get_tempvar();
        tac="Lcall_Alloc\n"; 
        tac=tac+temp+" = "+temp_type+"[1]";
        (yyval.node)->tac_val=tac;
        (yyval.node)->flag=4;
        (yyval.node)->length=0;
        (yyval.node)->type="nd";
        (yyval.node)->dims=1;
        (yyval.node)->value=",";
        // $$->tuples=NULL;
    }
#line 5783 "lalr1.tab.c"
    break;

  case 180: /* ArrayInitializer: OPEN_CR CLOSE_CR  */
#line 2368 "lalr1.y"
                         {
        (yyval.node)=new astnode;
        (yyval.node)->token="ArrayInitializer";
        vector<astnode*>v;
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        string tac,temp=get_tempvar();
        tac="Lcall_Alloc\n"; 
        tac=tac+temp+" = "+temp_type+"[0]";
        (yyval.node)->tac_val=tac;
        (yyval.node)->flag=4;
        (yyval.node)->length=0;
        (yyval.node)->type="nd";
        (yyval.node)->dims=1;
        (yyval.node)->value="";
        // $$->tuples=NULL;
    }
#line 5807 "lalr1.tab.c"
    break;

  case 181: /* VariableInitializers: VariableInitializer  */
#line 2389 "lalr1.y"
                           {
        (yyval.node)=new astnode;
        (yyval.node)->token="VariableInitializers";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        (yyval.node)->type=(yyvsp[0].node)->type;
        // $$->length=$1->length;
        (yyval.node)->dims=(yyvsp[0].node)->dims;
        (yyval.node)->space=(yyvsp[0].node)->space;
        (yyval.node)->length=(yyvsp[0].node)->length;
        (yyval.node)->value=(yyvsp[0].node)->tac_val;
        // $$->tuples=$1->tuples;
        // cout<<"in VariableInitializer Length: "<<$$->length<<" Space:"<<$$->space;
    }
#line 5829 "lalr1.tab.c"
    break;

  case 182: /* VariableInitializers: VariableInitializers COMMA VariableInitializer  */
#line 2406 "lalr1.y"
                                                       {
        (yyval.node)=new astnode;
        (yyval.node)->token="VariableInitializers";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        (yyval.node)->tac_val=(yyvsp[-2].node)->tac_val+","+(yyvsp[0].node)->tac_val;
        temp=symtypeEvaluate((yyvsp[-2].node)->type,(yyvsp[0].node)->type);
        // cout<<"\n"<<$1->type<<" "<<$3->type;
        if(temp=="0")
        {
            //uncomment
            cout<<"Error, type mismatch in array initializer";
        }
        (yyval.node)->type=temp;
        (yyval.node)->dims=(yyvsp[-2].node)->dims;
        if(((yyvsp[-2].node)->length!=(yyvsp[0].node)->length)||((yyvsp[-2].node)->dims!=(yyvsp[0].node)->dims)){
            cout<<"Unequal length elements appended";
        }
        (yyval.node)->length=(yyvsp[-2].node)->length;
        (yyval.node)->space=(yyvsp[-2].node)->space+(yyvsp[0].node)->space;
        (yyval.node)->value=(yyval.node)->tac_val;
        // cout<<"in VariableInitializers Length: "<<$$->length<<" Space:"<<$$->space;
    }
#line 5861 "lalr1.tab.c"
    break;

  case 183: /* Block: OPEN_CR CLOSE_CR  */
#line 2438 "lalr1.y"
                     {
        (yyval.node)=new astnode;
        (yyval.node)->token="Block";
        vector<astnode*>v;
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 5875 "lalr1.tab.c"
    break;

  case 184: /* Block: OPEN_CR SYMTABS BlockStatements CLOSE_CR SYMTABE  */
#line 2447 "lalr1.y"
                                                      {
        (yyval.node)=new astnode;
        (yyval.node)->token="Block";
        vector<astnode*>v;
        v.push_back((yyvsp[-4].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 5890 "lalr1.tab.c"
    break;

  case 185: /* BlockStatements: BlockStatement  */
#line 2459 "lalr1.y"
                  {
        (yyval.node)=new astnode;
        (yyval.node)->token="BlockStatements";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 5903 "lalr1.tab.c"
    break;

  case 186: /* BlockStatements: BlockStatements BlockStatement  */
#line 2467 "lalr1.y"
                                    {
        (yyval.node)=new astnode;
        (yyval.node)->token="BlockStatements";
        vector<astnode*>v;
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 5917 "lalr1.tab.c"
    break;

  case 187: /* BlockStatement: LocalVariableDeclarationStatement  */
#line 2478 "lalr1.y"
                                     {
        (yyval.node)=new astnode;
        (yyval.node)->token="BlockStatement";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        if((yyvsp[0].node)->type!="ud"){
        string s=(yyvsp[0].node)->value;
        vector<string>tokens=split(s,',');
        symadd_list(tokens,(yyvsp[0].node)->type);
        if((yyvsp[0].node)->flag==4) {
            symadd(s,(yyvsp[0].node)->type,(yyvsp[0].node)->dims);
        }
        }
    }
#line 5938 "lalr1.tab.c"
    break;

  case 188: /* BlockStatement: Statement  */
#line 2494 "lalr1.y"
               {
        (yyval.node)=new astnode;
        (yyval.node)->token="BlockStatement";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        // cout<<"in"<<$$->token;
    }
#line 5952 "lalr1.tab.c"
    break;

  case 189: /* LocalVariableDeclarationStatement: LocalVariableDeclaration SEMICOLON  */
#line 2505 "lalr1.y"
                                      {
        (yyval.node)=new astnode;
        (yyval.node)->token="LocalVariableDeclarationStatement";
        vector<astnode*>v;
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        (yyval.node)->value=(yyvsp[-1].node)->value;
        (yyval.node)->type=(yyvsp[-1].node)->type;
        (yyval.node)->flag=(yyvsp[-1].node)->flag;
        (yyval.node)->dims=(yyvsp[-1].node)->dims;
    }
#line 5970 "lalr1.tab.c"
    break;

  case 190: /* LocalVariableDeclaration: Type VariableDeclarators  */
#line 2520 "lalr1.y"
                            {
        (yyval.node)=new astnode;
        (yyval.node)->token="LocalVariableDeclaration";
        vector<astnode*>v;
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        (yyval.node)->value=(yyvsp[0].node)->value;
        (yyval.node)->type=(yyvsp[-1].node)->type;
        (yyval.node)->flag=(yyvsp[0].node)->flag;
        (yyval.node)->dims=(yyvsp[0].node)->dims;
        // string s=$2->value;
        // vector<string>tokens=split(s,',');
        // symadd_list(tokens,$1->type);
    }
#line 5991 "lalr1.tab.c"
    break;

  case 191: /* Statement: StatementWithoutTrailingSubstatement  */
#line 2538 "lalr1.y"
                                        {
        (yyval.node)=new astnode;
        (yyval.node)->token="Statement";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        // cout<<"in"<<$$->token;
    }
#line 6005 "lalr1.tab.c"
    break;

  case 192: /* Statement: LabeledStatement  */
#line 2547 "lalr1.y"
                      {
        (yyval.node)=new astnode;
        (yyval.node)->token="Statement";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 6018 "lalr1.tab.c"
    break;

  case 193: /* Statement: IfThenStatement  */
#line 2555 "lalr1.y"
                     {
        (yyval.node)=new astnode;
        (yyval.node)->token="Statement";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 6031 "lalr1.tab.c"
    break;

  case 194: /* Statement: IfThenElseStatement  */
#line 2563 "lalr1.y"
                         {
        (yyval.node)=new astnode;
        (yyval.node)->token="Statement";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 6044 "lalr1.tab.c"
    break;

  case 195: /* Statement: WhileStatement  */
#line 2571 "lalr1.y"
                    {
        (yyval.node)=new astnode;
        (yyval.node)->token="Statement";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 6057 "lalr1.tab.c"
    break;

  case 196: /* Statement: ForStatement  */
#line 2579 "lalr1.y"
                  {
        (yyval.node)=new astnode;
        (yyval.node)->token="Statement";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 6070 "lalr1.tab.c"
    break;

  case 197: /* StatementNoShortIf: StatementWithoutTrailingSubstatement  */
#line 2589 "lalr1.y"
                                        {
        (yyval.node)=new astnode;
        (yyval.node)->token="StatementNoShortIf";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 6083 "lalr1.tab.c"
    break;

  case 198: /* StatementNoShortIf: LabeledStatementNoShortIf  */
#line 2597 "lalr1.y"
                               {
        (yyval.node)=new astnode;
        (yyval.node)->token="StatementNoShortIf";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 6096 "lalr1.tab.c"
    break;

  case 199: /* StatementNoShortIf: IfThenElseStatementNoShortIf  */
#line 2605 "lalr1.y"
                                  {
        (yyval.node)=new astnode;
        (yyval.node)->token="StatementNoShortIf";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 6109 "lalr1.tab.c"
    break;

  case 200: /* StatementNoShortIf: WhileStatementNoShortIf  */
#line 2613 "lalr1.y"
                             {
        (yyval.node)=new astnode;
        (yyval.node)->token="StatementNoShortIf";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 6122 "lalr1.tab.c"
    break;

  case 201: /* StatementNoShortIf: ForStatementNoShortIf  */
#line 2621 "lalr1.y"
                           {
        (yyval.node)=new astnode;
        (yyval.node)->token="StatementNoShortIf";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 6135 "lalr1.tab.c"
    break;

  case 202: /* StatementWithoutTrailingSubstatement: Block  */
#line 2631 "lalr1.y"
         {
        (yyval.node)=new astnode;
        (yyval.node)->token="StatementWithoutTrailingSubstatement";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 6148 "lalr1.tab.c"
    break;

  case 203: /* StatementWithoutTrailingSubstatement: EmptyStatement  */
#line 2639 "lalr1.y"
                    {
        (yyval.node)=new astnode;
        (yyval.node)->token="StatementWithoutTrailingSubstatement";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 6161 "lalr1.tab.c"
    break;

  case 204: /* StatementWithoutTrailingSubstatement: ExpressionStatement  */
#line 2647 "lalr1.y"
                         {
        (yyval.node)=new astnode;
        (yyval.node)->token="StatementWithoutTrailingSubstatement";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        // cout<<"in"<<$$->token;
    }
#line 6175 "lalr1.tab.c"
    break;

  case 205: /* StatementWithoutTrailingSubstatement: SwitchStatement  */
#line 2656 "lalr1.y"
                     {
        (yyval.node)=new astnode;
        (yyval.node)->token="StatementWithoutTrailingSubstatement";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 6188 "lalr1.tab.c"
    break;

  case 206: /* StatementWithoutTrailingSubstatement: DoStatement  */
#line 2664 "lalr1.y"
                 {
        (yyval.node)=new astnode;
        (yyval.node)->token="StatementWithoutTrailingSubstatement";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 6201 "lalr1.tab.c"
    break;

  case 207: /* StatementWithoutTrailingSubstatement: BreakStatement  */
#line 2672 "lalr1.y"
                    {
        (yyval.node)=new astnode;
        (yyval.node)->token="StatementWithoutTrailingSubstatement";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 6214 "lalr1.tab.c"
    break;

  case 208: /* StatementWithoutTrailingSubstatement: ContinueStatement  */
#line 2680 "lalr1.y"
                       {
        (yyval.node)=new astnode;
        (yyval.node)->token="StatementWithoutTrailingSubstatement";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 6227 "lalr1.tab.c"
    break;

  case 209: /* StatementWithoutTrailingSubstatement: ReturnStatement  */
#line 2688 "lalr1.y"
                     {
        (yyval.node)=new astnode;
        (yyval.node)->token="StatementWithoutTrailingSubstatement";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 6240 "lalr1.tab.c"
    break;

  case 210: /* StatementWithoutTrailingSubstatement: SynchronizedStatement  */
#line 2696 "lalr1.y"
                           {
        (yyval.node)=new astnode;
        (yyval.node)->token="StatementWithoutTrailingSubstatement";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 6253 "lalr1.tab.c"
    break;

  case 211: /* StatementWithoutTrailingSubstatement: ThrowStatement  */
#line 2704 "lalr1.y"
                    {
        (yyval.node)=new astnode;
        (yyval.node)->token="StatementWithoutTrailingSubstatement";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 6266 "lalr1.tab.c"
    break;

  case 212: /* StatementWithoutTrailingSubstatement: TryStatement  */
#line 2712 "lalr1.y"
                  {
        (yyval.node)=new astnode;
        (yyval.node)->token="StatementWithoutTrailingSubstatement";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 6279 "lalr1.tab.c"
    break;

  case 213: /* EmptyStatement: SEMICOLON  */
#line 2722 "lalr1.y"
             {
        (yyval.node)=new astnode;
        (yyval.node)->token="EmptyStatement";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 6292 "lalr1.tab.c"
    break;

  case 214: /* LabeledStatement: IDENTIFIER COLON Statement  */
#line 2732 "lalr1.y"
                              {
        (yyval.node)=new astnode;
        (yyval.node)->token="LabeledStatement";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        string tac,topush_label=get_label();
        tac=topush_label+":";
         prog.push_back(tac);
        m[(yyvsp[-2].node)->lexeme]=topush_label;
    }
#line 6311 "lalr1.tab.c"
    break;

  case 215: /* LabeledStatementNoShortIf: IDENTIFIER COLON StatementNoShortIf  */
#line 2748 "lalr1.y"
                                       {
        (yyval.node)=new astnode;
        (yyval.node)->token="LabeledStatementNoShortIf";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        string tac,topush_label=get_label();
        tac=topush_label+":";
         prog.push_back(tac);
        m[(yyvsp[-2].node)->lexeme]=topush_label;
    }
#line 6330 "lalr1.tab.c"
    break;

  case 216: /* ExpressionStatement: StatementExpression SEMICOLON  */
#line 2764 "lalr1.y"
                                 {
        (yyval.node)=new astnode;
        (yyval.node)->token="ExpressionStatement";
        vector<astnode*>v;
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        (yyval.node)->tac_val=(yyvsp[-1].node)->tac_val;
        (yyval.node)->type=(yyvsp[-1].node)->type;
    }
#line 6346 "lalr1.tab.c"
    break;

  case 217: /* StatementExpression: Assignment  */
#line 2777 "lalr1.y"
              {
        (yyval.node)=new astnode;
        (yyval.node)->token="StatementExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        (yyval.node)->type=(yyvsp[0].node)->type;
    }
#line 6361 "lalr1.tab.c"
    break;

  case 218: /* StatementExpression: PreIncrementExpression  */
#line 2787 "lalr1.y"
                            {
        (yyval.node)=new astnode;
        (yyval.node)->token="StatementExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        (yyval.node)->type=(yyvsp[0].node)->type;
    }
#line 6376 "lalr1.tab.c"
    break;

  case 219: /* StatementExpression: PreDecrementExpression  */
#line 2797 "lalr1.y"
                            {
        (yyval.node)=new astnode;
        (yyval.node)->token="StatementExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        (yyval.node)->type=(yyvsp[0].node)->type;
    }
#line 6391 "lalr1.tab.c"
    break;

  case 220: /* StatementExpression: PostIncrementExpression  */
#line 2807 "lalr1.y"
                             {
        (yyval.node)=new astnode;
        (yyval.node)->token="StatementExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        (yyval.node)->type=(yyvsp[0].node)->type;
    }
#line 6406 "lalr1.tab.c"
    break;

  case 221: /* StatementExpression: PostDecrementExpression  */
#line 2817 "lalr1.y"
                             {
        (yyval.node)=new astnode;
        (yyval.node)->token="StatementExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        (yyval.node)->type=(yyvsp[0].node)->type;
    }
#line 6421 "lalr1.tab.c"
    break;

  case 222: /* StatementExpression: MethodInvocation  */
#line 2827 "lalr1.y"
                      {
        (yyval.node)=new astnode;
        (yyval.node)->token="StatementExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        // string tac="push pc+1";
        // prog.push_back(tac);
        // tac="push obj_ref";
        // prog.push_back(tac);
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        (yyval.node)->type=(yyvsp[0].node)->type;
        prog.push_back((yyvsp[0].node)->tac_val);
    }
#line 6441 "lalr1.tab.c"
    break;

  case 223: /* StatementExpression: ClassInstanceCreationExpression  */
#line 2842 "lalr1.y"
                                     {
        (yyval.node)=new astnode;
        (yyval.node)->token="StatementExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        (yyval.node)->type=(yyvsp[0].node)->type;
    }
#line 6456 "lalr1.tab.c"
    break;

  case 224: /* StatementExpression: PrintStatement  */
#line 2852 "lalr1.y"
                    {
        (yyval.node)=new astnode;
        (yyval.node)->token="StatementExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        (yyval.node)->type=(yyvsp[0].node)->type;
        // cout<<"in StatementExpression";
    }
#line 6472 "lalr1.tab.c"
    break;

  case 225: /* IfThenStatement: IF OPEN_BR Expression CLOSE_BR IFMARK1 Statement IFEND1  */
#line 2865 "lalr1.y"
                                                            { 
        (yyval.node)=new astnode;
        (yyval.node)->token="IfThenStatement";
        vector<astnode*>v;
        v.push_back((yyvsp[-6].node));
        v.push_back((yyvsp[-5].node));
        v.push_back((yyvsp[-4].node));
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-1].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 6489 "lalr1.tab.c"
    break;

  case 226: /* IfThenElseStatement: IF OPEN_BR Expression CLOSE_BR IFMARK1 StatementNoShortIf IFEND2 ELSE ELSEMARK1 Statement ELSEEND1  */
#line 2879 "lalr1.y"
                                                                                                      {
        (yyval.node)=new astnode;
        (yyval.node)->token="IfThenElseStatement";
        vector<astnode*>v;
        v.push_back((yyvsp[-10].node));
        v.push_back((yyvsp[-9].node));
        v.push_back((yyvsp[-8].node));
        v.push_back((yyvsp[-7].node));
        v.push_back((yyvsp[-5].node));
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-1].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 6508 "lalr1.tab.c"
    break;

  case 227: /* IfThenElseStatementNoShortIf: IF OPEN_BR Expression CLOSE_BR IFMARK1 StatementNoShortIf IFEND2 ELSE ELSEMARK1 StatementNoShortIf ELSEEND1  */
#line 2895 "lalr1.y"
                                                                                                               {
        (yyval.node)=new astnode;
        (yyval.node)->token="IfThenElseStatementNoShortIf";
        vector<astnode*>v;
        v.push_back((yyvsp[-10].node));
        v.push_back((yyvsp[-9].node));
        v.push_back((yyvsp[-8].node));
        v.push_back((yyvsp[-7].node));
        v.push_back((yyvsp[-5].node));
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-1].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 6527 "lalr1.tab.c"
    break;

  case 228: /* SwitchStatement: SWITCH OPEN_BR Expression CLOSE_BR SwitchBlock  */
#line 2911 "lalr1.y"
                                                  {
        (yyval.node)=new astnode;
        (yyval.node)->token="SwitchStatement";
        vector<astnode*>v;
        v.push_back((yyvsp[-4].node));
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 6544 "lalr1.tab.c"
    break;

  case 229: /* SwitchBlock: OPEN_CR CLOSE_CR  */
#line 2925 "lalr1.y"
                     {
        (yyval.node)=new astnode;
        (yyval.node)->token="SwitchBlock";
        vector<astnode*>v;
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 6558 "lalr1.tab.c"
    break;

  case 230: /* SwitchBlock: OPEN_CR SYMTABS SwitchBlockStatementGroups CLOSE_CR SYMTABE  */
#line 2934 "lalr1.y"
                                                                {
        (yyval.node)=new astnode;
        (yyval.node)->token="SwitchBlock";
        vector<astnode*>v;
        v.push_back((yyvsp[-4].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 6573 "lalr1.tab.c"
    break;

  case 231: /* SwitchBlock: OPEN_CR SYMTABS SwitchLabels CLOSE_CR SYMTABE  */
#line 2944 "lalr1.y"
                                                   {
        (yyval.node)=new astnode;
        (yyval.node)->token="SwitchBlock";
        vector<astnode*>v;
        v.push_back((yyvsp[-4].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 6588 "lalr1.tab.c"
    break;

  case 232: /* SwitchBlock: OPEN_CR SYMTABS SwitchBlockStatementGroups SwitchLabels CLOSE_CR SYMTABE  */
#line 2954 "lalr1.y"
                                                                             {
        (yyval.node)=new astnode;
        (yyval.node)->token="SwitchBlock";
        vector<astnode*>v;
        v.push_back((yyvsp[-5].node));
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 6604 "lalr1.tab.c"
    break;

  case 233: /* SwitchBlockStatementGroups: SwitchBlockStatementGroup  */
#line 2967 "lalr1.y"
                             {
        (yyval.node)=new astnode;
        (yyval.node)->token="SwitchBlockStatementGroups";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 6617 "lalr1.tab.c"
    break;

  case 234: /* SwitchBlockStatementGroups: SwitchBlockStatementGroups SwitchBlockStatementGroup  */
#line 2975 "lalr1.y"
                                                          {
        (yyval.node)=new astnode;
        (yyval.node)->token="SwitchBlockStatementGroups";
        vector<astnode*>v;
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 6631 "lalr1.tab.c"
    break;

  case 235: /* SwitchBlockStatementGroup: SwitchLabels BlockStatements  */
#line 2986 "lalr1.y"
                                {
        (yyval.node)=new astnode;
        (yyval.node)->token="SwitchBlockStatementGroup";
        vector<astnode*>v;
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 6645 "lalr1.tab.c"
    break;

  case 236: /* SwitchLabels: SwitchLabel  */
#line 2997 "lalr1.y"
               {
        (yyval.node)=new astnode;
        (yyval.node)->token="SwitchLabels";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 6658 "lalr1.tab.c"
    break;

  case 237: /* SwitchLabels: SwitchLabels SwitchLabel  */
#line 3005 "lalr1.y"
                              {
        (yyval.node)=new astnode;
        (yyval.node)->token="SwitchLabels";
        vector<astnode*>v;
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 6672 "lalr1.tab.c"
    break;

  case 238: /* SwitchLabel: CASE ConstantExpression COLON  */
#line 3016 "lalr1.y"
                                 {
        (yyval.node)=new astnode;
        (yyval.node)->token="SwitchLabel";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 6687 "lalr1.tab.c"
    break;

  case 239: /* SwitchLabel: DEFAULT COLON  */
#line 3026 "lalr1.y"
                   {
        (yyval.node)=new astnode;
        (yyval.node)->token="SwitchLabel";
        vector<astnode*>v;
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 6701 "lalr1.tab.c"
    break;

  case 240: /* WhileStatement: WHILE WHILEMARK2 OPEN_BR Expression CLOSE_BR WHILEMARK1 Statement WHILEEND1  */
#line 3037 "lalr1.y"
                                                                               {
        (yyval.node)=new astnode;
        (yyval.node)->token="WhileStatement";
        vector<astnode*>v;
        v.push_back((yyvsp[-7].node));
        v.push_back((yyvsp[-5].node));
        v.push_back((yyvsp[-4].node));
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-1].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 6718 "lalr1.tab.c"
    break;

  case 241: /* WhileStatementNoShortIf: WHILE WHILEMARK2 OPEN_BR Expression CLOSE_BR WHILEMARK1 StatementNoShortIf WHILEEND1  */
#line 3051 "lalr1.y"
                                                                                        {
        (yyval.node)=new astnode;
        (yyval.node)->token="WhileStatementNoShortIf";
        vector<astnode*>v;
        v.push_back((yyvsp[-7].node));
        v.push_back((yyvsp[-5].node));
        v.push_back((yyvsp[-4].node));
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-1].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 6735 "lalr1.tab.c"
    break;

  case 242: /* DoStatement: DO DOMARK1 Statement WHILE OPEN_BR Expression CLOSE_BR SEMICOLON DOEND1  */
#line 3065 "lalr1.y"
                                                                           {
        (yyval.node)=new astnode;
        (yyval.node)->token="DoStatement";
        vector<astnode*>v;
        v.push_back((yyvsp[-8].node));
        v.push_back((yyvsp[-6].node));
        v.push_back((yyvsp[-5].node));
        v.push_back((yyvsp[-4].node));
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 6754 "lalr1.tab.c"
    break;

  case 243: /* ForStatement: FOR OPEN_BR FORMARK1 SEMICOLON FORMARK2 SEMICOLON CLOSE_BR FORMARK3 Statement FOREND1  */
#line 3081 "lalr1.y"
                                                                                         {
        (yyval.node)=new astnode;
        (yyval.node)->token="ForStatement";
        vector<astnode*>v;
        v.push_back((yyvsp[-9].node));
        v.push_back((yyvsp[-8].node));
        v.push_back((yyvsp[-6].node));
        v.push_back((yyvsp[-4].node));
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-1].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 6772 "lalr1.tab.c"
    break;

  case 244: /* ForStatement: FOR OPEN_BR FORMARK1 SEMICOLON FORMARK2 SEMICOLON ForUpdate CLOSE_BR FORMARK3 Statement FOREND1  */
#line 3094 "lalr1.y"
                                                                                                     {
        (yyval.node)=new astnode;
        (yyval.node)->token="ForStatement";
        vector<astnode*>v;
        v.push_back((yyvsp[-10].node));
        v.push_back((yyvsp[-9].node));
        v.push_back((yyvsp[-7].node));
        v.push_back((yyvsp[-5].node));
        v.push_back((yyvsp[-4].node));
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-1].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 6791 "lalr1.tab.c"
    break;

  case 245: /* ForStatement: FOR OPEN_BR FORMARK1 SEMICOLON Expression FORMARK2 SEMICOLON CLOSE_BR FORMARK3 Statement FOREND1  */
#line 3108 "lalr1.y"
                                                                                                      {
        (yyval.node)=new astnode;
        (yyval.node)->token="ForStatement";
        vector<astnode*>v;
        v.push_back((yyvsp[-10].node));
        v.push_back((yyvsp[-9].node));
        v.push_back((yyvsp[-7].node));
        v.push_back((yyvsp[-6].node));
        v.push_back((yyvsp[-4].node));
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-1].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 6810 "lalr1.tab.c"
    break;

  case 246: /* ForStatement: FOR OPEN_BR FORMARK1 SEMICOLON Expression FORMARK2 SEMICOLON ForUpdate CLOSE_BR FORMARK3 Statement FOREND1  */
#line 3122 "lalr1.y"
                                                                                                                {
        (yyval.node)=new astnode;
        (yyval.node)->token="ForStatement";
        vector<astnode*>v;
        v.push_back((yyvsp[-11].node));
        v.push_back((yyvsp[-10].node));
        v.push_back((yyvsp[-8].node));
        v.push_back((yyvsp[-7].node));
        v.push_back((yyvsp[-5].node));
        v.push_back((yyvsp[-4].node));
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-1].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 6830 "lalr1.tab.c"
    break;

  case 247: /* ForStatement: FOR OPEN_BR ForInit FORMARK1 SEMICOLON FORMARK2 SEMICOLON CLOSE_BR FORMARK3 Statement FOREND1  */
#line 3137 "lalr1.y"
                                                                                                   {
        (yyval.node)=new astnode;
        (yyval.node)->token="ForStatement";
        vector<astnode*>v;
        v.push_back((yyvsp[-10].node));
        v.push_back((yyvsp[-9].node));
        v.push_back((yyvsp[-8].node));
        v.push_back((yyvsp[-6].node));
        v.push_back((yyvsp[-4].node));
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-1].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 6849 "lalr1.tab.c"
    break;

  case 248: /* ForStatement: FOR OPEN_BR ForInit FORMARK1 SEMICOLON FORMARK2 SEMICOLON ForUpdate CLOSE_BR FORMARK3 Statement FOREND1  */
#line 3151 "lalr1.y"
                                                                                                             {
        (yyval.node)=new astnode;
        (yyval.node)->token="ForStatement";
        vector<astnode*>v;
        v.push_back((yyvsp[-11].node));
        v.push_back((yyvsp[-10].node));
        v.push_back((yyvsp[-9].node));
        v.push_back((yyvsp[-7].node));
        v.push_back((yyvsp[-5].node));
        v.push_back((yyvsp[-4].node));
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-1].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 6869 "lalr1.tab.c"
    break;

  case 249: /* ForStatement: FOR OPEN_BR ForInit FORMARK1 SEMICOLON Expression FORMARK2 SEMICOLON CLOSE_BR FORMARK3 Statement FOREND1  */
#line 3166 "lalr1.y"
                                                                                                              {
        (yyval.node)=new astnode;
        (yyval.node)->token="ForStatement";
        vector<astnode*>v;
        v.push_back((yyvsp[-11].node));
        v.push_back((yyvsp[-10].node));
        v.push_back((yyvsp[-9].node));
        v.push_back((yyvsp[-7].node));
        v.push_back((yyvsp[-6].node));
        v.push_back((yyvsp[-4].node));
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-1].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 6889 "lalr1.tab.c"
    break;

  case 250: /* ForStatement: FOR OPEN_BR ForInit FORMARK1 SEMICOLON Expression FORMARK2 SEMICOLON ForUpdate CLOSE_BR FORMARK3 Statement FOREND1  */
#line 3181 "lalr1.y"
                                                                                                                        {
        (yyval.node)=new astnode;
        (yyval.node)->token="ForStatement";
        vector<astnode*>v;
        v.push_back((yyvsp[-12].node));
        v.push_back((yyvsp[-11].node));
        v.push_back((yyvsp[-10].node));
        v.push_back((yyvsp[-8].node));
        v.push_back((yyvsp[-7].node));
        v.push_back((yyvsp[-5].node));
        v.push_back((yyvsp[-4].node));
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-1].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 6910 "lalr1.tab.c"
    break;

  case 251: /* ForStatementNoShortIf: FOR OPEN_BR FORMARK1 SEMICOLON FORMARK2 SEMICOLON CLOSE_BR FORMARK3 StatementNoShortIf FOREND1  */
#line 3199 "lalr1.y"
                                                                                                  {
        (yyval.node)=new astnode;
        (yyval.node)->token="ForStatementNoShortIf";
        vector<astnode*>v;
        v.push_back((yyvsp[-9].node));
        v.push_back((yyvsp[-8].node));
        v.push_back((yyvsp[-6].node));
        v.push_back((yyvsp[-4].node));
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-1].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 6928 "lalr1.tab.c"
    break;

  case 252: /* ForStatementNoShortIf: FOR OPEN_BR FORMARK1 SEMICOLON FORMARK2 SEMICOLON ForUpdate CLOSE_BR FORMARK3 StatementNoShortIf FOREND1  */
#line 3212 "lalr1.y"
                                                                                                              {
        (yyval.node)=new astnode;
        (yyval.node)->token="ForStatementNoShortIf";
        vector<astnode*>v;
        v.push_back((yyvsp[-10].node));
        v.push_back((yyvsp[-9].node));
        v.push_back((yyvsp[-7].node));
        v.push_back((yyvsp[-5].node));
        v.push_back((yyvsp[-4].node));
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-1].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 6947 "lalr1.tab.c"
    break;

  case 253: /* ForStatementNoShortIf: FOR OPEN_BR FORMARK1 SEMICOLON Expression FORMARK2 SEMICOLON CLOSE_BR FORMARK3 StatementNoShortIf FOREND1  */
#line 3226 "lalr1.y"
                                                                                                               {
        (yyval.node)=new astnode;
        (yyval.node)->token="ForStatementNoShortIf";
        vector<astnode*>v;
        v.push_back((yyvsp[-10].node));
        v.push_back((yyvsp[-9].node));
        v.push_back((yyvsp[-7].node));
        v.push_back((yyvsp[-6].node));
        v.push_back((yyvsp[-4].node));
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-1].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 6966 "lalr1.tab.c"
    break;

  case 254: /* ForStatementNoShortIf: FOR OPEN_BR FORMARK1 SEMICOLON Expression FORMARK2 SEMICOLON ForUpdate CLOSE_BR FORMARK3 StatementNoShortIf FOREND1  */
#line 3240 "lalr1.y"
                                                                                                                         {
        (yyval.node)=new astnode;
        (yyval.node)->token="ForStatementNoShortIf";
        vector<astnode*>v;
        v.push_back((yyvsp[-11].node));
        v.push_back((yyvsp[-10].node));
        v.push_back((yyvsp[-8].node));
        v.push_back((yyvsp[-7].node));
        v.push_back((yyvsp[-5].node));
        v.push_back((yyvsp[-4].node));
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-1].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 6986 "lalr1.tab.c"
    break;

  case 255: /* ForStatementNoShortIf: FOR OPEN_BR ForInit FORMARK1 SEMICOLON FORMARK2 SEMICOLON CLOSE_BR FORMARK3 StatementNoShortIf FOREND1  */
#line 3255 "lalr1.y"
                                                                                                            {
        (yyval.node)=new astnode;
        (yyval.node)->token="ForStatementNoShortIf";
        vector<astnode*>v;
        v.push_back((yyvsp[-10].node));
        v.push_back((yyvsp[-9].node));
        v.push_back((yyvsp[-8].node));
        v.push_back((yyvsp[-6].node));
        v.push_back((yyvsp[-4].node));
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-1].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 7005 "lalr1.tab.c"
    break;

  case 256: /* ForStatementNoShortIf: FOR OPEN_BR ForInit FORMARK1 SEMICOLON FORMARK2 SEMICOLON ForUpdate CLOSE_BR FORMARK3 StatementNoShortIf FOREND1  */
#line 3269 "lalr1.y"
                                                                                                                      {
        (yyval.node)=new astnode;
        (yyval.node)->token="ForStatementNoShortIf";
        vector<astnode*>v;
        v.push_back((yyvsp[-11].node));
        v.push_back((yyvsp[-10].node));
        v.push_back((yyvsp[-9].node));
        v.push_back((yyvsp[-7].node));
        v.push_back((yyvsp[-5].node));
        v.push_back((yyvsp[-4].node));
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-1].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 7025 "lalr1.tab.c"
    break;

  case 257: /* ForStatementNoShortIf: FOR OPEN_BR ForInit FORMARK1 SEMICOLON Expression FORMARK2 SEMICOLON CLOSE_BR FORMARK3 StatementNoShortIf FOREND1  */
#line 3284 "lalr1.y"
                                                                                                                       {
        (yyval.node)=new astnode;
        (yyval.node)->token="ForStatementNoShortIf";
        vector<astnode*>v;
        v.push_back((yyvsp[-11].node));
        v.push_back((yyvsp[-10].node));
        v.push_back((yyvsp[-9].node));
        v.push_back((yyvsp[-7].node));
        v.push_back((yyvsp[-6].node));
        v.push_back((yyvsp[-4].node));
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-1].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 7045 "lalr1.tab.c"
    break;

  case 258: /* ForStatementNoShortIf: FOR OPEN_BR ForInit FORMARK1 SEMICOLON Expression FORMARK2 SEMICOLON ForUpdate CLOSE_BR FORMARK3 StatementNoShortIf FOREND1  */
#line 3299 "lalr1.y"
                                                                                                                                 {
        (yyval.node)=new astnode;
        (yyval.node)->token="ForStatementNoShortIf";
        vector<astnode*>v;
        v.push_back((yyvsp[-12].node));
        v.push_back((yyvsp[-11].node));
        v.push_back((yyvsp[-10].node));
        v.push_back((yyvsp[-8].node));
        v.push_back((yyvsp[-7].node));
        v.push_back((yyvsp[-5].node));
        v.push_back((yyvsp[-4].node));
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-1].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 7066 "lalr1.tab.c"
    break;

  case 259: /* ForInit: StatementExpressionList  */
#line 3317 "lalr1.y"
                           {
        (yyval.node)=new astnode;
        (yyval.node)->token="ForInit";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
    }
#line 7080 "lalr1.tab.c"
    break;

  case 260: /* ForInit: LocalVariableDeclaration  */
#line 3326 "lalr1.y"
                              {
        (yyval.node)=new astnode;
        (yyval.node)->token="ForInit";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        string s=(yyvsp[0].node)->value;
        vector<string>tokens=split(s,',');
        for(int i=0;i<tokens.size();i++) {
            buffer[tokens[i]]=(yyvsp[0].node)->type;
        }
        // buffer[$1->value]=$1->type;
        // cout<<"in"<<$$->token;
    }
#line 7099 "lalr1.tab.c"
    break;

  case 261: /* ForUpdate: StatementExpressionList  */
#line 3342 "lalr1.y"
                           {
        (yyval.node)=new astnode;
        (yyval.node)->token="ForUpdate";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
    }
#line 7113 "lalr1.tab.c"
    break;

  case 262: /* StatementExpressionList: StatementExpression  */
#line 3353 "lalr1.y"
                       {
        (yyval.node)=new astnode;
        (yyval.node)->token="StatementExpressionList";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
    }
#line 7127 "lalr1.tab.c"
    break;

  case 263: /* StatementExpressionList: StatementExpressionList COMMA StatementExpression  */
#line 3362 "lalr1.y"
                                                       {
        (yyval.node)=new astnode;
        (yyval.node)->token="StatementExpressionList";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        (yyval.node)->tac_val=(yyvsp[-2].node)->tac_val=","+(yyvsp[-2].node)->tac_val;
    }
#line 7143 "lalr1.tab.c"
    break;

  case 264: /* BreakStatement: BREAK SEMICOLON  */
#line 3375 "lalr1.y"
                   {
        (yyval.node)=new astnode;
        (yyval.node)->token="BreakStatement";
        vector<astnode*>v;
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        string tac,toget_label;
        toget_label=while_endlabels.top();
        tac="goto "+toget_label;
         prog.push_back(tac);
    }
#line 7161 "lalr1.tab.c"
    break;

  case 265: /* BreakStatement: BREAK IDENTIFIER SEMICOLON  */
#line 3388 "lalr1.y"
                                {
        (yyval.node)=new astnode;
        (yyval.node)->token="BreakStatement";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 7176 "lalr1.tab.c"
    break;

  case 266: /* ContinueStatement: CONTINUE SEMICOLON  */
#line 3400 "lalr1.y"
                      {
        (yyval.node)=new astnode;
        (yyval.node)->token="ContinueStatement";
        vector<astnode*>v;
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        string tac,toget_label;
        toget_label=while_bwlabels.top();
        tac="goto "+toget_label;
         prog.push_back(tac);
    }
#line 7194 "lalr1.tab.c"
    break;

  case 267: /* ContinueStatement: CONTINUE IDENTIFIER SEMICOLON  */
#line 3413 "lalr1.y"
                                   {
        (yyval.node)=new astnode;
        (yyval.node)->token="ContinueStatement";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        string tac,toget_label;
        toget_label=m[(yyvsp[-1].node)->lexeme];
        tac="goto "+toget_label;
         prog.push_back(tac);
    }
#line 7213 "lalr1.tab.c"
    break;

  case 268: /* ReturnStatement: RETURN SEMICOLON  */
#line 3429 "lalr1.y"
                    {
        (yyval.node)=new astnode;
        (yyval.node)->token="ReturnStatement";
        vector<astnode*>v;
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        // prog.push_back("return");
        (yyval.node)->tac_val="return";
        (yyval.node)->type="void";
    }
#line 7230 "lalr1.tab.c"
    break;

  case 269: /* ReturnStatement: RETURN Expression SEMICOLON  */
#line 3441 "lalr1.y"
                                 {
        (yyval.node)=new astnode;
        (yyval.node)->token="ReturnStatement";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        string tac;
        if((yyvsp[-1].node)->flag)
        tac="rax = t"+to_string(tempno-1);
        else tac = "rax = "+(yyvsp[-1].node)->tac_val;
         prog.push_back(tac);
        (yyval.node)->tac_val=tac;
        (yyval.node)->type=(yyvsp[-1].node)->type;
    }
#line 7252 "lalr1.tab.c"
    break;

  case 270: /* ThrowStatement: THROW Expression SEMICOLON  */
#line 3460 "lalr1.y"
                              {
        (yyval.node)=new astnode;
        (yyval.node)->token="ThrowStatement";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 7267 "lalr1.tab.c"
    break;

  case 271: /* SynchronizedStatement: SYNCHRONIZED OPEN_BR Expression CLOSE_BR Block  */
#line 3472 "lalr1.y"
                                                  {
        (yyval.node)=new astnode;
        (yyval.node)->token="SynchronizedStatement";
        vector<astnode*>v;
        v.push_back((yyvsp[-4].node));
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 7284 "lalr1.tab.c"
    break;

  case 272: /* TryStatement: TRY Block Catches  */
#line 3486 "lalr1.y"
                     {
        (yyval.node)=new astnode;
        (yyval.node)->token="TryStatement";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 7299 "lalr1.tab.c"
    break;

  case 273: /* TryStatement: TRY Block Finally  */
#line 3496 "lalr1.y"
                        {
        (yyval.node)=new astnode;
        (yyval.node)->token="TryStatement";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 7314 "lalr1.tab.c"
    break;

  case 274: /* TryStatement: TRY Block Catches Finally  */
#line 3506 "lalr1.y"
                               {
        (yyval.node)=new astnode;
        (yyval.node)->token="TryStatement";
        vector<astnode*>v;
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 7330 "lalr1.tab.c"
    break;

  case 275: /* Catches: CatchClause  */
#line 3519 "lalr1.y"
               {
        (yyval.node)=new astnode;
        (yyval.node)->token="Catches";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 7343 "lalr1.tab.c"
    break;

  case 276: /* Catches: Catches CatchClause  */
#line 3527 "lalr1.y"
                         {
        (yyval.node)=new astnode;
        (yyval.node)->token="Catches";
        vector<astnode*>v;
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 7357 "lalr1.tab.c"
    break;

  case 277: /* CatchClause: CATCH OPEN_BR FormalParameter CLOSE_BR Block  */
#line 3538 "lalr1.y"
                                                {
        (yyval.node)=new astnode;
        (yyval.node)->token="CatchClause";
        vector<astnode*>v;
        v.push_back((yyvsp[-4].node));
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 7374 "lalr1.tab.c"
    break;

  case 278: /* Finally: FINALLY Block  */
#line 3552 "lalr1.y"
                 {
        (yyval.node)=new astnode;
        (yyval.node)->token="Finally";
        vector<astnode*>v;
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 7388 "lalr1.tab.c"
    break;

  case 279: /* Primary: PrimaryNoNewArray  */
#line 3566 "lalr1.y"
                      {
        (yyval.node)=new astnode;
        (yyval.node)->token="Primary";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        (yyval.node)->code=(yyvsp[0].node)->code;
        // cout<<"in"<<$$->token;
        (yyval.node)->flag=(yyvsp[0].node)->flag;
        (yyval.node)->type=(yyvsp[0].node)->type;
        (yyval.node)->dims=(yyvsp[0].node)->dims;
        if((yyval.node)->flag==4) {
            Type*t=symtabGetTypep(fullscope,(yyvsp[0].node)->value);
            cout<<t->dims<<" ";
            cout<<(yyval.node)->dims;
            if(t)
            if((yyval.node)->dims!=t->dims) cout<<"Error array of not same dimension";
        }
    }
#line 7413 "lalr1.tab.c"
    break;

  case 280: /* Primary: ArrayCreationExpression  */
#line 3586 "lalr1.y"
                            {
        (yyval.node)=new astnode;
        (yyval.node)->token="Primary";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        (yyval.node)->flag=(yyvsp[0].node)->flag;
        (yyval.node)->type=(yyvsp[0].node)->type;
        (yyval.node)->dims=(yyvsp[0].node)->dims;
    }
#line 7430 "lalr1.tab.c"
    break;

  case 281: /* PrimaryNoNewArray: Literal  */
#line 3600 "lalr1.y"
           {
        (yyval.node)=new astnode;
        (yyval.node)->token="PrimaryNoNewArray";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        (yyval.node)->code=(yyvsp[0].node)->code;
        // cout<<"in"<<$$->token;
        (yyval.node)->flag=(yyvsp[0].node)->flag;
        (yyval.node)->type=(yyvsp[0].node)->type;
    }
#line 7447 "lalr1.tab.c"
    break;

  case 282: /* PrimaryNoNewArray: THIS  */
#line 3612 "lalr1.y"
         {
        (yyval.node)=new astnode;
        (yyval.node)->token="PrimaryNoNewArray";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        (yyval.node)->tac_val=(yyvsp[0].node)->lexeme;
        (yyval.node)->type="this";
    }
#line 7462 "lalr1.tab.c"
    break;

  case 283: /* PrimaryNoNewArray: OPEN_BR Expression CLOSE_BR  */
#line 3622 "lalr1.y"
                                 {
        (yyval.node)=new astnode;
        (yyval.node)->token="PrimaryNoNewArray";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        if((yyvsp[-1].node)->flag==1) {
            (yyval.node)->tac_val="t"+to_string(tempno-1);
        }
        else {
            (yyval.node)->tac_val=(yyvsp[-1].node)->tac_val;
        }
        (yyval.node)->type=(yyvsp[-1].node)->type;
    }
#line 7484 "lalr1.tab.c"
    break;

  case 284: /* PrimaryNoNewArray: ClassInstanceCreationExpression  */
#line 3639 "lalr1.y"
                                    {
        (yyval.node)=new astnode;
        (yyval.node)->token="PrimaryNoNewArray";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        (yyval.node)->flag=(yyvsp[0].node)->flag;
         (yyval.node)->type=(yyvsp[0].node)->type; // NEED TO SEE
    }
#line 7500 "lalr1.tab.c"
    break;

  case 285: /* PrimaryNoNewArray: FieldAccess  */
#line 3650 "lalr1.y"
                {
        (yyval.node)=new astnode;
        (yyval.node)->token="PrimaryNoNewArray";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        (yyval.node)->type=(yyvsp[0].node)->type;
        (yyval.node)->flag=(yyvsp[0].node)->flag;
    }
#line 7516 "lalr1.tab.c"
    break;

  case 286: /* PrimaryNoNewArray: MethodInvocation  */
#line 3661 "lalr1.y"
                     {
        (yyval.node)=new astnode;
        (yyval.node)->token="PrimaryNoNewArray";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        // cout<<"in"<<$$->token;
        // symtab_t* t=symtab_top[fullscope];
        // $$->type=symtabGetType(t,$1->value);
        (yyval.node)->flag=(yyvsp[0].node)->flag;
        (yyval.node)->type=(yyvsp[0].node)->type;
    }
#line 7534 "lalr1.tab.c"
    break;

  case 287: /* PrimaryNoNewArray: ArrayAccess  */
#line 3674 "lalr1.y"
                {
        (yyval.node)=new astnode;
        (yyval.node)->token="PrimaryNoNewArray";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        (yyval.node)->flag=(yyvsp[0].node)->flag;
        (yyval.node)->dims=(yyvsp[0].node)->dims;
        (yyval.node)->type=(yyvsp[0].node)->type;
        (yyval.node)->value=(yyvsp[0].node)->value;
    }
#line 7552 "lalr1.tab.c"
    break;

  case 288: /* ClassInstanceCreationExpression: NEW ClassType OPEN_BR CLOSE_BR  */
#line 3690 "lalr1.y"
                                  {
        (yyval.node)=new astnode;
        (yyval.node)->token="ClassInstanceCreationExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        string tac,temp=get_tempvar();
        tac="Lcall_Alloc\n"; 
        tac=tac+temp+" = "+(yyvsp[-2].node)->tac_val;
        tac=tac+"\n"+"call "+(yyvsp[-2].node)->tac_val+".ctor 0";

        string scope=m1[(yyvsp[-2].node)->tac_val];
        // cout<<scope;
        symtab_t*t=symtab_top[scope];
        if((*t).find((yyvsp[-2].node)->tac_val)!=(*t).end()){
            Type*t1=(*t)[(yyvsp[-2].node)->tac_val];
            // cout<<endl<<t1->args;
            string s3=t1->args;
            vector<string>token1=split(s3,',');
            if(token1.size()>1) cout<<"arg length mismatch";
            else if(token1.size()==1&&token1[0]!="args") cout<<"arg mismatch";
        }
        
        (yyval.node)->tac_val=tac;
        (yyval.node)->flag=3;
        (yyval.node)->type=(yyvsp[-2].node)->type;
    }
#line 7588 "lalr1.tab.c"
    break;

  case 289: /* ClassInstanceCreationExpression: NEW ClassType OPEN_BR ArgumentList CLOSE_BR  */
#line 3721 "lalr1.y"
                                                 {
        (yyval.node)=new astnode;
        (yyval.node)->token="ClassInstanceCreationExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[-4].node));
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        string tac,temp=get_tempvar();
        tac="Lcall_Alloc\n"; 
        tac=tac+temp+" = "+(yyvsp[-3].node)->tac_val;
        string s=(yyvsp[-1].node)->tac_val;
        vector<string>token=split(s,',');
        for(int i=0;i<token.size();i++) {
            tac="push "+token[i];
             prog.push_back(tac);
        }
        string scope=m1[(yyvsp[-3].node)->tac_val];
        // cout<<scope;
        symtab_t*t=symtab_top[scope];
        if((*t).find((yyvsp[-3].node)->tac_val)!=(*t).end()) cout<<"no constructor present";
        Type*t1=(*t)[(yyvsp[-3].node)->tac_val];
        // cout<<endl<<t1->args;
        string s3=t1->args;
        vector<string>token3=split((yyvsp[-1].node)->type,',');
        vector<string>token1=split(s3,',');
        if(token1.size()!=token3.size()) cout<<"arg length mismatch";
        for(int i=0;i<token3.size();i++) if(token3[i]!=token1[i]) cout<<"arg mismatch";
        // if(t1->args!=$4->tac_val) yyerror("arg mismatch");

        tac=tac+"\n"+"call "+(yyvsp[-3].node)->tac_val+".ctor "+to_string(token.size());
        (yyval.node)->tac_val=tac;
        (yyval.node)->flag=3;
        (yyval.node)->type=(yyvsp[-3].node)->type;
    }
#line 7631 "lalr1.tab.c"
    break;

  case 290: /* ArgumentList: Expression  */
#line 3761 "lalr1.y"
              {
        (yyval.node)=new astnode;
        (yyval.node)->token="ArgumentList";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        (yyval.node)->type=(yyvsp[0].node)->type;
    }
#line 7646 "lalr1.tab.c"
    break;

  case 291: /* ArgumentList: ArgumentList COMMA Expression  */
#line 3771 "lalr1.y"
                                       {
        (yyval.node)=new astnode;
        (yyval.node)->token="ArgumentList";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        (yyval.node)->tac_val=(yyvsp[-2].node)->tac_val+","+(yyvsp[0].node)->tac_val;
        (yyval.node)->type=(yyvsp[-2].node)->type+","+(yyvsp[0].node)->type;
    }
#line 7663 "lalr1.tab.c"
    break;

  case 292: /* ArrayCreationExpression: NEW PrimitiveType DimExprs  */
#line 3785 "lalr1.y"
                                   {
        (yyval.node)=new astnode;
        (yyval.node)->token="ArrayCreationExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        string tac,temp=get_tempvar();
        tac="Lcall_Alloc\n"; 
        tac=tac+temp+" = "+(yyvsp[-1].node)->type+(yyvsp[0].node)->tac_val;
        (yyval.node)->tac_val=tac;
        (yyval.node)->flag=4;
        (yyval.node)->type=(yyvsp[-1].node)->type;
        (yyval.node)->dims=(yyvsp[0].node)->dims;
    }
#line 7685 "lalr1.tab.c"
    break;

  case 293: /* ArrayCreationExpression: NEW PrimitiveType DimExprs Dims  */
#line 3802 "lalr1.y"
                                      {
        (yyval.node)=new astnode;
        (yyval.node)->token="ArrayCreationExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        string tac,temp=get_tempvar();
        tac="Lcall_Alloc\n"; 
        tac=tac+temp+" = "+(yyvsp[-2].node)->type+(yyvsp[-1].node)->tac_val+(yyvsp[0].node)->tac_val;
        (yyval.node)->tac_val=tac;
        (yyval.node)->flag=4;
        (yyval.node)->type=(yyvsp[-2].node)->type;
        (yyval.node)->dims=(yyvsp[-1].node)->dims+(yyvsp[0].node)->dims;
    }
#line 7707 "lalr1.tab.c"
    break;

  case 294: /* ArrayCreationExpression: NEW ClassOrInterfaceType DimExprs  */
#line 3819 "lalr1.y"
                                        {
        (yyval.node)=new astnode;
        (yyval.node)->token="ArrayCreationExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        string tac,temp=get_tempvar();
        tac="Lcall_Alloc\n"; 
        tac=tac+temp+" = "+(yyvsp[-1].node)->tac_val+(yyvsp[0].node)->tac_val;
        (yyval.node)->tac_val=tac;
        (yyval.node)->flag=4;
        (yyval.node)->type=(yyvsp[-1].node)->type;
        (yyval.node)->dims=(yyvsp[0].node)->dims;
    }
#line 7729 "lalr1.tab.c"
    break;

  case 295: /* ArrayCreationExpression: NEW ClassOrInterfaceType DimExprs Dims  */
#line 3836 "lalr1.y"
                                                {
        (yyval.node)=new astnode;
        (yyval.node)->token="ArrayCreationExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        string tac,temp=get_tempvar();
        tac="Lcall_Alloc\n"; 
        tac=tac+temp+" = "+(yyvsp[-2].node)->tac_val+(yyvsp[-1].node)->tac_val+(yyvsp[0].node)->tac_val;
        (yyval.node)->tac_val=tac;
        (yyval.node)->flag=4;
        (yyval.node)->type=(yyvsp[-2].node)->type;
        (yyval.node)->dims=(yyvsp[-1].node)->dims+(yyvsp[0].node)->dims;
    }
#line 7752 "lalr1.tab.c"
    break;

  case 296: /* DimExprs: DimExpr  */
#line 3856 "lalr1.y"
                {
        (yyval.node)=new astnode;
        (yyval.node)->token="DimExprs";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        (yyval.node)->dims=(yyvsp[0].node)->dims;
        (yyval.node)->flag=(yyvsp[0].node)->flag;
    }
#line 7768 "lalr1.tab.c"
    break;

  case 297: /* DimExprs: DimExprs DimExpr  */
#line 3867 "lalr1.y"
                           {
        (yyval.node)=new astnode;
        (yyval.node)->token="DimExprs";
        vector<astnode*>v;
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        (yyval.node)->tac_val=(yyvsp[-1].node)->tac_val+(yyvsp[0].node)->tac_val;
        (yyval.node)->dims=(yyvsp[-1].node)->dims+1;
        (yyval.node)->flag=(yyvsp[-1].node)->flag;
    }
#line 7785 "lalr1.tab.c"
    break;

  case 298: /* DimExpr: OPEN_SQ Expression CLOSE_SQ  */
#line 3881 "lalr1.y"
                                    {
        (yyval.node)=new astnode;
        (yyval.node)->token="DimExpr";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        if((yyvsp[-1].node)->flag!=1&&(yyvsp[-1].node)->flag!=0) cout<<"array axis not defined";
        if((yyvsp[-1].node)->flag)
        (yyval.node)->tac_val="[t"+to_string(tempno-1)+"]";
        else (yyval.node)->tac_val="["+(yyvsp[-1].node)->tac_val+"]";
        (yyval.node)->dims=1;
        (yyval.node)->flag=4;
    }
#line 7806 "lalr1.tab.c"
    break;

  case 299: /* Dims: OPEN_SQ CLOSE_SQ  */
#line 3899 "lalr1.y"
                         {
        (yyval.node)=new astnode;
        (yyval.node)->token="Dims";
        vector<astnode*>v;
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        (yyval.node)->tac_val="[]";
    }
#line 7821 "lalr1.tab.c"
    break;

  case 300: /* Dims: Dims OPEN_SQ CLOSE_SQ  */
#line 3909 "lalr1.y"
                               {
        (yyval.node)=new astnode;
        (yyval.node)->token="Dims";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        (yyval.node)->tac_val=(yyvsp[-2].node)->tac_val+"[]";
    }
#line 7837 "lalr1.tab.c"
    break;

  case 301: /* FieldAccess: Primary PERIOD IDENTIFIER  */
#line 3922 "lalr1.y"
                                  {
        (yyval.node)=new astnode;
        (yyval.node)->token="FieldAccess";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        (yyval.node)->tac_val=(yyvsp[-2].node)->tac_val+"."+(yyvsp[0].node)->lexeme;
        (yyval.node)->type="fieldaccess";
        if((yyvsp[-2].node)->type=="this") {
            string scope=searchthis(fullscope);
            symtab_t*t=symtab_top[scope];
            if((*t).find((yyvsp[0].node)->lexeme)!=(*t).end()){
                Type*t1=(*t)[(yyvsp[0].node)->lexeme];
                (yyval.node)->type=t1->type;
            }
            (yyval.node)->flag=0;
        }
    }
#line 7863 "lalr1.tab.c"
    break;

  case 302: /* FieldAccess: SUPER PERIOD IDENTIFIER  */
#line 3943 "lalr1.y"
                                 {
        (yyval.node)=new astnode;
        (yyval.node)->token="FieldAccess";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        (yyval.node)->tac_val=(yyvsp[-2].node)->lexeme+"."+(yyvsp[0].node)->lexeme;
        (yyval.node)->type="fieldaccess";
    }
#line 7880 "lalr1.tab.c"
    break;

  case 303: /* MethodInvocation: Name OPEN_BR CLOSE_BR  */
#line 3957 "lalr1.y"
                             {
        (yyval.node)=new astnode;
        (yyval.node)->token="MethodInvocation";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // symadd($1->value,"nd","ud");
        // cout<<"in"<<$$->token;
        (yyval.node)->tac_val="call "+cname+"."+(yyvsp[-2].node)->tac_val+" 0";
        // symtab_t* t=symtab_top[fullscope];
        vector<string>tokens=split((yyvsp[-2].node)->value,'.');
        string x=m1[tokens[0]];
        if(fullscope.find(x)!=0){
            if((yyvsp[-2].node)->access_specifier==1)
            {
                cout<<"Method not accessible";
            }
        }
        // cout<<fullscope<<endl;
        string tac;
        tac="push pc + 1 ";
        prog.push_back(tac);
        tac="push obj_ref";
        prog.push_back(tac);
        (yyval.node)->type=symtabGetType(fullscope,(yyvsp[-2].node)->tac_val);
        if((yyval.node)->type!="0"){
            if(symtabGetArgs(fullscope,(yyvsp[-2].node)->value)!=""){
            cout<<"Argument list mismatch1";
        }
        }
        else{
            string s=(yyvsp[-2].node)->tac_val;
            vector<string>tokens=split(s,'.');
            s=symtabGetType(fullscope,tokens[0]);
            // cout<<"in"<<tokens[0]<<" "<<tokens[1]<<"out";
            // if(s=="0") {
            //     for(auto i: m1){
            //         cout<<"\n"<<i.second<<" "<<i.first;
            //         if(i.first==tokens[0]){
            //             string scope=i.second;
            //             cout<<scope;
            //             // symtab_t *t=symtab_top[scope];
            //             // Type*t1=(*t)[tokens[1]];
            //             // $$->type=t1->type;
            //             // cout<<$$->type<<" ";
            //             // cout<<t1->args;
            //             // if(t1->args!=""){
            //             //     yyerror("Argument list mismatch3");
            //             // }
            //         }
            //     }
            // }
            // else{
                symtab_t*t=symtab_top[m1[s]];
                Type*t1=(*t)[tokens[1]];
                (yyval.node)->type=t1->type;
                string x=m1[s];
                if(fullscope.find(x)!=0){
                    if(t1->access_specifier==0)
                    {
                        cout<<"Method not accessible";
                    }
                }
                // cout<<$$->type<<" ";
                // cout<<t1->args;
                if(t1->args!=""){
                    cout<<"Argument list mismatch3";
                }
            // }
        }
        (yyval.node)->tac_val=(yyval.node)->tac_val+"\n"+"deallocate 0";
        (yyval.node)->flag=2;                
    }
#line 7960 "lalr1.tab.c"
    break;

  case 304: /* MethodInvocation: Name OPEN_BR ArgumentList CLOSE_BR  */
#line 4032 "lalr1.y"
                                        {
        (yyval.node)=new astnode;
        (yyval.node)->token="MethodInvocation";
        vector<astnode*>v;
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        vector<string>tokens=split((yyvsp[-3].node)->value,'.');
        if(m1.find(tokens[0])!=m1.end()){
            string x=m1[tokens[0]];
            if(fullscope.find(x)!=0){
                if((yyvsp[-3].node)->access_specifier==1)
                {
                    cout<<"Method not accessible";
                }
            }
        }
        
        // symadd($1->value,"nd","ud");
        // cout<<"in"<<$$->token;
        string s=(yyvsp[-1].node)->tac_val,tac;
        vector<string>token=split(s,',');
        for(int i=0;i<token.size();i++) {
            tac="push "+token[i];
             prog.push_back(tac);
        }
        tac="push pc + 1 ";
        prog.push_back(tac);
        tac="push obj_ref";
        prog.push_back(tac);
        (yyval.node)->tac_val="call "+cname+"."+(yyvsp[-3].node)->tac_val+" "+to_string(token.size());
        // symtab_t* t=symtab_top[fullscope];
        (yyval.node)->type=symtabGetType(fullscope,(yyvsp[-3].node)->value);
        if((yyval.node)->type!="0")
        {
            vector<string>args=split((yyvsp[-1].node)->type,',');
            vector<string>args1=split(symtabGetArgs(fullscope,(yyvsp[-3].node)->value),',');
            if(args.size()!=args1.size()) cout<<"Argument mismatch2";
            for(int i=0;i<args.size();i++){
                if(args[i]!=args1[i]) cout<<"Argument mismatch2";
            }
            int si=getsize(args1);
            (yyval.node)->tac_val=(yyval.node)->tac_val+"\n"+"deallocate "+to_string(si);
        }
        else{
            string s=(yyvsp[-3].node)->tac_val;
            vector<string>tokens=split(s,'.');
            s=symtabGetType(fullscope,tokens[0]);
            // if(s=="0") {
            //     if(m1.find(tokens[0])!=m1.end()){
            //     // for(auto k : m1){
            //     //     if(k.first==tokens[0]){
            //             string scope=m1[tokens[0]];
            //             symtab_t *t=symtab_top[scope];
            //             Type*t1=(*t)[tokens[1]];
            //             $$->type=t1->type;
            //             cout<<$$->type<<" ";
            //             cout<<t1->args;
            //             vector<string>args=split($3->type,',');
            //             vector<string>args1=split(t1->args,',');
            //             if(args.size()!=args1.size()) yyerror("Argument mismatch2");
            //             for(int i=0;i<args.size();i++){
            //                 if(args[i]!=args1[i]) yyerror("Argument mismatch2");
            //             }
            //         // }
            //     }
            // }
            // else{
                symtab_t*t=symtab_top[m1[s]];
                Type*t1=(*t)[tokens[1]];
                (yyval.node)->type=t1->type;
                string x=m1[s];
                // cout<<endl<<"x: "<<x<<" fullscope: "<<fullscope<<" prefix: "<<fullscope.find(x)<<endl;
                if(fullscope.find(x)!=0){
                    // cout<<"hi2"<<endl;
                    if(t1->access_specifier==0)
                    {
                        cout<<"Method not accessible";
                    }
                    // cout<<"Token: "<<tokens[1]<<" "<<symtabGetAccess(fullscope,tokens[1]);
                }
                // cout<<$$->type<<" ";
                // cout<<t1->args;
                vector<string>args=split((yyvsp[-1].node)->type,',');
                vector<string>args1=split(t1->args,',');
                if(args.size()!=args1.size()) cout<<"Argument mismatch2";
                for(int i=0;i<args.size();i++){
                    if(args[i]!=args1[i]) cout<<"Argument mismatch2";
                }
                int si=getsize(args1);
                (yyval.node)->tac_val=(yyval.node)->tac_val+"\n"+"deallocate "+to_string(si);
            // }
            
        }
        (yyval.node)->flag=2; 
    }
#line 8063 "lalr1.tab.c"
    break;

  case 305: /* MethodInvocation: Primary PERIOD IDENTIFIER OPEN_BR CLOSE_BR  */
#line 4130 "lalr1.y"
                                                 {
        (yyval.node)=new astnode;
        (yyval.node)->token="MethodInvocation";
        vector<astnode*>v;
        v.push_back((yyvsp[-4].node));
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // symadd($1->value,"nd","ud");
        // cout<<"in"<<$$->token;
        (yyval.node)->tac_val="call "+(yyvsp[-4].node)->tac_val+(yyvsp[-3].node)->lexeme+(yyvsp[-2].node)->lexeme+" 0";
        
        // symtab_t*t=symtab_top[$1->tac_val];
        // Type*t1=(*t)[$3->lexeme];
        // $$->type=t1->type;
        // cout<<$$->type<<" ";
        // cout<<t1->args;
        // if(t1->args!=""){
        //     yyerror("Argument list mismatch3");
        // }
        (yyval.node)->type=symtabGetType(fullscope,(yyvsp[-4].node)->value);
        if(symtabGetArgs(fullscope,(yyvsp[-4].node)->value)!=""){
            cout<<"Argument list mismatch1";
        }
        (yyval.node)->flag=2;     
    }
#line 8096 "lalr1.tab.c"
    break;

  case 306: /* MethodInvocation: Primary PERIOD IDENTIFIER OPEN_BR ArgumentList CLOSE_BR  */
#line 4158 "lalr1.y"
                                                                 {
        (yyval.node)=new astnode;
        (yyval.node)->token="MethodInvocation";
        vector<astnode*>v;
        v.push_back((yyvsp[-5].node));
        v.push_back((yyvsp[-4].node));
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // symadd($1->value,"nd","ud");
        // cout<<"in"<<$$->token;
        string s=(yyvsp[-1].node)->tac_val,tac;
        vector<string>token=split(s,',');
        for(int i=0;i<token.size();i++) {
            tac="push "+token[i];
             prog.push_back(tac);
        }
        (yyval.node)->tac_val="call "+(yyvsp[-5].node)->tac_val+(yyvsp[-4].node)->lexeme+(yyvsp[-3].node)->lexeme+" "+to_string(token.size());
        (yyval.node)->type=symtabGetType(fullscope,(yyvsp[-3].node)->lexeme);
        // cout<<$$->type<<endl;
        // cout<<$3->type<<endl;
        vector<string>args=split((yyvsp[-1].node)->type,',');
        
        vector<string>args1=split(symtabGetArgs(fullscope,(yyvsp[-3].node)->lexeme),',');
        if(args.size()!=args1.size()) cout<<"Argument mismatch4";
        for(int i=0;i<args.size();i++){
            if(args[i]!=args1[i]) cout<<"Argument mismatch4";
        }
        (yyval.node)->flag=2;   
    }
#line 8133 "lalr1.tab.c"
    break;

  case 307: /* MethodInvocation: SUPER PERIOD IDENTIFIER OPEN_BR CLOSE_BR  */
#line 4190 "lalr1.y"
                                              {
        (yyval.node)=new astnode;
        (yyval.node)->token="MethodInvocation";
        vector<astnode*>v;
        v.push_back((yyvsp[-4].node));
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[-1].node));
        (yyval.node)->children=v;
        // symadd($1->value,"nd","ud");
        // cout<<"in"<<$$->token;
        (yyval.node)->tac_val="call "+(yyvsp[-4].node)->lexeme+(yyvsp[-3].node)->lexeme+(yyvsp[-2].node)->lexeme+" 0";
        (yyval.node)->tac_val="call "+(yyvsp[-4].node)->tac_val+(yyvsp[-3].node)->lexeme+(yyvsp[-2].node)->lexeme+" 0";
        (yyval.node)->type=symtabGetType(fullscope,(yyvsp[-2].node)->lexeme);
        if(symtabGetArgs(fullscope,(yyvsp[-2].node)->lexeme)!=""){
            cout<<"Argument list mismatch";
        }  
        (yyval.node)->flag=2;   
    }
#line 8158 "lalr1.tab.c"
    break;

  case 308: /* MethodInvocation: SUPER PERIOD IDENTIFIER OPEN_BR ArgumentList CLOSE_BR  */
#line 4210 "lalr1.y"
                                                               {
        (yyval.node)=new astnode;
        (yyval.node)->token="MethodInvocation";
        vector<astnode*>v;
        v.push_back((yyvsp[-5].node));
        v.push_back((yyvsp[-4].node));
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // symadd($1->value,"nd","ud");
        // cout<<"in"<<$$->token;
        string s=(yyvsp[-1].node)->tac_val,tac;
        vector<string>token=split(s,',');
        for(int i=0;i<token.size();i++) {
            tac="push "+token[i];
             prog.push_back(tac);
        }
        (yyval.node)->tac_val="call "+(yyvsp[-5].node)->lexeme+(yyvsp[-4].node)->lexeme+(yyvsp[-3].node)->lexeme+" "+to_string(token.size());
        (yyval.node)->type=symtabGetType(fullscope,(yyvsp[-3].node)->lexeme);
        // cout<<$$->type<<endl;
        // cout<<$3->type<<endl;
        vector<string>args=split((yyvsp[-1].node)->type,',');
        (yyval.node)->flag=2;   
        vector<string>args1=split(symtabGetArgs(fullscope,(yyvsp[-3].node)->lexeme),',');
        if(args.size()!=args1.size()) cout<<"Argument mismatch";
        for(int i=0;i<args.size();i++){
            if(args[i]!=args1[i]) cout<<"Argument mismatch";
        }
    }
#line 8194 "lalr1.tab.c"
    break;

  case 309: /* ArrayAccess: Name OPEN_SQ Expression CLOSE_SQ  */
#line 4243 "lalr1.y"
                                        {
        (yyval.node)=new astnode;
        (yyval.node)->token="ArrayAccess";
        vector<astnode*>v;
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        if((yyvsp[-1].node)->type!="int") {
            cout<<"array index not defined";
        }
        string tac,var;
        if((yyvsp[-1].node)->flag) {
            var=get_tempvar();
            tac=var+" = t"+to_string(tempno-2)+"*8";
        }
        else{
            var=get_tempvar();
            tac=var+" = "+(yyvsp[-1].node)->tac_val+"*8";
        }
        (yyval.node)->flag=4;
        (yyval.node)->dims=(yyval.node)->dims+1;
         prog.push_back(tac);
        var=get_tempvar();
        tac=var+" = "+(yyvsp[-3].node)->tac_val+"[t"+to_string(tempno-2)+"]";
        (yyval.node)->tac_val=var;
         prog.push_back(tac);
        (yyval.node)->type=(yyvsp[-3].node)->type;
        (yyval.node)->value=(yyvsp[-3].node)->value;
    }
#line 8231 "lalr1.tab.c"
    break;

  case 310: /* ArrayAccess: PrimaryNoNewArray OPEN_SQ Expression CLOSE_SQ  */
#line 4275 "lalr1.y"
                                                       {
        (yyval.node)=new astnode;
        (yyval.node)->token="ArrayAccess";
        vector<astnode*>v;
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        string tac,var;
        if((yyvsp[-1].node)->flag) {
            var=get_tempvar();
            tac=var+" = t"+to_string(tempno-2)+"*8";
        }
        else{
            var=get_tempvar();
            tac=var+" = "+(yyvsp[-1].node)->tac_val+"*8";
        }
        (yyval.node)->flag=4;
        (yyval.node)->dims=(yyvsp[-3].node)->dims+1;
         prog.push_back(tac);
        var=get_tempvar();
        tac=var+" = "+(yyvsp[-3].node)->tac_val+"[t"+to_string(tempno-2)+"]";
        (yyval.node)->tac_val=var;
         prog.push_back(tac);
        (yyval.node)->type=(yyvsp[-3].node)->type;
        (yyval.node)->value=(yyvsp[-3].node)->value;
    }
#line 8265 "lalr1.tab.c"
    break;

  case 311: /* PostfixExpression: Primary  */
#line 4306 "lalr1.y"
               {
        (yyval.node)=new astnode;
        (yyval.node)->token="PostfixExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        (yyval.node)->code=(yyvsp[0].node)->code;
        // cout<<"in"<<$$->token;
        (yyval.node)->flag=(yyvsp[0].node)->flag;
        (yyval.node)->dims=(yyvsp[0].node)->dims;
        (yyval.node)->type=(yyvsp[0].node)->type;
    }
#line 8283 "lalr1.tab.c"
    break;

  case 312: /* PostfixExpression: Name  */
#line 4319 "lalr1.y"
               {
        (yyval.node)=new astnode;
        (yyval.node)->token="PostfixExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        (yyval.node)->code=(yyvsp[0].node)->code;
        // cout<<"in"<<$$->token;
        (yyval.node)->flag=(yyvsp[0].node)->flag;
        (yyval.node)->type=(yyvsp[0].node)->type;
    }
#line 8300 "lalr1.tab.c"
    break;

  case 313: /* PostfixExpression: PostIncrementExpression  */
#line 4331 "lalr1.y"
                                  {
        (yyval.node)=new astnode;
        (yyval.node)->token="PostfixExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        (yyval.node)->code=(yyvsp[0].node)->code;
        // cout<<"in"<<$$->token;
        (yyval.node)->type=(yyvsp[0].node)->type;
    }
#line 8316 "lalr1.tab.c"
    break;

  case 314: /* PostfixExpression: PostDecrementExpression  */
#line 4342 "lalr1.y"
                                 {
        (yyval.node)=new astnode;
        (yyval.node)->token="PostfixExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        (yyval.node)->code=(yyvsp[0].node)->code;
        // cout<<"in"<<$$->token;
        (yyval.node)->type=(yyvsp[0].node)->type;
    }
#line 8332 "lalr1.tab.c"
    break;

  case 315: /* PostIncrementExpression: PostfixExpression INC  */
#line 4355 "lalr1.y"
                              {
        (yyval.node)=new astnode;
        (yyval.node)->token="PostfixIncrementExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        string temp=get_tempvar();
        (yyval.node)->tac_val=temp;
        string tac="";
        // tac=tac+$2->lexeme+","+$1->tac_val+","+","+temp;
        tac=temp+" = "+(yyvsp[-1].node)->tac_val;
        (yyval.node)->code=tac+"\n";
         prog.push_back(tac);
        tac=(yyvsp[-1].node)->tac_val+" = "+(yyvsp[-1].node)->tac_val+" + 1";
         prog.push_back(tac);
        // cout<<"in"<<$$->token;
        (yyval.node)->type=(yyvsp[-1].node)->type;
    }
#line 8356 "lalr1.tab.c"
    break;

  case 316: /* PostDecrementExpression: PostfixExpression DEC  */
#line 4376 "lalr1.y"
                             {
        (yyval.node)=new astnode;
        (yyval.node)->token="PostfixDecrementExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        string temp=get_tempvar();
        (yyval.node)->tac_val=temp;
        string tac="";
        // tac=tac+$2->lexeme+","+$1->tac_val+","+","+temp;
        tac=temp+" = "+(yyvsp[-1].node)->tac_val;
        (yyval.node)->code=tac+"\n";
         prog.push_back(tac);
        tac=(yyvsp[-1].node)->tac_val+" = "+(yyvsp[-1].node)->tac_val+" - 1";
         prog.push_back(tac);
        // cout<<"in"<<$$->token;
        (yyval.node)->type=(yyvsp[-1].node)->type;
    }
#line 8380 "lalr1.tab.c"
    break;

  case 317: /* UnaryExpression: PreIncrementExpression  */
#line 4397 "lalr1.y"
                              {
        (yyval.node)=new astnode;
        (yyval.node)->token="UnaryExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        (yyval.node)->code=(yyvsp[0].node)->code;
        // cout<<"in"<<$$->token;
        (yyval.node)->flag=(yyvsp[0].node)->flag;
        (yyval.node)->type=(yyvsp[0].node)->type;
    }
#line 8397 "lalr1.tab.c"
    break;

  case 318: /* UnaryExpression: PreDecrementExpression  */
#line 4409 "lalr1.y"
                                {
        (yyval.node)=new astnode;
        (yyval.node)->token="UnaryExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        (yyval.node)->code=(yyvsp[0].node)->code;
        // cout<<"in"<<$$->token;
        (yyval.node)->type=(yyvsp[0].node)->type;
    }
#line 8413 "lalr1.tab.c"
    break;

  case 319: /* UnaryExpression: ADD UnaryExpression  */
#line 4420 "lalr1.y"
                             {
        (yyval.node)=new astnode;
        (yyval.node)->token="UnaryExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        string temp=get_tempvar();
        (yyval.node)->tac_val=temp;
        string tac="";
        // tac=tac+$1->lexeme+","+$2->tac_val+","+","+temp;
        tac=temp+" = "+(yyvsp[-1].node)->lexeme+(yyvsp[0].node)->tac_val;
        (yyval.node)->code=tac+"\n";
         prog.push_back(tac);
        // cout<<"in"<<$$->token;
        (yyval.node)->type=(yyvsp[0].node)->type;
    }
#line 8435 "lalr1.tab.c"
    break;

  case 320: /* UnaryExpression: SUB UnaryExpression  */
#line 4437 "lalr1.y"
                             {
        (yyval.node)=new astnode;
        (yyval.node)->token="UnaryExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        string temp=get_tempvar();
        (yyval.node)->tac_val=temp;
        string tac="";
        // tac=tac+$1->lexeme+","+$2->tac_val+","+","+temp;
        tac=temp+" = "+(yyvsp[-1].node)->lexeme+(yyvsp[0].node)->tac_val;
        (yyval.node)->code=tac+"\n";
         prog.push_back(tac);
        // cout<<"in"<<$$->token;
        (yyval.node)->type=(yyvsp[0].node)->type;
    }
#line 8457 "lalr1.tab.c"
    break;

  case 321: /* UnaryExpression: UnaryExpressionNotPlusMinus  */
#line 4454 "lalr1.y"
                                     {
        (yyval.node)=new astnode;
        (yyval.node)->token="UnaryExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        (yyval.node)->code=(yyvsp[0].node)->code;
        // cout<<"in"<<$$->token;
        (yyval.node)->flag=(yyvsp[0].node)->flag;
        (yyval.node)->type=(yyvsp[0].node)->type;
        (yyval.node)->dims=(yyvsp[0].node)->dims;
    }
#line 8475 "lalr1.tab.c"
    break;

  case 322: /* PreIncrementExpression: INC UnaryExpression  */
#line 4469 "lalr1.y"
                           {
        (yyval.node)=new astnode;
        (yyval.node)->token="PreIncrementExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        string temp=get_tempvar();
        (yyval.node)->tac_val=temp;
        string tac="";
        // tac=tac+$1->lexeme+","+$2->tac_val+","+","+temp;
        tac=(yyvsp[0].node)->tac_val+" = "+(yyvsp[0].node)->tac_val+" + 1";
        (yyval.node)->code=tac+"\n";
         prog.push_back(tac);
        tac=temp+" = "+(yyvsp[0].node)->tac_val;
         prog.push_back(tac);
        // cout<<"in"<<$$->token;
        (yyval.node)->type=(yyvsp[-1].node)->type;
    }
#line 8499 "lalr1.tab.c"
    break;

  case 323: /* PreDecrementExpression: DEC UnaryExpression  */
#line 4490 "lalr1.y"
                           {
        (yyval.node)=new astnode;
        (yyval.node)->token="PreDecrementExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        string temp=get_tempvar();
        (yyval.node)->tac_val=temp;
        string tac="";
        // tac=tac+$1->lexeme+","+$2->tac_val+","+","+temp;
        tac=(yyvsp[0].node)->tac_val+" = "+(yyvsp[0].node)->tac_val+" - 1";
        (yyval.node)->code=tac+"\n";
         prog.push_back(tac);
        tac=temp+" = "+(yyvsp[0].node)->tac_val;
         prog.push_back(tac);
        // cout<<"in"<<$$->token;
        (yyval.node)->type=(yyvsp[-1].node)->type;
    }
#line 8523 "lalr1.tab.c"
    break;

  case 324: /* UnaryExpressionNotPlusMinus: PostfixExpression  */
#line 4511 "lalr1.y"
                         {
        (yyval.node)=new astnode;
        (yyval.node)->token="UnaryExpressionNotPlusMinus";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        (yyval.node)->code=(yyvsp[0].node)->code;
        // cout<<"in"<<$$->token;
        (yyval.node)->flag=(yyvsp[0].node)->flag;
        (yyval.node)->type=(yyvsp[0].node)->type;
        (yyval.node)->dims=(yyvsp[0].node)->dims;
    }
#line 8541 "lalr1.tab.c"
    break;

  case 325: /* UnaryExpressionNotPlusMinus: TILDE UnaryExpression  */
#line 4524 "lalr1.y"
                                {
        (yyval.node)=new astnode;
        (yyval.node)->token="UnaryExpressionNotPlusMinus";
        vector<astnode*>v;
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        string temp=get_tempvar();
        (yyval.node)->tac_val=temp;
        string tac="";
        // tac=tac+$1->lexeme+","+$2->tac_val+","+","+temp;
        tac=temp+" = "+(yyvsp[-1].node)->lexeme+" "+(yyvsp[0].node)->tac_val;
        (yyval.node)->code=tac+"\n";
         prog.push_back(tac);
        // cout<<"in"<<$$->token;
        (yyval.node)->type=(yyvsp[0].node)->type;
    }
#line 8563 "lalr1.tab.c"
    break;

  case 326: /* UnaryExpressionNotPlusMinus: NOT UnaryExpression  */
#line 4541 "lalr1.y"
                             {
        (yyval.node)=new astnode;
        (yyval.node)->token="UnaryExpressionNotPlusMinus";
        vector<astnode*>v;
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        string temp=get_tempvar();
        (yyval.node)->tac_val=temp;
        string tac="";
        // tac=tac+$1->lexeme+","+$2->tac_val+","+","+temp;
        tac=temp+" = "+(yyvsp[-1].node)->lexeme+" "+(yyvsp[0].node)->tac_val;
        (yyval.node)->code=tac+"\n";
         prog.push_back(tac);
        // cout<<"in"<<$$->token;
        (yyval.node)->type=(yyvsp[0].node)->type;
    }
#line 8585 "lalr1.tab.c"
    break;

  case 327: /* UnaryExpressionNotPlusMinus: CastExpression  */
#line 4558 "lalr1.y"
                        {
        (yyval.node)=new astnode;
        (yyval.node)->token="UnaryExpressionNotPlusMinus";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        // cout<<"in"<<$$->token;
        (yyval.node)->type=(yyvsp[0].node)->type;
    }
#line 8600 "lalr1.tab.c"
    break;

  case 328: /* CastExpression: OPEN_BR PrimitiveType CLOSE_BR UnaryExpression  */
#line 4570 "lalr1.y"
                                                      {
        (yyval.node)=new astnode;
        (yyval.node)->token="CastExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        string tac,temp=get_tempvar();
        tac=temp+" =cast_to_"+(yyvsp[-2].node)->type+" "+(yyvsp[0].node)->tac_val;
         prog.push_back(tac);
        (yyval.node)->tac_val=temp;
        (yyval.node)->type=(yyvsp[-2].node)->type;
    }
#line 8621 "lalr1.tab.c"
    break;

  case 329: /* CastExpression: OPEN_BR PrimitiveType Dims CLOSE_BR UnaryExpression  */
#line 4586 "lalr1.y"
                                                         {
        (yyval.node)=new astnode;
        (yyval.node)->token="CastExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[-4].node));
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        string tac,temp=get_tempvar();
        tac=temp+" =cast_to_"+(yyvsp[-3].node)->type+(yyvsp[-2].node)->tac_val+" "+(yyvsp[0].node)->tac_val;
         prog.push_back(tac);
        (yyval.node)->tac_val=temp;
        (yyval.node)->type=(yyvsp[-3].node)->type;
    }
#line 8643 "lalr1.tab.c"
    break;

  case 330: /* CastExpression: OPEN_BR Expression CLOSE_BR UnaryExpressionNotPlusMinus  */
#line 4603 "lalr1.y"
                                                                 {
        (yyval.node)=new astnode;
        (yyval.node)->token="CastExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        (yyval.node)->type=(yyvsp[-2].node)->type;
    }
#line 8660 "lalr1.tab.c"
    break;

  case 331: /* CastExpression: OPEN_BR Name Dims CLOSE_BR UnaryExpressionNotPlusMinus  */
#line 4615 "lalr1.y"
                                                                {
        (yyval.node)=new astnode;
        (yyval.node)->token="CastExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[-4].node));
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        (yyval.node)->type=(yyvsp[-3].node)->type;
        // string tac,var=get_tempvar();
        // tac=var+" =cast_to_"+$2->type+$3->tac_val+" "+$5->tac_val;
        //  prog.push_back(tac);
    }
#line 8681 "lalr1.tab.c"
    break;

  case 332: /* MultiplicativeExpression: UnaryExpression  */
#line 4633 "lalr1.y"
                       {
        (yyval.node)=new astnode;
        (yyval.node)->token="MultiplicativeExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        (yyval.node)->code=(yyvsp[0].node)->code;
        // cout<<"in"<<$$->token;
        (yyval.node)->flag=(yyvsp[0].node)->flag;
        (yyval.node)->type=(yyvsp[0].node)->type;
        (yyval.node)->dims=(yyvsp[0].node)->dims;
    }
#line 8699 "lalr1.tab.c"
    break;

  case 333: /* MultiplicativeExpression: MultiplicativeExpression MUL UnaryExpression  */
#line 4646 "lalr1.y"
                                                     {
        (yyval.node)=new astnode;
        (yyval.node)->token="MultiplicativeExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        temp=symtypeEvaluate((yyvsp[-2].node)->type,(yyvsp[0].node)->type,(yyvsp[-1].node)->lexeme);
        if(temp=="0")
        {
            cout<<"Error, type incompatible";
        }
        if((yyvsp[-2].node)->type != (yyvsp[0].node)->type)
        {   if((yyvsp[-2].node)->type==temp){
                string t1=get_tempvar(),t2;
                s1=t1+" =cast_to_"+temp+" "+(yyvsp[0].node)->tac_val;
                prog.push_back(s1);
                (yyvsp[0].node)->tac_val=t1;
                // t2=get_tempvar();

            }
                
            else s1="cast_to_"+temp+" "+(yyvsp[-2].node)->tac_val;
        }
        s2=temp+"*";
        (yyval.node)->type=temp;
        string temp1=get_tempvar();
        (yyval.node)->tac_val=temp1;
        string tac="";
        // tac=tac+$2->lexeme+","+$1->tac_val+","+$3->tac_val+","+temp;
        tac=temp1+" = "+(yyvsp[-2].node)->tac_val+" "+(yyvsp[-1].node)->lexeme+" "+(yyvsp[0].node)->tac_val;
        (yyval.node)->code=tac+"\n";
         prog.push_back(tac);
        // cout<<"in"<<$$->token;
    }
#line 8740 "lalr1.tab.c"
    break;

  case 334: /* MultiplicativeExpression: MultiplicativeExpression QUO UnaryExpression  */
#line 4682 "lalr1.y"
                                                     {
        (yyval.node)=new astnode;
        (yyval.node)->token="MultiplicativeExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        temp=symtypeEvaluate((yyvsp[-2].node)->type,(yyvsp[0].node)->type,(yyvsp[-1].node)->lexeme);
        if(temp=="0")
        {
            cout<<"Error, type incompatible";
        }
        if((yyvsp[-2].node)->type != (yyvsp[0].node)->type)
        {   if((yyvsp[-2].node)->type==temp){
                string t1=get_tempvar(),t2;
                s1=t1+" =cast_to_"+temp+" "+(yyvsp[0].node)->tac_val;
                prog.push_back(s1);
                (yyvsp[0].node)->tac_val=t1;
                // t2=get_tempvar();

            }
                
            else s1="cast_to_"+temp+" "+(yyvsp[-2].node)->tac_val;
        }
        s2=temp+"/";
        (yyval.node)->type=temp;
        string temp1=get_tempvar();
        (yyval.node)->tac_val=temp1;
        string tac="";
        // tac=tac+$2->lexeme+","+$1->tac_val+","+$3->tac_val+","+temp;
        tac=temp1+" = "+(yyvsp[-2].node)->tac_val+" "+(yyvsp[-1].node)->lexeme+" "+(yyvsp[0].node)->tac_val;
        (yyval.node)->code=tac+"\n";
         prog.push_back(tac);
        // cout<<"in"<<$$->token;
    }
#line 8781 "lalr1.tab.c"
    break;

  case 335: /* MultiplicativeExpression: MultiplicativeExpression REM UnaryExpression  */
#line 4718 "lalr1.y"
                                                     {
        (yyval.node)=new astnode;
        (yyval.node)->token="MultiplicativeExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        temp=symtypeEvaluate((yyvsp[-2].node)->type,(yyvsp[0].node)->type,(yyvsp[-1].node)->lexeme);
       if(temp=="0")
        {
            cout<<"Error, type incompatible";
        }
        if((yyvsp[-2].node)->type != (yyvsp[0].node)->type)
        {   if((yyvsp[-2].node)->type==temp){
                string t1=get_tempvar(),t2;
                s1=t1+" =cast_to_"+temp+" "+(yyvsp[0].node)->tac_val;
                prog.push_back(s1);
                (yyvsp[0].node)->tac_val=t1;
                // t2=get_tempvar();

            }
                
            else s1="cast_to_"+temp+" "+(yyvsp[-2].node)->tac_val;
        }
        s2=temp+"%";
        (yyval.node)->type=temp;
        string temp1=get_tempvar();
        (yyval.node)->tac_val=temp1;
        string tac="";
        // tac=tac+$2->lexeme+","+$1->tac_val+","+$3->tac_val+","+temp;
        tac=temp1+" = "+(yyvsp[-2].node)->tac_val+" "+(yyvsp[-1].node)->lexeme+" "+(yyvsp[0].node)->tac_val;
        (yyval.node)->code=tac+"\n";
         prog.push_back(tac);
        // cout<<"in"<<$$->token;
    }
#line 8822 "lalr1.tab.c"
    break;

  case 336: /* AdditiveExpression: MultiplicativeExpression  */
#line 4756 "lalr1.y"
                                {
        (yyval.node)=new astnode;
        (yyval.node)->token="AdditiveExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        (yyval.node)->code=(yyvsp[0].node)->code;
        // cout<<"in"<<$$->token;
        (yyval.node)->flag=(yyvsp[0].node)->flag;
        (yyval.node)->type=(yyvsp[0].node)->type;
        (yyval.node)->dims=(yyvsp[0].node)->dims;
    }
#line 8840 "lalr1.tab.c"
    break;

  case 337: /* AdditiveExpression: AdditiveExpression ADD MultiplicativeExpression  */
#line 4769 "lalr1.y"
                                                        {
        (yyval.node)=new astnode;
        (yyval.node)->token="AdditiveExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        string temp=get_tempvar();
        temp=symtypeEvaluate((yyvsp[-2].node)->type,(yyvsp[0].node)->type,(yyvsp[-1].node)->lexeme);
        if(temp=="0")
        {
            cout<<"Error, type incompatible";
        }
        if((yyvsp[-2].node)->type != (yyvsp[0].node)->type)
        {   if((yyvsp[-2].node)->type==temp){
                string t1=get_tempvar(),t2;
                s1=t1+" =cast_to_"+temp+" "+(yyvsp[0].node)->tac_val;
                prog.push_back(s1);
                (yyvsp[0].node)->tac_val=t1;
                // t2=get_tempvar();

            }
                
            else s1="cast_to_"+temp+" "+(yyvsp[-2].node)->tac_val;
        }
        s2=temp+"+";
        (yyval.node)->type=temp;
        string temp1=get_tempvar();
        (yyval.node)->tac_val=temp1;
        string tac="";
        // tac=tac+$2->lexeme+","+$1->tac_val+","+$3->tac_val+","+temp;
        tac=temp1+" = "+(yyvsp[-2].node)->tac_val+" "+(yyvsp[-1].node)->lexeme+" "+(yyvsp[0].node)->tac_val;
        (yyval.node)->code=tac+"\n";
         prog.push_back(tac);
        // cout<<"in"<<$$->token;
    }
#line 8882 "lalr1.tab.c"
    break;

  case 338: /* AdditiveExpression: AdditiveExpression SUB MultiplicativeExpression  */
#line 4806 "lalr1.y"
                                                        {
        (yyval.node)=new astnode;
        (yyval.node)->token="AdditiveExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        temp=symtypeEvaluate((yyvsp[-2].node)->type,(yyvsp[0].node)->type,(yyvsp[-1].node)->lexeme);
        if(temp=="0")
        {
            cout<<"Error, type incompatible";
        }
        if((yyvsp[-2].node)->type != (yyvsp[0].node)->type)
        {   if((yyvsp[-2].node)->type==temp){
                string t1=get_tempvar(),t2;
                s1=t1+" =cast_to_"+temp+" "+(yyvsp[0].node)->tac_val;
                prog.push_back(s1);
                (yyvsp[0].node)->tac_val=t1;
                // t2=get_tempvar();

            }
                
            else s1="cast_to_"+temp+" "+(yyvsp[-2].node)->tac_val;
        }
        s2=temp+"-";
        (yyval.node)->type=temp;
        string temp1=get_tempvar();
        (yyval.node)->tac_val=temp1;
        string tac="";
        // tac=tac+$2->lexeme+","+$1->tac_val+","+$3->tac_val+","+temp;
        tac=temp1+" = "+(yyvsp[-2].node)->tac_val+" "+(yyvsp[-1].node)->lexeme+" "+(yyvsp[0].node)->tac_val;
        (yyval.node)->code=tac+"\n";
         prog.push_back(tac);
        // cout<<"in"<<$$->token;
    }
#line 8923 "lalr1.tab.c"
    break;

  case 339: /* ShiftExpression: AdditiveExpression  */
#line 4844 "lalr1.y"
                          {
        (yyval.node)=new astnode;
        (yyval.node)->token="ShiftExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        (yyval.node)->code=(yyvsp[0].node)->code;
        // cout<<"in"<<$$->token;
        (yyval.node)->flag=(yyvsp[0].node)->flag;
        (yyval.node)->type=(yyvsp[0].node)->type;
        (yyval.node)->dims=(yyvsp[0].node)->dims;
    }
#line 8941 "lalr1.tab.c"
    break;

  case 340: /* ShiftExpression: ShiftExpression SHL AdditiveExpression  */
#line 4857 "lalr1.y"
                                               {
        (yyval.node)=new astnode;
        (yyval.node)->token="ShiftExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
       temp=symtypeEvaluate((yyvsp[-2].node)->type,(yyvsp[0].node)->type,(yyvsp[-1].node)->lexeme);
        if(temp=="0")
        {
            cout<<"Error, type incompatible";
        }
        if((yyvsp[-2].node)->type != (yyvsp[0].node)->type)
        {   if((yyvsp[-2].node)->type==temp){
                string t1=get_tempvar(),t2;
                s1=t1+" =cast_to_"+temp+" "+(yyvsp[0].node)->tac_val;
                prog.push_back(s1);
                (yyvsp[0].node)->tac_val=t1;
                // t2=get_tempvar();

            }
                
            else s1="cast_to_"+temp+" "+(yyvsp[-2].node)->tac_val;
        }
        s2=temp+"<<";
        (yyval.node)->type=temp;
        string temp1=get_tempvar();
        (yyval.node)->tac_val=temp1;
        string tac="";
        // tac=tac+$2->lexeme+","+$1->tac_val+","+$3->tac_val+","+temp;
        tac=temp1+" = "+(yyvsp[-2].node)->tac_val+" "+(yyvsp[-1].node)->lexeme+" "+(yyvsp[0].node)->tac_val;
        (yyval.node)->code=tac+"\n";
         prog.push_back(tac);
        // cout<<"in"<<$$->token;
    }
#line 8982 "lalr1.tab.c"
    break;

  case 341: /* ShiftExpression: ShiftExpression SHR AdditiveExpression  */
#line 4893 "lalr1.y"
                                                {
        (yyval.node)=new astnode;
        (yyval.node)->token="ShiftExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        temp=symtypeEvaluate((yyvsp[-2].node)->type,(yyvsp[0].node)->type,(yyvsp[-1].node)->lexeme);
        if(temp=="0")
        {
            cout<<"Error, type incompatible";
        }
        if((yyvsp[-2].node)->type != (yyvsp[0].node)->type)
        {   if((yyvsp[-2].node)->type==temp){
                string t1=get_tempvar(),t2;
                s1=t1+" =cast_to_"+temp+" "+(yyvsp[0].node)->tac_val;
                prog.push_back(s1);
                (yyvsp[0].node)->tac_val=t1;
                // t2=get_tempvar();

            }
                
            else s1="cast_to_"+temp+" "+(yyvsp[-2].node)->tac_val;
        }
        s2=temp+">>";
        (yyval.node)->type=temp;
        string temp1=get_tempvar();
        (yyval.node)->tac_val=temp1;
        string tac="";
        // tac=tac+$2->lexeme+","+$1->tac_val+","+$3->tac_val+","+temp;
        tac=temp1+" = "+(yyvsp[-2].node)->tac_val+" "+(yyvsp[-1].node)->lexeme+" "+(yyvsp[0].node)->tac_val;
        (yyval.node)->code=tac+"\n";
         prog.push_back(tac);
        // cout<<"in"<<$$->token;
    }
#line 9023 "lalr1.tab.c"
    break;

  case 342: /* ShiftExpression: ShiftExpression GR AdditiveExpression  */
#line 4929 "lalr1.y"
                                              {
        (yyval.node)=new astnode;
        (yyval.node)->token="ShiftExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        temp=symtypeEvaluate((yyvsp[-2].node)->type,(yyvsp[0].node)->type,(yyvsp[-1].node)->lexeme);
        if(temp=="0")
        {
            cout<<"Error, type incompatible";
        }
        if((yyvsp[-2].node)->type != (yyvsp[0].node)->type)
        {   if((yyvsp[-2].node)->type==temp){
                string t1=get_tempvar(),t2;
                s1=t1+" =cast_to_"+temp+" "+(yyvsp[0].node)->tac_val;
                prog.push_back(s1);
                (yyvsp[0].node)->tac_val=t1;
                // t2=get_tempvar();

            }
                
            else s1="cast_to_"+temp+" "+(yyvsp[-2].node)->tac_val;
        }
        s2=temp+">>>";
        (yyval.node)->type=temp;
        string temp1=get_tempvar();
        (yyval.node)->tac_val=temp1;
        string tac="";
        // tac=tac+$2->lexeme+","+$1->tac_val+","+$3->tac_val+","+temp;
        tac=temp1+" = "+(yyvsp[-2].node)->tac_val+" "+(yyvsp[-1].node)->lexeme+" "+(yyvsp[0].node)->tac_val;
        (yyval.node)->code=tac+"\n";
         prog.push_back(tac);
        // cout<<"in"<<$$->token;
    }
#line 9064 "lalr1.tab.c"
    break;

  case 343: /* RelationalExpression: ShiftExpression  */
#line 4967 "lalr1.y"
                       {
        (yyval.node)=new astnode;
        (yyval.node)->token="RelationalExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        (yyval.node)->code=(yyvsp[0].node)->code;
        // cout<<"in"<<$$->token;
        (yyval.node)->flag=(yyvsp[0].node)->flag;
        (yyval.node)->type=(yyvsp[0].node)->type;
        (yyval.node)->dims=(yyvsp[0].node)->dims;
    }
#line 9082 "lalr1.tab.c"
    break;

  case 344: /* RelationalExpression: RelationalExpression LSS ShiftExpression  */
#line 4980 "lalr1.y"
                                                 {
        (yyval.node)=new astnode;
        (yyval.node)->token="RelationalExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        temp=symtypeEvaluate((yyvsp[-2].node)->type,(yyvsp[0].node)->type,(yyvsp[-1].node)->lexeme);
        if(temp=="0")
        {
            cout<<"Error, type incompatible";
        }
        if((yyvsp[-2].node)->type != (yyvsp[0].node)->type)
        {   if((yyvsp[-2].node)->type==temp){
                string t1=get_tempvar(),t2;
                s1=t1+" =cast_to_"+temp+" "+(yyvsp[0].node)->tac_val;
                prog.push_back(s1);
                (yyvsp[0].node)->tac_val=t1;
                // t2=get_tempvar();

            }
                
            else s1="cast_to_"+temp+" "+(yyvsp[-2].node)->tac_val;
        }
        s2=temp+"<";
        (yyval.node)->type="boolean";
        string temp1=get_tempvar();
        (yyval.node)->tac_val=temp1;
        string tac="";
        // tac=tac+$2->lexeme+","+$1->tac_val+","+$3->tac_val+","+temp;
        tac=temp1+" = "+(yyvsp[-2].node)->tac_val+" "+(yyvsp[-1].node)->lexeme+" "+(yyvsp[0].node)->tac_val;
        (yyval.node)->code=tac+"\n";
         prog.push_back(tac);
        // cout<<"in"<<$$->token;
    }
#line 9123 "lalr1.tab.c"
    break;

  case 345: /* RelationalExpression: RelationalExpression GTR ShiftExpression  */
#line 5016 "lalr1.y"
                                                 {
        (yyval.node)=new astnode;
        (yyval.node)->token="RelationalExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        temp=symtypeEvaluate((yyvsp[-2].node)->type,(yyvsp[0].node)->type,(yyvsp[-1].node)->lexeme);
        if(temp=="0")
        {
            cout<<"Error, type incompatible";
        }
        if((yyvsp[-2].node)->type != (yyvsp[0].node)->type)
        {   if((yyvsp[-2].node)->type==temp){
                string t1=get_tempvar(),t2;
                s1=t1+" =cast_to_"+temp+" "+(yyvsp[0].node)->tac_val;
                prog.push_back(s1);
                (yyvsp[0].node)->tac_val=t1;
                // t2=get_tempvar();

            }
                
            else s1="cast_to_"+temp+" "+(yyvsp[-2].node)->tac_val;
        }
        s2=temp+">";
        (yyval.node)->type="boolean";
        string temp1=get_tempvar();
        (yyval.node)->tac_val=temp1;
        string tac="";
        // tac=tac+$2->lexeme+","+$1->tac_val+","+$3->tac_val+","+temp;
        tac=temp1+" = "+(yyvsp[-2].node)->tac_val+" "+(yyvsp[-1].node)->lexeme+" "+(yyvsp[0].node)->tac_val;
        (yyval.node)->code=tac+"\n";
         prog.push_back(tac);
        // cout<<"in"<<$$->token;
    }
#line 9164 "lalr1.tab.c"
    break;

  case 346: /* RelationalExpression: RelationalExpression LEQ ShiftExpression  */
#line 5052 "lalr1.y"
                                                 {
        (yyval.node)=new astnode;
        (yyval.node)->token="RelationalExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        temp=symtypeEvaluate((yyvsp[-2].node)->type,(yyvsp[0].node)->type,(yyvsp[-1].node)->lexeme);
        if(temp=="0")
        {
            cout<<"Error, type incompatible";
        }
        if((yyvsp[-2].node)->type != (yyvsp[0].node)->type)
        {   if((yyvsp[-2].node)->type==temp){
                string t1=get_tempvar(),t2;
                s1=t1+" =cast_to_"+temp+" "+(yyvsp[0].node)->tac_val;
                prog.push_back(s1);
                (yyvsp[0].node)->tac_val=t1;
                // t2=get_tempvar();

            }
                
            else s1="cast_to_"+temp+" "+(yyvsp[-2].node)->tac_val;
        }
        s2=temp+"<=";
        (yyval.node)->type="boolean";
        string temp1=get_tempvar();
        (yyval.node)->tac_val=temp1;
        string tac="";
        // tac=tac+$2->lexeme+","+$1->tac_val+","+$3->tac_val+","+temp;
        tac=temp1+" = "+(yyvsp[-2].node)->tac_val+" "+(yyvsp[-1].node)->lexeme+" "+(yyvsp[0].node)->tac_val;
        (yyval.node)->code=tac+"\n";
         prog.push_back(tac);
        // cout<<"in"<<$$->token;
    }
#line 9205 "lalr1.tab.c"
    break;

  case 347: /* RelationalExpression: RelationalExpression GEQ ShiftExpression  */
#line 5088 "lalr1.y"
                                                 {
        (yyval.node)=new astnode;
        (yyval.node)->token="RelationalExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        temp=symtypeEvaluate((yyvsp[-2].node)->type,(yyvsp[0].node)->type,(yyvsp[-1].node)->lexeme);
        if(temp=="0")
        {
            cout<<"Error, type incompatible";
        }
        if((yyvsp[-2].node)->type != (yyvsp[0].node)->type)
        {   if((yyvsp[-2].node)->type==temp){
                string t1=get_tempvar(),t2;
                s1=t1+" =cast_to_"+temp+" "+(yyvsp[0].node)->tac_val;
                prog.push_back(s1);
                (yyvsp[0].node)->tac_val=t1;
                // t2=get_tempvar();

            }
                
            else s1="cast_to_"+temp+" "+(yyvsp[-2].node)->tac_val;
        }
        s2=temp+">=";
        (yyval.node)->type="boolean";
        string temp1=get_tempvar();
        (yyval.node)->tac_val=temp1;
        string tac="";
        // tac=tac+$2->lexeme+","+$1->tac_val+","+$3->tac_val+","+temp;
        tac=temp1+" = "+(yyvsp[-2].node)->tac_val+" "+(yyvsp[-1].node)->lexeme+" "+(yyvsp[0].node)->tac_val;
        (yyval.node)->code=tac+"\n";
         prog.push_back(tac);
        // cout<<"in"<<$$->token;
    }
#line 9246 "lalr1.tab.c"
    break;

  case 348: /* RelationalExpression: RelationalExpression INSTANCEOF ReferenceType  */
#line 5124 "lalr1.y"
                                                      {
        (yyval.node)=new astnode;
        (yyval.node)->token="RelationalExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        temp=symAssignment((yyvsp[-2].node)->type,(yyvsp[0].node)->type);
        if(temp=="0")
        {
            cout<<"Error, type incompatible";
        }
        (yyval.node)->type="boolean";
        string tac,temp1=get_tempvar();
        tac=temp1+" = "+(yyvsp[-2].node)->tac_val+" "+(yyvsp[-1].node)->lexeme+" "+(yyvsp[0].node)->tac_val;
         prog.push_back(tac);
        (yyval.node)->tac_val=temp1;
    }
#line 9271 "lalr1.tab.c"
    break;

  case 349: /* EqualityExpression: RelationalExpression  */
#line 5146 "lalr1.y"
                            {
        (yyval.node)=new astnode;
        (yyval.node)->token="EqualityExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        (yyval.node)->code=(yyvsp[0].node)->code;
        // cout<<"in"<<$$->token;
        (yyval.node)->flag=(yyvsp[0].node)->flag;
        (yyval.node)->type=(yyvsp[0].node)->type;
        (yyval.node)->dims=(yyvsp[0].node)->dims;
    }
#line 9289 "lalr1.tab.c"
    break;

  case 350: /* EqualityExpression: EqualityExpression EQL RelationalExpression  */
#line 5159 "lalr1.y"
                                                    {
        (yyval.node)=new astnode;
        (yyval.node)->token="EqualityExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        temp=symtypeEvaluate((yyvsp[-2].node)->type,(yyvsp[0].node)->type,(yyvsp[-1].node)->lexeme);
        if(temp=="0")
        {
            cout<<"Error, type incompatible";
        }
        if((yyvsp[-2].node)->type != (yyvsp[0].node)->type)
        {   if((yyvsp[-2].node)->type==temp){
                string t1=get_tempvar(),t2;
                s1=t1+" =cast_to_"+temp+" "+(yyvsp[0].node)->tac_val;
                prog.push_back(s1);
                (yyvsp[0].node)->tac_val=t1;
                // t2=get_tempvar();

            }
                
            else s1="cast_to_"+temp+" "+(yyvsp[-2].node)->tac_val;
        }
        s2=temp+"==";
        (yyval.node)->type="boolean";
        string temp1=get_tempvar();
        (yyval.node)->tac_val=temp1;
        string tac="";
        // tac=$2->lexeme+","+$1->tac_val+","+$3->tac_val+","+temp;
        tac=temp1+" = "+(yyvsp[-2].node)->tac_val+" "+(yyvsp[-1].node)->lexeme+" "+(yyvsp[0].node)->tac_val;
        (yyval.node)->code=tac+"\n";
         prog.push_back(tac);
        // cout<<"in"<<$$->token;
    }
#line 9330 "lalr1.tab.c"
    break;

  case 351: /* EqualityExpression: EqualityExpression NEQ RelationalExpression  */
#line 5195 "lalr1.y"
                                                    {
        (yyval.node)=new astnode;
        (yyval.node)->token="EqualityExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        temp=symtypeEvaluate((yyvsp[-2].node)->type,(yyvsp[0].node)->type,(yyvsp[-1].node)->lexeme);
        if(temp=="0")
        {
            cout<<"Error, type incompatible";
        }
        if((yyvsp[-2].node)->type != (yyvsp[0].node)->type)
        {   if((yyvsp[-2].node)->type==temp){
                string t1=get_tempvar(),t2;
                s1=t1+" =cast_to_"+temp+" "+(yyvsp[0].node)->tac_val;
                prog.push_back(s1);
                (yyvsp[0].node)->tac_val=t1;
                // t2=get_tempvar();

            }
                
            else s1="cast_to_"+temp+" "+(yyvsp[-2].node)->tac_val;
        }
        s2=temp+"!=";
        (yyval.node)->type="boolean";
        string temp1=get_tempvar();
        (yyval.node)->tac_val=temp1;
        string tac="";
        // tac=tac+$2->lexeme+","+$1->tac_val+","+$3->tac_val+","+temp;
        tac=temp1+" = "+(yyvsp[-2].node)->tac_val+" "+(yyvsp[-1].node)->lexeme+" "+(yyvsp[0].node)->tac_val;
        (yyval.node)->code=tac+"\n";
         prog.push_back(tac);
        // cout<<"in"<<$$->token;
    }
#line 9371 "lalr1.tab.c"
    break;

  case 352: /* AndExpression: EqualityExpression  */
#line 5233 "lalr1.y"
                          {
        (yyval.node)=new astnode;
        (yyval.node)->token="AndExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        (yyval.node)->code=(yyvsp[0].node)->code;
        // cout<<"in"<<$$->token;
        (yyval.node)->flag=(yyvsp[0].node)->flag;
        (yyval.node)->type=(yyvsp[0].node)->type;
        (yyval.node)->dims=(yyvsp[0].node)->dims;
    }
#line 9389 "lalr1.tab.c"
    break;

  case 353: /* AndExpression: AndExpression AMPERSAT EqualityExpression  */
#line 5246 "lalr1.y"
                                                  {
        (yyval.node)=new astnode;
        (yyval.node)->token="AndExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        temp=symtypeEvaluate((yyvsp[-2].node)->type,(yyvsp[0].node)->type,(yyvsp[-1].node)->lexeme);
        if(temp=="0")
        {
            cout<<"Error, type incompatible";
        }
        if((yyvsp[-2].node)->type != (yyvsp[0].node)->type)
        {   if((yyvsp[-2].node)->type==temp){
                string t1=get_tempvar(),t2;
                s1=t1+" =cast_to_"+temp+" "+(yyvsp[0].node)->tac_val;
                prog.push_back(s1);
                (yyvsp[0].node)->tac_val=t1;
                // t2=get_tempvar();

            }
                
            else s1="cast_to_"+temp+" "+(yyvsp[-2].node)->tac_val;
        }
        s2=temp+"&";
        (yyval.node)->type="boolean";
        string temp1=get_tempvar();
        (yyval.node)->tac_val=temp1;
        string tac="";
        // tac=tac+$2->lexeme+","+$1->tac_val+","+$3->tac_val+","+temp;
        tac=temp1+" = "+(yyvsp[-2].node)->tac_val+" "+(yyvsp[-1].node)->lexeme+" "+(yyvsp[0].node)->tac_val;
        (yyval.node)->code=tac+"\n";
         prog.push_back(tac);
        // cout<<"in"<<$$->token;
    }
#line 9430 "lalr1.tab.c"
    break;

  case 354: /* ExclusiveOrExpression: AndExpression  */
#line 5284 "lalr1.y"
                     {
        (yyval.node)=new astnode;
        (yyval.node)->token="ExclusiveOrExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        (yyval.node)->code=(yyvsp[0].node)->code;
        // cout<<"in"<<$$->token;
        (yyval.node)->flag=(yyvsp[0].node)->flag;
        (yyval.node)->type=(yyvsp[0].node)->type;
        (yyval.node)->dims=(yyvsp[0].node)->dims;
    }
#line 9448 "lalr1.tab.c"
    break;

  case 355: /* ExclusiveOrExpression: ExclusiveOrExpression XOR AndExpression  */
#line 5297 "lalr1.y"
                                                {
        (yyval.node)=new astnode;
        (yyval.node)->token="ExclusiveOrExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        temp=symtypeEvaluate((yyvsp[-2].node)->type,(yyvsp[0].node)->type,(yyvsp[-1].node)->lexeme);
        if(temp=="0")
        {
            cout<<"Error, type incompatible";
        }
        if((yyvsp[-2].node)->type != (yyvsp[0].node)->type)
        {   if((yyvsp[-2].node)->type==temp){
                string t1=get_tempvar(),t2;
                s1=t1+" =cast_to_"+temp+" "+(yyvsp[0].node)->tac_val;
                prog.push_back(s1);
                (yyvsp[0].node)->tac_val=t1;
                // t2=get_tempvar();

            }
                
            else s1="cast_to_"+temp+" "+(yyvsp[-2].node)->tac_val;
        }
        s2=temp+"^";
        (yyval.node)->type="boolean";
        string temp1=get_tempvar();
        (yyval.node)->tac_val=temp1;
        string tac="";
        // tac=tac+$2->lexeme+","+$1->tac_val+","+$3->tac_val+","+temp;
        tac=temp1+" = "+(yyvsp[-2].node)->tac_val+" "+(yyvsp[-1].node)->lexeme+" "+(yyvsp[0].node)->tac_val;
        (yyval.node)->code=tac+"\n";
         prog.push_back(tac);
        // cout<<"in"<<$$->token;
    }
#line 9489 "lalr1.tab.c"
    break;

  case 356: /* InclusiveOrExpression: ExclusiveOrExpression  */
#line 5335 "lalr1.y"
                             {
        (yyval.node)=new astnode;
        (yyval.node)->token="InclusiveOrExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        (yyval.node)->code=(yyvsp[0].node)->code;
        // cout<<"in"<<$$->token;
        (yyval.node)->flag=(yyvsp[0].node)->flag;
        (yyval.node)->type=(yyvsp[0].node)->type;
        (yyval.node)->dims=(yyvsp[0].node)->dims;
    }
#line 9507 "lalr1.tab.c"
    break;

  case 357: /* InclusiveOrExpression: InclusiveOrExpression OR ExclusiveOrExpression  */
#line 5348 "lalr1.y"
                                                       {
        (yyval.node)=new astnode;
        (yyval.node)->token="InclusiveOrExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        temp=symtypeEvaluate((yyvsp[-2].node)->type,(yyvsp[0].node)->type,(yyvsp[-1].node)->lexeme);
        if(temp=="0")
        {
            cout<<"Error, type incompatible";
        }
        if((yyvsp[-2].node)->type != (yyvsp[0].node)->type)
        {   if((yyvsp[-2].node)->type==temp){
                string t1=get_tempvar(),t2;
                s1=t1+" =cast_to_"+temp+" "+(yyvsp[0].node)->tac_val;
                prog.push_back(s1);
                (yyvsp[0].node)->tac_val=t1;
                // t2=get_tempvar();

            }
                
            else s1="cast_to_"+temp+" "+(yyvsp[-2].node)->tac_val;
        }
        s2=temp+"|";
        (yyval.node)->type="boolean";
        string temp1=get_tempvar();
        (yyval.node)->tac_val=temp1;
        string tac="";
        // tac=tac+$2->lexeme+","+$1->tac_val+","+$3->tac_val+","+temp;
        tac=temp1+" = "+(yyvsp[-2].node)->tac_val+" "+(yyvsp[-1].node)->lexeme+" "+(yyvsp[0].node)->tac_val;
        (yyval.node)->code=tac+"\n";
         prog.push_back(tac);
        // cout<<"in"<<$$->token;
    }
#line 9548 "lalr1.tab.c"
    break;

  case 358: /* ConditionalAndExpression: InclusiveOrExpression  */
#line 5386 "lalr1.y"
                             {
        (yyval.node)=new astnode;
        (yyval.node)->token="ConditionalAndExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        (yyval.node)->code=(yyvsp[0].node)->code;
        // cout<<"in"<<$$->token;
        (yyval.node)->flag=(yyvsp[0].node)->flag;
        (yyval.node)->type=(yyvsp[0].node)->type;
        (yyval.node)->dims=(yyvsp[0].node)->dims;
    }
#line 9566 "lalr1.tab.c"
    break;

  case 359: /* ConditionalAndExpression: ConditionalAndExpression LAND InclusiveOrExpression  */
#line 5399 "lalr1.y"
                                                            {
        (yyval.node)=new astnode;
        (yyval.node)->token="ConditionalAndExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        temp=symtypeEvaluate((yyvsp[-2].node)->type,(yyvsp[0].node)->type,(yyvsp[-1].node)->lexeme);
        if(temp=="0")
        {
            cout<<"Error, type incompatible";
        }
        if((yyvsp[-2].node)->type != (yyvsp[0].node)->type)
        {   if((yyvsp[-2].node)->type==temp){
                string t1=get_tempvar(),t2;
                s1=t1+" =cast_to_"+temp+" "+(yyvsp[0].node)->tac_val;
                prog.push_back(s1);
                (yyvsp[0].node)->tac_val=t1;
                // t2=get_tempvar();

            }
                
            else s1="cast_to_"+temp+" "+(yyvsp[-2].node)->tac_val;
        }
        s2=temp+"&&";
        (yyval.node)->type="boolean";
        string temp1=get_tempvar();
        (yyval.node)->tac_val=temp1;
        string tac="";
        // tac=tac+$2->lexeme+","+$1->tac_val+","+$3->tac_val+","+temp;
        tac=temp1+" = "+(yyvsp[-2].node)->tac_val+" "+(yyvsp[-1].node)->lexeme+" "+(yyvsp[0].node)->tac_val;
        (yyval.node)->code=tac+"\n";
         prog.push_back(tac);
        // cout<<"in"<<$$->token;
    }
#line 9607 "lalr1.tab.c"
    break;

  case 360: /* ConditionalOrExpression: ConditionalAndExpression  */
#line 5437 "lalr1.y"
                                {
        (yyval.node)=new astnode;
        (yyval.node)->token="ConditionalOrExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        (yyval.node)->code=(yyvsp[0].node)->code;
        // cout<<"in"<<$$->token;
        (yyval.node)->flag=(yyvsp[0].node)->flag;
        (yyval.node)->type=(yyvsp[0].node)->type;
        (yyval.node)->dims=(yyvsp[0].node)->dims;
    }
#line 9625 "lalr1.tab.c"
    break;

  case 361: /* ConditionalOrExpression: ConditionalOrExpression LOR ConditionalAndExpression  */
#line 5450 "lalr1.y"
                                                             {
        (yyval.node)=new astnode;
        (yyval.node)->token="ConditionalOrExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        temp=symtypeEvaluate((yyvsp[-2].node)->type,(yyvsp[0].node)->type,(yyvsp[-1].node)->lexeme);
        if(temp=="0")
        {
            cout<<"Error, type incompatible";
        }
        if((yyvsp[-2].node)->type != (yyvsp[0].node)->type)
        {   if((yyvsp[-2].node)->type==temp){
                string t1=get_tempvar(),t2;
                s1=t1+" =cast_to_"+temp+" "+(yyvsp[0].node)->tac_val;
                prog.push_back(s1);
                (yyvsp[0].node)->tac_val=t1;
                // t2=get_tempvar();

            }
                
            else s1="cast_to_"+temp+" "+(yyvsp[-2].node)->tac_val;
        }
        s2=temp+"||";
        (yyval.node)->type="boolean";
        string temp1=get_tempvar();
        (yyval.node)->tac_val=temp1;
        string tac="";
        // tac=tac+$2->lexeme+","+$1->tac_val+","+$3->tac_val+","+temp;
        tac=temp1+" = "+(yyvsp[-2].node)->tac_val+" "+(yyvsp[-1].node)->lexeme+" "+(yyvsp[0].node)->tac_val;
        (yyval.node)->code=tac+"\n";
         prog.push_back(tac);
        // cout<<"in"<<$$->token;
    }
#line 9666 "lalr1.tab.c"
    break;

  case 362: /* ConditionalExpression: ConditionalOrExpression  */
#line 5488 "lalr1.y"
                               {
        (yyval.node)=new astnode;
        (yyval.node)->token="ConditionalExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        (yyval.node)->code=(yyvsp[0].node)->code;
        // cout<<"in"<<$$->token;
        (yyval.node)->flag=(yyvsp[0].node)->flag;
        (yyval.node)->type=(yyvsp[0].node)->type;
        (yyval.node)->dims=(yyvsp[0].node)->dims;
    }
#line 9684 "lalr1.tab.c"
    break;

  case 363: /* ConditionalExpression: ConditionalOrExpression CONDMARK1 QMARK Expression CONDMARK2 COLON ConditionalExpression CONDMARK3  */
#line 5501 "lalr1.y"
                                                                                                            {
        (yyval.node)=new astnode;
        (yyval.node)->token="ConditionalExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[-7].node));
        v.push_back((yyvsp[-5].node));
        v.push_back((yyvsp[-4].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        (yyval.node)->children=v;
        temp=symtypeEvaluate((yyvsp[-4].node)->type,(yyvsp[-1].node)->type);
        if(temp=="0")
        {
            // yyerror("Error, type incompatible");
        }
        (yyval.node)->type=temp;
        // string temp=get_tempvar();
        // $$->tac_val=temp;
        // string tac="";
        // tac=tac+$2->lexeme+","+$1->tac_val+","+$3->tac_val+","+temp;
        //  prog.push_back(tac);
        // cout<<"in"<<$$->token;
    }
#line 9712 "lalr1.tab.c"
    break;

  case 364: /* AssignmentExpression: ConditionalExpression  */
#line 5526 "lalr1.y"
                             {
        (yyval.node)=new astnode;
        (yyval.node)->token="AssignmentExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        (yyval.node)->code=(yyvsp[0].node)->code;
        // cout<<"in"<<$$->token;
        (yyval.node)->flag=(yyvsp[0].node)->flag;
        (yyval.node)->type=(yyvsp[0].node)->type;
        (yyval.node)->dims=(yyvsp[0].node)->dims;
    }
#line 9730 "lalr1.tab.c"
    break;

  case 365: /* AssignmentExpression: Assignment  */
#line 5539 "lalr1.y"
                   {
        (yyval.node)=new astnode;
        (yyval.node)->token="AssignmentExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        (yyval.node)->code=(yyvsp[0].node)->code;
        // cout<<"in"<<$$->token;
        (yyval.node)->type=(yyvsp[0].node)->type;
    }
#line 9746 "lalr1.tab.c"
    break;

  case 366: /* Assignment: LeftHandSide AssignmentOperator AssignmentExpression  */
#line 5552 "lalr1.y"
                                                            {
        (yyval.node)=new astnode;
        (yyval.node)->token="Assignment";
        vector<astnode*>v;
        // cout<<$3->tac_val<<endl;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // string temp=get_tempvar();
        (yyval.node)->tac_val=(yyvsp[-2].node)->tac_val;
        string tac="";
        // tac=tac+$2->tac_val+","+$1->tac_val+","+$3->tac_val+","+$1->tac_val;
        // cout<<"in"<<$$->token;
        if((yyvsp[0].node)->type=="String" && !((yyvsp[-1].node)->lexeme=="+="||(yyvsp[-1].node)->lexeme=="="))
        {
            cout<<"String operation undefined";
            // exit(0);
        }
        // check for Strings once
        temp=symAssignment((yyvsp[-2].node)->type,(yyvsp[0].node)->type);
        // cout<<$1->type<<" "<<$3->type;
       if(temp=="0")
        {
            cout<<"Error, type incompatible";
        }
        // if(($1->flag==4&&$3->flag!=4)||($1->flag!=4&&$3->flag==4)) cout<<"Error, type incompatible";
        // cout<<$1->flag<<" "<<$3->flag;
        if((yyvsp[-2].node)->flag==4||(yyvsp[0].node)->flag==4) {
            Type*t=symtabGetTypep(fullscope,(yyvsp[-2].node)->value);
            if(t){
                // cout<<" "<<t->dims<<" "<<$1->value<<" "<<$3->dims<<endl;
                if(t->dims!=(yyvsp[0].node)->dims) cout<<"Error, dims are different";
            }
        }
        if((yyvsp[-2].node)->type != (yyvsp[0].node)->type)
        {   
            s1="typecast_to_"+temp+" t"+to_string(tempno-1);
            string t=get_tempvar();
            s1=t+" ="+s1;
            prog.push_back(s1);
        }
        s2=(yyvsp[-1].node)->tac_val+temp;
        // temp="int";
        if((yyvsp[0].node)->flag==1)
        tac=(yyvsp[-2].node)->tac_val+" "+s2+" t"+to_string(tempno-1);
        else tac=(yyvsp[-2].node)->tac_val+" "+s2+" "+(yyvsp[0].node)->tac_val;
        (yyval.node)->code=tac+"\n";
        vector<string>v2=split((yyvsp[-2].node)->tac_val,'.');
        if(v2[0]=="this"){
            string s3=searchthis(fullscope);
            string classname="";
            map<string,string>::iterator it=m1.begin();
            while(it!=m1.end()){
                if(s3==it->second) {
                    classname=it->first;
                    break;
                }
                it++;
            }
            tac=get_tempvar()+" = symtable("+classname+","+v2[1]+")\n"+"*(obj_ref+t"+to_string(tempno)+") = "+(yyvsp[0].node)->tac_val;
        }
        v2=split((yyvsp[0].node)->tac_val,'.');
        if(v2[0]=="this"){
            string s3=searchthis(fullscope);
            string classname="";
            map<string,string>::iterator it=m1.begin();
            while(it!=m1.end()){
                if(s3==it->second) {
                    classname=it->first;
                    break;
                }
                it++;
            }
            tac=get_tempvar()+" = symtable("+classname+","+v2[1]+")\n"+(yyvsp[-2].node)->tac_val+" = *(obj_ref+t"+to_string(tempno)+")";
        }
         prog.push_back(tac);
        //  cout<<tac<<endl;
        (yyval.node)->type=temp;
    }
#line 9831 "lalr1.tab.c"
    break;

  case 367: /* LeftHandSide: Name  */
#line 5634 "lalr1.y"
            {
        (yyval.node)=new astnode;
        (yyval.node)->token="LeftHandSide";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        (yyval.node)->value=(yyvsp[0].node)->value;
        // cout<<"in"<<$$->token;
        (yyval.node)->type=(yyvsp[0].node)->type;
    }
#line 9847 "lalr1.tab.c"
    break;

  case 368: /* LeftHandSide: FieldAccess  */
#line 5645 "lalr1.y"
                    {
        (yyval.node)=new astnode;
        (yyval.node)->token="LeftHandSide";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        (yyval.node)->type=(yyvsp[0].node)->type;
    }
#line 9862 "lalr1.tab.c"
    break;

  case 369: /* LeftHandSide: ArrayAccess  */
#line 5655 "lalr1.y"
                    {
        (yyval.node)=new astnode;
        (yyval.node)->token="LeftHandSide";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        (yyval.node)->type=(yyvsp[0].node)->type;
        Type*t=symtabGetTypep(fullscope,(yyvsp[0].node)->value);
        if(t){
            if(t->dims!=(yyvsp[0].node)->dims) cout<<"Error dimension incorrect";
        }
    }
#line 9881 "lalr1.tab.c"
    break;

  case 370: /* AssignmentOperator: ASSIGN  */
#line 5671 "lalr1.y"
          {
        (yyval.node)=new astnode;
        (yyval.node)->token="AssignmentOperator";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->tac_val=(yyvsp[0].node)->lexeme;
        // cout<<"in"<<$$->token;
    }
#line 9895 "lalr1.tab.c"
    break;

  case 371: /* AssignmentOperator: MUL_ASSIGN  */
#line 5680 "lalr1.y"
                {
        (yyval.node)=new astnode;
        (yyval.node)->token="AssignmentOperator";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->tac_val=(yyvsp[0].node)->lexeme;
        // cout<<"in"<<$$->token;
    }
#line 9909 "lalr1.tab.c"
    break;

  case 372: /* AssignmentOperator: QUO_ASSIGN  */
#line 5689 "lalr1.y"
                {
        (yyval.node)=new astnode;
        (yyval.node)->token="AssignmentOperator";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->tac_val=(yyvsp[0].node)->lexeme;
        // cout<<"in"<<$$->token;
    }
#line 9923 "lalr1.tab.c"
    break;

  case 373: /* AssignmentOperator: REM_ASSIGN  */
#line 5698 "lalr1.y"
                {
        (yyval.node)=new astnode;
        (yyval.node)->token="AssignmentOperator";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->tac_val=(yyvsp[0].node)->lexeme;
        // cout<<"in"<<$$->token;
    }
#line 9937 "lalr1.tab.c"
    break;

  case 374: /* AssignmentOperator: ADD_ASSIGN  */
#line 5707 "lalr1.y"
                {
        (yyval.node)=new astnode;
        (yyval.node)->token="AssignmentOperator";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->tac_val=(yyvsp[0].node)->lexeme;
        // cout<<"in"<<$$->token;
    }
#line 9951 "lalr1.tab.c"
    break;

  case 375: /* AssignmentOperator: SUB_ASSIGN  */
#line 5716 "lalr1.y"
                {
        (yyval.node)=new astnode;
        (yyval.node)->token="AssignmentOperator";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->tac_val=(yyvsp[0].node)->lexeme;
        // cout<<"in"<<$$->token;
    }
#line 9965 "lalr1.tab.c"
    break;

  case 376: /* AssignmentOperator: SHL_ASSIGN  */
#line 5725 "lalr1.y"
                {
        (yyval.node)=new astnode;
        (yyval.node)->token="AssignmentOperator";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->tac_val=(yyvsp[0].node)->lexeme;
        // cout<<"in"<<$$->token;
    }
#line 9979 "lalr1.tab.c"
    break;

  case 377: /* AssignmentOperator: SHR_ASSIGN  */
#line 5734 "lalr1.y"
                {
        (yyval.node)=new astnode;
        (yyval.node)->token="AssignmentOperator";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->tac_val=(yyvsp[0].node)->lexeme;
        // cout<<"in"<<$$->token;
    }
#line 9993 "lalr1.tab.c"
    break;

  case 378: /* AssignmentOperator: GEQUAL  */
#line 5743 "lalr1.y"
            {
        (yyval.node)=new astnode;
        (yyval.node)->token="AssignmentOperator";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->tac_val=(yyvsp[0].node)->lexeme;
        // cout<<"in"<<$$->token;
    }
#line 10007 "lalr1.tab.c"
    break;

  case 379: /* AssignmentOperator: AND_ASSIGN  */
#line 5752 "lalr1.y"
                {
        (yyval.node)=new astnode;
        (yyval.node)->token="AssignmentOperator";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->tac_val=(yyvsp[0].node)->lexeme;
        // cout<<"in"<<$$->token;
    }
#line 10021 "lalr1.tab.c"
    break;

  case 380: /* AssignmentOperator: XOR_ASSIGN  */
#line 5761 "lalr1.y"
                {
        (yyval.node)=new astnode;
        (yyval.node)->token="AssignmentOperator";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->tac_val=(yyvsp[0].node)->lexeme;
        // cout<<"in"<<$$->token;
    }
#line 10035 "lalr1.tab.c"
    break;

  case 381: /* AssignmentOperator: OR_ASSIGN  */
#line 5770 "lalr1.y"
               {
        (yyval.node)=new astnode;
        (yyval.node)->token="AssignmentOperator";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->tac_val=(yyvsp[0].node)->lexeme;
        // cout<<"in"<<$$->token;
    }
#line 10049 "lalr1.tab.c"
    break;

  case 382: /* Expression: AssignmentExpression  */
#line 5781 "lalr1.y"
                            {
        (yyval.node)=new astnode;
        (yyval.node)->token="Expression";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        (yyval.node)->code=(yyvsp[0].node)->code;
        // cout<<"in"<<$$->token;
        (yyval.node)->flag=(yyvsp[0].node)->flag;
        (yyval.node)->type=(yyvsp[0].node)->type;
        (yyval.node)->dims=(yyvsp[0].node)->dims;
    }
#line 10067 "lalr1.tab.c"
    break;

  case 383: /* ConstantExpression: Expression  */
#line 5796 "lalr1.y"
                  {
        (yyval.node)=new astnode;
        (yyval.node)->token="ConstantExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        (yyval.node)->code=(yyvsp[0].node)->code;
        // cout<<"in"<<$$->token;
        (yyval.node)->flag=(yyvsp[0].node)->flag;
        (yyval.node)->type=(yyvsp[0].node)->type;
    }
#line 10084 "lalr1.tab.c"
    break;


#line 10088 "lalr1.tab.c"

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
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
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
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 5809 "lalr1.y"



int nodeId = 0;
void prettyPrint(ofstream&astfile,astnode* root){
    // if((root->children.size()==1)&&(root->children[0]!=NULL)){
    //     while((root->children.size()==1)&&(root->children[0]!=NULL)){
    //         root=root->children[0];
    //     }
    // }
    if(root->token=="STR_LIT"){
        string str=root->token;
        str+="(";
        string str1=root->lexeme;
        str1=str1.substr(1,str1.length()-2);
        str+=str1;
        str+=")";
        astfile << nodeId << " [label=\"" << str << "\"]" << endl;
    }
    else if(root->lexeme!="lexeme"){
        string str=root->token;
        str+="(";
        str+=root->lexeme;
        str+=")";
        astfile << nodeId << " [label=\"" << str << "\"]" << endl;
    }
    else {
        astfile << nodeId << " [label=\"" << root->token << "\"]" << endl;
        
    }
	int parentId = nodeId;
	for(auto child : root->children){
        if(child) {
            astfile << parentId << "->" << ++nodeId << endl;
            prettyPrint(astfile,child);
        }
	}
}

// int main (int argc, char **argv) {
//     if(argc==2) {
//         yyin=fopen(argv[1],"r");
//         yyparse();
//     }
// 	// yyparse ( );
// 	// redirect ostream to file
// 	ofstream myfile;
// 	myfile.open ("ast.dot");
// 	cout.rdbuf(myfile.rdbuf());
// 	cout << "digraph \"src/parser.ypp\" \n { \n node [fontname = courier, shape = box, colorscheme = paired6] \n edge [fontname = courier]" << endl;
// 	prettyPrint(theprogram);
// 	cout << "}" << endl;
// }

void print_tac( ofstream& tac){
    // tac<<"op"<<","<<"arg1"<<","<<"arg2"<<","<<"result"<<endl;
	int i=0,l=prog.size(),of=0;
    for(i=0;i<l;i++) {
        vector<string> words=split(prog[i],' ');
        if((words[0]=="Pop")&&(of!=0)){tac<<"SP = SP + "<<of<<endl;tac<<prog[i]<<endl;}
        else if(words[0]!="pop"){
            tac<<prog[i]<<endl;
        }
        else {
            symtab_t* table;
            while(words[0]=="pop"){
                i+=1;
                table=symtab_top[words[1]];
                // tac<<prog[i]<<endl;
                words=split(prog[i],' ');
            }
            i-=1;
            of=getoffset(table, 0);
            tac<<"SP = SP - "<<getoffset(table, 0)<<endl;
            for(auto i=table->begin();i!=table->end();i++){
                if(i->second->flag){
                    tac<<i->first<<" = BP + "<<4+i->second->offset<<endl;
                }
                else {tac<<i->first<<" = BP - "<<i->second->offset<<endl;}
            } 
        }
    }
}

void print_symtab( ){
    ofstream symtabf;
    int count=0;
	string curr_fcn_scope = "";
    symtab_t* sym;
    
	for( auto symt : symtab_top ){

        symtabf.open("SymbolTable"+to_string(count++)+".csv");
        symtabf<<"name"<<","<<"lineno"<<","<<"type"<<","<<"size"<<","<<"args"<<","<<"access_specifier"<<","<<"dims"<<","<<"flag"<<","<<"offset"<<endl;
		curr_fcn_scope = symt.first;
	    symtabf <<"----Symbtab for scope "<< curr_fcn_scope <<"----"<<endl;
	// symbolTable <<"Scope_num Sym_name"<<endl;
	for( auto i=(symt.second)->begin(); i != (symt.second)->end(); i++ ){
		// symbolTable <<i->first;
		if( i->second != NULL ) {
			// symbolTable << " " << i->second->type <<endl;
            // if(i->second->args!="args") symbolTable<<i->second->access_specifier<<" "<<i->second->type<< " " <<i->first  <<" "<<i->second->args <<endl;
            // else symbolTable  << i->second->type<<" " <<i->first<<endl;
            symtabf<<i->first<<","<<i->second->lineno<<","<<i->second->type<<","<<i->second->size<<","<<i->second->args<<","<<i->second->access_specifier<<","<<i->second->dims<<","<<i->second->flag<<","<<i->second->offset<<endl;
        }
	}
	symtabf <<endl<<"----DONE----"<<endl<<endl;
    symtabf.close();
}
}

// void print_symtab( ofstream& symbolTable){
// 	string curr_fcn_scope = "";
//     symtab_t* sym;
//     symbolTable<<"name"<<","<<"lineno"<<","<<"type"<<","<<"size"<<","<<"args"<<","<<"access_specifier"<<endl;
// 	for( auto symt : symtab_top ){
// 		// if( symtab == i.second ){
// 			curr_fcn_scope = symt.first;
// 		// 	break;
// 		// }
// 	// sym=symt.second;
// 	symbolTable <<"----Symbtab for scope "<< curr_fcn_scope <<"----"<<endl;
// 	// symbolTable <<"Scope_num Sym_name"<<endl;
// 	for( auto i=(symt.second)->begin(); i != (symt.second)->end(); i++ ){
// 		// symbolTable <<i->first;
// 		if( i->second != NULL ) {
// 			// symbolTable << " " << i->second->type <<endl;
//             // if(i->second->args!="args") symbolTable<<i->second->access_specifier<<" "<<i->second->type<< " " <<i->first  <<" "<<i->second->args <<endl;
//             // else symbolTable  << i->second->type<<" " <<i->first<<endl;
//             symbolTable<<i->first<<","<<i->second->lineno<<","<<i->second->type<<","<<i->second->size<<","<<i->second->args<<","<<i->second->access_specifier<<endl;
//         }
// 	}
// 	symbolTable <<endl<<"----DONE----"<<endl<<endl;
// }
// }

// int nodeId = 0;
// void prettyPrint(ofstream& astFile, astnode* root){
//     if(root->token=="STR_LIT"){
//         string str=root->token;
//         str+="(";
//         string str1=root->lexeme;
//         str1=str1.substr(1,str1.length()-2);
//         str+=str1;
//         str+=")";
//         astFile << nodeId << " [label=\"" << str << "\"]" << endl;
//     }
//     else if(root->lexeme!="lexeme"){
//         string str=root->token;
//         str+="(";
//         str+=root->lexeme;
//         str+=")";
//         astFile << nodeId << " [label=\"" << str << "\"]" << endl;
//     }
//     else {
//         if(root->children.size()!=1)
//         astFile << nodeId << " [label=\"" << root->token << "\"]" << endl;
        
//     }
// 	int parentId = nodeId;
// 	for(auto child : root->children){
//         if(child) {
//             if(root->children.size()!=1)
//                 astFile << parentId << "->" << ++nodeId << endl;
//             prettyPrint(astFile,child);
//         }
// 	}
// }

int main (int argc, char **argv) {
    string outputfile="ast.dot";
    // cout<<"hello"<<argc<<" "<<*argv<<argv[1];
    // if(argv[1]=="-help"){
    //                 cout<<"For the given AST generator, we have to run the file using the following command: ./a.out <command-line arguments>\n_________________\n-help    option is passed as the first argument to know how to pass command line arguments to AST generator\nThe first command line argument is always the input file if \"-help\" option is not used.\n-verbose    option is used for verbose error displaying\n-output    option is used to set the name of the output dot file. This is done using the following syntax: =<filename.dot>. For example -output=hi.dot\n_________________";
    //                 exit(0);
    //             }
    string y;
    switch(argc){
        case 2: y=argv[1];if(y=="-help"){
                    cout<<"For the given AST generator, we have to run the file using the following command: ./a.out <command-line arguments>\n_________________\n-help    option is passed as the first argument to know how to pass command line arguments to AST generator\nThe first command line argument is always the input file if \"-help\" option is not used.\n-verbose    option is used for verbose error displaying\n-output    option is used to set the name of the output dot file. This is done using the following syntax: =<filename.dot>. For example -output=hi.dot\n_________________";
                    return 0;
                }
                else break;
        case 3: y=argv[2];if(y=="-verbose"){
                    verb=1;
                    break;
                }
                else{
                    string x=argv[2];
                    outputfile=x.substr(8);
                    break;
                }
        case 4: y=argv[2];if(y=="-verbose"){
                    string x=argv[3];
                    outputfile=x.substr(8);
                }
                else{
                    string x=argv[2];
                    outputfile=x.substr(8);
                }
                verb=1;
                break;
        default: cout<<"Incorrect command line arguments, please use -help option to understand how to use them!";
    }

    // map<string,Type*>::iterator it=(*(symtab_top["r"])).begin();
    // while(it!=(*(symtab_top["r"])).end()){
    //     cout<<it->first<<" ";
    //     ++it;
    // }cout<<'\n';
    // map<string,Type*>m=(*(symtab_top["0"]));

	yyin=fopen(argv[1],"r");
    symbolTable.open("symbolTable.csv");
    tac.open("tac.txt");
    yyparse();
    // cout<<"\n"<<symtab_top.size()<<"\n";
	// ofstream myfile(outputfile);
    // //  ofstream myfile("ast.dot");

	// cout.rdbuf(myfile.rdbuf());
	// cout << "digraph \"src/parser.ypp\" \n { \n node [fontname = courier, shape = box, colorscheme = paired6] \n edge [fontname = courier]" << endl;
    // cout << "0" << " [label=\"" << theprogram->token << "\"]" << endl;
    // cout << "0" << "->" << ++nodeId << endl;
	// prettyPrint(theprogram);
	// cout << "}" << endl;

    ofstream astFile;
	astFile.open("ast.dot" );
    astFile << "digraph \"src/parser.ypp\" \n { \n node [fontname = courier, shape = box, colorscheme = paired6] \n edge [fontname = courier]" << endl;
	prettyPrint(astFile, theprogram);
	astFile << "}" << endl;
	astFile.close();
    cout<<"\ndone ast file\n";

    // print_symtab(symbolTable);
    print_symtab();
    cout<<"\ndone print symtab\n";

    // for(int i=0;i<prog.size();i++) {
    //     cout<<prog[i]<<endl;
    // }
    print_tac(tac);
    cout<<"\ndone prog\n";
    ifstream tac_file("tac.txt");
    ofstream x86_file("Assembly.s");
    string tac_line;
    string s=".LC0:\n\t";
    s=s+".string  \"%d\\n\"\n\t.text\n\t.globl main\n";
    x86_file<<s;
    s="System.println:\n";
    s=s+"\tpushq	%rbp\n\tmovq	%rsp, %rbp\n\tmovq	16(%rbp), %rsi\n\tleaq	.LC0(%rip), %rdi\n\tmovq	$0, %rax\n\tcall printf@PLT\n\tmovq	$0, %rax\n\tmovq	%rbp, %rsp\n\tpopq	%rbp\n\tret\n";
    x86_file<<s;
    while(getline(tac_file,tac_line)){
        x86_file << convert_tac_to_x86(tac_line);
    }
    tac_file.close();
    x86_file.close();
    return 0;
}


int yyerror(const char*msg) {
	cout<<"ERROR in: "<<yylineno<<'\n';
    if(verb==1)
    cout<<msg<<'\n';
    exit(0);
    // return 0;
};
