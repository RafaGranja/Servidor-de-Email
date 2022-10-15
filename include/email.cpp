#include <iostream>
using namespace std;

class Email{

    public :
    unsigned int pri;
    string msg;

    //CONSTRUTOR PASSANDO PRIORIDADE E MENSAGEM
    Email(unsigned int _pri,string _msg){
        this->pri=_pri;
        this->msg=_msg;
    }

};

class ListaEmail{

    public :
    Email *data=NULL;
    ListaEmail *next=NULL;

};

class CaixaDeEntrada{

    public :
    ListaEmail *listaEmail=NULL;

    void push(Email *new_email,unsigned int _id){

        //CRIA E ALOCA UM NOVO EMAIL
        ListaEmail* newNode = new ListaEmail();
        
        //INPUTA O DADO NO EMAIL
        newNode->data = new_email;
        
        //SE A LISTA ESTA VAZIA CRIA UM HEAD
        if(this->listaEmail == NULL){
            this->listaEmail = newNode;
            cout << "OK: MENSAGEM PARA "<<_id<<" ENTREGUE"<<endl;
        }
        else{//SE NAO ESTA VAZIA
            //PROCURA UM LUGAR ONDE FICAR
            // LUGAR = ANTES DO PRIMEIRO EMAIL COM PRIRORIDADE MENOR
            ListaEmail *it = new ListaEmail();
            ListaEmail *it_anterior = new ListaEmail();
            it = this->listaEmail;
            //SE FOR A CABECA COM PRIORIDADE MENOR
            if(it->data->pri<newNode->data->pri){

                newNode->next=it;
                this->listaEmail = newNode;
                cout << "OK: MENSAGEM PARA "<<_id<<" ENTREGUE"<<endl;

            }
            else{//SE NAO FOR
                while (it->data->pri>=newNode->data->pri)//ENQUANTO O EMAIL TEM A PRIORIDADE MAIOR 
                {                                        //OU IGUAL PASSA PARA O PRÓXIMO              
                    if(it->next!=NULL){
                        it_anterior=it;
                        it=it->next;
                    }
                    else{
                        break;
                    }
                }
                newNode->next=it;
                it_anterior->next = newNode;
                cout << "OK: MENSAGEM PARA "<<_id<<" ENTREGUE"<<endl;
                
            }
            
        }

    } 

    //DESALOCA TODA LISTA
    void deletaCaixa(){

        //DECLARA AUXILIAR
        ListaEmail *aux = new ListaEmail();

        while(this->listaEmail!=NULL){
            aux=this->listaEmail;
            this->listaEmail=this->listaEmail->next;
            cout<<aux->data->msg<<endl;
            delete aux->data;
            delete aux;
        }
    }

    void pop(unsigned int _id){

        //DECLARA AUXILIAR
        ListaEmail *aux = new ListaEmail();

        //SE CAIXA DE EMAIL ESTA VAZIA
        if(this->listaEmail==NULL){
            cout << "CONSULTA "<<_id<<": CAIXA DE ENTRADA VAZIA" << endl;
        }
        else{//SE NÃO RETIRA O PRIMEIRO
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
    CaixaDeEntrada *inbox = NULL;
    Usuario *prox = NULL;

    //CONSTRUTOR INICIA A CAIXA DE ENTRADA E O PROX COMO NULL
    Usuario(){
        this->inbox=new CaixaDeEntrada();
        this->prox=NULL;
    }

};

class ListaUsuarios{

    public:

    Usuario *user = NULL;

    //INSERE USUARIO CASO O ID NAO EXISTA
    void push(unsigned int _id){
        
        //DECLARA OS ITERADORES
        Usuario *it = new Usuario();
        Usuario *it_anterior = new Usuario();

        //NAO POSSUI USUARIO NENHUM
        if(this->user==NULL){

            this->user = new Usuario();
            this->user->id=_id;
            cout << "OK: CONTA "<<_id<<" CADASTRADA" << endl;

        }
        else{//POSSUI USUARIO
            it=this->user;
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

    void push_email(string _new_email,unsigned int _pri,unsigned int _id){

        //DECLARA OS ITERADORES
        Usuario *it = new Usuario();

        //NAO POSSUI USUARIO NENHUM
        if(this->user==NULL){
            cout << "ERRO: CONTA "<<_id<<" NAO EXISTE" << endl;
        }
        else{//POSSUI USUARIO
            it=this->user;
            do{ 
                if(it->id==_id){
                    Email *new_email = new Email(_pri,_new_email);
                    it->inbox->push(new_email,_id);
                    return;
                }
                else{
                    it=it->prox;
                }
            }while(it!=NULL);
            //PERCORRE TODA A LISTA ATRAS DO ID E SE ENCONTRA PRINTA O ERRO E ACABA A A FUNCAO
            //SE NAO ENCONTRA O ID EXIBE O ERRO

            cout << "ERRO: CONTA "<<_id<<" NAO EXISTE" << endl;
            delete it;

        }


    }
    
    //DELETE USUARIO CASO O ID EXISTA
    void pop(unsigned int _id){

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

            if(this->user->id==_id){
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

    void pop_email(unsigned int _id){
        //DECLARA OS ITERADORES
        Usuario *it = new Usuario();

        //NAO POSSUI USUARIO NENHUM
        if(this->user==NULL){
            cout << "ERRO: CONTA "<<_id<<" NAO EXISTE" << endl;
        }
        else{//POSSUI USUARIO
            it=this->user;
            do{
                if(it->id==_id){
                    it->inbox->pop(_id);
                    return;
                }
                else{
                    it=it->prox;
                }
            }while(it!=NULL);
            //PERCORRE TODA A LISTA ATRAS DO ID E SE ENCONTRA PRINTA O ERRO E ACABA A A FUNCAO
            //SE NAO ENCONTRA O ID EXIBE O ERRO

            cout << "ERRO: CONTA "<<_id<<" NAO EXISTE" << endl;
            delete it;

        }


    }

    //DESALOCA TODA LISTA
    void limpa_usuarios(){
        //DECLARA AUXILIAR
        Usuario *aux = new Usuario();

        while(this->user!=NULL){
            aux=this->user;
            this->user=this->user->prox;
            aux->inbox->deletaCaixa();//DESALOCA LISTA DE EMAIL
            delete aux->inbox;//DESALOCA CAIXA DE EMAIL
            delete aux;//DESALOCA USUARIO
        }
    }

};
