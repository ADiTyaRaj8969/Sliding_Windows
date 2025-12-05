// Topic: Number of subarrays with sum = goal (binary array)
#include <bits/stdc++.h>
using namespace std;

int numSubarraysWithSum(vector<int>& A, int S)
{
    unordered_map<int, int> cnt;
    cnt[0] = 1;
    int prefix = 0, ans = 0;
    for (int x : A)
    {
        prefix += x;
        if (cnt.count(prefix - S))
            ans += cnt[prefix - S];
        cnt[prefix]++;
    }
    return ans;
}

int main()
{
    vector<int> A = {1, 0, 1, 0, 1};
    int S = 2;
    cout << "Count: " << numSubarraysWithSum(A, S) << '\n';
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n)
