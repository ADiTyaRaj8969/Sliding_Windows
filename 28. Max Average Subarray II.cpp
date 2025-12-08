// Topic: Max Average Subarray II (find maximum average for subarray length >= k)
#include <bits/stdc++.h>
using namespace std;

bool check(const vector<int>& nums, int k, double mid)
{
    int n = nums.size();
    vector<double> prefix(n + 1, 0);
    for (int i = 0; i < n; ++i) prefix[i + 1] = prefix[i] + nums[i] - mid;
    double min_pref = 0;
    for (int i = k; i <= n; ++i)
    {
        if (prefix[i] - min_pref >= 0)
            return true;
        min_pref = min(min_pref, prefix[i - k + 1]);
    }
    return false;
}

double findMaxAverage(vector<int>& nums, int k)
{
    double low = *min_element(nums.begin(), nums.end());
    double high = *max_element(nums.begin(), nums.end());
    for (int iter = 0; iter < 40; ++iter)
    {
        double mid = (low + high) / 2;
        if (check(nums, k, mid))
            low = mid;
        else
            high = mid;
    }
    return low;
}

int main()
{
    vector<int> nums = {1, 12, -5, -6, 50, 3};
    int k = 4;
    cout.setf(std::ios::fixed);
    cout << setprecision(6);
    cout << "Max avg: " << findMaxAverage(nums, k) << '\n';
    return 0;
}

// Time Complexity: O(n log(range/eps))
// Space Complexity: O(n)
