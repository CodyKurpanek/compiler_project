// definitions section 
%{
	//#include "HashTable.h"
	#include<stdio.h>
	#include<stdlib.h>
	#include <string.h>
	#include <stdbool.h>
	extern FILE *yyin;
	extern int yylex();
    extern int yyparse();
	extern int line;
	int yyerror(char * s);
	int scope; // use later
	struct CodeNode 
	{
		char code[1000];
		char name[20];
	};
	struct symbol {
		char *name;
		char *type;
		int scope;
	};
	#define NHASH 9997
	struct symbol symtab[NHASH];

	void lookup(char* sym, char* type);
	void lookup2(char* sym, char* type);
	void lookup3(char* sym, char* type);

	//variable
	int scopeCount = 1; // This is for cases where we have multiple if and loop statemnetst inside a fucntion or main 
	int label = 0;
	int scope = 0;
	int exp1_cnt = 0;
	bool error = false;
	bool has_main = false;
	char *allCode; 
%}


// bridge between flex and bison
%union
{

	char *id;	
	char *keyWord;
	char sym;
	int num;
	struct CodeNode* cn;

}
%token INTEGER IDENTIFIER END_STATEMENT COMMENT_SINGLE FUNC RETURN
%token ZERO NEG_NUM POS_NUM 
%token MULT DIV PLUS MINUS LESS EQ GREATER  NOT_EQ LESS_EQ GREATER_EQ MOD
%token L_PAREN R_PAREN L_BRACK R_BRACK L_CURL R_CURL
%token EQUAL IF ELSE COMMA BEGIN_PHASE DO
%token BEGIN_FUNCTION   
%token OUT_ARROW IN_ARROW STOP  CONSOLE_IN CONSOLE_OUT NEW_LINE

%type<id> BEGIN_FUNCTION
%type<id> IDENTIFIER 
%type<num> NEG_NUM
%type<num> POS_NUM
%type<num> ZERO
%type<cn>  fcodeseg
%type<cn>  statement
%type<cn>  number
%type<cn> condition_op 
%type<cn> choice 
%type<cn> option 
%type<cn> operation 
%type<cn> condition 
%type<cn> codeseg 
%type<cn> array
%type<cn> Function_Call
%type<cn> else
%type<cn> if_statement
%type<cn> loop
%type<cn> Expression
%type<cn> Parameter
%type<cn> Function
// Added return for Function Related Statements
%type<cn> RETURN
// Added Mod for Arithmetic Operator Statements

//  Rules section  
%%
start : fcodeseg
{
	if(!has_main)
	{
		yyerror("No main");
		error = true;
	}
	
	if(!error)
		allCode = $1->code;
	
	
}


fcodeseg  : fcodeseg statement END_STATEMENT 
			{
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
				strcpy(new->code, "");
				strcpy(new->name, "");
				strcat(new->code, $1->code);
				strcat(new->code, $2->code);

				$$ = new;
			}

	      | fcodeseg loop 
		  {
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
				strcpy(new->code, "");
				strcpy(new->name, "");
				strcat(new->code, $1->code);
				strcat(new->code, $2->code);

				$$ = new;
		  }
		  | fcodeseg if_statement 
		  {
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
				strcpy(new->code, "");
				strcpy(new->name, "");
				strcat(new->code, $1->code);
				strcat(new->code, $2->code);

				$$ = new;
		  }
          | fcodeseg Function
		  {
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
				strcpy(new->code, "");
				strcpy(new->name, "");
				strcat(new->code, $1->code);
				strcat(new->code, $2->code);

				$$ = new;
		  }
		  | fcodeseg RETURN number END_STATEMENT
		  {
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
				strcpy(new->code, "");
				strcpy(new->name, "");
				printf("Error on line %d: invalid spot for return.\n", line);
				error = true;


				$$ = new;
		  }
		  | fcodeseg RETURN option operation option 
		  {
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
				strcpy(new->code, "");
				strcpy(new->name, "");
				printf("Error on line %d: invalid spot for return.\n", line);
				error = true;

				
				$$=new;
		  } 
		  | fcodeseg RETURN IDENTIFIER
		  {
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
				strcpy(new->code, "");
				strcpy(new->name, "");
				printf("Error on line %d: invalid spot for return.\n", line);
				error = true;

				$$ = new;
		  }
          | %empty
			{
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
				strcpy(new->code, "");
				strcpy(new->name, "");

				$$ = new;
			}
          
		  ;

