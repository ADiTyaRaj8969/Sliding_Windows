# Topic: Number of subarrays with sum = goal (binary array)

from collections import defaultdict

def num_subarrays_with_sum(A, S):
    cnt = defaultdict(int)
    cnt[0] = 1
    prefix = 0
    ans = 0
    for x in A:
        prefix += x
        ans += cnt.get(prefix - S, 0)
        cnt[prefix] += 1
    return ans

if __name__ == '__main__':
    A = [1,0,1,0,1]
    S = 2
    print('Count:', num_subarrays_with_sum(A,S))

# Time Complexity: O(n)
# Space Complexity: O(n)
