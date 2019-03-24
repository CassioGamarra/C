/*Sistema de Gerenciamento de Garagem - Versão 4.0
Exercício para a disciplina de Estrutura de Dados
Aluno: Cássio Gamarra
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#include <io.h>

#define TAM 5
#define VALOR_TAXA 2.5

typedef struct{
    char placa[8];
    char dataEntrada[20];
    char dataSaida[20];
    char horaEntrada[20];
    char horaSaida[20];
    double taxa;
    double contEntrada;
    double contSaida;
}Vaga;

void menu();
void inicializar(Vaga *v, int n);
void gerirGaragem(Vaga *v, int n);
void entrarGaragem(char placa[], Vaga *v, int n);
void saidaGaragem(char placa[], Vaga *v, int posPlaca);
void estadoGaragem(Vaga *v);
void gravarEntrada(Vaga *v, int n);
void gravarSaida(Vaga vaga);
void data(char *dataAtual);
void hora(char *horaAtual);
void exibirHistoricoGaragem();
void exibirDataHora();

double calcularTaxa(double a, double b);
double contagemHoras();

int verificaGaragem(char placa[], Vaga *v, int n);

int main(){
    setlocale (LC_ALL, "Portuguese");
    menu();
    return 0;
}

//MENU PRINCIPAL
void menu(){
    int opcao;
    Vaga v[TAM];

    inicializar(v, TAM);
    do{
        printf("\t***********************************\n");
        printf("\t* GARAGEM DO JOÃO - GERENCIAMENTO *\n");
        printf("\t***********************************\n");
        printf("1 - GERIR GARAGEM\n");
        printf("2 - LISTAR CARROS\n");
        printf("3 - HISTÓRICO\n");
        printf("4 - HORA DO SISTEMA\n");
        printf("5 - SAIR\n");
        printf("Opção: ");
        scanf("%d", &opcao);
        fflush(stdin);
        switch(opcao){
            case 1: system("cls");
                    printf("\t*****************\n");
                    printf("\t* GERIR GARAGEM *\n");
                    printf("\t*****************\n");
                    gerirGaragem(v, TAM);
                    break;

            case 2: system("cls");
                    printf("\t*********************\n");
                    printf("\t* CARROS NA GARAGEM *\n");
                    printf("\t*********************\n");
                    estadoGaragem(v);
                    break;

            case 3: system("cls");
                    printf("\t***********************\n");
                    printf("\t* HISTÓRICO DE CARROS *\n");
                    printf("\t***********************\n");
                    exibirHistoricoGaragem();
                    break;

            case 4: system("cls");
                    printf("\t**************************\n");
                    printf("\t* DATA E HORA DO SISTEMA *\n");
                    printf("\t**************************\n");
                    exibirDataHora();
                    break;

            case 5: printf("\t*******\n");
                    printf("\t* FIM *\n");
                    printf("\t*******\n");
                    break;

            default:printf("Opção inválida! Tente novamente.\n");
                    system("pause");
                    system("cls");
        }
    }while (opcao != 5);

    return 1;
}

//INICIALIZAR A ESTRUTURA
void inicializar(Vaga *v, int n){
    int i;

    FILE *arquivo = fopen("entrada.txt","r");
    i = 0;
    if (arquivo) {
    	while (!feof(arquivo)) {
    		fscanf(arquivo,"%s %s %s", v[i].placa, v[i].dataEntrada, v[i].horaEntrada);
			if (feof(arquivo)) break;
			i++;
    	}
    }
    for (; i < n; i++) {
        strcpy(v[i].placa," ");
        strcpy(v[i].dataEntrada," ");
        strcpy(v[i].horaEntrada," ");
        strcpy(v[i].dataSaida," ");
        strcpy(v[i].horaSaida," ");
        v[i].taxa = 0.00;
    }
    if (arquivo) fclose(arquivo);
}

//GERENCIAMENTO DA GARAGEM
void gerirGaragem(Vaga *v, int n){
    char placa[8];
    int posPlaca = -1;

    printf("Por favor, digite a placa do veículo.\n");
    printf("Placa: ");
    scanf("%s", placa);
    fflush(stdin);
    if(strlen(placa) != 7){
        printf("\nPLACA INVÁLIDA!!!\n");
        system("pause");
        system("cls");
        return;
    }

    posPlaca = verificaGaragem(placa, v, n);

    if(posPlaca != -1){
        printf("\nCARRO LOCALIZADO!\n");
        printf("CALCULANDO TAXA...\n");
        saidaGaragem(placa, v, posPlaca);
    }
    else{
        printf("\nCARRO NÃO LOCALIZADO!\n");
        printf("ENTRADA NA GARAGEM...\n");
        entrarGaragem(placa, v, n);
    }
}

//VERIFICA A GARAGEM
int verificaGaragem(char placa[], Vaga *v, int n){
    int i;

    for (i = 0; i < n; i++){
        if(strcmp(v[i].placa, placa) == 0){
            return i; //Carro encontrado, retorna a posição da placa
        }
    }
    return -1; //Carro não encontrado, retorna a posição -1 do vetor
}

//PROCESSO DE ENTRADA NA GARAGEM
void entrarGaragem(char placa[], Vaga *v, int n){
    int i;
    char dataAtual[20];
    char horaAtual[20];

    strcpy(dataAtual, " ");
    strcpy(horaAtual, " ");

    data(dataAtual);
    hora(horaAtual);

    system("pause");
    putchar('\n');
    for (i = 0; i < n; i++) {
        if (strcmp(v[i].placa, " ") == 0) {
            strcpy(v[i].placa, placa);

            printf("DATA ENTRADA: %s", dataAtual);
            strcpy(v[i].dataEntrada, dataAtual);
            fflush(stdin);

            printf(" | HORA ENTRADA: %s", horaAtual);
            strcpy(v[i].horaEntrada, horaAtual);
            fflush(stdin);
            //Grava no arquivo de entrada
            gravarEntrada(v, n);
            v[i].contEntrada = contagemHoras();
            putchar('\n');
            system("pause");
            system("cls");
            return;
        }
    }
    printf("A GARAGEM ENCONTRA-SE LOTADA...\n");
    system("pause");
    system("cls");
}

//PROCESSO DE SAÍDA DA GARAGEM
void saidaGaragem(char placa[], Vaga *v, int posPlaca){
    char dataAtual[20];
    char horaAtual[20];

    strcpy(dataAtual, " ");
    strcpy(horaAtual, " ");

    data(dataAtual);
    hora(horaAtual);

    printf("Data saida: %s", dataAtual);
    strcpy(v[posPlaca].dataSaida, dataAtual);
    fflush(stdin);

    printf(" | Hora saida: %s", horaAtual);
    strcpy(v[posPlaca].horaSaida, horaAtual);
    fflush(stdin);

    //Realiza o cálculo da taxa

    v[posPlaca].contSaida = contagemHoras();

    v[posPlaca].taxa = calcularTaxa(v[posPlaca].contSaida, v[posPlaca].contEntrada);

    printf("\nValor final: %.1f\n", v[posPlaca].taxa);

    //Grava no arquivo saída
    gravarSaida(v[posPlaca]);

    //Realiza a limpeza do vetor
    int i;
    strcpy(v[posPlaca].placa," ");
    strcpy(v[posPlaca].dataEntrada," ");
    strcpy(v[posPlaca].horaEntrada," ");
    strcpy(v[posPlaca].dataSaida," ");
    strcpy(v[posPlaca].horaSaida," ");
    v[posPlaca].taxa = 0;
    system("pause");
    system("cls");
}

//GRAVAR ENTRADA
void gravarEntrada(Vaga *v, int n) {
	FILE *procurador;
	int i;
	procurador = fopen("entrada.txt", "w");

	for (i = 0; i < n; i++) {
    	if (strcmp(v[i].placa," ") != 0) {
			fprintf(procurador,"%s %s %s\n", v[i].placa, v[i].dataEntrada, v[i].horaEntrada);
		}
    }

	fclose(procurador);
}

//GRAVAR SAÍDA
void gravarSaida(Vaga vaga) {
	FILE *procurador;

	procurador = fopen("saida.txt","a");

    fprintf(procurador,"%s %s %s %s %s %.2f\n", vaga.placa, vaga.dataEntrada, vaga.horaEntrada, vaga.dataSaida,
	                                            vaga.horaSaida, vaga.taxa);
	fclose(procurador);
}

//ESTADO DA GARAGEM
void estadoGaragem(Vaga *v){
    int i, situacaoGaragem;

    for(i = 0; i < TAM; i++){
        if (strcmp(v[i].placa, " ") != 0){
            situacaoGaragem = 1;
        }
    }
    if(situacaoGaragem == 1){
        for (i = 0; i < TAM; i++){
            if (strcmp(v[i].placa, " ") != 0){
                printf("VAGA %d: PLACA: %s | DATA DE ENTRADA: %s | HORA DE ENTRADA: %s\n", i+1, v[i].placa, v[i].dataEntrada, v[i].horaEntrada);
            }
        }
        system("pause");
        system("cls");
    }
    else{
        printf("\nA GARAGEM ENCONTRA-SE VAZIA!\n");
        system("pause");
        system("cls");
    }
}

//EXIBIR HISTÓRICO DA GARAGEM
void exibirHistoricoGaragem() {
	double totalRecebido = 0;
    Vaga vaga;

    FILE *arquivo = fopen("saida.txt","r");

    if (arquivo == NULL){
        printf("\nO ARQUIVO NÃO EXISTE!\n");
        system("pause");
        system("cls");
        return;
    }

    if ( !filelength( fileno(arquivo) ) ) {
        printf("\tSEM HISTÓRICO");
    }

    else{
        while (!feof(arquivo)) {
            fscanf(arquivo,"%s %s %s %s %s %lf\n", vaga.placa, vaga.dataEntrada, vaga.horaEntrada, vaga.dataSaida, vaga.horaSaida, &vaga.taxa);
            totalRecebido = totalRecebido + vaga.taxa;
            printf("PLACA: %s \nENTRADA: %s %s\nSAÍDA: %s %s\nTAXA: %.2lf\n\n", vaga.placa, vaga.dataEntrada, vaga.horaEntrada, vaga.dataSaida, vaga.horaSaida, vaga.taxa);
        }
        printf("TOTAL RECEBIDO DO HISTÓRICO: %.2f\n\n", totalRecebido);
    }


    putchar('\n');
    fclose(arquivo);

    system("pause");
    system("cls");
}

//CALCULAR TAXAS
double calcularTaxa(double a, double b){
    double total;

    total = (a-b)* VALOR_TAXA;

    return total;
}

//CALCULAR HORAS
double contagemHoras(){
    int hora, minuto, segundo;
    double tempoTotal;

    struct tm *local;
    time_t t;

    t = time(NULL);
    local = localtime(&t);

    hora = local -> tm_hour;
    minuto = local -> tm_min;
    segundo = local -> tm_sec;

    tempoTotal = ((hora*3600)+(minuto*60)+segundo)/3600;

    return tempoTotal;
}

//MOSTRAR DATA E HORA DO SISTEMA
void exibirDataHora(){
    char dataAtual[20];
    char horaAtual[20];

    strcpy(dataAtual, " ");
    strcpy(horaAtual, " ");

    data(dataAtual);
    hora(horaAtual);

    printf("\nDATA: %s", dataAtual);
    printf(" | HORA: %s\n\n", horaAtual);
    system("pause");
    system("cls");
    return;
}

//FUNÇÃO PARA DATA ATUAL
void data(char *dataAtual){
    int dia, mes, ano; //Vai receber o valor da data

    strcpy(dataAtual, " ");

    struct tm *local;
    time_t t;

    t = time(NULL);
    local = localtime(&t);

    dia = local -> tm_mday;
    mes = local -> tm_mon + 1;
    ano = local -> tm_year + 1900;

    sprintf(dataAtual,"%d/%d/%d", dia, mes, ano);
}

//FUNÇÃO PARA HORAS, MINUTOS E SEGUNDOS
void hora(char *horaAtual){
    int hora, minuto, segundo;

    strcpy(horaAtual, " ");

    struct tm *local;
    time_t t;

    t = time(NULL);
    local = localtime(&t);

    hora = local -> tm_hour;
    minuto = local -> tm_min;
    segundo = local -> tm_sec;

    sprintf(horaAtual,"%d:%d:%d", hora, minuto, segundo);
}
