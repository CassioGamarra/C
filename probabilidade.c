#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

double calcularProbabilidadeA(double carroA, double carroB);
double calcularProbabilidadeB(double carroA, double carroB);


int main(){
		double carroA, carroB;
		int opcao;
		setlocale(LC_ALL, "Portuguese");
		
		printf("TRABALHO DE PROBABILIDADE E ESTATÍSTICA - CÁSSIO GAMARRA\n\n");
		system("pause");
		system("cls");
		
		//Garantindo que não tenham valores de sujeira de memória no sistema
		carroA = 0;
		carroB = 0;
		
		printf("Mike tem dois velhos automóveis.\nNas manhãs frias, há %.2f%% de probabilidade de um deles não pegar, \ne %.2f%% do outro não pegar.", carroA, carroB);
		
		//Solicitando os valores para o enunciado
		printf("\n\nDigite a probabilidade do carro A: ");
		scanf("%lf", &carroA);
		printf("\nDigite a probabilidade do carro B: ");
		scanf("%lf", &carroB);
		
		//Garantindo que os valores sejam positivos
		if(carroA < 0){
			carroA = carroA * -1;
		}
		if(carroB < 0){
			carroB = carroB * -1;	
		}
	
		//Atualizando os valores do enunciado e printando as questões
		printf("\n\nMike tem dois velhos automóveis.\nNas manhãs frias, há %.2f%% de probabilidade de um deles não pegar, \ne %.2f%% do outro não pegar.", carroA, carroB);
		printf("\n\na) Qual a probabilidade de nenhum pegar?");
		printf("\nb) Qual a probabilidade de apenas um pegar?");
		printf("\n\n1 - Resultado Questão A | 2 - Resultado Questão B: ");
		scanf("%d", &opcao);
		
		//Exibindo o resultado da questão A
		if(opcao == 1){
			printf("\nA probabilidade de nenhum pegar é de ");
			printf("%.2lf%%", calcularProbabilidadeA(carroA,carroB));
		}
		//Exibindo o resultado da questão B
		else if(opcao == 2){
			printf("\nA probabilidade de apenas um pegar é de ");
			printf("%.2lf%%", calcularProbabilidadeB(carroA,carroB));
		}
		
		else{
			printf("\nOpção inválida!\n");
			system("pause");
			system("cls");
			main();
		}
	
    return 1;
}

//Calculo da probabilidade para a questão A
double calcularProbabilidadeA(double carroA, double carroB){
	double resultado = 0;
	double probCarroA, probCarroB;
	
	probCarroA = carroA/100.0;
	probCarroB = carroB/100.0;
	
	/*Questão A: é necessário multiplicar a probabilidade do carro A não pegar
	*com a probabilidade do carro B não pegar.
	*/
	resultado = (probCarroA * probCarroB)*100;
	
	return resultado;
}

//Calculo da probabilidade para a questão B
double calcularProbabilidadeB(double carroA, double carroB){
	double resultado = 0;
	double probCarroA, probCarroB, situacaoA, situacaoB;
	
	//Convertendo os valores para trabalhar com a porcentagem
	probCarroA = carroA/100.0;
	probCarroB = carroB/100.0;
	
	//As situações são: o carro A pegar e o carro B pegar
	//Sendo 100% menos a probabilidade do carro não pegar
	situacaoA = 100-carroA;
	situacaoB = 100-carroB;
	
	/* O cálculo utilizado é:
	*	A probabilidade do carro A não pegar multiplica a probabilidade do carro B Pegar
	* 	A probabilidade do carro B não pegar multiplica a probabilidade do carro A Pegar
	*	Realiza a soma desses valores, obtendo a probabilidade de apenas um deles pegar
	*/
	resultado = (probCarroA*situacaoB)+(probCarroB*situacaoA); 
	
	return resultado;
}

