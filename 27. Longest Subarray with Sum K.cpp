// Topic: Longest Subarray with Sum K (handles negatives)
#include <bits/stdc++.h>
using namespace std;

int longestSubarraySumK(vector<int>& nums, int K)
{
    unordered_map<int, int> first;
    first[0] = -1;
    int sum = 0, res = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        sum += nums[i];
        if (first.find(sum - K) != first.end())
        {
            res = max(res, i - first[sum - K]);
        }
        if (first.find(sum) == first.end())
            first[sum] = i;
    }
    return res;
}

int main()
{
    vector<int> nums = {1, -1, 5, -2, 3};
    int K = 3;
    cout << "Longest length: " << longestSubarraySumK(nums, K) << '\n';
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n)
