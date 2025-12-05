"""
Longest Substring Without Repeating Characters
"""
def longest_unique_substring(s):
    last = {}
    start = 0
    maxlen = 0
    for i, ch in enumerate(s):
        if ch in last and last[ch] >= start:
            start = last[ch] + 1
        maxlen = max(maxlen, i - start + 1)
        last[ch] = i
    return maxlen

def main():
    print(longest_unique_substring('abcabcbb'))

if __name__ == '__main__':
    main()

# Time Complexity: O(n)
# Space Complexity: O(1)
