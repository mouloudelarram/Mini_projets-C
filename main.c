#include <stdlib.h>
#include "biblio.h"


int main()
{  
    menu();
    return EXIT_SUCCESS;
}

















































































































































/*Ajouter_zone(5,"abcd5");
    Ajouter_zone(10,"abcd10");
    Ajouter_zone(15,"abcd15");
    Ajouter_zone(20,"abcd20");
    Ajouter_zone(25,"abcd000000000000000025");
    Ajouter_zone(30,"abcd30");
    Ajouter_abonne(100, "mouloud", "myadresse", 5);
    Ajouter_abonne(200, "mnhfhgfg", "myadresse", 5);
    Ajouter_abonne(300, "mouloud", "mfdrrewse", 5);
    Ajouter_abonne(400, "mouloud", "myadresse", 5);
    Ajouter_abonne(500, "457987ud", "myadresse", 5);
    Ajouter_abonne(600, "mouloud", "myadresse", 5);
    Ajouter_abonne(700, "moulud", "mzaaaaaaaaase", 5);
    Ajouter_abonne(800, "mouloud", "myadresse", 5);
    Ajouter_abonne(900, "mouloud", "myadresse", 5);

    //fct_Afficher_tous_abonnes(5);
    
    //liste_pays = initialise_liste(liste_pays );
  /*

    Enlever_abonne(2500);
    Enlever_abonne(200); 
    Enlever_abonne(300); 
    Enlever_abonne(400); 
    Enlever_abonne(500); 
    Enlever_abonne(600); 
    Enlever_abonne(700); 
    Enlever_abonne(800); 
    Enlever_abonne(900); 
    Enlever_abonne(1000); 
    Enlever_abonne(100);


    Enlever_zone(10);
    Enlever_zone(5);
    Enlever_zone(5);
    Enlever_zone(20);
    Enlever_zone(25);
    Enlever_zone(30);
    Enlever_zone(154);
    Enlever_zone(200);/
    fct_ajouter_zone();
    fct_ajouter_abonne();
    while(liste_pays!=NULL)
    {
        printf(" code =%d\tnom=%s \t nbr_abonne=%d \n",liste_pays->code ,liste_pays->nom_zone , liste_pays->nb_abonnes);
        while(liste_pays->debut_abonne!=NULL)
        {
            printf("-->num=%d \t nom=%s \t adesse=%s\n",liste_pays->debut_abonne->num_tel,liste_pays->debut_abonne->nom_abonne,liste_pays->debut_abonne->adresse);
            while(liste_pays->fin_abonne!=NULL)
            {
                printf("-->num=%d \t nom=%s \t adesse=%s\n",liste_pays->fin_abonne->num_tel,liste_pays->fin_abonne->nom_abonne,liste_pays->fin_abonne->adresse);
                liste_pays->fin_abonne=liste_pays->fin_abonne->precedent;
            }
            liste_pays->debut_abonne=liste_pays->debut_abonne->suivant;
        }
        liste_pays=liste_pays->suivant;
    }
    printf("\n%d\n",    Enregistrer_abonne("moulud",5) );

   /* printf("%d\t%s\n",liste_pays->code , liste_pays->nom_zone);
    printf("%d\t%s\n",(liste_pays->suivant)->code , (liste_pays->suivant)->nom_zone);
    printf("%d\t%s\n",((liste_pays->suivant)->suivant)->code , ((liste_pays->suivant)->suivant)->nom_zone);
    //fct();
    //printf("%d\n",liste_pays->code);*/