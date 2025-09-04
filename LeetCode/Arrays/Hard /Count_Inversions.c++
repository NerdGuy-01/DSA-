/*
Problem Statement: Given an array of N integers, count the inversion of the array (using merge-sort).

What is an inversion of an array? Definition: for all i & j < size of array, if i < j then you have to find pair (A[i],A[j]) such that A[j] < A[i].

means (left,right) left element should always be bigger

Brute force : Using Two pointers 
Time Complexity: O(N2), where N = size of the given array.
Space Complexity: O(1) as we are not using any extra space to solve this problem

Optimal :
Using merge sorted Imagine you have 2 arrays both are sorted. Then we only need to find left>right so if we got one element which is greater than in right array we can say that after that element all are greater than that why cause arrays are sorted.
Numbers on the right = mid-left+1
Time Complexity: O(N*logN), where N = size of the given array.
Reason: We are not changing the merge sort algorithm except by adding a variable to it. So, the time complexity is as same as the merge sort.

Space Complexity: O(N), as in the merge sort We use a temporary array to store elements in sorted order.



*/

// brute 
int Inversion(vector<int>&nums){
    int n = nums.size();
    int count = 0;
    for(int i =0;i<n;i++){
        for(int j =i+1;j<n;j++){
            if(nums[i]>nums[j]){
                count++;
            }
        }
    }
  return count;
}


// Optimal 
int merge(vector<int>&nums,int low,int mid,int high){
    int count = 0;
    int left = low;
    int right = mid+1;
    vector<int>temp;
    while(left<=mid && right<=high){
        if(nums[left]<=nums[right]){
            temp.push_back(nums[left++]);
            left++;
        } 
         // right is smaller
        else{
             temp.push_back(nums[right++]);
             count +=(mid-low+1);
             right++;
        }
    }
    while(left<=mid){
        temp.push_back(nums[left++]);
        left++;
    }
    while (right<=high)
    {
       temp.push_back(nums[left++]);
       right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
     return count;
}

int merge_sort(vector<int>&nums,int low,int high){
    int count;
       if(low>=high) return count;
       int mid = (high+low)/2;
     count+= merge_sort(nums,low,mid+1);
     count+= merge_sort(nums,mid+1,high);
      count+= merge(nums,low,mid,high);
      return count;
}

int Inversion(vector<int>&nums){
    int n = nums.size();
 return   merge_sort(nums,0,n-1);
    
}
