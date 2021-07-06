#include <stdlib.h>
#include <stdio.h>

/*
IFBA
Disciplina: INF006 - Estrutura de dados
Docente: Prof. Antônio Carlos
Discente: Pedro Costa
Semestre: 2021.1
Atividade: Mercado simulado de compra e venda de ações
Entrega parcial: 21/06/2021/ Resolução das letras a e b.
*/

//declaração de struct
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
	FILE *pont_arq;//cria variável ponteiro para o arquivo

	//abrindo o arquivo com tipo de abertura w
	pont_arq = fopen("arquivo_acoes.txt", "w");

	//testando a criação do arquivo
	if(pont_arq == NULL){
		printf("Erro na abertura do arquivo\n");
		return 1;
	} else{


	t_ponto* ini_ponto;//início da lista
	t_ponto* proximo_ponto;
	int resp;
	int sorte01, sorte02, atual = 0, anterior = 0, codigo = 0, codigo03 = 0, atual02 =0, anterior02 =0;

	//alocação de memória
	ini_ponto = (t_ponto *)malloc(sizeof(t_ponto));
	if(ini_ponto == NULL)
		exit(1);

	//aponta para o mesmo endereço de ini_ponto
	proximo_ponto = ini_ponto;

	while(1){
		printf("Digite a quantidade: \n");
		scanf("%d", &proximo_ponto->quantidade);
		//usando fprintf para armazenar a string no arquivo
		fprintf(pont_arq, "%d\n", proximo_ponto->quantidade);

		printf("Digite o valor: \n");
		scanf("%f", &proximo_ponto->valor);
		//usando fprintf para armazenar a string no arquivo
		fprintf(pont_arq, "%d\n", proximo_ponto->valor);

		do{
			printf("Qual o tipo? <2> COMPRA <3> VENDA: \n");
			scanf("%d", &sorte01);
			//usando fprintf para armazenar a string no arquivo
			fprintf(pont_arq, "%d\n", sorte01);


			proximo_ponto->tipo = sorte01;

		}while(sorte01 !=2 && sorte01 != 3);
		

		do{
			printf("Digite a sigla: <4> PETR4 <5> VALE5 <6> ITSA4 <7> USIM5 <8> LAME3 \n");
			scanf("%d", &sorte02); 
			//usando fprintf para armazenar a string no arquivo
			fprintf(pont_arq, "%d\n", sorte02);

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

			//verificando igualdade de valores
			if(codigo == 0){
				atual = proximo_ponto->valor;
				
			}

			int codigo02 = 0;
			if(codigo02 == 0 && codigo > 0){
				anterior = proximo_ponto->valor;				
			}

			codigo++;
			

			if(proximo_ponto->tipo == 2){
				printf("Tipo: Compra, ");
			}else{
				printf("Tipo: Venda, ");
			}

			//comparando a quantidade
			if(codigo03 == 0){
				atual02 = proximo_ponto->quantidade;
				
			}

			int codigo04 = 0;
			if(codigo04 == 0 && codigo03 > 0){
				anterior02 = proximo_ponto->quantidade;				
			}

			codigo03++;
			

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

			if (anterior != atual && anterior02 == atual02 && proximo_ponto == NULL)
			{
				printf("\n");				
				printf("Desculpa, a operacao nao pode ser realizada. \n");
				printf("ValorVenda deve ser igual ao de ValorCompra\n");
				printf("Quantidade de venda ou compra deve ser menor das duas quanitdades\n");
			} else if (anterior == atual && anterior02 == atual02 && proximo_ponto == NULL){
			
				printf("\n");				
				printf("Desculpa, a operacao nao pode ser realizada. \n");				
				printf("Quantidade de venda ou compra deve ser menor das duas quantidades\n");
			}else if (anterior == atual && anterior02 != atual02 && proximo_ponto == NULL){
				printf("\n");
				printf("Operacao realizada com sucesso!!!\n");
			}
			
		}

		fclose(pont_arq);


	}



	
	return 0;
}