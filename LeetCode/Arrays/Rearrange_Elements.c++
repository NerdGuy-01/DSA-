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


Better :

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
