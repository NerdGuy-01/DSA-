/*
Problem Statement: Given an array and a sum k, we need to print the length of the longest subarray that sums to k.

Brute :
We will check the sum of every possible subarray and consider the one with the sum k and the maximum length among them. To get every possible subarray sum, we will be using three nested loops.

for subarray use i and j 
Time Complexity: O(N2)
Space Complexity: O(1)

Better : Using hashing
it like first we keep summing then if we find it equal to k then we check in map if it exist if yes then we check the lenght of it, if it is greater then previous one we update it, but if we don't find it then we just store the new value of sum
Time Complexity: O(N) or O(N*logN) 
Space Complexity: O(N)

if the array contains only positives and negatives then this is the optimal solution



Optimal : Using Two pointer 
Time Complexity: O(2*N)
Space Complexity: O(1) as we are not using any extra space.
*/


// brute 
int getLongestSubarray(vector<int>& nums, long long k) {
    int n = nums.size(); // size of the array.

    int len = 0;
    for (int i = 0; i < n; i++) { // starting index
        long long s = 0; // Sum variable
        for (int j = i; j < n; j++) { // ending index
            // add the current element to
            // the subarray a[i...j-1]:
            s += nums[j];

            if (s == k)
                len = max(len, j - i + 1); // lenght of i and j -> j-i+1
        }
    }
    return len;
}

// better 
int getLongestSubarray(vector<int>& nums, long long k) {
    int n = nums.size(); // size of the array.

    map<long long, int> preSumMap;
    long long sum = 0;
    int maxLen = 0;
    for (int i = 0; i < n; i++) {
        //calculate the prefix sum till index i:
        sum += nums[i];

        // if the sum = k, update the maxLen:
        if (sum == k) {
            maxLen = max(maxLen, i + 1);
        }

        // calculate the sum of remaining part i.e. x-k:
        long long rem = sum - k;

        //Calculate the length and update maxLen:
        if (preSumMap.find(rem) != preSumMap.end()) {
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }

        //Finally, update the map checking the conditions: to check for zeros too
        if (preSumMap.find(sum) == preSumMap.end()) {
            preSumMap[sum] = i;
        }
    }

    return maxLen;
}

// Optimal

int getLongestSubarray(vector<int>& nums, long long k) {
    int n = a.size(); // size of the array.

    int left = 0, right = 0; // 2 pointers
    long long sum = a[0];
    int maxLen = 0;
    while (right < n) {
        // if sum > k, reduce the subarray from left
        // until sum becomes less or equal to k:
        while (left <= right && sum > k) {
            sum -= nums[left];
            left++;
        }

        // if sum = k, update the maxLen i.e. answer:
        if (sum == k) {
            maxLen = max(maxLen, right - left + 1);
        }

        // Move forward the right pointer:
        right++;
        if (right < n) sum += nums[right];
    }

    return maxLen;
}

/*
for Subarray Sum 
We will use prefix sum 
Why we set presum = 0 ; 
Let’s understand this using an example. Assume the given array is [3, -3, 1, 1, 1] and k is 3. Now, for index 0, we get the total prefix sum as 3, and k is also 3. So, the prefix sum of the remove-part should be x-k = 3-3 = 0. Now, if the value is not previously set for the key 0 in the map, we will get the default value 0 for the key 0 and we will add 0 to our answer. This will mean that we have not found any subarray with sum 3 till now. But this should not be the case as index 0 itself is a subarray with sum k i.e. 3.
So, in order to avoid this situation we need to set the value of 0 as 1 on the map beforehand.


mpp[0] = 1 is important: it handles the case when the subarray itself (from start) equals k.

 T.C: if we are using an unordered_map data structure in C++ the time complexity will be O(N) but if we are using a map data structure, the time complexity will be O(N*logN). The least complexity will be O(N) as we are using a loop to traverse the array.
*/ 

// Optimal 

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int>mpp;
        int n = nums.size();
        mpp[0] =1;
        int presum = 0, count  = 0;
       for(int i =0;i<n;i++){
        presum+=nums[i];
        int remove = presum -k;
        count+=mpp[remove];
        mpp[presum]+=1;
       }

        return count;
    }
};
