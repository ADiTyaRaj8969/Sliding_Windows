// Topic: Subarray Sum Equals K (for non-negative / positive numbers)
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {1, 2, 3, 7, 5};
    int K = 12;
    int left = 0, sum = 0;
    for (int right = 0; right < arr.size(); ++right)
    {
        sum += arr[right];
        while (sum > K && left <= right) sum -= arr[left++];
        if (sum == K)
        {
            cout << "Found at " << left << ".." << right << "\n";
            return 0;
        }
    }
    cout << "Not found\n";
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
