/*
Problem Statement: Given a valid parentheses string s, return the nesting depth of s. The nesting depth is the maximum number of nested parentheses.
*/

// My-Code, Didn't work as it only give us the total balance, it only tells you how many brackets remained open at the end.
int ParanthesisDepth(string s ){
  int ans =0;
  for(char x : s){
    if(x=='('){
      ans++;
    } else if (x==')'){
       ans--;
    }
  }
  return ans;
}

// Real Solution 
class Solution {
public:
    int maxDepth(string s) {
        int ans =0;
        int current = 0;
  for(char x : s){
    if(x=='('){
      current++;
    } else if (x==')'){
       current--;
    }
    ans = max(ans,current);
  }
  return ans;
    }
};
