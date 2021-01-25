#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TRUE 1
#define FALSE 0

// Struct to be used for taint tracking of integer variables.
struct taintint {
	int val;    // Actual value
  int taint;  // TRUE means tainted, FALSE is untainted.
};

int addval (int input, int val, int *val2) {
	int output;

	output = input + val;

	*val2 = output;

	return output;
}

void main (int argc, char *argv[]) {
	struct taintint x, y, z, out;

	printf ("Enter an integer: ");
	scanf ("%d", &x.val);
	x.taint = TRUE; // Initialization at taint source has been done for you.

	if (x.val < 0) {
		y.val = addval (x.val, 10, &(z.val));
	}
	else {
		y.val = x.val;
	}

	out.val = addval (y.val, 20, &(z.val));

	printf ("The output is: %d\n", out.val);
	printf ("The taint values are x.taint = %d, y.taint = %d, z.taint = %d, out.taint = %d\n",
					 x.taint, y.taint, z.taint, out.taint);
	return;
}
