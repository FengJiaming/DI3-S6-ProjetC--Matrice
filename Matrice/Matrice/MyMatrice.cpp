// Matrice.cpp? d�finit le point d'entr�e pour l'application console.
//

#include "stdafx.h"
#include "CFichier.h"


int main(int argc, char* argv[])
{
	if(argc >= 2){
		//on cr�e un tableau  pour stocker les Matrices.
		CMatrice<double>** MatriceArray = new CMatrice<double>*[argc - 1];  //Le taile est �gal au nombre de fichiers 
		
		//Lire les fichiers et cre�r les matrices associ�e
		for(int i = 1; i < argc; i++)
		{
			try{
				CFichier * File = new CFichier(argv[i]);
				MatriceArray[i - 1] = new CMatrice<double>();
				*MatriceArray[i - 1] = File->FICLire_Fichier();
				cout << "Matrice" << i <<  " =  { "<<endl;
				MatriceArray[i - 1]->MATAfficherMatrice();

			}
			catch (CException EXCLevee) {
				cout << "Exception est levee lors de la lecture du fichier numero " << i << " : ";
				cout << "Exception numero " <<EXCLevee.EXCLireValeur() << ": "<< EXCLevee.EXCLireMessage() << endl;
				system("pause");
				return 0;
			}
		}

		//Faire des op�rations sur les matrices
		try{
			unsigned int uiM1Lignes = 0;
			unsigned int uiM1Colonnes = 0;

			cout << "Please input a value double to multiplier/divide : ";
			double dValuerC;
			cin >> dValuerC; //Demande � l'utilisateur de saisir une valeur c

			//Faire la multiplication entre une matrice et un nombre.
			for(int nBoucleI = 1; nBoucleI < argc; nBoucleI++)
			{
				//Initialiser une matrice pour afficher le r�sultat
				uiM1Lignes = MatriceArray[nBoucleI - 1]->MATLireNBLignes();
				uiM1Colonnes = MatriceArray[nBoucleI - 1]->MATLireNBColonnes();
				CMatrice<double> *MATResult= new CMatrice<double>(uiM1Lignes, uiM1Colonnes);

				*MATResult =  *MatriceArray[nBoucleI - 1] * dValuerC ;                 //M x c
				cout << "M" << nBoucleI << " x " << dValuerC << "= {" << endl;  
				MATResult->MATAfficherMatrice();

				*MATResult = dValuerC * (*MatriceArray[nBoucleI - 1]);       //c x M
				cout << dValuerC <<" x M" << nBoucleI << "= {" << endl;
				MATResult->MATAfficherMatrice();
				delete MATResult;
			}

			//Faire la division de chacune des matrices par la valeur c
			for(int nBoucleI = 1; nBoucleI < argc; nBoucleI++)
			{
				uiM1Lignes = MatriceArray[nBoucleI - 1]->MATLireNBLignes();
				uiM1Colonnes = MatriceArray[nBoucleI - 1]->MATLireNBColonnes();
				CMatrice<double> *MATResult= new CMatrice<double>(uiM1Lignes, uiM1Colonnes);

				*MATResult = *MatriceArray[nBoucleI - 1] / dValuerC;
				//Afficher le r�sultat de la division de chacune des matrices par la valeur c
				cout << "M" << nBoucleI << " / " << dValuerC  << "= {" << endl;
				MATResult->MATAfficherMatrice();
				delete MATResult;
			}

			//Faire l'addition de toutes les matrices entre elles: M1+M2+M3...
			//Intialiser une matrice pour stocker le r�sultat
			uiM1Lignes = MatriceArray[0]->MATLireNBLignes();
			uiM1Colonnes = MatriceArray[0]->MATLireNBColonnes();
			CMatrice<double> MATResult (uiM1Lignes, uiM1Colonnes);
			MATResult = *MatriceArray[0];
			cout << "M1 +";
			for(int nBoucleI = 2; nBoucleI < argc; nBoucleI++)
			{
				MATResult = MATResult + *MatriceArray[nBoucleI - 1];
				if(nBoucleI == argc-1){
					cout << " M" << nBoucleI;
				}else{
					cout << " M" << nBoucleI << " +";
				}
			}
			cout << " = {" << endl;
			MATResult.MATAfficherMatrice(); 

			//Faire l'op�ration: M1-M2+M3-M4+M5-M6...
			MATResult = *MatriceArray[0];
			for(int nBoucleI = 2; nBoucleI < argc; nBoucleI++)   
			{
				if(nBoucleI % 2 == 0)
					MATResult = MATResult - *MatriceArray[nBoucleI - 1];
				if(nBoucleI % 2 == 1)
					MATResult = MATResult + *MatriceArray[nBoucleI - 1];
			}
			cout << "M1-M2+M3-M4+M5-M6+...=" << endl;	//Afficher le r�sultat de M1-M2+M3-...
			MATResult.MATAfficherMatrice(); 

			//Faire le produit des matrices
			MATResult = *MatriceArray[0];
			for(int nBoucleI = 2; nBoucleI < argc; nBoucleI++){   
				MATResult = MATResult * *MatriceArray[nBoucleI - 1];
			}
			cout << "M1*M2*M3-...=" << endl;	//Afficher le r�sultat du produit des matrices
			MATResult.MATAfficherMatrice(); 

			//Faire la transposition de chacune des matrices
			for(int nBoucleI = 1; nBoucleI < argc; nBoucleI++)
			{
				uiM1Lignes = MatriceArray[nBoucleI - 1]->MATLireNBLignes();
				uiM1Colonnes = MatriceArray[nBoucleI - 1]->MATLireNBColonnes();
				CMatrice<double> *MATResult= new CMatrice<double>(uiM1Lignes, uiM1Colonnes);

				*MATResult = *(MatriceArray[nBoucleI - 1]->MATTransposer());
				cout << "M" << nBoucleI << " Transposee = {" << endl;
				MATResult->MATAfficherMatrice();
				delete MATResult;
			}

		}
		//Attraper les exceptions de op�ration des matrices
		catch(CException EXCLevee) {
			cout << "Exception numero " <<EXCLevee.EXCLireValeur() << ": "<< EXCLevee.EXCLireMessage() << endl;
		}

		//lib�rer la m�moire
		for(int nBoucleI = 1; nBoucleI < argc; nBoucleI++)
			delete MatriceArray[nBoucleI - 1];
		delete[] MatriceArray;

		}
		else{
			cout << "Veuillez entrer des nom de fichier" << endl;
		}
	//Afficher un r�sum� des fuites m�moire
	_CrtDumpMemoryLeaks();
	
	system("pause");
	return 0;
}

