#include<iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int nthUglyNumber(int n)
    {
        vector<int> arr(n + 1);

        arr[1] = 1;

        int p2 = 1;
        int p3 = 1;
        int p5 = 1;

        for (int i = 2; i <= n; i++)
        {
            int p2uglyNum = arr[p2] * 2;
            int p3uglyNum = arr[p3] * 3;
            int p5uglyNum = arr[p5] * 5;

            int minUgly = min({p2uglyNum, p3uglyNum, p5uglyNum});

            arr[i] = minUgly;

            if (p2uglyNum == minUgly)
                p2++;
            if (p3uglyNum == minUgly)
                p3++;
            if (p5uglyNum == minUgly)
                p5++;
        }

        return arr[n];
    }
};