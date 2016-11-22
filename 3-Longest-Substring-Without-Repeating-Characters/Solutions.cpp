/*
*  解法一，结果超时
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int iStrLen = s.length();
        int iMaxSubLen = 0;
        for (int i = 0; i < iStrLen; ++i) {
            for (int j = i + 1; j <= iStrLen; ++j) {
                if (isUnique(i, j, s)) {
                    iMaxSubLen = iMaxSubLen > j - i? iMaxSubLen: j - i;
                }
            }
        }
        return iMaxSubLen;
    }
    bool isUnique(int start, int end, const string& s) {
        int len = end - start;
        for (int i = start; i < start + len; ++i) {
            for (int j = start; j < start + len; ++j) {
                if (i != j && s[i] == s[j]) {
                    return false;
                }
            }
        }
        return true;
    }
};

/*
* 解法二，滑动窗口
*/
#include <unordered_set>
#include <algorithm>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int iStrLen = s.length();
        int iMaxSubLen = 0;
        unordered_set<char> hashSet;
        int i = 0, j = 0;
        while (i < iStrLen && j < iStrLen) {
            if (hashSet.end() == hashSet.find(s[j])) {
                hashSet.insert(s[j++]);
                iMaxSubLen = std::max(iMaxSubLen, (j - i));
            } else {
                hashSet.erase(s[i++]);
            }
        }
        return iMaxSubLen;
    }
};

/*
* 解法三，滑动窗口优化
*/
#include <unordered_map>
#include <algorithm>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int iStrLen = s.length();
        int iMaxSubLen = 0;
        unordered_map<char, int> hashMap;
        int i = 0, j = 0;
        while (i < iStrLen && j < iStrLen) {
            if (hashMap.end() != hashMap.find(s[j])) {
                i = std::max(hashMap[s[j]], i);
            }
            iMaxSubLen = std::max(iMaxSubLen, (j - i + 1));
            hashMap[s[j]] = j + 1;
            j++;
        }
        return iMaxSubLen;
    }
};