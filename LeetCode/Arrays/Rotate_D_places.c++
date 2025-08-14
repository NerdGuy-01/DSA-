/* 
Given an array of integers, rotating array of elements by D elements 

If we Rotate it by  the number of element and if more then we can Divide it like

9 -> 7+2 Rotation thats why we do Modular of d = d%N as we will be at the same element

Brute ->
shifting
for(int i =d;i<n;i++){
a[i-d] = a[i]  new element
}
put back 
int j =0;
for(int i = n-d;i<n;i++){
a[i] = temp[j]; or you can do this a[i] = temp[i-(n-d)]
j++;
}

T.C. : O(N+D)
S.C. : Extra space O(k)




Optimal ->
Revserse upto K parts array then another k-1 arrays and then to get answer reverse whole array 
T.C: O(2N)
S.C: O(1)
*/

//  Brute
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n; // to handle k > n
        vector<int> temp(k);

        // Step 1: Store last k elements
        for (int i = 0; i < k; i++) {
            temp[i] = nums[n - k + i];
        }

        // Step 2: Shift remaining elements to the right
        for (int i = n - 1; i >= k; i--) {
            nums[i] = nums[i - k];
        }

        // Step 3: Copy temp elements to the front
        for (int i = 0; i < k; i++) {
            nums[i] = temp[i];
        }
    }
};

// Optimal 
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n; // handle k > n

        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};

