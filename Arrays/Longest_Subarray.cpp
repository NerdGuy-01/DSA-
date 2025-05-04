// Brute force 
#include<iostream>
using namespace std;

for(int i=0;i<n;i++)[
  s=0;
  for(int j=i;j<n;j++){
    for(k=i;i<j;i++){
      s+=a[k];
      if(s==k) length = MAX(len,j-i-1);
    }
  }
]
cout<<length;

// But we can Optimize it by adding only the New ELement from the perious one 
#include<iostream>
using namespace std;

for(int i=0;i<n;i++)[
  for(int j=i;j<n;j++){
   s+=a[j];

   if(s==k) length = MAX(length,j-i-1)
  }
]
cout<<length;
