/* 
Q : return true if an array contains atleast two duplicates otherwise false

my approach using hash just like striver but my code has logic error 

1. Approach : Brute force The brute force approach compares each element with every other element in the array to check for duplicates. If any duplicates are found, it returns true
T.C : O(n^2)  not good for greater arrays

2. Approach : Sorting The sorting approach sorts the array in ascending order and then checks for adjacent elements that are the same. If any duplicates are found, it returns 
T.C : O(n log n)  we can make it better

3. Approach(best): Hash set The hash set approach uses a hash set data structure to store encountered elements. It iterates through the array, checking if an element is already in the set. If so, it returns true. Otherwise, it adds the element to the set
T.C : O(n) 

*/

// 1. Approach 
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] == nums[j])
                    return true;
            }
        }
        return false;
    }
};

// 2. Approach 
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1])
                return true;
        }
        return false;
    }
};

// 3. Approach 
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> map;
        for (int it : nums) {
            if (seen.count(it) > 0)
                return true;
            seen.insert(it);
        }
        return false;
    }
};
