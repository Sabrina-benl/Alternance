#include <stdio.h>
#include <stdlib.h>
#include "tests.h"
#include "type.h"

void trierHoraires(lutin *lutins, int taille) {
    int i, j;
    lutin temp;

    for (i = 0; i < taille - 1; i++) {
        for (j = 0; j < taille - 1 - i; j++) {
            if (lutins[j].disponibilitees.debut > lutins[j + 1].disponibilitees.debut) {
	      /*Échanger les horaires si nécessaire*/
                temp = lutins[j];
                lutins[j] = lutins[j + 1];
                lutins[j + 1] = temp;
            }
        }
    }
}

int sauvhoraire(lutin * lutins,int nombre){
  FILE* fichier = NULL;
  int i;
  fichier = fopen("fichier.txt", "w+");
  if(fichier==NULL){
    printf("Impossible d'ouvrir le fichier\n");
    exit(EXIT_FAILURE);
  }
  fprintf(fichier,"%d\n",nombre);
  for(i=0; i < nombre; i++){
    fprintf(fichier,"-%s %d %d %d\n",lutins[i].prenom, lutins[i].professions , lutins[i].disponibilitees.debut,lutins[i].disponibilitees.fin);
  }
  
  fclose(fichier);
  return 0;
}

int main() {
    int nombreLutins = 10;
    lutin * lutins =NULL;

    initialiserLutins(&lutins, nombreLutins);
    sauve(nombreLutins);
    recup(lutins);
    corrigerHoraires(lutins, nombreLutins);
    trierHoraires(lutins,nombreLutins);
    libererMemoire(lutins);
    sauvhoraire(lutins,nombreLutins);

    exit(EXIT_SUCCESS);
}