codeseg   : codeseg statement END_STATEMENT 
			{
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
				strcpy(new->code, "");
				strcpy(new->name, "");
				strcat(new->code, $1->code);
				strcat(new->code, $2->code);

				$$ = new;
		   }
          | codeseg loop 
		  {
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
				strcpy(new->code, "");
				strcpy(new->name, "");
				strcat(new->code, $1->code);
				strcat(new->code, $2->code);

				$$ = new;
		   }
		   | codeseg if_statement 
		  {
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
				strcpy(new->code, "");
				strcpy(new->name, "");
				strcat(new->code, $1->code);
				strcat(new->code, $2->code);
				
				$$ = new;
		  }
          | codeseg Expression 
		  {
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
				strcpy(new->code, "");
				strcpy(new->name, "");
				strcat(new->code, $1->code);
				strcat(new->code, $2->code);

				$$ = new;
		   }
		  | codeseg Function_Call END_STATEMENT// this is for calling a 
		  {
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
				strcpy(new->code, "");
				strcpy(new->name, "");
				strcat(new->code, $1->code);
				strcat(new->code, $2->code);

				$$ = new;
		  }
		  |%empty
		  {
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
				strcpy(new->code, "");
				strcpy(new->name, "");
				$$ = new;
		  }
;



statement  : 
           array 
		   {
				struct CodeNode *new = malloc(sizeof(struct CodeNode));
				strcpy(new->code, "");
				strcpy(new->name, "");
				strcat(new->code, $1->code);

				$$ = new;
		   }
           | INTEGER IDENTIFIER  
			{
				char *temp = $2;
				lookup(temp, "INTEGER");
				//create new empty CodeNode
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
				strcpy(new->code, "");
				strcpy(new->name, "");

				//. id  (declare)
				strcat(new->code, ". ");
				strcat(new->code, $2);
				strcat(new->code, "\n");

				$$=new;
			}	
		   | IDENTIFIER EQUAL Expression 
			{
				char *temp = $1;
				lookup2(temp, "INTEGER");
				lookup3(temp, "INTEGER");
				//create new empty CodeNode
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
				strcpy(new->code, "");
				strcpy(new->name, "");
				strcat(new->code, $3->code);
				strcat(new->code, "= ");
				strcat(new->code, $1);
				strcat(new->code, ", ");
				strcat(new->code, $3->name);
				

				strcat(new->code, "\n");

				$$=new;
			}
			| INTEGER IDENTIFIER EQUAL Expression 
			{
				char *temp = $2;
				lookup(temp, "INTEGER");
				lookup3(temp, "INTEGER");
				//create new empty CodeNode
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
				strcpy(new->code, "");
				strcpy(new->name, "");

				//. id  (declare)
				strcat(new->code, $4->code);
				strcat(new->code, ". ");
				strcat(new->code, $2);
				strcat(new->code, "\n");


				strcat(new->code, "= ");
				strcat(new->code, $2);
				strcat(new->code, ", ");
				strcat(new->code, $4->name);
				
				strcat(new->code, "\n");
				
				$$=new;				
			}
		   | CONSOLE_OUT OUT_ARROW IDENTIFIER // Output an identifier 
		   {
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
				strcpy(new->code, "");
				strcpy(new->name, "");
				strcat(new->code, ".> ");
				strcat(new->code, $3);
				strcat(new->code, "\n");
				
				$$ = new;

		   }
		   | CONSOLE_OUT OUT_ARROW IDENTIFIER L_BRACK POS_NUM R_BRACK  // This is used to print out location inside of an array
		   {
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
				strcpy(new->code, "");
				strcpy(new->name, "");
				strcat(new->code, ".[]> ");
				strcat(new->code, $3);
				strcat(new->code, ", ");
				char temp[100];  
				int value = $5;
                sprintf(temp, "%d", value); 
				strcat(new->code, temp);
				strcat(new->code, "\n");

				$$ = new;
		   }
		   | CONSOLE_OUT OUT_ARROW IDENTIFIER L_BRACK ZERO R_BRACK  // This is used to print out location inside of an array
		   {
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
				strcpy(new->code, "");
				strcpy(new->name, "");
				strcat(new->code, ".[]> ");
				strcat(new->code, $3);
				strcat(new->code, ", ");
				char temp[100];  
				int value = $5;
                sprintf(temp, "%d", value); 
				strcat(new->code, temp);
				strcat(new->code, "\n");

				$$ = new;
		   }
		   | CONSOLE_IN IN_ARROW IDENTIFIER // grab input and store inside given identifier 
		   {
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
				strcpy(new->code, "");
				strcpy(new->name, "");
				strcat(new->code, ".< ");
				strcat(new->code, $3);
				strcat(new->code, "\n");

				$$ = new;
		   }
		   | CONSOLE_IN IN_ARROW IDENTIFIER L_BRACK POS_NUM R_BRACK // grab input and store at specificed array index
		   {
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
				strcpy(new->code, "");
				strcpy(new->name, "");
				strcat(new->code, ".[]< ");
				strcat(new->code, $3);
				strcat(new->code, ", ");
				char temp[100];  
				int value = $5;
                sprintf(temp, "%d", value); 
				strcat(new->code, temp);
				strcat(new->code, "\n");

				$$ = new;
		   }
		   | IDENTIFIER EQUAL IDENTIFIER
		   {
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
				strcpy(new->code, "");
				strcpy(new->name, "");
				strcat(new->code, "= ");
				strcat(new->code, $1);
				strcat(new->code, ", ");
				strcat(new->code, $3);

				$$ = new;

		   }
		   | RETURN Expression
		  {
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
				strcpy(new->code, "");
				strcpy(new->name, "");

				strcat(new->code, $2->code);
				strcat(new->code, "ret ");
				strcat(new->code, $2->name);
				strcat(new->code, "\n");
				
				$$=new;
		  } 
		   | STOP {printf("statment -> STOP\n");}
           ;

