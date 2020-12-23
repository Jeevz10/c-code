#include <stdio.h>
#define MAX_PIXELS 20

typedef struct {
	int r,g,b;
} pixel_t;

void scanPixels(pixel_t [],int);
void findMin(pixel_t [],int,int *,int *,int *);
int main(void) {
	int n,   // number of pixels
	    constA, constB, constC, constD;
	int r_min,g_min,b_min;
	pixel_t pixels[MAX_PIXELS];

	scanf("%d %d %d %d %d", &n, &constA, &constB, &constC, &constD);
	scanPixels(pixels,n);

	findMin(pixels,n,&r_min,&g_min,&b_min);

	return 0;
}

void scanPixels(pixel_t pixels[],int size) {
	int i = 0,j = 0;

	for (i = 0;i < size;i++) {
		scanf("%d %d %d",&pixels[i].r,&pixels[i].g,&pixels[i].b);
	}
}

void findMin(pixel_t pixels[],int size,int *r_min,int *g_min,int *b_min) {
	int i = 0,min;

	min = pixels[0].r
	for (i = 1;i < size;i++) {
		if (pixels[i].r < min) {
			min = pixels[i].r;
		}
	}

	*r_min = min;

	min = pixels[0].b

	for (i = 1;i < size;i++) {
		if (pixels[i].b < min) {
			min = pixels[i].b;
		}
	}

	*b_min = min;

	min = pixels[0].g

	for (i = 1;i < size;i++) {
		if (pixels[i].g < min) {
			min = pixels[i].g;
		}
	}

	*g_min = min;
}




