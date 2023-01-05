//1. Create an Empty stack st
//2. Traverse through every symbol x of given postfix.
     //1.) If x is an Operand, push to st.
     //2.) Else (x is an Operator)
         //i) op1 = st.pop();
         //ii) op2 = st.pop();
         //iii) Compute op2 x op1 and push the result to st
     
     //3.) Return st.top()
     
