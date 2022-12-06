#pragma once
#include <iostream> 
#include "Evento.h"
using namespace std;

class Produtor
{
private:
    string nome;


public:
    void criarEvento();
    void verificarEvento();
    void cancelarEvento();
    Evento eventosProdutor;
};