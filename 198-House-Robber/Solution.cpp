/*
 * 递归法
 */
class Solution {
    public:
        int solve(int length, const vector<int>& nums) {
            if (length < 0) {
                return 0;
            }
            if (result[length] < 0) {
                result[length] = max(nums[length] + solve(length - 2, nums), solve(length - 1, nums));
            }
            return result[length];
        }
        int rob(vector<int>& nums) {
            result.resize(nums.size(), -1);
            return solve(nums.size() - 1, nums);
        }
    private:
        vector<int> result;
};

/*
 * 递推法
 */
class Solution {
    public:
        int rob(vector<int>& nums) {
            result.resize(nums.size(), -1);
            if (nums.size() == 0) {
                return 0;
            } else if (nums.size() == 1) {
                return nums[0];
            } else {
                result[0] = nums[0];
                result[1] = max(nums[0], nums[1]);
                for (int idx = 2; idx < nums.size(); ++idx) {
                    result[idx] = max(nums[idx] + result[idx - 2], result[idx - 1]);
                }
                return result[nums.size() - 1];
            }
        }
    private:
        vector<int> result;
};
