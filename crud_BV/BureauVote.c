#include "BureauVote.h"

int ajouter(char *filename, bv bv1)
{
    FILE * f=fopen(filename, "a");
    if(f!=NULL)
    {
        fprintf(f,"%d %d %d %d %s  \n",bv1.idbureau,bv1.capaciteelectoral,bv1.capaciteobservateur,bv1.idagent,bv1.adresse);
        fclose(f);
        return 1;
    }
    else return 0;
}
int modifier( char *filename, int idbureau,bv bv1 )
{
    int tr=0;
    bv bv3 ;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("bv2.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%d %d %d %d %s  \n",&bv1.idbureau,&bv1.capaciteelectoral,&bv1.capaciteobservateur,&bv1.idagent,bv1.adresse)!=EOF)
        {
            if(bv1.idbureau==idbureau)
            
               { fprintf(f,"%d %d %d %d %s  \n",bv1.idbureau,bv1.capaciteelectoral,bv1.capaciteobservateur,bv1.idagent,bv1.adresse);
                tr=1;}
            
            else
                fprintf(f,"%d %d %d %d %s  \n",bv1.idbureau,bv1.capaciteelectoral,bv1.capaciteobservateur,bv1.idagent,bv1.adresse);

        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("bv2.txt", filename);
    return tr;

}
int supprimer(char * filename, int idbureau)
{
    int tr=0;
    bv bv1 ;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("bv2.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%d %d %d %d %s  \n",&bv1.idbureau,&bv1.capaciteelectoral,&bv1.capaciteobservateur,&bv1.idagent,bv1.adresse)!=EOF)
        {
            if(bv1.idbureau==idbureau)
                tr=1;
            else
                fprintf(f,"%d %d %d %d %s  \n",bv1.idbureau,bv1.capaciteelectoral,bv1.capaciteobservateur,bv1.idagent,bv1.adresse);
        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("bv2.txt", filename);
    return tr;
}
bv chercher(char *filename, int idbureau)
{
    bv bv1;
    int tr;
    FILE *f=fopen(filename, "r");
    if(f!=NULL)
    {
        while(tr==0&& fscanf(f,"%d %d %d %d %s  \n",&bv1.idbureau,&bv1.capaciteelectoral,&bv1.capaciteobservateur,&bv1.idagent,bv1.adresse)!=EOF)
        {
            if(bv1.idbureau== idbureau)
                tr=1;
        }
    }
    fclose(f);
    if(tr==0)
        bv1.idbureau=-1;
    return bv1;

}
