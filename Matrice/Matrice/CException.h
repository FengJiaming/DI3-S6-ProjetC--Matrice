#pragma once

#include <iostream>
#include "stdio.h"
#include <string.h>
#include <stdlib.h>
#include <fstream>

#define ERREUR_OUVERTURE_FICHIER 1
#define ERREUR_TYPE_DONNEES 2
#define ERREUR_SYNTAXIQUE 3
#define ERREUR_TAILLE_MATRICE 4
#define ERREUR_DIMENSIONS_INVALIDES 5
#define ERREUR_DIVISION_PAR_ZERO 6

class CException
{
private:
	unsigned int uiEXCValeur;	//le numero d'erreur.
	char * pcEXCMessage;	// le message d'erreur.

public:
	/****************************
	*  @brief: constructeur par default
	*  @param:  rien
	*  @return : rien
	*****************************/
	CException(void);
	/********************************
	*  @brief: constructeur
	*  @param:  uivaleur
	*  @param : pcMessage
	*  @return : rien
	********************************/
	CException(const unsigned int uiValeur, char * pcMessage);
	/*******************************
	*  @brief: constructeur de recopie
	*  @param:  EXCParam
	*  @return : rien
	********************************/
	CException(CException & EXCParam);            
	/*******************************
	*  @brief: destructeur
	*  @param:  rien
	*  @return : rien
	**********************************/
	~CException(void);
	/*******************************
	*  @brief: Modofier le numero d'erreur
	*  @param:  uiValeur
	*  @return : rien
	**********************************/
	void EXCModifierValeur(unsigned int uiValeur);
	/*******************************
	*  @brief: Lire le numero d'erreur
	*  @param:  rien
	*  @return :  le numero d'erreur
	**********************************/
	unsigned int EXCLireValeur();
	/*******************************
	*  @brief: Lire le numero d'erreur
	*  @param:  rien
	*  @return :  le message d'erreur
	**********************************/
	char * EXCLireMessage();
};
