/*
Problem Statement: Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.
A shift on s consists of moving the leftmost character of s to the rightmost position. For example, if s = "abcde", then it will be "bcdea" after one shift.

Brute :
Time Complexity: O(N^2) since generating N rotations and each comparison takes O(N) time.

Space Complexity: O(N) for the space needed to store each rotated string.

Optimal :
Time Complexity: O(N), because checking for a substring in s + s is linear in time.

Space Complexity: O(N) for the space needed to store the concatenated string s + s.
*/

// Brute 
class Solution {
public:
    bool rotateString(string s, string goal) {
         if(s.length()!=goal.length()) return false;
 for(int i =0;i<s.size();i++){
  string rotated  = s.substr(i) + s.substr(0,i); // this substr(i) means to take from i-> to whole string 
  if(rotated==goal) return true;
 }
 return false;
    }
};

// Optimal
class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length()!=goal.length()) return false;
 string doubled = s+s;
 return doubled.find(goal)!=string::npos; // string::npos is used if output is not found 
    }
};

