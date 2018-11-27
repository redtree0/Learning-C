#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    printf("fork 전 현재 ppid = %d pid = %d \n", getppid() ,getpid());
    int status;
    pid_t cpid = fork();
    if(cpid == 0){
        
        printf("자식 프로세스 ppid = %d pid = %d cid = %d \n", getppid() , getpid(), cpid);
        
    }else{
        
        printf("현재 프로세스 ppid = %d pid = %d cid = %d \n", getppid() , getpid(), cpid);
        
        do {
            waitpid(cpid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
    return 0;
}
