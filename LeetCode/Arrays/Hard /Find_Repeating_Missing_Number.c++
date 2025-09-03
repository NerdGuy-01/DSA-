/*
Problem Statement: You are given a read-only array of N integers with values also in the range [1, N] both inclusive. Each integer appears exactly once except A which appears twice and B which is missing. The task is to find the repeating and missing numbers A and B where A repeats twice and B is missing.

Brute : Using two loops 

Time Complexity: O(N2), where N = size of the given array.
Reason: Here, we are using nested loops to count occurrences of every element between 1 to N.

Space Complexity: O(1) as we are not using any extra space.

Better :
Using Hash maps
Time Complexity: O(2N), where N = the size of the given array.
Reason: We are using two loops each running for N times. So, the time complexity will be O(2N).

Space Complexity: O(N) as we are using a hash array to solve this problem.

Optimal :
Using two equation approach 



*/

// Brute

vector<int> findMissingRepeatingNumbers(vector<int> nums) {
    int n = nums.size(); // size of the array
    int repeating = -1, missing = -1;

    //Find the repeating and missing number:
    for (int i = 1; i <= n; i++) {
        //Count the occurrences:
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (nums[j] == i) cnt++;
        }

        if (cnt == 2) repeating = i;
        else if (cnt == 0) missing = i;

        if (repeating != -1 && missing != -1)
            break;
    }
    return {repeating, missing};
}



// Better 
vector<int>MissingNumber(vector<int>&nums){
    int n = nums.size();
    vector<int>result;
    unordered_map<int,int>mpp;
    for (int i = 0; i < n; i++)
    {
        mpp[nums[i]]++;
    }
     int repeatingNumber = -1; int missingNubmer = -1;
     for(int i =0;i<n;i++){
        if(mpp[i]==2) repeatingNumber = i;
        if(mpp[i]==0) missingNubmer = i;
     }
     result.push_back(missingNubmer);
     result.push_back(missingNubmer);
     return result;

}

// optimal 
explain this code to me vector<int> findMissingRepeatingNumbers(vector<int> nums) {
    long long n = nums.size(); // size of the array

    // Find Sn and S2n:
    long long SN = (n * (n + 1)) / 2; // sum of N natural numbers
    long long S2N = (n * (n + 1) * (2 * n + 1)) / 6; // sum of square of N natural number

    // Calculate S and S2:
    long long S = 0, S2 = 0;
    for (int i = 0; i < n; i++) {
        S += nums[i];
        S2 += (long long)nums[i] * (long long)nums[i];
    }

    //S-Sn = X-Y:
    long long val1 = S - SN;

    // S2-S2n = X^2-Y^2:
    long long val2 = S2 - S2N;

    //Find X+Y = (X^2-Y^2)/(X-Y):
    val2 = val2 / val1; // gives us value of X+Y

    //Find X and Y: X = ((X+Y)+(X-Y))/2 and Y = X-(X-Y),
    // Here, X-Y = val1 and X+Y = val2:
    long long x = (val1 + val2) / 2;
    long long y = x - val1;

    return {(int)x, (int)y};
}
