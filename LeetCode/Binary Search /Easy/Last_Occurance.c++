/*
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

my code :
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
vector<int>result = {-1,-1};
  int low = 0; int high = n-1;
  while(low<=high){
    int mid = low + (high-low)/2;
    if(nums[mid]==target){
        result.push_back(mid);
        low = mid+1;
    } else if(target<nums[mid]){
        high = mid-1;
    }  else if(target>nums[mid]){
        low = mid+1;
    }
    else {
        return result;
    }
  }
  return result;
    }
};

I learned that I am not updating result arrays I am just pushing into elements it will add more rather than updating
Time Complexity (TC): O(log n)

Space Complexity (SC): O(1)
*/

// Correct ans 
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> result(2, -1);

        // first occurrence
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] >= target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
            if (nums[mid] == target) result[0] = mid;
        }

        // last occurrence
        low = 0; high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] <= target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
            if (nums[mid] == target) result[1] = mid;
        }

        return result;
    }
};
