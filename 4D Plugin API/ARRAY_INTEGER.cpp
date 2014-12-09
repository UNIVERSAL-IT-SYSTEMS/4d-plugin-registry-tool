/*
 *  ARRAY_INTEGER.cpp
 *  4D Plugin
 *
 *  Created by miyako on 11/01/03.
 *
 */

#include "ARRAY_INTEGER.h"

void ShortArray::fromParamAtIndex(PackagePtr pParams, uint32_t index)
{	
	if(index)		
	{
		PA_Variable arr = *((PA_Variable*) pParams[index - 1]);
		
		if(arr.fType == eVK_ArrayInteger)
		{
			this->setSize(0);
			
			unsigned int i;
			
			short shortValue;
			
			for(i = 0; i <= (unsigned int)arr.uValue.fArray.fNbElements; i++)
			{
				shortValue = ( * (short**) (arr.uValue.fArray.fData) )[i];
				this->_ShortArray.push_back(shortValue);				
			}
			
		}
		
	}
			
}

void ShortArray::toParamAtIndex(PackagePtr pParams, uint32_t index)
{
	if(index)		
	{
		PA_Variable arr = *((PA_Variable*) pParams[index - 1]);
		
		if(arr.fType == eVK_ArrayInteger)
		{
			
			PA_ResizeArray(&arr, this->_ShortArray.empty() ? 0 : (this->_ShortArray.size() - 1));
			
			unsigned int i;
			
			for(i = 0; i < this->_ShortArray.size(); i++)
			{
				PA_SetIntegerInArray(arr, i, this->_ShortArray.at(i));	
			}
			
			PA_Variable *param = ((PA_Variable *)pParams[index - 1]);
			
			param->fFiller = 0;
			param->uValue.fArray.fCurrent = arr.uValue.fArray.fCurrent;
			param->uValue.fArray.fNbElements = arr.uValue.fArray.fNbElements;
			param->uValue.fArray.fData = arr.uValue.fArray.fData;	
			
		}
		
	}
				
}

void ShortArray::setShortValueAtIndex(short shortValue, uint32_t index)
{
	if(index < this->_ShortArray.size())
	{
		
		std::vector<short>::iterator it = this->_ShortArray.begin();
		it += index;
		
		this->_ShortArray.insert(this->_ShortArray.erase(it), shortValue);
		
	}
}

short ShortArray::getShortValueAtIndex(uint32_t index)
{
	
	short shortValue = 0;
	
	if(index < this->_ShortArray.size())
	{
		
		shortValue = this->_ShortArray.at(index);
	}
	
	return shortValue;
	
}

unsigned int ShortArray::getSize()
{
	return this->_ShortArray.size();
}

void ShortArray::setSize(unsigned int size)
{
	this->_ShortArray.resize(size);
}

ShortArray::ShortArray()
{	

}

ShortArray::~ShortArray()
{

}

void ARRAY_INTEGER::fromParamAtIndex(PackagePtr pParams, uint32_t index)
{
	_ShortArray->fromParamAtIndex(pParams, index);	
}

void ARRAY_INTEGER::toParamAtIndex(PackagePtr pParams, uint32_t index)
{
	_ShortArray->toParamAtIndex(pParams, index);	
}

void ARRAY_INTEGER::setShortValueAtIndex(short shortValue, uint32_t index)
{
	_ShortArray->setShortValueAtIndex(shortValue, index);		
}

short ARRAY_INTEGER::getShortValueAtIndex(uint32_t index)
{
	return this->_ShortArray->getShortValueAtIndex(index);	
}

unsigned int ARRAY_INTEGER::getSize()
{
	return this->_ShortArray->getSize();		
}

void ARRAY_INTEGER::setSize(unsigned int size)
{
	_ShortArray->setSize(size);		
}

ARRAY_INTEGER::ARRAY_INTEGER() : _ShortArray(new ShortArray)
{
	
}

ARRAY_INTEGER::~ARRAY_INTEGER()
{ 
	delete _ShortArray; 
}