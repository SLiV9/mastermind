#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include "code.h"
#include "dlist.h"

void start_dlist()
{
  for (int i = 0; i < DEXES; i++)
  {
    dlist[i] = i;
    order[i] = 0;
  }
}

void sort_dlist()
{
  /* Sort by order. */
}
