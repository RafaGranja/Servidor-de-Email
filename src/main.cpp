#include <iostream>

using namespace std;

class Email{

    int pri;
    std::string msg;

};

class ListaEmail{

    Email data;
    ListaEmail *next;

};

class CaixaDeEntrada{

    ListaEmail *listaEmail;

    void push(Email new_email){

        /* 1. create and allocate node */
        ListaEmail* newNode = new ListaEmail;
        
        /* 2. assign data to node */
        newNode->data = new_email;
        
        if(this->data)

    }
        
        //insert new node after a given node
    void insertAfter(ListaEmail* prev_node, Email node_data){

        /*1. check if the given prev_node is NULL */
        if (prev_node == NULL)
        {
        cout<<"the given previous node is required,cannot be NULL"; return; } 
        
        /* 2. create and allocate new node */
        ListaEmail* newNode =new ListaEmail; 
        
        /* 3. assign data to the node */
        newNode->data = node_data;
        
        /* 4. Make next of new node as next of prev_node */
        newNode->next = prev_node->next;
        
        /* 5. move the next of prev_node as new_node */
        prev_node->next = newNode;

    }
        
        /* insert new node at the end of the linked list */
    void append(ListaEmail** head, Email node_data){

        /* 1. create and allocate node */
        ListaEmail* newNode = new ListaEmail;
        
        ListaEmail *last = *head; /* used in step 5*/
        
        /* 2. assign data to the node */
        newNode->data = node_data;
        
        /* 3. set next pointer of new node to null as its the last node*/
        newNode->next = NULL;
        
        /* 4. if list is empty, new node becomes first node */
        if (*head == NULL)
        {
            *head = newNode;
            return;
        }
        
        /* 5. Else traverse till the last node */
        while (last->next != NULL)
            last = last->next;
        
        /* 6. Change the next of last node */
        last->next = newNode;
        return;

    }
        
        // display linked list contents
    // void displayList(ListaEmail *node){

    //     //traverse the list to display each node
    //     while (node != NULL)
    //     {
    //         cout<<node->data<<"-->";
    //         node = node->next;
    //     }
        
    //     if(node== NULL)
    //     cout<<"null"; 
    // } 

};

class Usuario
{

    unsigned int id;
    ListaEmail inbox;

};

