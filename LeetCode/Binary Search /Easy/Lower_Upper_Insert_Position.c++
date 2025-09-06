/*
Problem Statement: Given a sorted array of N integers and an integer x, write a program to find the lower and upper bound of x.
the code for lower bound

*/

// for lower bound 
int Lower_bound(vector<int>&nums,int x){
   int n = nums.size();
   int result = n;
   int low = 0; int high = n-1;
   while(low<=high){
       int mid  = (low+high)/2;
       if(nums[mid]>=x){
        result = mid;
        high = mid-1;
       } else{
        low = mid+1;
       }
   
   }
   return result; // hypothetical answer if we don't find any lower bond
}
// TC : O(log2N)

// but for C users you can also use C++ template 
lower_bound(nums.begin(),nums.end(),x);
// to get index 
lb =  lower_bound(nums.begin(),nums.end(),x) - nums.begin();


// Upper bound
int Upper_bound(vector<int>&nums,int x){
   int n = nums.size();
   int result = n;
   int low = 0; int high = n-1;
   while(low<=high){
       int mid  = (low+high)/2;
       if(nums[mid]>x){ // only >= changes to >
        result = mid;
        high = mid-1;
       } else{
        low = mid+1;
       }
   
   }
   return result; // hypothetical answer if we don't find any lower bond
}
// // TC : O(log2N) and yeah you can also use upper_bound template 



// for Insert Position 
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
    int low =0;
    int high = n-1;
    int result = n;
    while(low<=high){
    int mid = low + (high-low)/2;
        if(nums[mid]>=target){
               result = mid;
               high = mid-1;
        } else{
            low = mid+1;
        }
    }
    return result;
    }
};
