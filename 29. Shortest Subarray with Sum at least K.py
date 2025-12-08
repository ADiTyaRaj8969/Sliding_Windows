# Topic: Shortest Subarray with Sum at least K (deque on prefix sums)

from collections import deque

def shortest_subarray(A, K):
    n = len(A)
    prefix = [0]*(n+1)
    for i in range(n): prefix[i+1] = prefix[i] + A[i]
    dq = deque()
    res = float('inf')
    for i in range(n+1):
        while dq and prefix[i] - prefix[dq[0]] >= K:
            res = min(res, i - dq.popleft())
        while dq and prefix[i] <= prefix[dq[-1]]:
            dq.pop()
        dq.append(i)
    return -1 if res == float('inf') else res

if __name__ == '__main__':
    A = [2,-1,2]
    K = 3
    print('Min length:', shortest_subarray(A,K))

# Time Complexity: O(n)
# Space Complexity: O(n)
