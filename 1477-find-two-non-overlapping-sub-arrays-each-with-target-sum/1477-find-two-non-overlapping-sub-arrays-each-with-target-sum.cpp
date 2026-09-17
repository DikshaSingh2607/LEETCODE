class Solution {
public:

    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        const int INF = 1e9;

        vector<int> best(n, INF);

        int left = 0;
        int sum = 0;
        int ans = INF;
        int minLen = INF;

        for (int right = 0; right < n; right++) {
            sum += arr[right];

            while (sum > target) {
                sum -= arr[left];
                left++;
            }

            // Store the best subarray found before/at this position
            if (right > 0) {
                best[right] = best[right - 1];
            }

            // Current window has sum = target
            if (sum == target) {
                int len = right - left + 1;

                // Check if there is a previous non-overlapping subarray
                if (left > 0 && best[left - 1] != INF) {
                    ans = min(ans, len + best[left - 1]);
                }

                // Current subarray can become the best previous subarray
                minLen = min(minLen, len);
                best[right] = min(best[right], minLen);
            }
        }

        return ans == INF ? -1 : ans;
    }
};