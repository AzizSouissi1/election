#include "list_elec.h"

int ajouter(char * filename, LIST_ELEC l)
{
    FILE * f=fopen(filename, "a");
    if(f!=NULL)
    {
        fprintf(f,"%d %s %s %s %s\n", l.id_list,l.id_electeur,l.orientation,l.id_condidat,l.nom_condidat);
        fclose(f);
        return 1;
    }
    else return 0;
}
int modifier( char * filename, char id_list, LIST_ELEC nouv )
{
    int tr=0;
    LIST_ELEC l ;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%d %s %s %s %s\n",&l.id_list,&l.id_electeur,&l.orientation,&l.id_condidat,&l.nom_condidat)!=EOF)
        {
	 if(l.id_list== id_list)
            {
		tr=1;

		fprintf(f2,"%d %s %s %s %s\n",nouv.id_list,nouv.id_electeur,nouv.orientation,nouv.id_condidat,nouv.nom_condidat);
                
            }
            else
                fprintf(f2,"%d %s %s %s %s\n",l.id_list,l.id_electeur,l.orientation,l.id_condidat,l.nom_condidat);

        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;

}
int supprimer(char * filename, char id_list)
{
    int tr=0;
    LIST_ELEC l;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%d %s %s %s %S \n",&l.id_list,&l.id_electeur,&l.orientation,&l.id_condidat,&l.nom_condidat)!=EOF)
        {
            if(l.id_list== id_list)
                tr=1;
            else
                fprintf(f2,"%d %s %s %s %s \n",l.id_list,l.id_electeur,l.orientation,l.id_condidat,l.nom_condidat);
        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;
}
LIST_ELEC chercher(char * filename, char id_list)
{
    LIST_ELEC l ;
    int tr;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while(tr==0 && fscanf(f,"%d %s %s %s %s \n",&l.id_list,&l.id_electeur,&l.orientation,&l.id_condidat,&l.nom_condidat)!=EOF)
        {
            if(l.id_list== id_list)
                tr=1;
        }
    }
    fclose(f);
    if(tr==0)
        l.id_list==-1;
    return l;

}
