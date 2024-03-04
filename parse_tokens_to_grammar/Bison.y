
// definitions section 
%{
	#include<stdio.h>
	#include<stdlib.h>
	#include <string.h>
	extern FILE *yyin;
	extern int yylex();
    extern int yyparse();
	int yyerror(char * s);
%}

// bridge between flex and bison
%union
{
	char *id;	
	char *keyWord;
	char sym;
	int num;
}

%token INTEGER IDENTIFIER END_STATEMENT COMMENT_SINGLE
%token ZERO NEG_NUM POS_NUM 
%token MULT DIV PLUS MINUS LESS EQ GREATER  NOT_EQ LESS_EQ GREATER_EQ
%token L_PAREN R_PAREN L_BRACK R_BRACK L_CURL R_CURL
%token EQUAL IF ELSE COMMA BEGIN_PHASE DO
%token BEGIN_FUNCTION   
%token OUT_ARROW IN_ARROW STOP  CONSOLE_IN CONSOLE_OUT NEW_LINE

%type<id> IDENTIFIER 

%type<num> NEG_NUM
%type<num> POS_NUM
%type<num> ZERO

//  Rules section  
%%
fcodeseg  : fcodeseg statement END_STATEMENT {printf("fcodeseg -> fcodeseg statement END_STATEMENT\n");}
	      | fcodeseg loop {printf("fcodeseg -> fcodeseg loop\n");}
		  | fcodeseg if_statement {printf("fcodeseg -> fcodeseg if_statement\n");}
          | fcodeseg Function_Call {printf("fcodeseg -> fcodeseg Function_Call\n");}
          | %empty
          ;

codeseg   : codeseg statement END_STATEMENT {printf("codeseg -> codeseg statement END_STATEMEN\n");}
          | codeseg loop {printf("codeseg -> codeseg loop\n");}
          | codeseg Expression {printf("codeseg -> codeseg condition\n");}
          | %empty
;

statement  : INTEGER IDENTIFIER EQUAL number {printf("statment -> INTEGER IDENTIFIER EQUAL number\n");}
           | array {printf("statment -> array\n");}
           | INTEGER  IDENTIFIER  {printf("statement -> INTEGER  IDENTIFIER\n");}
		   | IDENTIFIER EQUAL Expression {printf("statement -> IDENTIFIER EQUAL Expression\n");}
		   | CONSOLE_OUT OUT_ARROW Expression {printf("statement ->  CONSOLE_OUT OUT_ARROW Expression\n");}
		   | STOP {printf("statment -> STOP\n");}
		   //{printf("%s\n", $2);}
           ;

number     : POS_NUM {printf("number -> POS_NUM\n");}
		   | NEG_NUM {printf("number -> NEG_NUM\n");}
		   | ZERO {printf("number -> ZERO\n");}
;

array      : IDENTIFIER L_BRACK POS_NUM R_BRACK {printf("array -> IDENTIFIER L_BRACK POS_NUM R_BRACK\n");}
		   | IDENTIFIER {printf("array -> IDENTIFIER\n");}
		   | IDENTIFIER L_BRACK POS_NUM R_BRACK EQUAL L_CURL fill R_CURL {printf("array -> IDENTIFIER L_BRACK POS_NUM R_BRACK EQUAL L_CURL fill R_CURL\n");}
		   ;

fill       : fill COMMA POS_NUM {printf("fill -> fill COMMA POS_NUM\n");}
		   | fill COMMA NEG_NUM {printf("fill -> fill COMMA NEG_NUM\n");}
		   | fill COMMA ZERO {printf("fill -> fill COMMA ZERO\n");}
		   | single_choice {printf("fill -> single_choice\n");}
		   ;

single_choice : POS_NUM {printf("single_choice -> POS_NUM");}
			  | NEG_NUM {printf("single_choice -> NEG_NUM");}
   		      | ZERO {printf("single_choice -> ZERO");}
		      ;

Function      : BEGIN_FUNCTION Parameter R_PAREN L_CURL codeseg R_CURL {printf("Function -> BEGIN_FUNCTION Parameter R_PAREN L_CURL codeseg R_CURL\n");}
			  ;

