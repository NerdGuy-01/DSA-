/*
Problem Statement: Given an array that contains both negative and positive integers, find the maximum product subarray.


Brute :
Three pointers
Time Complexity: O(N3)

Reason: We are using 3 nested loops for finding all possible subarrays and their product.

Space Complexity: O(1)

Reason: No extra data structure was used



Better : 
Two pointer 
Time Complexity: O(N2)

Reason: We are using two nested loops

Space Complexity: O(1)

Reason: No extra data structures are used for computation

Optimal :
pre (prefix product) and suff (suffix product) are both set to 1.

ans keeps track of the maximum product found so far, initialized with the lowest possible integer (INT_MIN).
Loop runs from i = 0 to n - 1.

pre multiplies elements from left to right.

suff multiplies elements from right to left.

So, for each iteration, you check:

Product of subarray starting from left (pre)

Product of subarray starting from right (suff)
If at any point pre or suff becomes 0, reset it to 1 (because a zero would ruin the product chain; resetting allows checking subarrays after zero).
Time Complexity: O(N), N = size of the given array.
Reason: We are using a single loop that runs for N times.

Space Complexity: O(1) as No extra data structures are used for computation.
*/

// brute 
int maxProductSubArray(vector<int>& nums) {
    int result = INT_MIN;
    for(int i=0;i<nums.size()-1;i++) {
        for(int j=i+1;j<nums.size();j++) {
            int prod = 1;
            for(int k=i;k<=j;k++) 
                prod *= nums[k];
            result = max(result,prod);    
        }
    }
    return result;
}

// Better 

int maxProductSubArray(vector<int>& nums) {
    int result = nums[0];
    for(int i=0;i<nums.size()-1;i++) {
        int p = nums[i];
        for(int j=i+1;j<nums.size();j++) {
           result = max(result,p);
           p *= nums[j];
        }
        result = max(result,p);//manages (n-1)th term 
    }
    return result;
}

// Optimal 
int maxProductSubArray(vector<int> &arr) {
    int n = arr.size(); //size of array.

    int pre = 1, suff = 1;
    int ans = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (pre == 0) pre = 1;
        if (suff == 0) suff = 1;
        pre *= arr[i];
        suff *= arr[n - i - 1];
        ans = max(ans, max(pre, suff));
    }
    return ans;
}
