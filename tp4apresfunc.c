// NOTE : 11/20

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// ne compile pas, tu ne peux pas avoir une variable en paramètre d'un tableau en tout cas on n'a pas encore vu comment

void initialiserGrille(int taillegrille, int grille[9][9]) {
    for (int i = 0; i < taillegrille; i++) {
        for (int j = 0; j < taillegrille; j++) {
            grille[i][j] = 0;
        }
    }
}


void remplirGrille(int taillegrille, int grille[9][9], int remplissagedemande) {
    double degreremplissage = 0;
    double remplismax = taillegrille * taillegrille;

    for (int i = 0; i < taillegrille; i++) {
        for (int j = 0; j < taillegrille; j++) {
            degreremplissage++;
            int remplipourcentage = (degreremplissage / remplismax) * 100;
            if (remplipourcentage < remplissagedemande) {
                grille[i][j] = rand() % taillegrille;
            } else {
                grille[i][j] = 0;
            }
        }
    }
}

void afficherGrille(int taillegrille, int grille[9][9]) {
    for (int i = 0; i < taillegrille; i++) {
        printf("{");
        for (int j = 0; j < taillegrille; j++) {
            printf("%i,", grille[i][j]);
        }
        printf("},\n");
    }
}

// verifie que les ligne pas les colonnes
int verifierSiValeurAutorisee(int ligne[9], int valeuraverifier, int taillegrille) {
    for (int i = 0; i < taillegrille; i++) {
        if (ligne[i] == valeuraverifier || valeuraverifier < 0) {
            return 1;
        }
    }
    return 0;
}

void modifierGrille(int taillegrille, int grille[9][9]) {
    int lignemodifier, colonnemodifier, nouvellevaleur;

    printf("quelle ligne souhaitez vous modifier ?\n");
    scanf_s("%i", &lignemodifier);
    while (lignemodifier < 1 || lignemodifier > taillegrille) {
        printf("en dehors de la taille max, quelle ligne souhaitez vous modifier ?\n");
        scanf_s("%i", &lignemodifier);
    }

    printf("quelle colonne souhaitez vous modifier ?");
    scanf_s("%i", &colonnemodifier);
    while (colonnemodifier < 1 || colonnemodifier > taillegrille) {
        printf("en dehors de la taille max, quelle colonne souhaitez vous modifier ?\n");
        scanf_s("%i", &colonnemodifier);
    }

    printf("avec quelle valeur ?\n");
    scanf_s("%i", &nouvellevaleur);
    while (verifierSiValeurAutorisee(grille[lignemodifier - 1], nouvellevaleur, taillegrille)) {
        printf("tu peux pas avec celle-ci, avec quelle valeur ?\n");
        scanf_s("%i", &nouvellevaleur);
    }

    grille[lignemodifier - 1][colonnemodifier - 1] = nouvellevaleur;
}

void choixfunc(int choix[1]){
    printf("1. choix de la taille de grille souhaitée\n");
    printf("2. générer la grille aléatoirement\n");
    printf("3. résoudre la grille\n");
    printf("4. afficher la grille\n");
    printf("5. quitter\n");
    int currchoix;
    scanf_s("%i",&currchoix);
    while (currchoix < 1 | currchoix > 6) {
        printf("de 1 à 6 svp\n");
        scanf_s("%i", &currchoix);
    }
    choix[0]=currchoix; // tu aurais pu laisser une valeur de retour à ta fonction comme au début plutôt que de passer un tableau en parametre
}


// debut de menu mais il manque la boucle de jeu
int main() {
    srand(time(NULL));


    int choix[1];
    choixfunc(choix);

    if(choix[0]==5){
        exit(0);
    }
    int taillegrille;
    if(choix[0]==2){
        taillegrille=1+(rand()%9);
    }else{
    printf("La taille de votre grille ?\n");
    scanf_s("%i", &taillegrille);
    while (taillegrille < 1 || taillegrille > 9) {
        printf("de 1 à 9 svp\n");
        scanf_s("%i", &taillegrille);
    }
    }
    int grille[9][9];

    initialiserGrille(taillegrille, grille);
    int remplissage;
    int remplissagedemande = 25;
    if(choix[0]==2){
        remplissage = 1 + (rand() % 3);
    }else{
        printf("La remplir à moitié (1), tiers(2), ou quart(3) ?\n");
        scanf_s("%i", &remplissage);
        while (remplissage < 1 || remplissage > 3) {
            printf("de 1 à 3 svp\n");
            scanf_s("%i", &remplissage);
        }
        }
    if (remplissage == 1) {
        remplissagedemande = 50;
    }
    if (remplissage == 2) {
        remplissagedemande = 33;
    }

    remplirGrille(taillegrille, grille, remplissagedemande);

    afficherGrille(taillegrille, grille);

    modifierGrille(taillegrille, grille);

    afficherGrille(taillegrille, grille);

    return 0;
}
