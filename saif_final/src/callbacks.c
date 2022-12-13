#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include"user.h"
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include"bureau.h"
int saif_accept=0;
int saif_flag_edit=0;
char saif_identifiant[30] ="";
int saif_oui_non_edit=0;


void
on_saif_radiobutton_oui_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{/*
char fich[20] = "bvote.txt";
GtkWidget *msg;
msg = lookup_widget(togglebutton,"saif_label_aff_msgcher");
if (strlen(saif_identifiant)>0){
bureau bv;
int x;
x=saif_supprimer_bv(fich,saif_identifiant);
gtk_label_set_text(msg,"Supprission terminé!");
GtkWidget *tree;
tree =  lookup_widget(togglebutton,"saif_treeview_aff");
afficher(tree,fich);
}
strcpy(saif_identifiant,"");
*/}


void
on_saif_radiobutton_non_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
GtkWidget *saif_window_supp_bv;
GtkWidget *saif_window_aff;
saif_window_supp_bv=lookup_widget(togglebutton,"saif_window_supp_bv");
gtk_widget_destroy(saif_window_supp_bv);
saif_window_aff=lookup_widget(togglebutton,"saif_window_aff");
saif_window_aff=create_saif_window_aff();
gtk_widget_show(saif_window_aff);
}


gboolean
on_saif_window_aff_focus_in_event      (GtkWidget       *widget,
                                        GdkEventFocus   *event,
                                        gpointer         user_data)
{
strcpy(saif_identifiant,"");
GtkWidget *tree;

tree =  lookup_widget(widget,"saif_treeview_aff");

afficher(tree,"bvote.txt");
  return FALSE;
}


void
on_saif_treeview_aff_row_activated     (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter  iter;
gchar *identifiant;


GtkTreeModel *model = gtk_tree_view_get_model(treeview);

if (gtk_tree_model_get_iter(model,&iter,path)){
gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0 , &identifiant ,-1);
strcpy(saif_identifiant,identifiant); 
saif_flag_edit = 0;
}
}


void
on_saif_button_aff_rech_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_saif_button_aff_sup_clicked         (GtkButton       *widget,
                                        gpointer         user_data)
{
GtkWidget *msg;
msg = lookup_widget(widget,"saif_label_aff_msgcher");
/*if (strlen(saif_identifiant)>0){
GtkWidget *saif_window_supp_bv;
GtkWidget *saif_window_aff;
saif_window_aff=lookup_widget(widget,"saif_window_aff");
gtk_widget_destroy(saif_window_aff);
saif_window_supp_bv=lookup_widget(widget,"saif_window_supp_bv");
saif_window_supp_bv=create_saif_window_supp_bv();
gtk_widget_show(saif_window_supp_bv);
}
else{
	
	gtk_label_set_text(msg,"Selectionner bureau de vote par double click!");
}*/
//strcpy(saif_identifiant,"");
/*
GtkWidget *saif_window_aff;
	GtkTreeModel     *model;
        GtkTreeSelection *selection;
        GtkTreeIter iter;
        GtkWidget* treeview;
	gchar id;
	saif_window_aff=lookup_widget(widget,"saif_window_aff");
        treeview=lookup_widget(saif_window_aff,"saif_treeview_aff");
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(treeview));
       if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {
		gtk_tree_model_get (model,&iter,0,&id,-1);
		saif_supprimer_bv("bvote.txt",id);
		afficher(treeview,"bvote.txt");
	}
*/		
char text[200];
char fich[20] = "bvote.txt";
if (strlen(saif_identifiant)>0){ 
	saif_supprimer_bv(fich,saif_identifiant);
	GtkWidget *tree;

	tree =  lookup_widget(GTK_WIDGET(widget),"saif_treeview_aff");

	afficher(tree,"bvote.txt");
		//strcpy(text,"<span color=\"green\" font-size=\"13500\"><b>Supprimer avec succes</b></span>");
		//gtk_label_set_markup(msg,text);
	strcpy(saif_identifiant,"");

}else{
		strcpy(text,"<span color=\"red\" font-size=\"11500\"><b>Selectionné bureau de vote avec double click</b></span>");
		gtk_label_set_markup(msg,text);
}

}

void
on_saif_button_aff_act_clicked         (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *saif_treeview_aff;
GtkWidget *saif_window_aff;
saif_window_aff=lookup_widget(objet,"saif_window_aff");
gtk_widget_destroy(saif_window_aff);
saif_window_aff=lookup_widget(objet,"saif_window_aff");
saif_window_aff=create_saif_window_aff();
gtk_widget_show(saif_window_aff);
saif_treeview_aff=lookup_widget(saif_window_aff,"saif_treeview_aff");
afficher(saif_treeview_aff,"bvote.txt");
}


