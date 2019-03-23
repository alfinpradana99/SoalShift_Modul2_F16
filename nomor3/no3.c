#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/stat.h>

int p[2];

int main() {

pid_t satu;
pid_t dua;
pid_t tiga;

char *unzip[] = {"unzip", "/home/alfin/Desktop/modul2/nomor3/campur2.zip", NULL};
char *ls[]= {"ls", "/home/alfin/Desktop/modul2/nomor3/campur2", NULL};
char *grep[]= {"grep", "[.]txt$", NULL};
char *touch[]={"touch", "/home/alfin/Desktop/modul2/nomor3/daftar.txt", NULL};

int tunggu;
int tunggu2;
int tunggu3;

pipe(p);

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
          close(p[0]);
	  execvp("ls", ls);
        }
}
else
{
while ((wait(&tunggu)) > 0);
	//printf("4\n")
	int file_desc = open("daftar.txt",O_WRONLY);
        dup2(p[0], 0);
        close(p[1]);
        dup2(file_desc, 1);
        execvp("grep", grep);
	close(p[0]);
}
return 0;
}
