#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 20

/**
 * Determine if the string s starts with the string prefix.
 * @param s - the string to see if it starts with prefix
 * @param prefix - the prefix to test
 * @returns true if the strings begins with the prefix.
 */
int startsWith(const char s[], const char prefix[])
{
    char buf[MAX_SIZE];
    int i;
    int sz = strlen(prefix);
    for (i = 0; i < sz; i++)
    {
        buf[i] = s[i];
    }
    buf[sz] = '\0';
    return 0 == strcmp(buf, prefix);
}
/**
 * Determine if the string s ends with the string suffix.
 * @param s - the string to see if it ends with suffix
 * @param suffix - the suffix to test
 * @returns true if the strings ends with the suffix.
 */
int endsWith(const char s[], const char suffix[])
{
    int sz = strlen(suffix);
    int slen = strlen(s);
    return 0 == strcmp(s + slen - sz, suffix);
}

/**
 * Determine if the given string follows the guide rules
 * of the program, printing a error message based on the
 * broken rule.
 * - None NULL values or pointers
 * - No empty strings
 * - Cannot go over the MAX_SIZE
 * @param str - the strinf to be verified
 * @return true if all the rules are followed, and false 
 * otherwise
*/
int inputStringVerifier(char *str)
{
    if (str == NULL)                 
    {
        printf("The string value nor pointer can be NULL.\n");
        return 0;
    }
    else if (strlen(str) <= 0)       
    {
        printf("The string cannot be empty, you need at least 1 character.\n");
        return 0;
    }
    else if (strlen(str) > MAX_SIZE) 
    {
        printf("The string cannot be bigger than %d characters.\n", MAX_SIZE);
        return 0;
    }
    else                                
    {
        return 1;
    }
}

/**
 * Main function the evaluates if the prefix and/or are contained in the
 * given string s1, and stores the outcome in result.
 * @param s1 - The string to be evaluated
 * @param prefix - The searched prefix
 * @param suffix - The searched suffix
 * @param result - A two postional array of integers where the outcomes
 * are gonna be stored, 0 position for the prefix and 1 posotion for the
 * suffix.
 * @return the return value is stored in result. If its contained 1 would
 * be assigned, else 0, but if the program guidelines or rules were broken
 * -1 would be returned.
*/
void stringIdentifier(char *s1, char *prefix, char *suffix, int *result)
{
    result[0] = -1;
    result[1] = -1;
    if (inputStringVerifier(s1))
    {
        if (inputStringVerifier(prefix))
        {
            result[0] = 0;
            if (strlen(prefix) <= strlen(s1))
            {
                printf("|%s| does %s start with |%s|\n",
                    s1, startsWith(s1, prefix) ? "\b" : "not", prefix);
                result[0] = startsWith(s1, prefix);
            }
            
        }

        if (inputStringVerifier(suffix))
        {
            result[1] = 0;
            if (strlen(suffix) <= strlen(s1))
            {
                printf("|%s| does %s end with |%s|\n",
                    s1, endsWith(s1, suffix) ? "\b" : "not", suffix);
                result[1] = endsWith(s1, suffix);
            }
        } 
    }
} 


