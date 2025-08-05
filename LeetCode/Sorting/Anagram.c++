/* 
Q : Check if string s and string t are anagram(means using same words to form another words like live evil)

Brute 
Sorth both then return them 
 Time Complexity:
Sorting: O(n log n)

🧠 Space Complexity:
O(1) if in-place sorting is allowed, otherwise O(n)


Better
Count the frequency of each character in both strings using a map and compare the maps.
⏱ Time Complexity:
O(n)

🧠 Space Complexity:
O(n) (for hash maps)


Optimized

Use a fixed-size array of 26 (for lowercase letters) and increment for s, decrement for t. If all values are zero in the end — it's an anagram.
*/


// brute
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};

// better

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        
        unordered_map<char, int> mp1, mp2;
        
        for (char ch : s) mp1[ch]++;
        for (char ch : t) mp2[ch]++;
        
        return mp1 == mp2;
    }
};

// Optimized

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        int count[26] = {0};

        for(int i =0;i<s.size();i++){
            count[s[i]-'a']++;
            count[t[i]-'a']--;
        }

        for(int i =0;i<26;i++){
            if(count[i]!=0) return false;
        }
        return true;
    }
};
