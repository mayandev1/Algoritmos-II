#include <stdio.h>
#include <stdlib.h>

int main(){
 
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            if ((i + j) % 2 == 0){
                printf("0 ");
            } else {
                printf("1 ");
            }
            
        }
        printf("\n");        
    }
    
    return 0;
}