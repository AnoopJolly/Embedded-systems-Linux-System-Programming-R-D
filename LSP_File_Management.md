## FILE MANAGEMENT
## 1. Write a C program to create a new text file and write "Hello, World!" to it?
```c
#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
        int fd;
        char filename[100];
        char content[100];
        printf("Enter File name:\t");
        scanf("%s",filename);
        getchar();
        fd=open(filename,O_WRONLY|O_CREAT|O_TRUNC,0666);
        if(fd==-1)
        {
                printf("ERROR");
                return -1;
        }
        printf("Enter the content:\t");
        fgets(content,sizeof(content),stdin);
        content[strcspn(content,"\n")]='\0';
        write(fd,content,100);
        printf("Succesfull");
        close(fd);
        return 0;
}
```
## 2. Develop a C program to open an existing text file and display its contents?
```c
#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
        int fd;
        char filename[100];
        char content[100];
        printf("Enter File name:\t");
        scanf("%s",filename);
        getchar();
        fd=open(filename,O_RDONLY,0666);
        if(fd==-1)
        {
                printf("ERROR");
                return -1;
        }
        while((read(fd,content,5))!=0)
        {
                printf("%s",content);
        }


        printf("\nSuccesfull");
        close(fd);
        return 0;
}
```
## 3. 3Implement a C program to create a new directory named "Test" in the current directory?
```c
#include<stdio.h>
#include<sys/stat.h>
int main()
{
        int status;
        char foldername[100];
        printf("Enter folder name :");
        scanf("%s",foldername);
        status=mkdir(foldername,0777);
        if(status==0)
        {
                printf("File %s created successfully\n",foldername);
        }
        else
        {
                printf("ERROR");
        }
        return 0;
}
```
## 4. Write a C program to check if a file named "sample.txt" exists in the current directory?
```c
#include<stdio.h>
#include<string.h>
#include<fcntl.h>
int main()
{
        char filename[100];
        int fd;
        printf("Enter the file name\t:");
        scanf("%s",filename);
        fd=open(filename,O_RDONLY,0777);
        if(fd==-1)
        {
                printf("ERROR FILE DOES NOT EXIST");
                return -1;
        }
        else
        {
                printf("FILE EXIST");

        }
        return 0;
}
```
### 5. Develop a C program to rename a file from "oldname.txt" to "newname.txt"?
```c
#include <stdio.h>
#include<string.h>
int main() {
    int result;
    char oldfilename[100];
    char newfilename[100];
    printf("Enter the existing existing file name:" );
    scanf("%s",oldfilename);
    printf("Enter the new file name\t:");
    scanf("%s",newfilename);

    result = rename(oldfilename, newfilename);

    if (result == 0) {
        printf("File renamed successfully.\n");
    } else {
        perror("Error renaming file");
    }

    return 0;
}

```
## 6. Implement a C program to delete a file named "delete_me.txt"?
...c
#include <stdio.h>
#include<string.h>
int main() {
    int result;
    char filename[100];
    printf("Enter the file name to remove:" );
    scanf("%s",filename);
    result = remove(filename);
    if (result == 0) {
        printf("File removed successfully.\n");
    } else {
        perror("Error removing file");
    }

    return 0;
}
```
## 7. Write a C program to copy the contents of one file to another?
```c
#include<stdio.h>
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
        char filename[100];
        char filename2[100];
        char content[1000];
        printf("Enter source filename :");
        scanf("%s",filename);
        printf("Enter destination filename :");
        scanf("%s",filename2);

        int fd,fd2;
        fd=open(filename,O_RDONLY,0666);
        if(fd==-1)
        {
                printf("ERROR file 1 doesnot exist");
                return 1;
        }
        fd2=open(filename2,O_WRONLY|O_CREAT,0666);
        if(fd2==-1)
        {
                printf("ERROR file 2 doesnot exist");
                close(fd);
                return 1;
        }
        while((read(fd,content,5))!=0)
        {
                write(fd2,content,5);
        }
        close(fd);
        close(fd2);
        printf("Succesfull\n");
        return 0;
}
```
## 8. Develop a C program to move a file from one directory to another?
```c
#include<stdio.h>
int main()
{
        char source[256];
        char destination[256];
        printf("Enter the source path followed by filename");
        scanf("%255s",source);
        printf("Enter the destination path to move the file into");
        scanf("%255s",destination);

        if(rename(source,destination)==0)
        {
                printf("file moved succesfully from %s to %s\n",source,destination);
        }
        else
        {
                printf("ERROR unsuccesfull");
        }
        return 0;
}
```
## 9. Implement a C program to list all files in the current directory?
```c
#include<stdio.h>
#include<unistd.h>
int main()
{
          execlp("ls","ls",NULL,NULL);
          return 0;
}
```
## 10. Write a C program to get the size of a file named "file.txt"?
```c
#include<stdio.h>

int main()
{
        FILE *fp;
        char filename[100];
        long size;
        printf("enter the file name: ");
        scanf("%s",filename);
        fp = fopen(filename,"r");
        if(fp==NULL)
        {
                printf("ERROR file doesnot exist\n");
                return 1;
        }

        fseek(fp,0,SEEK_END);
        size=ftell(fp);
        fclose(fp);
        printf("Size of file %s is %ld bytes\n",filename,size);
        return 0;
}

```
```c
#include<stdio.h>
#include<sys/stat.h>
int main()
{
        struct stat st;

        if(stat("apple.txt",&st)==0)
        {
                printf("File found\n");
                printf("The size of the file apple.txt is %ld bytes",st.st_size);
        }
        else
        {
                printf("ERROR stat file not found\n");
                return 1;
        }
        return 0;
}
```
## 11. Develop a C program to check if a directory named "Test" exists in the current directory?
```c
#include<stdio.h>
#include<sys/stat.h>
int main()
{
        struct stat st;

        if((stat("test",&st))==0)
        {
                if(S_ISDIR(st.st_mode))
                {
                        printf("file: test\n File exist");
                }
                else
                {
                        printf("test exist but not a direcctory\n");
                }
        }
        else
        {
                printf("Does not exist\n");
        }
        return 0;
}
```
## 12. Implement a C program to create a new directory named "Backup" in the parent directory?
```c
#include<stdio.h>
#include<sys/stat.h>
int main()
{

        if((mkdir("Backup",0777))==0)
        {

                printf("Directory created succesfully\n");
        }
        else
        {
                printf("ERROR creating file");
        }

        return 0;
}
```



