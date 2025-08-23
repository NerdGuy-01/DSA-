/*
Problem Statement: You are given an array of ‘N’ integers. You need to find the length of the longest sequence which contains the consecutive elements.

My code : int Sequence(vector<int>nums,int n){
     vector<int> result;
     sort(nums.begin(),nums.end());
   int i = 0;
   int count  =0;
   for(int j= i+1;j<n;j++){
    if(nums[j]-1==nums[i]){
      count++;
    }
   }
}

Brute :  Lets say longest  = 1 cause longest will always be 1 what linear search do is it checks if the num is present in array or not
Time Complexity: O(N2),
Space Complexity: O(1)

Better :  In this solution We will consider 3 variables, 
‘lastSmaller’ →(to store the last included element of the current sequence), 
‘cnt’ → (to store the length of the current sequence), 
‘longest’ → (to store the maximum length).
Initialize ‘lastSmaller’ with ‘INT_MIN’, ‘cnt’ with 0, and ‘longest’ with 1(as the minimum length of the sequence is 1).
*/

// Brute 
bool linearSearch(vector<int>nums,int num){
  int n = nums.size();
  for (int i = 0; i <n; i++)
  {
    if(nums[i]==num) return true;
  }
  return false;
}

int Sequence(vector<int>nums,int n){
 int longest = 1;
 // pick a element and search for its consectuive members
 for(int i =0;i<n;i++){
  int x = nums[i];
 int count=1;

 while(linearSearch(nums,x+1)==true){
  x+=1;
  count+=1;
 }
 longest =  max(longest,count);
 }
cout << longest;
   
}

// Better 
int Sequence(vector<int>nums,int n){
 if(n==0) return 0;
 sort(nums.begin(),nums.end());
 int lastSmaller =  INT_MIN;
 int count  = 0;
 int longest = 1;


 // find longest Sequence:
 for(int i =0;i<n;i++){
  if(nums[i]-1==lastSmaller){
    count+=1;
    lastSmaller =  nums[i];
  } else if(nums[i]!=lastSmaller){
    count = 1;
    lastSmaller =  nums[i];
  }
  longest =  max(longest,count);
 }
 
return longest;
   
}
