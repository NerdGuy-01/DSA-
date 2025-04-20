#include<bits/stdc++.h>
using namespace std;


void ms(vector<int> &arr,int low,int high){
    if(low==high) return;
    int middle = (low + high)/2;
    ms(arr,low,mid);
    ms(arr,mid+1,high);
    merge(arr,low,mid,high);
  }

void merge(vector<int>&arr,int low,int mid,int high){
  vector<int> temp;
  int left = low;
  int right = mid+1;

   while(left<=mid && right<=high){
    if(arr[left]<=arr[right]){
      temp.push_back(arr[left]);
      left++;
    }
    else{
      temp.push_back(arr[right]);
      right++;
    }
   }

   while(left<=mid){
    temp.push_back(arr[left]);
      left++;
   }
   while(right<=high){
      temp.push_back(arr[right]);
      right++;
   }

   for(int i =low=;i<=high;i++){
    arr[i] = temp[i-low]
   }

}

  

int main(){
   int n;
   cin>>n;
   int arr[n];
   for(int i =0;i<n;i++){
  cin>>arr[i];
   }
   selection_sort(arr,n);
   for(int i =0;i<n;i++){
    cout << arr[i] << " ";
   }
}
