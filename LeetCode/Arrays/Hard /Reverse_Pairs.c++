/*
Problem Statement: Given an array of numbers, you need to return the count of reverse pairs. Reverse Pairs are those pairs where i<j and arr[i]>2*arr[j].

Brute : Two pointer 
Time Complexity: O(N2), where N = size of the given array.
Reason: We are using nested loops here and those two loops roughly run for N times.

Space Complexity: O(1) as we are not using any extra space to solve this problem.


Optimal :
Again merge Sort but with sligth modifications
but the same logic of count_inversions will not work cause 
The merge function works by comparing two elements from two halves i.e. arr[left] and arr[right]. Now, the condition in the question was arr[i] > arr[j]. That is why we merged the logic. While comparing the elements, we counted the number of pairs.
But in this case, the condition is arr[i] > 2*arr[j]. And, we cannot change the condition of comparing the elements in the merge() function. If we change the condition, the merge() function will fail to merge the elements. So, we need to check this condition and count the number of pairs separately.

Time Complexity: O(2N*logN), where N = size of the given array.
Reason: Inside the mergeSort() we call merge() and countPairs() except mergeSort() itself. Now, inside the function countPairs(), though we are running a nested loop, we are actually iterating the left half once and the right half once in total. That is why, the time complexity is O(N). And the merge() function also takes O(N). The mergeSort() takes O(logN) time complexity. Therefore, the overall time complexity will be O(logN * (N+N)) = O(2N*logN).

Space Complexity: O(N), as in the merge sort We use a temporary array to store elements in sorted order.
*/


// Brute 
int count(vector<int>&nums){
    int n = nums.size();
    int count=0;
    for(int i =0;i<n;i++){
        for(int j =i+1;j<n;j++){
             if(nums[i]>2*nums[j]){
                count++;
             }
        }
    }
   return count;
}

// Optimal 
class Solution {
public:
void merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp; // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1;   // starting index of right half of arr

    //storing elements in the temporary array in a sorted manner//

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // if elements on the left half are still left //

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

int count_pairs(vector<int>&nums,int low,int mid,int high){
    int right = mid+1;
    int count = 0;
    for(int i =low;i<=mid;i++){
        // If nums[i] and nums[right] are large (> 1e9), this may overflow int.
        while(right<=high && (long long)nums[i]>2LL*nums[right]) right++;
        count+=(right-(mid+1));
    }
    return count;
}
int mergeSort(vector<int>&nums,int low,int high){
    int count = 0;
     int mid = (low + high) / 2 ;
    if(low>=high) return count;
      count+= mergeSort(nums,low,mid);
        count+=  mergeSort(nums,mid+1,high);
        count+= count_pairs(nums,low,mid,high);
         merge(nums,low,mid,high);
        return count;
}
    int reversePairs(vector<int>& nums) {
         int n = nums.size();
         return mergeSort(nums,0,n-1);
    }
};
