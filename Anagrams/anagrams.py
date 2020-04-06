class Solution:
    def groupAnagrams(self, strs):
        if len(strs) == 0:
            return [[""]]
        k1 = str(sorted([i for i in strs[0]]))
        dick = {k1: []}
        for s in strs:
            key = str(sorted([i for i in s]))
            if key in dick:
                dick[key].append(s)
            else:
                dick.update({str(key): [s]})
        ans = []
        for i in dick:
            ans.append(dick[i])
        return ans


strs = list(map(str, input().split()))
print(Solution().groupAnagrams(strs))
