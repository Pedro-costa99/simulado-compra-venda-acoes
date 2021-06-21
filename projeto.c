#include <stdlib.h>
#include <stdio.h>

/*
IFBA
Disciplina: INF006 - Estrutura de dados
Docente: Prof. Antônio Carlos
Discente: Pedro Fernando C. Costa
Semestre: 2021.
Atividade: Mercado simulado de compra e venda de ações
Entrega parcial: 21/06/2021/ Resolução das letras a e b.
*/

typedef struct ponto
{
	int quantidade;
	float valor;
	int tipo;//compra ou venda
	int sigla;//título
	struct ponto* proximo;//ponteiro para o próximo elemento
	int resp;
	
}t_ponto;


int main(int argc, char const *argv[])
{
	t_ponto* ini_ponto;//início da lista
	t_ponto* proximo_ponto;
	int resp;
	int sorte01, sorte02;

	ini_ponto = (t_ponto *)malloc(sizeof(t_ponto));
	if(ini_ponto == NULL)
		exit(1);

	proximo_ponto = ini_ponto;

	while(1){
		printf("Digite a quantidade: \n");
		scanf("%d", &proximo_ponto->quantidade);

		printf("Digite o valor: \n");
		scanf("%f", &proximo_ponto->valor);

		do{
			printf("Qual o tipo? <2> COMPRA <3> VENDA: \n");
			scanf("%d", &sorte01);

			proximo_ponto->tipo = sorte01;

		}while(sorte01 !=2 && sorte01 != 3);
		

		do{
			printf("Digite a sigla: <4> PETR4 <5> VALE5 <6> ITSA4 <7> USIM5 <8> LAME3 \n");
			scanf("%d", &sorte02); 

			proximo_ponto->sigla = sorte02;

		}while(sorte02 !=4 && sorte02 != 5 && sorte02 != 6 && sorte02 != 7 && sorte02 != 8);
		

		printf("Deseja continuar? <1> SIM <outro valor> NAO: \n");
		scanf("%d", &resp);

		if(resp == 1){
			proximo_ponto->proximo = (t_ponto*)malloc(sizeof(t_ponto));
			proximo_ponto = proximo_ponto->proximo;
		}else
			break;
		}

		printf("\n");
		proximo_ponto->proximo = NULL;
		proximo_ponto = ini_ponto;

		while(proximo_ponto != NULL){
			printf("Quantidade: %d, Valor: %.2f, ", proximo_ponto->quantidade, proximo_ponto->valor);
			if(proximo_ponto->tipo == 2){
				printf("Tipo: Compra, ");
			}else{
				printf("Tipo: Venda, ");
			}

			//<4> PETR4 <5> VALE5 <6> ITSA4 <7> USIM5 <8> LAME3

			if(proximo_ponto->sigla == 4){
				printf("Sigla: PETR4\n");
			}else if(proximo_ponto->sigla == 5){
				printf("Sigla: VALE5\n");
			}else if(proximo_ponto->sigla == 6){
				printf("Sigla: ITSA4\n");
			}else if(proximo_ponto->sigla == 7){
				printf("Sigla: USIM5\n");
			}else if(proximo_ponto->sigla == 8){
				printf("Sigla: LAME3\n");
			}
			
			proximo_ponto = proximo_ponto->proximo;
		}
	
	return 0;
}