#include <iostream>

class Email{

    int destino;
    int emissor;
    std::string conteudo;

};

class ListaEmail{

    Email email;
    ListaEmail *prox;

};

class CaixaDeEntrada{

    int tam;
    ListaEmail emails;

};

class Usuario
{

    unsigned int id;

};

