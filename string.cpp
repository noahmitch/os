
#include "string.h"


string::string (const char *input)
{
	val = 0;
	length = 0;
	set (input);
}

void string::add (char const *newval)
{
	char *tmpval = val;
	int x = 0;
	while (newval[x] != '\0')
	{
		x++;
	}
	
	val = (char*)realloc (val, length + x);
	for (int i = 0; i < length; i++)
	{
		val[i] = tmpval[i];
	}
	for (int i = 0; i < x; i++)
	{
		val[length+i] = newval[i];
	}
	length += x;
}

void string::set (const char *newval)
{
	int x = 0;
	while (newval[x] != '\0')
	{
		x++;
	}
	val = (char*)realloc (val, x);
	for (int i = 0; i < x; i++)
	{
		val[i] = newval[i];
	}
	length = x;
}

char *string::c_str ()
{
	return val;
}

int string::size ()
{
	return length;
}

char &string::operator[] (int place)
{
	return val[place];
}
void string::operator= (string input)
{
	set (input.c_str ());
}

void string::operator= (const char *input)
{
	set (input);
}

string string::operator+ (string input)
{
	string out = val;
	out.add (input.c_str ());
	return out;
}

string string::operator+ (char *input)
{
	string out = val;
	out.add (input);
	return out;
}
