#include <string.h>

int lengthOfLongestSubstring(char* s) 
{
    int countChar[256] = {0};

    int left = 0;
    int maxLength = 0;

    int stringLength = strlen(s);

    for (int right = 0; right < stringLength; right++)
    {
        char c = s[right];

        countChar[c]++;

        while (countChar[c] > 1)
        {
            char leftChar = s[left];
            countChar[leftChar]--;
            left++;
        }

        int currentLength = right - left + 1;
        
        if (currentLength > maxLength)
        {
            maxLength = currentLength;
        }
    }

    return maxLength;
}