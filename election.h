#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED
#include <stdio.h>
#include<string.h>
typedef struct{
int j; 
int m ; 
int a;
}Date;
typedef struct {
int id;
char Muni[50];
int nbrh;
int nbrc;
Date d;
}election;
int ajouter(char * filename, election e );
int modifier( char * filename, int iden, election new );
int supprimer(char * filename, int iden);
election chercher(char * filename, int iden);
#endif

