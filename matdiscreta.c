#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int calcularFatorial(int n);
int combinacao(int n, int p);


int main(){
	
	setlocale (LC_ALL, "Portuguese");

	int estudantes, estudantesHabilitados, equipes, estudantesSemHabilitacao; //Variáveis do problema
	int p, total, n, soma, ladoA, ladoB; //Varíaveis do laço de repetição

	printf("Trabalho Matem�tica Discreta - C�ssio Gamarra");
	putchar('\n');
	printf("\nDigite o n�mero de estudantes: ");
	scanf("%d", &estudantes);
	printf("\nDigite o n�mero de estudantes habilitados: ");
	scanf("%d", &estudantesHabilitados);
	printf("\nN�mero de estudantes na equipe: ");
	scanf("%d", &equipes);
	putchar('\n');

	estudantesSemHabilitacao = estudantes - estudantesHabilitados;
	n = estudantesHabilitados;
	soma = 0;
	for(p = 1; p <= estudantesHabilitados; p++){
		total = equipes - p;
		ladoA = combinacao(estudantesHabilitados, p);
		ladoB = combinacao(estudantesSemHabilitacao, total);
		soma += ladoA * ladoB;
		printf("Habilitados: %d | ", ladoA);
		printf("N�o Habilitados: %d | ", ladoB);
		printf("SOMA: %d ", soma);
		putchar('\n');
	}
	putchar('\n');
	printf("Resultado: %d", soma);
	return 0;
}

int combinacao(int n, int p){
	int resultadoCombinacao;

	resultadoCombinacao = calcularFatorial(n)/(calcularFatorial(p)*(calcularFatorial(n-p)));

	return resultadoCombinacao;
}

int calcularFatorial(int n){
	int fatorial;
	for (fatorial = 1; n > 1; n = n -1){
		fatorial = fatorial * n;
	}
	return fatorial;
}
