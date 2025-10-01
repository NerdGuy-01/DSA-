/*
Problem Statement: Given a 0-indexed n x m matrix mat where no two adjacent cells are equal, find any peak element mat[i][j] and return the array [i, j]. A peak element in a 2D grid is an element that is strictly greater than all of its adjacent neighbours to the left, right, top, and bottom.
Assume that the entire matrix is surrounded by an outer perimeter with the value -1 in each cell.

Note: As there can be many peak values, 1 is given as output if the returned index is a peak number, otherwise 0

Brute :
Iterating every element and checking at 4 positions 
T.C : O(n*m*4)

Best :
Intitution : That we  learn the graph in 1D peak element 
First we find maximum element in colum 
[Input Matrix]
      |
      v
[findPeakGrid]
      |
      v
[Binary Search on Columns]
      |
      v
[maxElement finds max in current column]
      |
      v
[Check if max is a peak]
      |         \
      |          \
   Yes: Return   No: Move left/right in columns
      |
      v
[Output Peak Position]
*/

// Solution 
 int maxElement(vector<vector<int>>& arr, int col) {
          int n = arr.size();
          int max_val = INT_MIN;
          int index = -1;
  
          // Iterate through each row to find the maximum element 
          // in the particular column
          for (int i = 0; i < n; i++) {
              if (arr[i][col] > max_val) {
                  max_val = arr[i][col];
                  index = i;
              }
          }
          return index;
      }
  
      // Function to find a peak element in the 2D matrix 
      // using binary search
      vector<int> findPeakGrid(vector<vector<int>>& arr) {
          int n = arr.size();     
          int m = arr[0].size();  
  
          // Initialize the lower and upper bounds for binary search
          int low = 0;           
          int high = m - 1;      
  
          // Perform binary search on columns
          while (low <= high) {
              int mid = (low + high) / 2;
  
              // Find the index of the row with the maximum element 
              // in the middle column
              int row = maxElement(arr, mid);
  
              // Determine the elements to the left and right of 
              // the middle element in the found row
              int left = mid - 1 >= 0 ? arr[row][mid - 1] : INT_MIN;
              int right = mid + 1 < m ? arr[row][mid + 1] : INT_MIN;
  
              // Check if the middle element is greater than its neighbors
              if (arr[row][mid] > left && arr[row][mid] > right) {
                  return {row, mid};
              } 
              else if (left > arr[row][mid]) {
                  high = mid - 1;
              } 
              else {
                  low = mid + 1;
              }
          }
  
          // Return {-1, -1} if no peak element is found
          return {-1, -1};
      }
