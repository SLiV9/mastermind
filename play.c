#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include "code.h"

int main(int argc, char** argv)
{
    printf("[ Mastermind ]\n\n\n");
    
    /* Seed the random number generater. */
    srand(time(NULL));
    
    code attempt, master;
    for (int i = 0; i < 4; i++)
    {
      master[i] = (digit) (rand() % 6);
    }
    //char masterstring[5] = "1234";
    //stringify(master, masterstring);
    //printf("{ %s }\n", masterstring);
    
    char input[80] = "1234X";
    int turn;
    score S;
    
    for (turn = 1; turn <= 8; turn++)
    {
      printf("%d:: ", turn);
      fgets(input, 80, stdin);
      
      if (! fill(attempt, input))
      {
        printf("\t(Invalid input.)\n");
        turn--;
      }
      else
      {
        S = evaluate(attempt, master);
        
        if (S == 16)
        {
          printf("->\t\tCorrect!\n");
          break;
        }
        else
        {
          printf("->\t\t[ %d exact, %d about ]\n", exacts(S), abouts(S));
        }
        printf("\n");
      }
    }
    
    if (turn > 8)
    {
      printf("Game over.\n");
    }
    
    printf("\n\n[ done ]\n");

    return 0;
}
