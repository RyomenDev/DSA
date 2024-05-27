// swapping using bit
void swap(int &x, int &y)
{
    x = x ^ y;
    y = x ^ y;
    x = x ^ y;
}

// check if a bit is set or not
bool checkBit(int n, int pos)
{
    return (n & (1 << pos)); // left shift
}

// set a bit
int setBit(int n, int pos)
{
    return (n | (1 << pos));
}

// unset a bit
int unsetBit(int n, int pos)
{
    return (n & ~(1 << pos));
}

// toggle a bit
int toggleBit(int n, int pos)
{
    return (n ^ (1 << pos));
}

//remove the lasts set bit
int removeLastSetBit(int n)
{
    return (n & (n - 1));
}

// to check if a number is power of two
bool isPowerOfTwo(int n)
{
    return (n && !(n & (n - 1)));
    // return n&(n-1)==0;
}

// to count the number of set bits
// __builtin_popcount( n)
int countSetBits(int n)
{
    int count = 0;
    while (n > 0)
    {
        n = n & (n - 1);
        count++;
    }
    return count;
}

// to find the position of the only set bit
int findPositionOfOnlySetBit(int n)
{
    int pos = 0;
    while (n > 0)
    {
        if ((n & 1) == 1)
            return pos;
        n = n >> 1;
        pos++;
    }
    return -1;
}
