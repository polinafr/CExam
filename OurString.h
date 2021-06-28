#ifndef __cplusplus
typedef unsigned char bool;
static const bool False = 0;
static const bool True = 1;
#endif

typedef unsigned int size_t;
#define ERROR -1000 
#define NULL 0

typedef char comparison;
static const comparison greater = 1;
static const comparison equal = 0;
static const comparison less = -1;

#ifdef OurString
#undef OurString
#endif
#define OurString
struct String_t
{
	char* text;
	size_t len;
};

typedef struct String_t String;

String* CreateString(const char* source);
bool DeleteString(String* str);
int GetStringLength(const String* str);
int IsEmpty(const String* str);
comparison CompareString(const String* str1, const String* str2);
String* CopyString(String* dst, const String* src);
String* CopyCString(String* dst, const char* src);
