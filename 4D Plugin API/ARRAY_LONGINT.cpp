/*
 *  ARRAY_LONGINT.cpp
 *  4D Plugin
 *
 *  Created by miyako on 11/01/03.
 *
 */

#include "ARRAY_LONGINT.h"

void IntArray::fromParamAtIndex(PackagePtr pParams, uint32_t index)
{	
	if(index)		
	{
		PA_Variable arr = *((PA_Variable*) pParams[index - 1]);
		
		if(arr.fType == eVK_ArrayLongint)
		{
			this->setSize(0);
			
			unsigned int i;
			
			int intValue;
			
			for(i = 0; i <= (unsigned int)arr.uValue.fArray.fNbElements; i++)
			{
				intValue = ( * (int**) (arr.uValue.fArray.fData) )[i];
				this->_IntArray.push_back(intValue);				
			}
			
		}
		
	}
			
}

void IntArray::toParamAtIndex(PackagePtr pParams, uint32_t index)
{
	if(index)		
	{
		PA_Variable arr = *((PA_Variable*) pParams[index - 1]);
		
		if(arr.fType == eVK_ArrayLongint)
		{
			
			PA_ResizeArray(&arr, this->_IntArray.empty() ? 0 : (this->_IntArray.size() - 1));
			
			unsigned int i;
			
			for(i = 0; i < this->_IntArray.size(); i++)
			{
				PA_SetLongintInArray(arr, i, this->_IntArray.at(i));	
			}
			
			PA_Variable *param = ((PA_Variable *)pParams[index - 1]);
			
			param->fFiller = 0;
			param->uValue.fArray.fCurrent = arr.uValue.fArray.fCurrent;
			param->uValue.fArray.fNbElements = arr.uValue.fArray.fNbElements;
			param->uValue.fArray.fData = arr.uValue.fArray.fData;	
			
		}
		
	}
				
}

void IntArray::setIntValueAtIndex(int intValue, uint32_t index)
{
	if(index < this->_IntArray.size())
	{
		
		std::vector<int>::iterator it = this->_IntArray.begin();
		it += index;
		
		this->_IntArray.insert(this->_IntArray.erase(it), intValue);
		
	}
}

int IntArray::getIntValueAtIndex(uint32_t index)	
{
	
	int intValue = 0;
	
	if(index < this->_IntArray.size())
	{
		
		intValue = this->_IntArray.at(index);
	}
	
	return intValue;
	
}

unsigned int IntArray::getSize()
{
	return this->_IntArray.size();
}

void IntArray::setSize(unsigned int size)
{
	this->_IntArray.resize(size);
}

IntArray::IntArray()
{	

}

IntArray::~IntArray()
{

}

void ARRAY_LONGINT::fromParamAtIndex(PackagePtr pParams, uint32_t index)
{
	_IntArray->fromParamAtIndex(pParams, index);	
}

void ARRAY_LONGINT::toParamAtIndex(PackagePtr pParams, uint32_t index)
{
	_IntArray->toParamAtIndex(pParams, index);	
}

void ARRAY_LONGINT::setIntValueAtIndex(int intValue, uint32_t index)
{
	_IntArray->setIntValueAtIndex(intValue, index);		
}

int ARRAY_LONGINT::getIntValueAtIndex(uint32_t index)
{
	return this->_IntArray->getIntValueAtIndex(index);	
}

unsigned int ARRAY_LONGINT::getSize()
{
	return this->_IntArray->getSize();		
}

void ARRAY_LONGINT::setSize(unsigned int size)
{
	_IntArray->setSize(size);		
}

ARRAY_LONGINT::ARRAY_LONGINT() : _IntArray(new IntArray)
{
	
}

ARRAY_LONGINT::~ARRAY_LONGINT()
{ 
	delete _IntArray; 
}