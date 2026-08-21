class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        mp = {}

        for i in nums:
            if mp.get(i) == 1:
                return True
            mp[i] = mp.get(i,0) + 1

        return False