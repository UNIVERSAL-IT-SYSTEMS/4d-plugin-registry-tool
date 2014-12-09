/*
 *  ARRAY_REAL.h
 *  4D Plugin
 *
 *  Created by miyako on 11/01/03.
 *
 */

#ifndef __ARRAY_REAL_H__
#define __ARRAY_REAL_H__ 1

#include "4DPluginAPI.h"

#include <vector>

#ifdef __cplusplus
extern "C" {
#endif

class DoubleArray
{

private:

	std::vector<double> _DoubleArray;
	
public:

	void fromParamAtIndex(PackagePtr pParams, uint32_t index);
	void toParamAtIndex(PackagePtr pParams, uint32_t index);	
	
	void setDoubleValueAtIndex(double doubleValue, uint32_t index);	
	double getDoubleValueAtIndex(uint32_t index);	
	
	unsigned int getSize();
	void setSize(unsigned int size);
	
	DoubleArray();	
	~DoubleArray();
		
};

class ARRAY_REAL
{

private:

	DoubleArray* _DoubleArray;
	
public:
 
	void fromParamAtIndex(PackagePtr pParams, uint32_t index);
	void toParamAtIndex(PackagePtr pParams, uint32_t index);	
	
	void setDoubleValueAtIndex(double doubleValue, uint32_t index);	
	double getDoubleValueAtIndex(uint32_t index);	
	
	unsigned int getSize();
	void setSize(unsigned int size);
	
	ARRAY_REAL();
	~ARRAY_REAL();

};

#ifdef __cplusplus
}
#endif

#endif