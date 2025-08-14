/*
Move all Zeros on right side of array 
Brute :
Pick all non zero element and store in temp
T.C.: O(2N)
S.C: extra space is O(x) where is the number of non zeros element and can be O(N);


Better :
Using two Pointer Approach
Swap i and j and j will be always at a zero 
T.C: O(N);
S.C : O(1) not extra space
*/

// brute 
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
       //   step-1
        vector<int> temp;
        for(int i =0;i<n;i++){
             if(nums[i]!=0){
                temp.push_back(nums[i]);
             }
        }
           // step -2 
           int nz = temp.size();
        for(int i =0;i<nz;i++){  
      nums[i]= temp[i];
        }
        // step -3
        for(int i =nz;i<n;i++){ // nz because thats where  the zero elements start indexing
         nums[i] = 0;
        }

    }
};

// optimal 
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int j = 0; // pointer for where the next non-zero should go

        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                swap(nums[i], nums[j]);
                j++;
            }
        }
    }
};

