#include "Produtor.h"

void Produtor::criarEvento()
{
	int dia, mes, ano;
	string nome, local;

	cout << "Insira a data do evento." << endl;
	cin >> dia >> mes >> ano;
	cout << "Digite o local do evento " << endl;
	cin >> local;
	cout << "Digite o nome do evento " << endl;
	cin >> nome;
	eventosProdutor.setEvento(dia, mes, ano, local, nome);
}

void Produtor::verificarEvento()
{
	eventosProdutor.getEventos();
}

void Produtor::cancelarEvento()
{
	int id;
	eventosProdutor.getEventos();
	cout << "Digite o ID do evento que deseja cancelar " << endl;
	cin >> id;
	eventosProdutor.cancelarEvento(id);
	cout << "Evento cancelado com sucesso." << endl;
}