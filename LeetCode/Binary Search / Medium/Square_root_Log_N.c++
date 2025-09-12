/*
Problem Statement: You are given a positive integer n. Your task is to find and return its square root. If ‘n’ is not a perfect square, then return the floor value of 'sqrt(n)'.

Note: The question explicitly states that if the given number, n, is not a perfect square, our objective is to find the maximum number, x, such that x squared is less than or equal to n (x*x <= n). In other words, we need to determine the floor value of the square root of n

Brute :
Linear search as we know sqrt is n*n;

Optimal 1 :
Whenever you are given a condition where to a certain point ans is possible and after that ans is not possible always use binary search 
*/

// Brute 
int Floorsqrt(int n){
  int ans =0;
  for(long long i =1;i<=n;i++){
    long long val = i*i;
    if(val<=n){
      ans = i;
    } else  break;
  }
return  ans;
}
