// Topic: Sum of Elements in Every Window of Size K
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    int k = 3, n = arr.size();
    int sum = 0;
    for (int i = 0; i < k; i++) sum += arr[i];
    cout << sum << ' ';
    for (int i = k; i < n; i++)
    {
        sum += arr[i] - arr[i - k];
        cout << sum << ' ';
    }
    cout << '\n';
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
