#include <iostream>
#include <algorithm>
#include <string>
#include "../include/email.cpp"

using namespace std;

int main(){

    ListaUsuarios *usuarios = new ListaUsuarios();
    unsigned int id;
    unsigned int pri;
    string msg;

    string c;

    while(cin >> c){//ENQUANTO HOUVER INPUTS

        for (auto & a: c) a = toupper(a);//TRANSFORMA COMANDO PARA CAIXA ALTA
        if(c=="CADASTRA"){//SE OPERACAO DE CADASTRO DE USUARIO
            cin >> id;//LE O ID DO USUARIO
            usuarios->push(id);//CAHAMA FUNCAO DE CADASTRO PASSANDO O ID
        }
        else if(c=="REMOVE"){//SE OPERACAO DE EXCLUIR USUARIO
            cin >> id;//LE O ID DO USUARIO
            usuarios->pop(id);//CHAMA A FUNCAO DE EXCLUSAO PASSANDO O ID

        }
        else if(c=="ENTREGA"){//SE OPERACAO DE ENVIAR EMAIL
            cin >> id;//LE O ID DO USUARIO
            cin >> pri;//LE A PRIORIDADE
            getline(std::cin>>ws,msg);//LE TODA A MENSAGEM QUE SERÁ ENVIADA
            msg = msg.substr(0,(msg.length() - 3));//RETIRA O 'FIM'
            usuarios->push_email(msg,pri,id);//CHAMA FUNCAO DE ENVIO DE EMAIL PASSANDO A MENSAGEM, PRIORIDADE DA MENSAGEM E ID DO USUARIO
        }
        else if(c=="CONSULTA"){//SE OPERACAO DE LER EMAIL
            cin >> id;//LE O ID DO USUARIO
            usuarios->pop_email(id);//CHAMA FUNCAO DE LEITURA DE EMAIL PASSANDO O ID DO USUARIO
        }

    }

    usuarios->limpa_usuarios();
    delete usuarios;
    return 0;
}



