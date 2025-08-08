/* 
 Q : Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

 my code :
 I try to use 3 sum 
 class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> result;
   sort(nums.begin(),nums.end());
   for(int  a = 0;a<nums.size();a++){
    int b = a+1;
    int c = b+1;
    int d = nums.size()-1;
    while(b<d){
        int sum  = nums[a]+nums[b]+nums[c]+nums[d];
        if(sum<target){
            b++;
        }
        else if(sum>target){
            d--;
        }
        else{
            vector<int> temp  = {nums[a]+nums[b]+nums[c]+nums[d]};
            result.push_back(temp);
            b++;
            d--;
        }
    }
    return result;
   }    
    }
};



Brute force ->  We declare a set because we want unique quadruplets
T.C :  O(n4)
S.C. : O(number of quadrants)*2

Better -> we can write last element as target-(nums[a)+nums[b]+nums[c])
everything between b and c will be put in hash set in order to get unique elements 
T.C: O(n3) * log(n);
S.C: O(n) + O(number of quadrants)*2


*/

// Brute force 
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>> result;
       for(int a =0;a<n;a++){
        for(int b = a+1;b<n;b++){
            for(int c = b+1;c<n;c++){
                for(int d = c+1;d<n;d++){
                    long long sum = nums[a]+nums[b];
                    sum+= nums[c];
                    sum+=nums[d];
                    if(sum==target){
                        vector<int> temp = {nums[a],nums[b],nums[c],nums[d]};
                        sort(temp.begin(),temp.end());
                        result.insert(temp);
                    }
                }
            }
        }
       }
        vector<vector<int>>ans(result.begin(),result.end());
        return ans;
    }
};

// Better 
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>> result;
       for(int a =0;a<n;a++){
        for(int b = a+1;b<n;b++){
            set<long long> hash;
            
            for(int c = b+1;c<n;c++){
                long long sum = nums[a]+nums[b];
                sum+= nums[c];
               long long d = target -(sum); 
                if(hash.find(d)!=hash.end()){ // is in between b and c 
                vector<int> temp  = {nums[a],nums[b],nums[c],int(d)};
                sort(temp.begin(),temp.end());
                result.insert(temp);
                }

               hash.insert(nums[c]);
            }
        }
       }
        vector<vector<int>>ans(result.begin(),result.end());
        return ans;
    }
};

// Optimal 
