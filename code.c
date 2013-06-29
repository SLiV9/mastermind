#include <string.h>

#include "code.h"

#include "evaluate.c"

void fill(code a, const char* str)
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

void stringify(const code a, char* str)
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
