#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include "structs.h"
#include "cabecalho.h"

#define MAX_PAC 100

int string_to_int(char str[]) {
    int resultado = 0;
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            resultado = resultado * 10 + (str[i] - '0');
        } else {
            return 0;
        }
        i++;
    }
    return resultado;
}

long string_to_long(char str[]) {
    int resultado = 0;
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            resultado = resultado * 10 + (str[i] - '0');
        } else {
            return 0;
        }
        i++;
    }
    return resultado;
}

float string_to_double(char str[]) {
    double resultado = 0.0;
    double decimal = 0.1;
    int i = 0;
    int ponto_decimal = 0;

    while (str[i] != '\0') {
        if ((str[i] >= '0' && str[i] <= '9') || str[i] == '.') {
            if (str[i] == '.') {
                ponto_decimal = 1;
            } else {
                if (!ponto_decimal) {
                    resultado = resultado * 10 + (str[i] - '0');
                } else {
                    resultado += (str[i] - '0') * decimal;
                    decimal *= 0.1;
                }
            }
        } else {
            return 0.0;
        }
        i++;
    }
    return resultado;
}


void verifica(char nome[]){
    while(string_to_long(nome) == 0){
        printf("Número de ID inválido, introduza novamente:\n");
        fgets(nome, 50, stdin);
        if(nome[strlen(nome) - 1] == '\n'){
            nome[strlen(nome) - 1] = '\0';
        }
    }
}
int main(){


    char opcao[20];
    int num_opcao;
    list_doentes_t listDoentes;

    init(&listDoentes);

    FILE *file = fopen("docs/doentes.txt","r");
    int contador_ID = 0;

    if(file == NULL){ //se nao existir
        printf("A criar o ficheiro dos doentes...\n");
        FILE *file = fopen("docs/doentes.txt", "w");
        fclose(file);
    }
    else{ //se ja existir, temos de percorrer o ficheiro, encontrar o ID de maior valor para que seja retomado com o valor do ID

        char ler_linha[100];
        int linha = 0;

        while(fgets(ler_linha,sizeof(ler_linha),file) != NULL){
            linha++;
            if(ler_linha[strlen(ler_linha)-1] == '\n'){
                ler_linha[strlen(ler_linha)-1] = '\0';
            }
            if(linha%6 == 1){ //Os ID's estão nas posições 1,7,13,...
                int id = string_to_int(ler_linha);
                if(id>contador_ID){
                    contador_ID = id;
                }
            }
        }

        fclose(file);
    }

    recolhe_info_fich(&listDoentes);

    do{

        printf("\n=== Menu ===\n");
        printf("1. Adicionar Doente\n");
        printf("2. Eliminar Doente\n");
        printf("3. Listar Doente por Ordem Alfabética\n");
        printf("4. Listar os Doentes com Tensões Máximas acima de um determinado valor\n");
        printf("5. Apresentar a informação de um doente\n");
        printf("6. Registar a informação de um doente num determinado dia \n");
        printf("7. Sair\n");
        printf("Opção que quer selecionar: ");

        fgets(opcao,20,stdin);

        int len = strlen(opcao);

        if(opcao[len-1] == '\n'){
            opcao[len-1] = '\0';
        }

        num_opcao = string_to_int(opcao);


        switch (num_opcao) {
            case 1:
                contador_ID++;
                insert(&listDoentes, contador_ID);
                break;
            case 2:
                //Eliminar um doente existente
                mostra_nome_id(&listDoentes);
                char var[50];


                printf("Para remover, introduza o ID do doente:\n");
                fgets(var, 50, stdin);

                if(var[strlen(var) - 1] == '\n'){
                    var[strlen(var) - 1] = '\0';
                }

                while(string_to_int(var) == 0){
                    printf("ID inválido, introduza novamente:\n");
                    fgets(var, 50, stdin);
                    if(var[strlen(var) - 1] == '\n'){
                        var[strlen(var) - 1] = '\0';
                    }
                }

                file = fopen("docs/doentes.txt","w");

                if (file == NULL) {
                    printf("Erro ao abrir o arquivo doentes.txt para escrita.\n");
                    return -1;
                }

                remove_doente(&listDoentes,string_to_int(var));

                fclose(file);


                break;

            case 3:
                ordem_alfabetica(&listDoentes);
                break;

            case 4:
                //listar_doente_tensao(&listDoentes,100);
                //Listar os doentes com tensões máximas acima de um determinado valor (por ordem decrescente das mesmas)
                break;

            case 5:
                //Apresentar toda a informação de um determinado doente
                printf("i");
                break;

            case 6:
                //Registar as tensões, o peso e a altura de um determinado doente num determinado dia. 

                /*int ID_num, dia , mes, ano, ten_max, ten_min;
                double altura, peso;

                do {
                    printf("Por favor, insira o ID do paciente: ");
                    char ID[50];
                    fgets(ID, 50, stdin);
                    if (ID[strlen(ID) - 1] == '\n') {
                        ID[strlen(ID) - 1] = '\0';
                    }
                    ID_num = string_to_int(ID);
                } while (ID_num == 0 || ID_num == INT_MAX); // Verifica se é zero ou se está no limite superior de um inteiro


                do {
                    printf("Por favor, insira o dia do registo: ");
                    char input_dia[50];
                    fgets(input_dia, 50, stdin);
                    if (input_dia[strlen(input_dia) - 1] == '\n') {
                        input_dia[strlen(input_dia) - 1] = '\0';
                    }
                    dia = string_to_int(input_dia);
                } while (dia < 1 || dia > 31);

                // Solicitar e verificar o mês
                do {
                    printf("Por favor, insira o mês do registo: ");
                    char input_mes[50];
                    fgets(input_mes, 50, stdin);
                    if (input_mes[strlen(input_mes) - 1] == '\n') {
                        input_mes[strlen(input_mes) - 1] = '\0';
                    }
                    mes = string_to_int(input_mes);
                } while (mes < 1 || mes > 12);

                // Solicitar e verificar o ano
                do {
                    printf("Por favor, insira o ano do registo: ");
                    char input_ano[50];
                    fgets(input_ano, 50, stdin);
                    if (input_ano[strlen(input_ano) - 1] == '\n') {
                        input_ano[strlen(input_ano) - 1] = '\0';
                    }
                    ano = string_to_int(input_ano);
                } while (ano > 2024);

                // Solicitar e verificar a tensão máxima
                do {
                    printf("Por favor, insira a tensão máxima (mmHg) do registo: ");
                    char input_ten_max[50];
                    fgets(input_ten_max, 50, stdin);
                    if (input_ten_max[strlen(input_ten_max) - 1] == '\n') {
                        input_ten_max[strlen(input_ten_max) - 1] = '\0';
                    }
                    ten_max = string_to_int(input_ten_max);
                } while (ten_max < 0 || ten_max > 500); // Exemplo de valores válidos, ajuste conforme necessário

                // Solicitar e verificar a tensão mínima
                do {
                    printf("Por favor, insira a tensão mínima (mmHg) do registo: ");
                    char input_ten_min[50];
                    fgets(input_ten_min, 50, stdin);
                    if (input_ten_min[strlen(input_ten_min) - 1] == '\n') {
                        input_ten_min[strlen(input_ten_min) - 1] = '\0';
                    }
                    ten_min = string_to_int(input_ten_min);
                } while (ten_min < 0 || ten_min > 300); // Exemplo de valores válidos, ajuste conforme necessário

                // Solicitar e verificar o peso
                do {
                    printf("Por favor, insira o peso (kg) do registo: ");
                    char input_peso[50];
                    fgets(input_peso, 50, stdin);
                    if (input_peso[strlen(input_peso) - 1] == '\n') {
                        input_peso[strlen(input_peso) - 1] = '\0';
                    }
                    peso = string_to_double(input_peso);
                    printf("%f",peso);
                } while (peso < 0); // Exemplo de valores válidos, ajuste conforme necessário

                // Solicitar e verificar a altura
                do {
                    printf("Por favor, insira a altura (m) do registo: ");
                    char input_altura[50];
                    fgets(input_altura, 50, stdin);
                    if (input_altura[strlen(input_altura) - 1] == '\n') {
                        input_altura[strlen(input_altura) - 1] = '\0';
                    }
                    altura = string_to_double(input_altura);
                    printf("%f",altura);
                } while (altura <0); // Exemplo de valores válidos, ajuste conforme necessário


                inserir_registos(&listDoentes,dia, mes, ano, ID_num , ten_max, ten_min, peso, altura);*/

                break;

            case 7:
                //Sair

                printf("A sair...\n");
                break;

            default:
                printf("Opcao invalida.\n");
        }
    } while (num_opcao != 7);

    return 0;
}

//para implementar uma forma para proteger o codigo ao inserir, podiamos usar switch e do-while