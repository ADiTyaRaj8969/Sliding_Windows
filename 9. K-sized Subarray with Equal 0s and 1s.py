"""
K-sized Subarray with Equal 0s and 1s
"""
def exists_equal_zeros_ones(arr, k):
    n = len(arr)
    b = [ -1 if x==0 else 1 for x in arr ]
    s = sum(b[:k])
    if s==0: return True
    for i in range(k, n):
        s += b[i] - b[i-k]
        if s==0: return True
    return False

def main():
    print(exists_equal_zeros_ones([0,1,0,1,1,0,0,1], 4))

if __name__ == '__main__':
    main()

# Time Complexity: O(n)
# Space Complexity: O(n) or O(1) if transformed on the fly
