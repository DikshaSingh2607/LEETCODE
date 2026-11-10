
class Solution {
public:
    int divide(int dividend, int divisor) {

        // Handle overflow case
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        // Convert to long long to avoid overflow
        long long a = abs((long long)dividend);
        long long b = abs((long long)divisor);

        // Determine sign
        bool negative = (dividend < 0) ^ (divisor < 0);

        long long ans = 0;

        // Repeatedly subtract the largest doubled divisor
        while (a >= b) {

            long long temp = b;
            long long count = 1;

            while (a >= (temp << 1)) {
                temp <<= 1;
                count <<= 1;
            }

            a -= temp;
            ans += count;
        }

        if (negative)
            ans = -ans;

        return (int)ans;
    }
};
