#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    if (argc == 4) {
        int x = atoi(argv[1]);
        int y = atoi(argv[2]);
        int z = atoi(argv[3]);
        int gcd = 1;
        
        for(int i = 1; i <= x && i <= y && i <= z; i++){
            if(x % i == 0 && y % i == 0 && z % i == 0)
                gcd = i;
            }

        printf("The GCD of %d, %d, and %d is %d\n", x, y, z, gcd); 
    }

    else{
        printf("Invalid argument input\n");
    }

        return 0;
    }