number     : POS_NUM 
			{
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
				strcpy(new->code, "");
				strcpy(new->name, "");
				sprintf(new->code, "%i", $1);

				$$=new;
			}
		   | NEG_NUM 
		   {
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
				strcpy(new->code, "");
				strcpy(new->name, "");
				sprintf(new->code, "%i", $1);

				$$=new;
			}
		   | ZERO 
		   {
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
				strcpy(new->code, "");
				strcpy(new->name, "");
				sprintf(new->code, "%i", $1);

				$$=new;
			}
;

array      : INTEGER IDENTIFIER L_BRACK POS_NUM R_BRACK 
			{
				char *temp = $2;
				lookup(temp, "ARRAY");
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
                strcpy(new->code, "");
                strcpy(new->name, "");
                strcat(new->code, ".[] ");
                strcat(new->code, $2);
                strcat(new->code, ", ");
                char temp1[100];  
				int value = $4;
                sprintf(temp1, "%d", value); 
                strcat(new->code, temp1);
                strcat(new->code, "\n");

                $$ = new;
			}
		   | INTEGER IDENTIFIER L_BRACK NEG_NUM R_BRACK 
			{
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
                strcpy(new->code, "");
                strcpy(new->name, "");
				printf("Error on line %d: invalid array size.\n", line);
				error = true;
                
                $$ = new;
			}
		   | INTEGER IDENTIFIER L_BRACK ZERO R_BRACK 
			{
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
                strcpy(new->code, "");
                strcpy(new->name, "");
				printf("Error on line %d: invalid array size.\n", line);
				error = true;
                
                $$ = new;
			}
			| IDENTIFIER EQUAL IDENTIFIER L_BRACK IDENTIFIER R_BRACK
		   {
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
                strcpy(new->code, "");
                strcpy(new->name, "");
				strcat(new->code, "=[] ");
				strcat(new->code, $1);
				strcat(new->code, ", ");
				strcat(new->code, $3);
				strcat(new->code, ", ");
				strcat(new->code, $5);
				strcat(new->code, "\n");
				

				$$ = new;
		   }
		   | IDENTIFIER EQUAL IDENTIFIER L_BRACK POS_NUM R_BRACK
		   {
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
                strcpy(new->code, "");
                strcpy(new->name, "");
				strcat(new->code, "=[] ");
				strcat(new->code, $1);
				strcat(new->code, ", ");
				strcat(new->code, $3);
				strcat(new->code, ", ");
				char temp[100];  
				int value = $5;
                sprintf(temp, "%d", value); 
                strcat(new->code, temp);
				strcat(new->code, "\n");

				$$ = new;
		   }
		   | IDENTIFIER L_BRACK POS_NUM R_BRACK EQUAL choice
		   {
			    char *temp = $1;
				lookup2(temp, "ARRAY");
				lookup3(temp, "ARRAY");
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
                strcpy(new->code, "");
                strcpy(new->name, "");
				strcat(new->code, "[]= ");
				strcat(new->code, $1);
				strcat(new->code, ", ");
				char temp1[100];  
				int value = $3;
                sprintf(temp1, "%d", value); 
				strcat(new->code, temp1);
				strcat(new->code, ", ");
				strcat(new->code, $6->code);
				strcat(new->code, "\n");

				$$ = new;
		   }
		   | IDENTIFIER L_BRACK IDENTIFIER R_BRACK EQUAL choice
		   {
			    char *temp = $1;
				lookup2(temp, "ARRAY");
				lookup3(temp, "ARRAY");
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
                strcpy(new->code, "");
                strcpy(new->name, "");
				strcat(new->code, "[]= ");
				strcat(new->code, $1);
				strcat(new->code, ", ");
				strcat(new->code, $3);
				strcat(new->code, ", ");
				strcat(new->code, $6->code);
				strcat(new->code, "\n");

				$$ = new;
		   }
		   | IDENTIFIER EQUAL IDENTIFIER L_BRACK ZERO R_BRACK
		   {
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
                strcpy(new->code, "");
                strcpy(new->name, "");
				strcat(new->code, "=[] ");
				strcat(new->code, $1);
				strcat(new->code, ", ");
				strcat(new->code, $3);
				strcat(new->code, ", ");
				char temp[100];  
				int value = $5;
                sprintf(temp, "%d", value); 
                strcat(new->code, temp);
				strcat(new->code, "\n");

				$$ = new;
		   }
		   | IDENTIFIER L_BRACK ZERO R_BRACK EQUAL choice
		   {
			    char *temp = $1;
				lookup2(temp, "ARRAY");
				lookup3(temp, "ARRAY");
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
                strcpy(new->code, "");
                strcpy(new->name, "");
				strcat(new->code, "[]= ");
				strcat(new->code, $1);
				strcat(new->code, ", ");
				char temp1[100];  
				int value = $3;
                sprintf(temp1, "%d", value); 
				strcat(new->code, temp1);
				strcat(new->code, ", ");
				strcat(new->code, $6->code);
				strcat(new->code, "\n");

				$$ = new;
		   }
		   ;

