#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>

    static int parse_ext(const struct dirent *dir)
   {
     if(!dir)
       return 0;

     if(dir->d_type == DT_REG) { 
         const char *ext = strrchr(dir->d_name,'.');
         if((!ext) || (ext == dir->d_name))
           return 0;
         else {
           if(strcmp(ext, ".png") == 0)
             return 1;
         }
     }
     return 0;
   }


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

  if ((chdir("/home/alfin/Desktop/modul2/no1")) < 0) {
    exit(EXIT_FAILURE);
  }

  close(STDIN_FILENO);
  close(STDOUT_FILENO);
  close(STDERR_FILENO);

  while(1) {

       struct dirent **namelist;
       int n;
       n = scandir(".", &namelist, parse_ext, alphasort);
       if (n < 0) {
           perror("scandir");
           return 1;
       }
       else {
           while (n--) {
                int pjg, len;
               char ku[100],temp[100]="",nama[100]="_grey.png",kosongan[100]="", namafolder[1000]="/home/alfin/modul2/gambar/", akhir[100];
                strcpy(ku,namelist[n]->d_name);
                pjg = strlen(ku);
                len = pjg - 4;
                int b=0;
                for(int i=0;i<len;++i)
                {
                        temp[b]=ku[i];
                        b++;
                }
                strcpy(kosongan,(strcat(temp,nama)));
                strcpy(akhir,(strcat(namafolder,kosongan)));
                rename(ku, akhir);           }
           free(namelist);
       }
    sleep(1);
  }
 
  exit(EXIT_SUCCESS);
}
