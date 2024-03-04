to run:
gcc y.tab.c lex.yy.c -o parser
./parser ez_code/(code to tokenize and parse)




How to read the output:
Take for example the first three lines of arithmeticOperators.ez:
int x.
int y.
x is 4 + 4.

After running ./parser ez_code/arithmeticOperators.ez, the beginning of the output implements this:  (These following 10 lines implement the 3 lines above)
1. statement -> INTEGER  IDENTIFIER
2.fcodeseg -> fcodeseg statement END_STATEMENT
3. statement -> INTEGER  IDENTIFIER
4.fcodeseg -> fcodeseg statement END_STATEMENT
5.   option -> POS_NUM
6.operation -> PLUS
7. option -> POS_NUM
8.Expression -> choice_1 condition_op choice_2
9.statement -> IDENTIFIER EQUAL Expression
10.fcodeseg -> fcodeseg statement END_STATEMENT



The first four lines: 
1. statement -> INTEGER  IDENTIFIER                  this is indented, thus it implements the statement seen in the next line
2.fcodeseg -> fcodeseg statement END_STATEMENT
3. statement -> INTEGER  IDENTIFIER                  this is indented, thus it implements the statement seen in the next line
4.fcodeseg -> fcodeseg statement END_STATEMENT

implement 
int x.
int y.

how?
in terms of the grammar, what happens is:
first 2 lines:
fcodeseg -> fcodeseg INTEGER IDENTIFIER END_STATEMENT
   but you can perceive this in terms of our code as:
   (add more code here) -> (add more code here) int x.

then the next 2 lines just change this new fcodeseg in the same way. So, in the end, we get from all 4 of these lines that
fcodeseg -> fcodeseg INTEGER IDENTIFIER END_STATEMENT -> fcodeseg INTEGER IDENTIFIER END_STATEMENT INTEGER IDENTIFIER END_STATEMENT
   so in terms of our code, this implements (add more code here) int x. int y.




Does it make sense how the next 5 lines:
5.   option -> POS_NUM
6.operation -> PLUS
7. option -> POS_NUM
8.Expression -> choice_1 condition_op choice_2
9.statement -> IDENTIFIER EQUAL Expression
10.fcodeseg -> fcodeseg statement END_STATEMENT

end up changing a single fcodeseg into:
fcodeseg INTEGER EQUAL POS_NUM + POS_NUM     (assuming option implements choice_1, operation implements condition_op, and option implements choice_2?)

