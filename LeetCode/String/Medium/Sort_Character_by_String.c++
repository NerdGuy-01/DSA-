/*
Problem Statement: You are given a string s. Return the array of unique characters, sorted by highest to lowest occurring characters.
If two or more characters have same frequency then arrange them in alphabetic order.
*/

// code 
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for (char ch : s) freq[ch]++;

        vector<pair<char, int>> vec(freq.begin(), freq.end()); // for {{b,1},{a,2}} etc 

        sort(vec.begin(), vec.end(), [](auto &a, auto &b) {
            if (a.second == b.second) return a.first < b.first; // this checks if freq are same then alphabatically
            return a.second > b.second;
        });

        string result;
        for (auto &p : vec)
            result.append(p.second, p.first);

        return result;
    }
}; 


// T.C : O(Nlogn)
// S.C : O(N)
