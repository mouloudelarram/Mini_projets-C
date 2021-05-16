#ifndef H_FILE
#define H_FILE


/*si vous utilise la competateur GNU (code::blocks) essaye de desactiver l'instruction 
 #include "fonction.c" par un commentaire comme suit  //#include "fonction.c" . */

/* ce programme develope utilisant Visual Studio Code avec le compelateur gcc .*/

//structure des abonnées:
typedef struct ElementAbonne{
    int num_tel ;           //numéro de télépone
    char *nom_abonne ;      //le nom de l'abonné
    char *adresse ;         //adresse de l'abonné
    struct ElementAbonne *precedent ;
    struct ElementAbonne *suivant;

}Abonne;


//structure des zone:
typedef struct Zone{
    int code ;              //code de la zone
    char *nom_zone ;        //nom de la zone
    Abonne *debut_abonne ;
    Abonne *fin_abonne ;
    int nb_abonnes ;
    struct Zone *suivant;

}Repertoire_telephone;


//tous les fonction de fontend utilise :
void textcolor(unsigned short color);
void menu(void);
void fct_ajouter_zone(void);
void fct_aff_zones();
void fct_ouvrir_zone(void);
void fct_ajouter_abonne(int code_zone_zone);
void fct_Afficher_tous_abonnes(int code_zone);
void clore_porgramme(void);


//tous les fonction de bachend utilise :
Repertoire_telephone *create_zone(int code , char *nom_zone );
int Ajouter_zone(int code_zone , char *nom_zone);
Abonne *create_abonne(int num_tel , char *nom_abonne , char *adresse);
int Ajouter_abonne(int num_tel, char *nom_abonne, char *adresse, int code_zone);
int Enregistrer_abonne(char *nom, int code_zone);
//supprission au debut:
int enlever_abonne_debut(int numero);
//supprission a la fin:
int enlever_abonne_fin(int numero);
//supprission au milieu:
int enlever_abonne_milieu(int numero);
//la fonction globale de la supprission.
int Enlever_abonne(int numero);
int Enlever_zone(int code_zone) ;


//Le variable globale.
Repertoire_telephone *liste_pays=NULL;                    //liste des pays .


#include "backend.c"
#include "frontend.c"
#endif