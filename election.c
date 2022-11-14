#include "election.h"

int ajouter(char * filename, election e )
{
    FILE * f=fopen(filename, "a");
    if(f!=NULL)
    {
        fprintf(f,"%d %s %d %d %d %d %d \n",e.id,e.Muni,e.nbrh,e.nbrc,e.d.j,e.d.m,e.d.a);
        fclose(f);
        return 1;
    }
    else return 0;
}
int modifier( char * filename, int iden, election new )
{
    int tr=0;
    election e ;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("new.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%d %s %d %d %d %d %d ",&e.id,e.Muni,&e.nbrh,&e.nbrc,&e.d.j,&e.d.m,&e.d.a)!=EOF)
        {
            if(e.id== iden)
            {
                fprintf(f2,"%d %s %d %d %d %d %d \n",new.id,new.Muni,new.nbrh,new.nbrc,new.d.j,new.d.m,new.d.a);
                tr=1;
            }
            else
                fprintf(f2,"%d %s %d %d %d %d %d \n",e.id,e.Muni,e.nbrh,e.nbrc,e.d.j,e.d.m,e.d.a);

        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("new.txt", filename);
    return tr;

}
int supprimer(char * filename, int iden)
{
    int tr=0;
    election e ;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("new.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%d %s %d %d %d %d %d ",&e.id,e.Muni,&e.nbrh,&e.nbrc,&e.d.j,&e.d.m,&e.d.a)!=EOF)
        {
            if(e.id== iden)
                tr=1;
            else
                fprintf(f2,"%d %s %d %d %d %d %d \n",e.id,e.Muni,e.nbrh,e.nbrc,e.d.j,e.d.m,e.d.a);
        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("new.txt", filename);
    return tr;
}
election chercher(char * filename, int iden)
{
    election e;
    int tr;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while(tr==0&& fscanf(f,"%d %s %d %d %d %d %d ",&e.id,e.Muni,&e.nbrh,&e.nbrc,&e.d.j,&e.d.m,&e.d.a)!=EOF)
        {
            if(e.id== iden)
                tr=1;
        }
    }
    fclose(f);
    if(tr==0)
        e.id=-1;
    return e;

}

