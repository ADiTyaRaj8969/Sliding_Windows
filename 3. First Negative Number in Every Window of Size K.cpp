// Topic: First Negative Number in Every Window of Size K
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {12, -1, -7, 8, -15, 30, 16, 28};
    int k = 3;
    deque<int> dq;  // store indices of negative numbers
    int n = arr.size();
    for (int i = 0; i < k; i++)
        if (arr[i] < 0)
            dq.push_back(i);
    for (int i = k; i < n; i++)
    {
        if (!dq.empty())
            cout << arr[dq.front()] << ' ';
        else
            cout << 0 << ' ';
        while (!dq.empty() && dq.front() <= i - k) dq.pop_front();
        if (arr[i] < 0)
            dq.push_back(i);
    }
    if (!dq.empty())
        cout << arr[dq.front()];
    else
        cout << 0;
    cout << '\n';
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(k)
