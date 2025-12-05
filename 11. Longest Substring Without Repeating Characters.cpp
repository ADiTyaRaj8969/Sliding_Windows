// Topic: Longest Substring Without Repeating Characters
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "abcabcbb";
    vector<int> last(256, -1);
    int start = 0, maxlen = 0;
    for (int i = 0; i < s.size(); i++)
    {
        start = max(start, last[s[i]] + 1);
        maxlen = max(maxlen, i - start + 1);
        last[s[i]] = i;
    }
    cout << "Longest length: " << maxlen << '\n';
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1) (alphabet size)
