/*
Problem Statement: Given an array of N integers, count the inversion of the array (using merge-sort).

What is an inversion of an array? Definition: for all i & j < size of array, if i < j then you have to find pair (A[i],A[j]) such that A[j] < A[i].

means (left,right) left element should always be bigger

Brute force : Using Two pointers 
Time Complexity: O(N2), where N = size of the given array.
Space Complexity: O(1) as we are not using any extra space to solve this problem


*/

// brute 
int Inversion(vector<int>&nums){
    int n = nums.size();
    int count = 0;
    for(int i =0;i<n;i++){
        for(int j =i+1;j<n;j++){
            if(nums[i]>nums[j]){
                count++;
            }
        }
    }
  return count;
}
