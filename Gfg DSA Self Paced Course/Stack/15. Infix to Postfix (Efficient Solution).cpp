//Infix to Postfix using Stack
//Algorithm

//1. Create an Empty Stack, st
//2. Do Following for every character x from left to right.
//3. If x is:
    // a.) Operand: Output it
    // b.) Left Parenthesis : Push to st
    // c.) Right Parenthesis : pop from st until left parenthesis is found. Output the popped operators.
    // d.) Operator : If st is empty, push x to st. Else compare with st to top.
             // i.) Higher precedence (than st top), push to st.
             // ii.) Lower precedence, pop st top and output until a higher precedence operator is found. Then push s to st.
             // iii.) Equal precedence, use associativity.

//4. pop and output everything from st.
              