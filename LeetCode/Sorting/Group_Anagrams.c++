/*
Q: Given an array of strings strs, group the anagrams together. You can return the answer in any order.

Sort karne mein nlogn T.C. lagti hai 

 A: My code
 class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        if(strs.size()==0 && strs.size()==1) return strs[0];
        int count [26] = {0};
        else{
                    for(int i =0;i<strs.size();i++){
                        count[s[i]-'a']++;
                        count[s[i]-'a']--;
                    }
                    for(int i =0;i<25;i++){
                       if(count[i]==0){
                        result.push_back(s[i]);
                       }
                    }

        }
        return strs;
    }
};

Thought process -> sort in accending order then they will be same 
T.C. : N*Klog(K) , K = Maximum number of strings in str


2. Approach 
You create an array a[26] to count frequency of each lowercase letter.

ch - 'a' → converts a character into an index between 0 and 25.
You loop through the word, incrementing the count for each letter.

After counting, you reconstruct a canonical form of the word:

Always sorted alphabetically.

Always contains letters in correct frequency.
map → Key: the canonical form (sorted string). Value: all words matching that form.

result → Final output.
For each string:

Generate its signature (new_word) using generate.

Push it into the map under that signature.
Each entry in map has a vector<string> containing one group of anagrams.

Push all groups into result.



*/

// 1 Approach 
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
     unordered_map<string,vector<string>> map;
     vector<vector<string>> result;
     int n = strs.size();
     for(int i =0;i<n;i++){
        string temp = strs[i];
        sort(temp.begin(),temp.end());
        map[temp].push_back(strs[i]);
     }
     for(auto it:map){
        result.push_back(it.second);
     }
     return result;

    }
};

// 2 Approach
class Solution {
public:

   string generate(string &word){
    int a[26]  = {0};
    for(char &ch:word){
        a[ch-'a']++;
    }
    string new_word = "";
    for(int i =0;i<26;i++){
        int freq = a[i];

        if(freq>0){
            new_word += string(freq,i+'a');
        }

    }
    return new_word;
   }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>map;
        vector<vector<string>> result;
        int n = strs.size();
        for(int i =0;i<n;i++){
        string word = strs[i];
        string new_word = generate(word);
        map[new_word].push_back(word);
        }
        for(auto &it: map){
            result.push_back(it.second);
        }
          return result;
    }
};
