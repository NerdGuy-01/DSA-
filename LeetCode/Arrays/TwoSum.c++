/*
Problem Statement: Given an array of integers arr[] and an integer target.

1st variant: Return YES if there exist two numbers such that their sum is equal to the target. Otherwise, return NO.

2nd variant: Return indices of the two numbers such that their sum is equal to the target. Otherwise, we will return {-1, -1}.

Idea we can do this too  return {"Yes", {i, j}}; but then we have to make it pair<string, vector<int>>


// Brute (think by me)
check both elements but in Striver its maintained to be two functions 
T.C : O(N^2)
S.C: O(1);
*/


// Brute 
pair<string, vector<int>> two_Sum(vector<int>& nums, int target) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i] + nums[j] == target) {
                return {"Yes", {i, j}};
            }
        }
    }
    return {"No", {-1, -1}};
}
