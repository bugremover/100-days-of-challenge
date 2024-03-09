class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        # Sort the array
        nums.sort()
        result = []
        
        # Iterate through the array
        for i in range(len(nums)):
            # Skip duplicates to avoid duplicate triplets
            if i > 0 and nums[i] == nums[i-1]:
                continue
            
            # Set the target for two sum
            target = -nums[i]
            left, right = i + 1, len(nums) - 1
            
            # Two sum problem
            while left < right:
                total = nums[left] + nums[right]
                if total == target:
                    # Found a triplet, append to result
                    result.append([nums[i], nums[left], nums[right]])
                    
                    # Skip duplicates for left pointer
                    while left < right and nums[left] == nums[left + 1]:
                        left += 1
                    # Skip duplicates for right pointer
                    while left < right and nums[right] == nums[right - 1]:
                        right -= 1
                    left += 1
                    right -= 1
                elif total < target:
                    left += 1
                else:
                    right -= 1
        
        return result