#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<errno.h>
#include<fcntl.h>
#include<stdlib.h>
//converts my string into an int array
void ConvertToInt(char* ptr ,int arr[10][4],int* x,int* y) {
long *temp;
while(*ptr!='\0') {
if(*ptr!=' ' && *ptr!='\n' && *ptr!='\t' && *ptr!='\0') {
sscanf(ptr,"%d",&temp);
arr[*y][*x]=(long)temp; //x is columns 
*x=*x+1;
if (*x>=4) {
*x=0;
*y=*y+1;
}
if(*y>10){ 
printf("2d array is full\n"); 
return;
 }
//after copying we skip to the next step
while(*ptr!=' ' && *ptr!='\n' ) {
ptr++;
} }
ptr++; 
}
return;
}

int main(int argc,char *argv[]) {
int managers=1;
if(argc!=2) {
printf("No file was input\n");
return -1;
}
int fd=open(argv[1],O_RDONLY);
if(fd==-1) {
printf("open() failed \n");
return 1;
}

int arr[10][4]; //10 is rows 4 is colums 
char get[1024]; //im going to copy all my file to a large array
int row=0;
int column=0;
int zw=-1;
//read my file to it can be paste to my get
read(fd,get,1024); 
ConvertToInt(get,arr,&row,&column); 

//finish copying my file 
//creating two managers
int columnsread=1;
while(managers<=2) {
int man=fork();
int status;

waitpid(man,&status,0);

if(man==0) { 
//in manager
printf("Chapter %d\n",managers);
int tempy=2;
while(tempy>=1) {
int work=fork();
int stat;
waitpid(work,&stat,0);

if(stat==0) {
//in worker
double ave=0;
for(int i=0;i<10;i++) {
ave=ave+arr[i][columnsread];
}

printf("HW %d average = %f\n",tempy,(ave/10));
return 0;
}
else {
tempy--;
columnsread--;
}} return 0;
}
else {managers++;
columnsread=3;
} } 
close(fd);
return 0;
}
