/*
 *  ARRAY_TEXT.cpp
 *  4D Plugin
 *
 *  Created by miyako on 11/01/03.
 *
 */

#include "ARRAY_TEXT.h"

void UStringArray::fromParamAtIndex(PackagePtr pParams, uint32_t index)
{	
	if(index)		
	{
		PA_Variable arr = *((PA_Variable*) pParams[index - 1]);
		
		if(arr.fType == eVK_ArrayUnicode)
		{
			this->setSize(0);
			
			unsigned int i;
			
			PA_Unistring str;
			
			for(i = 0; i <= (unsigned int)arr.uValue.fArray.fNbElements; i++)
			{				
				str = (*(PA_Unistring **) (arr.uValue.fArray.fData))[i];
				
				int len = (str.fLength * 4) + 1;
				
				std::vector<uint8_t> buf(len);
					
				PA_ConvertCharsetToCharset(
					(char *)str.fString, 
					str.fLength*2, 
					eVTC_UTF_16, 
					(char *)&buf[0],
					len, 
					eVTC_UTF_8
					);
				
				this->_UStringArray.push_back(std::string((const char *)&buf[0]));
				
			}
			
		}

	}
	
}

void UStringArray::toParamAtIndex(PackagePtr pParams, uint32_t index)
{
	if(index)		
	{
		PA_Variable arr = *((PA_Variable*) pParams[index - 1]);
		
		if(arr.fType == eVK_ArrayUnicode)
		{
			
			PA_ResizeArray(&arr, this->_UStringArray.empty() ? 0 : (this->_UStringArray.size() - 1));
			
			unsigned int i;
			
			for(i = 0; i < this->_UStringArray.size(); i++)
			{
				
				int size = this->_UStringArray.at(i).length();
				int len = (size * sizeof(PA_Unichar)) + 2;
				
				std::vector<uint8_t> buf(len);

				PA_ConvertCharsetToCharset(
					(char *)this->_UStringArray.at(i).c_str(),
					size,
					eVTC_UTF_8,
					(char *)&buf[0],
					len,
					eVTC_UTF_16
					);
				
				PA_Unistring str = PA_CreateUnistring((PA_Unichar *)&buf[0]);
				PA_SetStringInArray(arr, i, &str);					

			}
			
			PA_Variable *param = ((PA_Variable *)pParams[index - 1]);
			
			param->fFiller = 0;
			param->uValue.fArray.fCurrent = arr.uValue.fArray.fCurrent;
			param->uValue.fArray.fNbElements = arr.uValue.fArray.fNbElements;
			param->uValue.fArray.fData = arr.uValue.fArray.fData;			
			
		}
		
	}
	
}

void UStringArray::setUTF8BytesAtIndex(const uint8_t *bytes, uint32_t index)
{

	if(index < this->_UStringArray.size())
	{
		
		const std::string str = std::string((const char *)bytes);
		
		std::vector<std::string>::iterator it = this->_UStringArray.begin();
		it += index;

		this->_UStringArray.insert(this->_UStringArray.erase(it), str);
	
	}

}

const uint8_t *UStringArray::getUTF8BytesAtIndex(uint32_t index)
{
	
	uint8_t *str = NULL;
	
	if(index < this->_UStringArray.size())
	{
	
		str = (uint8_t *)this->_UStringArray.at(index).c_str();
	}
	
	return str;
	
}

unsigned int UStringArray::getSize()
{
	return this->_UStringArray.size();
}

void UStringArray::setSize(unsigned int size)
{
	this->_UStringArray.resize(size);
}

UStringArray::UStringArray()
{	

}

UStringArray::~UStringArray()
{

}

void ARRAY_TEXT::fromParamAtIndex(PackagePtr pParams, uint32_t index)
{
	_UStringArray->fromParamAtIndex(pParams, index);	
}

void ARRAY_TEXT::toParamAtIndex(PackagePtr pParams, uint32_t index)
{
	_UStringArray->toParamAtIndex(pParams, index);	
}

void ARRAY_TEXT::setUTF8BytesAtIndex(const uint8_t *bytes, uint32_t index)
{
	_UStringArray->setUTF8BytesAtIndex(bytes, index);		
}

const uint8_t *ARRAY_TEXT::getUTF8BytesAtIndex(uint32_t index)
{
	return this->_UStringArray->getUTF8BytesAtIndex(index);	
}

unsigned int ARRAY_TEXT::getSize()
{
	return this->_UStringArray->getSize();		
}

void ARRAY_TEXT::setSize(unsigned int size)
{
	_UStringArray->setSize(size);		
}

ARRAY_TEXT::ARRAY_TEXT() : _UStringArray(new UStringArray)
{
	
}

ARRAY_TEXT::~ARRAY_TEXT()
{ 
	delete _UStringArray; 
}