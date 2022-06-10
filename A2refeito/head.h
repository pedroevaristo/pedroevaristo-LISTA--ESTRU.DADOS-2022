struct Alunos
{
    char Nome[50];
    int Matricula;
    int idade;
    float n1,n2, MF;//nota1,nota2,media final
    char status[20];
};

struct Elemento{
	Alunos Dados;
	Elemento *Proximo;
};
struct Lista{
    int quantid;
    
	Elemento *Inicio;
	Elemento *Final;
};



Lista* CriarLista();
int statusVazio(Lista *lista);
void mostrarLista(Lista *lista);
void mediaTotal(Lista *lista);

void buscarMatricula(Lista *lista);
void buscarPosicaoAlu(Lista *lista);


int inforAlunoInicio(Lista *lista, Alunos apont);
int inforAlunoFinal(Lista *lista, Alunos apont);

void inforAlunoOrdenado(Lista *lista, Alunos apont);


void liberarLista(Lista *lista);

void removerListaInicio(Lista *lista);
void removerListaFinal(Lista *lista);
void removerMatricula(Lista *lista);

