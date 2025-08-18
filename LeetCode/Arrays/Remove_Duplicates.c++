/*
Remove Duplicates in an array which is definitely sorted
It says Modify array not create a new array
We can use set as it only store unique elements  and where it stops is the size of my array 

Brute force

set<int>set;
index = 0;
for(int i =0;i<n;i++){
st.insert(arr[i]);
}

for(auto it : st){
arr[index] = it;
index++;
}

T.C : O(NlogN+N)
O.C : O(N)


Optimal Solution 
Using Two Pointer  we check what number is different from i and then place the next value in front of i 
 After completion of the loop return i+1, i.e size of the array of unique elements.
 Time Complexity: O(N)

Space Complexity: O(1)


*/
// Optimal 
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i =0;
        for(int j =1;j<nums.size();j++){
            if(nums[i]!=nums[j]){
                nums[i+1] = nums[j];
                i++;
            }
        }
        return (i+1);  // nums or unique elements 
    }
};
