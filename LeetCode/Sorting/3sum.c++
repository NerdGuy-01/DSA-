/* 
Q :Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

A : my Approach  in my previous problom of duplicates i used in this, for ex the question says to not return duplicate so I do this and then I compare both the values like numi  should not be equal to j and  k cause if they do their sums will not be 0 int

my code :  which is totally wrong ❎
int three_sum(vector<int>&nums){
 unordered_set<int>mpp;;
 for(auto it: nums){
   if(mpp.count(it)>0) return 0 ;
   else mpp.insert(it);
 }
 for(int i =0;i<nums.size();i++){
   for(int j =i+1;j<nums.size()-1;j++){
      for(int k = i+2;k<nums.size()-2;j++){
         if(nums[i]==nums[j] && nums[j]==nums[k]) continue;
         if(nums[i]+nums[j]+nums[k]==0){
         }
          return i,j,k;
      }
   }
 }
 
}

Real Answer : Striver Solution
   Brute force
   first let i start form zero and j after that and k afer that so then store in it, and to get unique elements after storing them sort them and then compare with other triplets
 T.C:  O(N3 * log(no. of unique triplets)), where N = size of the array



   Better Approach
   get rid of loop k like nums[k] = -(nums[i]+nums[j]) by using hashing but we have to be clear so that we don't choose the current elements in the array for the sum
 T.C.:  O(N2 * log(no. of unique triplets)), where N = size of the array
 There is a reason why we are storing in a new set cause if we do what we did above we will get an runtime Error cause we are setting K equal to value that would make the sum Zero but we are treating it as index.



  Optimal Approach 
 Two pointer approach fix i and then keep moving j,k in order to get 0  and incrementing j and decrementing k and check value if =0 then ok otherwise move j,k
T.C. : O(NlogN)+O(N2), where N = size of the array


 
*/

// brute force 
  vector<vector<int>> triplet(int n, vector<int> &arr) {
    set<vector<int>> st; // store vector of integers

    // check all possible triplets:
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (arr[i] + arr[j] + arr[k] == 0) {
                    vector<int> temp = {arr[i], arr[j], arr[k]};
                    sort(temp.begin(), temp.end()); // sorting so that same numbers but with different order are considere identical
                    st.insert(temp);
                }
            }
        }
    }

    //store the set elements in the answer:
    vector<vector<int>> ans(st.begin(), st.end()); // means storing as a list
    return ans;
}


// Better Approach 
vector<vector<int>> triplet(int n, vector<int> &arr) {
    set<vector<int>> st;

    for (int i = 0; i < n; i++) {
        set<int> hashset; // putting in for loop so that everytime i increments we get a new set
        for (int j = i + 1; j < n; j++) {
            //Calculate the 3rd element:
            int third = -(arr[i] + arr[j]);

            //Find the element in the set:
            if (hashset.find(third) != hashset.end()) {
                vector<int> temp = {arr[i], arr[j], third};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hashset.insert(arr[j]); // also check we insert in it
        }
    }

    //store the set in the answer:
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

// Optimal Approach
vector<vector<int>> triplet(int n, vector<int> &arr) {
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++) {
        //remove duplicates:
        if (i != 0 && arr[i] == arr[i - 1]) continue;

        //moving 2 pointers:
        int j = i + 1;
        int k = n - 1;
        while (j < k) {
            int sum = arr[i] + arr[j] + arr[k];
            if (sum < 0) {
                j++;
            }
            else if (sum > 0) {
                k--;
            }
            else {
                vector<int> temp = {arr[i], arr[j], arr[k]};
                ans.push_back(temp);
                j++;
                k--;
                //skip the duplicates:
                while (j < k && arr[j] == arr[j - 1]) j++;
                while (j < k && arr[k] == arr[k + 1]) k--;
            }
        }
    }
    return ans;
}


