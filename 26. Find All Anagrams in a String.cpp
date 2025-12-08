// Topic: Find All Anagrams in a String
#include <bits/stdc++.h>
using namespace std;

vector<int> findAnagrams(string s, string p)
{
    vector<int> res;
    if (p.size() > s.size())
        return res;
    vector<int> cnt1(26, 0), cnt2(26, 0);
    for (int i = 0; i < p.size(); ++i)
    {
        cnt2[p[i] - 'a']++;
        cnt1[s[i] - 'a']++;
    }
    if (cnt1 == cnt2)
        res.push_back(0);
    for (int i = p.size(); i < s.size(); ++i)
    {
        cnt1[s[i] - 'a']++;
        cnt1[s[i - p.size()] - 'a']--;
        if (cnt1 == cnt2)
            res.push_back(i - p.size() + 1);
    }
    return res;
}

int main()
{
    string s = "cbaebabacd", p = "abc";
    auto idx = findAnagrams(s, p);
    cout << "Indices:";
    for (int i : idx) cout << " " << i;
    cout << '\n';
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
