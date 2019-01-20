
#include "stdafx.h"
#include "CException.h"

CException::CException()
{
	uiEXCValeur= 0;
	pcEXCMessage = _strdup("");
}

CException ::CException(const unsigned int uiValeur, char * pcMessage)
{
	uiEXCValeur = uiValeur;
	pcEXCMessage = _strdup(pcMessage);
}

CException ::CException(CException & EXCParam)
{
	uiEXCValeur = EXCParam.uiEXCValeur;
	pcEXCMessage = _strdup(EXCParam.pcEXCMessage);
}

CException :: ~CException()
{
	free(pcEXCMessage);
}

void CException::EXCModifierValeur(unsigned int uiValeur)
{
	uiEXCValeur = uiValeur;
}

unsigned int CException::EXCLireValeur()
{
	return uiEXCValeur;
}

char *  CException::EXCLireMessage()
{
	return pcEXCMessage;
}
