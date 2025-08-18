/*
Problem Statement: Given an array that contains only 1 and 0 return the count of maximum consecutive ones in the array.

Time Complexity: O(N) since the solution involves only a single pass.

Space Complexity: O(1) because no extra space is used.
*/

void count_Maximum(vector<int>&nums){
 int n = nums.size();
 int count = 0;
 int maxcount = 0;
  for(int i =0;i<n;i++){
    if(nums[i]==1){
    count++;
    } else{
      count = 0;
    }
    maxcount = max(count,maxcount);
  }

  cout << maxcount ;

}
