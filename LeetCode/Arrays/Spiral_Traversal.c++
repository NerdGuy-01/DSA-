/*
Problem Statement: Given a Matrix, print the given matrix in spiral order.
This problem doesn't have any optimal or better just one solution 
It goes from right->bottom->left->top

Even if we have only one row then the top will move ++ but the next for loops checks the condition so it will never print that 
Time Complexity: O(m x n) { Since all the elements are being traversed once and there are total n x m elements ( m elements in each row and total n rows) so the time complexity will be O(n x m)}.

Space Complexity: O(n) { Extra Space used for storing traversal in the ans array }
*/


// solution 
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size(); // number of rows
        int left =0; int right = m-1;
        int top = 0; int bottom = n-1;
        vector<int>result;

     while(top<=bottom && left<=right){
        // right
        for(int i = left;i<=right;i++){
            result.push_back(matrix[top][i]);
        }
        top++;
        // top to bottom
        for(int i =  top;i<=bottom;i++){
            result.push_back(matrix[i][right]);
        }
        right--;
        if(top<=bottom){
        // right to left 
        for(int i = right; i>=left;i--){
            result.push_back(matrix[bottom][i]);
        }
        bottom--;
        }

        if(left<=right){ // checks if left still has any elements

        // from bottom to top 
        for(int i = bottom;i>=top;i--){
            result.push_back(matrix[i][left]);
        }
        left++;
        }
    }
    return result;
    }
};