void
on_saif_button_aff_ret_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_saif_button_aff_mod_clicked         (GtkButton       *widget,
                                        gpointer         user_data)
{/*
if (strlen(saif_identifiant)>0){
char fich="bvote.txt";
bureau p = chercher(saif_identifiant,fich);
GtkWidget *modifier,*id,*cap_elec,*cap_obs,*b_adr,*id_agentb;
modifier = create_saif_window_mod();
gtk_widget_show(modifier);
id = lookup_widget(GTK_WIDGET(widget),"saif_entry_mod_id"); 
cap_elec = lookup_widget(GTK_WIDGET(widget),"saif_spinbutton_mod_ce");
cap_obs = lookup_widget(GTK_WIDGET(widget),"saif_spinbutton_mod_co");
b_adr = lookup_widget(GTK_WIDGET(widget),"saif_combobox_mod_ad");
id_agentb = lookup_widget(GTK_WIDGET(widget),"saif_combobox_mod_idbv");

	
	//p = chercher(saif_identifiant,fich);
	gtk_entry_set_text(GTK_ENTRY(id),p.id);
	gtk_spin_button_set_value(cap_elec,p.cap_elec);
	gtk_spin_button_set_value(cap_obs,p.cap_obs);
	gtk_combo_box_set_active(GTK_COMBO_BOX(b_adr), p.b_adr);
	gtk_combo_box_set_active(GTK_COMBO_BOX(id_agentb), p.id_agentb);



strcmp(saif_identifiant,"");	
}else{
GtkWidget *msg;
msg = lookup_widget(widget,"saif_label_aff_msgcher");
gtk_label_set_text(msg,"Selectionner bureau de vote par double click!");
}*/

/*GtkWidget *saif_window_aff,*saif_window_mod;
	GtkTreeModel     *model;
        GtkTreeSelection *selection;
        GtkTreeIter iter;
        GtkWidget* treeview;
	gint cap_elec,cap_obs;
	gchar *id,*b_adr,*id_agentb;
	saif_window_aff=lookup_widget(widget,"saif_window_aff");
        treeview=lookup_widget(saif_window_aff,"saif_treeview_aff");
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(treeview));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {
		gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0 , &id ,1, &cap_elec,2, cap_obs,3 , b_adr,4, id_agentb,-1);
		gtk_widget_destroy(saif_window_aff);
		saif_window_mod=lookup_widget(widget,"saif_window_mod");
		saif_window_mod=create_saif_window_mod();
		gtk_widget_show(saif_window_mod);
		//p=saif_remplir_edit(fich,id);
	        gtk_entry_set_text(GTK_ENTRY(lookup_widget(saif_window_mod,"saif_entry_mod_id")),id);
		gtk_spin_button_set_value(GTK_SPIN_BUTTON(lookup_widget(saif_window_mod,"saif_spinbutton_mod_ce")),cap_elec);
		gtk_spin_button_set_value(GTK_SPIN_BUTTON(lookup_widget(saif_window_mod,"saif_spinbutton_mod_co")),cap_obs);
		gtk_combo_box_set_active(GTK_COMBO_BOX(lookup_widget(saif_window_mod,"saif_combobox_mod_ad")),b_adr);
		gtk_combo_box_set_active(GTK_COMBO_BOX(lookup_widget(saif_window_mod,"saif_combobox_mod_idbv")),id_agentb);

	}
*/


GtkWidget *saif_window_aff,*mod;
GtkWidget *saif_entry_mod_id, *saif_spinbutton_mod_ce, *saif_spinbutton_mod_co, *saif_combobox_mod_ad, *saif_combobox_mod_idbv, *pInfo;
GtkWidget saif_window_mod;
char capobs[20], capelec[10], id[20];
bureau b;
int a=0;
saif_window_aff=lookup_widget(widget,"saif_window_aff");
gtk_widget_destroy(saif_window_aff);
mod=lookup_widget(widget,"saif_window_mod");
mod=create_saif_window_mod();
gtk_widget_show(mod);
saif_entry_mod_id=lookup_widget(widget,"saif_entry_mod_id");
saif_spinbutton_mod_ce=lookup_widget(widget,"saif_spinbutton_mod_ce");
saif_spinbutton_mod_co=lookup_widget(widget,"saif_spinbutton_mod_co");
saif_combobox_mod_ad=lookup_widget(widget,"saif_combobox_mod_ad");
saif_combobox_mod_idbv=lookup_widget(widget,"saif_combobox_mod_idbv");
FILE *f;
f = fopen("bvote.txt","r");
if(f!=NULL){
while(fscanf(f,"%s %d %d %s %s \n",b.id,&(b.cap_elec),&(b.cap_obs),b.b_adr,b.id_agentb)!=EOF)
	{
		if(strcmp(b.id,saif_identifiant)==0){
			a=1;
			break;
                 }
	}
fclose(f);
}
if(a==1){
gtk_entry_set_text(GTK_ENTRY(saif_entry_mod_id),b.id);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(saif_spinbutton_mod_ce),b.cap_elec);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(saif_spinbutton_mod_co),b.cap_obs);
gtk_combo_box_set_active (GTK_COMBO_BOX(saif_combobox_mod_ad), b.b_adr);
gtk_combo_box_set_active (GTK_COMBO_BOX(saif_combobox_mod_idbv), b.id_agentb);


}
else{
pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_ERROR,GTK_BUTTONS_OK,"Bureau introuvable");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}
}
}


