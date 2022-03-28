#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/types.h>

char* firstWord(char* sentence , int index){ 
    char* ans = malloc(index*sizeof(char));
    int i = 0;
    while( i < index)
    {
        ans[i] = sentence[i];
        i++;
    } 
    return ans;
}

#define SIZE 1

void getTheEcho(char* sentence){
    int length = strlen(sentence);
    if (length<=5){return "";}
    if(sentence[4]!=' '){printf ("you need to add a space between echo and the text\n");}
    else{
    char* ans = malloc((length-4-1)*sizeof(char));
    int i = 4;
    while (i < length){
        ans[i-4] = sentence[i];
        i++;
    }
    printf("%s\n",ans);
    free(ans);
    }
}


void getListDir(const char* path){
    struct dirent *dp;
    DIR *dir = opendir(path);
    if(!dir){printf("");}
    while ((dp = readdir(dir)) != NULL)
    {   
        char file[50];
        strcpy(file,dp->d_name);
        if (strcmp(file,".")!=0 && strcmp(file,"..")!=0 )
        {
        printf("%s  ", dp->d_name);
        }  
    }
    printf("\n");
    closedir(dir); 
}

void changeDir(const char* nextPath){
    char path[100];
    int length = strlen(nextPath);
    int i = 3;
    char* ans = malloc(length-3);
    while (i < length)
    {
        ans[i-3] = nextPath[i];
        i++;
    }
    int val = chdir(ans); 
    if (val != 0){
        printf("wrong directory name \n");
    }
    free(ans);
}


void copyTxt(const char* fileto){
    
    char *cmad[6]; 
    strcpy(cmad,strtok(fileto," "));
    printf("%s\n",cmad);

    char *src[50];
    strcpy(src , strtok(NULL," "));
    printf("%s\n",src);

    char *dest[50];
    strcpy(dest , strtok(NULL," "));
    printf("%s\n",dest);
    
    char buf[SIZE];
    int count ;
    FILE *file1;
    FILE *file2;

// open file source
    file1 = fopen(src , "r");
    printf("file1 was open");
    
// open file destination
    file2 = fopen(dest , "a");
    printf("file2 was open");

// copy all the file 
    while (count = fread(buf , 1 ,SIZE , file1) != 0)
    {
        int wr = fwrite(buf , 1 , sizeof(buf) , file2);
        printf("\na part was copied , buff = %s\n",buf);
        if (wr < 0)
        {
            perror("error occur while writing to the dest file \n");
            break;
        }
    }
    fclose(file1);
    fclose(file2);
}

void delete_file(const char* file_to_del){
    char *cmad[6]; 
    strcpy(cmad,strtok(file_to_del," "));
    printf("%s\n",cmad);

    char *file[100];
    strcpy(file , strtok(NULL," "));
    printf("%s\n",file);

    FILE *fp = fopen(file , "r");
    if (fp)
    {
        unlink(file);
        fclose(fp);
    }
    else
    {
        perror("there is no file with this name");
    }

}