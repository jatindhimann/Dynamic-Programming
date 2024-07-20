#include <iostream>
#include <vector>
using namespace std;

// top down
class Solution
{
    vector<vector<int>> dp;
    int solve(vector<int> &nums, int prev, int i)
    {
        if (i >= nums.size())
        {
            return 0;
        }

        if (dp[prev + 1][i] != -1)
        {
            return dp[prev + 1][i];
        }

        int take = 0;
        if (prev == -1 || nums[prev] < nums[i])
        {
            take = 1 + solve(nums, i, i + 1);
        }

        int skip = solve(nums, prev, i + 1);

        return dp[prev + 1][i] = max(take, skip);
    }

public:
    int lengthOfLIS(vector<int> &nums)
    {
        dp.resize(nums.size() + 1, vector<int>(nums.size() + 1, -1));
        return solve(nums, -1, 0);
    }
};

// bottom up
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int len = 1;
        vector<int> dp(nums.size(), 1);

        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                    len = max(len, dp[i]);
                }
            }
        }

        return len;
    }
};