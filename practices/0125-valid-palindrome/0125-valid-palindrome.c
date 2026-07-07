#include <stdbool.h>

/*
    iaslnum: isalnum() function checks whether a character is alphanumeric (i.e., a letter or a digit).
*/

bool isPalindrome(char* s) 
{
    int left = 0;
    int right = strlen(s) - 1;

    while (left < right) 
    {
        // Move left pointer to the next alphanumeric character
        while ((left < right) && (isalnum(s[left]) == false)) 
        {
            left++;
        }

        // Move right pointer to the previous alphanumeric character
        while ((left < right) && (isalnum(s[right]) == false)) 
        {
            right--;
        }

        // Compare characters in a case-insensitive manner
        if (tolower(s[left]) != tolower(s[right])) 
        {
            return false;
        }

        left++;
        right--;
    }

    return true;    
}