Function      : FUNC IDENTIFIER L_PAREN Parameter R_PAREN L_CURL codeseg R_CURL
				{	
					char *temp = $2;
					lookup(temp, "FUNCTION");
					if(strcmp($2, "main") == 0)
					{
						has_main = true;
					}
					struct CodeNode* new = malloc(sizeof(struct CodeNode));
					strcpy(new->code, "");
					strcpy(new->name, "");
					strcat(new->code, "func ");
					strcat(new->code, $2);
					strcat(new->code, "\n");
					strcat(new->code, $4->code);
					strcat(new->code, $7->code);
					strcat(new->code, "endfunc\n");

					$$=new;

				}
			  ;

// previously the CFG below was --> INTEGER Parameter COMMA INTEGER IDENTIFIER

// func MyFunction(int a, int b)

// INT ID COMMA INT ID  
Parameter     : Parameter COMMA INTEGER IDENTIFIER
				{
					struct CodeNode* new = malloc(sizeof(struct CodeNode));
					strcpy(new->code, "");
					strcpy(new->name, "");
					strcat(new->code, $1->code);
					strcat(new->code, ". ");
					strcat(new->code, $4);
					strcat(new->code, "\n");

					$$ = new;
				}
              | INTEGER IDENTIFIER 
				{
					struct CodeNode* new = malloc(sizeof(struct CodeNode));
					strcpy(new->code, "");
					strcpy(new->name, "");
					strcat(new->code, ". ");
					strcat(new->code, $2);
					strcat(new->code, "\n");
					strcat(new->code, "= ");
					strcat(new->code, $2);
					strcat(new->code, ", ");
					strcat(new->code, "$");
					strcat(new->code, "0");
					strcat(new->code, "\n");

					


					$$ = new;
				}
			  | IDENTIFIER
			  {
					struct CodeNode* new = malloc(sizeof(struct CodeNode));
					strcpy(new->code, "");
					strcpy(new->name, "");
					strcat(new->code, "param ");
					strcat(new->code, $1);
					strcat(new->code, "\n");


					$$ = new;
			  }
			  | Parameter COMMA IDENTIFIER
			  {
					struct CodeNode* new = malloc(sizeof(struct CodeNode));
					strcpy(new->code, "");
					strcpy(new->name, "");
					strcat(new->code, $1->code);
					strcat(new->code, "param ");
					strcat(new->code, $3);
					strcat(new->code, "\n");
					$$ = new;
			  }
			  | %empty
			    {
					struct CodeNode* new = malloc(sizeof(struct CodeNode));
					strcpy(new->code, "");
					strcpy(new->name, "");

					
					$$ = new;
				}
              ;
