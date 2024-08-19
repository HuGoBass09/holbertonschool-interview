#include "palindrome.h"
#include<math.h>

/**
 * is_palindrome - checkes whether a number is palindrome or not
 *
 * @n: number to be checked
 * Return: 1 if number is polindrom, otherwise 0
 */
int is_palindrome(unsigned long n)
{
    unsigned long reverse_n = 0, temp_n = n;
    int digits = 0;

    while (temp_n != 0) {
        temp_n /= 10;
        ++digits;
    }

    temp_n = n;

    while (temp_n != 0)
    {
        reverse_n += (temp_n % 10) * pow(10, digits);
        temp_n /= 10;
        --digits;
    }

    if (n == reverse_n)
    {
        return (1);
    }
    else
    {
        return (0);
    }
}
