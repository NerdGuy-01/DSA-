/*
Problem Statement: Given two numbers N and M, find the Nth root of M. The nth root of a number M is defined as a number X when raised to the power N equals M. If the 'nth root is not an integer, return -1.

// Brute 
Linear search but using pow function I got stuck at where should I use pow 
T.C : O(M*log2N); Each pow(i, N) costs O(log N) (because pow uses fast exponentiation internally).
SC = O(1) (constant).
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
