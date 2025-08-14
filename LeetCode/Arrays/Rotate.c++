/*
Rotate the element array by one array 

Optimal -> For easy questions directly jump to Optimal 

temp = nums[0];
for(int i =1;i<n;i++){

nums[i-1] = nums[i]
}
arr[n-1] = temp;

T.C : O(N);
S.C : O(N); but extra space is O(1)
*/

class Solution {
public:
    void rotateArrayByOne(vector<int>& nums) {
        int n = nums.size();
        int temp = nums[0]; // store first element
        for (int i = 1; i < n; i++) {
            nums[i - 1] = nums[i];
        }
        nums[n - 1] = temp; // put first element at the end
    }
};

