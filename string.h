
#ifndef STRING_H
#define STRING_H
#include "memory.h"
#ifdef __cplusplus
extern "C" {
#endif
	class string
	{
	public:
		string (const char *input="");
		void add (char const *newval);
		void set (const char *newval);
		char *c_str ();
		int size ();
		
		char &operator[] (int place);
		void operator= (string input);
		void operator= (const char *input);
	private:
		char *val;
		int length;
	};
#ifdef __cplusplus
}
#endif
#endif
