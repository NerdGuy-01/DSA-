/* 
Q: Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.

my code :

Logic errors like it compares every element but we are not given they are in sorted order  what if [1,2,3] and [3,1,2] in  my code it will give no elements but it has 3 intersections and also if I use sort two times then it will increse the time complexity and also number of elements both are not same 

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
       unordered_set<int> store;
       int i = nums1.size()-1;
       int j = nums2.size()-1;
       while(i>=0 && j>=0){
        if(nums1[i]==nums2[j]){
            store.insert(nums1[i]);
            i--;
            j--;
        }
         else{
            i--;
            j--;
         }
         
       }
      return vector<int>(store.begin(),store.end());
    }
};

*/


// Code that is right Time: O(n + m) — where n and m are sizes of nums1 and nums2

 // Space: O(n) — storing elements in a set

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> store(nums1.begin(),nums1.end()); // store all elements in set because sets remove duplicates 
        unordered_set<int> result;
        for(int num:nums2){    // Iterate over nums2 and check which elements exist in the set. Store common ones in a result set (to avoid duplicates).
            if(store.count(num)){
                result.insert(num);
            }
        }

        return vector<int>(result.begin(),result.end());
    }
};
