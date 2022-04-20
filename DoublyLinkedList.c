// Program: Doubly Linked head
// Coder  : Khalid Saifullah Fuad
// Date   : 14-Apr-2022

#include<stdio.h>
#include<stdlib.h>

#define NULL_VALUE 0
#define SUCCESS_VALUE 1
#define ERROR_VALUE -1

struct node
{
    struct node *prev; // for previous node
    int data; // for storing data
    struct node *next; // for next node
};

struct node *head;
struct node *tail;
int length;


// Initializing the list with setting all values to 0
void initializeList()
{
    head = NULL_VALUE;
    tail = NULL_VALUE;
    length = 0;
}

// Delete the last occurrence of the item in the head
int deleteLastOccurrence(int item)
{
    struct node *tempNode = head, *targetNode = NULL_VALUE;

    while(tempNode != NULL_VALUE)
    {
        if(tempNode->data == item)
            targetNode = tempNode;

        tempNode = tempNode->next;
    }

    if(targetNode != NULL_VALUE)
    {
        struct node *prevNode = targetNode->prev;
        struct node *nextNode = targetNode->next;

        if(prevNode == NULL_VALUE)
            head = nextNode;
        else
            prevNode->next = nextNode;

        if(nextNode != NULL_VALUE)
            nextNode->prev = prevNode;

        length--;

        return SUCCESS_VALUE;
    }

    return ERROR_VALUE;
}

// Delete the first item of the head
int deleteHead()
{
    if (length == 0) return ERROR_VALUE;

    struct node *headNode = head;
    head = headNode->next;

    if(head != NULL_VALUE)
        head->prev = NULL_VALUE;
    else
        tail = head;

    length--;

    return SUCCESS_VALUE;
}

// Delete the last item of the head
int deleteTail()
{
    if (length == 0) return ERROR_VALUE;

    struct node *tempNode = tail->prev;

    if(tempNode == NULL_VALUE)
        head = tempNode;
    else
        tempNode->next = NULL_VALUE;

    tail = tempNode;

    length--;

    return SUCCESS_VALUE;

}

// Insert item at the start of the doubly list
int insertItemFirst(int item)
{
    struct node *newNode = (struct node*) malloc(sizeof(struct node));
    newNode->prev = NULL_VALUE;
    newNode->data = item;
    newNode->next = head;

    if(newNode->next == NULL_VALUE)
    {
        tail = newNode;
    }
    else
    {
        tail->next = head->prev;
        head->prev = newNode;
    }
    head = newNode;

    length++;

    return SUCCESS_VALUE;
}

// Insert item at the end of the doubly list
int insertItemLast(int item)
{
    struct node *newNode = (struct node*) malloc(sizeof(struct node));
    newNode->prev = tail;
    newNode->data = item;
    newNode->next = NULL_VALUE;

    if(newNode->prev == NULL_VALUE)
        head = newNode;
    else
        tail->next = newNode;

    tail = newNode;

    length++;

    return SUCCESS_VALUE;
}

// Print the doubly linked list
void printList()
{
    printf("--------------------\n");
    printf("[");

    struct node *tempNode = head;

    while(tempNode != NULL_VALUE)
    {
        printf("%d", tempNode->data);
        tempNode = tempNode->next; // move to next node

        if(tempNode != NULL_VALUE)
            printf(", "); // print comma between items
    }
    printf("]\n");
}

int main()
{
    int choice, number;

    printf("--------------------\n");
    printf(" Singly Linked List\n");
    printf("--------------------\n");
    printf("1. Insert Item First\n");
    printf("2. Insert Item Last\n");
    printf("3. Delete First Item\n");
    printf("4. Delete Last Item\n");
    printf("5. Delete Last Match\n");
    printf("6. List Length\n");
    printf("7. Exit\n");

    initializeList();

    do {
        printf("--------------------\n");
        printf(">>> ");

        scanf("%d", &choice);

        printf("--------------------\n");
        if (choice == 1) {
            printf("    INSERT FIRST  \n");
            printf("--------------------\n");
            printf("Enter a Number : ");

            scanf("%d", &number);

            insertItemFirst(number);
            printList();

        } else if (choice == 2) {
            int position;
            printf("    INSERT LAST  \n");
            printf("--------------------\n");
            printf("Enter a Number : ");

            scanf("%d", &number);

            insertItemLast(number);
            printList();

        } else if (choice == 3) {
            printf(" DELETE FIRST ITEM  \n");
            printf("--------------------\n");

            int value = deleteHead(number);
            if (value == SUCCESS_VALUE)
                printf("Delete Successful!!\n");
            else if (length == 0)
                printf("  List is Empty!!\n");
            else
                printf("Failed to Delete !!\n");

            printList();

        } else if (choice == 4) {
            printf("  DELETE LAST ITEM  \n");
            printf("--------------------\n");

            int value = deleteTail(number);
            if (value == SUCCESS_VALUE)
                printf("Delete Successful!!\n");
            else if (length == 0)
                printf("  List is Empty!!\n");
            else
                printf("Failed to Delete !!\n");

            printList();

        } else if (choice == 5) {
            printf("  DELETE LAST MATCH  \n");
            printf("--------------------\n");
            printf("Enter a Number : ");

            scanf("%d", &number);
            printf("--------------------\n");

            int value = deleteLastOccurrence(number);
            if (value == SUCCESS_VALUE)
                printf("Delete Successful!!\n");
            else if (length == 0)
                printf("  List is Empty!!\n");
            else
                printf("Failed to Delete !!\n");

            printList();
        } else if (choice == 6) {
            printf("     LIST LENGTH  \n");
            printf("--------------------\n");
            printf("Length : %d\n", length);
            printList();
        } else if (choice != 7) {
            printf("  INVALID OPTION!!  \n");
        }
    } while (choice != 7);

    printf("     THANK YOU     \n");
    printf("--------------------\n");

    return 0;
}
