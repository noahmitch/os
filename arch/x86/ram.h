
#ifndef RAM_H
#define RAM_H
	#ifdef __cplusplus
	extern "C" {
	#endif
	#include <stdint.h>
	
	extern uint32_t directory[1024] __attribute__((aligned(4096)));
	
	void initMem ();
	
	extern void loadPageDirectory(uint32_t*);
	extern void enablePaging();
	
	void *getPage ();
	void freePage (void *page);
	
	#ifdef __cplusplus
	}
	#endif
#endif
