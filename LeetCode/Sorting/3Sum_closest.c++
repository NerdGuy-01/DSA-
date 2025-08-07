/*
Q : Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.

Return the sum of the three integers.

You may assume that each input would have exactly one solution.

My code : 
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
      set<int> store;
      int i = nums[0];
      int j = i+1;
      int k = nums.size()-1;
      while(k>=0){
       int sum = nums[i]+nums[j]+nums[k];
       if(sum ==target){
        store.insert(sum);
        k--;
       }
        else{
            i++;
            j++;
        }
       }
    
      }
      return (int)(store[0]);
    }
};

But Thought Process -> it ask for sum only so no indexes sort and use Two pointer


Approach -1 : Fix i and j and keep k moving then keep j moving then i 
T.C :  O(n3) triple loops
*/
