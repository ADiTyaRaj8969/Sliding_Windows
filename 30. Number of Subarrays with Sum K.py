# Topic: Number of Subarrays with Sum K (general integers)

from collections import defaultdict

def subarray_sum(nums, k):
    count = defaultdict(int)
    count[0] = 1
    s = 0
    ans = 0
    for x in nums:
        s += x
        ans += count.get(s-k, 0)
        count[s] += 1
    return ans

if __name__ == '__main__':
    nums = [1,1,1]
    k = 2
    print('Count:', subarray_sum(nums,k))

# Time Complexity: O(n)
# Space Complexity: O(n)
