#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include "code.h"
#include "dlist.h"

/* Fill the dlist with all possible dexes, i.e. from AAAA to FFFF. */
void start_dlist()
{
  for (int i = 0; i < DEXES; i++)
  {
    dlist[i] = i;
    order[i] = 0;
  }
  
  dlist_length = DEXES;
}

/* Shuffle the dlist in linear time with Fisher and Yates' method. */
void shuffle_dlist()
{
  for (unsigned int i = DEXES - 1; i > 0; i--)
  {
    unsigned int j = rand() % (i+1);
    
    dex tmp = dlist[i];
    dlist[i] = dlist[j];
    dlist[j] = tmp;
  }
}

/* Filter the dlist to dexes where the order is positive. */
void filter_dlist()
{
  unsigned int j = 0;
  
  for (unsigned int i = 0; i < dlist_length; i++)
  {
    if (order[i])
    {
      dlist[j] = dlist[i];
      j++;
    }
  }
  
  dlist_length = j;
}

/* Sort the dlist by order. */
void sort_dlist()
{
  /* Sort by order. */
}
