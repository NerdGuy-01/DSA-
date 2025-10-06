/*
Problem Statement: Given a string s, reverse the words of the string.

Examples:

Example 1:
Input: s=”this is an amazing program”
Output: “program amazing an is this”

Example 2:
Input: s=”This is decent”
Output: “decent is This”

Brute :

*/

// Brute 
class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string str = "";

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                if (!str.empty()) st.push(str);
                str = "";
            } else str += s[i];
        }

        // Push the last word
        if (!str.empty()) st.push(str);

        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
            if (!st.empty()) ans += " "; // add space only if more words left
        }

        return ans;
    }
};

// Optimal 
class Solution {
public:
    string reverseWords(string s) {
        string result;
        int end = s.size();
        
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == ' ') {
                end = i;  // Update end of current word
            } else if (i == 0 || s[i - 1] == ' ') {
                // Found start of a word
                if (!result.empty()) result += " ";
                result += s.substr(i, end - i);
            }
        }
        
        return result;
    }
};
