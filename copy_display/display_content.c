#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>
#include<iostream>
//takes a file and displays content 
//report appropriate messages 
//	-does not exist
//      -can't be opened
//      -not correct permissions 
// used only open read write and close

int main(int argc,char *argv[]) {
	//no file was given
   int fd;
   if(2!=argc){
   printf("\n Usage : \n");
   return 1;
  }
  errno=0;
  fd=open(argv[1],O_RDONLY);
//check if file exist and gives out the reason such as permmision...
  if(-1==fd) {
    printf("\n open() failed with error[%s]\n",strerror(errno) );
    return 1;
}

char display[15]; //to display the 15 bytes then so on it will continue 
//when i=0 the for loop would end

for(int i=-1;i!=0;i=read(fd,display,15)) {
	i=write(1,display,i);
	}
	
	
	close(fd);//clsing the file
	
  return 0;
}







