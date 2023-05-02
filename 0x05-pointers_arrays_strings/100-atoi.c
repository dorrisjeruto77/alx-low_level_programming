#include "main.h"

/**
 * _atoi - Converts a string to an integer.
 * @s: The string to be converted.
 * Return: The integer value of the converted string.
 */

int _atoi(char *s)
{
      int c = 0;
      unsigned int ni = 0;
      int min = 1 ;
      while (s[c])
      {
      if (s[c] == 45)
      {
      min *= -1;
      } 
      while (s[c] >= 48 && s[c] <= 57)
      {
      isi = 1;
      ni = (ni * 10) + (s[c] - '0');
      c++;
      }
      ni *= min;
      return (ni);
}
      else if (*s >= '0' && *s <= '9')
      num = (num * 10) + (*s - '0');
      else if (num > 0)
      break;
      } 
      while (*s++);
      return (num * sign);
      }
