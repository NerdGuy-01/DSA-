/*
Problem Statement: You are given an array of integers 'arr' and an integer i.e. a threshold value 'limit'. Your task is to find the smallest positive integer divisor, such that upon dividing all the elements of the given array by it, the sum of the division's result is less than or equal to the given threshold value

Brute force :
Time Complexity: O(max(arr[])*N), where max(arr[]) = maximum element in the array, N = size of the array.
Reason: We are using nested loops. The outer loop runs from 1 to max(arr[]) and the inner loop runs for N times.

Space Complexity: O(1) as we are not using any extra space to solve this problem.

Optimal :
Using binary Search 
Time Complexity: O(log(max(arr[]))*N), where max(arr[]) = maximum element in the array, N = size of the array.
Reason: We are applying binary search on our answers that are in the range of [1, max(arr[])]. For every possible divisor ‘mid’, we call the sumByD() function. Inside that function, we are traversing the entire array, which results in O(N).

Space Complexity: O(1) as we are not using any extra space to solve this problem.

*/

// Brute force 
int smallestDivisor(vector<int>& nums, int limit) {
    int n = nums.size(); //size of array.
    //Find the maximum element:
    int maxi = *max_element(arr.begin(), arr.end());

    //Find the smallest divisor:
    for (int d = 1; d <= maxi; d++) {
        //Find the summation result:
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += ceil((double)(nums[i]) / (double)(d));
        }
        if (sum <= limit)
            return d;
    }
    return -1;
}

// Optimal 
class Solution {
public:

  int sumD(vector<int>nums,int div){
    int n = nums.size();
 int sum = 0;
 for (int i = 0; i < n; i++)
 {
   sum += ceil((double)nums[i]/(double)div);
 }
 return sum;
  }
    int smallestDivisor(vector<int>& nums, int threshold) {
        
         int n = nums.size(); // if divisor dont exist 
         if(n>threshold) return -1;
   int low = 1;
   int high = *max_element(nums.begin(),nums.end());
   
   while(low<=high){
    int mid = (high+low)/2;
    if(sumD(nums,mid)<=threshold){
        high = mid-1;
    } else {
        low = mid+1;
    }
   }
   return low;
    }
};
