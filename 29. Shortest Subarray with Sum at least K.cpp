// Topic: Shortest Subarray with Sum at least K
#include <bits/stdc++.h>
using namespace std;

int shortestSubarray(vector<int>& A, int K)
{
    int n = A.size();
    vector<long long> prefix(n + 1, 0);
    for (int i = 0; i < n; ++i) prefix[i + 1] = prefix[i] + A[i];
    deque<int> dq;
    int res = INT_MAX;
    for (int i = 0; i <= n; ++i)
    {
        while (!dq.empty() && prefix[i] - prefix[dq.front()] >= K)
        {
            res = min(res, i - dq.front());
            dq.pop_front();
        }
        while (!dq.empty() && prefix[i] <= prefix[dq.back()]) dq.pop_back();
        dq.push_back(i);
    }
    return res == INT_MAX ? -1 : res;
}

int main()
{
    vector<int> A = {2, -1, 2};
    int K = 3;
    cout << "Min length: " << shortestSubarray(A, K) << '\n';
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n)
