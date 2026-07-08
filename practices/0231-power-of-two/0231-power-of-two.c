#include <stdbool.h>

bool isPowerOfTwo(int n) 
{
    if (n == 1)
    {
        return true;
    }

    /*
        if n is odd or n is less than or equal to 0, then it is not a power of two
    */
    if (((n%2) == 1) || (n <= 0))
    {
        return false;
    }

    int countBitset = 0;
    for (int x = 1; x < 32; x++)
    {
        /*
            check quantity of bit set in n
        */
        if (((n >> x) & 1) == 1)
        {
            countBitset++;
        }          
    }

    /*
        if only one bit is set, then n is a power of two
    */
    if (countBitset == 1)
    {
        return true;
    }

    return false;
}