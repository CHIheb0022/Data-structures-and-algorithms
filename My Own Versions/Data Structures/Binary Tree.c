/*  Made by e chi */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Structure d'un Arbre */

typedef struct Tree
{
	int value;
	struct Tree *tleft;
	struct Tree *tright;
	struct Tree *parent;
}Tree;

/* Prototypes des fonctions */

Tree *new_tree(int x);
void clean_tree(Tree *tr);
Tree *join_tree(Tree *left, Tree *right, int node);
void print_tree_prefix(Tree *tr);
void print_tree_infix(Tree *tr);
int  heghit_tree(Tree *tr);//la hauteur est le nb de nivau
int  deep_node(Tree* tr, int x);//la profondeur d'une etiquette (0 [celle de la racine] ---> hauteur-1 )
int  count_tree_nodes(Tree *tr);//nb totale des etiquette somme(de 0 a h-1) de 2^(p)=2^(h) - 1
int  search_tree(Tree* tr);// teste si tr est une arbre de recherche ou non 
int  Max_ABR(Tree* tr);//max des etiquettes de l'ABR
int  Min_ABR(Tree* tr);//min des etiquettes de l'ABR
int  search_elt_tree(Tree* tr,int x);//retourne 1 si l'elt x est dans l'arbre (ABR) 0 sinon
Tree *insert_elt_Tree(Tree* tr, int elt);
Tree *delet_elt_Tree(Tree* tr, int elt);

/*programe principale */

void main() {
    int x;
    Tree *tr=join_tree(join_tree(join_tree(new_tree(5),new_tree(13),12),new_tree(16),14),new_tree(29),22);
    printf("\n\n/*............... Affichage préfixé ..............*/\n\n");
    print_tree_prefix(tr);
    printf("\n\n/*.................................................*/\n\n");
    
    printf("\n\n/*............... Affichage infixé ..............*/\n\n");
    print_tree_infix(tr);
    printf("\n\n/*....................................................*\n\n");
    
    printf("la hauter de l'arbre est : %d\n",heghit_tree(tr));
    
    printf("\n\n/*...................................................*/\n\n");
    
    printf("le nb des noeuds est : %d\n",count_tree_nodes(tr));//ou bien printf("le nb des noeuds est : %d ",2^(heghit_tree)+1)
    
    printf("\n\n/*...................................................*/\n\n");
    
    printf("l'arbre est ABR (1/0) : %d\n",search_tree(tr));
    
    printf("\n\n/*...................................................*/\n\n");
    
    printf("le max de l arbre est : %d\n",Max_ABR(tr));
    
    printf("\n\n/*...................................................*/\n\n");
    
    printf("le min de l arbre est : %d\n",Min_ABR(tr));
    
    printf("\n\n/*...................................................*/\n\n");
    
    printf("donner l'elt que tu recherche \n");scanf("%d",&x);
    
    printf("\n\n/*...................................................*/\n\n");
    
    if (search_elt_tree(tr,x)) {
      printf("--------->L'elt %d existe dans l'arbre\n",x);
      printf("--------->la profondeur de %d dans l'arbre est : %d ",x,deep_node(tr,x));}
       else {printf("------->L'elt %d n'existe pas dans l'arbre\n",x);}
       
    printf("\n\n/*...................................................*/\n\n");
    
    clean_tree(tr);
    
    printf("\n\n/*...................................................*/\n\n");
    
    printf("le nb des noeuds est : %d\n", count_tree_nodes(tr));
    
    printf("\n\n/*....................................................*\n\n");
    
    printf("la hauter de l'arbre est : %d\n",heghit_tree(tr));
}

/*-----------------------------note cours------------------------------------------*/

/*parcours_prefixé(la meilleur manière d'affichage):
 * parcours_prefixé(Tree *tr){
     if (tr==NULL)
       return;
       
     //traitement;
     
     parcours_prefixé(Tree *tleft);
     parcours_prefixé(Tree *tright);
 }
 /*parcours_infixé:
 * parcours_ifixé(Tree *tr){
     if (tr==NULL)
       return;
       
     parcours_infixé(Tree *tleft);
     
     //traitement;
     
     parcours_infixé(Tree *tright);
 }
/*parcours_postfixé(slt de la proc de supression):
 * parcours_postfixé(Tree *tr){
     if (tr==NULL)
      
       return;
     
     parcours_postfixé(Tree *tleft);
     parcours_postfixé(Tree *tright);
     
     //traitement;
 }
 
 /*-----------------------------------------------------------------------*/


/**Remarque :une arbre binaire de recherche (ABR) c'est un arbre speciale permet une rapidité de recherche caracterisé par:
 * l'elt etiquette de la racine est >= tout les etiquettes de la sous-arbre gauche. 
 * l'elt etiquette de la racine est <= tout les etiquettes de la sous-arbre droite. 
 * les deux sous-arbres sont eux_meme des ABR.
 -convention: une Arbre vide est consideré ABR.
/*-----------------------------------------------------------------------*/

/** 
* Créée un nouvel Arbre
* @param x La valeur de la racine
* @return Le nouvel arbre créé
*/

