#include "head.h"
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

Lista *CriarLista()
{
	Lista *lista = (Lista *)malloc(sizeof(Lista));
	if (lista != NULL)
	{
		lista->Inicio = NULL;
		lista->Final = NULL;
	}
	else
	{
		cout << "Erro ao criar Lista";
	}
	return lista;
}
int tamanhoLista(Lista *lista)
{
	if (lista == NULL)
	{
		cout << "lista Vazia!";
		return 0;
	}
	else
	{
		int cont = 0;
		Elemento *no = lista->Inicio;
		while (no != NULL)
		{
			cont++;
			no = no->Proximo;
		}
		return cont;
	}
}

void buscarMatricula(Lista *lista)
{

	int matricula;
	cout << "\nMatrícula: ";
	cin >> matricula;

	Elemento *no = lista->Inicio;
	while (no->Dados.Matricula != matricula)
	{
		if (no->Proximo == NULL)
		{
			cout << "Nao foi encontrado o aluno de matrícula " << matricula << endl;
			return;
		}
		else
		{
			no = no->Proximo;
		}
	}
	
	char escolha;
	
	cout<<"Deseja adicionar nota? s ou n?"<<endl;
	
	cin>>escolha;
	
	if(escolha == 's'){
		
			cout << "N1: " << endl;
            cin >> no->Dados.n1;
            while (no->Dados.n1 < 0 || no->Dados.n1 > 10)
            {
                cout << " Tem que ser entre 0 a 10" << endl;
                cout << "digite novamente" << endl;
                cin >> no->Dados.n1;
            }
            cout << "N2 " << endl;
            cin >> no->Dados.n2;
            while (no->Dados.n2 < 0 || no->Dados.n2 > 10)
            {
                cout << "Tem que ser entre 0 a 10" << endl;
                cout << "digite novamente" << endl;
                cin >> no->Dados.n2;
            }
            no->Dados.MF = ((no->Dados.n1 * (0.4)) + (no->Dados.n2 * (0.6)));
			if (no->Dados.MF >= 6)
			{
				strcpy(no->Dados.status, "Aprovado");
			}			
			else
			{
				strcpy(no->Dados.status, "Reprovado");
			}
			cout << "Media Final: " << no->Dados.MF << endl;
			cout << "Status do aluno: " << no->Dados.status << endl;
		
	}else if(escolha == 'n'){
		return;
	}
	

	cout << "Matricula encontrada!\n"
		 << endl;
	cout << "Nome: " << no->Dados.Nome << endl;
	cout << "Idade: " << no->Dados.idade << endl;
	cout << "Matricula: " << no->Dados.Matricula << endl;
}

void removerMatricula(Lista *lista)
{
	int matricula;
	cout << "\nMatrícula: ";
	cin >> matricula;

	Elemento *anterior = lista->Inicio;
	Elemento *no = lista->Inicio;
	
	while(no->Dados.Matricula != matricula)
	{
		if(no == NULL)
		{
			cout << "Nao foi encontrado o aluno de matrícula " << matricula << endl;
			return;
		}
		else
		{
			anterior = no;
			no = no->Proximo;
		}
	}
	anterior->Proximo = no->Proximo;
	
	free(no);
	
}

int inforAlunoInicio(Lista *lista, Alunos apont)
{
	if (lista == NULL)
	{
		return 0;
	}
	else
	{
		Elemento *no = (Elemento *)malloc(sizeof(Elemento));
		if (no == NULL)
		{
			return 0;
		}
		no->Dados = apont;
		no->Proximo = NULL;
		if (lista->Inicio == NULL)
		{
			lista->Inicio = no;
			lista->Final = no;
		}
		else
		{
			no->Proximo = lista->Inicio;
			lista->Inicio = no;
		}
		return 1;
	}
}

int inforAlunoFinal(Lista *lista, Alunos apont)
{
	if (lista == NULL)
	{
		return 0;
	}
	else
	{
		Elemento *no = (Elemento *)malloc(sizeof(Elemento));
		if (no == NULL)
		{
			return 0;
		}
		no->Dados = apont;
		no->Proximo = NULL;
		if (lista->Final == NULL)
		{
			lista->Inicio = no;
		}
		else
		{
			lista->Final->Proximo = no;
		}
		lista->Final = no;
		return 1;
	}
}

int statusVazio(Lista *lista)
{
	if (lista == NULL || lista->Inicio == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void mostrarLista(Lista *lista)
{
	system("cls");
	if (statusVazio(lista))
	{
		cout << "Lista Vazia!";
	}
	else
	{
		int cont = 0;
		Elemento *no = lista->Inicio;
		while (no != NULL)
		{
			cout << "\n\nDados da Pessoa da Posicao: " << cont + 1 << " na lista!" << endl;
			cout << "Nome: " << no->Dados.Nome << endl;
			cout << "Idade: " << no->Dados.idade << endl;
			cout << "Matricula: " << no->Dados.Matricula << endl;
			no = no->Proximo;

			cont++;
		}
	}
}

void mediaTotal(Lista *lista)
{
	system("cls");
	if (statusVazio(lista))
	{
		cout << "Lista Vazia!";
	}
	else
	{
		int cont = 0;
		float media = 0;
		Elemento *no = lista->Inicio;
		while (no != NULL)
		{
			media += no->Dados.MF;
			cont += 1;
			no = no->Proximo;
		}
		media = media / cont;
		cout << "\nMedia da turma: " << media << "\n"
			 << endl;
	}
}

void liberarLista(Lista *lista)
{
	if (lista != NULL)
	{
		Elemento *no;
		while (lista->Inicio != NULL)
		{
			no = lista->Inicio;
			lista->Inicio = lista->Inicio->Proximo;
			free(no);
		}
		free(lista);
	}
}
void removerListaInicio(Lista *lista)
{
	int tam = 0;

	tam = tamanhoLista(lista);
	if (tam == 1)
	{
		free(lista->Inicio);
		lista->Inicio = NULL;
		lista->Final = NULL;
	}
	else if (tam >= 2)
	{
		Elemento *no = lista->Inicio;
		lista->Inicio = no->Proximo;
		free(no);
	}
}

void removerListaFinal(Lista *lista)
{
	int tam = 0;

	tam = tamanhoLista(lista);

	if (tam == 1)
	{
		free(lista->Inicio);
		lista->Inicio = NULL;
		lista->Final = NULL;
	}
	else if (tam >= 2)
	{
		Elemento *no = lista->Inicio;
		while (no->Proximo->Proximo != NULL)
		{
			no = no->Proximo;
		}

		free(no->Proximo);
		no->Proximo = NULL;
		lista->Final = no;
	}
}
