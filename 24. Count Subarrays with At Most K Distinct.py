# Topic: Count subarrays with at most K distinct elements

from collections import defaultdict

def at_most_k(A, K):
    cnt = defaultdict(int)
    left = 0
    res = 0
    for right, v in enumerate(A):
        cnt[v] += 1
        while len(cnt) > K:
            cnt[A[left]] -= 1
            if cnt[A[left]] == 0:
                del cnt[A[left]]
            left += 1
        res += right - left + 1
    return res

if __name__ == '__main__':
    A = [1,2,1]
    print('AtMostK:', at_most_k(A,2))

# Time Complexity: O(n)
# Space Complexity: O(k)
