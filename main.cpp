#include <sys/types.h>
#include <stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main() {
    pid_t pid, ppid;
    pid = getpid();
    printf("当前进程ID: %d\n", pid);
    ppid = fork();
    if (-1 == ppid) {
        printf("进程创建失败！\n");
        return -1;
    } else if (ppid == 0) {
        printf("子进程，fork返回值：%d, Id: %d, 父进程ID： %d\n", ppid, getpid(), getppid());
    } else {
        printf("父进程，fork返回值：%d, ID: %d, 父进程ID： %d\n", ppid, getpid(), getppid());
    }
    return 0;
}