/*   Question -> You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order

First Approach Use STL 

Add all elements of num2 in num1 and then sort them 
Time complexity: O((m+n)log(m+n)) due to sort()function
Inserting a key in map takes logN times
Space complexity: O(1)  not using any extra space


Second Approach 

Use two Pointer i = m-1 and j =n-1 and k= m+n-1;Then we can start iterating from the end of the arrays i and j, and compare the elements at these positions. We will place the larger element in nums1 at position k, and decrement the corresponding pointer i or j accordingly.

Compare elements at nums1[i] and nums2[j]

Place the larger element at nums1[k]

Decrement the respective pointer
Time complexity: O(m+n)  we are iterating on both arrays
Space complexity: O(1)

*/


// first Approach
class Solution {
public:
    void merge(vector<int>& num1, int m, vector<int>& num2, int n) {
       for(int j =0,i<m;j<n;j++){ // we declared two var in for loop
         nums1[i] =  nums2[j];
         i++;
       }
      sort(nums1.begin(),nums1.end());
      
    }
};

// second Approach
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1; // Pointer to last valid element in nums1
        int j = n - 1; // Pointer to last element in nums2
        int k = m + n - 1; // Pointer to the last position in merged array
        
        while (j >= 0) {  /// checks for element that is greater in nums1 if not shift it, its like comparing 
            if (i >= 0 && nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }
    }
};
