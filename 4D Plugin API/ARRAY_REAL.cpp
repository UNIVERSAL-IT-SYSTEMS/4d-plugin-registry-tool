/*
 *  ARRAY_REAL.cpp
 *  4D Plugin
 *
 *  Created by miyako on 11/01/03.
 *
 */

#include "ARRAY_REAL.h"

void DoubleArray::fromParamAtIndex(PackagePtr pParams, uint32_t index)
{	
	if(index)		
	{
		PA_Variable arr = *((PA_Variable*) pParams[index - 1]);
		
		if(arr.fType == eVK_ArrayReal)
		{
			this->setSize(0);
			
			unsigned int i;
			
			double doubleValue;
			
			for(i = 0; i <= (unsigned int)arr.uValue.fArray.fNbElements; i++)
			{
				doubleValue = ( * (double**) (arr.uValue.fArray.fData) )[i];
				this->_DoubleArray.push_back(doubleValue);				
			}
			
		}
		
	}
			
}

void DoubleArray::toParamAtIndex(PackagePtr pParams, uint32_t index)
{
	if(index)		
	{
		PA_Variable arr = *((PA_Variable*) pParams[index - 1]);
		
		if(arr.fType == eVK_ArrayReal)
		{
			
			PA_ResizeArray(&arr, this->_DoubleArray.empty() ? 0 : (this->_DoubleArray.size() - 1));
			
			unsigned int i;
			
			for(i = 0; i < this->_DoubleArray.size(); i++)
			{
				PA_SetRealInArray(arr, i, this->_DoubleArray.at(i));	
			}
			
			PA_Variable *param = ((PA_Variable *)pParams[index - 1]);
			
			param->fFiller = 0;
			param->uValue.fArray.fCurrent = arr.uValue.fArray.fCurrent;
			param->uValue.fArray.fNbElements = arr.uValue.fArray.fNbElements;
			param->uValue.fArray.fData = arr.uValue.fArray.fData;	
			
		}
		
	}
				
}

void DoubleArray::setDoubleValueAtIndex(double doubleValue, uint32_t index)
{
	if(index < this->_DoubleArray.size())
	{
		
		std::vector<double>::iterator it = this->_DoubleArray.begin();
		it += index;
		
		this->_DoubleArray.insert(this->_DoubleArray.erase(it), doubleValue);
		
	}
}

double DoubleArray::getDoubleValueAtIndex(uint32_t index)	
{
	
	double doubleValue = 0;
	
	if(index < this->_DoubleArray.size())
	{
		
		doubleValue = this->_DoubleArray.at(index);
	}
	
	return doubleValue;
	
}

unsigned int DoubleArray::getSize()
{
	return this->_DoubleArray.size();
}

void DoubleArray::setSize(unsigned int size)
{
	this->_DoubleArray.resize(size);
}

DoubleArray::DoubleArray()
{	

}

DoubleArray::~DoubleArray()
{

}

void ARRAY_REAL::fromParamAtIndex(PackagePtr pParams, uint32_t index)
{
	_DoubleArray->fromParamAtIndex(pParams, index);	
}

void ARRAY_REAL::toParamAtIndex(PackagePtr pParams, uint32_t index)
{
	_DoubleArray->toParamAtIndex(pParams, index);	
}

void ARRAY_REAL::setDoubleValueAtIndex(double doubleValue, uint32_t index)
{
	_DoubleArray->setDoubleValueAtIndex(doubleValue, index);		
}

double ARRAY_REAL::getDoubleValueAtIndex(uint32_t index)
{
	return this->_DoubleArray->getDoubleValueAtIndex(index);	
}

unsigned int ARRAY_REAL::getSize()
{
	return this->_DoubleArray->getSize();		
}

void ARRAY_REAL::setSize(unsigned int size)
{
	_DoubleArray->setSize(size);		
}

ARRAY_REAL::ARRAY_REAL() : _DoubleArray(new DoubleArray)
{
	
}

ARRAY_REAL::~ARRAY_REAL()
{ 
	delete _DoubleArray; 
}