"""
Average of Subarrays of Size K
"""
def averages(arr, k):
    n = len(arr)
    if k>n: return []
    window_sum = sum(arr[:k])
    res = [window_sum / k]
    for i in range(k, n):
        window_sum += arr[i] - arr[i-k]
        res.append(window_sum / k)
    return res

def main():
    arr = [1,3,2,6,-1,4,1,8,2]
    print(averages(arr,5))

if __name__ == '__main__':
    main()

# Time Complexity: O(n)
# Space Complexity: O(n) for result
