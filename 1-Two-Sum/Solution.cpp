class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        vector<int> result;
        for(int i=0;i<nums.size();++i) {
            if(m.find(nums[i])==m.end()) {
                m[target-nums[i]]=i;
            } else {
                result.push_back(m[nums[i]]);
                result.push_back(i);
                break;
            }
        }
        return result;
    }
};
