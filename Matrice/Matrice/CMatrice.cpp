#include "stdafx.h"
#include "CMatrice.h"

/*template<class T>
CMatrice<T>::CMatrice(void)
{
	 eMATNBLignes = 0;
}
*/

//template<class T>
CMatrice::~CMatrice(void)
{
}

//template<class T>
void CMatrice::MATModifierTypeMatrice(char * type){
	pcMATTypeMatrice = type;
	cout << "Type in method" << type <<endl;
	cout << "pcMATTypeMatrice in method" << pcMATTypeMatrice <<endl;
}

void CMatrice::MATModifierNBLignes(int eValeur)
{
	eMATNBLignes = eValeur;
}

void CMatrice::MATModifierNBColonnes(int eValeur)
{
	eMATNBColonnes = eValeur;
}

char * CMatrice::MATLireTypeMatrice()
{
	return pcMATTypeMatrice;
}

/*template<class T>
int CMatrice<T>::MATLireNBLignes()
{
	return eMATNBLignes;
}
*/
