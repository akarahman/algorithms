/*
 * Problem: Solve a multiplication expression by using only additions, subtractions and/or bit shifting.
 * Input: positive integers
 */ 

/*
 * Requires: mcand and mplier are non-negative integers
 *           cache is a mcand x mplier matrix
 * Modifies: cache
 * Effects: returns mcand * mplier
 */
int mult_helper (int mcand, int mplier, int** cache);

/*
 * Requires: mcand and mplier are positive integers
 * Effects: returns mcand * mplier
 */
int multiply (int mcand, int mplier);
