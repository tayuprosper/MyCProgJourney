//c program demostrationg the use of malloc a technique to dynamically allocate memory for a data structure
//in the heap section during run time and not compile time

#include <stdio.h>

int main(){
//declear the name for the memory as a pointer. i don't know why! :(

    int *data;
    //alocate the memory using the funcion malloc(sizeof(datatype) * the number of items to be stored)
    data = malloc(sizeof(int) * 10);
    //if an error occures data willb return NULL
    //check for any error (if data == NULL)
    if (data == NULL){
    //an arror we don't occurred while allocation memory print the error
        printf("OOPs!! There was a problem allocation the memory\n");
    }else{
        printf("Hurray!! Memory allocated succefully\n");
        printf("The location is at %p\n\n",data);
    }
//fill the memory block with number from 0 to n for example
    for (int i = 0; i<=  9; i++){
        data[i] = i+1;
    }

//print memory location and coresponding vallues
for (int i = 0; i<=  9; i++){
        printf("At %p we have %d \n",data[i],data[i]);
    }
//free the alocated memory when finished
    free(data);
return 0;
}
