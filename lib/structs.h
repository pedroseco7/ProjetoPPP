#ifndef STRUCT
#define STRUCT

typedef struct registo{
    int ten_min;
    int ten_max;
    int peso;
    double altura;
    int ID;
}registo_t;

typedef struct l_node_registos{
    registo_t registo;
    struct l_node *next;
}l_node_registos_t;

typedef struct list_registo{
    size_t num_elem;
    l_node_registos_t *front;
}list_registo_t;

typedef struct{
    int ID;
    char nome[30];
    int dia;
    int mes;
    int ano;
    char cc[14];
    long telemovel;
    char email[30];
    list_registo_t *registos;
}Doente;

typedef struct l_node{
    Doente doente;
    struct l_node *next;
}l_node_doentes_t;

typedef struct list_doentes{
    size_t num_elems;
    l_node_doentes_t *front;
}list_doentes_t;

#endif