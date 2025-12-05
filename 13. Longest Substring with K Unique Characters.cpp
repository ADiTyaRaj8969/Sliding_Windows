// Topic: Longest Substring with K Unique Characters
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "araaci";
    int k = 2;
    unordered_map<char, int> freq;
    int left = 0, maxlen = 0;
    for (int right = 0; right < s.size(); ++right)
    {
        freq[s[right]]++;
        while (freq.size() > k)
        {
            if (--freq[s[left]] == 0)
                freq.erase(s[left]);
            left++;
        }
        maxlen = max(maxlen, right - left + 1);
    }
    cout << "Longest: " << maxlen << '\n';
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(k)
