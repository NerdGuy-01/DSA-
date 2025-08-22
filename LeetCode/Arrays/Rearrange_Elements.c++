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

 Brute : 
*/
