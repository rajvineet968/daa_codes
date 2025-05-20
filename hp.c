#include <stdio.h>
#include <string.h>
#define MAX 256

void buildShiftTable(char pattern[], int m, int shift[])
{
    for (int i = 0; i < MAX; i++)
        shift[i] = m;
    for (int i = 0; i < m - 1; i++)
        shift[(unsigned char)pattern[i]] = m - 1 - i;
}
int horspool(char text[], char pattern[])
{
    int n = strlen(text);
    int m = strlen(pattern);
    int shift[MAX];
    buildShiftTable(pattern, m, shift);
    int i = m - 1;
    while (i < n)
    {
        int k = 0;
        while (k < m && pattern[m - 1 - k] == text[i - k])
            k++;
        if (k == m)
            return i - m + 1;
        i += shift[(unsigned char)text[i]];
    }
    return -1;
}
int main()
{
    char text[100], pattern[100];
    printf("Enter the text: ");
    gets(text);
    printf("Enter the pattern: ");
    gets(pattern);
    int position = horspool(text, pattern);
    if (position == -1)
        printf("Pattern not found.\n");
    else
        printf("Pattern found at position %d.\n", position + 1); 
    return 0;
}
