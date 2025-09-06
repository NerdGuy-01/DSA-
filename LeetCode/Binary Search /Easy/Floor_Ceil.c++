/*
Problem Statement: You're given an sorted array arr of n integers and an integer x. Find the floor and ceiling of x in arr[0..n-1].
The floor of x is the largest element in the array which is smaller than or equal to x.
The ceiling of x is the smallest element in the array greater than or equal to x.

Floor -> Largest number in an array <=x: Upper Bound
Ceil -> Smallest number in an array >=x : Lower Bound

// My answer which is slightly wrong 
vector<int>Floor(vector<int>&nums,int target){
    int n = nums.size();
     int low = 0;
     int high = n-1;
     vector<int>result;
     while(low<=high){
        int mid = low + (high-low)/2;
        if(nums[mid]>target) {
             result.push_back(nums[mid]);
             high = mid-1;  
        }  else if(nums[mid]>=target){
            result.push_back(nums[mid]);
            low = mid+1;
        } else{
            low = mid+1;
        }
     }
}

Approach : 
find mid then 
If it’s ≤ target, it can be a floor candidate → save it, then search right to see if there’s a bigger one still ≤ target.

If it’s > target, it’s too big → search left.\
Why are we not comparing the numbers to get the largest or smallest while calculating the floor or ceiling?

In the floor algorithm, if we get a possible answer, we are reducing the search space to the right half. And the right half certainly contains larger numbers than the current answer. So, every time we are getting larger numbers as answers.
Similarly, in the ceil algorithm, if we get a possible answer, we are reducing the search space to the left half. And the left half certainly contains smaller numbers than the current answer. So, every time we are getting smaller numbers as answers.
Basically, in each case, we are moving in a direction such that we get the largest or the smalleset as per our need. That is why we are not checking for the largest or the smallest explict

Time Complexity: O(logN), where N = size of the given array.
Reason: We are basically using the Binary Search algorithm.

Space Complexity: O(1) as we are using no extra space
*/

// Correct answer
int Floor(vector<int>& nums, int target) {
    int n = nums.size();
    int low = 0, high = n - 1;
    int ans = -1; // use -1 if no floor exists

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] <= target) { // main is here playing with symbols
            ans = nums[mid];  // candidate for floor
            low = mid + 1;    // look for right 
        } else {
            high = mid - 1; // look on right 
        }
    }
    return ans;
}
