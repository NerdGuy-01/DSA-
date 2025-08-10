/* 
Q : Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

 A: I couldn't think of anything else 

 Brute force ->  Sort and if first element is equal then sort it and to check overlapping first element is smaller then  last element of  prev pair
T.C : O(N*logN) + O(2*N), where N = the size of the given array.
 O(N), as we are using an answer list to store the merged intervals


 Optimal -> In the previous approach, while checking the intervals, we first selected an interval using a loop and then compared it with others using another loop. But in this approach, we will try to do the same using a single loop. Let’s understand how:

We will start traversing the given array with a single loop. At the first index, as our answer list is empty, we will insert the first element into the answer list. While traversing afterward we can find two different cases:

T.C. : O(N*logN) + O(N), where N = the size of the given array.
 S.C.: O(N)

*/


// Brute
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> result;
        sort(intervals.begin(),intervals.end());
        for(int i =0;i<n;i++){
                 int start = intervals[i][0];
                 int end = intervals[i][1];
                 if(!result.empty()&& end<=result.back()[1]){
                    continue;
                 }

        for(int j =i+1;j<n;j++){
            if(intervals[j][0]<=end){
                end = max(end,intervals[j][1]);
            }
            else{
                break;
            }
        }
       result.push_back({start,end});
        }

        return result;
    }
};


// optimal 
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> result;
        sort(intervals.begin(),intervals.end());
        for(int i =0;i<n;i++){
            if(result.empty()||intervals[i][0]> result.back()[1]){
               result.push_back(intervals[i]);
            }
            else{
                result.back()[1] =  max(result.back()[1],intervals[i][1]);
            }
        }
        

        return result;
    }
};
