#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/stat.h>


int main() {

pid_t satu;
pid_t dua;
pid_t tiga;

char *unzip[] = {"unzip", "/home/alfin/Desktop/modul2/campur2.zip", NULL};
char *ls[]= {"ls", "/home/alfin/Desktop/modul2/campur2", NULL};
char *grep[]= {"grep", ".txt", NULL};
char *touch[]={"touch", "/home/alfin/Desktop/modul2/daftar.txt", NULL};


int tunggu;
int tunggu2;
int tunggu3;

int p[2];
satu = fork();
if (satu == 0)
{
	dua = fork();

	if(dua == 0)
        {
	  tiga = fork();
          if(tiga == 0)
          {
           //printf("1\n");
           execv("/usr/bin/unzip", unzip);
          }
          else
          {
           while ((wait(&tunggu2)) > 0);
           //printf("2\n");
	   execv("/usr/bin/touch", touch);
          }
        }
        else
        {
          while ((wait(&tunggu3)) > 0);
          //printf("3\n");
	  dup2(p[1], 1);
	  execv("/bin/ls", ls);
        }
}
else
{
 while ((wait(&tunggu)) > 0);
	//printf("4\n");
	dup2(p[0], 0);
	close(p[1]);
	int file_desc = open("daftar.txt",O_WRONLY | O_APPEND);
        dup2(file_desc, 1) ;
	execv("/bin/grep/", grep);
}
return 0;
}
