#ifndef cabecalho
#define cabecalho
#include "structs.h"

int string_to_int(char str[]);
long string_to_long(char str[]);
void init(list_doentes_t *list);
void insert(list_doentes_t *list, int contador);
void search(list_doentes_t *list,int ID, l_node_doentes_t **prev, l_node_doentes_t **cur);
void remove_doente(list_doentes_t *list, int ID);
void ordem_alfabetica(list_doentes_t *list);
void recolhe_info_fich(list_doentes_t *list);
void insere_ordenado(list_doentes_t *list, Doente doente);
void inserir_registos(list_doentes_t *list,int dia, int mes, int ano, int ID, int ten_max, int ten_min, float peso, float alt);
float string_to_double(char str[]);
void escreve_ficheiro(list_doentes_t *list);
void mostra_nome_id(list_doentes_t *list);
#endif 