// ------------------------------------------------------------------------------------
// THIS WILL BE USED FOR LOOP CONDITIONS
condition     : choice condition_op choice 
				{
					char varname[10];
					sprintf(varname, "tmp_exp%i", exp1_cnt); // we create new temp 
					struct CodeNode* new = malloc(sizeof(struct CodeNode));
					strcpy(new->code, "");
					strcpy(new->name, varname);
					strcat(new->code, ". ");
					strcat(new->code, varname);
					strcat(new->code, "\n");
					strcat(new->code, $2->code);
					strcat(new->code, " ");
					strcat(new->code, varname);
					strcat(new->code, ", ");
					strcat(new->code, $1->code);
					strcat(new->code, ", ");
					strcat(new->code, $3->code);
					strcat(new->code, "\n");

					exp1_cnt += 1;
					$$ = new;
				}
			  ;	

choice  	  : IDENTIFIER 
				{
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
				strcpy(new->code, "");
				strcpy(new->name, "");
				sprintf(new->code, "%s", $1);

				$$=new;
				}
			  | POS_NUM 
			  {
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
				strcpy(new->code, "");
				strcpy(new->name, "");
				sprintf(new->code, "%i", $1);

				$$=new;
				}
			  | NEG_NUM 
			  {
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
				strcpy(new->code, "");
				strcpy(new->name, "");
				sprintf(new->code, "%i", $1);

				$$=new;
				}
			  | ZERO 
			  {
				//create new empty CodeNode
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
				strcpy(new->code, "");
				strcpy(new->name, "");
				sprintf(new->code, "%i", $1);

				$$=new;
				}
			  ;



condition_op  : LESS 
				{
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
				strcpy(new->code, "<");
				strcpy(new->name, "");

				$$=new;
				}
			  | GREATER 
			  {
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
				strcpy(new->code, ">");
				strcpy(new->name, "");

				$$=new;
			  }
			  | EQ 
			  {
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
				strcpy(new->code, "==");
				strcpy(new->name, "");

				$$=new;
			  }
			  | NOT_EQ 
			  {
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
				strcpy(new->code, "!=");
				strcpy(new->name, "");

				$$=new;
			  }
			  
			  | GREATER_EQ 
			  {
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
				strcpy(new->code, ">=");
				strcpy(new->name, "");

				$$=new;
			  }
			  | LESS_EQ 
			  {
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
				strcpy(new->code, "<=");
				strcpy(new->name, "");

				$$=new;
			  }
			  ;
// ------------------------------------------------------------------------------------
Expression    : option operation option 
				{
					
					//create new empty CodeNode
					struct CodeNode* new = malloc(sizeof(struct CodeNode));
					strcpy(new->code, "");
					strcpy(new->name, "");

					//.tmp_exp1
					//operation tmp_exp1, value, value
					char varname[10];
					sprintf(varname, "tmp_exp%i", exp1_cnt);
					strcat(new->code, $1->code);
					strcat(new->code, $3->code);
					strcat(new->code, ". ");
					strcat(new->code, varname);
					strcat(new->code, "\n");
					strcat(new->code, $2->code);
					strcat(new->code, varname);
					strcat(new->code, ", ");
					strcat(new->code, $1->name);
					strcat(new->code, ", ");
					strcat(new->code, $3->name);
					strcat(new->code, "\n");
					strcat(new->name, varname);

					exp1_cnt++;
					$$=new;
				}
				// --------------------------------------------------------------------------------------------------> Removed this becuase it was causing ambiguity in our langauge 
		      | IDENTIFIER 
			  {
					struct CodeNode* new = malloc(sizeof(struct CodeNode));
					strcpy(new->code, "");
					strcpy(new->name, "");
					strcat(new->name, $1);

					$$ = new;
			  } 
			  | number 
			  {
					struct CodeNode* new = malloc(sizeof(struct CodeNode));
					strcpy(new->code, "");
					strcpy(new->name, "");
					strcat(new->name, $1->code);
					$$ = new;
			  }
			  | Function_Call 
			  {
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
				strcpy(new->code, "");
				strcpy(new->name, "");
				strcpy(new->code, $1->code);
				strcpy(new->name, $1->name);
				$$=new;
				}
			  ;	

