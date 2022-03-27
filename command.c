#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>

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