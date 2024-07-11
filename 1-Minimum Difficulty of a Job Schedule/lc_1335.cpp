#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// asked in amazon
class Solution
{
    int t[301][11];

public:
    int Solve(vector<int> &jobDifficulty, int idx, int d, int n)
    {
        if (d == 1)
        {
            int maxD = INT_MIN;

            for (int i = idx; i < n; i++)
            {
                maxD = max(maxD, jobDifficulty[i]);
            }

            return maxD;
        }

        if (t[idx][d] != -1)
        {
            return t[idx][d];
        }

        int maxD = INT_MIN;
        int finalRes = INT_MAX;

        for (int i = idx; i <= n - d; i++)
        {
            maxD = max(maxD, jobDifficulty[i]);

            int result = maxD + Solve(jobDifficulty, i + 1, d - 1, n);

            finalRes = min(finalRes, result);
        }

        return t[idx][d] = finalRes;
    }
    int minDifficulty(vector<int> &jobDifficulty, int d)
    {
        int n = jobDifficulty.size();

        if (n < d)
        {
            return -1;
        }

        memset(t, -1, sizeof(t));

        return Solve(jobDifficulty, 0, d, n);
    }
};