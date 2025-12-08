// Topic: Count subarrays with at most K distinct elements
#include <bits/stdc++.h>
using namespace std;

int atMostK(vector<int>& A, int K)
{
    unordered_map<int, int> cnt;
    int left = 0, res = 0;
    for (int right = 0; right < A.size(); ++right)
    {
        if (++cnt[A[right]] == 1)
            ;
        while (cnt.size() > K)
        {
            if (--cnt[A[left]] == 0)
                cnt.erase(A[left]);
            left++;
        }
        res += right - left + 1;
    }
    return res;
}

int main()
{
    vector<int> A = {1, 2, 1};
    int K = 2;
    cout << "AtMostK: " << atMostK(A, K) << '\n';
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(k)
