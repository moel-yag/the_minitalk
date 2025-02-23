#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <sys/wait.h>
#include <signal.h>

int main(int argc, char **argv)
{
    int pid = fork();
    int i = 0;
    
    if (pid == -1)
        return 1;
    if (pid == 0)
    {
        while (1)
        {
            printf("Child process ID: %d\n", i);
            usleep(50000);
            i++;
        }
    }
    else
    {
        sleep(1);
        kill(pid, SIGKILL);
        wait(NULL);
        printf("Done!!!!!\n");
    }
    return 0;
}