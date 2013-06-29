#include <string.h>
#include <stdbool.h>

#include "code.h"

#include "evaluate.c"

bool fill(code a, const char* str)
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
      return false;
    }
  }
  
  return true;
}

bool stringify(const code a, char* str)
{
  if (strlen(str) < 4)
  {
    return false;
  }
  
  for (int i = 0; i < 4; i++)
  {
    str[i] = ((char) a[i]) + 'A';
  }
  
  return true;
}
