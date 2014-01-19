/* Warshall-floyd algorithm
 *
 * Shortest path between all pairs of vertices
 * strategy: dynamic programming
 * order: n **3
 */

#include <limits.h>
#include <stdio.h>

typedef int	adj_matrix [10][10];

#define MAX_VERTEX	9

#define FOUND 0

adj_matrix gr = {
		{ 0, 5, 3, INT_MAX, 2 },
		{ INT_MAX, 0, 2, 6, INT_MAX },
		{ INT_MAX, 1, 0, 2, INT_MAX },
		{ INT_MAX, INT_MAX, INT_MAX, 0, INT_MAX },
		{ INT_MAX, 6, 10, 4, 0 }
	};
	//	This directed graph has five vertices.

#define NUM_VERT	5
	// as on gr

char first_hop[NUM_VERT][NUM_VERT];
	// first_hop[i][j] contains the first hop in the path between i and j


void warshall() {

	int k,i,j;
	int hopdist;

	for( k = 0; k < NUM_VERT; k ++ ) {

		for( i = 0; i < NUM_VERT; i ++ ) {	// row index

			for( j = 0; j < NUM_VERT; j ++ ) {	// column index
				
				if(gr[i][k] == INT_MAX || gr[k][j] == INT_MAX ) 
					hopdist = INT_MAX;
				else					// can hop to k
					hopdist = gr[i][k] + gr[k][j];
				
				if( hopdist < gr[i][j]) { // if hopping to k is better
					first_hop[i][j] = k;		// if you want to go from i to j then first go to k
					gr[i][j] = hopdist;
				}
			}
		}
	}
}


void print_first_hop() {

	int i,j;
	for( i = 0; i < NUM_VERT; i ++ ) {
		for( j = 0 ; j < NUM_VERT; j ++ ) 
			printf("%d ",first_hop[i][j]);
	
		printf("\n");
	}
			
}

int main() {

	int i, j;
	for( i = 0; i < NUM_VERT; i ++ ) {
		
		for( j = 0; j < NUM_VERT; j ++ ) {
			
			if( gr[i][j] != INT_MAX )	// if edge exists
				first_hop[i][j] = j;
			else first_hop[i][j] = -1;	// not known yet
		}
		
	}
	warshall();
	printf("the first hop in the shortest path from any vertex i to j is \n");
	print_first_hop();
}
