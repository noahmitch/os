
#include "memory.h"
#include "ram.h"

int liballoc_lock ()
{
	return 0;
}

int liballoc_unlock ()
{
	return 0;
}

void *liballoc_alloc (int pages) // todo allocate pages in ram header
{
	uint32_t *list[1024];
	for (int i = 0; i < pages; i++)
	{
		list[i] = getPage ();
	}
	return &list;
}

int liballoc_free (void* ptr, int pages)
{
	for (int i = 0; i < pages; i++)
	{
		freePage (&ptr[i]);
	}
	return 0;
}
