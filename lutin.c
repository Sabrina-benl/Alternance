#include <stdio.h>
#include <stdlib.h>
#include <MLV/MLV_all.h>

#define MAX_DAYS 7
#define MAX_HOUR 24

/* Définition des heures de travail (0h à 24h)*/
#define HEURE_DEBUT 0
#define HEURE_FIN 24
#define NB_HEURES (HEURE_FIN - HEURE_DEBUT + 1)

/* Dimensions de la grille*/
#define LARGEUR_CELLULE (LARGEUR_FENETRE / MAX_DAYS)
#define HAUTEUR_CELLULE (HAUTEUR_FENETRE / (NB_HEURES + 1))

/* Couleurs*/
#define COULEUR_FOND MLV_COLOR_WHITE
#define COULEUR_GRILLE MLV_COLOR_BLACK
#define COULEUR_TEXTE MLV_COLOR_BLACK

void dessiner_grille(int LARGEUR_FENETRE, int HAUTEUR_FENETRE) {
    int i,x,y;
    /*Dessine la grille*/
    for (i = 0; i <= MAX_DAYS; ++i) {
        x = i * LARGEUR_CELLULE;
        MLV_draw_line(x, 0, x, HAUTEUR_FENETRE, COULEUR_GRILLE);
    }
    for (i = 0; i <= NB_HEURES; ++i) {
        y = i * HAUTEUR_CELLULE;
        MLV_draw_line(0, y, LARGEUR_FENETRE, y, COULEUR_GRILLE);
    }
}

void afficher_planning(int LARGEUR_FENETRE, int HAUTEUR_FENETRE) {
    int i,x,y;
    char* days[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    MLV_clear_window(COULEUR_FOND);
    dessiner_grille(LARGEUR_FENETRE, HAUTEUR_FENETRE);
    /* Affiche les heures*/
    for (i = HEURE_DEBUT; i <= HEURE_FIN; ++i) {
        y = (i - HEURE_DEBUT) * HAUTEUR_CELLULE;
        MLV_draw_text(5, y + 5, "%dh", COULEUR_TEXTE, i);
    }
    /* Affiche les noms des jours*/
    for (i = 0; i < MAX_DAYS; ++i) {
        x = (i + 1) * LARGEUR_CELLULE;
        MLV_draw_text(x + 5, 5, "%s", COULEUR_TEXTE, days[i]);
    }
    MLV_actualise_window();
}



/*
#include <stdio.h>
#include <stdlib.h>
#include <MLV/MLV_all.h>

#define MAX_DAYS 7
#define MAX_HOUR 24

 Définition des heures de travail (0h à 24h)
#define HEURE_DEBUT 0
#define HEURE_FIN 24
#define NB_HEURES (HEURE_FIN - HEURE_DEBUT + 1)

 Dimensions de la grille
#define LARGEUR_CELLULE (LARGEUR_FENETRE / MAX_DAYS)
#define HAUTEUR_CELLULE (HAUTEUR_FENETRE / (NB_HEURES + 1))

 Couleurs
#define COULEUR_FOND MLV_COLOR_WHITE
#define COULEUR_GRILLE MLV_COLOR_BLACK
#define COULEUR_TEXTE MLV_COLOR_BLACK

void dessiner_grille(int LARGEUR_FENETRE, int HAUTEUR_FENETRE) {
    int i,x,y;
    Dessine la grille
    for (i = 0; i <= MAX_DAYS; ++i) {
        x = i * LARGEUR_CELLULE;
        MLV_draw_line(x, 0, x, HAUTEUR_FENETRE, COULEUR_GRILLE);
    }
    for (i = 0; i <= NB_HEURES; ++i) {
        y = i * HAUTEUR_CELLULE;
        MLV_draw_line(0, y, LARGEUR_FENETRE, y, COULEUR_GRILLE);
    }
}

void afficher_planning(int LARGEUR_FENETRE, int HAUTEUR_FENETRE) {
    int i,x,y;
    char* days[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    MLV_clear_window(COULEUR_FOND);
    dessiner_grille(LARGEUR_FENETRE, HAUTEUR_FENETRE);
     Affiche les heures
    for (i = HEURE_DEBUT; i <= HEURE_FIN; ++i) {
        y = (i - HEURE_DEBUT) * HAUTEUR_CELLULE;
        MLV_draw_text(5, y + 5, "%dh", COULEUR_TEXTE, i);
    }
     Affiche les noms des jours
    for (i = 0; i < MAX_DAYS; ++i) {
        x = (i + 1) * LARGEUR_CELLULE;
        MLV_draw_text(x + 5, 5, "%s", COULEUR_TEXTE, days[i]);
    }
    MLV_actualise_window();
}

*/


/*

#include <stdio.h>
#include <stdlib.h>
#include <MLV/MLV_all.h>

#define MAX_LUTIN 250
#define MAX_PRENOM 10

 Définition des heures de travail (6h à 20h)
#define HEURE_DEBUT 6
#define HEURE_FIN 20
#define NB_HEURES (HEURE_FIN - HEURE_DEBUT + 1)

Dimensions de la grille
#define LARGEUR_CELLULE (LARGEUR_FENETRE / NB_HEURES)
#define HAUTEUR_CELLULE (HAUTEUR_FENETRE / (MAX_LUTIN + 1))

Couleurs
#define COULEUR_FOND MLV_COLOR_WHITE
#define COULEUR_GRILLE MLV_COLOR_BLACK
#define COULEUR_TEXTE MLV_COLOR_BLACK

void dessiner_grille(int LARGEUR_FENETRE, int HAUTEUR_FENETRE) {
    int i,x,y;
    Dessine la grille
    for (i = 0; i <= NB_HEURES; ++i) {
         x = i * LARGEUR_CELLULE;
        MLV_draw_line(x, 0, x, HAUTEUR_FENETRE, COULEUR_GRILLE);
    }
    for (i = 0; i <= MAX_LUTIN; ++i) {
        y = i * HAUTEUR_CELLULE;
        MLV_draw_line(0, y, LARGEUR_FENETRE, y, COULEUR_GRILLE);
    }
}

void afficher_planning(int LARGEUR_FENETRE, int HAUTEUR_FENETRE) {
    int i,x,y;
    MLV_clear_window(COULEUR_FOND);
    dessiner_grille(LARGEUR_FENETRE, HAUTEUR_FENETRE);
    Affiche les heures
    for (i = HEURE_DEBUT; i <= HEURE_FIN; ++i) {
        x = (i - HEURE_DEBUT) * LARGEUR_CELLULE;
        MLV_draw_text(x + 5, 5, "%dh", COULEUR_TEXTE, i);
    }
    Affiche les noms des lutins
    for (i = 0; i < MAX_LUTIN; ++i) {
        y = (i + 1) * HAUTEUR_CELLULE;
        MLV_draw_text(5, y + 5, "%s", COULEUR_TEXTE, "Lutin");
    }
    MLV_actualise_window();
}
*/