#include <string.h>
#include <stdbool.h>

#include "code.h"

#include "evaluate.c"

bool codex(code a, dex j)
{
  if (j >= DEXES)
    return false;
    
  for (int i = 0; i < 4; i++)
  {
    a[i] = j % 6;
    j /= 6;
  }
    
  return true;
}

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
    if (a[i] >= A && a[i] <= F)
    {
      str[i] = ((char) (a[i] - A)) + 'A';
    }
    else if (a[i] == X)
    {
      str[i] = 'X';
    }
    else
    {
      str[i] = '$';
    }
  }
  
  return true;
}
