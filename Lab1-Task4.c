#include <stdio.h>

void addition(int x, int y, int z);
void subtraction(int x, int y, int z);
void multiplication(int x, int y, int z);
void modulus(int x, int y, int z);

int main() {
   
    int x, y, z;
    
    printf("Please enter the first value: ");
    scanf("%d", &x);
    
    printf("Please enter the second value: ");
    scanf("%d", &y);
    
    printf("Please enter the third value: ");
    scanf("%d", &z);
    
    addition(x,y,z);
    subtraction(x,y,z);
    multiplication(x,y,z);
    modulus(x,y,z);

    return 0;
}

void addition(int x, int y, int z){
    int result = x + y + z;
    printf("\nAddition result: %d", result);
}

void subtraction(int x, int y, int z){
    int result = x - y - z;
    printf("\nSubtraction result: %d\n", result);
}

void multiplication(int x, int y, int z){
    int result = x * y * z;
    printf("Multiplication result: %d\n", result);
}

void modulus(int x, int y, int z){
    int result = (x % y) % z;
    printf("Modulus result: %d\n", result);
}
