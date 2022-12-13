#include <stdio.h>
#include <time.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "bureau.h"
#include "callbacks.h"
#include <gtk/gtk.h>
#include"user.h"

enum
{
	ID,
	CAPELEC,
	CAPOBS,
        ADR,
	IDA,
	COLUMNS,
};


void ajouter_bureau(bureau p, char *filename)
{
GtkWidget *pQuestion, *pInfo;
FILE *f;
int i=0;
gpointer user_data;
bureau b;
f=fopen(filename,"a+");
if(f!=NULL)
{	while(fscanf(f,"%s %d %d %s %s \n",b.id,&(b.cap_elec),&(b.cap_obs),b.b_adr,b.id_agentb)!=EOF)
	{
		
	if(strcmp(p.id,b.id)==0)
		i++;
	}
	if(i==0){
	fprintf(f,"%s %d %d %s %s \n",p.id,p.cap_elec,p.cap_obs,p.b_adr,p.id_agentb);
	pQuestion=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Bureau ajouté avec succès !");
	switch(gtk_dialog_run(GTK_DIALOG(pQuestion)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pQuestion);
	break;
	}
	}
	if(i!=0){
	pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_WARNING,GTK_BUTTONS_OK,"ID doit etre unique !");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}
	}
	fclose(f);
}
}

void modifier_bureau(bureau p, char *filename){
bureau b;
GtkWidget *pInfo;
gpointer user_data;
FILE *f, *g;
f=fopen(filename,"r");
g=fopen("dump.txt","w");
if(f==NULL||g==NULL)
{
	return;
}
else{
	while(fscanf(f,"%s %d %d  %s %s \n",b.id,&(b.cap_elec),&(b.cap_obs),b.b_adr,b.id_agentb)!=EOF)
	{
		if(strcmp(b.id,p.id)!=0)
			fprintf(g,"%s %d %d %s %s \n",b.id,b.cap_elec,b.cap_obs,b.b_adr,b.id_agentb);
		else
			fprintf(g,"%s %d %d %s %s \n",b.id,p.cap_elec,p.cap_obs,p.b_adr,p.id_agentb);
	}
	pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Bureau modifié avec succès !");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}
	fclose(f);
	fclose(g);
remove(filename);
rename("dump.txt",filename);
}
}



/*int supprimer_bureau(bureau p, char *filename)
{
bureau b;
int a=0;
GtkWidget *pInfo;
gpointer user_data;
FILE *f, *g;
f=fopen(filename,"r");
g=fopen("dump.txt","w");
if(f!=NULL&&g!=NULL){
	while(fscanf(f,"%s %d %d %s %s \n",b.id,&(b.cap_elec),&(b.cap_obs),b.b_adr,b.id_agentb)!=EOF)
	{
		if(strcmp(b.id,p.id)!=0)
			fprintf(g,"%s %d %d %s %s \n",b.id,b.cap_elec,b.cap_obs,b.b_adr,b.id_agentb);
		else
			a=1;
	}
	pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,a==1?"Bureau supprimé avec succès":"Bureau introuvable");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}
	fclose(f);
	fclose(g);
remove(filename);
rename("dump.txt",filename);
}
return a;
}*/

bureau fchercher(char *id, char *filename){
bureau b, e;
FILE *f;
f=fopen(filename,"r");
if(f!=NULL){
	while(fscanf(f,"%s %d %d %s %s \n",b.id,&(b.cap_elec),&(b.cap_obs),b.b_adr,b.id_agentb)!=EOF)
	{
		if(strcmp(b.id,id)==0)
			return b;
	}
	fclose(f);
}
strcpy(e.id,"");
return e;
}



void afficher(GtkWidget *liste, char *filename)
{
bureau p;
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
gchar capelec[10], capobs[10];
FILE *f;


store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" Identifiant", renderer,"text",ID, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	gtk_tree_view_column_set_expand(column,TRUE);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" Capacité electeurs", renderer,"text",CAPELEC, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	gtk_tree_view_column_set_expand(column,TRUE);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" Capacité observateurs", renderer,"text",CAPOBS, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	gtk_tree_view_column_set_expand(column,TRUE);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" Adresse", renderer,"text",ADR, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	gtk_tree_view_column_set_expand(column,TRUE);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" ID Agent", renderer,"text",IDA, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	gtk_tree_view_column_set_expand(column,TRUE);




store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
f=fopen(filename,"r");
if(f!=NULL)

{ f = fopen(filename,"a+");
	while(fscanf(f,"%s %d %d %s %s \n",p.id,&(p.cap_elec),&(p.cap_obs),p.b_adr,p.id_agentb)!=EOF)
	{
sprintf(capelec,"%d",p.cap_elec);
sprintf(capobs,"%d",p.cap_obs);
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,ID,p.id,CAPELEC,capelec,CAPOBS,capobs,ADR,p.b_adr,IDA,p.id_agentb,-1);
	}
	fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref(store);
}
}
gtk_tree_view_set_enable_search(GTK_TREE_VIEW(liste),TRUE);
}


