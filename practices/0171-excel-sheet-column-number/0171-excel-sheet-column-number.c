int titleToNumber(char* columnTitle) 
{
    int result = 0;
    int length = strlen(columnTitle);

    for (int i = 0; i < length; i++)
    {
        result *= 26;
        result += columnTitle[i] - 'A' + 1;
    }

    return result;    
}