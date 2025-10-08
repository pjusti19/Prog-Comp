#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include <stdbool.h>

int myAtoi(char *s)
{

    long long number;
    bool digit_read, found_signal;
    int signal, length = strlen(s);

    digit_read = found_signal = false;
    number = 0;
    signal = 1;

    for (int i = 0; i < length; i++)
    {
        if (s[i] >= 'A' && s[i] <= 'z' || s[i] == '.')
        {
            break;
        }
        else
        {
            if (digit_read == true || found_signal == true)
            {
                if (s[i] < '0' || s[i] > '9')
                {
                    break;
                }
                else if (number < INT_MAX)
                {
                    number *= 10;
                    number += ((int)s[i] - 48);
                }
            }
            else
            {
                if (s[i] == ' ')
                {
                    continue;
                }
                else if (s[i] == '-' || s[i] == '+')
                {
                    if (s[i] == '-')
                    {
                        signal = -1;
                    }
                    found_signal = true;
                    continue;
                }
                digit_read = true;
                number = ((int)s[i] - 48);
            }
        }
    }

    number *= signal;

    if (number > INT_MAX)
    {
        number = INT_MAX;
    }
    else if (number < INT_MIN)
    {
        number = INT_MIN;
    }

    return number;
}

int main()
{

    printf("%d\n", myAtoi("21474836460"));
}