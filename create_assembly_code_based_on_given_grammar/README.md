Video Demo: <br />

    https://youtu.be/YIIxy1bI8to


1. Instructions: Inorder to compile the code do as follows <br />
1a. Be sure you are in the correct directory <br />
1b. Once you are in the correct directory do the following 3 commands In a row: <br />
  
        Command 1: bison -v -d --file-prefix=y Bison.y
        Command 2: flex Lex_analyzer.l
        Command 3: gcc -o parser y.tab.c lex.yy.c
        
    1c. Once all 3 commands run we must run the parser <br />
    1d. Now inorder to run the parser, we must choose a file to run the parser on <br />
    1e. All the test cases are going to be inside the folder "phase3_code" <br />
    1f. phase3_code error handleing test casees are in the "errors folder " <br />
    1g. phase3_code cases where there are no errorss is in the "errors folder " <br />
    1h. Example of how to run on one of the error test cases <br />
  
      Command: ./parser phase3_code/errors/return_outside_function.ez 
      
  1i. Example of how to run on one of the working test cases <br />
     
     Command: ./parser phase3_code/no_errors/1variable_declaration.ez


To run the MIL Code do as follows below  <br />

        Command: ./mil_run mil_code.mil

2. Language Features:

   Feature 1: Declare and Assign integers and Arrays
   <br />

       func main(){
           int x.
           x is 5.
           int y is 7.

           int myArr[5].
            myArr[0] is x.
        }

   Feature 2: Creating If and Else Statment  
    <br />
    
            func main()
           {
                int x.
                x is 5.
                if(x == 5)
                {
                  x is 7.
                }
                else 
                {
                  x is 3.
                }
           }
   
   Feature 3: Phase Loop 
     <br />
    
          func main()
           {
                int x is 0.
                phase(x != 7)
                {
                    x is x + 1.
                }
           }
  
  Feature 4: Arrays 
     <br />
    
          func main()
           {
                int x[5].
                x[3] is 1.
           }
   
   Feature 5: Console Out 
    <br />
    
           func main()
           {
              int x is 10. 
              out << x. 
              
              int myArr[3].
              myArr[2] is 56.
              
              out << myArr[2].
             
           }
   Feature 6: Console In 
    <br />
    
           func main()
           {
              int x. 
              in >> x. 
              
              int myArr[6].
              in >> myArr[3]. 
           }
  
     
   Feature 7: Arithmetic Operations 
     <br />
    
          func main()
           {
              int x = 9.
              int z = 3. 
              int result.
              
              result is x + z.
              result is x - z.
              result is x * z. 
              result is x / z. 
              result is x % z.
              result is x + 2.
              result is 3 - z.
              result is x * 5. 
              result is 9 / z. 
              result is 2 % z. 
           }
        
          
   Feature 8: Logical Operations  
     <br />
    
            func main()
           {
              int x is 9.
              int y.
              int z.
              int d. 
              int f. 
              int g.
              int h.
              if (x == 9){
                in >> y.
              }
              
              if(x != 9){
                in >> z.
              }
              
              if (x > 9){
                in >> d.
              }
              
              if(x < 9){
                in >> f.
              }
              
              if (x >= 9){
                in >> g.
              }
              
              if(x <= 9){
                in >> h.
              }
              
           }
   
   Feature 9: Array Access Statement 
     <br />
    
          Func main()
          {
              int myArr[10].
              myArr[5] is 3.
              
              int temp is  myArr[5]
              
              myArr[0] is temp.
          }
      
      
      
   Feature 10: Functions
     <br />
    
    func inc(int x){
        return x + 1.
        }

    func main(){
        int a.
        in >> a.
        int b is inc(a).
        out << b.
    }
   

   
