
#include "string.h"
#include  <stdio.h>
#include <stdlib.h>
#include "user.h"
/*int ajouter(char * filename, user u)
{
    FILE *f = fopen(filename,"a");
    if(f!=NULL)
    { fprintf(f,"%s %s %d %d %s %d %d %d %d %s %d %d\n",u.nom,u.prenom,u.genre,u.role,u.nationalite,u.date.j,u.date.m,u.date.a,u.id,u.mdp,u.ncin,u.vote);
        fclose(f);
        return 1;
    }
    else return 0;
}

int modifier( char * filename, int id, user nouv )
{
    int tr=0;
    user u;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "a");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %s %d %d %s %d %d %d %d %s %d %d\n",u.nom,u.prenom,&u.genre,&u.role,u.nationalite,&u.date.j,&u.date.m,&u.date.a,&u.id,u.mdp,&u.ncin,&u.vote)!=EOF)
        {
            if(u.id== id)
            {
                fprintf(f2,"%s %s %d %d %s %d %d %d %d %s %d %d\n",nouv.nom,nouv.prenom,nouv.genre,nouv.role,nouv.nationalite,nouv.date.j,nouv.date.m,nouv.date.a,nouv.id,nouv.mdp,nouv.ncin,nouv.vote);
		tr=1;
            }
            else
                fprintf(f2,"%s %s %d %d %s %d %d %d %d %s %d %d\n",u.nom,u.prenom,u.genre,u.role,u.nationalite,u.date.j,u.date.m,u.date.a,u.id,u.mdp,u.ncin,u.vote);
        }
    }

    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;
}

int supprimer(char * filename, int id)
{
    int tr=0;
    user u ;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "a");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %s %d %d %s %d %d %d %d %s %d %d\n",u.nom,u.prenom,&u.genre,&u.role,u.nationalite,&u.date.j,&u.date.m,&u.date.a,&u.id,u.mdp,&u.ncin,&u.vote)!=EOF)
        {
            if(u.id== id)
                tr=1;
            else
            fprintf(f2,"%s %s %d %d %s %d %d %d %d %s %d %d\n",u.nom,u.prenom,u.genre,u.role,u.nationalite,u.date.j,u.date.m,u.date.a,u.id,u.mdp,u.ncin,u.vote);
        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;
}
user chercher(char * filename, int id)
{
    user u ;
    int tr=0;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while(tr==0&& fscanf(f,"%s %s %d %d %s %d %d %d %d %s %d %d\n",u.nom,u.prenom,&u.genre,&u.role,u.nationalite,&u.date.j,&u.date.m,&u.date.a,&u.id,u.mdp,&u.ncin,&u.vote)!=EOF)
        {
            if(u.id== id)
                tr=1;
        }
    }
    fclose(f);
    if(tr==0)
        u.id=-1;
    return u ;
}
int nbr_bote_blanc(char*filename)
{
        user u;
        int k=0;
        FILE* f=fopen(filename,"r");
        if(f!=NULL)
	{
        while(fscanf(f,"%s %s %d %d %s %d %d %d %d %s %d %d\n",u.nom,u.prenom,&u.genre,&u.role,u.nationalite,&u.date.j,&u.date.m,&u.date.a,&u.id,u.mdp,&u.ncin,&u.vote)!=EOF)
        {

      if(u.vote==0)
	{
        k++;
	}
        return k;
	}
	}
}
void taux_obser(char *filename)
{ 
user u;
float tn,te;
int nbO,nbn,nbe;
tn=0;
te=0;
FILE *f=fopen(filename, "r");
if(f!=NULL)
{
        while(fscanf(f,"%s %s %d %d %s %d %d %d %d %s %d %d\n",u.nom,u.prenom,&u.genre,&u.role,u.nationalite,&u.date.j,&u.date.m,&u.date.a,&u.id,u.mdp,&u.ncin,&u.vote)!=EOF)
	{
	if(strcmp(u.nationalite,"tunisienne")==0)
		{nbn++;
		}
	else 
	{nbe++;
	}
	}
	nbO=nbn+nbe;	
	tn=(nbn/nbO)*100;
	te=(nbe/nbO)*100;

	printf("\nle taux d'observateur tunisien est %f",tn);
	printf("\nle taux d'observateur etranger est %f \n",te);
}
}*/


