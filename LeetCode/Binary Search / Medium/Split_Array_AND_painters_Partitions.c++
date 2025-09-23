/*
Problem Statement: Given an integer array ‘A’ of size ‘N’ and an integer ‘K'. Split the array ‘A’ into ‘K’ non-empty subarrays such that the largest sum of any subarray is minimized. Your task is to return the minimized largest sum of the split.
A subarray is a contiguous part of the array.



Brute :
Time Complexity: O(N * (sum(arr[])-max(arr[])+1)), where N = size of the array, sum(arr[]) = sum of all array elements, max(arr[]) = maximum of all array elements.
Reason: We are using a loop from max(arr[]) to sum(arr[]) to check all possible values of time. Inside the loop, we are calling the countPartitions() function for each number. Now, inside the countPartitions() function, we are using a loop that runs for N times.

Space Complexity:  O(1) as we are not using any extra space to solve this problem.


Optimal :
Time Complexity: O(N * log(sum(arr[])-max(arr[])+1)), where N = size of the array, sum(arr[]) = sum of all array elements, max(arr[]) = maximum of all array elements.
Reason: We are applying binary search on [max(arr[]), sum(arr[])]. Inside the loop, we are calling the countPartitions() function for the value of ‘mid’. Now, inside the countPartitions() function, we are using a loop that runs for N times.

Space Complexity:  O(1) as we are not using any extra space to solve this problem.
*/


// Brute 
int countPartition(vector<int>&nums,int maxSum){ // this functions helps us in  finding👉 If the largest allowed subarray sum is maxSum, how many partitions will I need?
    int n = nums.size();
    int partitions = 1;
    long long subarray =0;
    for (int i = 0; i < n; i++)
    {
        if(subarray + nums[i]<=maxSum){
            subarray += nums[i];
        } else{
            partitions++;
            subarray = nums[i];


        }
       
    }
    return partitions;
    
}

int split_Array(vector<int>&nums,int k){
    int n = nums.size();
 int low  = *max_element(nums.begin(),nums.end());// low = max_element(a) (because no subarray sum can be less than the largest single element, otherwise you can’t even fit that element)

high = sum of all elements (the case where you don’t cut at all, 1 partition).
 int high = accumulate(nums.begin(),nums.end(),0);
 for(int maxSum = low ; maxSum<=high;maxSum++){
    if(countPartition(nums,maxSum)==k){
         return maxSum;
    }
 }
 return low;
}


// optimal 
int countPartition(vector<int>&nums,int maxSum){
    int n = nums.size();
    int partitions = 1;
    long long subarray =0;
    for (int i = 0; i < n; i++)
    {
        if(subarray + nums[i]<=maxSum){
            subarray += nums[i];
        } else{
            partitions++;
            subarray = nums[i];


        }
       
    }
    return partitions;
    
}

int split_Array(vector<int>&nums,int k){
    int n = nums.size();
 int low  = *max_element(nums.begin(),nums.end());
 int high = accumulate(nums.begin(),nums.end(),0);
 while (low <= high) {
        int mid = (low + high) / 2;
        int partitions = countPartition(nums, mid);
        if (partitions > k) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return low;
}

// Painters Partitions same as split_array  and same time complexity 
int countPainters(vector<int>&boards,int time){
    int n = boards.size();
    int painter = 1;
    long long boardPainter =0;
    for (int i = 0; i < n; i++)
    {
        if(boardPainter + boards[i]<=time){
            boardPainter += boards[i];
        } else{
            painter++;
            boardPainter = boards[i];
        }
       
    }
    return painter;
    
}

int split_Array(vector<int>&boards,int k){
    int n = boards.size();
 int low  = *max_element(boards.begin(),boards.end());
 int high = accumulate(boards.begin(),boards.end(),0);
 while (low <= high) {  // you can do for brute force too 
        int mid = (low + high) / 2;
        int painters = countPainters(boards, mid);
        if (painters > k) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return low;
}
