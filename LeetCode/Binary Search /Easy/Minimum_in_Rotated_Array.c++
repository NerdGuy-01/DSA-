/*
Problem Statement: Given an integer array arr of size N, sorted in ascending order (with distinct values). Now the array is rotated between 1 to N times which is unknown. Find the minimum element in the array. 

Brute :
Linear Search 

Better :
Binary Search : First we check whose array is sorted and we can say that our answer will lie in unsorted array (but not always)
So heres the approach  we first find lefmost(smallest) in sorted half and then check in other half then update it 
Time Complexity: O(logN), N = size of the given array.
Reason: We are basically using binary search to find the minimum.

Space Complexity: O(1)
Reason: We have not used any extra data structures, this makes space complexity, even in the worst case as O(1).


Optimal : 
if the searh space is already sorted then nums[low] will always be smaller in that search space 
*/

// Better 
class Solution {
public:
    int findMin(vector<int>& nums) {
          int n = nums.size();
  int low = 0;
  int high = n-1;
  int result = INT_MAX;
  while(low<=high){
    int mid  =low +(high-low)/2;
    if(nums[low]<=nums[mid]){
      result = min(result,nums[low]);
    low = mid+1;
      
    } else {
      result = min(result,nums[mid]);
       high = mid-1;
    }
  }
 return result;
    }
};

// Optimal 
class Solution {
public:
    int findMin(vector<int>& nums) {
          int n = nums.size();
  int low = 0;
  int high = n-1;
  int result = INT_MAX;
  while(low<=high){
    int mid  =low +(high-low)/2;

    if(nums[low] <=nums[high]){
      result = min(result,nums[low]);
      break;
    }
    if(nums[low]<=nums[mid]){
      result = min(result,nums[low]);
    low = mid+1;
      
    } else {
      result = min(result,nums[mid]);
       high = mid-1;
    }
  }
 return result;
    }
};
