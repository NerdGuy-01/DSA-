/*
Problem Statement: Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer.
The algorithm for myAtoi(string s) is as follows:
1. Whitespace: Ignore any leading whitespace (" ").
2. Signedness: Determine the sign by checking if the next character is '-' or '+', assuming positivity if neither present.
3. Conversion: Read the integer by skipping leading zeros until a non-digit character is encountered or the end of the string is reached. If no digits were read, then the result is 0.
4. Rounding: If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then round the integer to remain in the range. Specifically, integers less than -231 should be rounded to -231, and integers greater than 231 - 1 should be rounded to 231 - 1.


In simple words this questions wants you to convert string into number but neglecting all zeros leadering and whitespaces

Time Complexity: O(N), where N is the length of the string.

Space Complexity: O(1), as constant space is used.
*/

// Code 
class Solution {
public:
    int myAtoi(string s) {
         int i =0; int sign =1; // index to scan string and assume number be positive 
    long result  = 0;

    while(i<s.size() && s[i]==' ')i++;
    if(i==s.size()) return 0;
    if(s[i]=='-'){
        sign  = -1;
        i++;
    } else if (s[i]=='+'){
        i++;
    }
    while(i<s.size() && isdigit(s[i])){
        result =  result*10  + (s[i] - '0');
        if(sign * result >INT_MAX) return INT_MAX;
        if(sign *result<INT_MIN) return INT_MIN;
    i++;
    }

    return (int)(sign*result);
    }
};
