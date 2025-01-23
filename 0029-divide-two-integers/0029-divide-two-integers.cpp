class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle edge case for overflow
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        
        // Determine the sign of the result
        int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;

        // Work with absolute values to simplify logic
        long long ldividend = abs((long long)dividend);
        long long ldivisor = abs((long long)divisor);

        long long result = 0;
        
        // Repeated subtraction using bitwise shifts for efficiency
        while (ldividend >= ldivisor) {
            long long tempDivisor = ldivisor, multiple = 1;
            while (ldividend >= (tempDivisor << 1)) {
                tempDivisor <<= 1;
                multiple <<= 1;
            }
            ldividend -= tempDivisor;
            result += multiple;
        }
        
        // Apply the sign
        result = sign * result;

        // Handle result overflow for 32-bit integers
        if (result > INT_MAX) return INT_MAX;
        if (result < INT_MIN) return INT_MIN;
        
        return result;
    }
};
