#include <stdio.h>
#include <string.h>

// Function to build the prefix table (failure function) for the pattern
void buildPrefixTable(char *pattern, int prefix[], int m)
{
    int len = 0;
    prefix[0] = 0; // First value is always 0

    for (int i = 1; i < m; i++)
    {
        // If pattern[i] matches the character at prefix[len]
        if (pattern[i] == pattern[len])
        {
            len++;
            prefix[i] = len;
        }
        else
        {
            // If there is no match, backtrack to the previous prefix value
            if (len != 0)
            {
                len = prefix[len - 1];
                i--; // Decrement i to recheck the current character in the next iteration
            }
            else
            {
                prefix[i] = 0; // No match found, reset to 0
            }
        }
    }
}

// Function to perform pattern matching using the KMP algorithm
void KMP(char *text, char *pattern)
{
    int n = strlen(text);
    int m = strlen(pattern);

    // Create and initialize the prefix table
    int prefix[m];
    buildPrefixTable(pattern, prefix, m);

    int i = 0; // Index for text[]
    int j = 0; // Index for pattern[]

    while (i < n)
    {
        // If pattern[j] matches text[i], increment both indices
        if (pattern[j] == text[i])
        {
            j++;
            i++;
        }

        // If a complete match is found
        if (j == m)
        {
            printf("Pattern found at index %d\n", i - j);
            j = prefix[j - 1]; // Move to the previous match in pattern
        }

        // If mismatch occurs, adjust j based on prefix table
        else if (i < n && pattern[j] != text[i])
        {
            if (j != 0)
            {
                j = prefix[j - 1];
            }
            else
            {
                i++;
            }
        }
    }
}

int main()
{
    char text[] = "ABABDABACDABABCABAB";
    char pattern[] = "ABABCABAB";

    printf("Text: %s\n", text);
    printf("Pattern: %s\n", pattern);

    printf("Occurrences:\n");
    KMP(text, pattern);

    return 0;
}
