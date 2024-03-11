from ast import List
from collections import deque

class Solution:
    def constrainedSubsetSum(self, nums: List[int], k: int) -> int:
        n = len(nums)
        dp = [0] * n
        dq = deque()
        max_sum = float('-inf')
        for i in range(n):
            if dq and dq[0] < i - k:
                dq.popleft()           
            dp[i] = nums[i]
            if dq:
                dp[i] = max(dp[i], nums[i] + dp[dq[0]])
            max_sum = max(max_sum, dp[i])
            while dq and dp[dq[-1]] <= dp[i]:
                dq.pop()
            dq.append(i)
        
        return max_sum
