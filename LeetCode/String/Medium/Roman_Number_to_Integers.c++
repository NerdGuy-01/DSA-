/*
Problem Statement: Roman numerals are represented by seven different symbols: I = 1, V = 5, X = 10, L = 50, C = 100, D = 500, M = 1000
For example: 2 is written as II, 12 is written as XII, 27 is written as XXVII.
Roman numerals are usually written largest to smallest from left to right. But in six special cases, subtraction is used instead of addition:
I before V or X → 4 and 9,
X before L or C → 40 and 90,
C before D or M → 400 and 900
Given a Roman numeral, convert it to an integer.

Time Complexity: O(n), where n is the length of the input string since we traverse the string once.
Space Complexity: O(1), since we use a fixed-size map for Roman numerals.
*/

// Code
class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
  unordered_map<char,int> roman = {
    {'I', 1}, {'V', 5}, {'X', 10},
            {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
  };

  for(int i =0;i<s.size()-1;i++){ //Understand that Roman numerals are generally written in descending order of value, and their values are added.
    if(roman[s[i]]<roman[s[i+1]]){
      ans -=roman[s[i]]; // when a smaller value appears before a larger one, it indicates subtraction instead of addition
    } else {
      ans +=roman[s[i]];

    }
  }
  return ans + roman[s.back()]; //The final character is always added since there's nothing after it to compare.
    }
};
