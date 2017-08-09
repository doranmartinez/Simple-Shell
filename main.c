//
//  main.c
//  Tish
//
//  Created by Doran Martinez on 7/28/17.
//  Copyright © 2017 Doran Martinez. All rights reserved.
//

#include <string.h>
#include <stdio.h>
#include <sys/types.h>

int main()
{
    printf("tish> ");
    char str[80];
    gets( str );
    const char delim[2] = " ";
    char *tok = strtok(str, delim);
    char *array[80]; //an array to carry tokens
    int i = 0;
    int bkgr = 0;
    int j = 0;
    
    //tok = strtok(str, delim);   //First token
    
    while( tok != NULL )    //The other Tokens
    {
        array[i++] = tok;
        if (*tok == '&') {
            bkgr = 1;
            array[--i] = NULL;
        }
        printf( "%s\n", tok );
        tok = strtok(NULL, delim);
        //++j;
    }
            //printf( "%d\n", bkgr);
    
            //for (i = 0; i < j; ++i)
                //printf("%s\n", array[i]);
    
            //printf("%s\n", array[i++]);
    
    
    pid_t pid;
    /* fork another process */
    pid = fork();
    if (pid < 0) { /* error occurred */
        fprintf(stderr, "Fork Failed");
        exit(-1); }
    else if (pid == 0) { /* child process */
        execvp(array[0],array);
    }
    else if (bkgr ==1) { /* parent process */
        /* parent will wait for the child to
         complete */
        wait (NULL);
        printf ("Child Complete");
        bkgr = 0;
        exit(0);
    }
    
    
    
    return(0);
}
