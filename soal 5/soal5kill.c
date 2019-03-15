#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

int main(){
char proses[100];
memset(proses, 0, strlen(proses));
scanf("%[^\n]%*c", proses);
char *pkill[] = {"pkill",proses,NULL};
execvp("pkill",pkill);
}
