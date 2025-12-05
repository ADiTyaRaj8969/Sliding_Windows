// Topic: Smallest Substring Containing All Characters of Another String
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "ADOBECODEBANC", t = "ABC";
    vector<int> need(128, 0);
    for (char c : t) need[c]++;
    int missing = t.size(), left = 0, start = 0, minLen = INT_MAX;
    for (int right = 0; right < s.size(); right++)
    {
        if (need[s[right]]-- > 0)
            missing--;
        while (missing == 0)
        {
            if (right - left + 1 < minLen)
            {
                minLen = right - left + 1;
                start = left;
            }
            if (++need[s[left++]] > 0)
                missing++;
        }
    }
    cout << (minLen == INT_MAX ? string("") : s.substr(start, minLen)) << '\n';
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
