#include <stdio.h>
#include <stdlib.h>
#include <time.h> //Para utilizar a função time
#include <locale.h> //Para definir o idioma como português

/*Nesse programa, optei pelo uso de CHAR nas escolha e os números digitados em formato decimal, sendo assim reconhecido e evitando erros quando o
usuário digita um char ao invés de
um inteiro.*/

//Declaração de funções
void parImpar();
void escolhaJogador();
void jogoVelha();
void jogarNovamente();
void campoJogo();
void instrucoes();
void sobre();


//Declaração de variáveis globais
int vitoriaParImpar, linhaJogada, colunaJogada, linha, coluna, jogadas, vitoria; //Variáveis de inteiros
char jogadorUm, jogadorDois, matriz[3][3];//Matriz 3x3, com 9 espaços.

int main(){

	char escolhaMenu;

	system("cls"); //Limpa a tela quando retorna a função main para um novo jogo.
	setlocale(LC_ALL, "Portuguese"); //Define o idioma do sistema como sendo PT-BR

	printf("BEM-VINDO AO JOGO DA VELHA");

	//Switch case do menu
	printf("\n 1 - Jogar");
	printf("\n 2 - Instruções");
	printf("\n 3 - Sobre");
	printf("\n 4 - Sair");
	putchar('\n');
	printf("\nSua escolha: ");
	scanf("%c", &escolhaMenu);

	fflush(stdin);

	switch(escolhaMenu){
		case 49:{ //Inicia o Jogo
			system ("cls");
			printf("JOGO DA VELHA!!!");
			putchar('\n');
			parImpar();
			jogoVelha();
			break;
		}

		case 50:{//Texto com as instruções do jogo
			instrucoes();
			break;
		}

		case 51:{//Sobre o jogo
			sobre();
			break;
		}

		case 52:{ // Sai do jogo
			printf("\nObrigado por jogar!!!");
			system("exit");
			break;
		}

		default:{ //Caso seja feita uma escolha inválida
			printf("\nEscolha Inválida!!! Tente novamente\n");
			system("pause");
			return main();
		}
	}

	return 0;
}


//Função para tirar no "Par ou impar" qual jogador vai escolher primeiro.

void parImpar(){

	int random, resto;
	char escolhaParImpar;

	srand(time(NULL)); //Função para gerar um valor aleatório em C, o srand inicializa a função rand com um valor para que seja criado um valor aleatório na faixa definida.
	random = rand()%10; //Função para gerar um valor aleatório entre 0 e 10, como em um jogo de Par ou Impar. Necessita da função srand para gerar um valor diferente sempre.

	//Scan da escolha do jogador. O jogador 1 escolhe se deseja par ou impar.

	printf("\nJogador 1, deseja par ou impar?");
	printf("\n1 - PAR / 2 - IMPAR\n");
	scanf("%c", &escolhaParImpar);
	fflush(stdin);

	resto = random%2; //Resto armazena um valor que é igual a 0 ou 1, se é igual a 0 PAR, se é igual a 1 IMPAR.

	switch(escolhaParImpar){ //Switch case, dependendo da escolha do jogador 1.

		case 49:{ //Caso o jogador 1 escolha PAR
			if(resto == 0){
				printf("\nJogador 1 GANHOU!!! Valor random: %d", random);
				vitoriaParImpar = 1;
			}

			else if(resto == 1){
				printf("\nJogador 2 GANHOU!!! Valor random: %d", random);
				vitoriaParImpar = 2;
			}

			break;
		}

		case 50:{ //Caso o jogador 1 escolha IMPAR
			if(resto == 0){
				printf("\nJogador 2 GANHOU!!! Valor random: %d", random);
				vitoriaParImpar = 2;
			}

			else if(resto == 1){
				printf("\nJogador 1 GANHOU!!! Valor random: %d", random);
				vitoriaParImpar = 1;
			}

			break;
		}

		default :{ //Caso o jogador 1 digite um valor inválido.

			printf("\nEscolha inválida, tente novamente.");
			putchar('\n');
			system("pause");
			system("cls");
			parImpar();
			break;
		}
	}
}

