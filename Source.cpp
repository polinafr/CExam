#include "OurString.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define FirstTestString "Gaudeamus igitur, Iuvenes dum sumus"
#define EmptyString ""
#define SECOND_TEST_STRING "Draco dormiens nunquam tititlandus"
void main()
{
	char* str1 = (char*)malloc(strlen(FirstTestString));
	strcpy_s(str1, strlen(FirstTestString), FirstTestString);
	String* FString = CreateString(str1);
	printf(FString->text);
	printf("%d", FString->len);

	String* SecondTestString = CreateString(SECOND_TEST_STRING);

	String* ErrorString = CreateString(EmptyString);
	printf("%d", ErrorString->len);

	printf("%d", IsEmpty(ErrorString));
	printf("%d", IsEmpty(FString));
	printf("%d", IsEmpty(NULL));

	printf("%d", GetStringLength(ErrorString));
	printf("%d", GetStringLength(FString));

	//printf("%d", CompareString(NULL, ));

	printf("%d", DeleteString(FString));
	printf("%d", DeleteString(ErrorString));

	



}
