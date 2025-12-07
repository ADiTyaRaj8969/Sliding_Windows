// Topic: Permutation in String (check if s2 contains permutation of s1)
#include <bits/stdc++.h>
using namespace std;

bool checkInclusion(string s1, string s2)
{
    if (s1.size() > s2.size())
        return false;
    vector<int> cnt1(26, 0), cnt2(26, 0);
    for (int i = 0; i < s1.size(); ++i)
    {
        cnt1[s1[i] - 'a']++;
        cnt2[s2[i] - 'a']++;
    }
    if (cnt1 == cnt2)
        return true;
    for (int i = s1.size(); i < s2.size(); ++i)
    {
        cnt2[s2[i] - 'a']++;
        cnt2[s2[i - s1.size()] - 'a']--;
        if (cnt1 == cnt2)
            return true;
    }
    return false;
}

int main()
{
    string s1 = "ab";
    string s2 = "eidbaooo";
    cout << (checkInclusion(s1, s2) ? "Yes" : "No") << '\n';
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
