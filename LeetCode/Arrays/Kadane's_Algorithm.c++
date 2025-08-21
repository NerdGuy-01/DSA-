/*
Problem Statement: Given an integer array arr, find the contiguous subarray (containing at least one number) which
has the largest sum and returns its sum and prints the subarray.

Brute :  We add all the elements and then return the max using 3 loops 
Time Complexity: O(N3), where N = size of the array.
Space Complexity: O(1) as we are not using any extra space.

Better : f we carefully observe, we can notice that to get the sum of the current subarray we just need to add the current element(i.e. arr[j]) to the sum of the previous subarray i.e. arr[i….j-1]
Time Complexity: O(N2), where N = size of the array.
Space Complexity: O(1) as we are not using any extra space.

Optimal : Using Kadane Algorithm
If you carry negative sum the summation will always gets reduced.
In simple words it says that I will loop over the array and if the sum is less than zero I will be drop it otherwise I will increase it..


*/


// Brute
int maxSubarraySum(vector<int>nums, int n) {
    int maxi = INT_MIN; // maximum sum

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            // subarray = arr[i.....j]
            int sum = 0; // here to reset the sum everytime looping end

            //add all the elements of subarray:
            for (int k = i; k <= j; k++) {
                sum += nums[k];
            }

            maxi = max(maxi, sum);
        }
    }

    return maxi;
}

// Better
int maxSubarraySum(vector<int>nums, int n) {
    int maxi = INT_MIN; // maximum sum

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            // current subarray = arr[i.....j]

            //add the current element arr[j]
            // to the sum i.e. sum of arr[i...j-1]
            sum += nums[j];

            maxi = max(maxi, sum); // getting the maximum
        }
    }

    return maxi;
}


// Optimal 
int MaximumSubarray(vector<int>&nums){
    int n = nums.size();
   long long sum = 0;
   int maxInt = LONG_MIN;
   for (int i = 0; i < n; i++)
   {
     sum+=nums[i];

     if(sum>maxInt){
        maxInt =  sum;
     }
     if(sum<0){
        sum = 0;
     }
   }
    // To consider the sum of the empty subarray
    // uncomment the following check:

    if (maxInt < 0) maxInt = 0;
return maxInt;
  
}
