/* 
Q :Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

A : my Approach  in my previous problom of duplicates i used in this, for ex the question says to not return duplicate so I do this and then I compare both the values like numi  should not be equal to j and  k cause if they do their sums will not be 0 int

my code :  which is totally wrong ❎
int three_sum(vector<int>&nums){
 unordered_set<int>mpp;;
 for(auto it: nums){
   if(mpp.count(it)>0) return 0 ;
   else mpp.insert(it);
 }
 for(int i =0;i<nums.size();i++){
   for(int j =i+1;j<nums.size()-1;j++){
      for(int k = i+2;k<nums.size()-2;j++){
         if(nums[i]==nums[j] && nums[j]==nums[k]) continue;
         if(nums[i]+nums[j]+nums[k]==0){
         }
          return i,j,k;
      }
   }
 }
 
}

Real Answer : Striver Solution
   Brute force
   first let i start form zero and j after that and k afer that so then store in it, and to get unique elements after storing them sort them and then compare with other triplets
*/
