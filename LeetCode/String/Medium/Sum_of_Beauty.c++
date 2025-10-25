/*
Problem Statement: The beauty of a string is defined as the difference between the frequency of the most frequent character and the least frequent character (excluding characters that do not appear) in that string.

Given a string s, return the sum of beauty values of all possible substrings of s.

 

*/

// my code 
class Solution {
public:
    int beautySum(string s) {
        int freq[26] = {0};
        int result;
        for(char ch:s) freq[ch-'a']++;
        int maxi = INT_MIN;
        int mini = INT_MAX;
        for(int i= 0;i<s.size();i++){
            if(maxi>freq[i-'a']){
                maxi = freq[i-'a'];
            }
            if(mini<freq[i-'a']){
                mini = freq[i-'a'];
            }
        }
             result = (maxi-mini);
        return result;
        
        
    }
};
 // key wrong mistakes are first the question is asking for maximum frequency  of substring  not for a single one 


// brute force similar to my code    T.C = O(n2)
class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int totalBeauty = 0;

        for (int i = 0; i < n; i++) {
            int freq[26] = {0};
            for (int j = i; j < n; j++) {
                freq[s[j] - 'a']++;
                int maxi = INT_MIN, mini = INT_MAX;
                for (int k = 0; k < 26; k++) {
                    if (freq[k] > 0) {
                        maxi = max(maxi, freq[k]);
                        mini = min(mini, freq[k]);
                    }
                }
                totalBeauty += (maxi - mini);
            }
        }
        return totalBeauty;
    }
};

// Better  T.C : O(N) and SC : O(N)
class Solution {
public:
    int beautySum(string s) {
       int  n = s.size();
        int  sum = 0;
        for(int i =0;i<n;i++){
            unordered_map<int,int>freq;
            for(int  j = i ;j<n;j++){
                freq[s[j]]++;
                int maxi = INT_MIN;
                int mini = INT_MAX;

                for(auto it :freq){
                    mini = min(mini,it.second);
                    maxi = max(maxi,it.second);
                }
                sum+= (maxi-mini);
            }
            
        }
        return sum;
    }
};

