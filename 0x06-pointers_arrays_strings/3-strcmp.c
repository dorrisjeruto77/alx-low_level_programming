#include "main.h"

/**
 * _strcmp - Compares pointers to two strings.
 * @s1: A pointer to the first string to be compared.
 * @s2: A pointer to the second string to be compared.
 * Return: the negative difference of
 * the first unmatched characters If s1 < s2, 
 * If s1 > s2 return a positive difference of the first
 * chars that don't match
 */
int _strcmp(char *s1, char *s2)
{
      while (((*s1 != '\0') && (*s2 != '\0')) && (*s1 == *s2))
      {
            s1++;
            s2++;
      }
      if (*s1 == *s2)
      {
              return (0);
      }
      else
      {
              return (*s1 - *s2);
      }
}
