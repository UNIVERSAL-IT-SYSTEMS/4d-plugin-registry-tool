/*
 *  UTF8UTIL.h
 *  4D Plugin
 *
 *  Created by miyako on 11/01/18.
 *  Copyright 2011 miyako. All rights reserved.
 *
 */

#ifndef __UTF8UTIL_H__
#define __UTF8UTIL_H__ 1

#include "4DPluginAPI.h"
#include <string>

#ifdef __cplusplus
extern "C" {
#endif

class UTF8UTIL
{
	
	private:
	
		bool _EqualString(const uint8_t *str1, const uint8_t *str2, bool diacSensitive);
	
	public:
		
		bool EqualString(const uint8_t *str1, const uint8_t *str2);
		bool EqualStringDiacritical(const uint8_t *str1, const uint8_t *str2);
		int Munger(PA_Handle h, unsigned int offset, const uint8_t *str1, const uint8_t *str2);
		UTF8UTIL();
		~UTF8UTIL();
		
};

#ifdef __cplusplus
}
#endif

#endif