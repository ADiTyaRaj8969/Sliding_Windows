// Topic: Longest Subarray with Equal 0s and 1s
#include <bits/stdc++.h>
using namespace std;

int findMaxLength(vector<int>& nums)
{
    unordered_map<int, int> first;
    first[0] = -1;
    int sum = 0, res = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        sum += (nums[i] == 1) ? 1 : -1;
        if (first.find(sum) != first.end())
        {
            res = max(res, i - first[sum]);
        }
        else
        {
            first[sum] = i;
        }
    }
    return res;
}

int main()
{
    vector<int> nums = {0, 1, 0, 1, 0, 1, 1};
    cout << "Max length: " << findMaxLength(nums) << '\n';
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n)
