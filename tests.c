#include<stdio.h>
#include<stdlib.h>
#include "type.h"

char* genererNomAleatoire() {
  char caracteres[] = "abcdefghijklmnopqrstuvwxyz";
  int taille_max = 10;
  int lettre;
  int taille = (rand() % (taille_max - 1) + 1)+1;
  char *nom= NULL;
  int i;
  nom = (char*) malloc (taille_max*sizeof(char));
  if (nom == NULL) {
    fprintf(stderr, "Erreur d'allocation mémoire.\n");
    exit(EXIT_FAILURE);
  }
  for (i = 0; i < taille; i++) {
    lettre = rand() % (26-1) + 1;
    nom[i] = caracteres[lettre];
  }
  nom[i] = '\0';
  return nom;
}

int genererProffessionAleatoire(){
  return rand() % 3 + 1;
}

int genererHoraireAleatoire() {
  int min = 6;
  int max = 20;
  return rand() % (max - min + 1) + min;
}

int sauve(int nombre){
  FILE* fichier = NULL;
  int i;
  
  fichier = fopen("fichier_test.txt", "w");
  
  if(fichier==NULL){
    printf("Impossible d'ouvrir le fichier\n");
    exit(EXIT_FAILURE);
  }
  fprintf(fichier,"%d\n",nombre);
  for(i=0; i < nombre; i++){

    fprintf(fichier,"%s %d %d %d\n",genererNomAleatoire(), genererProffessionAleatoire(),genererHoraireAleatoire(),genererHoraireAleatoire());
  }
  
  
  fclose(fichier);
  return 0;
}


int recup( lutin * lutins){
  FILE* fichier = NULL;
  int i,j;
  fichier = fopen("fichier_test.txt", "r");
  
  if(fichier==NULL){
    fprintf(stderr,"Impossible d'ouvrir le fichier\n");
    exit(EXIT_FAILURE);
  }
  
  if(fscanf(fichier,"%d",&i)!=1){
    fprintf(stderr,"erreur de chargement\n");
    exit(EXIT_FAILURE);
  }
  for(j=0; j<i; j++){
    if(fscanf(fichier,"%s %d %d %d",lutins[j].prenom, &lutins[j].professions , &lutins[j].disponibilitees.debut,&lutins[j].disponibilitees.fin)!=4){
      fprintf(stderr,"pb de chargement\n");
      exit(EXIT_FAILURE);
    }
  }
  return 0;
}


void corrigerHoraires(lutin *lutins, int nombreLutins) {
  int temp,i;
    for (i = 0; i < nombreLutins; i++) {
        if (lutins[i].disponibilitees.debut > lutins[i].disponibilitees.fin) {
	  /*les horaires ne sont pas dans le bon ordre, les échanger */
            temp = lutins[i].disponibilitees.debut;
            lutins[i].disponibilitees.debut = lutins[i].disponibilitees.fin;
            lutins[i].disponibilitees.fin = temp;
        }
    }
}

void initialiserLutins(lutin **lutins, int nombreLutins) {
    *lutins = malloc(sizeof(lutin) * nombreLutins);
    if (*lutins == NULL) {
        fprintf(stderr, "Erreur d'allocation mémoire\n");
        exit(EXIT_FAILURE);
    }
}

void libererMemoire(lutin *lutins) {
    free(lutins);
}


