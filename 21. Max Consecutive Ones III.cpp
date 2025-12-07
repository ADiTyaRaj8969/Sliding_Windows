// Topic: Max Consecutive Ones III
#include <bits/stdc++.h>
using namespace std;

int longestOnes(vector<int>& A, int K)
{
    int left = 0, zeros = 0, res = 0;
    for (int right = 0; right < A.size(); ++right)
    {
        if (A[right] == 0)
            zeros++;
        while (zeros > K)
        {
            if (A[left] == 0)
                zeros--;
            left++;
        }
        res = max(res, right - left + 1);
    }
    return res;
}

int main()
{
    vector<int> A = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int K = 2;
    cout << "Max consecutive ones: " << longestOnes(A, K) << '\n';
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
