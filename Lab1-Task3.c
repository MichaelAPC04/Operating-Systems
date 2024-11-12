#include <stdio.h>
#include <math.h>
#define M_PI 3.14159265358979323846

int main() {
    int radius, height;

    printf("Please enter the radius: ");
    scanf("%d", &radius);
    
    printf("Please enter the height: ");
    scanf("%d", &height);
    
    float surface_area = (2 * M_PI * radius * height) + (2 * M_PI * pow(radius, 2));
    float volume = M_PI * pow(radius, 2) * height;
    
    printf("Your surface area is: %.2f", surface_area);
    printf("\nYour volume is: %.2f", volume);

    return 0;
}