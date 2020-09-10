#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct 
{
    char dirName[10];
    char fileName[10][10];
    int fileCount;
}dir;

void main()
{
    int i,ch;
    char tmp[10];
    dir.fileCount=0;
    printf("Enter the name for the directory = ");
    scanf("%s",dir.dirName);

    while (1)
    {
        printf("\n1. Create a File\n2. Delete a File\n3. Search in Directory\n4. Display \n5. Exit\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch (ch) 
        {

            case 1:
                printf("Enter the name of the file = ");
                scanf("%s",dir.fileName[dir.fileCount++]);
                break;

            case 2:
                printf("Enter the name of the file to delete = ");
                scanf("%s",tmp);
                for (i=0;i<dir.fileCount;i++)
                {
                    if (strcmp(tmp,dir.fileName[i])==0)
                    {
                        printf("The File %s is deleted!!\n", tmp);
                        strcpy(dir.fileName[i],dir.fileName[dir.fileCount-1]); 
                        break;
                    }    
                }     
                if (i==dir.fileCount) 
                    printf("File Is Not Found!!\n");
                else    
                    dir.fileCount--;
                break;

            case 3:
                printf("Enter the name of the file to be searched for = ");
                scanf("%s",tmp);
                for (i=0;i<dir.fileCount;i++) 
                {
                    if (strcmp(tmp,dir.fileName[i])==0) 
                    {
                        printf("File Found!!");
                        break;
                    }
                }
                if (i==dir.fileCount) 
                    printf("File Is Not Found");
                break;

            case 4:
                if (dir.fileCount==0) 
                 {
                    printf("Directory Empty!!!");
                 }
                else 
                 {
                    printf("Files:\n");
                    for (i=0;i<dir.fileCount;i++)
                    {
                        printf("%s\n",dir.fileName[i]);
                    }
                    printf("Total %d files in directory",dir.fileCount);
                 }
                break;

            default:exit(0);
        }
    }
}
