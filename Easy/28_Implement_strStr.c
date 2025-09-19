#include <stdio.h>
#include <string.h>

int strStr(char *haystack, char *needle)
{

    int haystack_length = strlen(haystack);
    int needle_length = strlen(needle);
    int equal_char_count = 0;

    for (int i = 0; i < haystack_length; i++)
    {
        if (haystack[i] == needle[0])
        {
            while ((haystack[i + equal_char_count] == needle[0 + equal_char_count]) && needle[0 + equal_char_count] != '\0' )
            {
                equal_char_count++;
            }
            if (equal_char_count == needle_length)
            {
                return i;
            }
            else
            {
                equal_char_count = 0;
            }
        }
    }

    return -1;
}

int main(){

    printf("%d\n", strStr("andasdnasdnkasdkasjdkasjdksajdksacoringao", "coringao"));

    return 0;
}