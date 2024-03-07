#define MAX_LUTIN 250
#define MAX_PRENOM 10
#ifndef _TYPE_H_
#define _TYPE_H_
typedef struct {
  int debut;
  int fin;
  int nb_heures;
  int num_ligne;
}horaire;

typedef enum {
	      bricoleur=1,
	      controleur=2,
	      empaqueteur=3
}profession;

typedef struct {
  char prenom[MAX_PRENOM];
  int professions;
  horaire disponibilitees;
  horaire travaille;
}lutin;

typedef struct {
  int ligne;
  lutin employe;
  horaire libre;
}ligne;

#endif
