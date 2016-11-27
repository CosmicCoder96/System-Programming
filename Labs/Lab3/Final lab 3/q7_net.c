#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void)
{
    pid_t before_pid, after_pid;
    pid_t forked_pid;
    int count;
    int i;
    int status;

    before_pid = getpid();
    count = 0; /* count self */
    for (i = 0; i < 10; i++) {
        forked_pid = fork();

        if (forked_pid > 0) {
            waitpid(forked_pid, &status, 0);
            /* parent process - count child and descendents */
            count += WEXITSTATUS(status); 
        } else {
            /* Child process - init with self count */
            count = 1;
        }
    }

    after_pid = getpid();
    if (after_pid == before_pid) {
        printf("%d processes created\n", count);
    }

    return (count);
}
