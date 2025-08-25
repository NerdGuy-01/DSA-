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
