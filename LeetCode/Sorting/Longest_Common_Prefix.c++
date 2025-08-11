/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Logic we sort and then check if  first and last string is equal or not 
Before sort: ["flower", "flow", "flight"]
After sort:  ["flight", "flow", "flower"]

The longest common prefix of all strings will be the same as the longest common prefix between:

strs[0] → "flight"

strs[strs.size()-1] → "flower"


*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        string str1 = strs[0];
        string str2 = strs[strs.size() - 1];
        int index = 0;

        while (index < str1.size() && index < str2.size()) {
            if (str1[index] == str2[index]) {
                index++;
            } else {
                break;
            }
        }

        return index == 0 ? "" : str1.substr(0, index);
    }
};
