# Topic: Longest Substring with K Unique Characters

def longest_substring_k_unique(s, k):
    freq = {}
    left = 0
    maxlen = 0
    for right, ch in enumerate(s):
        freq[ch] = freq.get(ch, 0) + 1
        while len(freq) > k:
            freq[s[left]] -= 1
            if freq[s[left]] == 0:
                del freq[s[left]]
            left += 1
        maxlen = max(maxlen, right-left+1)
    return maxlen

if __name__ == '__main__':
    s = "araaci"
    k = 2
    print("Longest:", longest_substring_k_unique(s, k))

# Time Complexity: O(n)
# Space Complexity: O(k)
