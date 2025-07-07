#Given two strings s and t, return true if the two strings are anagrams of each other, otherwise return false.
#An anagram is a string that contains the exact same characters as another string, but the order of the characters can be different.

class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False

        sDict = {}
        tDict = {}

        for i in range(len(s)):

            #retrieves count of character that defaults to 0 if character is not already in the dictionary, then increments
            sDict[s[i]]= sDict.get(s[i],0) + 1
            tDict[t[i]]= tDict.get(t[i],0) + 1
        
        if sDict == tDict:
            return True
        else:
            return False