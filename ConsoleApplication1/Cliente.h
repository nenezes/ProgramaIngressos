#pragma once
#include <iostream>
#include <vector>
#include "Ingresso.h"
#include "Produtor.h"
using namespace std;

class Cliente
{
private:
    string nome;
    Evento eventosCliente;

public:
    vector <Ingresso> ingressos;
    void setIngresso(int id, string t, string i);
    void comprarIngresso(Produtor p);
    void verificarEvento(Produtor p);
    void meusIngressos();
    void reembolsar();
    void registro(string n);
    string getName();
};