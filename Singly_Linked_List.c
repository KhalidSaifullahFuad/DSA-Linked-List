// Program: Singly Linked List
// Coder  : Khalid Saifullah Fuad
// Date   : 03-Apr-2022

#include <stdio.h>
#include <stdlib.h>

#define SUCCESS_VALUE 1
#define NULL_VALUE 0

struct node {
    int data;
    struct node *link;
};

struct node *list = NULL_VALUE;
int length = 0;

/**
int deleteALLOccurence(int item);// Delete all the occurrence of the given item in the list with preserving order
int deleteLastOccurrence(int item);// Delete the last occurrence of the given item in the list
**/


int deleteAll(int item){
    if(length==0) return NULL_VALUE;

    struct node* tempNode = list, *prevNode, *foundNode;

    while(tempNode->link != NULL_VALUE){
        prevNode = tempNode;
        tempNode = prevNode->link;

        if(tempNode->data == item){
            foundNode = tempNode;
            prevNode->link = foundNode->link;
            length--;
        }
    }
    free(foundNode);
    printf("\n");
    return SUCCESS_VALUE;
}
// Deletes the first item of the list
int deleteHead() {
    if(length==0) return NULL_VALUE;

    struct node *headNode = list;
    list = headNode->link;

    free(headNode);
    length--;

    return SUCCESS_VALUE;
}

// Deletes the first item of the list
int deleteTail() {
    if(length==0) return NULL_VALUE;

    struct node *tailNode = list, *prevNode;

    while (tailNode->link != NULL_VALUE) {
        prevNode = tailNode;
        tailNode = tailNode->link;
    }

    prevNode->link = NULL_VALUE;
    free(tailNode);
    length--;

    return SUCCESS_VALUE;
}


// Insert item at the end of the list
int insertItemLast(int item) {
    struct node *node = (struct node *) malloc(sizeof(struct node));
    node->data = item;
    node->link = NULL_VALUE;

    if (length == 0) {
        list = node;
    } else {
        struct node *tailNode = list;
        while (tailNode->link != NULL_VALUE) {
            tailNode = tailNode->link;
        }
        tailNode->link = node;
    }

    length++;

    return SUCCESS_VALUE;
}

// Insert item at the given position of the list
int insertItemAt(int position, int item) {
    struct node *node = (struct node *) malloc(sizeof(struct node));
    node->data = item;

    if (length < position) {
        return NULL_VALUE;
    } else {
        int index = 0;
        struct node *prevNode = list, *nextNode;
        while (index < position-1) {
            prevNode = prevNode->link;
            index++;
        }
        nextNode = prevNode->link;
        prevNode->link = node;
        node->link = nextNode;
    }

    length++;

    return SUCCESS_VALUE;
}

// Number of the occurrence of the given item
int countItem(int item) {
    int count = 0;
    struct node *tempNode = list;
    while (tempNode != NULL_VALUE) {
        if (tempNode->data == item) {
            count++;
        }
        tempNode = tempNode->link;
    }
    free(tempNode);
    return count;
}

// Search an item in the linked list
struct node* searchItem(int item) {
    struct node *tempNode = list;
    while (tempNode != NULL_VALUE) {
        if (tempNode->data == item)
            return tempNode;

        tempNode = tempNode->link;
    }
    free(tempNode);
    return NULL_VALUE;
}

// Delete an item from list
int deleteItem(int item) {
    struct node *tempNode, *prevNode;
    tempNode = list;

    while (tempNode != NULL_VALUE) {
        if (tempNode->data == item)
            break;
        prevNode = tempNode;
        tempNode = tempNode->link;
    }

    if (tempNode == NULL_VALUE)
        return NULL_VALUE;

    if (tempNode == list) {
        list = list->link;
    } else {
        prevNode->link = tempNode->link;
    }
    length--;

    return SUCCESS_VALUE;
}

// Print the linked list
void printList() {
    printf("--------------------\n");
    printf("[");

    struct node *tempNode = list;

    while (tempNode != NULL_VALUE) {
        printf("%d", tempNode->data);
        tempNode = tempNode->link;

        if(tempNode != NULL_VALUE) printf(", ");
    }

    printf("]\n");
    free(tempNode);
}

int main() {
//    initList();

    insertItemLast(3);
    insertItemLast(1);
    insertItemLast(2);
    insertItemLast(3);
    insertItemLast(4);
    insertItemLast(3);

    printList();

    deleteAll(3);

    printList();




/**

    int choice, number;

    printf("--------------------\n");
    printf(" Singly Linked List\n");
    printf("--------------------\n");
    printf("1. Insert Item.\n");
    printf("2. Delete Item.\n");
    printf("3. Search Item.\n");
    printf("4. Exit\n");

    do {
        printf("--------------------\n");
        printf(">>> ");

        scanf("%d", &choice);

        printf("--------------------\n");
        if (choice == 1) {
            printf("  INSERT OPERATION  \n");
            printf("--------------------\n");
            printf("Enter a Number : ");

            scanf("%d", &number);

            insertItemLast(number);
            printList();

        } else if (choice == 2) {
            printf("  DELETE OPERATION  \n");
            printf("--------------------\n");
            printf("Enter a Number : ");

            scanf("%d", &number);
            printf("--------------------\n");

            int value = deleteItem(number);
            if ( value== SUCCESS_VALUE)
                printf("Delete Successful!!\n");
            else if(length == 0)
                printf("  List is Empty!!\n");
            else
                printf("Failed to Delete !!\n");

            printList();

        } else if (choice == 3) {
            printf("  SEARCH OPERATION  \n");
            printf("--------------------\n");
            printf("Enter a Number : ");

            scanf("%d", &number);
            printf("--------------------\n");

            struct node *node = searchItem(number);
            if (node != NULL_VALUE)
                printf("\nFound at %d!!\n", node);
            else
                printf("Not Found!!\n");

            printList();
        } else if (choice != 4)  {
            printf("  INVALID OPTION!!  \n");
        }
    } while (choice!=4);
**/
    return 0;
}
