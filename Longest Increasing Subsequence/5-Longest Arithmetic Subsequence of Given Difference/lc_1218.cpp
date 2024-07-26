#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// recursive + memo
class Solution
{
    int solve(vector<int> &arr, int idx, int difference, int prev, vector<vector<int>> &dp)
    {
        if (idx >= arr.size())
        {
            return 0;
        }

        if (dp[prev + 1][idx] != -1)
        {
            return dp[prev + 1][idx];
        }

        int take = 0;
        if (prev == -1 || (arr[idx] - arr[prev]) == difference)
        {
            take = 1 + solve(arr, idx + 1, difference, idx, dp);
        }

        int skip = solve(arr, idx + 1, difference, prev, dp);

        return dp[prev + 1][idx] = max(take, skip);
    }

public:
    int longestSubsequence(vector<int> &arr, int difference)
    {
        // LIS
        vector<vector<int>> dp(arr.size() + 1, vector<int>(arr.size() + 1, -1));

        return solve(arr, 0, difference, -1, dp);
    }
};

// bottom - up (TLE)
class Solution
{
public:
    int longestSubsequence(vector<int> &nums, int difference)
    {
        // LIS
        int len = 1;
        vector<int> dp(nums.size(), 1);

        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] - nums[j] == difference)
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                    len = max(len, dp[i]);
                }
            }
        }

        return len;
    }
};

// most optimal one
class Solution
{
public:
    int longestSubsequence(vector<int> &arr, int difference)
    {
        unordered_map<int, int> mp; // prev <-> len
        int n = arr.size();

        int result = 0;

        for (int i = 0; i < n; i++)
        {
            // for any elem to be added to subsequence arr[i] - diff should be present previously
            // we can use map to check if arr[i] - difference is been encountered earlier
            int prev = arr[i] - difference;

            int lengt_till_prev = mp[prev];

            mp[arr[i]] = lengt_till_prev + 1;

            result = max(result, mp[arr[i]]);
        }

        return result;
    }
};