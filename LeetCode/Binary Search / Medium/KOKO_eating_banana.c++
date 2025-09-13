/*
Problem Statement: A monkey is given ‘n’ piles of bananas, whereas the 'ith' pile has ‘a[i]’ bananas. An integer ‘h’ is also given, which denotes the time (in hours) for all the bananas to be eaten.

Each hour, the monkey chooses a non-empty pile of bananas and eats ‘k’ bananas. If the pile contains less than ‘k’ bananas, then the monkey consumes all the bananas and won’t eat any more bananas in that hour.

Find the minimum number of bananas ‘k’ to eat per hour so that the monkey can eat all the bananas within ‘h’ hours.


Brute :
but it will give you Time limit exceeds
Time Complexity: O(max(a[]) * N), where max(a[]) is the maximum element in the array and N = size of the array.
Reason: We are running nested loops. The outer loop runs for max(a[]) times in the worst case and the inner loop runs for N times.

Space Complexity: O(1) as we are not using any extra space to solve this problem.

Optimal :
Using binary Search 
Time Complexity: O(N * log(max(a[]))), where max(a[]) is the maximum element in the array and N = size of the array.
Reason: We are applying Binary search for the range [1, max(a[])], and for every value of ‘mid’, we are traversing the entire array inside the function named calculateTotalHours().

Space Complexity: O(1) as we are not using any extra space to solve this problem.
*/

int findMax(vector<int>&arr){
    int maxInt = INT_MIN;
    int n = arr.size();
        for (int i = 0; i < n; i++) {
        maxInt = max(maxInt, arr[i]);
    }
 return maxInt;
}

int CalculateTotalHours(vector<int>&arr,int hour){
 int totalH = 0;
 int n= arr.size();
 for(int i =0;i<n;i++){
      totalH += ceil((double)(arr[i]) / (double)(hour));
 }
 return totalH;
}

int minimumTimeToEat(vector<int>arr,int h ){
    int maxInt = findMax(arr);
    for (int i = 1; i <= maxInt; i++) {
        int reqTime = CalculateTotalHours(arr, i);
        if (reqTime <= h) {
            return i;
        }
    }
    return maxInt; // dummy statement
}

// optimal 
class Solution {
public:
    int findMax(vector<int>& piles) {
        int maxInt = INT_MIN;
        for (int x : piles) {
            maxInt = max(maxInt, x);
        }
        return maxInt;
    }

    long long CalculateTotalHours(vector<int>& piles, int hour) {
        long long totalH = 0;
        for (int pile : piles) {
            // integer ceil: ceil(pile/hour) = (pile + hour - 1) / hour
            totalH += (pile + hour - 1) / hour;
        }
        return totalH;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = findMax(piles);

        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long totalH = CalculateTotalHours(piles, mid);

            if (totalH <= h) {
                high = mid - 1;  // try smaller speed
            } else {
                low = mid + 1;   // need larger speed
            }
        }
        return low;  // smallest valid eating speed
    }
};
