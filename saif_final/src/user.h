#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED

typedef struct{
int jour;
int mois;
int annee;
}date;
typedef struct{
int id;
char nationalite[50];
char nom[50];
char prenom[50];
char cin[50];
date ddn ;
char login[50];
char mdp[50];
int sexe;
char adresse[50];
char numbv[50];
char role[50];
int vote;
}utilisateur;

/*int ajouter(char *filename,user u);
int modifier( char *filename, int id, user nouv);
int supprimer(char *filename, int id);
user chercher(char *filename, int id);
int nbr_bote_blanc(char*filename);
void taux_obser(char *filename);
*/

#endif // USER_H_INCLUDED
