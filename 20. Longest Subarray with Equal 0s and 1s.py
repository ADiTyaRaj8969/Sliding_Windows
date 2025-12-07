# Topic: Longest Subarray with Equal 0s and 1s

from collections import defaultdict

def find_max_length(nums):
    first = {0: -1}
    s = 0
    res = 0
    for i, v in enumerate(nums):
        s += 1 if v == 1 else -1
        if s in first:
            res = max(res, i - first[s])
        else:
            first[s] = i
    return res

if __name__ == '__main__':
    nums = [0,1,0,1,0,1,1]
    print('Max length:', find_max_length(nums))

# Time Complexity: O(n)
# Space Complexity: O(n)
