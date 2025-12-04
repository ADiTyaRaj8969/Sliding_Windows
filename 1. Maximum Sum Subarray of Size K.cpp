// Topic: Maximum Sum Subarray of Size K
// Description: Given an array and K, find maximum sum among all contiguous subarrays of length K
// Demo: hardcoded example
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {2, 1, 5, 1, 3, 2};
    int k = 3;
    int n = arr.size();
    if (k > n)
    {
        cout << "Window larger than array\n";
        return 0;
    }
    int max_sum = 0, window_sum = 0;
    for (int i = 0; i < k; i++) window_sum += arr[i];
    max_sum = window_sum;
    for (int i = k; i < n; i++)
    {
        window_sum += arr[i] - arr[i - k];
        max_sum = max(max_sum, window_sum);
    }
    cout << "Max sum of subarray size " << k << " = " << max_sum << '\n';
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