option  	  : IDENTIFIER 
				{
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
				strcpy(new->code, "");
				strcpy(new->name, "");
				sprintf(new->name, "%s", $1);

				$$=new;
				}
			  | POS_NUM 
			  {
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
				strcpy(new->code, "");
				strcpy(new->name, "");
				sprintf(new->name, "%i", $1);

				$$=new;
			  }
			  | Function_Call 
			  {
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
				strcpy(new->code, "");
				strcpy(new->name, "");
				strcpy(new->code, $1->code);
				strcpy(new->name, $1->name);
				$$=new;
				}
			  ;	
			  | NEG_NUM 
			  {
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
				strcpy(new->code, "");
				strcpy(new->name, "");
				sprintf(new->code, "%i", $1);

				$$=new;
				}
			  | ZERO 
			  {
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
				strcpy(new->code, "");
				strcpy(new->name, "");
				sprintf(new->code, "%i", $1);

				$$=new;
				}
			  ;



operation     : PLUS 
				{
				//create new empty CodeNode
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
				strcpy(new->code, "+ ");
				strcpy(new->name, "");
				
				$$=new;
			  }
			  | MINUS 
			  {
				//create new empty CodeNode
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
				strcpy(new->code, "- ");
				strcpy(new->name, "");
				
				$$=new;
			  }
			  | MULT 
			  {
				//create new empty CodeNode
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
				strcpy(new->code, "* ");
				strcpy(new->name, "");
				
				$$=new;
			  }
			  | DIV 
			  {
				//create new empty CodeNode
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
				strcpy(new->code, "/ ");
				strcpy(new->name, "");
				
				$$=new;
			  }
			  | MOD
			  {
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
				strcpy(new->code, "% ");
				strcpy(new->name, "");
				
				$$=new;
			  }
			  ;


// ------------------------------------------------------------------------------------

// BEGIN_LOOP includes left Parenthesis 
loop          : BEGIN_PHASE condition R_PAREN L_CURL codeseg R_CURL 
				{
					char labelName1[10];
					sprintf(labelName1, "L%i", label); // Lablel for Begging of Loop
					label += 1;
					char labelName2[10];
					sprintf(labelName2, "L%i", label); // Label for End of Loop
					label += 1;
					struct CodeNode* new = malloc(sizeof(struct CodeNode));
					strcat(new->name, "");
					strcat(new->code, "");

					strcat(new->code, ": "); // we declare Lable 1 
					strcat(new->code, labelName1);
					strcat(new->code, "\n");

					strcat(new->code, $2->code); // negating condition 
					strcat(new->code, "! ");
					strcat(new->code, $2->name);
					strcat(new->code, ", ");
					strcat(new->code, $2->name);
					strcat(new->code, "\n");

					strcat(new->code, "?:= "); // If-Statement
					strcat(new->code, labelName2);
					strcat(new->code, ", ");
					strcat(new->code, $2->name);
					strcat(new->code, "\n");
					strcat(new->code, $5->code);
					strcat(new->code, ":= ");
					strcat(new->code, labelName1);
					strcat(new->code, "\n");

					strcat(new->code, ": "); // we declare Lable 2
					strcat(new->code, labelName2);
					strcat(new->code, "\n");

					$$ = new;
				}
			  ;

Function_Call : IDENTIFIER L_PAREN Parameter R_PAREN 
				{
					// char *temp = $1;
					// lookup2(temp, "FUNCTION");
					char varname[10];
					sprintf(varname, "tmp_exp%i", exp1_cnt);
					struct CodeNode* new = malloc(sizeof(struct CodeNode));
					strcpy(new->code, "");
					strcpy(new->name, "");
					strcat(new->code, ". ");
					strcat(new->code, varname);
					strcat(new->code, "\n");
					strcat(new->code, $3->code); // this will do the assembly code for the values in
					strcat(new->code, "call ");
					strcat(new->code, $1);
					strcat(new->code, ", ");
					strcat(new->code, varname);
					strcat(new->code, "\n");
					strcat(new->name, varname);

					exp1_cnt++;
					$$ = new;
					
				}
			  ;


