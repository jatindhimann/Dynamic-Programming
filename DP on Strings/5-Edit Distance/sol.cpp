#include<iostream>
#include <vector>
using namespace std;

// top - down

// traversal from start
class Solution
{
    int t[501][501];
    int solve(string s1, string s2, int i, int j)
    {
        if (j == s2.length())
        {
            return s1.length() - i;
        }

        if (i == s1.length())
        {
            return s2.length() - j;
        }

        if (t[i][j] != -1)
        {
            return t[i][j];
        }

        if (s1[i] == s2[j])
        {
            t[i][j] = solve(s1, s2, i + 1, j + 1);
        }
        else
        {
            t[i][j] = min({1 + solve(s1, s2, i, j + 1), 1 + solve(s1, s2, i + 1, j), 1 + solve(s1, s2, i + 1, j + 1)});
        }

        return t[i][j];
    }

public:
    int minDistance(string word1, string word2)
    {
        memset(t, -1, sizeof(t));
        return solve(word1, word2, 0, 0);
    }
};

// traversal from behind - preferred approach - easy to convert into bottom up
class Solution
{
private:
    int t[501][501];

    int solve(string s1, string s2, int m, int n)
    {
        if (m == 0)
        {
            return n;
        }
        if (n == 0)
        {
            return m;
        }
        if (t[m][n] != -1)
        {
            return t[m][n];
        }
        if (s1[m - 1] == s2[n - 1])
        {
            t[m][n] = solve(s1, s2, m - 1, n - 1);
        }
        else
        {
            t[m][n] = min({1 + solve(s1, s2, m, n - 1), 1 + solve(s1, s2, m - 1, n), 1 + solve(s1, s2, m - 1, n - 1)});
        }
        return t[m][n];
    }

public:
    int minDistance(string word1, string word2)
    {
        int m = word1.length();
        int n = word2.length();
        memset(t, -1, sizeof(t));
        return solve(word1, word2, m, n);
    }
};

// bottom - up

class Solution
{
public:
    int solve(string s1, string s2, int m, int n)
    {
        int t[501][501];

        for (int i = 0; i < m + 1; i++)
        {
            for (int j = 0; j < n + 1; j++)
            {
                if (i == 0 || j == 0)
                    t[i][j] = i + j;
                else if (s1[i - 1] == s2[j - 1])
                    t[i][j] = t[i - 1][j - 1];
                else
                    t[i][j] = 1 + min({t[i][j - 1], t[i - 1][j], t[i - 1][j - 1]});
            }
        }
        return t[m][n];
    }
    int minDistance(string s1, string s2)
    {
        int m = s1.length();
        int n = s2.length();

        return solve(s1, s2, m, n);
    }
};