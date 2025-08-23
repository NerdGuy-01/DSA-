/*
Problem Statement : : Given an array, print all the elements which are leaders. A Leader is an element that is greater than all of the elements on its right side in the array.

My code : void Leader(vector<int>&array,int n){
    vector<int>result;
   for (int i = 0; i < n; i++)
   {
  
    for(int j=i+1;j<n;j++){
         if(array[j]>array[i]){
          result.push_back(array[j]);
          break;
         } 
    }
   }
for(int i =0;i<n;i++){
  cout << result[i];
}
}

Brute : almost same my logic
Time Complexity: O(N^2,
Space Complexity: O(N)

*/

// Brute 
vector<int> Leader(vector<int>&array,int n){
    vector<int>result;
   for (int i = 0; i < n; i++)
   {
   bool leader = true;
    for(int j=i+1;j<n;j++){
         if(array[j]>array[i]){
         // If any element is greater than current element then current element is not leader
         leader = false;
         break;
         } 
        }
        if(leader) result.push_back(array[i]);
   }
return result;
}
