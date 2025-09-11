/*
Problem Statement: Given an integer array arr of size N, sorted in ascending order (with distinct values) and a target value k. Now the array is rotated at some pivot point unknown to you. Find the index at which k is present and if k is not present return -1.

Brute force : Using linear Search 
Time Complexity: O(N), N = size of the given array.
Reason: We have to iterate through the entire array to check if the target is present in the array.

Space Complexity: O(1)
Reason: We have not used any extra data structures, this makes space complexity, even in the worst case as O(1).

Optimal :
We can't use simple binary Search as after rotation numbers have replaced their position
Time Complexity: O(logN), N = size of the given array.
Reason: We are using binary search to search the target.

Space Complexity: O(1)
Reason: We have not used any extra data structures, this makes space complexity, even in the worst case as O(1).
*/

// Optimal 
int search(vector<int>&nums,int target){
   int n = nums.size();
  int low = 0;
  int high = n-1;
  while(low<=high){
    int mid = low + (high-low)/2;
    if(nums[mid]==target) return mid;
    // Left part is sorted
    if(nums[low]<nums[mid]){
        if(nums[low]<=target && target<=nums[mid]){
          // element exits 
          high = mid-1;
        } else {
          low = mid+1;
        }
    }  else {
      // right half is sorted
      if(nums[mid]<=target && target <=nums[high]){
        low = mid+1;
      } else {
        high = mid-1;
      }
    }
  } 
  return -1;

}
