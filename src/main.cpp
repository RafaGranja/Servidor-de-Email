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

        //CRIA E ALOCA UM NOVO EMAIL
        ListaEmail* newNode = new ListaEmail;
        
        //INPUTA O DADO NO EMAIL
        newNode->data = new_email;
        
        //SE A LISTA ESTA VAZIA CRIA UM HEAD
        if(this->listaEmail == NULL){
            this->listaEmail = newNode;
        }
        else{//SE NAO ESTA VAZIA
            //PROCURA UM LUGAR ONDE FICAR
            // LUGAR = ANTES DO PRIMEIRO EMAIL COM PRIRORIDADE MENOR
            ListaEmail* aux = new ListaEmail;
            ListaEmail* Node = this->listaEmail;
            Node = this->listaEmail;
            //SE FOR A CABECA COM PRIORIDADE MENOR
            if(Node->data->pri<newNode->data->pri){

                aux=this->listaEmail;
                newNode->next=aux;
                this->listaEmail = newNode;
                delete aux;

            }
            else{//SE NAO FOR
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

    //DESALOCA TODA LISTA
    void deletaCaixa(){

        //DECLARA ITERADOR
        ListaEmail *it = new ListaEmail();
        //DECLARA AUXILIAR
        ListaEmail *aux = new ListaEmail();

        while(this->listaEmail!=NULL){
            aux=this->listaEmail;
            this->listaEmail=this->listaEmail->next;
            delete aux->data;
            delete aux;
        }
    }

    void pop(){

        //DECLARA AUXILIAR
        ListaEmail *aux = new ListaEmail();

        //SE CAIXA DE EMAIL ESTA VAZIA
        if(this->listaEmail==NULL){
            cout << "CAIXA DE ENTRADA VAZIA" << endl;
        }
        else{
            cout << this->listaEmail->data->msg << endl;
            aux=this->listaEmail;
            this->listaEmail=this->listaEmail->next;
            delete aux->data;
            delete aux;
        }

    }

};

class Usuario
{
    public:

    unsigned int id;
    CaixaDeEntrada *inbox;
    Usuario *prox;

};

class ListaUsuarios{

    public:

    Usuario *user;

    //INSERE USUARIO CASO O ID NAO EXISTA
    void push(int _id){
        
        //DECLARA OS ITERADORES
        Usuario *it = new Usuario();
        Usuario *it_anterior = new Usuario();

        //NAO POSSUI USUARIO NENHUM
        if(this->user==NULL){

            this->user = new Usuario();
            this->user->id=_id;

        }
        else{//POSSUI USUARIO
            //CHECA SE O PRIMEIRO TEM O ID
            do{
                if(it->id==_id){
                    cout << "ERRO: CONTA "<<_id<<" JA EXISTENTE" << endl;
                    return;
                }
                else{
                    it_anterior=it;
                    it=it->prox;
                }
            }while(it!=NULL);
            //PERCORRE TODA A LISTA ATRAS DO ID E SE ENCONTRA PRINTA O ERRO E ACABA A A FUNCAO
            //SE NAO ENCONTRA O ID FAZ A CRIACAO DE UM NOVO ITEM E ATRIBUI O ID

            it_anterior->prox= new Usuario();
            it_anterior->prox->id=_id;
            cout << "OK: CONTA "<<_id<<" CADASTRADA" << endl;
            delete it;

        }

    }
    
    //DELETE USUARIO CASO O ID EXISTA
    void pop(int _id){

        //DECLARA ITERADOR
        Usuario *it = new Usuario();
        //DECLARA AUXILIAR
        Usuario *aux = new Usuario();

        //NAO POSSUI USUARIO NENHUM
        if(this->user==NULL){

            cout << "ERRO: CONTA "<<_id<<" NAO EXISTE" << endl;
            return;

        }
        else{// SE NAO

            if(this->user->id=_id){
                aux=this->user;
                this->user=this->user->prox;
                aux->inbox->deletaCaixa();//DESALOCA LISTA DE EMAIL
                delete aux->inbox;//DESALOCA CAIXA DE EMAIL
                delete aux;//DESALOCA USUARIO
                cout << "OK: CONTA "<<_id<<" REMOVIDA" << endl;
            }
            else{

                it=this->user;
                while (it->prox->id!=_id)//PERCORRE A LISTA ATE ENCONTRAR O ID NO PROXIMO 
                {   
                    if(it->prox==NULL){
                        cout << "ERRO: CONTA "<<_id<<" NAO EXISTE" << endl;
                        return;
                    }
                    else{
                        it=it->prox;
                    }
                }
                aux=it->prox;
                it->prox=it->prox->prox;
                aux->inbox->deletaCaixa();//DESALOCA LISTA DE EMAIL
                delete aux->inbox;//DESALOCA CAIXA DE EMAIL
                delete aux;//DESALOCA USUARIO
                cout << "OK: CONTA "<<_id<<" REMOVIDA" << endl;
                

            }

        }
    }

    //LE O PRIMEIRO EMAIL DO USUARIO CASO ELE EXISTA E POSSUA EMAIL
    void busca(int _id){

        //DECLARA ITERADOR
        Usuario *it = new Usuario();

        if(this->user==NULL){

            cout << "ERRO: CONTA "<<_id<<" NAO EXISTE" << endl;
            return;

        }
        else{// SE NAO

            it=this->user;
            while (it->id!=_id)//PERCORRE A LISTA ATE ENCONTRAR O ID
            {   
                if(it->prox==NULL){
                    cout << "ERRO: CONTA "<<_id<<" NAO EXISTE" << endl;
                    return;
                }
                else{
                    it=it->prox;
                }
            }
            //IMPRIME EMAIL QUANDO ENCONTRA
            it->inbox->pop(); 

        }

    }

};

