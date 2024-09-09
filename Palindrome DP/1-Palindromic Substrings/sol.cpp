#include<iostream>
using namespace std;

// Brute Force 
class Solution
{
    bool isPalindrome(string s, int i, int j)
    {
        while (i <= j)
        {
            if (s[i] != s[j])
            {
                return false;
            }
            i++;
            j--;
        }

        return true;
    }

public:
    int countSubstrings(string s)
    {
        int n = s.length();
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                if (isPalindrome(s, i, j))
                {
                    count++;
                }
            }
        }

        return count;
    }
};


// subproblems handling
class Solution
{
    int t[1001][1001];
    bool isPalindrome(string s, int i, int j)
    {
        if (i > j)
        {
            return true;
        }

        if (t[i][j] != -1)
        {
            return t[i][j];
        }
        if (s[i] == s[j])
        {
            return t[i][j] = isPalindrome(s, i + 1, j - 1);
        }

        return t[i][j] = false;
    }

public:
    int countSubstrings(string s)
    {
        int n = s.length();
        int count = 0;
        memset(t, -1, sizeof(t));
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                if (isPalindrome(s, i, j))
                {
                    count++;
                }
            }
        }

        return count;
    }
};