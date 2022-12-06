#include "Evento.h"
#include <iostream>
#include <string>
using namespace std;

void Evento::setInfo(int d, int m, int a, string l, string n)
{
    local = l;
    nome = n;
    dia = d;
    mes = m;
    ano = a;
}

void Evento::setEvento(int d, int m, int a, string l, string n)
{
    bool freeDate = true;
    for (int j = 0; j < eventos.size(); j++)
    {
        if (d == eventos[j].dia)
        {
            if (m == eventos[j].mes)
            {
                if (a == eventos[j].ano)
                {
                    system("cls");
                    cout << "Já existe um evento cadastrado nesta data." << endl;
                    freeDate = false;
                }
            }
        }
    }

    if (freeDate == true)
    {
        Evento novo_evento;
        novo_evento.setInfo(d, m, a, l, n);
        eventos.push_back(novo_evento);
        cout << "O evento " << n << ", no local " << l << " foi registrado com sucesso na data " << d << "/" << m << "/" << a << "." << endl;
    }
}

string Evento::getInfo()
{
    string eventoFormatado;

    eventoFormatado = to_string(dia) + "/" + to_string(mes) + "/" + to_string(ano) + " " + local + " " + nome;

    return eventoFormatado;
}

void Evento::getEventos()
{
    cout << "Eventos registrados:" << endl;
    cout << "ID |  DATA  | LOCAL | TIPO" << endl;
    for (int j = 0; j < eventos.size(); j++)
    {
        cout << j << " - " << eventos[j].getInfo() << endl;
    }
}

void Evento::cancelarEvento(int num)
{
    int numero = num;
    eventos.erase(eventos.begin() + numero);
}