if_statement  : IF condition R_PAREN  L_CURL codeseg R_CURL else
				{	
					char labelName[10];
					char elseLabel[10];
					char endLabel[10];
					sprintf(labelName, "L%i", label); // Created new Lable
					label += 1;
					sprintf(elseLabel, "L%i", label);
					label += 1;
					sprintf(endLabel, "L%i", label);
					label += 1;
					scope += scopeCount;
					struct CodeNode* new = malloc(sizeof(struct CodeNode));
					strcpy(new->code, "");
					strcpy(new->name, "");
					strcat(new->code, $2->code);
				
					strcat(new->code, "?:= ");
					strcat(new->code, labelName);
					strcat(new->code, ", ");
					strcat(new->code, $2->name);
					strcat(new->code, "\n");
					strcat(new->code, ":= ");
					strcat(new->code, elseLabel);
					strcat(new->code, "\n");
					strcat(new->code, ": ");
					strcat(new->code, labelName);
					strcat(new->code, "\n");
					strcat(new->code, $5->code);
					strcat(new->code, ":= ");
					strcat(new->code, endLabel);
					strcat(new->code, "\n");
					strcat(new->code, ": ");
					strcat(new->code, elseLabel);
					strcat(new->code, "\n");
					strcat(new->code, $7->code);
					strcat(new->code, ": ");
					strcat(new->code, endLabel);
					strcat(new->code, "\n");


					// we are assuming there is a newline after codeseg
					scope -= scopeCount;
					scopeCount += 1;
					$$ = new;
				}     
			  ;

else          : ELSE L_CURL codeseg R_CURL 
			   {
					scope += scopeCount;
					struct CodeNode* new = malloc(sizeof(struct CodeNode));
					strcpy(new->code, "");
					strcpy(new->name, "");
					strcat(new->code, $3->code);
					scope -= scopeCount;
					scopeCount += 1;
					
					$$ = new;
			   }
			  | %empty
			  {
				struct CodeNode* new = malloc(sizeof(struct CodeNode));
				strcpy(new->code, "");
				strcpy(new->name, "");

				$$ = new;
			  }
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

	FILE *fptr;  // create file pointer 
	fptr = fopen("mil_code.mil","w"); // we point to file mil_code 
	fputs(allCode,fptr);
	free(allCode);
	fclose(fptr);

	return 0;
} 

static unsigned symhash(char* sym){
	unsigned int hash = 0;
	unsigned c;

	while(c = *sym++) hash = hash*9 ^ c;

	return hash;
}

void lookup(char* sym, char* type){//for declaring multiple times
	struct symbol *sp = &symtab[symhash(sym)%NHASH];
	int scount = NHASH;
	while(--scount >= 0){
		if((sp->name && !strcmp(sp->name, sym)) && sp->scope == scope){//if symbol exists 
			printf("Error on line %d: symbol exists.\n", line);//bad, redeclaring it
			error = true;
			return;
		}
		if(!sp->name){
			sp->name = strdup(sym);
			sp->scope = scope;
			sp->type = strdup(type);
			return;
		}
	}
}

void lookup2(char* sym, char* type){// to set variable, the variable must already be declared
	struct symbol *sp = &symtab[symhash(sym)%NHASH];
	int scount = NHASH;
	while(--scount >= 0){
		if((sp->name && !strcmp(sp->name, sym)) && sp->scope == scope){ //if symbol exists
			//good. set the value
			return;
		}
		if(!sp->name){//otherwise
			//bad; trying to add value to undeclared variable
			printf("Error on line %d: variable not defined.\n", line);
			error = true;
			return;
		}
	}
}

void lookup3(char* sym, char* type){// for modifying wrong type
	struct symbol *sp = &symtab[symhash(sym)%NHASH];
	int scount = NHASH;
	while(--scount >= 0){
		//if symbol exists, and right type
		if((sp->name && !strcmp(sp->name, sym)) && sp->scope == scope && strcmp(sp->type, type) == 0){
			//good. return
			return;
		}
		//now, if it does exist, it must be the wrong type. Throw error.
		else if(sp->name){
			printf("Error on line %d: Modifying wrong variable type.\n", line);
			error = true;
			return;
		}
	}
}


int yyerror(char * s)
{
	printf("ERROR: %s\n", s);
	return 0;
}


