#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    int minInsertions(int arr[], int N)

    {

        // Your code goes here

        vector<int> dp(N + 1);

        dp[0] = 1;

        for (int i = 1; i <= N; i++)
        {

            dp[i] = 1;

            for (int j = 0; j < i; j++)
            {

                if (arr[i] >= arr[j])
                {

                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        int rem = *max_element(dp.begin(),dp.end());

        return N - rem;
    }
};