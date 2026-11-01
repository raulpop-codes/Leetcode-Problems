## Result

- Runtime: 1 ms, beats 58.39%
- Memory: 9.55 MB, beats 90.83%

# 242. Valid Anagram

Given two strings `s` and `t`, return `true` if `t` is an anagram of `s`,
and `false` otherwise.

**Example 1:**
```
Input: s = "anagram", t = "nagaram"
Output: true
```

**Example 2:**
```
Input: s = "rat", t = "car"
Output: false
```

**Constraints:**
- `1 <= s.length, t.length <= 5 * 10^4`
- `s` and `t` consist of lowercase English letters.

## Complexity

- Time: O(n)
- Space: O(1) auxiliary (fixed 26-element frequency array)
