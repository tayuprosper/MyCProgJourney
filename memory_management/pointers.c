#include <stdio.h>

main(){
    //declear a variable example an integer
    int a = 10;
    //create a pointer variable (int for example) to hold the memory location of a
    int *loca;
    //assign memory location of a to the pointer loca (location of a)
    loca = &a;
    //print the memory loction of a
    printf("%p",loca);
    return 0;
}
