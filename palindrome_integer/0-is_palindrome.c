#include "palindrome.h"

/**
 * is_palindrome - checkes whether a number is palindrome or not
 *
 * @n: number to be checked
 * Return: 1 if number is polindrom, otherwise 0
 */
int is_palindrome(unsigned long n)
{
    unsigned long reverse_n = 0, temp_n = n;
    int digit = 1;

    while (temp_n != 0)
    {
        reverse_n += temp_n % 10 * digit;
        temp_n /= 10;
        digit *= 10;
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
