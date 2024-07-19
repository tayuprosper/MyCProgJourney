//======================================//
//      linkedlist.c                   //
//                                    //
//   implementin a basic linked list in c //
//====================================//

//including header files
#include <stdio.h>
#include <stdlib.h>

//function prototypes
//insert element at the beggining of the list
int insertToFirst(int d);   //return 0 if successful else 1
//insert element at the end
int insertToLast(int d);  //returns 0 if successful else 1
//print all element in list
void printAll();
//delete an element
int deleteElement(int e);


//Node for value and pointer to next

typedef struct
{
    int value;
    struct Node* next;
}Node;

Node* head = NULL;

int insertToFirst(int d)
{

    Node* node = (Node*)malloc(sizeof(Node));
    (*node).value = d;
    (*node).next = head;
    head = node;
    return 0;
    
}

int insertToLast(int d)
{
    Node* node = head;
    Node* to_insert = (Node*)malloc(sizeof(Node));

    while(node->next!=NULL){
        node = node->next;
    }
    to_insert->value = d;
    to_insert->next = NULL;
    node->next = to_insert;
    
    return 0;
}

int deleteElement(int d)
{
    Node* n = head;
    Node* prev;
    Node* next;
    if (head->value == d){
            head = n->next;
            free(n);
            return 0;
        }else{
            n = n->next;
            prev = head;
            next = n->next;
            while(n->next != NULL){
                if (n->value == d){
                    prev->next = next;
                    free(n);
                    return 0;
                }
                prev =n;
                n = n->next;
                next = n->next;
            }
        }
    return 0;
}

void printAll()
{
    Node* n = head;
    while(n->next != NULL){
        printf("---------------------------------\n");
        printf("|    %d    |",n->value);
         printf("   %p    |\n",n->next);
        printf("---------------------------------\n");
        n = n->next;
    }
}

void fillList(){
    int number;
    int pos;
    for (int i = 0;i<5;i++)
    {
        printf("Enter number: ");
        scanf("%d",&number);
        printf("Enter position to insert: ");
        scanf("%d",&pos);
        if (pos == 1){
            insertToFirst(number);
        }else{
            insertToLast(number);
        }
    }
}

int main()
{
    int number;
    printf("Enter the head of the list: ");
    scanf("%d",&number);
    Node* n = (Node*)malloc(sizeof(Node));
    (*n).value = number;
    (*n).next = NULL;
    head = n;
    int pos;
 

    printAll();
    int del;
    printf("Enter number to delete: ");
    scanf("%d",&del);
    int res = deleteElement(del);;;;;;;;

    printAll();
    return 0;
}