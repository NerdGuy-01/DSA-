/*
Problem statement: Given two sorted arrays arr1[] and arr2[] of sizes n and m in non-decreasing order. Merge them in sorted order. Modify arr1 so that it contains the first N elements and modify arr2 so that it contains the last M elements.

Brute force :
first store all elements in tempArray and then rearrange themselves and put in array1 and array2 
Time Complexity: O(n+m) + O(n+m), where n and m are the sizes of the given arrays.
Reason: O(n+m) is for copying the elements from arr1[] and arr2[] to arr3[]. And another O(n+m) is for filling back the two given arrays from arr3[].

Space Complexity: O(n+m) as we use an extra array of size n+m.


Optimal : 
To get rid of Extra Space we know both arrays are sorted then we will compare nums1 last element and nums2 first element as we know that smaller will go in nums1 and larger will go in nums2
Time Complexity: O(min(n, m)) + O(n*logn) + O(m*logm), where n and m are the sizes of the given arrays.
Reason: O(min(n, m)) is for swapping the array elements. And O(n*logn) and O(m*logm) are for sorting the two arrays.

Space Complexity: O(1) as we are not using any extra space


Optimal 2:
Using gap Method-> shell sort
first we divide the size of both arrays then take an absolute size and keep pointers at that gap after right pointer goes out of box now we again find average of gap take absolute value then keep the gap  that value
Time Complexity: O((n+m)*log(n+m)), where n and m are the sizes of the given arrays.
Reason: The gap is ranging from n+m to 1 and every time the gap gets divided by 2. So, the time complexity of the outer loop will be O(log(n+m)). Now, for each value of the gap, the inner loop can at most run for (n+m) times. So, the time complexity of the inner loop will be O(n+m). So, the overall time complexity will be O((n+m)*log(n+m)).

Space Complexity: O(1) as we are not using any extra space.

*/

// brute 
void MergeSortedArray(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    int m = nums2.size();
    vector<int> tempArray(n + m);

    int left = 0, right = 0, index = 0;

    // Merge two sorted arrays
    while (left < n && right < m) {
        if (nums1[left] <= nums2[right]) {
            tempArray[index++] = nums1[left++];
        } else {
            tempArray[index++] = nums2[right++];
        }
    }

    // Copy remaining elements
    while (left < n) {
        tempArray[index++] = nums1[left++];
    }
    while (right < m) {
        tempArray[index++] = nums2[right++];
    }

  
    for (int i = 0; i < n + m; i++) {
        if (i < n) nums1[i] = tempArray[i];
        else nums2[i - n] = tempArray[i];
    }  
}

// Optimal 
void MergeSortedArray(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    int m = nums2.size();
    int left = n-1;   // start from end of nums1
    int right = 0;    // start from beginning of nums2
    
    // Step 1: Push bigger nums1 elements to nums2
    while(left >= 0 && right < m){
        if(nums1[left] > nums2[right]){
            swap(nums1[left], nums2[right]); // put smaller element in nums1, bigger in nums2
            left--; 
            right++;
        } else {
            break;  // already sorted
        }
    }

  // Optimal 2 
  void swapIfGreater(vector<int>& nums1, vector<int>& nums2, int ind1, int ind2) {
    if (nums1[ind1] > nums2[ind2]) {
        swap(nums1[ind1], nums2[ind2]);
    }
}

void MergeSortedArray(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    int m = nums2.size();
    int len = n + m;

    int gap = (len / 2) + (len % 2); // initial gap

    while (gap > 0) {
        int left = 0, right = left + gap;

        while (right < len) {
            // case 1: both pointers in nums1
            if (left < n && right < n) {
                swapIfGreater(nums1, nums1, left, right);
            }
            // case 2: left in nums1, right in nums2
            else if (left < n && right >= n) {
                swapIfGreater(nums1, nums2, left, right - n);
            }
            // case 3: both pointers in nums2
            else {
                swapIfGreater(nums2, nums2, left - n, right - n);
            }
            left++;
            right++;
        }

        if (gap == 1) break; // final pass done
        gap = (gap / 2) + (gap % 2); // shrink gap
    }
}

    
    // Step 2: Sort both arrays individually
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
}
