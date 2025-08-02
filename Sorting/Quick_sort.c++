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

void quick_sort(vector<int>&a,int low,int high){
if(low<high){
int pIndex = partition(a,low,high);
  quick_sort(a,low,pIndex-1);
  quick_sort(a,pIndex+1,high);
}
}
int main(){
vector<int> a = {2,3,6,4,5,1,2,3,6,9,6,3,2,41,25};
  int n = a.size();


  cout << "After Sorting" << endl;
  for(int i =0;i<n;i++){
    cout << a[i] << " ";
  }
}
