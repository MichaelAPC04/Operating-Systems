/* task3_unit_code.h */

#include <stdio.h>
#include <string.h>

typedef struct{
    char *FacID;   // facaulty ID, for example: FIT , ENG, MTH, SCI, etc.
    int UnitID;    // unit ID, for example: 1047, 2100, 3142, etc.
} UnitCode;

int compareUnitCodes(UnitCode unit1, UnitCode unit2){

    if(strcmp(unit1.FacID, unit2.FacID) != 0 || unit1.UnitID != unit2.UnitID){
        return 0;
    }

    return 1;

}

int main(){
    UnitCode unit1 = {"FIT", 2100};
    UnitCode unit2 = {"MTH", 1830};

    if(compareUnitCodes(unit1, unit2)){
        printf("These units are equal\n");
    } else {
        printf("These units are not equal\n");
    }

    return 0;
}