#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <iso646.h>
#include "biblio.h"

Repertoire_telephone *create_zone(int code , char *nom_zone )
{
    Repertoire_telephone *Zone = (Repertoire_telephone *)malloc(sizeof(Repertoire_telephone));
    Zone->code = code;
    Zone->nom_zone=(char*)malloc(sizeof(char));
    strcpy(Zone->nom_zone,nom_zone);
    Zone->nom_zone = nom_zone;
    Zone->debut_abonne = Zone->fin_abonne = NULL;
    Zone->nb_abonnes = 0;
    Zone->suivant = NULL;
    return Zone;
}

int Ajouter_zone(int code_zone , char *nom_zone)
{
    if (liste_pays == NULL)
    {
        liste_pays = create_zone(code_zone , nom_zone);
        //teste si l'operation est bien effectuer.
        if (liste_pays == NULL)
            return -1;
        else
            return 1;
    }
    else
    {
        Repertoire_telephone *new_zone=create_zone(code_zone,nom_zone);
        Repertoire_telephone *aux_var = liste_pays;     //variable auxiliaire.
        while(aux_var->suivant != NULL)
        {
            aux_var=aux_var->suivant;
        }
        aux_var->suivant=new_zone;
        //teste si l'operation est bien effectuer.
        if (aux_var->suivant == NULL)
            return -1;
        else
            return 1;
    }
}

Abonne *create_abonne(int num_tel , char *nom_abonne , char *adresse)
{
    Abonne *abonne = malloc(sizeof(*abonne));
    abonne->num_tel=num_tel;
    abonne->nom_abonne=(char*)malloc(sizeof(char));
    strcpy(abonne->nom_abonne,nom_abonne);
    //abonne->nom_abonne=nom_abonne;
    abonne->adresse=(char*)malloc(sizeof(char));
    strcpy(abonne->adresse,adresse);
    //abonne->adresse=adresse;
    abonne->precedent = abonne->suivant = NULL;
    return abonne;
}

int Ajouter_abonne(int num_tel, char *nom_abonne, char *adresse, int code_zone)
{
    Repertoire_telephone *aux_var = liste_pays;
    Abonne *new_abonne = create_abonne(num_tel , nom_abonne , adresse);
    while(aux_var->code != code_zone)
    {
        aux_var=aux_var->suivant;
    }
    if (aux_var->debut_abonne == NULL)
    {
        aux_var->debut_abonne = new_abonne;

        if (aux_var->debut_abonne==NULL)
            return -1;
        else
        {
            aux_var->nb_abonnes++;
            return 1;
        }
    }
    else
    {
        if (aux_var->fin_abonne == NULL)
        {
            aux_var->fin_abonne = new_abonne;

            if (aux_var->fin_abonne==NULL)
                return -1;
            else
            {
                aux_var->nb_abonnes++;
                return 1;
            }
        }
        else
        {
            Abonne *aux_abonne = aux_var->fin_abonne;
            while(aux_abonne->suivant != NULL)
            {
                aux_abonne=aux_abonne->suivant;
            }
            aux_abonne->suivant = new_abonne;
            new_abonne->precedent = aux_abonne;
            
            if (aux_abonne->suivant==NULL)
                return -1;
            else
            {
                aux_var->fin_abonne=new_abonne;
                aux_var->nb_abonnes++;
                return 1;
            }
        }
    }
}

int Enregistrer_abonne(char *nom, int code_zone) 
{
    Repertoire_telephone *aux_var = liste_pays;

    //trouver la zone .
    while(aux_var != NULL and aux_var->code != code_zone )
    {
        aux_var=aux_var->suivant;
    }
    //tester tous les abonnées.
    for(int i=0 ; aux_var !=NULL and i<aux_var->nb_abonnes and aux_var->debut_abonne!=NULL  ; i++)
    {
        if (strcmp(nom , (aux_var->debut_abonne)->nom_abonne)==0 )
        {
            return aux_var->debut_abonne->num_tel;
        }
        else if (strcmp(nom , (aux_var->fin_abonne)->nom_abonne)==0)
        {
            return aux_var->fin_abonne->num_tel;
        }
        aux_var->fin_abonne=aux_var->fin_abonne->precedent;
    } 

    return -1;
}

