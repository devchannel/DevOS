#include <stdio.h>
#include <string.h>

#include <drivers/screen.h>

int puts(const char* str)
{
	kprint(str);
  kprint("\n");
	return strlen(str);
}
