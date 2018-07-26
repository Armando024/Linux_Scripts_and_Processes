#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>
//takes the source.tx and copies the content to destination.txt

int main(int argc,char *argv[]) {
	
	int returnval,source;
	
	returnval=access("source.txt",R_OK);
	if(returnval==0) {
		//file can be read and exist
		 source=open("source.txt",O_RDONLY);
		}
	//creating destination file or opening destination file
  int fd;
   if(2!=argc){
   printf("\n Usage : \n");
   return 1;
  }
  //open the file in write mode or creates it if it does not exists
  //the user also gets write and read permissions
  errno=0;
  fd=open(argv[1],O_WRONLY|O_CREAT,S_IRWXU);

  //checks if there is a error opening the file
  if(-1==fd) {
    printf("open() failed with error[%s]\n",strerror(errno) );
    return 1;
}

char display[15]; //15 bytes then so on it will continue
//when i=0 the for loop would end

for(int i=-1;i!=0;i=read(source,display,15)) 
	write(fd,display,i);
	
	close(fd);//closing the file
	close(source); //cosing the source file
	
  return 0;
}







