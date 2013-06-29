#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include "code.h"
#include "ai.h"

bool run(const AI ai, const bool verbose);

int main(int argc, char** argv)
{
    printf("[ Mastermind ]\n\n\n");
    
    /* Seed the random number generator. */
    srand(time(NULL));
    
    ai_setup();
    
    unsigned int tries = 1000000;
    unsigned int successes;
    
    for (int ai = 0; ai < N_AI; ai++)
    {
      successes = 0;
      printf("It's now %s's turn.\n", ai_name[ai]);
      
      for (int t = 0; t < tries; t++)
      {
        successes += (run(ai, false));
      }
    
      printf("%s's success rate: %d / %d.\n", ai_name[ai], successes, tries); 
    }
    
    printf("\n\n[ done ]\n");

    return 0;
}

bool run(const AI ai, const bool verbose)
{
  if (! ai_name[ai])
  {
    printf("AI %d is not initialised.\n", ai);
    printf("\n< aborted >\n");
    exit(-1);
  }
  
  code attempt, master;
  int turn;
  score S = 0;
  char str[5];
  
  codex(master, rand() % DEXES);
  
  init[ai]();
  
  for (turn = 1; turn <= 8; turn++)
  {
    guess[ai](attempt);
    if (verbose)
    {
      stringify(attempt, str);
      printf("%s: %s\n", ai_name[ai], str);
    }
    
    S = evaluate(attempt, master);
    
    if (S == 16)
    {
      if (verbose)
      {
        printf("->\t\tCorrect!\n");
      }
      break;
    }
    else if (verbose)
    {
      reward[ai](S);
      
      printf("->\t\t[ %d exact, %d about ]\n", exacts(S), abouts(S));
    }
    
    if (verbose)
    {
      printf("\n");
    }
  }
  
  end[ai]();
  
  return (S == 16);
}
