#include <iostream>
#include <algorithm>
#include <string>
#include "../include/email.hpp"
#include <time.h>

using namespace std;

int main(){

    //clock_t inicio,fim;
    //inicio = clock();

    ListaUsuarios *usuarios = new ListaUsuarios();
    unsigned int id;
    unsigned int pri;
    string msg;
    char arquivo[100];
    char Linha[100];
    

    FILE *arq;

    cin >> arquivo;

    arq = fopen(arquivo,"rt"); 

    char c;
    string aux;

    if (arq == NULL)  // Se houve erro na abertura
    {
        cout << "Problemas na abertura do arquivo" << endl;
        //cout << "TEMPO DE EXECUÇÃO: " <<  ((double)(fim - inicio) / CLOCKS_PER_SEC) << endl;
        return 0;
    }

    while (!feof(arq)){//ENQUANTO HOUVER INPUTS

        fscanf(arq, "%s", &c);
        string comando(&c);
        
        for (auto & a: comando) a = toupper(a);//TRANSFORMA COMANDO PARA CAIXA ALTA
        if(comando=="CADASTRA"){//SE OPERACAO DE CADASTRO DE USUARIO
            fscanf(arq, "%d", &id);//LE O ID DO USUARIO
            usuarios->push(id);//CAHAMA FUNCAO DE CADASTRO PASSANDO O ID
        }
        else if(comando=="REMOVE"){//SE OPERACAO DE EXCLUIR USUARIO
            fscanf(arq, "%d", &id);//LE O ID DO USUARIO
            usuarios->pop(id);//CHAMA A FUNCAO DE EXCLUSAO PASSANDO O ID

        }
        else if(comando=="ENTREGA"){//SE OPERACAO DE ENVIAR EMAIL
            fscanf(arq, "%d", &id);//LE O ID DO USUARIO
            fscanf(arq, "%d", &pri);//LE A PRIORIDADE
            msg = fgets(Linha, 100, arq);
            msg = msg.substr(1,(msg.length() - 5));//RETIRA O 'FIM'
            usuarios->push_email(msg,pri,id);//CHAMA FUNCAO DE ENVIO DE EMAIL PASSANDO A MENSAGEM, PRIORIDADE DA MENSAGEM E ID DO USUARIO
        }
        else if(comando=="CONSULTA"){//SE OPERACAO DE LER EMAIL
            fscanf(arq, "%d", &id);//LE O ID DO USUARIO
            usuarios->pop_email(id);//CHAMA FUNCAO DE LEITURA DE EMAIL PASSANDO O ID DO USUARIO
        }

    }

    usuarios->limpa_usuarios();
    delete usuarios;

    //fim = clock();
    //cout << "TEMPO DE EXECUÇÃO: " <<  ((double)(fim - inicio) / CLOCKS_PER_SEC) << endl;
    return 0;
}



