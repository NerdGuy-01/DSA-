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
