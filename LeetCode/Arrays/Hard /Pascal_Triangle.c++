/*
Pascal Triangle -> at both start and end are 1 and in middle are their sum 
1 
1 1 
1 2 1 
1 3 3 1 
1 4 6 4 1 

Types of questions 
1. Given row and colums find the element at that place 
2. Print any Nth row of pascal 
3. Given N print entire pascal Triangle 


for 1 answer 
Brute force is print entire pascal triangle and then get element but another way use 
permutation 
do r-1 then c-1 and then do permutation of given 
to find the permutations do this 
*/

int ncr(int n , int r){
    long long res = 1;
    for(int i = 0;i<r;i++){
        res = res*(n-1);
        res = res/(i+1); // to divide like 10/1* 9/2 *8/3 
    }
}
// for use :  element = ncr(n-1,r-1); return element;


// 2 question
class Solution {
public:
    long long ncr(int n, int r) {
        long long res = 1;
        for (int i = 0; i < r; i++) {
            res = res * (n - i);
            res = res / (i + 1);
        }
        return res;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;

        for (int i = 0; i < numRows; i++) {
            vector<int> row;
            for (int j = 0; j <= i; j++) {
                row.push_back(ncr(i, j));
            }
            result.push_back(row);
        }

        return result;
    }
};

/*
Time Complexity: O(n*r), where n is the given row number, and r is the column index which can vary from 0 to n-1.
Reason: We are calculating the element for each column. Now, there are total n columns, and for each column, the calculation of the element takes O(r) time where r is the column index.

Space Complexity: O(1) as we are not using any extra space.
*/

// 3 Question

vector<int>generatePascalTriange(int row){
    long long ans = 1;
    vector<int>ansrow;
    ansrow.push_back(1);
    for(int col = 1;col<row;col++){
        ans = ans*(row-col);
        ans = ans/(col);
        ansrow.push_back(ans);
    }
    return ansrow;
}
// Time Complexity: O(N) where N = given row number. Here we are using only a single loop.

 // Space Complexity: O(1) as we not using any extra space.
