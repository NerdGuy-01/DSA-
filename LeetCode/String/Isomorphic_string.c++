/*
Problem Statement: Given two strings s and t, determine if they are isomorphic. Two strings s and t are isomorphic if the characters in s can be replaced to get t.
All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself

We will be using two integer arrays (m1 and m2) of size 256 (enough for all ASCII characters).
Each array keeps track of the last index where a particular character appeared — but with a twist:

You store i + 1 instead of just i
(because default 0 means “never seen before,” and we can’t use 0 as a valid index).

Time Complexity: O(N) where N is the length of the input strings, due to the single loop iterating through each character.

Space Complexity: O(1) since the space used by the arrays is constant (256 fixed size) regardless of input size
*/

// Code
class Solution {
public:
    bool isIsomorphic(string s, string t) {
            // Arrays to store last seen positions of characters in s and t
          int m1[256] = {0}, m2[256] = {0}; 
          
          // Get the length of the strings
          int n = s.size(); 
          
          // Traverse each character of the strings
          for (int i = 0; i < n; ++i) {
              // If previous positions of current characters differ, return false
              if (m1[s[i]] != m2[t[i]]) return false;
              
              // Update the position with current index + 1
              m1[s[i]] = i + 1;
              m2[t[i]] = i + 1;
          }
          
          // If no mismatch is found, return true
          return true;
    }
};
