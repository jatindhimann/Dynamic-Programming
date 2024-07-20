#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int findLongestChain(vector<vector<int>> &pairs)
    {
        // we can select pairs in any order
        sort(pairs.begin(), pairs.end());

        int len = 1;
        vector<int> dp(pairs.size(), 1);

        for (int i = 0; i < pairs.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (pairs[j][1] < pairs[i][0])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                    len = max(len, dp[i]);
                }
            }
        }

        return len;
    }
};