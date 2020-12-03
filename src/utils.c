#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "utils.h"
/*
  Voir les TPs, = libentrée, sauf qu'on lit dans un fichier f
 */

void lire_donnee ( FILE * f , char * format , void * res )
{
    int lu = 0 ;
    int count = 0 ;
    char c ;
    do
    {
        lu = fscanf (f,format , res ) ;
        do {
            c = getc ( f ) ;
            if ( ! isspace ( c ) )
                count ++ ;
        } while (! feof(f) && ( c != '\n' )) ;
        
    }
    while ( ( ! feof(f))  &&( (lu != 1) || (count > 0))  );
  
}
  
int lire_entier ( FILE * f )
{
  int res ;
  lire_donnee(f,"%d", &res) ;
  return res ;
}


int lire_entier_intervalle ( FILE * f , int min, int max ) // on part du principe que min est bien inférieur à max 
{
  int lu ;
  do {
      lu = lire_entier(f);
  } while( !(( lu >= min) && (lu < max))) ;
  return 0 ;
}


float lire_float ( FILE * f )
{
  float res;
  lire_donnee(f, " %f", &res);
  return res;  
}


char * lire_string ( FILE * f)
{
  char res;
  lire_donnee(f, " %s", &res);
  return NULL ;
}
/*
  Cadeau, fonction compliquée sur un fichier... On tente de lire un
  mot, si ça échoue, on revient au point de départ et on revoie 1,
  si ça réussit, on reste à la fin du mot et on renvoie 0.
 */
int lire_mot_clef ( FILE * f , const char * mot )
{
  int c ;
  long int
    position_debut,
    position_fin ;
  while ( isspace ( c = getc ( f) ) )
    ;
  ungetc ( c , f ) ;
  position_debut = ftell ( f ) ;
  fscanf ( f , mot ) ;
  position_fin = ftell ( f ) ;
  if ( position_fin != position_debut + strlen ( mot ) )
    {
      fseek ( f , position_debut , SEEK_SET ) ;
      return 0 ;
    }
  else return 1 ;
}
