"""
First Negative Number in Every Window of Size K
"""
from collections import deque

def first_negative(arr, k):
    dq = deque()
    n = len(arr)
    res = []
    for i in range(k):
        if arr[i] < 0: dq.append(i)
    for i in range(k, n):
        res.append(arr[dq[0]] if dq else 0)
        while dq and dq[0] <= i-k: dq.popleft()
        if arr[i] < 0: dq.append(i)
    res.append(arr[dq[0]] if dq else 0)
    return res

def main():
    arr = [12,-1,-7,8,-15,30,16,28]
    print(first_negative(arr,3))

if __name__ == '__main__':
    main()

# Time Complexity: O(n)
# Space Complexity: O(k)
