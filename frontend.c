#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <iso646.h>
#include <windows.h>
#include <conio.h>
#include "biblio.h"

void textcolor(unsigned short color)
{
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hcon,color);
}

void menu(void)
{
    while(1)
    {
    system("CLS");
    textcolor(1);
    printf("\n\n\n\n\n\t\t\t\t<--------------------------------------- Gerer un repertoire telephonique . --------------------------------------->\n\n\n\n\n\n");
    textcolor(15);
    printf("\t\t\t\t......................................................................................................................\n");
    printf("\t\t\t\t:                          :                                 :                         :                             :\n");
    printf("\t\t\t\t:   1- Ajouter une zone    :   2- Afficher tous les zones    :   3- Ouvrir une zone    :    4- clore le programme    :\n");
    printf("\t\t\t\t:                          :                                 :                         :                             :\n");
    printf("\t\t\t\t:..........................:.................................:.........................:.............................:\n");
    textcolor(2);
    int choix;
    printf("\n\n\t\t\t\tVotre Choix (entez nombre) : ");scanf("%d",&choix);getchar();
    switch(choix)
    {
        case 1 : fct_ajouter_zone();
            break;
        case 2 : fct_aff_zones();
            break;
        case 3 : fct_ouvrir_zone();
            break;
        case 4 : clore_porgramme();
            break;
        default : printf("\n\t\t\t\t:(\terreur !! ") ;printf("\n\n\t\t\t\t\t\t\tcontinue . . .");getch(); ; menu();
    }
    }
}

void fct_ajouter_zone(void)
{
    system("CLS");
    printf("\n\t\t\t\t\t\t\t\t\t    Ajouter un nouveau zone : \n\n");
    int code;
    char *nom_zone = (char *)malloc(sizeof(char ));
    printf("\n\t\t\t\t\t\t\t\t\t code de la nouveau zone : ");scanf("%d",&code);
    printf("\n\t\t\t\t\t\t\t\t\t nom de la zone : ");scanf("%s",nom_zone);
    Ajouter_zone(code,nom_zone);
    printf("\n\n\t\t\t\t\t\t\tcontinue . . .");getch();
}

void fct_aff_zones()
{
    Repertoire_telephone *aux_var = liste_pays;           //varivable auxiliaire.
    system("CLS");
    printf("\n\t\t\t\t\t\t\t\t\t    Tous les Zones : \n\n");
    int i=1;
    while(aux_var!=NULL)
    {
        printf("\n\t\t\t\t\t\t\t\t\t\t Zone %d : \n",i++);
        printf("\t\t\t\t\t\t\t\t __________________|\n");
        printf("\t\t\t\t\t\t\t\t|         Code de la zone :      %d         \n",aux_var->code);
        printf("\t\t\t\t\t\t\t\t|         Nom de la zone  :      %s         \n",aux_var->nom_zone);
        printf("\t\t\t\t\t\t\t\t|         Nombre d\'abonnees :   %d         \n",aux_var->nb_abonnes);
        printf("\t\t\t\t\t\t\t\t|_________________________________________/\n");
        aux_var=aux_var->suivant;
    }
    printf("\n\n\t\t\t\t\t\t\tcontinue . . .");getch();
}

void fct_ouvrir_zone(void)
{
    system("CLS");
    Repertoire_telephone *aux_var = liste_pays;           //varivable auxiliaire.
    int code_zone;
    printf("\n\t\t\t\t\t\t\t\t\t\t Ouvrir un zone :\n\n");
    printf("\n\t\t\t\t\t\t\t\t\t Enterz le code de la zone :");scanf("%d",&code_zone);getchar();
    while(aux_var!=NULL && aux_var->code != code_zone)
    {
        aux_var=aux_var->suivant;
    }
    if (aux_var!=NULL)
    {
        while(1)
        {
        system("CLS");
        textcolor(3);
        printf("\t\t\t\t<--------------------------------------- Gerer le zone : %s . --------------------------------------->\n\n\n",aux_var->nom_zone);
        textcolor(6);
        printf("\t................................................................................................................................................................\n");
        printf("\t:  1- Ajouter un Abonne  :  2- Trouver un abonne  :  3- Enlever un abonne  :  4- Enlever ce zone  :  5- Afficher tous les abonnes  :  6- clore zone            :\n");
        printf("\t:........................:........................:........................:......................:................................:...........................:\n");
        textcolor(2);
        int choix;
        char *nom_abonne=(char *)malloc(sizeof(char ));
        int num_tel;
        printf("\n\n\t\t\t\tVotre Choix (entez nombre) : ");scanf("%d",&choix);getchar();
        switch(choix)
        {
            case 1 : fct_ajouter_abonne(aux_var->code);
                break;
            case 2 : 
                    printf("\n\n\t\t\t\tEntrez le nom d'abonne : ");scanf("%s",nom_abonne);getchar();
                    if (Enregistrer_abonne(nom_abonne, aux_var->code) == -1)
                        printf("\n\n\t\t\t\tIl n'execte pas un abonne avec ce nom !\n ");
                    else
                        printf("\n\n\t\t\t\tSont numero de telephone est : %d .\n ",Enregistrer_abonne(nom_abonne,aux_var->code));
                    printf("\n\n\t\t\t\t\t\t\tcontinue . . .");getch();
                break;
            case 3 : 
                printf("\n\n\t\t\t\tEntrez numero de telephone de l'abonne : ");scanf("%d",&num_tel);getchar();
                if (Enlever_abonne(num_tel) == 1)
                    printf("\n\n\t\t\t\t L\'operation a ete bien effectuer \n");
                else
                    printf("\n\n\t\t\t\t Erreur ! \n");
                printf("\n\n\t\t\t\t\t\t\tcontinue . . .");getch();
                break;
            case 4 : Enlever_zone(aux_var->code);menu();
                break;
            case 5 : fct_Afficher_tous_abonnes(aux_var->code);printf("\n\n\t\t\t\t\t\t\tcontinue . . .");getch();
                break;
            case 6 : menu();
            default : printf("\n\t\t\t\t:(\terreur !! ") ; printf("\n\n\t\t\t\t\t\t\tcontinue . . .");getch(); menu();
        }   
        }
    }
}

