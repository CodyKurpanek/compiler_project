/*IDENTIFIER ([a-zA-Z_])([0-9]|[a-zA-Z_-])* */


/* This is our Flex File */

%{
	#include<stdio.h>
   #include<string.h>
   #include "y.tab.h" 
   /* 
   #include "y.tab.h"
   Line above is how lexical analysis is going to know about the tokens
   
    */
%}

COMMENT_SINGLE "~"(.*)\n
ZERO "0"
NEG_NUM \-[1-9][0-9]*
POS_NUM [1-9][0-9]*
PLUS "+"
MINUS "-"
MULT "*"
DIV "\/"
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
ELSE "else{"
DO "do" 
BEGIN_PHASE "phase("
BEGIN_FUNCTION (([a-zA-Z_])([0-9]|[a-zA-Z_-])*)\(
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
{COMMENT_SINGLE} {return(COMMENT_SINGLE);} 
{ZERO} {yylval.num = atoi(yytext); return(ZERO);}
{NEG_NUM} {yylval.num = atoi(yytext); return(NEG_NUM);}
{POS_NUM} {yylval.num = atoi(yytext); return(POS_NUM);}
{PLUS} {return(PLUS);}
{MINUS} {return(MINUS);}
{MULT} {return(MULT);}
{DIV} {return(DIV);}
{LESS} {return(LESS);}
{LESS_EQ} {return(LESS_EQ);}
{GREATER} {return(GREATER);}
{GREATER_EQ} {return(GREATER_EQ);}
{NOT_EQ} {return(NOT_EQ);}
{EQ} {return(EQ);}
{L_PAREN} {return(L_PAREN);}
{R_PAREN} {return(R_PAREN);}
{L_BRACK} {return(L_BRACK);}
{R_BRACK} {return(R_BRACK);}
{L_CURL} {return(L_CURL);}
{R_CURL} {return(R_CURL);}
{EQUAL} {return(EQUAL);}
{IF} {return(IF);}
{ELSE} {return(ELSE);}
{DO} {return(DO);}
{BEGIN_PHASE} {return(BEGIN_PHASE);}
{BEGIN_FUNCTION} {return(BEGIN_FUNCTION);}
{INTEGER} {return(INTEGER);}
{CONSOLE_IN} {return(CONSOLE_IN);}
{IN_ARROW} {return(IN_ARROW);}
{CONSOLE_OUT} {return(CONSOLE_OUT);}
{OUT_ARROW} {return(OUT_ARROW);}
{STOP} {return(STOP);}
{IDENTIFIER} {yylval.id = yytext; return(IDENTIFIER);}
{END_STATEMENT} {return(END_STATEMENT);}
{COMMA} {return(COMMA);}
[\t\n]+ 
%%


//int yywrap(void) {return 1;}

/*
int main( int argc, char **argv )
{
    ++argv, --argc;  

    const char* file = argv[0];
    printf("opening %s and printing contents:\n", file);
    printf("-----------------------------------\n");

    FILE *fp;
    int c;
    int n = 0;
  
    fp = fopen(file, "r");
    if(fp == NULL) {
       perror("Error in opening file");
       return(-1);
    } do {
       c = fgetc(fp); 
       if( feof(fp) ) {
          break ;
       }
       printf("%c", c); 
    } while(1);
    printf("\n");

    fclose(fp);
    printf("\n-----------------------------------\n");

   printf("tokenizing:\n");
   printf("-----------------------------------\n");
   yyin = fopen(file, "r");
   // yyin = stdin;
    yylex();
    printf("\n-----------------------------------\n");
}

*/