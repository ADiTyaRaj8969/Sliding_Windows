// Topic: Check if array contains subarray of size K with given sum
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {1, 4, 20, 3, 10, 5};
    int k = 3, target = 33;
    int n = arr.size();
    if (k > n)
    {
        cout << "No" << '\n';
        return 0;
    }
    int s = 0;
    for (int i = 0; i < k; i++) s += arr[i];
    if (s == target)
    {
        cout << "Yes" << '\n';
        return 0;
    }
    for (int i = k; i < n; i++)
    {
        s += arr[i] - arr[i - k];
        if (s == target)
        {
            cout << "Yes" << '\n';
            return 0;
        }
    }
    cout << "No" << '\n';
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
