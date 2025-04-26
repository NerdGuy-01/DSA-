#include<iostream>
using namespace std;
int  main(){
    int n;
  cin >> n;
  int arr[n];
  for(int i =0;i<n;i++){
    cin >> arr[i];
  }
    
  int max = arr[0]; // moved it here now it works because arrays didnn't even get value
    
  for(int i =0;i<n;i++){
     /* if(arr[i+1]>arr[i]){     not a good comparison 
        max  = arr[i];
    } */
     if(arr[i]>max){
    max = arr[i];
  }
  }
 
  cout << "Largest is " <<  max << endl;
}


Second Largest Element


#include<iostream>
using namespace std;
int  main(){
    int n;
  cin >> n;
  int arr[n];
 
  for(int i =0;i<n;i++){
    cin >> arr[i];
  }
   int max = arr[0];
  // int second_max = -arr[0];  because what if the first element is 0 
    int second_max = -1;
  
  for(int i =0;i<n;i++){
     if(arr[i]>max){
    max = arr[i];
  }
  }
  for(int i=0;i<n;i++){
    if(arr[i]>second_max && arr[i] != max){
        second_max = arr[i];

    }
  }
 
  cout << "Largest is " <<  second_max << endl;
}
