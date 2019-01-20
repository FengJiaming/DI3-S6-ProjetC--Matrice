template <class Type>
CMatrice<Type>::CMatrice(void)
{
	uiMATNBLignes = 0;
	uiMATNBColonnes = 0;
	pptMATMatrice = NULL;
}

template <class Type>
CMatrice<Type>::CMatrice(unsigned int uiMATLigne, unsigned int uiMATColonne)
{
	if(uiMATLigne == 0 || uiMATColonne == 0)
        throw CException(ERREUR_TAILLE_MATRICE,"Taille de matrice est zero.");
	uiMATNBLignes = uiMATLigne;
	uiMATNBColonnes = uiMATColonne;
	MATDistribuerMemoire(uiMATLigne, uiMATColonne);
	
}

template <class Type>
CMatrice<Type>::CMatrice(CMatrice & MATB)
{
	// Initialisation
	uiMATNBLignes = MATB.uiMATNBLignes;
	uiMATNBColonnes = MATB.uiMATNBColonnes;
	MATDistribuerMemoire(uiMATNBLignes, uiMATNBColonnes);
	// Copie
	for (unsigned int uiBoucleI = 0; uiBoucleI < uiMATNBLignes; uiBoucleI++) {
		for (unsigned int uiBoucleJ = 0; uiBoucleJ < uiMATNBColonnes; uiBoucleJ++) {
			pptMATMatrice[uiBoucleI][uiBoucleJ] = MATB.pptMATMatrice[uiBoucleI][uiBoucleJ];
		}
	}
}

template <class Type>
CMatrice<Type>::~CMatrice(void)
{
	for (unsigned int uiBoucleI = 0; uiBoucleI < uiMATNBColonnes; uiBoucleI++) {
		delete pptMATMatrice[uiBoucleI];
	}
	delete pptMATMatrice;
}

template <class Type>
void CMatrice<Type>::MATDistribuerMemoire(unsigned int uiMATLigne, unsigned int uiMATColonne)
{
	//distribuer memoire
	pptMATMatrice = new Type*[uiMATLigne];
	for (unsigned int uiBoucleI = 0; uiBoucleI < uiMATLigne; uiBoucleI++) {
		pptMATMatrice[uiBoucleI] = new Type[uiMATColonne];
	}

	//assignation
	for (unsigned int uiBoucleI = 0; uiBoucleI < uiMATLigne; uiBoucleI++) {
		for (unsigned int uiBoucleJ = 0; uiBoucleJ < uiMATColonne; uiBoucleJ++) {
			pptMATMatrice[uiBoucleI][uiBoucleJ] = 0;
		}
	}
}

template <class Type>
void CMatrice<Type>::MATModifierNBLignes(unsigned int uiValeur)
{
	uiMATNBLignes = uiValeur;
	
}

template <class Type>
void CMatrice<Type>::MATModifierNBColonnes(unsigned int uiValeur)
{
	uiMATNBColonnes = uiValeur;
	
}

template <class Type>
void CMatrice<Type>::MATModifierMatrice(unsigned int uiMATLigne, unsigned int uiMATColonne, Type tValeur)
{
	pptMATMatrice[uiMATLigne][uiMATColonne] = tValeur; // exception if ligne and colonne wrong!
}

template <class Type>
unsigned int CMatrice<Type>::MATLireNBLignes()
{
	return uiMATNBLignes;
}

template <class Type>
unsigned int CMatrice<Type>::MATLireNBColonnes(){
	return uiMATNBColonnes;
}
template <class Type>
Type  CMatrice<Type>::MATLireMatrice()
{
	return pptMATMatrice[uiMATNBLignes][uiMATNBColonnes];
}

template <class Type>
void CMatrice<Type>::MATAfficher()
{
	cout << "NBLignes = " << uiMATNBLignes << endl;
	cout << "NBColonnes = " << uiMATNBColonnes << endl;
	cout << "Matrice = { "<<endl;
	MATAfficherMatrice();
}

