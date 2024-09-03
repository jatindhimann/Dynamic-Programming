// lcs variant - https://www.geeksforgeeks.org/problems/minimum-number-of-deletions-and-insertions0209/1
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
    int LCS(const string &s1, const string &s2)
    {
        int m = s1.length();
        int n = s2.length();
        vector<vector<int>> t(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (s1[i - 1] == s2[j - 1])
                {
                    t[i][j] = 1 + t[i - 1][j - 1];
                }
                else
                {
                    t[i][j] = max(t[i][j - 1], t[i - 1][j]);
                }
            }
        }

        return t[m][n];
    }

public:
    int minOperations(const string &str1, const string &str2)
    {
        int lcs = LCS(str1, str2);
        int operations = (str1.length() - lcs) + (str2.length() - lcs);
        return operations;
    }
};