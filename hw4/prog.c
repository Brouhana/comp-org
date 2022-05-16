/*
 * prog.c
 *
 * This program creates an array of 10,000 random integers, sorts it
 * using bubble sort, then checks to make sure it is sorted.
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * This function performs bubble sort on an array v[] of n integers
 */
void bubble_sort (int v[], int n) {
	int	i,	// outer loop counter
		j,	// inner loop counter
		t,	// temporary used for swapping
		swapped;// Boolean variable that means swapping has occured


	// do this at most n times

	for (i=0; i<n; i++) {

		// we haven't swapped anything yet, so set swapped to false

		swapped = 0;

		// go through the array, swapping elements that are
		// out of order

		for (j=1; j<n; j++) {

			// if the j'th and j-1'th elements of v are
			// out of order...
			if (v[j-1] > v[j]) {

				// ... then swap them

				t = v[j];
				v[j] = v[j-1];
				v[j-1] = t;

				// indicate that we have swapped so that
				// the outer loop should continue

				swapped = 1;
			}
		}

		// if no element was out of order, then we are done

		if (!swapped) break;
	}
}

/*
 * This function returns 1 if an array v[] of n integers is in sorted
 * order, 0 otherwise
 */
int check_sorted (int v[], int n) {
	int	i; // loop counter

	// for every adjacent pair of positions in the array

	for (i=1; i<n; i++)

		// return 0 if this pair of elements is out of order

		if (v[i-1] > v[i]) return 0;

	// nothing was out of order, so return 1

	return 1;
}

int numbers[10000]; // array of 10,000 integers to be filled in main()

/*
 * main function
 */
int main () {
	int	i;

	// fill the numbers array with random numbers

	for (i=0; i<10000; i++) numbers[i] = rand ();

	// sort the array

	bubble_sort (numbers, 10000);

	// check to make sure they are sorted

	if (check_sorted (numbers, 10000))
		printf ("numbers are sorted\n");
	else
		printf ("numbers are not sorted\n");

	// all done

	exit (0);
}
