#include <stdlib.h>
#include <string.h>

char* addBinary(char* a, char* b) 
{
    int lenA = strlen(a);
    int lenB = strlen(b);

    int maxLen;
    if (lenA > lenB) 
    {
        maxLen = lenA;
    } 
    else 
    {
        maxLen = lenB;
    }

    /*
        Result string length is maxLen + 1 (for carry) + 1 (for null terminator)
    */
    char* result = (char*)malloc((maxLen + 2) * sizeof(char));

    int i = lenA - 1;
    int j = lenB - 1;
    int k = maxLen;

    int carry = 0;

    result[maxLen + 1] = '\0';

    while ((i >= 0) || (j >= 0) || (carry != 0))
    {
        int sum = carry;

        if (i >= 0) 
        {
            sum += a[i] - '0';
            i--;
        }

        if (j >= 0) 
        {
            sum += b[j] - '0';
            j--;
        }

        result[k] = (sum % 2) + '0';
        carry = sum / 2;

        k--;
    }

    /*
        If k >= 0, it means there is a leading zero in the result string.
        We need to shift the result string to the left to remove the leading zero.
    */
    if (k >= 0) 
    {
        memmove(result, result + k + 1, maxLen - k + 1);
    }

    return result;
}