# Topic: Subarray Sum Equals K (for non-negative / positive numbers)

def subarray_sum_equals_k(arr, K):
    left = 0
    s = 0
    for right, val in enumerate(arr):
        s += val
        while s > K and left <= right:
            s -= arr[left]
            left += 1
        if s == K:
            return (left, right)
    return None

if __name__ == '__main__':
    arr = [1,2,3,7,5]
    K = 12
    res = subarray_sum_equals_k(arr, K)
    print('Found:', res if res else 'Not found')

# Time Complexity: O(n)
# Space Complexity: O(1)
