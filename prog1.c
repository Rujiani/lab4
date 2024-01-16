#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>

#define DELIM " \t"

int math_stuff(const char *str);

int main(){
    char *input = readline("> ");
    int res = math_stuff(input);
    printf("Result: %d\n", res);
    free(input);
    return 0;
}

int math_stuff(const char *str){
    char *str_temp = strdup(str);
    int str_len = strlen(str_temp);
    char *p = strtok(str_temp, DELIM);
    long res = strtol(p, NULL, 10);
    long num;
    p = strtok(NULL, DELIM);
    while(p){
        if(strcmp(p, "+") == 0){
            p = strtok(NULL, DELIM);    
            num = strtol(p, NULL, 10);;
            res += num;
        }
        else if(strcmp(p, "-") == 0){
            p = strtok(NULL, DELIM);
            num = strtol(p, NULL, 10);
            res -= num;
        }
        else{
             printf("ERROR!!!!!!\n");
             break;
        }
    p = strtok(NULL, DELIM);
    }
    free(str_temp);
return res;
}
 
