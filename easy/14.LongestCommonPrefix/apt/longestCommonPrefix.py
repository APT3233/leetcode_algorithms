class Solution(object):
    def longestCommonPrefix(self, strs):
        prefix = strs[0]    # flower

        for string in strs[1:]:
            while not string.startswith(prefix):
                prefix = prefix[:-1]
                
                if not prefix:
                    return ""

        return prefix
        