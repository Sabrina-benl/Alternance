#include <stdio.h>
#include <stdlib.h>
#include <MLV/MLV_all.h>

#define MAX_WORKERS 3
#define MAX_HOUR 15

/* Définition des heures de travail (6h à 20h)*/
#define HEURE_DEBUT 6
#define HEURE_FIN 20
#define NB_HEURES (HEURE_FIN - HEURE_DEBUT + 1)

/* Dimensions de la grille*/
#define LARGEUR_CELLULE (LARGEUR_FENETRE / MAX_WORKERS)
#define HAUTEUR_CELLULE (HAUTEUR_FENETRE / (NB_HEURES + 1))

/* Couleurs*/
#define COULEUR_FOND MLV_COLOR_WHITE
#define COULEUR_GRILLE MLV_COLOR_BLACK
#define COULEUR_TEXTE MLV_COLOR_BLACK

void dessiner_grille_ligne(int LARGEUR_FENETRE, int HAUTEUR_FENETRE) {
    int i,x,y;
    /*Dessine la grille*/
    for (i = 0; i <= MAX_WORKERS; ++i) {
        x = i * LARGEUR_CELLULE;
        MLV_draw_line(x, 0, x, HAUTEUR_FENETRE, COULEUR_GRILLE);
    }
    for (i = 0; i <= NB_HEURES; ++i) {
        y = i * HAUTEUR_CELLULE;
        MLV_draw_line(0, y, LARGEUR_FENETRE, y, COULEUR_GRILLE);
    }
}

void afficher_planning_ligne(int LARGEUR_FENETRE, int HAUTEUR_FENETRE) {
    int i,x,y;
    char* workers[] = {"Bricoleur", "Empacteur", "Contrôleur"};
    MLV_clear_window(COULEUR_FOND);
    dessiner_grille_ligne(LARGEUR_FENETRE, HAUTEUR_FENETRE);
    /* Affiche les heures*/
    for (i = HEURE_DEBUT; i <= HEURE_FIN; ++i) {
        y = (i - HEURE_DEBUT) * HAUTEUR_CELLULE;
        MLV_draw_text(5, y + 5, "%dh", COULEUR_TEXTE, i);
    }
    /* Affiche les noms des travailleurs*/
    for (i = 0; i < MAX_WORKERS; ++i) {
        x = (i + 1) * LARGEUR_CELLULE;
        MLV_draw_text(x + 5, 5, "%s", COULEUR_TEXTE, workers[i]);
    }
    MLV_actualise_window();
}