//Função para a escolha do jogador vencedor, se X ou O
void escolhaJogador(){
	char escolha;

	if (vitoriaParImpar == 1){
		printf("\nJogador %d, deseja jogar com X ou O: ", vitoriaParImpar); //Pergunta se o jogador 1 quer jogar com X ou O
		scanf("%c", &escolha); // Recebe a escolha do jogador
		fflush(stdin);
		switch (escolha){
			case 'x':{
				jogadorUm = 'X';
				jogadorDois = 'O';
				printf("\nO Jogador 1 é %c e o Jogador 2 é %c", jogadorUm, jogadorDois);
				putchar('\n');
				system("pause");
				system("cls");
				break;
			}

			case 'o':{
				jogadorUm = 'O';
				jogadorDois = 'X';
				printf("\nO Jogador 1 é %c e o Jogador 2 é %c", jogadorUm, jogadorDois);
				putchar('\n');
				system("pause");
				system("cls");
				break;
			}

			default :{
				printf("\nEscolha inválida, tente novamente!"); //Caso seja pressionada uma tecla inválida, é exibido um aviso na tela e retorna para o inicio do jogo.
				putchar('\n');
				system("pause");
				system("cls");
				escolhaJogador();
				break;
			}
		}
	}

	else if(vitoriaParImpar == 2){
		printf("\nJogador %d, deseja jogar com X ou O: ", vitoriaParImpar); //Pergunta se o jogador 2 quer jogar com X ou O
		scanf("%c", &escolha); // Recebe a escolha do jogador
		fflush(stdin);
		switch (escolha){

			case 'x':{
				jogadorUm = 'O';
				jogadorDois = 'X';
				printf("\nO Jogador 1 é %c e o Jogador 2 é %c", jogadorUm, jogadorDois);
				putchar('\n');
				system("pause");
				system("cls");
				break;
			}

			case 'o':{
				jogadorUm = 'X';
				jogadorDois = 'O';
				printf("\nO Jogador 1 é %c e o Jogador 2 é %c", jogadorUm, jogadorDois);
				putchar('\n');
				system("pause");
				system("cls");
				break;
			}

			default :{
				printf("\nEscolha inválida, tente novamente!"); //Caso seja pressionada uma tecla inválida, é exibido um aviso na tela e retorna para o inicio do jogo.
				putchar('\n');
				system("pause");
				system("cls");
				escolhaJogador();
				break;
			}
		}
	}
}

//Função para o jogo

void jogoVelha(){

	escolhaJogador();

	//Desenha a matriz do jogo na tela
	printf("JOGO DA VELHA");
	printf("\tJogador %d começa!", vitoriaParImpar); //Quem ganhou no par ou impar começa
	campoJogo();
	//Contador de jogadas, no total de 9 movimentos

	for (jogadas=0;jogadas < 9;jogadas++){ //Contador de jogadas
		printf("\n Jogador 1 = %c / Jogador 2 = %c", jogadorUm, jogadorDois);
		printf("\nInsira a linha em que deverá ser posto seu símbolo:\n"); //Linha que o primeiro jogador joga
		scanf("%d", &linhaJogada);
		fflush(stdout);
		linhaJogada--; //Diminui uma linha jogada

		printf("Insira a coluna em que deverá ser posto seu símbolo:\n");//Linha que o primeiro jogador joga
		scanf("%d", &colunaJogada);
		fflush(stdout);

		colunaJogada--; // Diminui uma coluna jogada
		putchar('\n');
		system("cls");

		if(matriz[linhaJogada][colunaJogada] == '.'){ //Se a linhaJogada e a colunaJogada possui um '.' é uma posição válida para jogar.

            if(vitoriaParImpar==1){ //Se a vitoria do par ou impar foi 1, o jogador 1 começa

                if(jogadas%2){//O resto por 2 dará 1 ou 0: Se for 1, equivale a true e entra no if, *se for 0 equivale a false e entra no else
                    matriz[linhaJogada][colunaJogada] = jogadorDois; //Recebe o valor atribuido ao segundo jogador.
                }

                else{
                    matriz[linhaJogada][colunaJogada] = jogadorUm; //Recebe o valor atribuido ao primeiro jogador.
                }
            }

            else if(vitoriaParImpar==2){ //Se a vitória do par ou impar foi 2, o jogador 2 começa

                if(jogadas%2){//O resto por 2 dará 1 ou 0: Se for 1, equivale a true e entra no if, *se for 0 equivale a false e entra no else
                    matriz[linhaJogada][colunaJogada] = jogadorUm; //Recebe o valor atribuido ao primeiro jogador.
                }

                else{
                    matriz[linhaJogada][colunaJogada] = jogadorDois; //Recebe o valor atribuido ao segundo jogador.

                }
            }


			for(linha = 0; linha < 3; linha++){ //Exibe novamente a matriz do jogo
				putchar('\n');

				for(coluna = 0; coluna < 3; coluna++){
					putchar('\t');
					printf("%c", matriz[linha][coluna]);

				}
				putchar('\n');
				putchar('\n');
			}

			//Condições de vitória

			if((matriz[0][0] == matriz[0][1] && matriz[0][0] == matriz[0][2] && matriz[0][0] == jogadorUm)||
			   (matriz[0][0] == matriz[1][1] && matriz[0][0] == matriz[2][2] && matriz[0][0] == jogadorUm)||
			   (matriz[0][0] == matriz[1][0] && matriz[0][0] == matriz[2][0] && matriz[0][0] == jogadorUm)||
			   (matriz[0][1] == matriz[1][1] && matriz[0][1] == matriz[2][1] && matriz[0][1] == jogadorUm)||
			   (matriz[0][2] == matriz[1][2] && matriz[0][2] == matriz[2][2] && matriz[0][2] == jogadorUm)||
			   (matriz[1][0] == matriz[1][1] && matriz[1][0] == matriz[1][2] && matriz[1][0] == jogadorUm)||
			   (matriz[2][0] == matriz[2][1] && matriz[2][0] == matriz[2][2] && matriz[2][0] == jogadorUm)||
			   (matriz[2][0] == matriz[1][1] && matriz[2][0] == matriz[0][2] && matriz[2][0] == jogadorUm)){

				printf("\nJogador 1 ganhou!");
				jogadas = 9;
				vitoria = 1; //Diz que vitoria recebe 1

				jogarNovamente(); //Chama a função para jogar novamente ou não

			}

			else if((matriz[0][0] == matriz[0][1] && matriz[0][0] == matriz[0][2] && matriz[0][0] == jogadorDois)||
			   (matriz[0][0] == matriz[1][1] && matriz[0][0] == matriz[2][2] && matriz[0][0] == jogadorDois)||
			   (matriz[0][0] == matriz[1][0] && matriz[0][0] == matriz[2][0] && matriz[0][0] == jogadorDois)||
			   (matriz[0][1] == matriz[1][1] && matriz[0][1] == matriz[2][1] && matriz[0][1] == jogadorDois)||
			   (matriz[0][2] == matriz[1][2] && matriz[0][2] == matriz[2][2] && matriz[0][2] == jogadorDois)||
			   (matriz[1][0] == matriz[1][1] && matriz[1][0] == matriz[1][2] && matriz[1][0] == jogadorDois)||
			   (matriz[2][0] == matriz[2][1] && matriz[2][0] == matriz[2][2] && matriz[2][0] == jogadorDois)||
			   (matriz[2][0] == matriz[1][1] && matriz[2][0] == matriz[0][2] && matriz[2][0] == jogadorDois)){

				printf("\nJogador 2 ganhou!");
				jogadas = 9;
				vitoria = 1; //Diz que vitoria recebe 1

				jogarNovamente(); //Chama a função para jogar novamente ou não
			}
		}

		else{ //Caso o valor escolhido seja inválido, solicita uma nova jogada.
			printf("\nO espaço escolhido já está ocupado ou inválido, repita a operação para um espaço válido\n");
			jogadas--; //Diminui as jogadas
		}
	}

	if (vitoria != 1){ //Caso o if de vitoria não ocorra, o valor vai ser diferente de 1, então ninguem ganhou
		printf("\nNinguém ganhou :("); //Caso nenhum dos if's seja satisfeito para vitória.
		jogarNovamente(); //Chama a função para jogar novamente ou não
	}
}

