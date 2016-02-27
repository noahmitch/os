
#include "ram.h"

uint32_t directory[1024] __attribute__((aligned(4096)));

void initMem ()
{
	unsigned int i = 0;
	uint32_t firstPageTable[1024] __attribute__((aligned(4096)));

	for (i = 0; i < 1024; i++)
	{
		directory[i] = 0x00000002;
		firstPageTable[i] = (i * 0x1000) | 3;
	}
	directory[0] = ((unsigned int)firstPageTable) | 3;
	loadPageDirectory(directory);
	enablePaging();
}

void *getPage ()
{
	for (int i = 0; i < 1024; i++)
	{
		if (directory[i] == 0x00000002)
		{
			return &directory[i];
		}
	}
}

void freePage (void *page)
{
	uint32_t t = 0x00000002;
	page = &t;
}
