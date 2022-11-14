#include <stdio.h>
#include <string.h>
#include"list_elec.h"

int main()
{
    LIST_ELEC l1={"14569","12549","gauche","12499","ali"},l2={"54983","265798","droite","54976","chadha"},l3;
    
    int x=ajouter("LIST_ELEC.txt", l1);
    x=ajouter("LIST_ELEC.txt", l3);
    
    if(x==1)
        printf("\n ajout d'une liste avec succes");
    else printf("\n echec ajout");
        
    x=modifier("LIST_ELEC.txt","54976",l2 );

    if(x==1)
        printf("\nModification de la liste avec succés");
    else printf("\nechec Modification");
    x=supprimer("LIST_ELEC","14569");
    if(x==1)
        printf("\nSuppression de la liste avec succés");
    else printf("\nechec Suppression");
    l3=chercher("LIST_ELEC","54983");
    if(l3.id_list
==-1)
        printf("introuvable");
    return 0; 
}
