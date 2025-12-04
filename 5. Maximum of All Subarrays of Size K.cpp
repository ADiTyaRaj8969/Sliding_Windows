// Topic: Maximum of All Subarrays of Size K
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3, n = arr.size();
    deque<int> dq;
    for (int i = 0; i < n; i++)
    {
        while (!dq.empty() && dq.front() <= i - k) dq.pop_front();
        while (!dq.empty() && arr[dq.back()] <= arr[i]) dq.pop_back();
        dq.push_back(i);
        if (i >= k - 1)
            cout << arr[dq.front()] << ' ';
    }
    cout << '\n';
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(k)
