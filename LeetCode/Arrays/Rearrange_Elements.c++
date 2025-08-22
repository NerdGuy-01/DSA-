/*
There’s an array ‘A’ of size ‘N’ with an equal number of positive and negative elements. Without altering the relative order of positive and negative elements, you must return an array of alternately positive and negative values.

Note: Start the array with positive elements.

My code :
int i =0;
int j =1;
while(i<=j){
  if(nums[j]<0){
    nums[i+1] = nums[j];
    nums[j] = nums[i];
    j++;
    i++;
  }
}

for (int i = 0; i <n; i++)
{
  cout << nums[i]<< " ";
}
 which is wrong btw 

 Brute :  Above logic but positive at even index and negative at odd index 
 Time Complexity: O(N+N/2) { O(N) for traversing the array once for segregating positives and negatives and another O(N/2) for adding those elements alternatively to the array, where N = size of the array A}.

Space Complexity:  O(N/2 + N/2) = O(N) { N/2 space required for each of the positive and negative element arrays, where N = size of the array A}.


Better : We can't optimize the storage but can optimize the Time complexity 
We know after the first positive element it will appear after two indexes same for negative 
 Time Complexity: O(N)
Space Complexity:  O(N/2 + N/2) = O(N
*/


// Brute
vector<int> Rearrange(vector<int>&nums, int n){
 vector<int>pos;
 vector<int>neg;
 for(int i =0;i<n;i++){
  if(nums[i]>=0) pos.push_back(nums[i]);
  else neg.push_back(nums[i]);
 }

 for(int i =0;i<n/2;i++){ // n/2 cause we after the n/2 both elements have placed at its place no need to iterate over n 
  nums[2*i] =  pos[i];
  nums[2*i+1] =  neg[i];
 }
 
 return nums;
  
}

// Better 
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
         vector<int> result(n,0);
  int posIndex = 0;
   int negIndex = 1;
   for(int i =0;i<n;i++){
    if(nums[i]<0){
    result[negIndex] =  nums[i];
    negIndex+=2;
    } else{
    result[posIndex] =  nums[i];
    posIndex+=2;
    }
   }
   return result;
    }
};


/* Alterning 
 Imagine if the question says that number are not even like 7, 3 positive and 4 negative elements and now you have to add them up too without alterning the order.  Two cases pos>neg or neg>pos    to solve this fall back to brute force
 T.C :  O(2*N) { The worst case complexity is O(2*N) which is a combination of O(N) of traversing the array to segregate into neg and pos array and O(N) for adding the elements alternatively to the main array}. 
 S.C:O(N/2 + N/2) = O(N)
*/

vector<int> Rearrange(vector<int>&nums, int n){
 vector<int>pos,neg;
 for(int i =0;i<n;i++){
  if(nums[i]>0){
    pos.push_back(nums[i]);
  } else{
    neg.push_back(nums[i]);
  }
 }

 if(pos.size()>neg.size()){
  for(int i =0;i<neg.size();i++){
    nums[2*i] = pos[i];
    nums[2*i+1] =  neg[i];
  }
  int index = neg.size()*2;
  for(int i = neg.size();i<pos.size();i++){
    nums[index] =  pos[i];
    index++;
  }
 } 
 else{
  for(int i =0;i<pos.size();i++){
    nums[2*i] = pos[i];
    nums[2*i+1] =  neg[i];
  }
  int index = pos.size()*2;
  for(int i = pos.size();i<neg.size();i++){
    nums[index] =  neg[i];
    index++;
  }
 }
  return nums;
}
