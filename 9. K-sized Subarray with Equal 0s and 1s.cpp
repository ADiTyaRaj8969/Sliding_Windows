// Topic: K-sized Subarray with Equal 0s and 1s
// Description: treat 0 as -1, check if any window of size K sums to 0
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {0, 1, 0, 1, 1, 0, 0, 1};
    int k = 4, n = arr.size();
    vector<int> b(n);
    for (int i = 0; i < n; i++) b[i] = (arr[i] == 0) ? -1 : 1;
    int sum = 0;
    for (int i = 0; i < k; i++) sum += b[i];
    if (sum == 0)
    {
        cout << "Yes" << '\n';
        return 0;
    }
    for (int i = k; i < n; i++)
    {
        sum += b[i] - b[i - k];
        if (sum == 0)
        {
            cout << "Yes" << '\n';
            return 0;
        }
    }
    cout << "No" << '\n';
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n) for transformed array (can be O(1) in-place)
