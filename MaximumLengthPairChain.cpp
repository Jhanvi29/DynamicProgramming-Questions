/* Problem Statement
You are given ‘N’ pairs of integers in which the first number is always smaller than the second number i.e in pair (a,b) -> a < b always. Now we define a pair chain as the continuous arrangement of pairs in which a pair ( c,d ) can follow another pair (a,b) only when b < c.
For example: Given Pairs =  [3,4], [1,2], [2,3]
The length of the maximum chain will be 2. The longest chain is [1,2] -> [3,4] */

#include <bits/stdc++.h> 
using namespace std; 

int maxLengthChain(vector<pair<int, int>> p, int n) {
    sort(p.begin(), p.end());

    // Definition: dp[i] will store the maximum length of chain ending at index i
    // Base case: All the pairs can form chain of length 1
    vector<int> dp(n, 1);

    int maxLength = 1;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            /*
                    If jth pair has its second element less than the first element of our current pair 
                    then we will update our answer for ith pair using the value of jth pair
                 */

            if (p[j].second < p[i].first) {
                dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
        // Keep track of max length so far
        maxLength = max(maxLength, dp[i]);
    }

    return maxLength;
}
