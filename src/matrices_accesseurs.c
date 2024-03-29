#include <stddef.h>
#include "matrices_struct.h"
#include "matrices_accesseurs.h"
/*
  accesseurs sur les matrices
*/
int nb_lignes ( struct matrice_s * m )
{
  return (m->nb_lignes); //On recupere le nombre de ligne de la matrice
}
int nb_cols ( struct matrice_s * m )
{
  return (m->nb_cols); //On recupere le nombre de colones de la matrice
}

int matrice_set (struct matrice_s * m, int num_ligne , int num_colonne, float value) //On met la valeur
{
  m->matrice[num_ligne][num_colonne]= value;
  return 0 ;
}

int matrice_get(struct matrice_s * m, int num_ligne, int num_colonne , float * value ) //On récupere la valeur
{
  *value= m->matrice[num_ligne][num_colonne];
  return 0 ;
}

float *** matrice_raw(struct matrice_s * m ) 
{
  return (&(m->matrice));
}
