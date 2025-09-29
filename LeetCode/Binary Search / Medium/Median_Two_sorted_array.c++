/*
Problem Statement: Given two sorted arrays arr1 and arr2 of size m and n respectively, return the median of the two sorted arrays. The median is defined as the middle value of a sorted list of numbers. In case the length of the list is even, the median is the average of the two middle elements.


Brute : Merging two arrays and then finding median 
My approach works fine but we need to resize the array to make spaces for nums2 elements 
T.C: O(m+n)
S.C. :O(1)


Better : this one only simulates the merge until it reaches the median indices. Let’s unpack it clearly.
If n is odd → the median index is n/2.

If n is even → we need two elements: n/2 - 1 and n/2.
So ind1 and ind2 are the two “middle” indices.
Each time we pick an element, we check:

Is it at position ind1? Save it in ind1el.

Is it at position ind2? Save it in ind2el.

Keep counting until we reach the needed indices.

T.C and S.C are same as brute force 


*/

// Brute 
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
          int n = nums1.size();
    int m = nums2.size();
    nums1.resize(n+m);
     int i = n-1;
    int j = m-1;
    int k = n+m-1;
    while(j>=0){
        if(i>=0 && nums1[i]>nums2[j]) {
            nums1[k--]  = nums1[i--];
        } else{
              nums1[k--]  = nums2[j--];
        }
    }
   int size = n+m;
   if(size%2==1){
    return (double) nums1[size/2];
   }
    double median = ((double)nums1[size/2] + (double)nums1[(size / 2) - 1])/2.0;
 return median;
    }
};

// Better 
double median(vector<int>& a, vector<int>& b) {
    //size of two given arrays:
    int n1 = a.size(), n2 = b.size();
    int n = n1 + n2; //total size
    //required indices:
    int ind2 = n / 2;
    int ind1 = ind2 - 1;
    int cnt = 0; // count keeps track of how far we have merged till now 
    int ind1el = -1, ind2el = -1; // both will hold values for it 

    //apply the merge step:
    int i = 0, j = 0;
    while (i < n1 && j < n2) {
        if (a[i] < b[j]) {
            if (cnt == ind1) ind1el = a[i];
            if (cnt == ind2) ind2el = a[i];
            cnt++;
            i++;
        }
        else {
            if (cnt == ind1) ind1el = b[j];
            if (cnt == ind2) ind2el = b[j];
            cnt++;
            j++;
        }
    }

    //copy the left-out elements:
    while (i < n1) {
        if (cnt == ind1) ind1el = a[i];
        if (cnt == ind2) ind2el = a[i];
        cnt++;
        i++;
    }
    while (j < n2) {
        if (cnt == ind1) ind1el = b[j];
        if (cnt == ind2) ind2el = b[j];
        cnt++;
        j++;
    }

    //Find the median:
    if (n % 2 == 1) {
        return (double)ind2el;
    }

    return (double)((double)(ind1el + ind2el)) / 2.0;
}

// Optimal 
