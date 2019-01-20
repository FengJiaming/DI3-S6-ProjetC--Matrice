#pragma once

#include "CException.h"

using namespace std;

template <class Type>
class CMatrice
{
	//Attributs
private:
	unsigned int uiMATNBLignes;      //le nombre de ligne de la matrice 
	unsigned int uiMATNBColonnes;    //le nombre de colonne de la matrice
	Type ** pptMATMatrice;			 //la matrice

public:
	//CONSTRUCTEURS ET DESTRUCTEUR 
	/****************************************************
	*  @brief: constructeur par default
	*  @param:  rien
	*  @return : rien
	*****************************************************/
	CMatrice(void);
	/*****************************************************
	*  @brief: constructeur avec MATligne lignes MATcolonne colonnes
	*  @param:  uiMATLigne
	*  @param:  uiMATColonne
	*  @return : rien
	******************************************************/
	CMatrice(unsigned int uiMATLigne, unsigned int uiMATColonne);
	/*****************************************************
	*  @brief: constructeur de recopie
	*  @param:  MATB
	*  @return : rien
	*****************************************************/
	CMatrice(CMatrice<Type> & MATB);
	/*****************************************************
	*  @brief: destructeur 
	*  @param:  rien
	*  @return : rien
	******************************************************/
	~CMatrice(void);
	/*****************************************************
	*  @brief: Distribuer la memoire pour la matrice de MATligne lignes MATcolonne colonnes 
	*  @param:  uiMATLigne
	*  @param:  uiMATColonne
	*  @return : rien
	******************************************************/
	void MATDistribuerMemoire(unsigned int uiMATLigne, unsigned int uiMATColonne);
	/*****************************************************
	*  @brief: Modifier le nombre de lignes
	*  @param:  uiValeur
	*  @return : rien
	*****************************************************/
	void MATModifierNBLignes(unsigned int uiValeur);
	/*****************************************************
	*  @brief:  Modifier le nombre de colonnes
	*  @param:  uiValeur
	*  @return: rien
	******************************************************/
	void MATModifierNBColonnes(unsigned int uiValeur);
	/*****************************************************
	*  @brief:  Modifier le valeur de uiLigne ligne uiColonne colonne
	*  @param:  uiMATLigne
	*  @param:  uiMATcolonne
	*  @param:  tValeur
	*  @return: rien
	*****************************************************/
	void MATModifierMatrice(unsigned int uiMATLigne, unsigned int uiMATcolonne, Type tValeur);
	/*****************************************************
	*  @brief:  Obtenir le nombre de lignes
	*  @param:  rien
	*  @return : le nombre de lignes
	*****************************************************/
	unsigned int MATLireNBLignes();
	/*****************************************************
	*  @brief:  Obtenir le nombre de colonnes
	*  @param:  rien
	*  @return: le nombre de colonnes
	*****************************************************/
	unsigned int MATLireNBColonnes();
	/*****************************************************
	*  @brief:  Obtenir la matrice
	*  @param:  rien
	*  @return: la matrice
	******************************************************/
	Type MATLireMatrice();
	/*****************************************************
	*  @brief:  Afficher les 3 attributs de la matrice
	*  @param:  rien
	*  @return: rien
	*******************************************************/
	void MATAfficher();
	/*****************************************************
	*  @brief:  Juste afficher la matrice
	*  @param:  rien
	*  @return: rien
	******************************************************/
	void MATAfficherMatrice();
	/*****************************************************
	*  @brief:  Afficher la matrice apres transposer
	*  @param:  rien
	*  @return: rien
	*******************************************************/
	void MATAfficherTransposer();
	/*****************************************************
	*  @brief:  Realiser M^T
	*  @param:  rien
	*  @return: un objet de la classe CMatrice
	********************************************************/
	CMatrice<Type> * MATTransposer();
	/******************************************************
	*  @brief:  La surcharge d'operateur =, Realiser M1=M2 
	*  @param:  & MATB
	*  @return: un objet de la classe CMatrice
	*******************************************************/
	CMatrice<Type> & operator = (const CMatrice<Type> & MATB);
	/******************************************************
	*  @brief:  La surcharge d'operateur +,Realiser M1 + M2
	*  @param:  & MATB
	*  @return: un objet de la classe CMatrice
	*******************************************************/
	CMatrice<Type>  operator +(const CMatrice<Type> & MATB);
	/******************************************************
	*  @brief:  La surcharge d'operateur -, Realiser M1 - M2
	*  @param:  & MATB
	*  @return: un objet de la classe CMatrice
	*******************************************************/
	CMatrice<Type> operator -(const CMatrice<Type> & MATB);
	/******************************************************
	*  @brief:  La surcharge d'operateur *, Realiser M1 * M2
	*  @param:  & MATB
	*  @return: un objet de la classe CMatrice
	*******************************************************/
	CMatrice<Type> operator *(const CMatrice<Type> & MATB);
	/******************************************************
	*  @brief:  La surcharge d'operateur *, Realiser M1 * c
	*  @param:  tValeur
	*  @return: un objet de la classe CMatrice
	*******************************************************/
	CMatrice<Type> operator *(Type tValeur);   // M x c
	/******************************************************
	*  @brief:  La surcharge d'operateur /, Realiser M1 / c
	*  @param:  tValeur
	*  @return: un objet de la classe CMatrice
	*******************************************************/
	CMatrice<Type> operator /(Type tValeur);   // M / c

};

#include "CMatrice.hpp"
