%{
	#include<stdio.h>
	#include<stdlib.h>
%}

COMMENT_SINGLE "~".*"\n"
COMMENT_MULTI "~~"(.|"\n")*"~~"
ZERO "0"
NEG_NUM \-[1-9][0-9]*
POS_NUM [1-9][0-9]*
PLUS "+"
MINUS "-"
MULT "*"
DIV "\/"
L_PAREN "("
R_PAREN ")"
L_BRACK "["
R_BRACK "]"
L_CURL "{"
R_CURL "}"
EQUAL "is"
IF "if"
ELSE "else"
BEGIN_ARRAY (([a-zA-Z_])([0-9]|[a-zA-Z_-])*)\[
BEGIN_FUNCTION (([a-zA-Z_])([0-9]|[a-zA-Z_-])*)\(
INTEGER "int"
CONSOLE_IN "in"
IN_ARROW ">>"
CONSOLE_OUT "out"
OUT_ARROW "<<"
STOP "stop"
LESS "<"
LE "<="
GREATER ">"
GE ">="
NOT_EQ "!="
IDENTIFIER ([a-zA-Z_])([0-9]|[a-zA-Z_-])*
END_STATEMENT "\."



/* Regex for indenififyig Array: (\w+)\[\d+\](\s)*\=(\s)*\{((\d*)|(\d*\,\d*))*\} */
/* Example tester: Identifier[3] = {3,4}  */

/* Rule Section: */
%%
{COMMENT_SINGLE} {printf("Comment_Single\n");} 
{COMMENT_MULTI} {printf("Comment_Multi ");} 
{ZERO} {printf("Zero ");} 
{NEG_NUM} {printf("Negative_Number ");} 
{POS_NUM} {printf("Positive_Number ");} 
{PLUS}  {printf("Plus ");}
{MINUS} {printf("Minus ");}
{MULT}  {printf("Multiplication ");}
{DIV}   {printf("Divide ");}
{L_PAREN} {printf("Left_Parentheses ");}
{R_PAREN} {printf("Right_parentheses ");}
{L_BRACK} {printf("Left_Bracket ");} 
{R_BRACK} {printf("Right_Bracket ");} 
{L_CURL} {printf("Left_curly ");} 
{R_CURL} {printf("Right_curly ");} 
{EQUAL} {printf("Equal ");}
{IF} {printf("If ");}
{ELSE} {printf("Else ");}
{BEGIN_ARRAY} {printf("Begin_Array ");}
{BEGIN_FUNCTION} {printf("Begin_function ");}
{INTEGER} {printf("Integer ");}
{CONSOLE_IN} {printf("Console_In ");} 
{IN_ARROW} {printf("Input_Arrow ");} 
{CONSOLE_OUT} {printf("Console_Out ");} 
{OUT_ARROW} {printf("Output_Arrow ");} 
{STOP} {printf("Stop ");}  
{LESS} {printf("Less_than ");} 
{LE} {printf("Less_or_Equal ");} 
{GREATER} {printf("Greater ");} 
{GE} {printf("Greater_or_Equal ");} 
{NOT_EQ} {printf("Not_Equal ");} 
{IDENTIFIER} {printf("Identifier ");} 
{END_STATEMENT} {printf("End_statement ");} 
"\n" {printf("\n ");}
%%


int yywrap(void) {return 1;}

int main( int argc, char **argv )
{
    ++argv, --argc;  /* skip over program name */

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