void
on_saif_button_aff_aj_clicked          (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *saif_window_aj;
GtkWidget *saif_window_aff;
saif_window_aff=lookup_widget(objet,"saif_window_aff");
gtk_widget_destroy(saif_window_aff);
saif_window_aj=lookup_widget(objet,"saif_window_aj");
saif_window_aj=create_saif_window_aj();
gtk_widget_show(saif_window_aj);
}


void
on_saif_button_aj_conf_clicked         (GtkButton       *objet,
                                        gpointer         user_data)
{
bureau p;

GtkWidget* input1 ;
GtkWidget* input2 ;
GtkWidget* input3 ;
GtkWidget* input4 ;
GtkWidget* input5 ;
GtkWidget* saif_checkbutton_aj ;
GtkWidget *saif_window_aj;
GtkWidget *pInfo;


saif_window_aj=lookup_widget(objet,"saif_window_aj");

input1= lookup_widget(objet,"saif_entry_aj_id") ;
input2= lookup_widget(objet,"saif_spinbutton_aj_ce") ;
input3= lookup_widget(objet,"saif_spinbutton_aj_co") ;
input4= lookup_widget(objet,"saif_combobox_aj_ad");
input5= lookup_widget(objet,"saif_combobox_aj_idbv");

saif_checkbutton_aj= lookup_widget(objet,"saif_checkbutton_aj");

strcpy(p.id,gtk_entry_get_text(GTK_ENTRY(input1)));
p.cap_elec= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input2));
p.cap_obs= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input3));
strcpy(p.b_adr,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input4)));
strcpy(p.id_agentb,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input5)));

//if(saif_accept==1)
ajouter_bureau(p,"bvote.txt");

/*else
{
pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_ERROR,GTK_BUTTONS_OK,"Confirmation requise");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}
}*/
}


void
on_saif_button_aj_ret_clicked          (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *saif_window_aj;
GtkWidget *saif_window_aff;
saif_window_aj=lookup_widget(objet,"saif_window_aj");
gtk_widget_destroy(saif_window_aj);
saif_window_aff=lookup_widget(objet,"saif_window_aff");
saif_window_aff=create_saif_window_aff();
gtk_widget_show(saif_window_aff);
}


void
on_saif_checkbutton_aj_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton)){ 
	saif_accept = 1;
}else{
	saif_accept = 0;

}
}


