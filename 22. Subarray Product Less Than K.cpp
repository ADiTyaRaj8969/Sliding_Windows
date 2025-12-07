// Topic: Subarray Product Less Than K
#include <bits/stdc++.h>
using namespace std;

int numSubarrayProductLessThanK(vector<int>& nums, int k)
{
    if (k <= 1)
        return 0;
    long long prod = 1;
    int left = 0, ans = 0;
    for (int right = 0; right < nums.size(); ++right)
    {
        prod *= nums[right];
        while (prod >= k && left <= right) prod /= nums[left++];
        ans += right - left + 1;
    }
    return ans;
}

int main()
{
    vector<int> nums = {10, 5, 2, 6};
    int k = 100;
    cout << "Count: " << numSubarrayProductLessThanK(nums, k) << '\n';
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
