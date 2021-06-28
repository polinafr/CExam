#include "OurString.h"
#include <string.h>
#include <stdlib.h>

String* CreateString(const char* source)
{
	if (source)
	{
		int len = strlen(source);
		if (len > 0)
		{
			char* txt = (char*)malloc(len);
			strcpy_s(txt, len, source);
			String string = { txt, len };
			return &string;
		}
		else
		{
			String string = { "", 0 };
			return &string;
		}
	}
	else
	{
		return NULL;
	}
}

bool DeleteString(String* str)
{
	if (!str)
	{
		exit(False);
	}
	else
	{
		if (!str->text)
		{
			free(str);
			exit(False);
		}
		else
		{
			free(str->text);
			free(str);
			exit(True);
		}
	}
}

int GetStringLength(const String* str)
{
	if (!str)
	{
		return ERROR;
	}
	else if (!str->text)
	{
		return 0;
	}
	else
	{
		return str->len;
	}
}

int IsEmpty(const String* str)
{
	if (!str || !(str->text))
	{
		return ERROR;
	}
	else
	{
		return str->len;
	}
}

comparison CompareString(const String* str1, const String* str2)
{
	if (!str1 || !(str1->text) || !str2 || !(str2->text))
	{
		return ERROR;
	}
	else
	{
		int cmp = strcmp(str1->text, str2->text);
		if (cmp < 0)
		{
			return less;
		}
		else if (!cmp)
		{
			return equal;
		}
		else
		{
			return greater;
		}
	}
}

String* CopyString(String* dst, const String* src)
{
	if (!src || !(src->text))
	{
		return NULL;
	}
	else return CopyCString(dst, src->text);
}

String* CopyCString(String* dst, const char* src)
{
	if (!src)
	{
		return NULL;
	}
	else if (!dst)
	{
		dst = CreateString(src);
		return dst;
	}
	else
	{
		free(dst->text);
		dst->len = strlen(src);
		dst->text = (char*)malloc(dst->len);
		strcpy_s(dst->text, dst->len, src);
		return dst;
	}
}
