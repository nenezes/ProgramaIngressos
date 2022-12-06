#include "Cliente.h"
#include <Windows.h>
#include <iostream>

int main() {
    Produtor plataforma;
    Cliente eu;
    int userIs;
    bool running = true; // controla o logout
    bool logged = false; // controla o loop do menu principal pós login
    bool onMenu = false; // controla o loop de menus secundários (?)
    string u;
    int choice; // determina as escolhas no menu

    while (running == true) {
        SetConsoleCP(1252); //para os acentos funcionarem
        SetConsoleOutputCP(1252);

        system("cls");
        cout << "Bem-vindo ao site de compra de ingressos." << endl;
        cout << "Para utilizar nossos servicos, indentifique-se." << endl;
        cout << "1 - Eu sou cliente. \n2 - Eu sou produtor." << endl;
        cin >> userIs;
        logged = true;
        system("cls");

        switch (userIs) {
        case 1: // clientes
            cout << "A s1mple agradece sua preferência!\nComo podemos te chamar?"
                << endl;
            cout << "Meu nome é: ";
            cin >> u;
            eu.registro(u);
            while (logged == true) {
                system("cls");
                cout << "Como podemos lhe ajudar hoje, " << eu.getName() << "?" << endl;
                cout << "1 - Comprar um ingresso.\n2 - Verificar lista de eventos.\n3 "
                    "- Reembolsar um ingresso.\n4 - Log Out."
                    << endl;
                cin >> choice;
                system("cls");
                switch (choice) {
                case 1: // compra de ingresso
                    
                    eu.comprarIngresso(plataforma);
                    cout << "Digite -1 para retornar ao menu de cliente." << endl;
                    cin >> choice;
                    if (choice == -1) {
                        userIs = 1;
                        system("cls");
                    }
                    break;

                case 2: // lista de eventos
                    plataforma.eventosProdutor.getEventos();
                    cout << "Para voltar digite -1" << endl;
                    cin >> choice;

                    break;

                case 3: // reembolsar ingresso
                    if (eu.ingressos.size() > 0) {
                        eu.meusIngressos();
                        eu.reembolsar();
                        cin >> choice;
                    }
                    else {
                        cout << "Você ainda não adquiriu nenhum ingresso!" << endl;
                        cout << "Digite -1 para retornar ao menu." << endl;
                        cin >> choice;
                    }

                    break;

                case 4: // voltar ao menu principal
                    logged = false;
                    break;
                }
            }
            break;

        case 2: // produtores
            while (logged == true) {
                system("cls");
                cout << "Que operação deseja realizar, produtor?" << endl;
                cout << "1 - Cadastrar um novo evento.\n2 - Cancelar um evento "
                    "ativo.\n3 - Informações de eventos.\n4 - Log Out."
                    << endl;
                cin >> choice;
                system("cls");
                switch (choice) {
                case 1:
                    plataforma.criarEvento();
                    cout << "Digite -1 para voltar ao menu." << endl;
                    cin >> choice;
                    break;

                case 2:
                    plataforma.cancelarEvento();
                    cout << "Digite -1 para voltar ao menu." << endl;
                    cin >> choice;
                    break;

                case 3:
                    onMenu = true;
                    while (onMenu == true) {
                        system("cls");
                        cout << "1 - Verificar eventos ativos.\n2 - Consultar ingressos "
                            "vendidos.\n3 - Retornar ao menu anterior."
                            << endl;
                        cin >> choice;
                        system("cls");
                        switch (choice) {
                        case 1:
                            plataforma.verificarEvento();
                            cout << "Digite -1 para voltar ao menu." << endl;
                            cin >> choice;
                            break;

                        case 2:
                            eu.meusIngressos();
                            cout << "Digite -1 para voltar ao menu.";
                            cin >> choice;
                            break;

                        case 3:

                            onMenu = false;
                            break;
                        }
                    }
                    break;

                case 4:
                    logged = false;
                    break;
                }
            }

            break;

        case 3: // logged out

            break;
        }
    }
}