#include <iostream>
#include <vector>
using namespace std;

// top down
class Solution
{
    vector<vector<long long>> dp;

public:
    long long Solve(vector<int> &nums, int idx, bool isEven)
    {
        if (idx >= nums.size())
        {
            return 0;
        }

        if (dp[idx][isEven] != -1)
        {
            return dp[idx][isEven];
        }

        int val = nums[idx];

        if (!isEven)
        {
            val = -val;
        }

        long long take = val + Solve(nums, idx + 1, !isEven);
        long long skip = Solve(nums, idx + 1, isEven);

        return dp[idx][isEven] = max(take, skip);
    }

    long long maxAlternatingSum(vector<int> &nums)
    {
        int n = nums.size();
        dp.resize(n, vector<long long>(2, -1));

        return Solve(nums, 0, true);
    }
};

// bottom-up
class Solution
{
public:
    long long maxAlternatingSum(vector<int> &nums)
    {
        int n = nums.size();

        vector<vector<long long>> dp(n + 1, vector<long long>(2, 0));

        for (int i = 1; i < n + 1; i++)
        {
            // even
            dp[i][0] = max(dp[i - 1][1] - nums[i - 1], dp[i - 1][0]);

            // odd
            dp[i][1] = max(dp[i - 1][0] + nums[i - 1], dp[i - 1][1]);
        }

        return max(dp[n][0], dp[n][1]);
    }
};