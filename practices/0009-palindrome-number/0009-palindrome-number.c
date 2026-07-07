#include <stdbool.h>

bool isPalindrome(int x) 
{
    if (x < 0)
    {
        return false;
    }

    long long tmp = x;
    long long rsno = 0;
    while (x != 0)
    {
        int digit = x % 10;
        rsno = rsno * 10 + digit;
        x /= 10;
    }

    return (rsno == tmp);
}