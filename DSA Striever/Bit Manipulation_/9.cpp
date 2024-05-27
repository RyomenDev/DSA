// Divide Two Integers without using Multiplication and Division Operators | Bit Manipulation

#define ll long long
class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        if (dividend == 0)
            return 0;
        if (divisor == 1)
            return dividend;
        if (divisor == -1)
        {
            if (dividend > INT_MIN)
                return -dividend;
            else
                return INT_MAX;
        }
        ll x = dividend, y = divisor;
        x = abs(x), y = abs(y);

        ll ans = 0, count = 1;

        while (x - y >= 0)
        {
            x -= y;
            ans += count;
            count <<= 1;
        }

        if ((dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0))
            return ans;
        else
            return -ans;
    }
};