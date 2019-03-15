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

  if ((chdir("/home/hisam/")) < 0) {
    exit(EXIT_FAILURE);
  }

  close(STDIN_FILENO);
  close(STDOUT_FILENO);
  close(STDERR_FILENO);
  int counter=0;
  while(1) {
    // main program here
    char filename[100];
    if(counter % 30 == 0) {
    	time_t T = time(NULL);
    	strcpy(filename, "/home/hisam/log/");
    	strftime(filename+strlen(filename), 100, "%d:%m:%Y-%H:%M", localtime(&T));
	mkdir(filename, S_IRWXU | S_IRWXG | S_IRWXO );
	counter=0;
    }

    counter++;
    char cntr[5]; 
    char filename2[120]; 
    strcpy(filename2,filename);

    strcpy(filename2+strlen(filename2), "/log");
    sprintf(cntr,"%d",counter);
    strcpy(filename2+strlen(filename2), cntr);
    strcpy(filename2+strlen(filename2), ".log");
    creat(filename2, S_IRWXU | S_IRWXG | S_IRWXO );
    
    FILE *fptr1, *fptr2;
    char c;
    fptr1 = fopen("/var/log/syslog", "r");
    
    fptr2 = fopen(filename2, "w");
    
    c = fgetc(fptr1); 
    while (c != EOF) 
    { 
        fputc(c, fptr2); 
        c = fgetc(fptr1); 
    } 
    sleep(60);
  }
  
  exit(EXIT_SUCCESS);
}
