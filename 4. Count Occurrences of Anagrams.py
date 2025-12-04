"""
Count Occurrences of Anagrams
"""
from collections import Counter

def count_anagrams(s, p):
    n, m = len(s), len(p)
    if m>n: return 0
    pc = Counter(p)
    window = Counter(s[:m])
    count = 1 if window==pc else 0
    for i in range(m, n):
        window[s[i]] += 1
        window[s[i-m]] -= 1
        if window[s[i-m]] == 0: del window[s[i-m]]
        if window==pc: count += 1
    return count

def main():
    print(count_anagrams('cbaebabacd','abc'))

if __name__ == '__main__':
    main()

# Time Complexity: O(n)
# Space Complexity: O(1) (alphabet size)
