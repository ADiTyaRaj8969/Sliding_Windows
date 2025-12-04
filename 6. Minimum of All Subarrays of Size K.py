"""
Minimum of All Subarrays of Size K
"""
from collections import deque

def min_of_subarrays(arr, k):
    dq = deque()
    res = []
    for i, val in enumerate(arr):
        while dq and dq[0] <= i-k: dq.popleft()
        while dq and arr[dq[-1]] >= val: dq.pop()
        dq.append(i)
        if i >= k-1: res.append(arr[dq[0]])
    return res

def main():
    print(min_of_subarrays([1,3,-1,-3,5,3,6,7], 3))

if __name__ == '__main__':
    main()

# Time Complexity: O(n)
# Space Complexity: O(k)
