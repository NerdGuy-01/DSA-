/*
Problem Statement: Given an array of length N. Peak element is defined as the element greater than both of its neighbors. Formally, if 'arr[i]' is the peak element, 'arr[i - 1]' < 'arr[i]' and 'arr[i + 1]' < 'arr[i]'. Find the index(0-based) of a peak element in the array. If there are multiple peak numbers, return the index of any peak number.

Note: For the first element, the previous element should be considered as negative infinity as well as for the last element, the next element should be considered as negative infinity.


My code 
int peakElement(vector<int>&nums){
  int n = nums.size();
  int first = INT_MIN;
  for(int i =0;i<n;i++){
 
   if(nums[0]>nums[1] && nums[first]<nums[0]){
    return 0;
   }
   if(nums[n-1]>nums[n-2] && nums[first]<nums[n-1]){
    return (n-1);
   }
    if(nums[i-1]<nums[i]&&nums[i]>nums[i+1]){
     return i;
    }
  }
  return -1;
}


Brute : Linear Search 
Time Complexity: O(N), N = size of the given array.
Reason: We are traversing the entire array.

Space Complexity: O(1) as we are not using any extra space.

Optimal :
In finding peak element we can say that it follows some sorting order like a graph 
if the mid is in increasing curve then the peak will be on right side and if the mid is in decresing curve then the peak will be on left side
Time Complexity: O(logN), N = size of the given array.
Reason: We are basically using binary search to find the minimum.

Space Complexity: O(1)
Reason: We have not used any extra data structures, this makes space complexity, even in the worst case as O(1).
*/

// Brute 
int peakElement(vector<int>&nums){
  int n = nums.size();

  // check for first element
  if (nums[0] > nums[1]) return 0;

   // Check last element
   if (nums[n-1] > nums[n-2]) return n-1;
   
  for(int i =0;i<n;i++){
    if(nums[i-1]<nums[i]&&nums[i]>nums[i+1]){
     return i;
    }
  }
  return -1;
}

// Optimal 
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
         int n = nums.size();
  // Edge cases 
   if(n==1) return 0;
   if(nums[0]>nums[1]) return 0;
   if(nums[n-1]>nums[n-2]) return n-1;
   int low = 1;
   int high = n-2;
   while(low<=high){
     int mid = low+ (high-low)/2;
     if(nums[mid-1]<nums[mid] && nums[mid]>nums[mid+1]){
      return mid;
     }
     // if we are on left 
     if(nums[mid]>nums[mid-1]) low = mid+1;
     // if we on right
     else high = mid-1;
   }
   return -1;
    }
};