Parameter     : INTEGER Parameter COMMA INTEGER IDENTIFIER {printf("Parameter -> INTEGER Parameter COMMA INTEGER IDENTIFIER\n");}
              | INTEGER IDENTIFIER {printf("Parameter -> INTEGER IDENTIFIER\n");}
              | %empty
              ;
// ------------------------------------------------------------------------------------
// THIS WILL BE USED FOR LOOP CONDITIONS
condition     : choice condition_op choice {printf("condition -> choice_1 condition_op choice_2\n");}
		      | IDENTIFIER {printf("condition -> IDENTIFIER\n");} 
			  | number {printf("condition -> number\n");}
			  ;	

choice  	  : IDENTIFIER {printf("choice -> IDENTIFIER\n");}
			  | POS_NUM {printf("choice -> POS_NUM\n");}
			  | NEG_NUM {printf("choice -> NEG_NUM\n");}
			  | ZERO {printf("choice -> ZERO\n");}
			  ;



condition_op  : LESS {printf("condition_op -> LESS\n");}
			  | GREATER {printf("condition_op -> GREATER\n");}
			  | EQ {printf("condition_op -> EQ\n");}
			  | NOT_EQ {printf("condition_op -> NOT_EQ\n");}
			  | PLUS {printf("condition_op -> PLUS\n");}
			  | MINUS {printf("condition_op -> MINUS\n");}
			  | MULT {printf("condition_op -> MULT\n");}
			  | DIV {printf("condition_op -> DIV\n");}
			  | GREATER_EQ {printf("condition_op -> GREATER_EQ\n");}
			  | LESS_EQ {printf("condition_op -> LESS_EQ\n");}
			  ;
// ------------------------------------------------------------------------------------
Expression    : option operation option {printf("Expression -> choice_1 condition_op choice_2\n");}
		      | IDENTIFIER {printf("Expression -> IDENTIFIER\n");} 
			  | number {printf("Expression -> number\n");}
			  ;	

option  	  : IDENTIFIER {printf("option -> IDENTIFIER\n");}
			  | POS_NUM {printf("option -> POS_NUM\n");}
			  | NEG_NUM {printf("option -> NEG_NUM\n");}
			  | ZERO {printf("option -> ZERO\n");}
			  ;



operation     : PLUS {printf("operation -> PLUS\n");}
			  | MINUS {printf("operation -> MINUS\n");}
			  | MULT {printf("operation -> MULT\n");}
			  | DIV {printf("operation -> DIV\n");}
			  ;

// ------------------------------------------------------------------------------------

// BEGIN_LOOP includes left Parenthesis 
loop          : BEGIN_PHASE condition R_PAREN L_CURL codeseg R_CURL {printf("loop -> BEGIN_PHASE condition R_PAREN L_CURL codeseg R_CUR\n");}
			  | DO L_CURL codeseg R_CURL BEGIN_PHASE condition R_PAREN {printf("loop -> DO codeseg R_CURL BEGIN_PHASE condition R_PAREN\n");}
			  ;

Function_Call : BEGIN_FUNCTION Parameter Parameter_Call R_PAREN END_STATEMENT {printf("Function_Call -> BEGIN_FUNCTION Parameter Parameter_Call R_PAREN END_STATEMENT\n");}
			  ;

Parameter_Call: Parameter_Call COMMA IDENTIFIER {printf("Parameter_Call -> Parameter_Call COMMA IDENTIFIER\n");}
		 	  | IDENTIFIER {printf("Parameter_Call -> IDENTIFIER\n");}
			  | Parameter_Call COMMA number {printf("Parameter_Call -> Parameter_Call COMMA number\n");}
			  | number {printf("Parameter_Call -> number\n");}
			  | %empty
			  ;
// ------------------------------------------------------------------------------------
if_statement  : IF condition R_PAREN L_CURL codeseg R_CURL else {printf("if_statement -> IF condition R_PAREN L_CURL codeseg R_CURL else\n");}      
			  ;

else          : ELSE codeseg R_CURL {printf("else -> ELSE L_CURL codeseg R_CURL\n");}
			  | %empty
              ;
      
%%


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