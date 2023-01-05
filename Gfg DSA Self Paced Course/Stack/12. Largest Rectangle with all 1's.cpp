//Naive Approach:
//1. Consider every cell as a starting point.

//2. Consider all sizes of rectangles with current cell as a starting point.

//3. For the Current rectangle, check if it has all 1's. If yes, then update the res if the current size is more.

//Time Complexity: O(R^3 X C^3)





//Efficient Solution : Run a Loop from 0 to R-1
// Then Update the histogram for the current row
//Find the largest area in the histogram and update the result if required.


int maxRectangle(int mat[R][C])   //mat[R][C] is a integer Matrix
{
    int res = largestlist(mat[0], C);
    for(int i=1;i<R; i++)
    {
        for(int j=0; j<C;j++)
        {
            if(mat[i][j] == 1)
              mat[i][j] +=mat[i-1][j];
        }
        res = max(res, largestlist(mat[i],C));
    }
    return res;
}

//Efficient Solution : Theta(R X C)