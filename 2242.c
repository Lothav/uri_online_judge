
#include <stdio.h>
#include <string.h>

int main() {
    char laugh[50];
    int i;

    size_t last_pos = 0;
    scanf("%s", laugh);

    last_pos = strlen(laugh) - 1;

    int count = 0;
    for(i = 0; i < strlen(laugh); i++){
        count += laugh[i] == 'a' || laugh[i] ==  'e' || laugh[i] ==  'i' || laugh[i] ==  'o' || laugh[i] == 'u' ? 1 : 0;
    }
    if(!count){
        printf("N\n");
        return 0;
    }

    i = 0;
    while(i < last_pos){
        while(laugh[i] != 'a' && laugh[i] != 'e' && laugh[i] != 'i' && laugh[i] != 'o' && laugh[i] != 'u'){
            i++;
            if(i > last_pos || i == last_pos){
                printf("S\n");
                return 0;
            }
        }
        while(laugh[last_pos] != 'a' && laugh[last_pos] != 'e' && laugh[last_pos] != 'i' && laugh[last_pos] != 'o' && laugh[last_pos] != 'u'){
            last_pos--;
            if(i > last_pos || i == last_pos){
                printf("S\n");
                return 0;
            }
        }
        if(laugh[last_pos] != laugh[i]){
            printf("N\n");
            return 0;
        }
        i++;
        last_pos--;
        if(i == last_pos ){
            printf("S\n");
            return 0;
        }
    }
    printf("S\n");

    return 0;
}
