#include <stdlib.h>
#include <stdio.h>

typedef struct list
{
  int val;
  struct list *next;
} list;

/*...............................*/

void aff_pile (list *);
list *creation_cellule (int);
int  taille_pile (list *);
int  is_empty (list *);
int  tete (list *);
list *empiler (list *, int);
list *depiler (list *);
list *liberer_pile (list *);
list *tri_pile (list *);
list *recherche_max (list *);

/*...............................*/

int
main ()
{
  list *li = creation_cellule (10);
  printf ("la taille de la pile est : %d \n", taille_pile (li));
  aff_pile (li);
  printf ("\n\n/..................................../\n\n");
  li = empiler (li, 20);
  printf ("la taille de la pile est : %d \n", taille_pile (li));
  aff_pile (li);
  printf ("\n\n/..................................../\n\n");
  li = empiler (li, 30);
  printf ("la taille de la pile est : %d \n", taille_pile (li));
  aff_pile (li);  
  printf ("\n\n---->la tete de la pile est : %d \n", tete (li));
  printf ("\n\n/..................................../\n\n");
  li = depiler (li);
  printf ("la taille de la pile est : %d \n", taille_pile (li));
  aff_pile (li);
  printf ("\n\n---->la tete de la pile est : %d \n", tete (li));
  printf ("\n\n/..................................../\n\n");
  li = liberer_pile (li);
  printf ("la taille de la pile est : %d \n", taille_pile (li));
  aff_pile (li);
  printf ("\n\n/..................................../\n\n");
}

/*...............................*/

int is_empty (list * li)
{
  if (li == NULL)
    {
      return 1;
    }
  return 0;
}

/*...............................*/

int taille_pile (list * li)
{
  int nb = 0;
  while (!is_empty (li))
    {
      nb++;
      li = li->next;
    }
  return nb;
}

/*...............................*/

void aff_pile (list * li)
{
  if (is_empty (li))
    {
      printf ("rien a afficher,la liste est vide.\n");
    }
    else{
      while (!(is_empty (li)))
      {
      printf ("[%d]\n", li->val);
      li = li->next;
      } 
    }
}

list * creation_cellule (int val_cell)
{
  list *li = malloc (sizeof (list *));
  li->val = val_cell;
  li->next = NULL;
  return li;
}

/*...............................*/

list * empiler (list * li, int nv_val)
{
  list *nv = creation_cellule (nv_val);
  nv->next = li;
  return nv;
}

/*...............................*/

list * depiler (list * li)
{
  if (!is_empty (li))
    {
      list * inte = li;
      li = li->next;
      free (inte);
      return (li);
    }
  return li;
}

/*...............................*/

int tete (list * li)
{
  return li->val;
}

/*...............................*/

list * liberer_pile (list * li)
{
  if (is_empty (li))
    {
      return li;
    }
  while (!is_empty (li))
    {
      depiler (li);
    }
}

/*...............................*/
 
list *tri_pile (list * li)
{



}



/*...............................*/






/*...............................*/







/*...............................*/

list *
recherche_max (list * li)
{


}

/*...............................*/
