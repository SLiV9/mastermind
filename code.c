#include <string.h>

#include "code.h"

void fill(code a, char* str)
{
  char c;
  
  for (int i = 0; i < 4; i++)
  {
    c = str[i];
    
    if (c >= 'a' && c <= 'f')
    {
      a[i] = (digit) (c - 'a');
    }
    else if (c >= 'A' && c <= 'F')
    {
      a[i] = (digit) (c - 'A');
    }
    else
    {
      return;
    }
  }
}

void stringify(code a, char* str)
{
  if (strlen(str) < 4)
  {
    return;
  }
  
  for (int i = 0; i < 4; i++)
  {
    str[i] = ((char) a[i]) + 'A';
  }
}