Tree *new_tree(int x)
{
	Tree *tr = malloc(sizeof(*tr));

	if(tr == NULL)
	{
		fprintf(stderr, "Erreur allocation memoire.\n");
		exit(EXIT_FAILURE);
	}

	tr->value = x;
	tr->parent = NULL;
	tr->tleft = NULL;
	tr->tright = NULL;

	//Aide pour le développeur
	printf("Creation de %d...\n", tr->value);

	return tr;
}

/*-----------------------------------------------------------------------*/

/**
* Nettoyage recursive de l'arbre (postfixé)
* @param tr L'arbre à vider de ses valeurs
*/
void clean_tree(Tree *tr)
{
	if(tr == NULL)
		return;

	clean_tree(tr->tleft);
	clean_tree(tr->tright);
	
    //aide pour le developpeur
    printf("suppression de %d ...\n",tr->value);
	free(tr);
}

/*-----------------------------------------------------------------------*/

/**
* Joint deux arbres pour n'en former qu'un
* @param left L'arbre de gauche
* @param right L'arbre de droite
* @param node Le noeud qui lie les deux arbres
* @return Le nouvel arbre formé
*/
Tree *join_tree(Tree* left, Tree* right, int node)
{
	Tree *tr = new_tree(node);

	tr->tleft = left;
	tr->tright = right;

	if(left != NULL)
		left->parent = tr;
	if(right != NULL)
		right->parent = tr;

	return tr;
}

/*-----------------------------------------------------------------------*/

/**
* Affiche un arbre récursivement (parcours préfixé)
* @param tr L'arbre à parcourir
*/
void print_tree_prefix(Tree *tr)
{
	if(tr == NULL)
		return;

	if(tr->parent != NULL)
    	printf("(%d) -> %d\n", tr->parent->value, tr->value);
    else
    	printf("(%d)\n", tr->value);

    print_tree_prefix(tr->tleft);

    print_tree_prefix(tr->tright);
}
/*-----------------------------------------------------------------------*/

/**
* Affiche un arbre récursivement (parcours infixé)
* @param tr L'arbre à parcourir
*/
void print_tree_infix(Tree *tr)
{
	if(tr == NULL)
		return;
		
    print_tree_infix(tr->tleft);
    
    	printf("(%d)\n", tr->value);
    	
    print_tree_infix(tr->tright);
}

/**
* Compte le nombre de noeuds d'un arbre
* @param tr L'arbre dont il faut compter les noeuds
* @return Le nombre de noeuds de l'arbre binaire
*/
int count_tree_nodes(Tree *tr)
{
	if(tr == NULL)
		return 0;

	return (count_tree_nodes(tr->tleft) + count_tree_nodes(tr->tright) + 1);	
}

/*-----------------------------------------------------------------------*/

/**
* Compte le hauteur d'un arbre
* par convention heghit_tree(NULL)=-1
* @param tr L'arbre dont il faut compter les noeuds
* @return Le hauteur de l'arbre binaire
*/
int heghit_tree(Tree* tr){
 if (tr==NULL)
    return 0;
 return 1+fmax(heghit_tree(tr->tleft),heghit_tree(tr->tright));    
}

/*-----------------------------------------------------------------------*/

int deep_node(Tree* tr , int x){
    if (tr==NULL)                 //ou bien "(search_elt_tree(tr,x)==0)"
      return -1;
      else if (tr->value==x)
    
        return 0;
        
            else if (x>tr->value)
            
                return deep_node(tr->tright,x) +1;
                
                    else
                    
                     return deep_node(tr->tleft,x) +1;  
}

/*-----------------------------------------------------------------------*/

int search_tree(Tree* tr){
    if (tr==NULL)
    
      return 1;
      
      else if ((tr->tleft!=NULL)&&(tr->tright!=NULL))//pour pouvoir tester sur tr->tright->value et tr->tleft->value
      {
            if (!((tr->tright->value>=tr->value) && (tr->tleft->value<=tr->value))) {
                
              return 0;}
              
                else {
                    
                  return (search_tree(tr->tleft))&&(search_tree(tr->tright));}
       }    
    return 1; // si il y a pas de coppure "(return 0)" on a parcourue tout l'arbre est donc il s'agit d'une ABR.        
}  

/*-----------------------------------------------------------------------*/

int  Max_ABR(Tree* tr){
  if (tr==NULL)
   return 0;
   else if (tr->tright==NULL)
    return tr->value;
      else 
      return (Max_ABR(tr->tright));
 
} 

/*-----------------------------------------------------------------------*/

int  Min_ABR(Tree* tr){
  if (tr==NULL)
   return 0;
   else if (tr->tleft==NULL)
    return tr->value;
      else 
      return(Min_ABR(tr->tleft));
}

/*-----------------------------------------------------------------------*/

int  search_elt_tree(Tree* tr,int x){
    if (tr==NULL)
      return 0;
      else if (tr->value==x) 
          return 1;
             else if (x>tr->value)
                return search_elt_tree(tr->tright,x);
                  else 
                     return search_elt_tree(tr->tleft,x);
}

/*-----------------------------------------------------------------------*/

Tree* insert_elt_Tree(Tree* tr, int elt){
    
 
    
    
    
}

/*-----------------------------------------------------------------------*/

Tree *delet_elt_Tree(Tree* tr, int elt){
    
    
    
    
    
}




