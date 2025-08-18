/*
Problem Statement: Given a non-empty array of integers arr, every element appears twice except for one. Find that single one.

Brute force : Naive search 
For every element present in the array, we will do a linear search and count the occurrence. If for any element, the occurrence is 1, we will return it.
Time Complexity: O(N2)
Space Complexity: O(1)

Better : Using hashing 
Time Complexity: O(N)+O(N)+O(N),
Space Complexity: O(maxElement+1);
you can use maps too then the T.C :  O(N*logM) + O(M), S.C:  O(M)

Optimal : Using XOR 
XOR of two same numbers is always 0 i.e. a ^ a = 0. ←Property 1.
XOR of a number with 0 will result in the number itself i.e. 0 ^ a = a.  ←Property 2
Time Complexity: O(N)
Time Complexity: O(N)

*/


// Brute 
int getSingleElement(vector<int> &nums) {
    // Size of the array:
    int n = nums.size();

    //Run a loop for selecting elements:
    for (int i = 0; i < n; i++) {
        int num = nums[i]; // selected element
        int count = 0;

        //find the occurrence using linear search:
        for (int j = 0; j < n; j++) {
            if (nums[j] == num)
                count++;
        }

        // if the occurrence is 1 return ans:
        if (count == 1) return num;
    }

    //This line will never execute
    //if the array contains a single element.
    return -1;
}

// Better 
int getSingleElement(vector<int> &nums) {

    //size of the array:
    int n = nums.size();

    // Find the maximum element:
    int maxElement = arr[0];
    for (int i = 0; i < n; i++) {
        maxElement = max(maxElement, arr[i]);
    }

    // Declare hash array of size maxi+1
    // And hash the given array:
    vector<int> hash(maxElement + 1, 0);
    for (int i = 0; i < n; i++) {
        hash[nums[i]]++;
    }

    //Find the single element and return the answer:
    for (int i = 0; i < n; i++) {
        if (hash[arr[i]] == 1)
            return nums[i];
    }

    //This line will never execute
    //if the array contains a single element.
    return -1;
}

// Optimal 
int getSingleElement(vector<int> &nums) {
    //size of the array:
    int n = nums.size();

    // XOR all the elements:
    int xorr = 0;
    for (int i = 0; i < n; i++) {
        xorr = xorr ^ nums[i];
    }
    return xorr;
}