void fct_ajouter_abonne(int code_zone_zone)
{
    int code__zone;
    printf("Entrez le code de la zone:");scanf("%d",&code__zone);getchar();
    if(code__zone == code_zone_zone)
    {
        printf("Entrez nombre des abonnees a ajouter:\n");
        int nbr_abonne;
        int num_tel;
        char *nom_abonne=malloc(sizeof(*nom_abonne));
        char *adresse = malloc(sizeof(*adresse));
        printf("nombre d\'abonnees = ");scanf("%d",&nbr_abonne);getchar();
        for (int i=0;i<nbr_abonne ; i++)
        {
            printf("Abonner %d :\n",i+1);
            printf("numero de telephone :");scanf("%d",&num_tel);getchar();
            printf("nom de l\'abonne : ");scanf("%s",nom_abonne);getchar();
            printf("adresse : ");scanf("%s",adresse);getchar();
            Ajouter_abonne(num_tel,nom_abonne,adresse,code__zone);
        }
    }
    else
        printf("\n\t\t\t\t\t\t\t\t\t   erreur 1!: ");
}

void fct_Afficher_tous_abonnes(int code_zone)
{
    Repertoire_telephone *aux_var = liste_pays;           //varivable auxiliaire.
    while(aux_var->code != code_zone)
    {
        aux_var=aux_var->suivant;
    }
    system("CLS");
    system("CLS");
    textcolor(3);
    printf("\t\t\t\t<--------------------------------------- Les abonnees de le zone : %s . --------------------------------------->\n\n\n",aux_var->nom_zone);
    int i=1;
    if (aux_var->debut_abonne != NULL)
    {
        textcolor(4);
        printf("\n\t\t\t\t\t\t\t\t\t    Abonne %d : ",i++);
        textcolor(3);
        printf("\n\t\t\t\t\t\t\t ______________________| ");
        printf("\n\t\t\t\t\t\t\t|\tNumero de telephone : %d ",aux_var->debut_abonne->num_tel);
        printf("\n\t\t\t\t\t\t\t|\tNom de la bonne : %s ",aux_var->debut_abonne->nom_abonne);
        printf("\n\t\t\t\t\t\t\t|\tAdresse de la bonne : %s ",aux_var->debut_abonne->adresse);
        textcolor(4);
        printf("\n\t\t\t\t\t\t\t|____________________________________________________________");
        printf("\n\t\t\t\t\t\t\t                                                             |");
        Abonne *aux_abonne = aux_var->fin_abonne;
        while(aux_abonne != NULL)
        {
            printf("\n\t\t\t\t\t\t\t\t\t    Abonne %d : ______________________________|",i++);
            textcolor(3);
            printf("\n\t\t\t\t\t\t\t ______________________|");
            printf("\n\t\t\t\t\t\t\t|\tNumero de telephone : %d ",aux_abonne->num_tel);
            printf("\n\t\t\t\t\t\t\t|\tNom de la bonne : %s ",aux_abonne->nom_abonne);
            printf("\n\t\t\t\t\t\t\t|\tAdresse de la bonne : %s ",aux_abonne->adresse);
            textcolor(4);
            printf("\n\t\t\t\t\t\t\t|____________________________________________________________");
            printf("\n\t\t\t\t\t\t\t                                                             |");
            aux_abonne=aux_abonne->precedent;
        }
        printf("\n\t\t\t\t\t\t\t                                                             fin\n");
        textcolor(15);
    }
}

void clore_porgramme(void)
{
    while(liste_pays!=NULL)
    {
        while(liste_pays->debut_abonne != NULL)
            Enlever_abonne(liste_pays->debut_abonne->num_tel);
        Enlever_zone(liste_pays->code);
    }
    printf("\n\n\t\t\t\t\t\t\tcontinue . . .");getch();
    system("CLS");
    exit(1);

}






