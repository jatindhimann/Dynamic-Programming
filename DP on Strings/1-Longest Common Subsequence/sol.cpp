#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Rec + Memo
class Solution
{
    vector<vector<int>> t;
    int solve(string s1, int i1, string s2, int i2)
    {
        if (i1 == s1.length() || i2 == s2.length())
        {
            return 0;
        }
        if (t[i1][i2] != -1)
        {
            return t[i1][i2];
        }
        if (s1[i1] == s2[i2])
        {
            t[i1][i2] = 1 + solve(s1, i1 + 1, s2, i2 + 1);
        }
        else
        {
            t[i1][i2] = max(solve(s1, i1 + 1, s2, i2), solve(s1, i1, s2, i2 + 1));
        }

        return t[i1][i2];
    }

public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int i1 = 0;
        int i2 = 0;

        t.resize(text1.length() + 1, vector<int>(text2.length(), -1));

        return solve(text1, i1, text2, i2);
    }
};


// Bottom-up

class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int m = text1.length();
        int n = text2.length();

        vector<vector<int>> t(m + 1, vector<int>(n + 1));

        for (int i = 0; i < m + 1; i++)
        {
            for (int j = 0; j < n + 1; j++)
            {
                if (i == 0 || j == 0)
                    t[i][j] = 0;
                else if (text1[i - 1] == text2[j - 1])
                    t[i][j] = 1 + t[i - 1][j - 1];
                else
                    t[i][j] = max(t[i][j - 1], t[i - 1][j]);
            }
        }

        return t[m][n];
    }
};