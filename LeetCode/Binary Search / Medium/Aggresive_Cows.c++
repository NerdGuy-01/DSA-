/*
Problem Statement: You are given an array 'arr' of size 'n' which denotes the position of stalls.
You are also given an integer 'k' which denotes the number of aggressive cows.
You are given the task of assigning stalls to 'k' cows such that the minimum distance between any two of them is the maximum possible.
Find the maximum possible minimum distance

These are like this patterns -> min of (max)  or max of (min)

We sorted the arrays because we want minimum and we know that that minimum will always be found between conseticutive numbers 
Brute : we  check linearly 
Time Complexity: O(NlogN) + O(N *(max(stalls[])-min(stalls[]))), where N = size of the array, max(stalls[]) = maximum element in stalls[] array, min(stalls[]) = minimum element in stalls[] array.
Reason: O(NlogN) for sorting the array. We are using a loop from 1 to max(stalls[])-min(stalls[]) to check all possible distances. Inside the loop, we are calling canWePlace() function for each distance. Now, inside the canWePlace() function, we are using a loop that runs for N times.

Space Complexity: O(1) as we are not using any extra space to solve this problem.


Optimal : Using binary search 
Time Complexity: O(NlogN) + O(N * log(max(stalls[])-min(stalls[]))), where N = size of the array, max(stalls[]) = maximum element in stalls[] array, min(stalls[]) = minimum element in stalls[] array.
Reason: O(NlogN) for sorting the array. We are applying binary search on [1, max(stalls[])-min(stalls[])]. Inside the loop, we are calling canWePlace() function for each distance, ‘mid’. Now, inside the canWePlace() function, we are using a loop that runs for N times.

Space Complexity: O(1) as we are not using any extra space to solve this problem.



*/

// Brute 
bool CanwePlace(vector<int>stalls,int dist,int cows){
    int n = stalls.size();
    int countCow = 1;
    int last = stalls[0];
    for(int i =1;i<n;i++){
          if(stalls[i]-last>=dist){
             countCow++;
             last = stalls[i];
          }
          if(countCow>=cows) return true;
    }
    return false;
}

int aggresiveCows(vector<int>&stalls,int k){
  int n = stalls.size();
  sort(stalls.begin(),stalls.end());
  int limit = stalls[n-1]-stalls[0];
  for(int i =1;i<=limit;i++){
    if(CanwePlace(stalls,i,k)==false){
        return (i-1);
    }
  }
 return limit;
}

// Optimal 
bool CanwePlace(vector<int>stalls,int dist,int cows){
    int n = stalls.size();
    int countCow = 1;
    int last = stalls[0];
    for(int i =1;i<n;i++){
          if(stalls[i]-last>=dist){
             countCow++;
             last = stalls[i];
          }
          if(countCow>=cows) return true;
    }
    return false;
}

int aggresiveCows(vector<int>&stalls,int k){
  int n = stalls.size();
  sort(stalls.begin(),stalls.end());
  int low = 0; int high =stalls[n-1] - stalls[0];
  while (low<=high)
  {
   int mid = (low+high)/2;
   if(CanwePlace(stalls,mid,k)==true){
    low = mid+1;
   } else high = mid-1;
  }
  return high ;
}
