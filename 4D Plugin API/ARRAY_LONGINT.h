/*
 *  ARRAY_LONGINT.h
 *  4D Plugin
 *
 *  Created by miyako on 11/01/03.
 *
 */

#ifndef __ARRAY_LONGINT_H__
#define __ARRAY_LONGINT_H__ 1

#include "4DPluginAPI.h"

#include <vector>

#ifdef __cplusplus
extern "C" {
#endif

class IntArray
{

private:

	std::vector<int> _IntArray;
	
public:

	void fromParamAtIndex(PackagePtr pParams, uint32_t index);
	void toParamAtIndex(PackagePtr pParams, uint32_t index);	
	
	void setIntValueAtIndex(int intValue, uint32_t index);	
	int getIntValueAtIndex(uint32_t index);	
	
	unsigned int getSize();
	void setSize(unsigned int size);
	
	IntArray();	
	~IntArray();
		
};

class ARRAY_LONGINT
{

private:

	IntArray* _IntArray;
	
public:
 
	void fromParamAtIndex(PackagePtr pParams, uint32_t index);
	void toParamAtIndex(PackagePtr pParams, uint32_t index);	
	
	void setIntValueAtIndex(int intValue, uint32_t index);	
	int getIntValueAtIndex(uint32_t index);	
	
	unsigned int getSize();
	void setSize(unsigned int size);
	
	ARRAY_LONGINT();
	~ARRAY_LONGINT();

};

#ifdef __cplusplus
}
#endif

#endif