#include <stdlib.h>
#include <stdio.h>

int* arr = {0};
int debug = 1;

void SystemOpen(int count){
    arr = malloc(sizeof(int) * count);
}

void SystemClose(){
    free(arr);
    printf("Memory freed\n");
}

void fatal_error(char* file,int line,char* message){
    printf("Fatal error in file: %s:%d. %s\n",file, line,message);
    SystemClose();
}

void assert_failed(char *file, int line, char* message, char* condition, int counter){
    if(debug == 0){
        return;
    }
    if(arr[counter] == 1){
        return;
    }
    printf("Assertion %s failed in file: %s:%d. %s\n",condition, file, line, message);
    char res;
    printf("Type (a)bort, (c)ontinue, (s)kip all aserts, (i)gnore current\n");
    scanf(" %c", &res);
    switch (res) {
        case 'a':
            printf("Aborting\n");
            exit(1);
        case 'c':
            printf("Continue\n");
            break;
        case 's':
            printf("Skip all aserts\n");
            debug = 0;
            break;
        case 'i':
            printf("Ignore current assert\n");
            arr[counter] = 1;
            break;
        default:
            printf("Wrong input, continue\n");
    }
}