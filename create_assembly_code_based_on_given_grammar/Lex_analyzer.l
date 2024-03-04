/*IDENTIFIER ([a-zA-Z_])([0-9]|[a-zA-Z_-])* */


/* This is our Flex File */

%{
	#include<stdio.h>
   #include<string.h>
   #include "y.tab.h" 
   int line = 1;
   int count = 0;
   char *prev;

%}
FUNC "func"
RETURN "return"
COMMENT_SINGLE "~"(.*)\n
ZERO "0"
NEG_NUM \-[1-9][0-9]*
POS_NUM [1-9][0-9]*
PLUS "+"
MINUS "-"
MULT "*"
DIV "\/"
MOD "%"
LESS "<"
LESS_EQ "<="
GREATER ">"
GREATER_EQ ">="
NOT_EQ "!="
EQ "=="
L_PAREN "("
R_PAREN ")"
L_BRACK "["
R_BRACK "]"
L_CURL "{"
R_CURL "}"
EQUAL "is"
IF "if("
ELSE "else"
DO "do" 
BEGIN_PHASE "phase("
INTEGER "int"
CONSOLE_IN "in"
IN_ARROW ">>"
CONSOLE_OUT "out"
OUT_ARROW "<<"
STOP "stop"
IDENTIFIER ([a-zA-Z])([0-9]|[a-zA-Z_-])*
END_STATEMENT "\."
COMMA ","




/* Regex for indenififyig Array: (\w+)\[\d+\](\s)*\=(\s)*\{((\d*)|(\d*\,\d*))*\} */
/* Example tester: Identifier[3] = {3,4}  */

/* Rule Section: */
%option noyywrap
%%
[\n] {char newline = '\n'; if(prev == &newline){count +=1;}else{line += 1; line += count;}}
{COMMENT_SINGLE} {prev = yytext; return(COMMENT_SINGLE);} 
{RETURN} {prev = yytext; return(RETURN);} 
{ZERO} {yylval.num = atoi(yytext); prev = yytext; return(ZERO);}
{NEG_NUM} {yylval.num = atoi(yytext); prev = yytext; return(NEG_NUM);}
{POS_NUM} {yylval.num = atoi(yytext); prev = yytext; return(POS_NUM);}
{PLUS} {prev = yytext; return(PLUS);}
{MINUS} {prev = yytext; return(MINUS);}
{MULT} {prev = yytext; return(MULT);}
{DIV} {prev = yytext; return(DIV);}
{MOD} {prev = yytext; return(MOD);}
{LESS} {prev = yytext; return(LESS);}
{LESS_EQ} {prev = yytext; return(LESS_EQ);}
{GREATER} {prev = yytext; return(GREATER);}
{GREATER_EQ} {prev = yytext; return(GREATER_EQ);}
{NOT_EQ} {prev = yytext; return(NOT_EQ);}
{EQ} {prev = yytext; return(EQ);}
{L_PAREN} {prev = yytext; return(L_PAREN);}
{R_PAREN} {prev = yytext; return(R_PAREN);}
{L_BRACK} {prev = yytext; return(L_BRACK);}
{R_BRACK} {prev = yytext; return(R_BRACK);}
{L_CURL} {prev = yytext; return(L_CURL);}
{R_CURL} {prev = yytext; return(R_CURL);}
{EQUAL} {prev = yytext; return(EQUAL);}
{IF} {prev = yytext; return(IF);}
{ELSE} {prev = yytext; return(ELSE);}
{DO} {prev = yytext; return(DO);}
{BEGIN_PHASE} {prev = yytext; return(BEGIN_PHASE);}
{FUNC} {prev =  yytext; return(FUNC);}
{INTEGER} {prev = yytext; return(INTEGER);}
{CONSOLE_IN} {prev = yytext; return(CONSOLE_IN);}
{IN_ARROW} {prev = yytext; return(IN_ARROW);}
{CONSOLE_OUT} {prev = yytext; return(CONSOLE_OUT);}
{OUT_ARROW} {prev = yytext; return(OUT_ARROW);}
{STOP} {prev = yytext; return(STOP);}
{IDENTIFIER} {char *temp =strdup(yytext); yylval.id = temp; prev = yytext; return(IDENTIFIER);}
{END_STATEMENT} {prev = yytext; return(END_STATEMENT);}
{COMMA} {prev = yytext; return(COMMA);}
[\t]+
%%

