#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


#define PREAD 0
#define PWRITE 1

/*
 * 
 */

    int main(int argc, char** argv) {

        int key_logger_on = 0;
        int pIn[2];
        int pOut[2]; 
        pid_t pid;
        char str[256];
        char input[1024] = "";
        int status;

        char file[] = "test.txt";
        char buf;
        printf("Input :: ");
        while (fgets(input,sizeof(input),stdin)) {

            char nChar;
            int nResult;

            if (pipe(pIn) < 0) {
                perror("allocating pipe for child input redirect");
                return -1;
            }
            if (pipe(pOut) < 0) {
                close(pIn[PREAD]);
                close(pIn[PWRITE]);
                perror("allocating pipe for child output redirect");
                return -1;
            }

            pid = fork();
            if ( pid==0) {
                // child continues here

                // redirect stdin
                if (dup2(pIn[PREAD], 0) == -1) {
                    perror("stdin");
                    return -1;
                }

                // redirect stdout
                if (dup2(pOut[PWRITE], 1) == -1) {
                    perror("stdout");
                    return -1;
                }

                // redirect stderr
                if (dup2(pOut[PWRITE], 2) == -1) {
                    perror("stderr");
                    return -1;
                }

                // all these are for use by parent only
                close(pIn[PREAD]);
                close(pIn[PWRITE]);
                close(pOut[PREAD]);
                close(pOut[PWRITE]);

                // run child process image
                nResult = execl(argv[0], argv[1],NULL);

                exit(nResult);
            } else if (pid > 0) {
                // parent continues here

                // close unused file descriptors, these are for child only
                close(pIn[PREAD]);
                close(pOut[PWRITE]);

                write(pIn[PWRITE], input, strlen(input));

                // char by char reading
                while (read(pOut[PREAD], &nChar, 1) == 1) {
                    write(STDOUT_FILENO, &nChar, 1);
                }

                // close we done
                close(pIn[PWRITE]);
                close(pOut[PREAD]);
            }
            printf("Input :: ");
        }
    }
