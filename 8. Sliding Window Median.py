"""
Sliding Window Median (balanced heaps) - concise demo
"""
import heapq

class DualHeap:
    def __init__(self):
        self.small = []  # max heap (invert sign)
        self.large = []  # min heap
    def add(self, num):
        if not self.small or num <= -self.small[0]: heapq.heappush(self.small, -num)
        else: heapq.heappush(self.large, num)
        # rebalance
        if len(self.small) > len(self.large) + 1: heapq.heappush(self.large, -heapq.heappop(self.small))
        if len(self.large) > len(self.small): heapq.heappush(self.small, -heapq.heappop(self.large))
    def median(self):
        if len(self.small) > len(self.large): return -self.small[0]
        return (-self.small[0] + self.large[0]) / 2
    def remove(self, num):
        # lazy removal not fully implemented; simple remove for demo (O(k))
        try:
            self.small.remove(-num); heapq.heapify(self.small)
        except ValueError:
            try:
                self.large.remove(num); heapq.heapify(self.large)
            except ValueError:
                pass

def medians(nums, k):
    dh = DualHeap(); res = []
    for i, val in enumerate(nums):
        dh.add(val)
        if i >= k-1:
            res.append(dh.median())
            dh.remove(nums[i-k+1])
    return res

def main():
    print(medians([1,3,-1,-3,5,3,6,7], 3))

if __name__ == '__main__':
    main()

# Time Complexity: O(n k) in this demo due to naive removal; full implementation O(n log k)
# Space Complexity: O(k)
