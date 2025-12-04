"""
Sum of Elements in Every Window of Size K
"""
def sums(arr, k):
    n = len(arr)
    if k>n: return []
    window = sum(arr[:k])
    res = [window]
    for i in range(k, n):
        window += arr[i] - arr[i-k]
        res.append(window)
    return res

def main():
    print(sums([1,2,3,4,5,6], 3))

if __name__ == '__main__':
    main()

# Time Complexity: O(n)
# Space Complexity: O(n) for result
