// Topic: Number of Subarrays with Sum K (general integers)
#include <bits/stdc++.h>
using namespace std;

int subarraySum(vector<int>& nums, int k)
{
    unordered_map<int, int> count;
    count[0] = 1;
    int s = 0, ans = 0;
    for (int x : nums)
    {
        s += x;
        if (count.count(s - k))
            ans += count[s - k];
        count[s]++;
    }
    return ans;
}

int main()
{
    vector<int> nums = {1, 1, 1};
    int k = 2;
    cout << "Count: " << subarraySum(nums, k) << '\n';
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n)
