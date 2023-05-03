#include "main.h"
/**
 * _isupper -  checks for uppercase characte
 *
 * @c: character that is checked
 *
 * Return:1 if true, 0 if false
 */

int _isupper(int n)
{
      if (n >= 65 && n <= 90)
              return (1);
      else
              return (0);
}
