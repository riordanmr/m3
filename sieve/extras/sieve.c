/* The Sieve of Eratosthenes
 * based on: http://www.programminglogic.com/the-sieve-of-eratosthenes-implemented-in-c/
 * mrr   2014-11-22
 * cc -o sieve sieve.c && ./sieve
 */
#include <stdio.h>

#define LIMIT 200

int main() 
{
    int i,j,numbers[LIMIT],thisnum,nprimes;

    /*fill the array with natural numbers*/
    for (i=0;i<LIMIT;i++) {
        numbers[i]=i+2;
    }

    /*sieve the non-primes*/
    for (i=0;i<LIMIT;i++){
        if (numbers[i]!=-1){
            thisnum = numbers[i];
            j = thisnum + thisnum - 2;
            for (; j<LIMIT; j+=thisnum) {
                numbers[j]=-1;
            }
        }
    }

    /*count the number of primes*/
    nprimes = 0;
    j = 0;
    for (i=0;i<LIMIT;i++) {
        if (numbers[i]!=-1) {
        	nprimes++;
        	printf("%d ", numbers[i]);
        }
    }
    printf("\n");
    printf("# of primes=%d\n", nprimes);
	return 0;
}
