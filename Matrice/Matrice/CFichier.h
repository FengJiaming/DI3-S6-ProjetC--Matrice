#pragma once

#include "CMatrice.h"

class CFichier
{
	//ATTRIBUTS
private:
	char * pcFICNom_Fichier;	// le nom de fichier.

public:
	//CONSTRUCTEURS ET DESTRUCTEUR 
	/***********************************
	*  @brief: constructeur par d�fault
	*  @param:  rien
	*  @return : rien
	************************************/
	CFichier(void);
	/***********************************
	*  @brief: constructeur
	*  @param:  pcNom
	*  @return : rien
	************************************/
	CFichier(char * pcNom);
	/************************************
	*  @brief: destructeur
	*  @param:  rien
	*  @return : rien
	*************************************/
	~CFichier(void);

	//METHODES
	/*************************************
	*  @brief: lire le fihcier et les stocker dans un objet de CMatrice
	*  @param:  rien
	*  @return : un objet de la classe  CMatrice
	***************************************/
	CMatrice<double> FICLire_Fichier();
	/**************************************
	*  @brief: lire les �lements de chaque ligne dans le fichier
	*  @param:  pcLine
	*  @param:  cDelimiter
	*  @param:  uiNBElement
	*  @return : le tableau qui est utilis� 
				pour stocker  de cha�nes s�par�es
	****************************************/
	char ** FICLireValeur(char * pcLine, char cDelimiter, unsigned int uiNBElement);
};
