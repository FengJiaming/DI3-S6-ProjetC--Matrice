#include "stdafx.h"
#include "CFichier.h"


CFichier::CFichier(void)
{
	pcFICNom_Fichier = "";
}

CFichier::CFichier(char * pcNom)
{
	pcFICNom_Fichier = pcNom;
}

CFichier::~CFichier(void)
{
	free(pcFICNom_Fichier);
}


CMatrice<double> CFichier::FICLire_Fichier()
{
	//Creer une matrice temporaire
	CMatrice<double> Matrice;
				
	ifstream File;

	File.open(pcFICNom_Fichier);
	if (!File.is_open()) {			  
		throw CException(ERREUR_OUVERTURE_FICHIER, "Could Not Open File.");
	}

	char buffer[1024];    //Stocker tout le contenu de chaque ligne
	char ** ppcElement;		//Stocker les elements de chaque ligne 
	char *pcNBLignes;		//Stocker le ligne de Matrice
	char *pcNBColonnes;		//Stocker le colonne de Matrice

	int fileligne = 1;       //Le nombre de lignes de fichier en cours de lecture
	int currentLigneMatrice = 0;	//Le nombre de lignes de Matrice en cours de lecture

	cout << "Read from file: " << pcFICNom_Fichier << endl;
	while (File.getline(buffer, 1024)) {

		//TypeMatrice
		if (fileligne == 1) {
			char typeDouble[] = "double";
			char * type = strstr(buffer, typeDouble);
			if (type == NULL) {
				throw CException(ERREUR_TYPE_DONNEES,"Matrice Type Error.");
			}
		}

		//Extraire nombre de lignes de la matrice
		if (fileligne == 2) {
			if(strstr(buffer,"NBLignes=")==NULL){
				throw CException(ERREUR_SYNTAXIQUE,"Syntax error in ligne 2.");
			}
			else {
				ppcElement = FICLireValeur(buffer,'=',2);
				pcNBLignes = ppcElement[1];
				Matrice.MATModifierNBLignes(atoi(pcNBLignes));
			}
		}

		//Extraire nombre de colonnes de la matrice
		if (fileligne == 3) {
			if(strstr(buffer,"NBColonnes=")==NULL){
				throw CException(ERREUR_SYNTAXIQUE,"Syntax error in ligne 3.");
			}
			else {
				ppcElement = FICLireValeur(buffer,'=',2);
				pcNBColonnes = ppcElement[1];
				Matrice.MATModifierNBColonnes(atoi(pcNBColonnes));
			}
		}

		//Distribuer le memoire pour le matrice temporaire
		if (fileligne == 4) {
			if(strstr(buffer,"Matrice=[")==NULL){
				throw CException(ERREUR_SYNTAXIQUE,"Syntax error in ligne 4.");
			}
			else {
				Matrice.MATDistribuerMemoire(Matrice.MATLireNBLignes(), Matrice.MATLireNBColonnes());
			}
		}

		//Extraire les elements de la matrice
		if (fileligne > 4) {
			if(strstr(buffer,"]")==NULL){
				if(currentLigneMatrice > Matrice.MATLireNBLignes()-1){    
					char pcMsg[1024];
					//Préparation du message d'erreur
					sprintf_s(pcMsg, 1024, "Syntax error in ligne %d.", fileligne);
					throw CException(ERREUR_SYNTAXIQUE,pcMsg); 
				}
				else{
					ppcElement = FICLireValeur(buffer,' ',Matrice.MATLireNBColonnes());
					for(unsigned int uiBoucleI = 0; uiBoucleI <	Matrice.MATLireNBColonnes(); uiBoucleI++){
						Matrice.MATModifierMatrice(currentLigneMatrice, uiBoucleI, atof(ppcElement[uiBoucleI]));
					}
				}
				currentLigneMatrice++;
			}
		}
		
		cout << "Ligne " << fileligne << " = "<< buffer << endl;
		fileligne++;
	}
	
	return Matrice;
}

//lire les élements de chaque ligne dans le fichier
char ** CFichier::FICLireValeur(char * pcLine, char cDelimiter, unsigned int uiNBElement)
{
		//Creer un tableau de type char ** pour stocker des elements sur une ligne
		char **ppcLigneelement = (char **)malloc((uiNBElement) * sizeof(char *));
		char * pcStart = pcLine;
		char * pcEnd = pcLine;

		for (unsigned int uiBoucleI = 0; uiBoucleI < uiNBElement; uiBoucleI++) {
			//On analyse chaque caractere
			while (*pcEnd != '\0' && *pcEnd != cDelimiter) { 	   //rechercher "=" " " "\0"  
				pcEnd++;
			}
			char *tmp = (char *)malloc(100 * sizeof(char));

			int length = pcEnd - pcStart;

			memcpy(tmp, pcStart, length);	//copy the string with length  
			tmp[length] = '\0';

			pcStart = pcEnd;
			pcStart++;
			pcEnd++;

			ppcLigneelement[uiBoucleI] = tmp;
			}
		return ppcLigneelement;
}