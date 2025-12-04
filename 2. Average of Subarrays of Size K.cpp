// Topic: Average of Subarrays of Size K
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {1, 3, 2, 6, -1, 4, 1, 8, 2};
    int k = 5;
    int n = arr.size();
    double window_sum = 0;
    for (int i = 0; i < k; i++) window_sum += arr[i];
    cout << window_sum / k << '\n';
    for (int i = k; i < n; i++)
    {
        window_sum += arr[i] - arr[i - k];
        cout << window_sum / k << '\n';
    }
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
