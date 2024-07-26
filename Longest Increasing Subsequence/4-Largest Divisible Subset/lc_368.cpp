#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// recursive solution
class Solution
{
public:
    void generate(int idx, vector<int> &nums, vector<int> &result, vector<int> &temp, int prev)
    {
        if (idx >= nums.size())
        {
            if (temp.size() > result.size())
            {
                result = temp;
            }
            return;
        }

        if (prev == -1 || nums[idx] % prev == 0)
        {
            temp.push_back(nums[idx]);
            generate(idx + 1, nums, result, temp, nums[idx]);
            temp.pop_back();
        }

        generate(idx + 1, nums, result, temp, prev);
    }

    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        sort(begin(nums), end(nums));

        vector<int> result;
        vector<int> temp;
        generate(0, nums, result, temp, -1);

        return result;
    }
};

// bottom-up
class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        // sort, to check only with last elem if divisible or not
        sort(nums.begin(), nums.end());
        int n = nums.size();

        // to store longest subset at idx i
        vector<int> dp(n, 1);
        int maxL = 1;

        // to print longest subset
        vector<int> prev_idx(n, -1);

        // where did we get the largest ans?
        int last_idx = 0;

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] % nums[j] == 0)
                {
                    // adding newest member , update len at dp[i]
                    if (dp[i] < dp[j] + 1)
                    {
                        dp[i] = dp[j] + 1;
                        prev_idx[i] = j;
                    }
                }

                if (dp[i] > maxL)
                {
                    maxL = dp[i];
                    last_idx = i;
                }
            }
        }

        vector<int> result;
        // print result
        while (last_idx != -1)
        {
            result.push_back(nums[last_idx]);
            last_idx = prev_idx[last_idx];
        }

        return result;
    }
};