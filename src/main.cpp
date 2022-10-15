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

    while(cin >> c){

        for (auto & a: c) a = toupper(a);
        if(c=="CADASTRA"){
            cin >> id;
            usuarios->push(id);
        }
        else if(c=="REMOVE"){
            cin >> id;
            usuarios->pop(id);

        }
        else if(c=="ENTREGA"){
            cin >> id;
            cin >> pri;
            cin >> msg;
            usuarios->push_email(msg,pri,id);
        }
        else if(c=="CONSULTA"){
            cin >> id;
            usuarios->pop_email(id);
        }

    }

    usuarios->limpa_usuarios();
    delete usuarios;
    return 0;
}



