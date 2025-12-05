// Topic: Sliding Window Median (two heaps)
// Note: Full robust implementation requires lazy deletions; this is a concise demo.
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    multiset<int> lo, hi;  // lo max half, hi min half
    for (int i = 0; i < nums.size(); i++)
    {
        if (lo.empty() || nums[i] <= *prev(lo.end()))
            lo.insert(nums[i]);
        else
            hi.insert(nums[i]);
        // rebalance
        while (lo.size() > hi.size() + 1)
        {
            hi.insert(*prev(lo.end()));
            lo.erase(prev(lo.end()));
        }
        while (hi.size() > lo.size())
        {
            lo.insert(*hi.begin());
            hi.erase(hi.begin());
        }
        if (i >= k - 1)
        {
            // get median
            double median = (*prev(lo.end()) + *hi.begin()) / 2.0;
            if (hi.empty())
                median = *prev(lo.end());
            cout << median << ' ';
            // remove nums[i-k+1]
            int out = nums[i - k + 1];
            if (lo.find(out) != lo.end())
                lo.erase(lo.find(out));
            else
                hi.erase(hi.find(out));
            while (lo.size() > hi.size() + 1)
            {
                hi.insert(*prev(lo.end()));
                lo.erase(prev(lo.end()));
            }
            while (hi.size() > lo.size())
            {
                lo.insert(*hi.begin());
                hi.erase(hi.begin());
            }
        }
    }
    cout << '\n';
    return 0;
}

// Time Complexity: O(n log k)
// Space Complexity: O(k)
