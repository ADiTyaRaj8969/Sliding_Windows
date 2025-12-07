# Topic: Subarray Product Less Than K

def num_subarray_product_less_than_k(nums, k):
    if k <= 1: return 0
    prod = 1
    left = 0
    ans = 0
    for right, val in enumerate(nums):
        prod *= val
        while prod >= k and left <= right:
            prod //= nums[left]
            left += 1
        ans += right - left + 1
    return ans

if __name__ == '__main__':
    nums = [10,5,2,6]
    k = 100
    print('Count:', num_subarray_product_less_than_k(nums,k))

# Time Complexity: O(n)
# Space Complexity: O(1)
