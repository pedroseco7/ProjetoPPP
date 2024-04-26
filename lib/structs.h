#ifndef STRUCT
#define STRUCT


typedef struct{
    int ten_min;
    int ten_max;
    int peso;
    double altura;
    int ID;
}Registo;

typedef struct l_node{
    Registo registo;
    struct l_node *next;
}l_node_t;

typedef struct list_registo{
    size_t num_elem;
    l_node_t *front;
}list_registo_t;

typedef struct{
    char nome[30];
    int dia;
    int mes;
    int ano;
    char cc[13];
    int telemovel;
    char email[30];
    int ID;
    list_registo_t *registos;
}Doente;

#endif