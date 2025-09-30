/*
Problem Statement: You have been given a 2-D array 'mat' of size 'N x M' where 'N' and 'M' denote the number of rows and columns, respectively. The elements of each row are sorted in non-decreasing order. Moreover, the first element of a row is greater than the last element of the previous row (if it exists). You are given an integer ‘target’, and your task is to find if it exists in the given 'mat' or not.

Brute : Using two loops
Time Complexity: O(N X M), where N = given row number, M = given column number.
Reason: In order to traverse the matrix, we are using nested loops running for n and m times respectively.

Space Complexity: O(1) as we are not using any extra space.

Better :
Using binary search 
Time Complexity: O(N + logM), where N = given row number, M = given column number.
Reason: We are traversing all rows and it takes O(N) time complexity. But for all rows, we are not applying binary search rather we are only applying it once for a particular row. That is why the time complexity is O(N + logM) instead of O(N*logM).

Space Complexity: O(1) as we are not using any extra space.

Optimal :
Hypothetically if we try to flatten the array into 1D and then apply BS and find it 
Time Complexity: O(log(NxM)), where N = given row number, M = given column number.
Reason: We are applying binary search on the imaginary 1D array of size NxM.

Space Complexity: O(1) as we are not using any extra space.

*/

// brute 
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

         for(int i =0;i<n;i++){
        for(int j = 0;j<=m;j++){
            if(matrix[i][j]==target) return true;
        }
    }
    return false;
    }
};

// better 
bool binarySearch(vector<int>arr,int x){
    int n = arr.size();
    int low = 0; int high = n-1;
    while(low<=high){
        int mid  = (low+high)/2;
        if(mid==x) return true;
        else if(x >mid) low = mid+1;
        else high = mid-1;
    }
 return false;
}

bool findel(vector<vector<int>>&matrix,int n, int m,int target ){
    for(int i =0;i<n;i++){
       if(matrix[i][0]<=target && target <=matrix[i][m-1]){
       return binarySearch(matrix[i],target);
       }
    }
    return false;
}

// Optimal 
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
         int n = matrix.size();
    int m = matrix[0].size();
      int low = 0, high = n * m - 1;

      // apply binary search
      
    while (low <= high) {
        int mid = (low + high) / 2;
        int row = mid / m, col = mid % m; // formula learn it 
        if (matrix[row][col] == target) return true;
        else if (matrix[row][col] < target) low = mid + 1;
        else high = mid - 1;
    }
    return false;
    }
};