/*int saif_supprimer_bv(char fich[],char id[]){
    FILE *f=NULL;
    FILE *t = NULL;
	FILE *m = NULL;
    bureau p;
    int flag=0;
    f = fopen(fich,"r");
    t = fopen("temp.txt" , "a+");
    m = fopen("bvote.txt", "a+");
    if (f!=NULL)
    {
    while (fscanf(f,"%s %d %d %s %s \n",p.id,&(p.cap_elec),&(p.cap_obs),p.b_adr,p.id_agentb)!=EOF){
            if (strcmp(p.id,id)!=0){
		fprintf(t,"%s %d %d %s %s \n",p.id,(p.cap_elec),(p.cap_obs),p.b_adr,p.id_agentb);
		}else{
		flag = 1;
			fprintf(m,"%s %d %d %s %s \n",p.id,(p.cap_elec),(p.cap_obs),p.b_adr,p.id_agentb);
			
		}

        }}
        fclose(f);
	fclose(m);
        remove(fich);
        fclose(t);
        rename("temp.txt",fich);
	return flag;
}*/




int saif_check_substring(char str1[], char str2[]){
	int n1,n2,i,flag = 0;
	n1 = strlen(str1);
	n2= strlen(str2);
	if (n1<=n2){
	for (i=0;i<n1;i++){
		if (str1[i] == str2[i]){
			flag +=1;			
}
	}
	if (flag == n1){
		return 1;
	}else{
		return 0;
	}
}else{
	return 0;
}
}


/*void saif_treeview_search(GtkWidget *liste,char id[]){
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;

GtkTreeIter iter;

GtkListStore *store;

bureau p;

store = NULL;
gchar capelec[10], capobs[10];
FILE* f= NULL;
store = gtk_tree_view_get_model(liste);

if (store==NULL){

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" Identifiant", renderer,"text",ID, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	gtk_tree_view_column_set_expand(column,TRUE);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" Capacité electeurs", renderer,"text",CAPELEC, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	gtk_tree_view_column_set_expand(column,TRUE);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" Capacité observateurs", renderer,"text",CAPOBS, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	gtk_tree_view_column_set_expand(column,TRUE);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" Adresse", renderer,"text",ADR, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	gtk_tree_view_column_set_expand(column,TRUE);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" ID Agent", renderer,"text",IDA, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	gtk_tree_view_column_set_expand(column,TRUE);

}

store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

f = fopen("bvote.txt","r");
if (f==NULL){
return ;
}else{
while(fscanf(f,"%s %d %d %s %s \n",p.id,&(p.cap_elec),&(p.cap_obs),p.b_adr,p.id_agentb)!=EOF){
if (saif_check_substring(id, p.id)){
gtk_list_store_append(store, &iter);
gtk_list_store_set(store,&iter,ID,p.id,CAPELEC,p.cap_elec,CAPOBS,p.cap_obs,ADR,p.b_adr,IDA,p.id_agentb,-1);
}
}
fclose(f);

gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}}
*/

bureau saif_remplir_edit(char fich[], char id[]){

    FILE *f=NULL;
    bureau p;
    f = fopen(fich,"r");
    if (f!=NULL)
    {
    while (fscanf(f,"%s %d %d %s %s \n",p.id,&(p.cap_elec),&(p.cap_obs),p.b_adr,p.id_agentb)!=EOF){
		if (strcmp(p.id,id)==0){
 		fclose(f);
		return p;
		};
}
    }
 	fclose(f);
}


int saif_supprimer_bv(char fich[],char id[]){
    FILE *f=NULL;
    FILE *t = NULL;
    bureau p ;
    int flag=0;
    f = fopen(fich,"r");
    t = fopen("temp.txt" , "a+");
    if (f!=NULL)
    {
    while (fscanf(f,"%s %d %d %s %s \n",p.id,&(p.cap_elec),&(p.cap_obs),p.b_adr,p.id_agentb)!=EOF){
            if (strcmp(p.id,id)!=0){
		fprintf(t,"%s %d %d %s %s \n",p.id,(p.cap_elec),(p.cap_obs),p.b_adr,p.id_agentb);
		}else{
		flag = 1;
		}

        }}
        fclose(f);
        remove(fich);
        fclose(t);
        rename("temp.txt",fich);
	return flag;
}

/*void chercherbureau(GtkWidget *liste, char id[])
{

GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

bureau p=chercher(id,"bvote.txt");

store=NULL;

FILE* f=NULL;

store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" Identifiant", renderer,"text",ID, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" Capacité electeurs", renderer,"text",CAPELEC, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);


	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" Capacité observateurs", renderer,"text",CAPOBS, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);


	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" Adresse", renderer,"text",ADR, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);


	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" ID Agent", renderer,"text",IDA, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);



}


store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

f=fopen("bvote.txt","r");
if(f!=NULL)
{      
while(fscanf(f,"%s %d %d %s %s \n",p.id,&(p.cap_elec),&(p.cap_obs),p.b_adr,p.id_agentb)!=EOF)
{
if(saif_check_substring(id,p.id))
{
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,ID,p.id,CAPELEC,p.cap_elec,CAPOBS,p.cap_obs,ADR,p.b_adr,IDA,p.id_agentb,-1);
}
}
fclose(f);

gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref(store);
}
}*/

