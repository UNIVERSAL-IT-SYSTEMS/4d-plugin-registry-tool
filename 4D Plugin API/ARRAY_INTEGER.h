/*
 *  ARRAY_INTEGER.h
 *  4D Plugin
 *
 *  Created by miyako on 11/01/03.
 *
 */

#ifndef __ARRAY_INTEGER_H__
#define __ARRAY_INTEGER_H__ 1

#include "4DPluginAPI.h"

#include <vector>

#ifdef __cplusplus
extern "C" {
#endif

class ShortArray
{

private:

	std::vector<short> _ShortArray;
	
public:

	void fromParamAtIndex(PackagePtr pParams, uint32_t index);
	void toParamAtIndex(PackagePtr pParams, uint32_t index);	
	
	void setShortValueAtIndex(short shortValue, uint32_t index);	
	short getShortValueAtIndex(uint32_t index);	
	
	unsigned int getSize();
	void setSize(unsigned int size);
	
	ShortArray();	
	~ShortArray();
		
};

class ARRAY_INTEGER
{

private:

	ShortArray* _ShortArray;
	
public:
 
	void fromParamAtIndex(PackagePtr pParams, uint32_t index);
	void toParamAtIndex(PackagePtr pParams, uint32_t index);	
	
	void setShortValueAtIndex(short shortValue, uint32_t index);	
	short getShortValueAtIndex(uint32_t index);	
	
	unsigned int getSize();
	void setSize(unsigned int size);
	
	ARRAY_INTEGER();
	~ARRAY_INTEGER();

};

#ifdef __cplusplus
}
#endif

#endif