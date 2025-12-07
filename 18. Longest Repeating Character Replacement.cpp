// Topic: Longest Repeating Character Replacement
#include <bits/stdc++.h>
using namespace std;

int characterReplacement(string s, int k)
{
    vector<int> count(26, 0);
    int maxf = 0, left = 0, res = 0;
    for (int right = 0; right < s.size(); ++right)
    {
        maxf = max(maxf, ++count[s[right] - 'A']);
        while (right - left + 1 - maxf > k)
        {
            count[s[left] - 'A']--;
            left++;
        }
        res = max(res, right - left + 1);
    }
    return res;
}

int main()
{
    string s = "AABABBA";
    int k = 1;
    cout << "Longest after replacement: " << characterReplacement(s, k) << '\n';
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1) (alphabet size)
