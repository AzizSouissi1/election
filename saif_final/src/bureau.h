#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>


typedef struct {
char id[30];
int cap_elec;
int cap_obs;
char b_adr[30];  
char  id_agentb[30];
} bureau ;

void ajouter_bureau(bureau p, char *filename);
void modifier_bureau(bureau p, char *filename);
//int supprimer_bureau(char *filename, bureau p );
void afficher(GtkWidget *liste, char *filename);
bureau chercher(char *id, char *filename);
int saif_supprimer_bv(char fich[],char id[]);
int saif_check_substring(char str1[], char str2[]);
//void saif_treeview_search(GtkWidget *liste,char id[]);
bureau saif_remplir_edit(char fich[], char id[]);
void chercherbureau(GtkWidget *liste, char id[]);
int nbr_vote_blanc(char*filename);
//void taux_obser(char *filename);
//void taux_obser(char *filename,float *tn,float *te);
int taux_obser_tun(char *filename);
int taux_obser(char *filename);