//supprission au debut:
int enlever_abonne_debut(int numero)
{
    
    Repertoire_telephone *aux_var = liste_pays;         //varivable zone auxiliaire.
    //teste si le debut de l'arbre et non vide.
    if (aux_var->debut_abonne!=NULL)
    {
        Abonne *aux_abonne = aux_var->debut_abonne;
        aux_var->debut_abonne=aux_var->fin_abonne;
        
        if (aux_var->fin_abonne!=NULL)
        {
            Abonne *aux_abonne_2 = aux_var->fin_abonne;
            aux_var->fin_abonne=aux_var->fin_abonne->precedent;
            if (aux_abonne_2->precedent!=NULL)
                aux_var->fin_abonne->suivant=NULL;
            //free(aux_abonne_2);
        }
        free(aux_abonne);
        
        return 1;
    }
    return -1;
}
//supprission a la fin:
int enlever_abonne_fin(int numero)
{
    Repertoire_telephone *aux_var = liste_pays;       //varivable auxiliaire.
    //enlever dans la fin de la "fin donne"colonne .
    if(aux_var->fin_abonne != NULL and aux_var->fin_abonne->num_tel == numero)
    {
        Abonne *aux_abonne = aux_var->fin_abonne;
        
        aux_var->fin_abonne=aux_var->fin_abonne->precedent;
        if (aux_var->fin_abonne!=NULL)
            aux_var->fin_abonne->suivant=NULL;
        free(aux_abonne);
        return 1;
    }
    return -1;
}
//supprission au milieu:
int enlever_abonne_milieu(int numero)
{
    Repertoire_telephone *aux_var = liste_pays;       //varivable auxiliaire.
    Abonne *aux_abonne = aux_var->fin_abonne;
    
    while(aux_abonne != NULL and aux_abonne->num_tel!=numero)
    {
        aux_abonne=aux_abonne->precedent;
    }
    
    if (aux_abonne!=NULL)
    {
        Abonne *aux_abonne_retire = aux_abonne;
        if (aux_abonne->precedent!=NULL)
            aux_abonne->precedent->suivant=aux_abonne_retire->suivant;
        aux_abonne->suivant->precedent=aux_abonne_retire->precedent;
        free(aux_abonne_retire);
        return 1;
    }
    return -1;
}
//la fonction globale de la supprission.
int Enlever_abonne(int numero) 
{
    Repertoire_telephone *aux_var = liste_pays;           //varivable auxiliaire.
    //enlever dans le debut de le "debut donne" colonne .
    if (aux_var->debut_abonne->num_tel == numero)
        return enlever_abonne_debut(numero);

    //enlever dans la fin de la "fin donne" colonne .
    else if(aux_var->fin_abonne->num_tel == numero)
        return enlever_abonne_fin(numero);

    //enlever au milieu de la "fin donne" colonne .
    else
        return enlever_abonne_milieu(numero);
}

int Enlever_zone(int code_zone) 
{
    //enlever zone au debut;
    if (liste_pays->code==code_zone)
    {
        Abonne *aux_abonne=liste_pays->debut_abonne;
        while(liste_pays->debut_abonne!=NULL)
        {
            free(aux_abonne);
            enlever_abonne_debut(liste_pays->debut_abonne->num_tel);
        }
        Repertoire_telephone *aux_var_zone_retire = liste_pays;           //varivable auxiliaire.
        liste_pays=liste_pays->suivant;
        free(aux_var_zone_retire);
        return 1;
    }
    //enlever zone au milieu au a la fin.
    else
    {
        Repertoire_telephone *aux_var = liste_pays;           //varivable auxiliaire.
        while(aux_var->suivant!=NULL)
        {
            if (aux_var->suivant->code==code_zone)
            {
                Abonne *aux_abonne=aux_var->suivant->debut_abonne;
                while(aux_var->suivant->debut_abonne!=NULL)
                {
                    free(aux_abonne);
                    enlever_abonne_debut(aux_var->suivant->debut_abonne->num_tel);
                }
                Repertoire_telephone *aux_var_zone_retire = aux_var->suivant;           //varivable auxiliaire.
                aux_var->suivant=aux_var->suivant->suivant;
                    free(aux_var_zone_retire);
                return 1;
            }
            else
                aux_var=aux_var->suivant;
        }
    }
    return -1;
}