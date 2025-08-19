/*
Problem Statement: Given an array of integers arr[] and an integer target.

1st variant: Return YES if there exist two numbers such that their sum is equal to the target. Otherwise, return NO.

2nd variant: Return indices of the two numbers such that their sum is equal to the target. Otherwise, we will return {-1, -1}.

Idea we can do this too  return {"Yes", {i, j}}; but then we have to make it pair<string, vector<int>>


 Brute (think by me)
check both elements but in Striver its maintained to be two functions 
T.C : O(N^2)
S.C: O(1);

Better : Use hashmaps if we do target-num = second_number if the second number exist then yes it is a pair otherwise its not
we are storing because ->If that element does not exist, then we will just store the current element in the hashMap along with its index. Because in the future, the current element might be a part of our answer. It's like sayinig “Hey map, remember that this number appears at this index, in case I need it later.

T.C. :O(N)
S.C : O(N)

Optimal : Not so optimal we use two pointers 
and if we sort the array then we loose  the indexes 
T.C. : O(N) + O(N*logN), 
Space Complexity: O(1)
*/


// Brute 
pair<string, vector<int>> two_Sum(vector<int>& nums, int target) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i] + nums[j] == target) {
                return {"Yes", {i, j}};
            }
        }
    }
    return {"No", {-1, -1}};
}

// Better

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int>result;
        for(int i =0;i<n;i++){
            int num = nums[i];
            int second_num = target-num;
            if(result.find(second_num)!=result.end()){
                return {result[second_num],i};
            }
            result[num] = i;
        }
        return {-1,-1};
    }
};

// Optimal 

vector<int> two_Sum(vector<int> nums, int target) {
    int n = nums.size();
    sort(nums.begin(), nums.end());  // works but loses original indices
    int left = 0, right = n - 1;

    while (left < right) {
        int sum = nums[left] + nums[right];
        if (sum == target) {
            return {nums[left], nums[right]}; // returns numbers, not indices
        }
        else if (sum < target) left++;
        else right--;
    }
    return {-1, -1};
}
