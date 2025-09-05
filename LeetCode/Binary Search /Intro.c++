
// Iterative method 
int search(vector<int>&nums,int target){
    int n = nums.size();
    int low =0;
    int high = n-1;
    while(low<=high){
        int mid = (low+high)/2;  
    if(nums[mid]==target) return mid;
    else if(target>nums[mid]) low = mid+1;
    else high = mid-1;
    }
    return -1;
}

// Recursive method
int bs(vector<int>&nums,int low,int high,int target){
    if(low>=high) return -1;
    int n = nums.size();
    int mid = (low+high)/2;
    if(nums[mid]==target) return mid;
    else if(target>nums[mid]) return bs(nums,mid+1,high,target);
    return bs(nums,low,high-1,target);
}
 int search(vector<int>&nums,int target){
    return bs(nums,0,nums.size()-1,target);
 }

// TC : O(log2N)

/*
Overflow case : imagine if you have a larger array that goes upto INT_MAX then after doing some calculations the low will also move to some place so when you again do mid  = low+high now both are INT_MAX it will overflow
either use long long or take mid = low + (high-low)/2    
*/
