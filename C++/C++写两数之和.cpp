class Solution {
public:
    vector<int> twoSum(const vector<int>& nums, const int target) {
        unordered_map<int, int> dict;
        for (int i = 0; i < nums.size(); i++)
            if (dict.count(target - nums[i]))//这个是查看target-nums[i]在哈希表里有没有存
                return {dict[target - nums[i]], i};
            else
                dict[nums[i]] = i;//一一创建哈希表的过程
        return {0, 0};
    }
};
// nums = [2,7,11,15]
// target = 9