#include <stdlib.h>
#include <string.h>

char* reverseWords(char* s)
{
    int n = strlen(s);

    // Allocate memory for the result string.
    // The result will never be longer than the original string.
    char* result = (char*)malloc((n + 1) * sizeof(char));

    int i = n - 1;   // Start scanning from the end of the string
    int k = 0;       // Current position in the result string

    while (i >= 0)
    {
        // Skip trailing or multiple spaces
        while (i >= 0 && s[i] == ' ')
        {
            i--;
        }

        // No more words
        if (i < 0)
        {
            break;
        }

        // Record the end of the current word
        int end = i;

        // Move backward until the beginning of the word
        while (i >= 0 && s[i] != ' ')
        {
            i--;
        }

        // Record the start of the current word
        int start = i + 1;

        // Add a space before the next word if needed
        if (k > 0)
        {
            result[k++] = ' ';
        }

        // Copy the current word into the result
        for (int j = start; j <= end; j++)
        {
            result[k++] = s[j];
        }
    }

    // Add the null terminator
    result[k] = '\0';

    return result;
}