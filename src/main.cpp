#include <iostream>

using namespace std;

class Email{

    public :
    int pri;
    std::string msg;

};

class ListaEmail{

    public :
    Email *data=NULL;
    ListaEmail *next=NULL;

};

class CaixaDeEntrada{

    public :
    ListaEmail *listaEmail;

    void push(Email *new_email){

        /* 1. create and allocate node */
        ListaEmail* newNode = new ListaEmail;
        
        /* 2. assign data to node */
        newNode->data = new_email;
        
        if(this->listaEmail == NULL){
            this->listaEmail = newNode;
        }
        else{
            ListaEmail* aux = new ListaEmail;
            ListaEmail* Node = this->listaEmail;
            Node = this->listaEmail;
            if(Node->data->pri<newNode->data->pri){

                aux=this->listaEmail;
                newNode->next=aux;
                this->listaEmail = newNode;
                delete aux;

            }
            else{
                while (Node->next->data->pri>=newNode->data->pri || Node->next==NULL)
                {
                    Node=Node->next;
                }
                aux=Node->next;
                newNode->next=aux;
                Node->next = newNode;
                delete aux;
            }
            
        }

    } 

};

class Usuario
{

    unsigned int id;
    ListaEmail inbox;

};

