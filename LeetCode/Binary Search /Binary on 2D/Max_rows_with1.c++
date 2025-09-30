/*
Problem Statement: You have been given a non-empty grid ‘mat’ with 'n' rows and 'm' columns consisting of only 0s and 1s. All the rows are sorted in ascending order.
Your task is to find the index of the row with the maximum number of ones.
Note: If two rows have the same number of ones, consider the one with a smaller index. If there's no row with at least 1 zero, return -1.

Time Complexity: O(n X m), where n = given row number, m = given column number.
Reason: We are using nested loops running for n and m times respectively.

Space Complexity: O(1) as we are not using any extra space.

Optimal : 
We cannot optimize the row traversal but we can optimize the counting of 1’s for each row.
no of ones = m - index of first occurance as whole array is sorted 
Time Complexity: O(n X logm), where n = given row number, m = given column number.
Reason: We are using a loop running for n times to traverse the rows. Then we are applying binary search on each row with m columns.

Space Complexity: O(1) as we are not using any extra space.
*/

// brute 
int RowWithMax1(int n, int m , vector<vector<int>>&matrix){
    int  count_max =0;
    int index = -1;
    for(int i =0;i<=n;i++){
      int  count_ones = 0;
        for(int j =0;j<=m;j++){
           count_ones+= matrix[i][j]; // as whole array contain only 0 and 1 
        }
        if(count_ones>count_max){
            count_max = count_ones;
            index  = i;
        }
    }
    return index;
}

// optimal 
int lowerBound(vector<int> arr, int n, int x) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] >= x) {
            ans = mid;
            //look for smaller index on the left
            high = mid - 1;
        }
        else {
            low = mid + 1; // look on the right
        }
    }
    return ans;
}

int RowWithMax1(int n, int m , vector<vector<int>>&matrix){
    int  count_max =0;
    int index = -1;
    for(int i =0;i<=n;i++){
      int  count_ones = m-lowerBound(matrix[i],m,1);
       
        if(count_ones>count_max){
            count_max = count_ones;
            index  = i;
        }
    }
    return index;
}
