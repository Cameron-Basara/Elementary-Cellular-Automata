#include <stdio.h>
#include <string.h>

int main(void){
    char str[4] = "hey";

    /*for (int i; i<5; i++){
        printf("%c", str[i-1]);
    }*/ 

    printf("%d, %c", strlen(str), str[3]);
    
    
}