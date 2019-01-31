/* PRIME EXPLORER
 * General header file
 * ---------------------
 * ict@nfinit.systems
 * 28 January 2019
 */

#ifndef _PRIME_EXPLORER_
#define _PRIME_EXPLORER_
/* [80]********************************************************************** */
/* INCLUDES ----------------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>
/* DEFINES ------------------------------------------------------------------ */
#define VERBOSE_OUTPUT 0
#define BENCHMARK 0
#define PRIME_LIST_SIZE (n/2+1)
#ifndef NULL
#define NULL (void *)0
#endif
/* TYPES -------------------------------------------------------------------- */
enum boolean { FALSE, TRUE };
typedef enum boolean boolean;
/* PROTOTYPES --------------------------------------------------------------- */
long *sieve(long n);
boolean check_sieve(long *primes);
/* [80]********************************************************************** */
#endif
