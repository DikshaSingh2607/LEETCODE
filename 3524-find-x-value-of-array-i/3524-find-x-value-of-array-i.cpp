class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0);
        vector<long long> dp(k, 0);

        for (int num : nums) {
            vector<long long> newdp(k, 0);

            int rem = num % k;

            // Start a new subarray with only num
            newdp[rem]++;

            // Extend previous subarrays
            for (int r = 0; r < k; r++) {
                if (dp[r] > 0) {
                    int newRem = (r * rem) % k;
                    newdp[newRem] += dp[r];
                }
            }

            dp = newdp;

            // Add all subarrays ending at this position
            for (int r = 0; r < k; r++) {
                ans[r] += dp[r];
            }
        }

        return ans;
    }
};