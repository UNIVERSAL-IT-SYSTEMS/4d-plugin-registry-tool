/*
 *  ARRAY_TEXT.h
 *  4D Plugin
 *
 *  Created by miyako on 11/01/03.
 *
 */

#ifndef __ARRAY_TEXT_H__
#define __ARRAY_TEXT_H__ 1

#include "4DPluginAPI.h"

#include <string>
#include <vector>

#ifdef __cplusplus
extern "C" {
#endif

class UStringArray
{

private:

	std::vector<std::string> _UStringArray;
	
public:

	void fromParamAtIndex(PackagePtr pParams, uint32_t index);
	void toParamAtIndex(PackagePtr pParams, uint32_t index);	
	
	void setUTF8BytesAtIndex(const uint8_t *bytes, uint32_t index);	
	const uint8_t *getUTF8BytesAtIndex(uint32_t index);	
	
	unsigned int getSize();
	void setSize(unsigned int size);
	
	UStringArray();	
	~UStringArray();
		
};

class ARRAY_TEXT
{

private:

	UStringArray* _UStringArray;
	
public:
 
	//	4D (UTF-16) interface
	void fromParamAtIndex(PackagePtr pParams, uint32_t index);
	void toParamAtIndex(PackagePtr pParams, uint32_t index);	
	
	//	UTF-8 interface
	void setUTF8BytesAtIndex(const uint8_t *bytes, uint32_t index);	
	const uint8_t *getUTF8BytesAtIndex(uint32_t index);	

	unsigned int getSize();
	void setSize(unsigned int size);
	
	ARRAY_TEXT();
	~ARRAY_TEXT();

};

#ifdef __cplusplus
}
#endif

#endif