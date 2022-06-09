#include <iostream>
#include <cstdlib>
#include <cstring>
#include "head.h"

using namespace std;

int main()
{
    Alunos apont; // apontando
    Lista *lista;
    char escolha, op;
    int x = 1, aux = 0;

    lista = CriarLista();
    while (x != 0)
    {
        cout << "\n\nO que voce quer fazer?\n"
             << endl;

        cout << "1 - colocar novo item" << endl;
        cout << "2 - remover item" << endl;
        cout << "3 - Buscar aluno pela matricula ou posicao?\n"
             << endl;
    	
        cout << "4 - Calcular a media final" << endl;
        cout << "5 -  mostrar a lista" << endl;
        cout << "6 - Sair" << endl;

        cin >> escolha;

        switch (escolha)
        {
        case '1':
           

            cout << "Inicio ou final? - i ou f" << endl;
            cin >> op;
			fflush(stdin);
            cout << "Informe o nome da pessoa a ser inserida na lista: ";
            cin.getline(apont.Nome, 50);
            cout << "Idade do aluno: " << endl;
            cin >> apont.idade;
            while (apont.idade < 0 || apont.idade > 100)
            {
                cout << "A idade ta fora do comum. Digite entre 0 a 100" << endl;
                cout << "digite novamente" << endl;
                cin >> apont.idade;
            }
            cout << "Matricula:" << endl;
            cin >> apont.Matricula;

            if (op == 'i')
            {
                aux = inforAlunoInicio(lista, apont);
            }
            else
            {
                aux = inforAlunoFinal(lista, apont);
            }

            break;
        case '2':
            			
			removerMatricula(lista);
			
            break;
        case '3':
            buscarMatricula(lista);

            break;
        case '4':
            mediaTotal(lista);

            break;
        case '5':
            mostrarLista(lista);

            break;
        case '6':
            cout << "Obrigado por usar nosso serviço." << endl;
            liberarLista(lista);
            exit(0);
            break;
        }
    }
}