template <class Type>
void CMatrice<Type>::MATAfficherMatrice()
{
	for (unsigned int uiBoucleI = 0; uiBoucleI < uiMATNBLignes; uiBoucleI++) {
		for (unsigned int uiBoucleJ = 0; uiBoucleJ < uiMATNBColonnes; uiBoucleJ++) {
			cout << pptMATMatrice[uiBoucleI][uiBoucleJ] << " ";
		}
		cout << endl;
	}
	cout << "}" << endl;
}

template <class Type>
void CMatrice<Type>::MATAfficherTransposer()
{
	for (unsigned int uiBoucleJ = 0; uiBoucleJ <uiMATNBLignes; uiBoucleJ++) {
		for (unsigned int uiBoucleI = 0; uiBoucleI <  uiMATNBColonnes; uiBoucleI++) {
			cout << pptMATMatrice[uiBoucleJ][uiBoucleI] << " ";
		} 
		cout << endl;
	}
	cout << "}" << endl;

}

template <class Type>
CMatrice<Type> * CMatrice<Type>::MATTransposer()
{
	CMatrice<Type> * MATResult = new CMatrice<Type>(uiMATNBColonnes, uiMATNBLignes );
	for (unsigned int uiBoucleI = 0; uiBoucleI < uiMATNBColonnes; uiBoucleI++) {
		for (unsigned int uiBoucleJ = 0; uiBoucleJ < uiMATNBLignes; uiBoucleJ++) {
			MATResult->pptMATMatrice[uiBoucleI][uiBoucleJ] = this->pptMATMatrice[uiBoucleJ][uiBoucleI] ;
		}
	}
	return MATResult;
}

template <class Type>
CMatrice<Type> & CMatrice<Type> :: operator= (const CMatrice<Type> & MATB)
{
	uiMATNBLignes = MATB.uiMATNBLignes;
	uiMATNBColonnes = MATB.uiMATNBColonnes;
	
	if (uiMATNBLignes != MATB.uiMATNBLignes || uiMATNBColonnes != MATB.uiMATNBColonnes) {
		throw CException(ERREUR_DIMENSIONS_INVALIDES,"Taille de matrice est invalide.On ne peux pas faire l'assignation de deux matrices ");
	}
	
	MATDistribuerMemoire(uiMATNBLignes, uiMATNBColonnes);
	for (unsigned int uiBoucleI = 0; uiBoucleI < uiMATNBLignes; uiBoucleI++) {
		for (unsigned int uiBoucleJ = 0; uiBoucleJ < uiMATNBColonnes; uiBoucleJ++) {
			pptMATMatrice[uiBoucleI][uiBoucleJ] = MATB.pptMATMatrice[uiBoucleI][uiBoucleJ];
		}
	}
	return *this;
}

template <class Type>
CMatrice<Type>  CMatrice<Type>::operator+(const CMatrice<Type> & MATB)
{
	if (uiMATNBLignes != MATB.uiMATNBLignes || uiMATNBColonnes !=  MATB.uiMATNBColonnes) {
		throw CException(ERREUR_DIMENSIONS_INVALIDES,"Taille de matrice est invalide.On ne peux pas faire l'addition de deux matrices ");
	}
	else {
		CMatrice<Type> * MATResult = new CMatrice<Type>(uiMATNBLignes, uiMATNBColonnes);
		for (unsigned int uiBoucleI = 0; uiBoucleI < uiMATNBLignes; uiBoucleI++) {
			for (unsigned int uiBoucleJ = 0; uiBoucleJ < uiMATNBColonnes; uiBoucleJ++) {
				MATResult->pptMATMatrice[uiBoucleI][uiBoucleJ] = pptMATMatrice[uiBoucleI][uiBoucleJ] + MATB.pptMATMatrice[uiBoucleI][uiBoucleJ];
			}
		}
		return *MATResult;
	}
}

