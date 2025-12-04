// Topic: Count Occurrences of Anagrams
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "cbaebabacd";
    string p = "abc";
    int n = s.size(), m = p.size();
    if (m > n)
    {
        cout << 0 << "\n";
        return 0;
    }
    vector<int> ps(26, 0), ws(26, 0);
    for (char c : p) ps[c - 'a']++;
    for (int i = 0; i < m; i++) ws[s[i] - 'a']++;
    int count = 0;
    if (ps == ws)
        count++;
    for (int i = m; i < n; i++)
    {
        ws[s[i] - 'a']++;
        ws[s[i - m] - 'a']--;
        if (ps == ws)
            count++;
    }
    cout << "Anagram occurrences: " << count << '\n';
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(26) ~ O(1)
