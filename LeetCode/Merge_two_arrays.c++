/*   Question -> You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order

First Approach Use STL 

Add all elements of num2 in num1 and then sort them 
Time complexity: O((m+n)log(m+n)) due to sort()function
Space complexity: O(1)  not using any extra space
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