template <class Type>
CMatrice<Type> CMatrice<Type>::operator-(const CMatrice<Type> & MATB)
{
	if (uiMATNBLignes != MATB.uiMATNBLignes || uiMATNBColonnes !=  MATB.uiMATNBColonnes) {
		throw CException(ERREUR_DIMENSIONS_INVALIDES,"Taille de matrice est invalide.On ne peux pas faire la soustraction de deux matrices ");
	}
	else {
		CMatrice<Type> * MATResult = new CMatrice<Type>(uiMATNBLignes, uiMATNBColonnes);
		for (unsigned int uiBoucleI = 0; uiBoucleI < uiMATNBLignes; uiBoucleI++) {
			for (unsigned int uiBoucleJ = 0; uiBoucleJ < uiMATNBColonnes; uiBoucleJ++) {
				MATResult->pptMATMatrice[uiBoucleI][uiBoucleJ] = pptMATMatrice[uiBoucleI][uiBoucleJ] - MATB.pptMATMatrice[uiBoucleI][uiBoucleJ];
			}
		}
		return *MATResult;
	}
}

template <class Type>
CMatrice<Type> CMatrice<Type>::operator*(const CMatrice<Type> & MATB)
{
	if (uiMATNBLignes != MATB.uiMATNBColonnes || uiMATNBColonnes != MATB.uiMATNBLignes ) {
		//Le nombre de lignes dans M1 et le nombre de colonnes dans M2 ne sont pas égaux
		throw CException(ERREUR_DIMENSIONS_INVALIDES,"Taille de matrice est invalide.On ne peux pas faire le produit de deux matrices "); 
	}
	else {
		CMatrice<Type> * MATResult = new CMatrice<Type>(uiMATNBLignes, MATB.uiMATNBColonnes);
		for (unsigned int uiBoucleI= 0; uiBoucleI< uiMATNBLignes; ++uiBoucleI) {
			for (unsigned int uiBoucleJ = 0; uiBoucleJ < MATB.uiMATNBColonnes; ++uiBoucleJ) {
				for (unsigned int uiBoucleK = 0; uiBoucleK < uiMATNBColonnes; ++uiBoucleK) {
					MATResult->pptMATMatrice[uiBoucleI][uiBoucleJ] += pptMATMatrice[uiBoucleI][uiBoucleK] * MATB.pptMATMatrice[uiBoucleK][uiBoucleJ];
				}
			}
		}
		return *MATResult;
	}
}

template<class Type>
 CMatrice<Type> CMatrice<Type>::operator*(Type tValeur)
{
	CMatrice<Type> MATResult (uiMATNBLignes, uiMATNBColonnes);
	for (unsigned int uiBoucleI = 0; uiBoucleI < uiMATNBLignes; uiBoucleI++) {
		for (unsigned int uiBoucleJ = 0; uiBoucleJ < uiMATNBColonnes; uiBoucleJ++) {
			MATResult.pptMATMatrice[uiBoucleI][uiBoucleJ] =  this->pptMATMatrice[uiBoucleI][uiBoucleJ] * tValeur ;
		}
	}
	return MATResult;
}
 
template<class Type>
CMatrice<Type> operator*(Type & tValeur,CMatrice<Type> &MATB){
	return MATB * tValeur;
}

template<class Type>
CMatrice<Type> CMatrice<Type>::operator/(Type tValeur)
{
	if(tValeur == 0)
	   throw CException(ERREUR_DIVISION_PAR_ZERO,"Le matrice ne peut pas diviser par un nombre");
	CMatrice<Type> MATResult (uiMATNBLignes, uiMATNBColonnes);
	for (unsigned int uiBoucleI = 0; uiBoucleI < uiMATNBLignes; uiBoucleI++) {
		for (unsigned int uiBoucleJ = 0; uiBoucleJ < uiMATNBColonnes; uiBoucleJ++) {
			MATResult.pptMATMatrice[uiBoucleI][uiBoucleJ] = this->pptMATMatrice[uiBoucleI][uiBoucleJ] / tValeur;
		}
	}
	return MATResult;
}