// https://leetcode.com/problems/house-robber/

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        auto take = [&](auto &&self, int i) -> int {
            if (i >= n) return 0;
            if (ans[i] != -1) return ans[i];
            
            int notTaken = self(self, i + 1);
            int taken = self(self, i + 2) + nums[i];
            return ans[i] = max(notTaken, taken);
        };

        return take(take, 0);
    }
};