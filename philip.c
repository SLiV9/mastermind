#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include "code.h"
#include "dlist.h"
#include "ai.h"

dex philips_dex;

void next_guess(code attempt)
{
  static unsigned int i = 0;
  if (i >= dlist_length)
  {
    i = 0;
  }
  
  philips_dex = dlist[i];  
  codex(attempt, philips_dex);
  
  i++;
}

void filter_evalscore(score S)
{
  code philips_guess, supposed_master;
  codex(philips_guess, philips_dex);
  
  for (int i = 0; i < dlist_length; i++)
  {
    codex(supposed_master, dlist[i]);
    order[i] = (evaluate(philips_guess, supposed_master) == S);
  }
  
  filter_dlist();
}
