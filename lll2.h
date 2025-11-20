




#ifndef __LINKED_LIST_LIBRARY_H
#define __LINKED_LIST_LIBRARY_H



#define LLL_VERSION_MAJOR 0
#define LLL_VERSION_MINOR 2




#include <stdlib.h>
#include <stdio.h>





struct Node
{
    int id;
    struct Node *next;
};






#ifdef LLL_DEBUG



#ifdef _WIN32
    #define LLL_DEBUG_PRINT(fmt, ...) \
        do { fprintf(stdout, "[DEBUG] " fmt, __VA_ARGS__); } while (0)
#else
    #define LLL_DEBUG_PRINT(fmt, ...) \
        do { fprintf(stdout, "[DEBUG] " fmt, ##__VA_ARGS__); } while (0)
#endif


#define LLL_DEBUG_NODE(n) \
    do \
    { \
        if (n) \
        { \
            LLL_DEBUG_PRINT("Node at %p -> id: %d, next: %p\n", (void*)(n), (n)->id, (void*)((n)->next)); \
        } \
        else \
        { \
            LLL_DEBUG_PRINT("Node is NULL\n"); \
        } \
    } while(0)


#define LLL_DEBUG_LIST(head) \
    do \
    { \
        node_ptr tmp=(head); \
        int idx=0; \
        while(tmp) \
        { \
            LLL_DEBUG_PRINT("Node[%d]: ", idx); \
            LLL_DEBUG_NODE(tmp); \
            tmp=tmp->next; \
            idx++; \
        } \
        if (idx==0) \
        { \
            LLL_DEBUG_PRINT("Empty list\n"); \
        } \
    } while(0)




#endif








typedef struct Node node;
typedef struct Node *node_ptr;









node_ptr addNodeTail(node_ptr head, int number_id)
{
    node_ptr new_node=(node_ptr) malloc(sizeof(node));

    if (!new_node) return NULL; 
    new_node->id=number_id;
    new_node->next=NULL;

    if (!head) return new_node; 

    node_ptr current=head;
    while (current->next) 
    {
        current=current->next;
    }
    current->next=new_node;
    return head;
}

node_ptr addNodeHead(node_ptr head, int number_id)
{
    node_ptr new_node=(node_ptr) malloc(sizeof(node));
    if (!new_node) return NULL; 
    new_node->id=number_id;
    new_node->next=head; 
    return new_node;       
}

node_ptr addNodeMiddle(node_ptr head, int number_id)
{
    node_ptr new_node=(node_ptr) malloc(sizeof(node));
    if (!new_node) return NULL; 
    new_node->id=number_id;

    if (!head) 
    {
        new_node->next=NULL;
        return new_node; 
    }

    
    node_ptr slow=head;
    node_ptr fast=head;
    while (fast->next && fast->next->next) 
    {
        slow=slow->next;
        fast=fast->next->next;
    }

    
    new_node->next=slow->next;
    slow->next=new_node;

    return head;
}


node_ptr addNodoInPosition(node_ptr head, int number_id, int position)
{
    node_ptr new_node=(node_ptr) malloc(sizeof(node));
    
    if (!new_node) return NULL; 
    new_node->id=number_id;
    new_node->next = NULL;

    
    if (!head || position <= 0)
    {
        new_node->next=head;
        return new_node;
    }

    node_ptr current=head;
    int index=0;

    
    while (current->next && index < position - 1)
    {
        current=current->next;
        index++;
    }

    
    new_node->next=current->next;
    current->next=new_node;

    return head;
}



void debugPrint(const char *msg)
{
    printf("[DEBUG] %s\n", msg);
}




void debugNode(node_ptr n)
{
    if (n)
        printf("[DEBUG] Node -> id: %d\n", n->id);
    else
        printf("[DEBUG] Node is NULL\n");
}





void debugList(node_ptr head)
{
    node_ptr tmp = head;
    int i = 0;

    if (!tmp)
    {
        printf("[DEBUG] Empty list\n");
        return;
    }

    while (tmp)
    {
        printf("[DEBUG] Node[%d]: %d\n", i, tmp->id);
        tmp = tmp->next;
        i++;
    }
}






void printList(node_ptr head)
{
    node_ptr current = head;

    while (current)
    {
        printf("%d -> ", current->id);
        current = current->next;
    }

    printf("NULL\n");
}




#endif 
