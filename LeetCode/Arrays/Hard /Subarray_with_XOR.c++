/*
Problem Statement: Given an array of integers A and an integer B. Find the total number of subarrays having bitwise XOR of all elements equal to k.

Brute : 
Time Complexity: O(N3) approx., where N = size of the array.
Reason: We are using three nested loops, each running approximately N times.

Space Complexity: O(1) as we are not using any extra space.

Better :
Same as longestSubarray
Time Complexity: O(N2), where N = size of the array.
Reason: We are using two nested loops here. As each of them is running for N times, the time complexity will be approximately O(N2).

Space Complexity: O(1) as we are not using any extra space.

Optimal :
Every subarray have a ending 

It's institution is : is there a subarray with XOR K and ending K 
*/

// Brute force
int Subarray_xor(vector<int>&nums,int k){
   int n = nums.size();
   int count = 0;
   for(int i =0;i<n;i++){
       for(int j=i;j<n;j++){
            int result = 0; 
        for(int k = i;k<=j;k++){
          result^=nums[k];
        }
        if(result==k) count++;
        
    }
   }
   cout << count;
}


// Better 
int Subarray_xor(vector<int>&nums,int k){
    int n = nums.size();
    int count = 0;
    for(int i = 0;i<n;i++){
        int result  =0;
        for(int j = i;j<n;j++){
           result^=nums[j];
           if(result ==k){
             count++;
           }
        }
    }
   return count;
}

// optimal 
int Subarray_xor(vector<int> &nums, int k) {
    int n = nums.size(); //size of the given array.
    int xr = 0;
    map<int, int> mpp; //declaring the map.
    mpp[xr]++; //setting the value of 0.
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        // prefix XOR till index i:
        xr = xr ^ nums[i];

        //By formula: x = xr^k:
        int x = xr ^ k;

        // add the occurrence of xr^k
        // to the count:
        cnt += mpp[x];

        // Insert the prefix xor till index i
        // into the map:
        mpp[xr]++;
    }
    return cnt;
}
