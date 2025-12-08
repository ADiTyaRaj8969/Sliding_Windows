# Topic: Max Average Subarray II (binary search + prefix sums)

def check(nums, k, mid):
    n = len(nums)
    prefix = [0.0] * (n+1)
    for i in range(n):
        prefix[i+1] = prefix[i] + nums[i] - mid
    min_pref = 0.0
    for i in range(k, n+1):
        if prefix[i] - min_pref >= 0:
            return True
        min_pref = min(min_pref, prefix[i-k+1])
    return False

def find_max_average(nums, k):
    low, high = min(nums), max(nums)
    for _ in range(40):
        mid = (low + high) / 2.0
        if check(nums, k, mid): low = mid
        else: high = mid
    return low

if __name__ == '__main__':
    nums = [1,12,-5,-6,50,3]
    k = 4
    print('Max avg:', round(find_max_average(nums,k),6))

# Time Complexity: O(n log(range/eps))
# Space Complexity: O(n)
