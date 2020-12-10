#include <malloc.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include "utils.h"
#include "matrices.h"
#include "matrices_struct.h"

/*
  Cette fonction doit libérer la mémoire allouée lors de la création d'une matrice
 */
void detruit_matrice ( struct matrice_s * m )
{
  free(m);
}

/*
  Cette fonction crée une matrice 
 */
struct matrice_s* creation_matrice ( int nb_lignes , int nb_colonnes )
{
  struct matrice_s* NouvMatrice;
  NouvMatrice = malloc( nb_colonnes * nb_lignes * sizeof(int));
  if (NouvMatrice == NULL) //On verifie que l'atribution a fonctionné
  {
    exit(0); //On Arrete tout
  }
  NouvMatrice->nb_lignes=nb_lignes;
  NouvMatrice->nb_cols= nb_colonnes;
  return NouvMatrice ;
}

/*
  Si *e == NULL , il faut créer une matrice 1 x n et la mettre dans
  *e.  Maintenant que *e contient une matrice 1 x n, il faut recopier
  les coefficients du tableau t dans cette matrice.  
 */
int matrice_ligne ( struct matrice_s * * m , float * t , int n )
{
  int i ; 
  if( *m == NULL ) 
	  {
	    *m = creation_matrice ( 1 , n ) ;
   	  }
  for ( i = 0 ; i < n ; i++ )
    (*m)->matrice[0][i] = t[i] ;
  return 0 ;
}



/*
  Cette fonction crée et initialise une matrice n x m avec des |float|
  dans [ -1 , 1 ].
*/
struct matrice_s * creation_matrice_aleatoire ( int nb_lignes , int nb_colonnes )
{
  float Nb=0; //Pour le tirage aleatoire
  srand(time(NULL));
  struct matrice_s* NewMatrice = creation_matrice( nb_lignes, nb_colonnes); // Creation de la matrice
  for ( int i= 0 ; i < nb_lignes*nb_colonnes ; i++)
  {
    Nb= (float)rand() / (float)RAND_MAX - (float)rand()/(float)RAND_MAX; //Tirage aleatoire d'un float entre -1 et 1
    *((NewMatrice)->matrice[i])=Nb;
  }
  return NewMatrice;
}


/*
  Cette fonction demande à l'utilisateur les dimensions et les
  coefficients d'une matrice, et renvoie la matrice correspondante.
*/
struct matrice_s * creation_matrice_utilisateur ( )
{  
  int ligne=0,colone=0;
  do {
    printf("Combien de Lignes voulez vous dans votre matrice ?");
    scanf("%d", &ligne);
    printf("Combien de Colones voulez vous dans votre matrice ?");
    scanf("%d", &colone);
  } while (ligne<=0 || colone<=0); //On verifie que les valeurs demandés par l'utilisateurs sont bonnes
  struct matrice_s* NwMatrice = creation_matrice(ligne, colone);
  return NwMatrice;
}

/*
  Cette fonction lit une matrice qui a été stockée dans un fichier.
*/
int lire_matrice_fichier ( FILE * f , struct matrice_s * * m )
{
  int nb_lignes=0, nb_colonnes=0;
  float case_m=0;
  if ( f == NULL) //On verifie que le fichier a bien pu etre ouvert
  {
    printf("ERREUR Impossible de lire le fichier");
  }
  else
  {
    fscanf(f, "%d %d", &nb_lignes, &nb_colonnes);
    *m = creation_matrice(nb_lignes, nb_colonnes);
    for (int i=0; i<nb_lignes;i++)
    {
      for (int j=0 ; j<nb_colonnes ; j++)
      {
        fscanf(f, "%f", &case_m); //VERIFIER AVEC LA PROF
        (*m)->matrice[i][j]=case_m;
      }
    }
  }
  return 0 ;
}
/*
  Cette fonction sauve une matrice dans un fichier. Elle
  doit utiliser la même format que lit_matrice_fichier
*/
int sauve_matrice_fichier ( FILE * f , struct matrice_s * m ) 
{
  if ( f == NULL)
  {
    printf("ERREUR Impossible de lire le fichier"); //Le fichier n'a pas pu etre ouvert/trouve
  }
  else
  {
    fprintf(f,"%d %d \n",m->nb_lignes,m->nb_cols); //On affiche le nombre de lignes et colones de la matrice
    for (int i=0; i<(m->nb_lignes) ;i++)
    {
      for (int j=0; j<(m->nb_cols) ; j++)
      {
        fprintf(f, "%f", m->matrice[i][j]);
      }
      fprintf(f,"\n"); //On revient a la ligne
    }
  }
  return 0 ;
}
/*
  Cette fonction affiche une matrice.
*/
void affiche_matrice ( struct matrice_s * m )
{
    for (int i=0; i<(m->nb_lignes) ; i++)
    {
      for (int j=0; j<(m->nb_cols) ; j++)
      {
        printf("%f ",m->matrice[i][j]);  //On affiche la valeur situé dans la matrice à la ligne i et colone j
      }
      printf("\n"); //On change de Ligne
    }
}


/*
  Copie le contenu de la matrice m1 dans la matrice m2.
  Les 2 matrices existent et ont les mêmes dimensions.
*/
int copie_matrice( struct matrice_s * m1, struct matrice_s * m2 )
{
  for (int i=0; i<(m1->nb_lignes) ; i++)
    {
      for (int j=0; j<(m1->nb_cols) ; j++)
      {
       m2->matrice[i][j] = m1->matrice[i][j];  //On atribue la valeur de la matrice 1 ligne i colone j à la meme place dans la matrice 2
      }
    }
  return 0 ;
}
