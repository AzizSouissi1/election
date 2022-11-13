#ifndef list_elec_H_INCLUDED
#define list_elec_H_INCLUDED
#include <stdio.h>

typedef struct liste_electorale
{
    int id_list[20];
    char id_electeur[20];
    char orientation [10];
    char id_condidat[20];
    char nom_condidat[20];

} LIST_ELEC ;


int ajouter(char * filename, LIST_ELEC l);
int modifier( char * filename, int id_list , LIST_ELEC nouv );
int supprimer(char * filename, int id_list );

LIST_ELEC chercher(char *, int id_list);

#endif
