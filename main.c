#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "code.h"

int main(int argc, char** argv)
{
    printf("[ Mastermind ]\n\n\n");
    
    code master;
    
    fill(master, "abce");
    
    if (contains(master, D))
    {
      printf("The master code contains the letter D.\n");
    }
    if (contains(master, E))
    {
      printf("The master code contains the letter E.\n");
    }
    
    char str[5] = "1234";
    stringify(master, str);
    printf("The master code is: %s.\n", str);
    
    printf("\n\n[ done ]\n");

    return 0;
}
