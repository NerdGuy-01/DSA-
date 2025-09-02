/*
Problem Statement: Given an array containing both positive and negative integers, we have to find the length of the longest subarray with the sum of all elements equal to zero.

Brute :
Time Complexity: O(n²)

Space Complexity: O(1)


Optimal : If sum has been seen before, it means that the subarray between the previous index and the current index has sum = 0.

Formula: length = i - previousIndex.
sum keeps track of total balance so far.

Map remembers the first place that balance occurred.

If balance repeats, the in-between part must sum to 0.
Time Complexity: O(N), as we are traversing the array only once

Space Complexity: O(N), in the worst case we would insert all array elements prefix sum into our hashmap


*/

// Brute 
int LongestSubarraySize(vector<int>&nums){
int maxLenght = 0;
int n = nums.size();
    for(int i =0;i<n;i++){
        long long s = 0;
        for(int j = i ;j<n;j++){
          s+=nums[j];
          if(s==0){
            maxLenght = max(maxLenght,j-i+1);
          }
        }

    }
    return maxLenght;

}

// Optimal
int LongestSubarraySize(vector<int>& nums){
    unordered_map<int,int> mpp;
    int maxlength = 0;
    int sum  = 0;
    int n = nums.size();

    for(int i = 0 ; i < n; i++){
        sum += nums[i];   // keep adding the numbers

        if(sum == 0){
            maxlength = i+1;   // whole array from 0 to i is zero sum
        } else {
            if(mpp.find(sum) != mpp.end()){
                // sum was seen before, subarray between previous index+1 and i has sum 0
                maxlength = max(maxlength, i - mpp[sum]);
            } else {
                // first time we see this sum, store index
                mpp[sum] = i; 
            }
        }
    }
    return maxlength;
}

