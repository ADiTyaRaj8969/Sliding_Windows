// Topic: Minimum Window Substring (find smallest window containing all chars of pattern)
#include <bits/stdc++.h>
using namespace std;

string minWindow(string s, string t)
{
    if (t.empty())
        return "";
    vector<int> need(128, 0);
    for (char c : t) need[c]++;
    int required = t.size();
    int left = 0, minLen = INT_MAX, start = 0;
    for (int right = 0; right < s.size(); ++right)
    {
        if (need[s[right]] > 0)
            required--;
        need[s[right]]--;
        while (required == 0)
        {
            if (right - left + 1 < minLen)
            {
                minLen = right - left + 1;
                start = left;
            }
            need[s[left]]++;
            if (need[s[left]] > 0)
                required++;
            left++;
        }
    }
    return minLen == INT_MAX ? "" : s.substr(start, minLen);
}

int main()
{
    string s = "ADOBECODEBANC";
    string t = "ABC";
    cout << "MinWindow: " << minWindow(s, t) << '\n';
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1) (constant-sized freq table)
