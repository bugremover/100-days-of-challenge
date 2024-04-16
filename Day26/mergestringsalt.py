class Solution(object):
    def mergeAlternately(self, word1, word2):
        len1,len2=len(word1),len(word2)
        result=''
        max_len=max(len1,len2)
        for i in range(max_len):
            if i<len1:
                result+=word1[i]
            if i<len2:
                result+=word2[i]
        return result
      
        