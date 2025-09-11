/*
Problem Statement: You are given a sorted array containing N integers and a number X, you have to find the occurrences of X in the given array.


  My code :  
  int CountOccurance(vector<int>&nums,int target){
  int n = nums.size();
  int low =0;
  int high = n-1;
  int count =0;
  while(low<=high){
    int mid = low + (high-low)/2;
    if(nums[mid]==target) {
      count++;
      low = mid+1;
    }
     else if(target>nums[mid]) low = mid+1;
    else high = mid-1;
  }

  return count;
}


Brute : Just search for whole array
Time Complexity: O(N), N = size of the given array
Reason: We are traversing the whole array.

Space Complexity: O(1) as we are not using any extra space.

Optimal :
Total Number of occurance = last Occurance - first Occurance +1;
Time Complexity: O(2*logN), where N = size of the given array.
Reason: We are basically using the binary search algorithm twice.

Space Complexity: O(1) as we are using no extra space

*/


// Optimal 
int firstOccurance(vector<int>&nums,int target){
  
 int n = nums.size();
 int low =0; int high = n-1;
 int first  =-1;
 while(low<=high){
  int mid  = low + (high-low)/2;
   if(nums[mid]==target){
    first = mid;
    high = mid-1; // Look on left side
   } else if(nums[mid]<target) low = mid+1;
   else high = mid-1;
 }
 return first;
}

int lastOccurance(vector<int>&nums,int target){
  int  n = nums.size();
  int low = 0; int high = n-1;
  int last =-1;
  while(low<=high){
    int mid  = low + (high-low)/2;
    if(nums[mid]==target){
      last = mid;
      low = mid+1;// look on right Side
    } else if(nums[mid]<target) low = mid+1;
    else high = mid-1;
  }
  return last;
}

pair<int,int>LastAndFirstOccurance(vector<int>&nums,int target){
  int first = firstOccurance(nums,target);
  if(first ==-1) return {-1,-1};
  int last = lastOccurance(nums,target);
  return {first,last};
}

int count(vector<int>&nums,int target){
  pair<int,int>ans = LastAndFirstOccurance(nums,target);
  if(ans.first==-1) return 0;
  return (ans.second - ans.first +1);
}
