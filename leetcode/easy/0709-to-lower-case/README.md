# To Lower Case

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given a string `s`, return  *the string after replacing every uppercase letter with the same lowercase letter*.

 

 **Example 1:** 

```
Input: s = "Hello"
Output: "hello"

```

 **Example 2:** 

```
Input: s = "here"
Output: "here"

```

 **Example 3:** 

```
Input: s = "LOVELY"
Output: "lovely"

```

 

 **Constraints:** 

- 1 <= s.length <= 100
- s consists of printable ASCII characters.

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 8.2 MB (beats 82.91%)  
**Submitted:** 2026-10-07T20:28:47.952Z  

```cpp
class Solution {
public:
    string toLowerCase(string s) {
         for(int i=0;i<s.length();i++){
            s[i] = tolower(s[i]);
        }   
        return s;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/to-lower-case/)