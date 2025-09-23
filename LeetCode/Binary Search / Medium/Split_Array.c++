/*
Problem Statement: Given an integer array ‘A’ of size ‘N’ and an integer ‘K'. Split the array ‘A’ into ‘K’ non-empty subarrays such that the largest sum of any subarray is minimized. Your task is to return the minimized largest sum of the split.
A subarray is a contiguous part of the array.



Brute :
Time Complexity: O(N * (sum(arr[])-max(arr[])+1)), where N = size of the array, sum(arr[]) = sum of all array elements, max(arr[]) = maximum of all array elements.
Reason: We are using a loop from max(arr[]) to sum(arr[]) to check all possible values of time. Inside the loop, we are calling the countPartitions() function for each number. Now, inside the countPartitions() function, we are using a loop that runs for N times.

Space Complexity:  O(1) as we are not using any extra space to solve this problem.
*/


// Brute 
int countPartition(vector<int>&nums,int maxSum){
    int n = nums.size();
    int partitions = 1;
    long long subarray =0;
    for (int i = 0; i < n; i++)
    {
        if(subarray + nums[i]<=maxSum){
            subarray += nums[i];
        } else{
            partitions++;
            subarray += nums[i];


        }
       
    }
    return partitions;
    
}

int split_Array(vector<int>&nums,int k){
    int n = nums.size();
 int low  = *max_element(nums.begin(),nums.end());
 int high = accumulate(nums.begin(),nums.end(),0);
 for(int maxSum = low ; maxSum<=high;maxSum++){
    if(countPartition(nums,maxSum)==k){
         return maxSum;
    }
 }
 return low;
}
