// tiles.c
#include <stdio.h>
#include <limits.h>
#define MAX_TILES 20

typedef struct {
	int length,width;
	float price;
} tile_t;

int scan_tiles(tile_t []);
float difference(tile_t [], int);

int main(void) {
	tile_t tiles[MAX_TILES];
	int num_tiles;
	
	num_tiles = scan_tiles(tiles);
	printf("Largest difference = $%.2f\n",
	       difference(tiles, num_tiles));

	return 0;
}

// To read tiles' data into array tiles
// Return the number of tiles read
int scan_tiles(tile_t tiles[]) {
	int num_tiles,i = 0;

	printf("Enter number of tiles: ");
	scanf("%d",&num_tiles);

	printf("Enter data for %d tiles:\n", num_tiles);
	
	for (i = 0;i < num_tiles;i++) {
		scanf("%d %d %f",&tiles[i].length,&tiles[i].width,&tiles[i].price);
	}

	return num_tiles;
}

// Return the difference in cost between 
// the cheapest tile and the most expensive tile.
float difference(tile_t tiles[], int size) {
	int i = 0;
	float max = 0,min = INT_MAX;
	float diff = 0.0;

	for (i = 0;i < size;i++) {
		if (tiles[i].length * tiles[i].width * tiles[i].price > max) {
			max = tiles[i].length * tiles[i].width * tiles[i].price;
		}
	}

	for (i = 0;i < size;i++) {
		if (tiles[i].length * tiles[i].width * tiles[i].price < min) {
			min = tiles[i].length * tiles[i].width * tiles[i].price;
		}
	}

	diff = max - min;

	return diff;
}

