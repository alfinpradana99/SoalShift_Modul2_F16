#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>
#include <pwd.h>
#include <grp.h>

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

  while(1) {
    // main program here
    
    struct stat isifile;
    char *directory = "/home/hisam/hatiku/elen.ku";
    stat(directory, &isifile);

    struct passwd *own;
    struct group *grp;

    own = getpwuid(isifile.st_uid);
    grp = getgrgid(isifile.st_gid);

    char perm[] = "0777";
    int c;
    c = strtol(perm,0,8);    
    chmod(directory, c);

    if(strcmp(own->pw_name, "www-data")==0 && strcmp(grp->gr_name, "www-data")==0) 
	remove(directory);

    sleep(3);
  }
  
  exit(EXIT_SUCCESS);
}

