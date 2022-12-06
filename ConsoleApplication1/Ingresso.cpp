#include "Ingresso.h"
#include <string>


void Ingresso::setInfo(int id, string t, string i)
{
	idIngresso = id;
	titular = t;
	infos = i;
}

string Ingresso::getInfo()
{
	string ingressoFormatado;
	ingressoFormatado = "Ingresso N." + to_string(idIngresso) + " | " + infos + " | Titular: " + titular;
	return ingressoFormatado;
}