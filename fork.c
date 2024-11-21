#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char** argv){
    int p[2];
    pipe(p);
    int pid = fork();
    char command[10];
    if(pid == 0){
        //CHILD
        char com[10];
        close(p[1]);
        read(p[0], com, sizeof(command));
        close(p[0]);
        if (strcmp(com, "id") == 0) {
            execl("/usr/bin/id", "id", NULL);
        } else if (strcmp(com, "pwd") == 0) {
            execl("/usr/bin/pwd", "pwd", NULL);
        } else if (strcmp(com, "date") == 0) {
            execl("/usr/bin/date", "date", NULL);
        } else {
            printf("Unknown command.\n");
        }
    }else{
        //PARENT
        close(p[0]);
        printf("prompt$ ");
        scanf(" %s", command);
        write(p[1],command,sizeof(command));
        close(p[1]);
        wait(NULL);
        printf("Done - %s\n",command);
    }
    return 0;
}
