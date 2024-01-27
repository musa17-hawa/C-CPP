// 206598146
// Musa Abu Alhawa
#include <stdio.h>
#include <stdlib.h>

// this is for dynamic string length, expands allocated string len value
char *inputString(FILE* fp, size_t size){
//The size is extended by the input with the value of the provisional
    char *str;
    int ch;
    size_t len = 0;
    str = realloc(NULL, sizeof(*str)*size);//size is start size
    if(!str)return str;
    while(EOF!=(ch=fgetc(fp)) && ch != '\n'){
        str[len++]=ch;
        if(len==size){
            str = realloc(str, sizeof(*str)*(size+=16));
            if(!str)return str;
        }
    }
    // checking for exit input before printing the value
    if(strcmp(str, "exit") == 0){
        str[len++]='\0';
        return realloc(str, sizeof(*str)*len);        
    }
    else{
        int i=0;
        int result = 0;
        while(str[i]!='\0') {
            result +=str[i];
            i++;
        }
        printf("%d", result);
        str[len++]='\0';
        return realloc(str, sizeof(*str)*len);
    }
}

int main(void){
    int ex = 0;
    while(ex != 1){
        char *m;
        printf("\ninput string : ");
        m = inputString(stdin, 10);
        // getting ready to exit the program
        if(strcmp(m, "exit") == 0){
            ex = 1;
            return 0;
        }
        free(m);        
    }
}

// EOF
