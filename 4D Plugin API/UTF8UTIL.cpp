/*
 *  UTF8UTIL.cpp
 *  4D Plugin
 *
 *  Created by miyako on 11/01/18.
 *  Copyright 2011 miyako. All rights reserved.
 *
 */


#include "UTF8UTIL.h"

int UTF8UTIL::Munger(PA_Handle h, unsigned int offset, const uint8_t *str1, const uint8_t *str2)
{
	
	//	this is a C++ replacement for the 10.6 deprecated Munger function
	
	
	std::string str;
	std::string src;
	std::string dst;
	
	str = std::string(*h, PA_GetHandleSize(h));
	src = (const char *)str1;
	dst = (const char *)str2;
	
	int pos = str.find(src, (size_t)offset);
	
	if(pos > 0)
	{	
		str.replace(pos, src.length(), dst);
		PA_SetHandleSize(h, str.length());
		void *p = PA_LockHandle(h);
		PA_MoveBlock((void *)str.c_str(), p, str.length());
		PA_UnlockHandle(h);
	}
	
	return pos;	
	
}


bool UTF8UTIL::_EqualString(const uint8_t *str1, const uint8_t *str2, bool diacSensitive)
{
	
	std::string string1;
	std::string string2;
	
	string1 = (const char *)str1;
	string2 = (const char *)str2;
	
	int size1 = string1.length();
	int len1 = (size1 * sizeof(PA_Unichar)) + 2;

	int size2 = string2.length();
	int len2 = (size2 * sizeof(PA_Unichar)) + 2;	
	
	std::vector<uint8_t> buf1(len1);
	std::vector<uint8_t> buf2(len2);	
	
	PA_ConvertCharsetToCharset(
							   (char *)string1.c_str(),
							   size1,
							   eVTC_UTF_8,
							   (char *)&buf1[0],
							   len1,
							   eVTC_UTF_16
							   );
	
	PA_ConvertCharsetToCharset(
							   (char *)string2.c_str(),
							   size2,
							   eVTC_UTF_8,
							   (char *)&buf2[0],
							   len2,
							   eVTC_UTF_16
							   );
	
	return (PA_CompareUnichars((PA_Unichar *)&buf1[0], (PA_Unichar *)&buf2[0], diacSensitive, NULL) == 0);
	
}


bool UTF8UTIL::EqualString(const uint8_t *str1, const uint8_t *str2)
{
	
	return _EqualString(str1, str2, false);
	
}


bool UTF8UTIL::EqualStringDiacritical(const uint8_t *str1, const uint8_t *str2)
{
	
	return _EqualString(str1, str2, true);
	
}


UTF8UTIL::UTF8UTIL()
{ 
	
}


UTF8UTIL::~UTF8UTIL()
{ 
	
}