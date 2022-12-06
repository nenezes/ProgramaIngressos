#include <iostream>
#include <vector>
#include "Cliente.h"

void Cliente::comprarIngresso(Produtor p)
{
    if (p.eventosProdutor.eventos.size() > 0) 
    {
        cout << "Digite o número do ingresso que deseja comprar." << endl;
        int c;
        p.eventosProdutor.getEventos();
        cout << "Para que evento você deseja comprar um ingresso?" << endl;
        cin >> c;
        Ingresso novo_ingresso;
        novo_ingresso.setInfo(ingressos.size(), nome, p.eventosProdutor.eventos[c].getInfo());
        ingressos.push_back(novo_ingresso);
        cout << "Você comprou 1 ingresso para " << p.eventosProdutor.eventos[c].getInfo() << endl;
    }
    else
    {
        cout << "Ainda não há eventos cadastrados no sistema!" << endl;
    }
}

void Cliente::registro(string n)
{
    nome = n;
}

string Cliente::getName()
{
    return nome;
}

void Cliente::verificarEvento(Produtor p)
{
    p.eventosProdutor.getEventos();
}

void Cliente::meusIngressos()
{
    cout << "Ingressos registrados:" << endl;
    for (int j = 0; j < ingressos.size(); j++)
    {
        cout << j << " - " << ingressos[j].getInfo() << endl;
    }
}

void Cliente::reembolsar()
{
    int id;
    cout << "Digite o ID do ingresso que deseja reembolsar." << endl;
    cin >> id;
    ingressos.erase(ingressos.begin() + id);
    cout << "Ingresso reembolsado com sucesso." << endl;
    cout << "Digite -1 para retornar ao menu." << endl;
}

void Cliente::setIngresso(int id, string t, string i)
{
    Ingresso novo_ingresso;
    novo_ingresso.setInfo(id, t, i);
    ingressos.push_back(novo_ingresso);
}
