#include <stdio.h>

int main() {
    
    char first_name[20];
    char last_name[20];
    
    printf("Please enter your first name: ");
    scanf("%s", &first_name);
    
    printf("Please enter your last name: ");
    scanf("%s", &last_name);
    
    printf("Your first name is: %c\n", first_name[0]);
    printf("Your last name is: %c", last_name[0]);
    
    return 0;
}