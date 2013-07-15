#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include "code.h"
#include "ai.h"
#include "dlist.h"

void empty_init()
{
}

void empty_guess(code attempt)
{
}

void empty_reward(score S)
{
}

void empty_end()
{
}

void ai_setup()
{
  ai_name[RANDY] = "Randy";
  init[RANDY] = empty_init;
  guess[RANDY] = random_guess;
  reward[RANDY] = empty_reward;
  end[RANDY] = empty_end;
  
  ai_name[JIMMY] = "Jimmy";
  init[JIMMY] = init_random_dlist;
  guess[JIMMY] = random_listed_guess;
  reward[JIMMY] = empty_reward;
  end[JIMMY] = empty_end;
  
  ai_name[PHILIP] = "Philip";
  init[PHILIP] = start_dlist;
  guess[PHILIP] = next_guess;
  reward[PHILIP] = filter_evalscore;
  end[PHILIP] = empty_end;
}
