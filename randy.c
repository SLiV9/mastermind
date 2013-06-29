#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include "code.h"
#include "ai.h"

void random_guess(code attempt)
{
  codex(attempt, rand() % DEXES);
}
