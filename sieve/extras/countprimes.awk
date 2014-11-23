# countprimes.awk - look at output from memory display of mford m3 emulator
#   and count the number of primes we found.
# /mrr  2014-11-23
# awk -f /Users/mrr/prog/m3/sieve/extras/countprimes.awk /Users/mrr/prog/m3/sieve/extras/sieve-out.txt 
#
# A correct list of primes less than 40:
#      2      3      5      7     11     13     17     19     23     29 
#     31     37   
{
	for(fld=2; fld<NF; fld=fld+2) {
		first = $(fld)
		second = $(fld+1)
		if(!("ff"==first && "ff"==second) && !("0"==first && "0"==second)) {
		    # Trick to convert hex to binary:
			thisPrime = ("0x" $(fld)) + 0
			primes = primes " " thisPrime 
			nprimes++
		}
	}
}

END {
	print primes
	print "nprimes " nprimes
}
