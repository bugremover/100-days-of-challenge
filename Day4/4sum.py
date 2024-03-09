class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        def kSum(nums: List[int], target: int, k: int) -> List[List[int]]:
            res = []
            if len(nums) == 0 or nums[0] * k > target or nums[-1] * k < target:
                return res
            if k == 2:
                return twoSum(nums, target)
            for i in range(len(nums)):
                if i == 0 or nums[i - 1] != nums[i]:
                    for _, arr in enumerate(kSum(nums[i + 1:], target - nums[i], k - 1)):
                        res.append([nums[i]] + arr)
            return res

        def twoSum(nums: List[int], target: int) -> List[List[int]]:
            res = []
            left, right = 0, len(nums) - 1
            while left < right:
                total = nums[left] + nums[right]
                if total == target:
                    res.append([nums[left], nums[right]])
                    left += 1
                    right -= 1
                    while left < right and nums[left] == nums[left - 1]:
                        left += 1
                    while left < right and nums[right] == nums[right + 1]:
                        right -= 1
                elif total < target:
                    left += 1
                else:
                    right -= 1
            return res

        nums.sort()
        return kSum(nums, target, 4)
