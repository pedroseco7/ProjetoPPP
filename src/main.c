#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include "structs.h"
#include "cabecalho.h"

#define MAX_PAC 100


int main(){

    Doente doentes[MAX_PAC];

    char *opcao = (char *)malloc(sizeof(char)*20);

    fgets(opcao,20,stdin);

    int len = strlen(opcao);

    if(opcao[len-1] == '\n'){
        opcao[len-1] = '\0';
    }


    do {
        printf("\n=== Menu ===\n");
        printf("1. Adicionar Doente\n");
        printf("2. Eliminar Doente\n");
        printf("3. Listar Doente por Ordem Alfabética\n");
        printf("4. Listar os Doentes com Tensões Máximas acima de um determinado valor\n");
        printf("5. Apresentar a informação de um doente\n");
        printf("6. Registar a informação de um determinado doente \n");
        printf("7. Sair\n");
        printf("Opcao: ");


        

        switch (opcao) {
            case 1:
                adicionarPaciente(pacientes, &total_pacientes);
                break;
            case 2:
                if (total_pacientes > 0) {
                    int indice;
                    printf("Indice do paciente: ");
                    scanf("%d", &indice);
                    if (indice >= 0 && indice < total_pacientes) {
                        mostrarPaciente(pacientes[indice]);
                    } else {
                        printf("Indice invalido.\n");
                    }
                } else {
                    printf("Nenhum paciente cadastrado.\n");
                }
                break;
            
            case 3:
        
                break;
            
            case 4:

                break;

            


            case 7:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida.\n");
        }
    } while (opcao != 3);
    

    

    

    
    

    int opcao;

    
    



    return 0;
}

//para implementar uma forma para proteger o codigo ao inserir, podiamos usar switch e do-while