gboolean
on_saif_window_mod_focus_in_event      (GtkWidget       *widget,
                                        GdkEventFocus   *event,
                                        gpointer         user_data)
{/*
if (saif_flag_edit==0){
GtkWidget *id,*cap_elec,*cap_obs,*b_adr,*id_agentb; 

bureau p; 
//saif_flag_tree_view = 0; 
char fich[20] = "bvote.txt";

id = lookup_widget(GTK_WIDGET(widget),"saif_entry_mod_id"); 
cap_elec = lookup_widget(GTK_WIDGET(widget),"saif_spinbutton_mod_ce");
cap_obs = lookup_widget(GTK_WIDGET(widget),"saif_spinbutton_mod_co");
b_adr = lookup_widget(GTK_WIDGET(widget),"saif_combobox_mod_adr");
id_agentb = lookup_widget(GTK_WIDGET(widget),"saif_combobox_mod_idbv");

char ide[40];
//saif_oui_non_edit=1;
if (strcmp(saif_identifiant,"")!=0){
p = chercher(saif_identifiant,fich);
//int index=0;
//int idab=0;
gtk_entry_set_text(GTK_ENTRY(ide),p.id);
gtk_spin_button_set_value(cap_elec,p.cap_elec);
gtk_spin_button_set_value(cap_obs,p.cap_obs);
gtk_combo_box_set_active (GTK_COMBO_BOX(b_adr), p.b_adr);
gtk_combo_box_set_active (GTK_COMBO_BOX(id_agentb), p.id_agentb);

}

}
strcmp(saif_identifiant,"");
saif_flag_edit=1;

*/
   if (saif_flag_edit==0){
GtkWidget *id, *cap_elec, *cap_obs, *b_adr, *id_agentb;

bureau b;
char idn[40];

id= lookup_widget((widget),"saif_entry_mod_id") ;
cap_elec= lookup_widget((widget),"saif_spinbutton_mod_ce") ;
cap_obs= lookup_widget((widget),"saif_spinbutton_mod_co") ;
b_adr= lookup_widget((widget),"saif_combobox_mod_adr");
id_agentb= lookup_widget((widget),"saif_combobox_mod_idbv");

if (strcmp(saif_identifiant,"")!=0){
b = saif_remplir_edit("bvote.txt",saif_identifiant);
int index;
if (strcmp(b.id_agentb,"123344") == 0){
index = 0;
}
else{
if (strcmp(b.id_agentb,"123456") == 0){
index = 1;
}
else{
if (strcmp(b.id_agentb,"765432") == 0){
index = 2;
}
else{
if (strcmp(b.id_agentb,"5546464") == 0){
index = 3;
}

}}}

int ind;
if (strcmp(b.b_adr,"la_nouvelle_matmata") == 0){
ind = 0;
}
else{
if (strcmp(b.b_adr,"la_ancienne_matmata") == 0){
ind = 1;
}
else{
if (strcmp(b.b_adr,"hamma") == 0){
ind = 2;
}
else{
if (strcmp(b.b_adr,"matouia") == 0){
ind = 3;
}
else{
if (strcmp(b.b_adr,"toujane") == 0){
ind = 4;
}
else{
if (strcmp(b.b_adr,"ghannouch") == 0){
ind = 5;
}
else{
if (strcmp(b.b_adr,"gabes_sud") == 0){
ind = 6;
}
else{
if (strcmp(b.b_adr,"gabes_ouest") == 0){
ind = 7;
}
else{
if (strcmp(b.b_adr,"gabes_medina") == 0){
ind = 8;
}
else{
if (strcmp(b.b_adr,"mareth") == 0){
ind = 9;
}
else{
if (strcmp(b.b_adr,"manzel_hbib") == 0){
ind = 10;

}}}}}}}}}}}

gtk_entry_set_text(GTK_ENTRY(id),b.id);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(cap_elec),b.cap_elec);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(cap_obs),b.cap_obs);
gtk_combo_box_set_active (GTK_COMBO_BOX(b_adr),ind);
gtk_combo_box_set_active (GTK_COMBO_BOX(id_agentb),index);
}
}
strcmp(saif_identifiant,"");
saif_flag_edit=1;


  return FALSE;
	
}

void
on_saif_button_md_conf_clicked         (GtkButton       *objet,
                                        gpointer         user_data)
{
bureau p;
GtkWidget* input1 ;
GtkWidget* input2 ;
GtkWidget* input3 ;
GtkWidget* input4 ;
GtkWidget* input5 ;
GtkWidget* saif_checkbutton_mod ;
GtkWidget *saif_window_mod;
GtkWidget *pInfo;


saif_window_mod=lookup_widget(objet,"saif_window_mod");

input1= lookup_widget(objet,"saif_entry_mod_id") ;
input2= lookup_widget(objet,"saif_spinbutton_mod_ce") ;
input3= lookup_widget(objet,"saif_spinbutton_mod_co") ;
input4= lookup_widget(objet,"saif_combobox_mod_ad");
input5= lookup_widget(objet,"saif_combobox_mod_idbv");

saif_checkbutton_mod= lookup_widget(objet,"saif_checkbutton_mod");

strcpy(p.id,gtk_entry_get_text(GTK_ENTRY(input1)));
p.cap_elec= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input2));
p.cap_obs= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input3));
strcpy(p.b_adr,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input4)));
strcpy(p.id_agentb,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input5)));
modifier_bureau(p,"bvote.txt");
/*pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Bureau modifié avec succès");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}
*/
}


