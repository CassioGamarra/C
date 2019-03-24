#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Funções utilizadas

int fatorial(int n);
int binomio(int n, int k);
void desenharTriangulo();
void linhaN();
void menu();

//Variável global do número calculado.
int numero;

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	printf("Triângulo de Pascal - Cássio Gamarra");
	printf("\nDigite o valor para calcular: ");
	scanf("%d", &numero);
	
	//Caso o número digitado seja menor que 0 ou maior que 10, retorna um erro.
	if((numero > 10)||(numero < 0)){
		printf("\nValor inválido! ");
		system("pause");
		system("cls");
		main();
	}
	else{
		menu();
	}
	
	
	return 0;
}
void menu(){
	int escolha;
	putchar('\n');
	printf("\nO que deseja exibir?");
	printf("\n1 - Desenhar Triângulo");
	printf("\n2 - Linha 'N' do triângulo");
	printf("\n0 - Sair");
	printf("\nESCOLHA: ");
	scanf("%d", &escolha);
	
	switch(escolha){
		case 0:{
			printf("Obrigado por usar o sistema!");
			break;
		}
		case 1:{
			desenharTriangulo();
			break;
		}
		case 2:{
			linhaN();
			break;
		}
		default:{
			printf("Você digitou um valor inválido! ");
			system("pause");
			system("cls");
			menu();
		}
	}
}

//Função para desenhar o Triângulo de Pascal
void desenharTriangulo(){
	int n, k;
	
	printf("\nTriângulo até a linha %d", numero);
	putchar('\n');
	//Laço de repetição que percorre o N e o K enquanto esse for menor que o número solicitado, usando a função do binômio.
	for (n = 0; n <= numero; n++){
		for (k=0; k <= n; k++){
			printf("%d ", binomio(n, k));
		}
	putchar('\n');
	}
	system("pause");
}


//Função para mostrar apenas uma linha do Triângulo de Pascal
void linhaN(){
	int k;
	printf("\nLinha %d do triângulo: ", numero);
	
	//Nesse caso, o laço de repetição precisa percorrer apenas o K da função anterior, pois imprime apenas uma linha.
	for(k=0; k<= numero; k++){
		printf("%d ", binomio(numero, k));
	}
	printf("\n");
	system("pause");
}

//Função para realizar o calculo do Fatorial, necessário para o binômio.
int fatorial(int n){
	int fat, i;
	
	fat = 1;
	
	for (i=1; i<=n;i++){
		fat = fat * i;
	}
	
	return fat;
}

//Função para calcular o coeficiente binomial. Usando a fórmula (n k) = n!/ n!(n-k)!

int binomio(int n, int k){
	int coeficiente;
	coeficiente = fatorial(n)/(fatorial(k) * fatorial(n-k)); //Fórmula.
	return coeficiente;
}
