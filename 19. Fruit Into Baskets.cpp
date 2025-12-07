// Topic: Fruit Into Baskets (longest subarray with at most two distinct types)
#include <bits/stdc++.h>
using namespace std;

int totalFruit(vector<int>& fruits)
{
    unordered_map<int, int> cnt;
    int left = 0, res = 0;
    for (int right = 0; right < fruits.size(); ++right)
    {
        cnt[fruits[right]]++;
        while (cnt.size() > 2)
        {
            if (--cnt[fruits[left]] == 0)
                cnt.erase(fruits[left]);
            left++;
        }
        res = max(res, right - left + 1);
    }
    return res;
}

int main()
{
    vector<int> fruits = {1, 2, 1};
    cout << "Max fruits: " << totalFruit(fruits) << '\n';
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1) or O(m) where m distinct types (here ≤ 2)
