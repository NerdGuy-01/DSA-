/*
Problem Statement: Given an input string, containing upper-case and lower-case letters, digits, and spaces( ' ' ). A word is defined as a sequence of non-space characters. The words in s are separated by at least one space.

Return a string with the words in reverse order, concatenated by a single space.


*/

// my code which is incorrect as  it reverse the whole string 
class Solution {
public:
    string reverseWords(string s) {
     int n = s.size();
        string result  = "";
        int k = n-1;
        while(k>=0){
            result.push_back(s[k]);
            k--;
        }
        return result;
    }
};

// Brute force  T.C.: O(N) and S.C :O(N)
class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        vector<string>word;
        int start , end;
        int i =0;
        while(i<n){
            while(i<n && s[i]==' ')i++;
            if(i>=n) break;

            start = i;
            while(i<n && s[i]!=' ') i++;
            end = i-1;
            string wordFount  = s.substr(start,end-start+1);
            word.push_back(wordFount);
        }
        string ans = "";
        for(int i = word.size() - 1; i >= 0; i--) {
            ans += word[i];
            
            // Adding spaces in between words
            if(i != 0) ans.push_back(' ');
        }
        
        return ans; 
        
    }
};

// optimal T.C : O(N) and S.C :O(N)
class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int i = 0, j = 0;
        int start, end;

        while (j < n) {
            // Skip spaces
            while (j < n && s[j] == ' ') j++;
            if (j == n) break;

            start = i;

            // Copy the word forward
            while (j < n && s[j] != ' ') {
                s[i++] = s[j++];
            }

            end = i - 1;

            // Reverse the current word
            reverse(s.begin() + start, s.begin() + end + 1);

            // Add a space if more words remain
            if (j < n) s[i++] = ' ';
        }

        // Trim trailing space
        if (i > 0 && s[i - 1] == ' ') i--;

        s.resize(i);
        reverse(s.begin(), s.end());

        return s;
    }
};
