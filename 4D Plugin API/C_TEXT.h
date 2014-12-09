/*
 *  C_TEXT.h
 *  4D Plugin
 *
 *  Created by miyako on 11/01/03.
 *
 */

#ifndef __C_TEXT_H__
#define __C_TEXT_H__ 1

#include "4DPluginAPI.h"
#include <string>

#ifdef __cplusplus
extern "C" {
#endif

class UString
{

private:
	
	std::string _UString;		
	
public:

	void fromParamAtIndex(PackagePtr pParams, uint32_t index);
	void toParamAtIndex(PackagePtr pParams, uint32_t index);	
	void setReturn(sLONG_PTR *pResult);	
	
	void setUTF8Bytes(const uint8_t *bytes);
	const uint8_t *getUTF8Bytes();
	unsigned int getUTF8BytesLength();	
	
	UString();	
	~UString();
		
};

class C_TEXT
{

private:

	UString* _UString;

public:
 
	//	4D (UTF-16) interface
	void fromParamAtIndex(PackagePtr pParams, uint32_t index);
	void toParamAtIndex(PackagePtr pParams, uint32_t index);	
	void setReturn(sLONG_PTR *pResult);		
	
	//	UTF-8 interface
	void setUTF8Bytes(const uint8_t *bytes);	
	const uint8_t *getUTF8Bytes();
	unsigned int getUTF8BytesLength();		
		
	C_TEXT();
	~C_TEXT();

};

#ifdef __cplusplus
}
#endif

#endif