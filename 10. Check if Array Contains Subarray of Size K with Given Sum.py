"""
Check if array contains subarray of size K with given sum
"""
def exists_subarray_sum_k(arr, k, target):
    n = len(arr)
    if k>n: return False
    s = sum(arr[:k])
    if s==target: return True
    for i in range(k, n):
        s += arr[i] - arr[i-k]
        if s==target: return True
    return False

def main():
    print(exists_subarray_sum_k([1,4,20,3,10,5], 3, 33))

if __name__ == '__main__':
    main()

# Time Complexity: O(n)
# Space Complexity: O(1)
