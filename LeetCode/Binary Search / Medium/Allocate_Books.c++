/*
Time Complexity: O(NlogN) + O(N * log(max(stalls[])-min(stalls[]))), where N = size of the array, max(stalls[]) = maximum element in stalls[] array, min(stalls[]) = minimum element in stalls[] array.
Reason: O(NlogN) for sorting the array. We are applying binary search on [1, max(stalls[])-min(stalls[])]. Inside the loop, we are calling canWePlace() function for each distance, ‘mid’. Now, inside the canWePlace() function, we are using a loop that runs for N times.

Space Complexity: O(1) as we are not using any extra space to solve this problem.

Brute force :
Using linear search 
Time Complexity: O(N * (sum(arr[])-max(arr[])+1)), where N = size of the array, sum(arr[]) = sum of all array elements, max(arr[]) = maximum of all array elements.
Reason: We are using a loop from max(arr[]) to sum(arr[]) to check all possible numbers of pages. Inside the loop, we are calling the countStudents() function for each number. Now, inside the countStudents() function, we are using a loop that runs for N times.

Space Complexity:  O(1) as we are not using any extra space to solve this problem.

Optimal :
Using binary search
Time Complexity: O(N * log(sum(arr[])-max(arr[])+1)), where N = size of the array, sum(arr[]) = sum of all array elements, max(arr[]) = maximum of all array elements.
Reason: We are applying binary search on [max(arr[]), sum(arr[])]. Inside the loop, we are calling the countStudents() function for the value of ‘mid’. Now, inside the countStudents() function, we are using a loop that runs for N times.

Space Complexity:  O(1) as we are not using any extra space to solve this problem.
*/

// Brute 
int CountStudents(vector<int>&nums,int pages ){
 int n = nums.size();
 int student = 1;
 long long pagesStudent = 0;
 for(int i =0;i<n;i++){
    if(pages + nums[i]<= pages){
        pagesStudent += nums[i];
    } else {
        student++;
        pagesStudent = nums[i];
    }
 }
 return student;

}

int findPages(vector<int>&nums,int n , int m){
    if(m>n) return -1;
    int low = *max_element(nums.begin(),nums.end());
    int high = accumulate(nums.begin(),nums.end(),0);
    for(int pages = low ;pages<=high;pages++){
 if (CountStudents(nums, pages) == m) {
            return pages;
        }

    }
    return low;
}

// Optimal 
int CountStudents(vector<int>&nums,int pages ){
 int n = nums.size();
 int student = 1;
 long long pagesStudent = 0;
 for(int i =0;i<n;i++){
    if(pages + nums[i]<= pages){
        pagesStudent += nums[i];
    } else {
        student++;
        pagesStudent = nums[i];
    }
 }
 return student;

}

int findPages(vector<int>&nums,int n , int m){
    if(m>n) return -1;
    int low = *max_element(nums.begin(),nums.end());
    int high = accumulate(nums.begin(),nums.end(),0);
       while (low <= high) {
        int mid = (low + high) / 2;
        int students = CountStudents(nums, mid);
        if (students > m) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return low;

  
}
