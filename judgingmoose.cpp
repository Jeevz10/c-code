//#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

int main() {

	int left,right;

	scanf("%d %d",&left,&right);

	if (left == 0 && right == 0) {
		printf("Not a moose\n");
	}

	else if (left == right) {
		printf("Even %d\n",2 * left);
	}

	else if (left > right) {
		printf("Odd %d\n",2 * left);
	}
	else if (right > left) {
		printf("Odd %d\n",2 * right);
	}

	return 0;
}
