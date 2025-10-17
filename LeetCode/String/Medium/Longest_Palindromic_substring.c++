/*
Problem Statement: Given a string s, return the longest palindromic substring in s.
Time Complexity: O(N²) For each character, expanding could take up to O(N)

Space Complexity: O(1) No extra space used.
*/


// My code  which is incorrect 

/* bool isPalindrome(string temp){
    int n = temp.size();
    string tempory = temp;
    int reversed = 0;
        while (n > 0) {
        int digit = n % 10;
        reversed = reversed * 10 + digit;
        n /= 10;
    }

    return n == reversed;
}
string function(string s){
    string ans = 0 ;
     for (int i = 0; i < s.size(); i++)
     {
        for (int j = i; j < s.size(); j++)
        {
         string temp = s.substr(i,j);
        }
        
     }   
}
*/

// Correct code
class Solution {
private:
    int expandFromCenter(const string& str, int left, int right) {
        while (left >= 0 && right < str.length() && str[left] == str[right]) {
            left--;
            right++;
        }
        return right - left - 1;  // length of palindrome
    }

public:
    string longestPalindrome(string s) {
        int start = 0, end = 0;

        for (int center = 0; center < s.length(); center++) {
            int lenOdd = expandFromCenter(s, center, center);
            int lenEven = expandFromCenter(s, center, center + 1);
            int maxLen = max(lenOdd, lenEven);

            if (maxLen > end - start) {
                start = center - (maxLen - 1) / 2;
                end = center + maxLen / 2;
            }
        }

        return s.substr(start, end - start + 1);
    }
};
