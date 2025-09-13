/*
Problem Statement: Given two numbers N and M, find the Nth root of M. The nth root of a number M is defined as a number X when raised to the power N equals M. If the 'nth root is not an integer, return -1.

// Brute 
Linear search but using pow function I got stuck at where should I use pow 
T.C : O(M*log2N); Each pow(i, N) costs O(log N) (because pow uses fast exponentiation internally).
SC = O(1) (constant).

Optimal 
Time Complexity: O(logN), N = size of the given array.
Reason: We are basically using binary search to find the minimum.

Space Complexity: O(1)
Reason: We have not used any extra data structures, this makes space complexity, even in the worst case as O(1).
*/

// Brute 
int NRoot(int N,int M){

 for(int i =0;i<=M;i++){
 long long  ans = pow(i,N);
  if(ans==M) return i;
  else if(ans>M) break;
 }
 return -1;
}

// Optimal 
//return 1, if == m:
//return 0, if < m:
//return 2, if > m:
int func(int mid, int N, int M){ // it finds mid^n
    long long ans = 1;
    for(int i =1;i<=N;i++){
        ans *=mid;
        if(ans >M)return 2;
    }
    if(ans ==M) return 1;
    return 0;
}

int NRoot(int N,int M){
 int low = 1; int high = M;
 while (low<=high)
 {
    int mid  = low + (high-low)/2;
    int midN = func(mid,N,M);
    if(midN ==1) return mid;
     else if(midN ==0) low =  mid+1;
     else high = mid-1;
 }
 return -1;
}
