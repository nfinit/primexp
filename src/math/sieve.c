/* PRIME EXPLORER
 * Generator algorithm:
 * Sieve of Eratosthenes
 * ---------------------
 * ict@nfinit.systems
 * 28 January 2019
 */
#include "primexp.h"
/* [80]********************************************************************** */
long *sieve(long n)
{
    /* VARIABLE, LIST DECLARATIONS AND INITIALIZATION *********************** */
    boolean *list;     /* a list of all integers from 2 to n ---------------- */
    long  *primes;   /* list of found primes -------------------------------- */
    static long invalid[1]; /* an invalid array for error checking ---------- */
    long i, m;       /* re-usable looping utility variables ----------------- */
    long p, f;       /* current/candidate prime, total number of found primes */
    /* Variable initialization ---------------------------------------------- */
    invalid[0] = -1; /* invalid array only contains -1 ---------------------- */
    f = 0;           /* initialize the prime counter ------------------------ */
    /* List allocation ------------------------------------------------------ */
    list = malloc((n+1)*sizeof(boolean)); /* n+1 so we can index by p ------- */
    if (list==NULL) {
        printf("ERROR: Could not allocate memory for integer list!\n");
        return invalid;
    }
    primes = malloc(PRIME_LIST_SIZE*sizeof(long)); /* see primexp.h --------- */
    if (primes==NULL) {
        printf("ERROR: Could not allocate memory for prime number list!\n");
        return invalid;
    }
    /* List initialization -------------------------------------------------- */
    for (i=0; i<n+1; i++) list[i] = TRUE; /* set all indexes in list to true  */
    for (i=0; i<PRIME_LIST_SIZE; i++) primes[i] = 0; /* zero all entries - */
    /* ********************************************************************** */
    /* ////////////////////////////////////////////////////////////////////// */
    /* SIEVE PROCESS ******************************************************** */
    for (p=2; p<n; p++)
    {
        if (list[p]==FALSE) continue; /* current value of p is not prime ---- */
	f++; primes[f] = p; /* current value of p is prime; add to the list - */
        for (m=2; m*p<n; m++) list[m*p] = FALSE; /* find more non-primes ---- */
    }
    /* ********************************************************************** */
    /* ////////////////////////////////////////////////////////////////////// */
    /* CLEANUP AND RESULT RETURN ******************************************** */
    free(list); primes[0]=f; return primes;
    /* END OF FUNCTION******************************************************* */
}
/* [80]********************************************************************** */
boolean check_sieve(long *primes)
{
	boolean state;
	state = TRUE;
	if (primes==NULL) state = FALSE;
	if (primes[0]<0) state = FALSE;
	if (!state) printf("ERROR: Prime list failed integrity check!\n");
	return state;
}
/* [80]********************************************************************** */
