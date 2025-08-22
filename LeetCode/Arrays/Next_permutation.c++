/*
Problem Statement: Given an array Arr[] of integers, rearrange the numbers of the given array into the lexicographically next greater permutation of numbers.

If such an arrangement is not possible, it must rearrange to the lowest possible order (i.e., sorted in ascending order).

permutations must be in order like 123<132<213<231<312<321 its called lexographical order 

Brute : Generate all possible recursions then linear search and print next index of it , update the code when watched recursion
 Time complexity : O(N!xN).
 Space complexity : O(1).
 
Better :  using STL inbuilt function called next_permutation();

Optimal :  Longer prefix matcher nums[i]<nums[i+1] then find someelement which is >nums but smaller one so that you stay close 
*/

// better
int main() {
    int arr[] = {1,3,2};
    
    next_permutation(arr,arr+3);//using in-built function of C++
    
    cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2];
    
    return 0;
}

// Optimal 
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int breakpoint = -1;

        // Step 1: Find the breakpoint
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                breakpoint = i;
                break;
            }
        }

        // Step 2: If no breakpoint, reverse and return
        if (breakpoint == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Step 3: Find element just larger than nums[breakpoint]
        for (int i = n - 1; i > breakpoint; i--) {
            if (nums[i] > nums[breakpoint]) {
                swap(nums[i], nums[breakpoint]);
                break;
            }
        }

        // Step 4: Reverse the suffix
        reverse(nums.begin() + breakpoint + 1, nums.end());
    }
};



