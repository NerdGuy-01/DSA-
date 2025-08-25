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

Approach -2 : sort the array Fix i and then find sum of i and j two pointer
absolute value(target-sum);

if sum >target j--;
if sum <targete i++;
*/




// Brute force
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int closetSum = INT_MAX;
        int minDifference = INT_MAX;
        for(int i =0;i<n;i++){
            for(int j =  i+1;j<n-1;j++){
                for(int k = j+1;k<n;k++ ){
                    int currentSum = nums[i]+nums[j]+nums[k];
                    int difference = abs(currentSum-target);
                    if(difference<minDifference){
                        minDifference = difference;
                        closetSum = currentSum;
                    }
                }
            }
        }
        return closetSum;
    }
};

// Approach -2
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int clSum = nums[0] + nums[1] + nums[2];
        sort(nums.begin(),nums.end());

        for(int k =0;k<=n-2;k++){
            int i = k+1;
            int j =n-1;
            while(i<j){
                int sum = nums[k] + nums[i]+nums[j];
                if(abs(target-sum)<abs(target-clSum)){
                    clSum = sum;
                }

                if(sum<target) i++;
                 else j--;
            }
        }
        return clSum;
    }
};
