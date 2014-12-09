/*
 *  C_TEXT.cpp
 *  4D Plugin
 *
 *  Created by miyako on 11/01/03.
 *
 */

#include "C_TEXT.h"

void UString::fromParamAtIndex(PackagePtr pParams, uint32_t index)
{
	if(index)
	{
		PA_Unistring *str = (PA_Unistring *)(pParams[index - 1]);
		
		int len = (str->fLength * 4) + 1;
		
		std::vector<uint8_t> buf(len);
		
		PA_ConvertCharsetToCharset(
			(char *)str->fString, 
			str->fLength*2, 
			eVTC_UTF_16, 
			(char *)&buf[0],
			len, 
			eVTC_UTF_8
			);
		
		this->_UString = std::string((const char *)&buf[0]);
	}
	
}

void UString::toParamAtIndex(PackagePtr pParams, uint32_t index)
{
	if(index)
	{
		int size = this->_UString.length();
		int len = (size * sizeof(PA_Unichar)) + 2;
		
		std::vector<uint8_t> buf(len);
		
		PA_ConvertCharsetToCharset(
			(char *)this->_UString.c_str(),
			size,
			eVTC_UTF_8,
			(char *)&buf[0],
			len,
			eVTC_UTF_16
			);
		
		PA_SetUnistring(
			(PA_Unistring *)(pParams[index - 1]),
			(PA_Unichar *)&buf[0]
			);
	}
}

void UString::setUTF8Bytes(const uint8_t *bytes)
{	
	this->_UString = std::string((const char *)bytes);		
}

void UString::setReturn(sLONG_PTR *pResult)
{
	int size = this->_UString.length();
	int len = (size * sizeof(PA_Unichar)) + 2;
	
	std::vector<uint8_t> buf(len);
	
	PA_ConvertCharsetToCharset(
		(char *)this->_UString.c_str(),
		size,
		eVTC_UTF_8,
		(char *)&buf[0],
		len,
		eVTC_UTF_16
		);

	PA_SetUnistring(
		*(PA_Unistring **) pResult,
		(PA_Unichar *)&buf[0]
		);		
}

const uint8_t *UString::getUTF8Bytes()
{
	return (const uint8_t *)this->_UString.c_str();
}

unsigned int UString::getUTF8BytesLength()
{
	return this->_UString.length();
}

UString::UString()
{	

}

UString::~UString()
{

}

void C_TEXT::fromParamAtIndex(PackagePtr pParams, uint32_t index)
{
	this->_UString->fromParamAtIndex(pParams, index);
}

void C_TEXT::toParamAtIndex(PackagePtr pParams, uint32_t index)
{
	this->_UString->toParamAtIndex(pParams, index);	
}

void C_TEXT::setReturn(sLONG_PTR *pResult)
{
	this->_UString->setReturn(pResult);
}

void C_TEXT::setUTF8Bytes(const uint8_t *bytes)
{
	this->_UString->setUTF8Bytes(bytes);
}

const uint8_t *C_TEXT::getUTF8Bytes()
{
	return this->_UString->getUTF8Bytes();
}

unsigned int C_TEXT::getUTF8BytesLength()
{
	return this->_UString->getUTF8BytesLength();	
}

C_TEXT::C_TEXT() : _UString(new UString)
{
	
}

C_TEXT::~C_TEXT()
{ 
	delete _UString; 
}