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

// Optimized Method but oonly for positive when provided 0 and negative this code will fail 
#include<iostream>
using namespace std;

map<long long,int > preSum;
long long sum = 0;
int length = 0;
for(int i =0;i,a.size();i++){
  if(sum ==k){
    length = max(length,i+1);
  }
  long long rem = sum-k;
  if(map.find(rem)!== preSum.end()){
     int length = i-preSum[rem];
     length = max(length,length)
  }
  preSum[sum] = i;

}

// Optimized Method 
#include<iostream>
using namespace std;

map<long long,int > preSum;
long long sum = 0;
int length = 0;
for(int i =0;i,a.size();i++){
  if(sum ==k){
    length = max(length,i+1);
  }
  long long rem = sum-k;
  if(map.find(rem)!== preSum.end()){
     int length = i-preSum[rem];
     length = max(length,length)
  }
 if( preSum[sum] = preSum.end()){ preSum[sum] =  i}

}

// More Optimized 
int main(){
  using namespace std;
  int left = 0,right = 0;
  long long sum = a[0];
  int maxlength = 0;
  int n = a.size();

  while(right<n){
    while( left<=right &&sum>k){
      sum-= a[left];
      left++;
    }
    if(sum==k){
      maxlength = max(maxlength,right-left + 1);
    }
    right++;
   if(right<n) sum+= a[right];
  }
  return maxlength;
}
