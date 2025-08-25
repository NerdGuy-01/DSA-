/*
Problem Statement: Given a matrix if an element in the matrix is 0 then you will have to set its entire column and row to 0 and then return the matrix. We have to mark entire col and row as zero

Brute force : 
We will use two nested Loops to traverse all the cells of matrix if any element (i,j) contains value 0 we will mark call cells in rows i and column j with -1 except. 
We are using this approach considering array does not contain any negative element. If we mark all the row and  col as zero then when it will again look for zero it will change row and col of others again zero which will be wrong.

Time Complexity: O((N*M)*(N + M)) + O(N*M), where N = no. of rows in the matrix and M = no. of columns in the matrix.
Space Complexity: O(1) as we are not using any extra space.


Better :  
We are iterating over whole array but we only need one 0 in any row and col, so we will mark it. 

Time Complexity: O(2*(N*M)), where N = no. of rows in the matrix and M = no. of columns in the matrix.
Space Complexity: O(N) + O(M), where N = no. of rows in the matrix and M = no. of columns in the matrix.


Optimal  :
In this approach, we can just improve the space complexity. So, instead of using two extra matrices row and col, we will use the 1st row and 1st column of the given matrix to keep a track of the cells that need to be marked with 0. But here comes a problem. If we try to use the 1st row and 1st column to serve the purpose, the cell matrix[0][0] is taken twice. To solve this problem we will take an extra variable col0 initialized with 1. Now the entire 1st row of the matrix will serve the purpose of the row array. And the 1st column from (0,1) to (0,m-1) with the col0 variable will serve the purpose of the col array.
*/


// Brute 
void markRow(vector<vector<int>> &matrix,int n ,int m, int i ){
    for (int j = 0; j < n; j++)
    {
        if (matrix[i][j]!=0)
        {
            matrix[i][j] = -1;
        }
        
    }
    
}

void markCol(vector<vector<int>>&matrix,int n,int m , int j ){
    for (int i = 0; i < n; i++)
    {
        if(matrix[i][j]!=0){
            matrix[i][j] = -1;
        }
    }
    
}

vector<vector<int>> ZeroMatrix(vector<vector<int>> &matrix, int n, int m){
    for(int i =0;i<n;i++){
        for(int j =0;j<m;j++){
            if(matrix[i][j]==0){
                markRow(matrix,n,m,i);
                markCol(matrix,n,m,j);
            }
        }
    }
    // Finally, mark all -1 as 0:
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == -1) {
                matrix[i][j] = 0;
            }
        }
    }

    return matrix;
}


// Better 
vector<vector<int>> ZeroMatrix(vector<vector<int>> &matrix, int n, int m){
  int row[n] = {0}; // row array
  int col[m] = {0}; // col array

  // Traverse the Matrix
  for(int i =0;i<n;i++){
     for(int j =0;j<m;j++){
        if(matrix[i][j]==0){
            row[i] = 1; // mark ith index of row wih 1:
            col[j] = 1;  // mark jth index of col wih 1:
        }
     }
  }

    // Finally, mark all (i, j) as 0
    // if row[i] or col[j] is marked with 1.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (row[i] || col[j]) {
                matrix[i][j] = 0;
            }
        }
    }
    return matrix;
}


// Optimal 
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
         int col0 = 1; 
         int n = matrix.size();
        int m = matrix[0].size();


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0; 
                if (j != 0) {
                    matrix[0][j] = 0; 
                } else {
                    col0 = 0; 
                }
            }
        }
    }


    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }

   
    if (matrix[0][0] == 0) {
        for (int j = 0; j < m; j++) {
            matrix[0][j] = 0;
        }
    }

  
    if (col0 == 0) {
        for (int i = 0; i < n; i++) {
            matrix[i][0] = 0;
        }
    }
    }
};