void chercherbureau(GtkWidget *liste, char id[])
{

GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

bureau p;

store=NULL;

FILE* f=NULL;

store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" Identifiant", renderer,"text",ID, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" Capacité electeurs", renderer,"text",CAPELEC, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" Capacité observateurs", renderer,"text",CAPOBS, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" Adresse", renderer,"text",ADR, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" ID Agent", renderer,"text",IDA, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

}


store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_INT, G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING);

f=fopen("bvote.txt","r");
if(f!=NULL)
{      
while(fscanf(f,"%s %d %d %s %s \n",p.id,&(p.cap_elec),&(p.cap_obs),p.b_adr,p.id_agentb)!=EOF)
{
if(saif_check_substring(id,p.id))
{
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,ID,p.id,CAPELEC,p.cap_elec,CAPOBS,p.cap_obs,ADR,p.b_adr,IDA,p.id_agentb,-1);
}
}
fclose(f);

gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref(store);
}
}



int nbr_vote_blanc(char*filename)
{
utilisateur u;
int k=0;
FILE* f=fopen(filename,"r");
if(f!=NULL)
{
	while(fscanf(f,"%d %s %s %s %s %d %d %d %s %s %d %s %s %d\n",&u.id,u.nom,u.prenom,u.nationalite,u.cin,&u.ddn.jour,&u.ddn.mois,&u.ddn.annee,u.login,u.mdp,&u.sexe,u.numbv,u.role,&u.vote)!=EOF)
	{
		if(u.vote==0)
		{
			k++;
		}
	}
}
return k;
}

/*
void taux_obser(char *filename)
{ 
utilisateur u;
float tn=0,te=0;
int nbO=0,nbn=0,nbe=0;
tn=0;
te=0;
FILE *f=fopen(filename, "r");
if(f!=NULL)
{
        while(fscanf(f,"%d %s %s %s %s %d %d %d %s %s %d %s %s %d\n",&u.id,u.nom,u.prenom,u.nationalite,u.cin,&u.ddn.jour,&u.ddn.mois,&u.ddn.annee,u.login,u.mdp,&u.sexe,u.numbv,u.role,&u.vote)!=EOF)
	{
	if(strcmp(u.nationalite,"tunisienne")==0)
		{nbn++;
		}
	if(strcmp(u.nationalite,"tunisienne")!=0)
		nbe++;
	}
	nbO=nbn+nbe;	
	tn=(float)nbn/nbO*100;
	te=(float)nbe/nbO*100;
	printf("\nnombre d observateur tunisien est %d",nbn);
	printf("\nnombre d'observateur etranger est %d \n",nbe);
	printf("\nle taux d'observateur tunisien est %.3f",tn);
	printf("\nle taux d'observateur etranger est %.3f \n",te);
}}*/
/*
void taux_obser(char *filename,float *tn,float *te)
{ 
utilisateur u;

FILE *f=fopen(filename, "r");
if(f!=NULL)
{
	while(fscanf(f,"%d %s %s %s %s %d %d %d %s %s %d %s %s %d\n",&u.id,u.nom,u.prenom,u.nationalite,u.cin,&u.ddn.jour,&u.ddn.mois,&u.ddn.annee,u.login,u.mdp,&u.sexe,u.numbv,u.role,&u.vote)!=EOF)
        {
	if(strcmp(u.nationalite,"tunisienne")==0)
		{(*tn)++;
		}
	else 
	{
		(*te)++;
	
	}
        }
	

}
}*/

int taux_obser_tun(char *filename)
{ 
utilisateur u;
int nbt=0;
int tn=0;
float k=0;
FILE *f=fopen(filename, "r");
if(f!=NULL)
{
	while(fscanf(f,"%d %s %s %s %s %d %d %d %s %s %d %s %s %d\n",&u.id,u.nom,u.prenom,u.nationalite,u.cin,&u.ddn.jour,&u.ddn.mois,&u.ddn.annee,u.login,u.mdp,&u.sexe,u.numbv,u.role,&u.vote)!=EOF)
	{
	if(strcmp(u.nationalite,"tunisienne")==0)
		{tn++;
		}
	}
        
	
}
return tn;
}



int taux_obser(char *filename)
{ 
utilisateur u;
int nbt=0;
FILE *f=fopen(filename, "r");
if(f!=NULL)
{
	while(fscanf(f,"%d %s %s %s %s %d %d %d %s %s %d %s %s %d\n",&u.id,u.nom,u.prenom,u.nationalite,u.cin,&u.ddn.jour,&u.ddn.mois,&u.ddn.annee,u.login,u.mdp,&u.sexe,u.numbv,u.role,&u.vote)!=EOF)
	
        { nbt++;
	
	}
	
}
return nbt;
}

