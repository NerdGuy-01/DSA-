/*
Given an integer N and an array of size N-1 containing N-1 numbers between 1 to N. Find the number(between 1 to N), that is not present in the given array.

Brute -> simple sort then run a loop 
T.C: O(N2)
S.C : O(1)  as we are not using any extra space.

Better -> Using Hash maps The range of the number is 1 to N. So, we need a hash array of size N+1 (as we want to store the frequency of N as well).After that, for each number between 1 to N, we will check the frequencies. And for any number, if the frequency is 0, we will return it.

T.C.  O(2*N); For storing the frequencies in the hash array, the program takes O(N) time complexity and for checking the frequencies in the second step again O(N) is required. So, the total time complexity is O(N) + O(N).
S.C :  O(N), where N = size of the array+1. Here we are using an extra hash array of size N+1.


Optimal ->
Summation Approach We know that the summation of the first N numbers is (N*(N+1))/2
T.C. : O(N), where N = size of array+1.
S.C.: O(1) we are not using any extra space
*/

// Brute 
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int i = 0;
       for(i;i<n;i++){
        if(nums[i]!=i) break;
       }
       return i ;
    }
};

// better 

int missingNumber(vector<int>&nums,int N){
int hash[n+1] = {0};
     // storing the frequencies:
    for (int i = 0; i < N - 1; i++)
        hash[nums[i]]++;
    //checking the freqencies for numbers 1 to N:
    for (int i = 1; i <= N; i++) {
        if (hash[i] == 0) {
            return i;
        }
    }
  // The following line will never execute.
    // It is just to avoid warnings.
    return -1;

}

// optimal 
int missingNumber(vector<int>&nums,int N){
    //Summation of first N numbers:
    int sum = (N * (N + 1)) / 2;

    //Summation of all array elements:
    int s2 = 0;
    for (int i = 0; i < N - 1; i++) {
        s2 += nums[i];
    }

    int missingNum = sum - s2;
    return missingNum
}
