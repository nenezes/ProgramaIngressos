#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Evento
{
private:
    int dia;
    int mes;
    int ano;
    string nome;
    string local;
    string produtor;


public:
    string getInfo();
    void setInfo(int d, int m, int a, string l, string n);
    void setEvento(int d, int m, int a, string l, string n);
    void getEventos();
    void cancelarEvento(int num);
    vector <Evento> eventos;
};