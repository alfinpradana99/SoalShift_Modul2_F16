#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>
#include <time.h>
#include <fcntl.h>


int main() {
  pid_t pid, sid;

  pid = fork();

  if (pid < 0) {
    exit(EXIT_FAILURE);
  }

  if (pid > 0) {
    exit(EXIT_SUCCESS);
  }

  umask(0);

  sid = setsid();

  if (sid < 0) {
    exit(EXIT_FAILURE);
  }

  if ((chdir("/")) < 0) {
    exit(EXIT_FAILURE);
  }

  close(STDIN_FILENO);
  close(STDOUT_FILENO);
  close(STDERR_FILENO);

  unsigned long long i=1;

  while(1) {
    // main program here
    struct stat status;
    struct tm waktusys;
    struct tm waktuaks;
    char dir[50];
    char dir2[50];
    
    memset(dir, 0, sizeof(dir));
    memset(dir2, 0, sizeof(dir2));
    strcpy(dir, "/home/hisam/Documents/makanan/makan_enak.txt");
    strcpy(dir2, "/home/hisam/Documents/makanan/");
    
    stat(dir, &status);

    waktuaks = *localtime(&status.st_atime);

    time_t T = time(NULL);

    waktusys = *localtime(&T);

    if(difftime(mktime(&waktusys),mktime(&waktuaks))<=30) {
	strcpy(dir2+strlen(dir2), "makan_sehat");
	char counter[1000];
	sprintf(counter,"%llu", i);
	strcpy(dir2+strlen(dir2), counter);
	strcpy(dir2+strlen(dir2), ".txt");
	creat(dir2, S_IRWXU | S_IRWXG | S_IRWXO );
	i++;    
    }
    sleep(5);
  }
  
  exit(EXIT_SUCCESS);
}
