//For our final demonstration of popen(), let's create a generic program that opens up a pipeline between a passed command and filename:

/*Try this program out, with the following invocations:

        pipfopen sort pipfopen.c
        pipfopen cat pipfopen.c
        pipfopen more pipfopen.c
        pipfopen cat pipfopen.c | grep main

*/

#include <stdio.h>

int main(int argc, char *argv[])
{
        FILE *pipe_fp, *infile;
        char readbuf[80];

        if( argc != 3) {
                fprintf(stderr, "USAGE:  pipfopen [command] [filename]\n");       
                exit(1);
        }

        /* Open up input file */
        if (( infile = fopen(argv[2], "rt")) == NULL)
        {
                perror("fopen");
                exit(1);        
        }

        /* Create one way pipe line with call to popen() */
        if (( pipe_fp = popen(argv[1], "w")) == NULL)
        {
                perror("popen");
                exit(1);
        }

        /* Processing loop */
        do { 
                fgets(readbuf, 80, infile);
                if(feof(infile)) break;

                fputs(readbuf, pipe_fp);
        } while(!feof(infile));

        fclose(infile); 
        pclose(pipe_fp);

        return(0);
}

