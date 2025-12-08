# Topic: Longest Subarray with Sum K (handles negatives)

from collections import defaultdict

def longest_subarray_sum_k(nums, K):
    first = {0: -1}
    s = 0
    res = 0
    for i, v in enumerate(nums):
        s += v
        if (s - K) in first:
            res = max(res, i - first[s - K])
        if s not in first:
            first[s] = i
    return res

if __name__ == '__main__':
    nums = [1,-1,5,-2,3]
    K = 3
    print('Longest length:', longest_subarray_sum_k(nums,K))

# Time Complexity: O(n)
# Space Complexity: O(n)
