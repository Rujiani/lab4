#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>

#define DELIM " \t"

char *math_stuff(const char *str);

int main(){
    char *input = readline("> ");
    char *res = math_stuff(input);
    printf("%s\n", res);
    free(res);
    free(input);
    return 0;
}

char *math_stuff(const char *str){
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
    int counter = 0, temp_res = res;
    while(temp_res){
        counter += 1;
        temp_res /= 10;
    }
    if(!counter){
        counter++;
    }
    char *result = malloc(counter + 4 * sizeof(char));
    snprintf(result, sizeof result, " = %d", res); 
    char *res_str = strdup(str);
    strcat(res_str, result);
    free(result);
    free(str_temp);
    return res_str;
}
 
