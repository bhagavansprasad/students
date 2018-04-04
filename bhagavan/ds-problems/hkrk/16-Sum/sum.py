'''
class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        hashtable = {}
        for pos, value in enumerate(nums):
            if (value in hashtable):
                hashtable[value].append(pos)
            else:
                hashtable.update({value: [pos]})

        #print (nums, "--", target, "--", hashtable)

        for pos, value in enumerate(nums):
            search_value = target - value

            if (search_value not in hashtable):
                continue

            pos_list = hashtable[search_value]
            
            for newpos in pos_list:
                if (pos == newpos):
                    continue
                return (pos, newpos)

class Solution:
    def twoSum(self, nums, target):
        hashtable = {}
        for pos, value in enumerate(nums):
            search_value = target - value

            if (search_value in hashtable):
                return (hashtable[search_value], pos)
            else:
                hashtable[value] = pos
'''
class Solution:
    def twoSum(self, nums, target):
        hashtable = {}
        for pos in range(len(nums)):
            search_value = target - nums[pos]

            if (search_value in hashtable):
                return (hashtable[search_value], pos)
            else:
                hashtable[nums[pos]] = pos


input_list = [
    [[2, 7, 15, 11], 9,  [0, 1]],
    [[3, 2, 4],      6,  [1, 2]],
    [[2, 5, 5, 11],  10, [1, 2]],
    [[0, 4, 3, 0],   0,  [0, 3]],
    [[-1,-2,-3,-4,-5], -8, [2, 4]]
]

def main():
    cobj = Solution()

    for ip in input_list:
        #print (ip[0], ip[1], cobj.twoSum(ip[0], ip[1]), ip[2])
        print (cobj.twoSum(ip[0], ip[1]), ip[2])

if (__name__ == "__main__"):
    main()
        
