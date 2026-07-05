#include <string.h>

int lengthOfLongestSubstring(char* s) 
{
    int count_char[256] = {0};

    int left = 0;
    int max_length = 0;

    int string_length = strlen(s);

    for (int right = 0; right < string_length; right++)
    {
        char c = s[right];

        /*
            Add char s[right] to the current window
        */
        count_char[c]++;

        /*
            If char c is a duplicate, shrink the window from the left 
            until there are no duplicates
        */
        while (count_char[c] > 1)
        {
            char left_char = s[left];
            count_char[left_char]--;
            left++;
        }

        /*
            Update the maximum length of the substring without repeating characters
        */
        int current_length = right - left + 1;
        
        if (current_length > max_length)
        {
            max_length = current_length;
        }
    }

    return max_length;
}