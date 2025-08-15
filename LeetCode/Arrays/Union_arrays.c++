/*
Q : Given two sorted arrays, arr1, and arr2 of size n and m. Find the union of two sorted arrays.

The union of two arrays can be defined as the common and distinct elements in the two arrays.NOTE: Elements in the union should be in ascending order.


Brute force ->
Using maps As we are using only a single map the common element in arr1 and arr2 are treated as a single element for finding frequency, so there would be no duplicates. Why not undordered because it says to store in ascending order 
T.C.:  O( (m+n)log(m+n) ) . Inserting a key in map takes logN times, where N is no of elements in map. At max map can store m+n elements {when there are no common elements and elements in arr,arr2 are distntict}.

S.C:O(m+n) {If Space of Union ArrayList is considered} 

O(1) {If Space of union ArrayList is not considered}

Better ->
Using set
Suppose we consider arr1 and arr2 as a single array say arr,  then the union of arr1 and arr2 is the distinct elements in arr.
T.C:O( (m+n)log(m+n) ) . Inserting an element in a set takes logN time
T.C: O(m+n) {If Space of Union ArrayList is considered} 

O(1) {If Space of union ArrayList is not considered}


Optimal ->
Using two Pointers

*/


// Brute
vector < int > FindUnion(vector<int> nums1, vector<int> nums2) {
  int n = nums1.size();
  int m = nums2.size();
  map < int, int > freq;
  vector < int > result;
  for (int i = 0; i < n; i++)
    freq[nums1[i]]++;
  for (int i = 0; i < m; i++)
    freq[nums2[i]]++;
  for (auto & it: freq)
    result.push_back(it.first);
  return result;
}

// Better 
vector < int > FindUnion(vector<int> nums1, vector<int> nums2) {
  int n = nums1.size();
  int m = nums2.size();
 set<int>s;
  vector < int > result;
  for (int i = 0; i < n; i++)
    s.insert(nums1[i])++;
  for (int i = 0; i < m; i++)
   s.insert(nums2[i]);
  for (auto & it: s)
    result.push_back(it);
  return result;
} 


// Optimal Method 
vector<int> union_fn(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    int m = nums2.size();
    vector<int> result;
    int i = 0, j = 0;

    while (i < n && j < m) {
        if (nums1[i] <= nums2[j]) {
            if (result.empty() || result.back() != nums1[i]) // to check if duplicate elements are not stored
                result.push_back(nums1[i]);
            i++;
        } else {
            if (result.empty() || result.back() != nums2[j])
                result.push_back(nums2[j]);
            j++;
        }
    }

    // Add remaining elements from nums1
    while (i < n) {
        if (result.empty() || result.back() != nums1[i])
            result.push_back(nums1[i]);
        i++;
    }

    // Add remaining elements from nums2
    while (j < m) {
        if (result.empty() || result.back() != nums2[j])
            result.push_back(nums2[j]);
        j++;
    }

    return result;
}

