#include <stdio.h>
#include <string.h>
#include"BureauVote.h"
int main()
{
   bv bv1= {12,8,25,25,"Elghazela"},bv2= {11,6,30,138,"Nkhilette"},bv3={105,5,20,123,"Morneg"};
   int x;
x=ajouter("bv2.txt", bv1);
x=ajouter("bv2.txt", bv2);
//x=ajouter("bv2.txt", bv3);
    if(x==1)
        printf("\najout  du bureau de vote avec succés  ");
    else printf("\nechec ajout");
  
  x=modifier("bv2.txt",11,bv2);

    if(x==1)
        printf("\nModification du bureau de vote avec succés ");
    else printf("\nechec Modification");
    x=supprimer("bv2.txt",105);
    if(x==1)
        printf("\nSuppression du bureau de vote avec succés ");
    else printf("\nechec Suppression");
    bv3=chercher("bv2.txt",11);
    if(bv3.idbureau==-1)
        printf("introuvable");
    return 0;
}
