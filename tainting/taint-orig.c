#include <stdio.h>
#include <stdlib.h>

int addval (int input, int val, int *val2) {
	int output;

	output = input + val;

	*val2 = output;

	return output;
}

void main (int argc, char *argv[]) {
	int x, y, z, out;

	printf ("Enter an integer: ");
	scanf ("%d", &x);

	if (x < 0) {
		y = addval (x, 10, &z);
	}
	else {
		y = x;
	}

	out = addval (y, 20, &z);

	printf ("The output is: %d\n", out);
	return;
}
