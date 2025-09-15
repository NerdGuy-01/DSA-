/*
Problem Statement: You are given a strictly increasing array ‘vec’ and a positive integer 'k'. Find the 'kth' positive integer missing from 'vec'.


My code : Which is completely wrong 
int KPositive(vector<int>&nums,int k){
    int n = nums.size();
    int maxEl = *max_element(nums.begin(),nums.end());
    map<int,int>mpp;
    for(int i =0;i<maxEl;i++){
        mpp[nums[i]]++;
    }
    
    for(auto cn:mpp){
         if(cn.second ==0){
            return mpp[k];
         }
    }
    return -1;
}


Brute :
Linear search 
Time Complexity: O(N), N = size of the given array.
Reason: We are using a loop that traverses the entire given array in the worst case.

Space Complexity: O(1) as we are not using any extra space to solve this problem.

Optimal :
Using binary Search ideally on the index 4 if 11 is present and if we subs by 5 it will give  us the missing number 11-5 =6
Time Complexity: O(logN), N = size of the given array.
Reason: We are using the simple binary search algorithm.

Space Complexity: O(1) as we are not using any extra space to solve this problem.
*/

// Brute 
int missingK(vector < int > vec, int n, int k) {
    for (int i = 0; i < n; i++) {
        if (vec[i] <= k) k++; //shifting k
        else break;
    }
    return k;
}

// Optimal 
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
         int n = arr.size();
   int low = 0;
   int high = n-1;
   while(low<=high){
    int mid = (low+high)/2;
    int missing = arr[mid] - (mid+1);
    if(missing <k){
        low = mid+1;
    } else {
        high = mid-1;
    }
   }
   return k + high + 1;
    }
};
