/*
Problem Statement: Given an array of length N. Peak element is defined as the element greater than both of its neighbors. Formally, if 'arr[i]' is the peak element, 'arr[i - 1]' < 'arr[i]' and 'arr[i + 1]' < 'arr[i]'. Find the index(0-based) of a peak element in the array. If there are multiple peak numbers, return the index of any peak number.

Note: For the first element, the previous element should be considered as negative infinity as well as for the last element, the next element should be considered as negative infinity.


Brute : Linear Search 
Time Complexity: O(N), N = size of the given array.
Reason: We are traversing the entire array.

Space Complexity: O(1) as we are not using any extra space.

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
