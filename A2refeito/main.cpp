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

            cout << "Inicio ou final? - i ou f ou m( colocar por matricula ):" << endl;
            cin >> op;
            while(op != 'i' && op != 'f' && op != 'm'){

                cout<<" digite Novamente a opcao"<<endl;

                cin >> op;
            }

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

            cout << "Matricula:" << endl; // aqui ja vai ordenando por matricula digitada
            cin >> apont.Matricula;

            apont.n1 = 0;
            apont.n2 = 0;

            if (op == 'i')
            {
                aux = inforAlunoInicio(lista, apont);
            }
            else if (op == 'f')
            {
                aux = inforAlunoFinal(lista, apont);
            }
            else if (op = 'm')
            {
                inforAlunoOrdenado(lista, apont);
            }

            break;
        case '2':
            char opcoes;

            cout << "Quais das opcoes gostaria de remover?\nremover por matricula( m ) \n remover inicio( i ) \n remover final ( f )\n\n";

            cin >> opcoes;

            if (opcoes == 'm')
            {
                removerMatricula(lista);
            }
            else if (opcoes == 'i')
            {
                removerListaInicio(lista);
            }
            else if (opcoes == 'f')
            {

                removerListaFinal(lista);
            }

            break;
        case '3':
            char options;
            cout << "Qual das opcoes quer fazer: buscar por matricula( m ) ou posicao ( p )?\n"
                 << endl;
            cin >> options;
             while(options != 'm' && options != 'p'){

                cout<<" digite Novamente a opcao"<<endl;
                
                cin >> options;
            }

            if (options == 'm')
            {
                buscarMatricula(lista);
            }
            else if(options == 'p')
            {
                buscarPosicaoAlu(lista);
            }
            break;
        case '4':
            mediaTotal(lista);

            break;
        case '5':
            mostrarLista(lista);

            break;
        case '6':
            cout << "Obrigado por usar nosso servico." << endl;
            liberarLista(lista);
            exit(0);
            break;
        }
    }
}