void
on_saif_button_md_ret_clicked          (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *saif_window_mod;
GtkWidget *saif_window_aff;
saif_window_mod=lookup_widget(objet,"saif_window_mod");
gtk_widget_destroy(saif_window_mod);
saif_window_aff=lookup_widget(objet,"saif_window_aff");
saif_window_aff=create_saif_window_aff();
gtk_widget_show(saif_window_aff);
}


void
on_saif_checkbutton_mod_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_saif_button_app_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
 GtkWidget *saif_window_login,*saif_window_aff;
 GtkWidget *user,*pass,*resultat; 
char username[20]; 
char password[20];
char text[20];
user= lookup_widget(button,"saif_entry_user");
pass = lookup_widget(button,"saif_entry_pass");
strcpy(username,gtk_entry_get_text(GTK_ENTRY(user)));
strcpy(password,gtk_entry_get_text(GTK_ENTRY(pass))); 
if ((strcmp(username,"bv")==0)&&(strcmp (password,"bv")==0)) 
{
saif_window_login=lookup_widget(button,"saif_window_login");
saif_window_aff = create_saif_window_aff (); 
gtk_widget_show (saif_window_aff);
gtk_widget_destroy(saif_window_login); }
else {
resultat=lookup_widget(button,"saif_label_login");
strcpy(text,"user not found ");
gtk_label_set_text(GTK_LABEL(resultat),text);


}

}


void
on_saif_entry_aff_cher_changed         (GtkEditable     *editable,
                                        gpointer         user_data)
{
GtkWidget *saif_entry_aff_cher;
char id[20]= "", fich[20]="bvote.txt";
int i;
GtkWidget *tree;
tree =  lookup_widget(editable,"saif_treeview_aff");

saif_entry_aff_cher = lookup_widget(GTK_WIDGET(editable),"saif_entry_aff_cher");
i=atoi(gtk_entry_get_text(GTK_ENTRY(saif_entry_aff_cher)));
sprintf(id,"%d",i);
chercherbureau(tree,id);
}


void
on_saif_button_ret_stat_clicked        (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *saif_window_stat;
GtkWidget *saif_window_aff;
saif_window_stat=lookup_widget(objet,"statistique");
gtk_widget_destroy(saif_window_stat);
saif_window_aff=lookup_widget(objet,"saif_window_aff");
saif_window_aff=create_saif_window_aff();
gtk_widget_show(saif_window_aff);
}


void
on_saif_button_aff_stat_clicked        (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *saif_window_stat;
GtkWidget *saif_window_aff;
saif_window_aff=lookup_widget(objet,"saif_window_aff");
gtk_widget_destroy(saif_window_aff);
saif_window_stat=lookup_widget(objet,"statistique");
saif_window_stat=create_statistique();
gtk_widget_show(saif_window_stat);
}


gboolean
on_statistique_focus_in_event          (GtkWidget       *widget,
                                        GdkEventFocus   *event,
                                        gpointer         user_data)
{
GtkWidget *saif_aff_stat;
GtkWidget *saif_label_nbvb,*saif_label_ton,*saif_label_toe;
saif_label_nbvb=lookup_widget(GTK_WIDGET(widget),"saif_label_nbvb");
saif_label_ton=lookup_widget(GTK_WIDGET(widget),"saif_label_ton");
saif_label_toe=lookup_widget(GTK_WIDGET(widget),"saif_label_toe");
saif_aff_stat=lookup_widget(widget,"statistique");
int x=0,z=0,e=0;
float t=0,r=0;
char nb[20]="",taux_etrang[20]="",taux_tun[20]="";
x=nbr_vote_blanc("utilisateur.txt");
sprintf(nb,"%d",x);
gtk_label_set_text(GTK_LABEL(saif_label_nbvb),nb);
z = taux_obser_tun("utilisateur.txt");
e = taux_obser("utilisateur.txt");
t=((float)z/e)*100;
r=((float)(e-z)/e)*100;
sprintf(taux_etrang,"%.2f",r); 
sprintf(taux_tun,"%.2f",t);
strcat(taux_tun,"%");
strcat(taux_etrang,"%");
gtk_label_set_text(GTK_LABEL(saif_label_ton),taux_tun);
gtk_label_set_text(GTK_LABEL(saif_label_toe),taux_etrang);


  return FALSE;
}

