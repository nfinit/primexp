/* PRIME EXPLORER
 * Driver program: 
 * Sieve of Eratosthenes
 * ---------------------
 * ict@nfinit.systems
 * 28 January 2019
 */

/* includes */
#include "primexp.h" 

/* useful definitions */
#define MIN_ARGS 2
#define MAX_ARGS 3
#define IN_RANGE(x) (x < MIN_ARGS || x > MAX_ARGS) 
#define USAGE_STR "usage: sieve <n> [(f)ind|(s)earch]"

/* USAGE STRING PRINTER
 * Prints any usage information for the program
 */
void print_usage ()
{
	printf("%s\n",USAGE_STR);
	return;
}

/* ARGUMENT CHECKER
 * Checks arguments using a preprocessor-defined method based on
 * the values MIN_ARGS and MAX_ARGS
 */
int check_args (int argc)
{
	if IN_RANGE(argc) return 0;
	return 1;
}

/* MAIN FUNCTION
 * Takes program arguments and passes them to core functions
 */
int main (int argc, char *argv[])
{
	/* declare utility variables */
	long n, p, t;
	long *primes;
	long double s;
	boolean fp;

	/* initialize prime list index p, running sum and search state */
	p = 1; s = 0;
	fp = FALSE;

	/* check that correct number of arguments have been supplied */
	if (!check_args(argc)) { print_usage(); return 0; }

	/* parse the arguments */
	n = atol(argv[1]);
	if (argc==MAX_ARGS) if (argv[2][0]=='f'||argv[2][0]=='s') fp = TRUE;
	
	/* generate primes using the sieve algorithm */
	if (fp) {
		t = n;
		n = 4;
		primes = sieve(n); if (!check_sieve(primes)) return 1;
		while (primes[0]<t)
		{
			free(primes);
			n *= 2;
			if (n<4) {
				printf("Overflow detected! halting...\n");
				return 1;
			}
			primes = sieve(n); if (!check_sieve(primes)) return 1;
			#if VERBOSE_OUTPUT==1
			printf("Generated %ld primes (n:%ld)\n",primes[0],n);
			#endif
		}
		/* print nth prime */
		printf("Prime %ld: %ld\n",t,primes[t]);
	} else {
		primes = sieve(n); if (!check_sieve(primes)) return 1;
		/* print contents of resultant array */
		while (primes[p] != 0)
		{
			#if BENCHMARK==0
			printf("%ld ",primes[p]);
			if (p%8==0) printf("\n");
			#endif
			s += primes[p];
			p++;
		}
		/* print summary */
		#if BENCHMARK==0
		printf("\n");
		#endif
		printf("Found %ld prime",p-1);
		if (p-1 != 1) printf("s");
		printf(".\n");
		if (s>0) printf("Total sum: %.0Lf\n",s);
	}

	/* program is done, return status */
	return 0;
}
