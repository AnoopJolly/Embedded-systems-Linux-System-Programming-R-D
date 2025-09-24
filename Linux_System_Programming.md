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
        printf("Enter file name :");
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
