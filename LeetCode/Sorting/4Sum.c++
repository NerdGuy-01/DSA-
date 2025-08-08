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



Optimal -> Get rid of two  hash set and optmizise S.C
1. sort()
2. fix i and j 
3. j will not move that place where i has same value
T.C: O(N3)
S.C :  O(1)

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

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i =0;i<n;i++){
           if(i>0 && nums[i]==nums[i-1]) continue;
           for(int j =i+1;j<n;j++){
            if(j!=i+1 && nums[j]==nums[j-1]) continue;

            int k = j+1;
            int l = n-1;
            while(k<l){
                long long sum = nums[i];
                sum+= nums[j];
                sum+= nums[k];
                sum+= nums[l];
                if(sum==target){
                      vector<int> temp = {nums[i],nums[j],nums[k],nums[l]};
                      result.push_back(temp);
                      k++;
                      l--;
                      while(k<l && nums[k]==nums[k-1]) k++;
                      while(k<l && nums[l]==nums[l+1]) l--;

                }
                else if(sum<target) k++;
                else l--;
            }
           }
        }
        return result;
    }
};
