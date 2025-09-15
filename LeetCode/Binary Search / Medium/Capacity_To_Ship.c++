/*
Problem Statement: You are the owner of a Shipment company. You use conveyor belts to ship packages from one port to another. The packages must be shipped within 'd' days.
The weights of the packages are given in an array 'of weights'. The packages are loaded on the conveyor belts every day in the same order as they appear in the array. The loaded weights must not exceed the maximum weight capacity of the ship.
Find out the least-weight capacity so that you can ship all the packages within 'd' days.

brute :
Using linear search 
Time Complexity: O(N * (sum(weights[]) - max(weights[]) + 1)), where sum(weights[]) = summation of all the weights, max(weights[]) = maximum of all the weights, N = size of the weights array.
Reason: We are using a loop from max(weights[]) to sum(weights[]) to check all possible weights. Inside the loop, we are calling findDays() function for each weight. Now, inside the findDays() function, we are using a loop that runs for N times.

Optimal :
Time Complexity: O(N * log(sum(weights[]) - max(weights[]) + 1)), where sum(weights[]) = summation of all the weights, max(weights[]) = maximum of all the weights, N = size of the weights array.
Reason: We are applying binary search on the range [max(weights[]), sum(weights[])]. For every possible answer ‘mid’, we are calling findDays() function. Now, inside the findDays() function, we are using a loop that runs for N times.

Space Complexity: O(1) as we are not using any extra space to solve this problem.
*/

// Brute 
int findDays(vector<int>weights,int cap){
    int days =1;
    int load =0;
    int n = weights.size();
    for (int i = 0; i < n; i++)
    {
         if(load+weights[i]>cap){
             days+=1;
             load = weights[i];
         } else{
            load+=weights[i];
         }
    }
     return days;
}

int leastweightDays(vector<int>&weights,int days){
     int maxi = *max_element(weights.begin(), weights.end());
        int sum = accumulate(weights.begin(), weights.end(), 0);
        for(int i= maxi;i<=sum;i++){
            if(findDays(weights,i)<=days){
               return i;
            }
        }
        return -1;
}

// Optimal 
int findDays(vector<int>weights,int cap){
    int days =1;
    int load =0;
    int n = weights.size();
    for (int i = 0; i < n; i++)
    {
         if(load+weights[i]>cap){
             days+=1;
             load = weights[i];
         } else{
            load+=weights[i];
         }
    }
     return days;
}

int leastweightDays(vector<int>&weights,int days){
       int low = *max_element(weights.begin(), weights.end());
    int high = accumulate(weights.begin(), weights.end(), 0);
    while (low <= high) {
        int mid = (low + high) / 2;
        int numberOfDays = findDays(weights, mid);
        if (numberOfDays <= days) {
            //eliminate right half
            high = mid - 1;
        }
        else {
            //eliminate left half
            low = mid + 1;
        }
    }
    return low;
}
