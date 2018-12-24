/*
* rvalgorithm.c
* @author rvarago
*/

#include "rvalgorithm/rvalgorithm.h"

void
foreach( const void *collection, size_t size, size_t nelems, processor_t processor )
{
	const char *base = ( const char * ) collection;
	int i;

	for( i = 0; i < nelems; ++i )
	{
		processor( base );
		base += size;
	}
}

const void*
find( const void *collection, size_t size, size_t nelems, predicate_t pred )
{
	const char *base = ( const char * ) collection;
	int i;

	for( i = 0; i < nelems && pred( base ) == 0; ++i )
	{
		base += size;
	}
	
	return i < nelems ? base : NULL ;
}
