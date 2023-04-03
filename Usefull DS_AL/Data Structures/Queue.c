#include <stdlib.h>
#include <stdio.h>

typedef struct list
{
  int val;
  struct list *next;
} list;

/*...............................*/

void aff_file (list *);
list *creation_cellule (int);
int taille_file (list *);
int is_empty (list *);
int queue (list *);
list *enfiler (list *, int);
list *defiler (list *);
list *liberer_file (list *);
list *insertion_elt (list *, int, int);
list *tri_file (list *);
list *recherche_max (list *);
list *inverser_flie (list *);

/*...............................*/

int
main ()
{
  list *li = creation_cellule (10);
  printf ("la taille de la file est : %d \n", taille_file (li));
  aff_file (li);
  printf ("\n\n/..................................../\n\n");
  li = enfiler (li, 20);
  printf ("la taille de la file est : %d \n", taille_file (li));
  aff_file (li);
  printf ("\n\n/..................................../\n\n");
  li = enfiler (li, 30);
  printf ("la taille de la file est : %d \n", taille_file (li));
  aff_file (li);
  printf ("\n\n---->le queue de la file est : %d \n", queue (li));
  printf ("\n\n/..................................../\n\n");
  li = defiler (li);
  printf ("la taille de la file est : %d \n", taille_file (li));
  aff_file (li);
  printf ("\n\n---->le queue de la file est : %d \n", queue (li));
  printf ("\n\n/..................................../\n\n");
  li = liberer_file (li);
  printf ("la taille de la file est : %d \n", taille_file (li));
  aff_file (li);
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

int taille_file (list * li)
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

void aff_file (list * li)
{
  if (is_empty (li))
    {
      printf ("rien a afficher,la liste est vide.\n");
    }
  else
    {
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

list * enfiler (list * li, int nv_val)
{
  list *nv = creation_cellule (nv_val);
  nv->next = li;
  return nv;
}

/*...............................*/

list * defiler (list * li)
{
  if (is_empty (li))
    {
      return li;
    }
  else if (taille_file (li) == 1)
    {
      free (li);		// ou bien liberer_file(li)
      return NULL;
    }
  else
    {
      list *cou = li;
      while (!is_empty (cou->next->next))
	{
	  li = li->next;
	}
      list *inte = cou->next;
      cou->next = NULL;
      free (inte);
      return (li);
    }
}

/*...............................*/

int queue (list * li)
{
  if (is_empty (li))
    {
      return -1;
    }
  while (!is_empty (li->next))
    {
      li = li->next;
    }
  return li->val;
}

/*...............................*/

list * liberer_file (list * li)
{
  if (is_empty (li))
    {
      return li;
    }
  while (!is_empty (li))
    {
      defiler (li);
    }
}

/*...............................*/

list * tri_file (list * li)
{

}

/*...............................*/

list * insertion_elt (list * li, int val_nv, int pos_nv)
{

}

/*...............................*/

list * inverser_flie (list * li)
{

}

/*...............................*/

list * recherche_max (list * li)
{

}

/*...............................*/
