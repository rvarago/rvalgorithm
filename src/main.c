#include <stdio.h>
#include "rvalgorithm.h"

struct person_t
{
	char name[ 10 ];
	int id;
};

int
id_equals_20( const void *el )
{
	return ( ( const struct person_t * ) el )->id == 20;
}

void
print_square( const void *el )
{
	int el_int = * ( ( const int * ) el );
	printf( "Square of %d = %d\n", el_int, el_int * el_int ); 
}

void 
test_foreach( void )
{
	const int arr[] = { 1, 2, 3, 4 };

	printf( "\n\nTest foreach:\n" );

	foreach( arr, sizeof( int ), 4, print_square );
}

void 
test_find( void )
{
	const struct person_t arr[] = { { "P1", 10 }, { "P2", 20 }, { "P3", 30 }, { "P4", 40 } };
	const void *arr_f = find( arr, sizeof( struct person_t ), 4, id_equals_20 );

	printf( "\n\nTest find:\n" );

	if( arr_f != NULL )
		printf( "El: %s\n", ( ( struct person_t * ) arr_f )->name );
	
}

int main( int argc, char **argv )
{
	test_foreach();
	test_find();
	return 0;
}