//Função para jogar novamente

void jogarNovamente(){

	int choice; //Escolha de jogar novamente ou não
	printf("\nDeseja jogar novamente? 1 - SIM 2 - NÃO: ");
	scanf("%d", &choice);
	fflush(stdin);


	switch(choice){ //Switch case da escolha

		case 1: {
			parImpar();
			jogoVelha();
			break;
		}

		case 2: {
			printf("\nObrigado por jogar!!!");
			exit(0); //Sai do programa
			break;
		}

		default: { //Em caso de uma escolha inválida, retorna a função novamente e limpa a tela.
			system("cls");
			printf("\nEscolha inválida!");
			jogarNovamente();
			break;
		}
	}
}

//Função para criar o campo de jogo
void campoJogo(){ //Exibe o campo de jogo pela primeira vez.

	for(linha = 0; linha < 3; linha++){ //Cria a matriz do campo de jogo, cada '.' é uma posição

		putchar('\n');

		for(coluna = 0; coluna < 3; coluna++){
			putchar('\t');
			matriz[linha][coluna] = '.';
			printf("%c", matriz[linha][coluna]);
		}

		putchar('\n');
		putchar('\n');
	}
}

//Função com as instruções do jogo

void instrucoes(){

	char voltar;
	system ("cls");
	printf("Instruções do jogo da Velha.");
	printf("\nO jogo inicia com uma escolha de par ou impar, o jogador 1 escolhe primeiro.");
	printf("\nConforme a condição de vitória, um dos jogadores escolhe primeiro se quer X ou O");
	printf("\nApós a escolha, o jogo é iniciado, o jogador 1 começa jogando, depois o jogador 2");
	printf("\n\nPressione 1 para voltar ao menu principal ou 2 para sair do programa.");
	printf("\nSua escolha: ");
	scanf("%c", &voltar);
	fflush(stdin);

	switch(voltar){

		case 49:{
			main();
			break;
		}

		case 50:{
			system("exit");
			break;
		}

		default:{
			printf("\nComando inválido, tente novamente\n");
			system("pause");
			system("cls");
			instrucoes();
		}
	}
}

//Função com texto Sobre

void sobre(){

	char voltar;
	system ("cls");
	printf("Jogo da Velha - Versão 1.0");
	printf("\nDesenvolvido por Cássio Gamarra\nAcademico do curso de Ciência da Computação da UFN.");
	printf("\nBuscas feitas no Stack Overflow e LinguagemC");
	printf("\n\nPressione 1 para voltar ao menu principal ou 2 para sair do programa.");
	printf("\nSua escolha: ");
	scanf("%c", &voltar);
	fflush(stdin);

	switch(voltar){

		case 49:{
			main();
			break;
		}

		case 50:{
			system("exit");
			break;
		}

		default:{
			printf("\nComando inválido, tente novamente\n");
			system("pause");
			system("cls");
			instrucoes();
		}
	}
}
