//Algorithm for the Efficient Solution
// 1. Create an Empty Stack, st.
// 2. Create an Empty String, prefix
// 3. Do Following for every character C from right to left.
// 4. If C is: 
     // a) Operand: Push it to prefix
     // b) Right Parenthesis : Push to st
     // c) Left Parenthesis : Pop from st until right parenthesis is found. Append the popped character to prefix.
     // d) Operator : If st is Empty, push C to st.
                   // Else compare with the st top.

          //i) Higher Precedence (than st top): Push C to st.
          //ii) Lower Precedence: Pop st top and append the popped item to prefix until a higher precedence operator is found (or st becomes empty). Push C to st.
          //iii) Equal Precedence : Use Associativity


// 5. Pop Everything from st and append to prefix.
// 6. Return reverse of prefix.
                  