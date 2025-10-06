/*
Problem Statement: A valid parentheses string is defined by the following rules:

It is the empty string "".
If A is a valid parentheses string, then so is "(" + A + ")".
If A and B are valid parentheses strings, then A + B is also valid.

A primitive valid parentheses string is a non-empty valid string that cannot be split into two or more non-empty valid parentheses strings.

Given a valid parentheses string s, your task is to remove the outermost parentheses from every primitive component of s and return the resulting string.


Initialize an empty result string to store the processed output
Initialize a counter (level) to track the depth of parentheses
Traverse through the string character by character:
If the current character is '(', increment the level counter. If the level is greater than 1 (indicating we're inside a valid primitive), add '(' to the result string
If the current character is ')', decrement the level counter. If the level is greater than 0 (indicating we're still inside a valid primitive), add ')' to the result string
After the entire string has been traversed, return the result string
Time Complexity: O(n), since we are performing a single traversal of the string.

Space Complexity: O(1), since we are using a few variables to track the current state.
*/

// code 
class Solution {
public:
    string removeOuterParentheses(string s) {
        string result ="";
  int level  = 0;
  for(char ch:s){
    if(ch=='('){
        if(level>0) result+=ch;
        level++;
    }
     else if(ch==')'){
        level--;
        if(level>0) result+=ch;
     }
  }
 return result;
    }
};
