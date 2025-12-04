"""
Maximum Sum Subarray of Size K
"""
def max_sum_subarray(arr, k):
    n = len(arr)
    if k > n: return None
    window_sum = sum(arr[:k])
    max_sum = window_sum
    for i in range(k, n):
        window_sum += arr[i] - arr[i-k]
        max_sum = max(max_sum, window_sum)
    return max_sum

def main():
    arr = [2,1,5,1,3,2]
    print('Max sum:', max_sum_subarray(arr, 3))

if __name__ == '__main__':
    main()

# Time Complexity: O(n)
# Space Complexity: O(1)
