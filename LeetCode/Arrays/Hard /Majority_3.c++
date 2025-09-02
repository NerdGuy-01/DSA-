/*
Problem Statement: Given an array of N integers. Find the elements that appear more than N/3 times in the array. If no such element exists, return an empty vector.

It will store max element 2 and min 0

Brute force : 
Time Complexity: O(N2), where N = size of the given array.
Reason: For every element of the array the inner loop runs for N times. And there are N elements in the array. So, the total time complexity is O(N2).

Space Complexity: O(1) as we are using a list that stores a maximum of 2 elements. The space used is so small that it can be considered constant.

Better : Hashing 
T.C : O(NlogM+M)≈O(NlogN)(worst case)
S.C : O(N)(worst case when all elements are unique

Optimal :
Time Complexity: O(N) + O(N), where N = size of the given array.
Reason: The first O(N) is to calculate the counts and find the expected majority elements. The second one is to check if the calculated elements are the majority ones or not.

Space Complexity: O(1) as we are only using a list that stores a maximum of 2 elements. The space used is so small that it can be considered constant.
*/

// Brute 
 int n = nums.size(); //size of the array
    vector<int> ls; // list of answers

    for (int i = 0; i < n; i++) {
        //selected element is v[i]:
        // Checking if v[i] is not already
        // a part of the answer:
        if (ls.size() == 0 || ls[0] != nums[i]) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                // counting the frequency of v[i]
                if (nums[j] == nums[i]) {
                    cnt++;
                }
            }

            // check if frquency is greater than n/3:
            if (cnt > (n / 3))
                ls.push_back(nums[i]);
        }

        if (ls.size() == 2) break;
    }

    return ls;


// Better 
vector<int> freq(vector<int>&nums,int N){
 map<int,int>mpp;
 vector<int>result;
for(int i = 0 ;i<N; i++){
    mpp[nums[i]]++;
}
for(auto it :mpp){
    if(it.second>(N/3)){
        result.push_back(it.first);
    }
}

return result;
 
}

// Optimal 
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0; int cnt2 = 0;
        int N = nums.size();
int ele1 = INT_MIN;
int ele2 = INT_MIN;
for (int i = 0; i < N; i++)
{
    if(cnt1 ==0 && ele2!=nums[i]){
        cnt1 = 1;
        ele1 = nums[i];
    }
    else if(cnt2 == 0 && ele1!=nums[i]){
        cnt2 = 1;
        ele2 = nums[i];
    }
    else if(nums[i]==ele1)cnt1++;
    else if(nums[i]==ele2)cnt2++;
    else {
        cnt1--; cnt2--;
    }
}
vector<int> ls; // list of answers

    // Manually check if the stored elements in
    // el1 and el2 are the majority elements:
    cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < N; i++) {
        if (nums[i] == ele1) cnt1++;
        if (nums[i] == ele2) cnt2++;
    }

    int mini = int(N / 3) + 1;
    if (cnt1 >= mini) ls.push_back(ele1);
    if (cnt2 >= mini) ls.push_back(ele2);



    return ls;

    }
};
