#include<bits/stdc++.h>
using namespace std;

void partition(vector<int>&a,int low,int high){
  int pivot = a[low]
int i=low;
  int j = high;

  while(i<j){
    while(a[i]<=pivot && i<=high-1){
      i++;
  }

    while(a[j]>pivot && low+1){}
    j--;
}
if(i<j) swap(a[i],a[j]);
}
swap(a[low],a[j]);
return j;
}
int main(){
vector<int> a = {2,3,6,4,5,1,2,3,6,9,6,3,2,41,25};
  int n = a.size();
  
}
