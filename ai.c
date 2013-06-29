#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include "code.h"
#include "ai.h"
#include "randy.h"

void ai_setup()
{
  ai_name[RANDY] = "Randy";
  init[RANDY] = init_randy;
  guess[RANDY] = guess_randy;
  reward[RANDY] = reward_randy;
  end[RANDY] = end_randy;
}
