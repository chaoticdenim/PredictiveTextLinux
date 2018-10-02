#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include <stdbool.h>

#define NOM_FICH1 "mots_courants.txt"
#define NOM_FICH2 "graphe.txt"
#define DICO "dictionnaire.txt"

//Structures utilisées

struct successeur;
typedef struct _graphe
{
	char lettre;
	int freq;
	int fin;
	struct _successeur *fils_tete;
} graphe;

typedef struct _successeur
{
	graphe *fils;
	struct _successeur *suiv;
} successeur;

typedef struct _occurrence_mot
{
	char m[100];
	int occ;
	struct _occurrence_mot *suivant;
} occurrence_mot;

//Variables globales

	char mot1[50];
	char mot2[50];
	char mot3[50];
		
	GtkWidget* Bouton1 = NULL;
	
	GtkWidget* Bouton2 = NULL;
	
	GtkWidget* Bouton3 = NULL;
	
	GtkWidget* suppr = NULL;
	
	GtkWidget* toggle = NULL;
	
	gint positionBeforeWord = 0;
	
	occurrence_mot *tete = NULL;

//Prototypes

void creation_graphe(graphe *G);
graphe *test_lettre_arbre(graphe* G, char a_comparer);
void ajouter_mot(graphe *G, char *mot, float f);
void initialisation(void);
void init_premiere_fois(void);
void init_random(void);
void sortie(void);
void visualisation_liste_chainee(void);
bool ajout_volee(char *a_ajouter, graphe *G);
void maj_occurrence(char *mot);
void suppression_volee(char *a_supprimer);
void parcours_profondeur(graphe *g);
graphe *graphe_to_look(graphe *G, char *debut);
static gboolean OnType(GtkWidget *widget, GdkEventKey *event, graphe* G);
gint OnPress (GtkButton *button, GtkEntry* entry);
gint OnDel (GtkButton *button, graphe *G);
int BestMatch(char* wordToLook, graphe *G, char mot1[], char mot2[], char mot3[]);