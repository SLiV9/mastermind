#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include "code.h"
#include "dlist.h"
#include "ai.h"

unsigned int jimmy;

void init_random_dlist()
{
  start_dlist();
  
  for (int i = 0; i < DEXES; i++)
  {
    order[i] = rand();
  }
  
  sort_dlist();
  
  jimmy = 0;
}

void random_listed_guess(code attempt)
{  
  codex(attempt, dlist[jimmy]);
  
  jimmy++;
}
