class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        freq = Counter(nums)
        h = []
        for val,f in freq.items():
            heapq.heappush(h,(f,val))
            if(len(h) > k):
                heapq.heappop(h)
        return [val for f, val in h]
