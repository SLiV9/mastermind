#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include "code.h"
#include "ai.h"

bool run(AI ai, bool verbose);

int main(int argc, char** argv)
{
    printf("[ Mastermind ]\n\n\n");
    
    /* Seed the random number generator. */
    srand(time(NULL));
    
    ai_setup();
    
    run(RANDY, false);
    
    printf("\n\n[ done ]\n");

    return 0;
}

bool run(AI ai, bool verbose)
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
