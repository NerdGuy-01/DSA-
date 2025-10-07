/*
Problem Statement: Given a string s, representing a large integer, the task is to return the largest-valued odd integer (as a string) that is a substring of the given string s.
The number returned should not have leading zero's. But the given input string may have leading zero.
*/


// First way 
class Solution {
public:
    string largestOddNumber(string num) {
        int index = -1;

        // traverse from end to start to find the last odd digit
        for (int i = num.size() - 1; i >= 0; i--) {
            if ((num[i] - '0') % 2 == 1) {
                index = i;
                break;
            }
        }

        // if no odd digit found, return empty string
        if (index == -1) return "";

        // return substring from 0 to index (inclusive)
        return num.substr(0, index + 1);
    }
};


// second way  a good way to be honest 
class Solution {
public:
    string largestOddNumber(string num) {
        for(int i=num.length()-1;i>=0;i--){
            if(num[i]%2==1){

                return num.substr(0,i+1);
            }
        }
        return "";
    }
};
