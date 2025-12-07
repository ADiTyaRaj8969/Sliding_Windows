# Topic: Max Consecutive Ones III

def longest_ones(A, K):
    left = 0
    zeros = 0
    res = 0
    for right, v in enumerate(A):
        if v == 0:
            zeros += 1
        while zeros > K:
            if A[left] == 0:
                zeros -= 1
            left += 1
        res = max(res, right-left+1)
    return res

if __name__ == '__main__':
    A = [1,1,1,0,0,0,1,1,1,1,0]
    K = 2
    print('Max consecutive ones:', longest_ones(A,K))

# Time Complexity: O(n)
# Space Complexity: O(1)
