#include<bits/stdc++.h>
using namespace std;

void bubble_sort(int arr[],int n){    // Not optimized because if the arrays is already is in accending order 
for(int i = n-1;i>=0;i--){
  for(int j=0;j<= i-1;j++){     
    if(arr[j]>a[j+1]){  
      int temp = arr[mini];
    arr[mini ]= arr[i];
    arr[i] = temp;
  }

    }
  }
}

void bubble_sort(int arr[],int n){    // Now optimized 
for(int i = n-1;i>=0;i--){
  int Did_swap = 0;
  for(int j=0;j<= i-1;j++){     
    if(arr[j]>a[j+1]){  
      int temp = arr[mini];
    arr[mini ]= arr[i];
    arr[i] = temp;
      Did_swap = 1;
  }

    }
  if(Did_swap ==0){
    break;
  }
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
