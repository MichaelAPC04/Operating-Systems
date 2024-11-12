#include <stdio.h>
#include <math.h>

int* find_closest_to_average(int the_array[], int num_elements) {
   
    float total = 0;
    for (int i = 0; i < num_elements; i++) {
        total += the_array[i];
    }
    float average = total / num_elements;

    int* closest = &the_array[0];
    double min_diff = fabs(the_array[0] - average);

    for(int i = 1; i < num_elements; i++){
        double diff = fabs(the_array[i] - average);
        if(diff < min_diff){
            min_diff = diff;
            closest = &the_array[i];
        }

    }

    return closest;

}


int main() {

    int num_elements;

    printf("Please enter the length of your array: ");
    scanf("%d", &num_elements);

    int array[num_elements];

    printf("Please enter the elements of your array: \n");
    for(int i = 0; i < num_elements; i++){
        scanf("%d", &array[i]);
    }
    
    int* closest = find_closest_to_average(array, num_elements);

    if (closest != NULL) {
        printf("The element closest to the average is: %d\n", *closest);
    } else {
        printf("No closest element found.\n");
    }
    
    return 0;
}