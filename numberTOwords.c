/*********************************************************************************
**                                                                              **
**      Copyleft 1991-2021 by Sandroid75 with GNU General Public License.       **
**                                                                              **
**                                                                              **
**  Redistribution and use in source and binary forms, with or without          **
**  modification, are permitted provided that the following conditions are met: **
**                                                                              **
**   * Redistributions of source code must retain the above copyleft notice,    **
**     this list of conditions and the following disclaimer.                    **
**   * Redistributions in binary form must reproduce the above copyleft         **
**     notice, this list of conditions and the following disclaimer in the      **
**     documentation and/or other materials provided with the distribution.     **
**   * Neither the name of Sandroid75 nor the names of its contributors may     **
**     be used to endorse or promote products derived from this software        **
**     without specific prior written permission.                               **
**                                                                              **
**  THIS SOFTWARE IS PROVIDED BY THE COPYLEFT HOLDERS AND CONTRIBUTORS "AS IS"  **
**  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE   **
**  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  **
**  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYLEFT OWNER OR CONTRIBUTORS BE     **
**  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR         **
**  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF        **
**  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS    **
**  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN     **
**  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)     **
**  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  **
**  POSSIBILITY OF SUCH DAMAGE.                                                 **
**                                                                              **
**  This code was made by Sandroid75 to illustrate various C language powers.   **
**                                                                              **
**  My recommendations for developing robust C code are:                        **
**  - first of all read The C Programming Language: ANSI C Version by K&R (C)   **
**  - after read K&R keep always in mind rules and methods                      **
**  - one of the most characteristics and powers of the C is the pointers       **
**  - pointers are very helpfull and flexibile to write efficient code          **
**  - pointers can be dangerous for stable code if you forget the rules         **
**  - if you use pointers for list of datas don't forget to reserve memory      **
**  - if you use pointers for list of datas don't forget to release memory      **
**  - write well-formatted code                                                 **
**  - only good formatted code makes the code readable                          **
**  - good formatting code reduces the risk of errors                           **
**  - good formatting code facilitates the debugging                            **
**  - good formatting code facilitates the maintenences                         **
**  - good formatting code facilitates future implementantions                  **
**  - commenting the code is another good and necessary practice                **
**  - commenting the code means understanding what you are doing                **
**  - commenting the code means understanding what you have done                **
**  - commenting the code is not a waste of time                                **
**  - at the last but not least, remember rules and methods                     **
**                                                                              **
**                  Have fun with C programming by Sandroid75                   **
**                                                                              **
**********************************************************************************/

#define _GNU_SOURCE // asprintf()
#include <stdio.h>
#include <stdlib.h>

char *numberTOwords(long number) {
    char *ones[] = {"zero","one", "two", "three", "four", "five", "six", "seven", "eight", "nine", NULL};
    char *teens[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen","sixteen", "seventeen", "eighteen", "nineteen", NULL};
    char *tens[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety", NULL};
    char *str = NULL, *buf1 = NULL, *buf2 = NULL;

    if(number < 10) {
        asprintf(&str, "%s", ones[number]);
    } else if (number < 20L) {
        asprintf(&str, "%s", teens[number - 10]);
    } else if (number < 100L) {
        buf1 = (number % 10 != 0) ? numberTOwords(number % 10L) : "";
        asprintf(&str, "%s %s", tens[number / 10], buf1);
    } else if (number < 1000L) {
        buf1 = numberTOwords(number / 100L);
        buf2 = (number % 100L != 0) ? numberTOwords(number % 100L) : "";
        asprintf(&str, "%s %s %s", buf1, "hundred", buf2);
    } else if (number < 1000000L) {
        buf1 = numberTOwords(number / 1000L);
        buf2 = (number % 1000L != 0) ? numberTOwords(number % 1000L) : "";
        asprintf(&str, "%s %s %s", buf1, "thousand", buf2);
    } else if (number < 1000000000L) {
        buf1 = numberTOwords(number / 1000000L);
        buf2 = (number % 1000000L != 0) ? numberTOwords(number % 1000000L) : "";
        asprintf(&str, "%s %s %s", buf1, "million", buf2);
    } else if (number < 1000000000000L) {
        buf1 = numberTOwords(number / 1000000000L);
        buf2 = (number % 1000000000L != 0) ? numberTOwords(number % 1000000000L) : "";
        asprintf(&str, "%s %s %s", buf1, "billion", buf2);
    } else if (number < 1000000000000000L) {
        buf1 = numberTOwords(number / 1000000000000L);
        buf2 = (number % 1000000000000L != 0) ? numberTOwords(number % 1000000000000L) : "";
        asprintf(&str, "%s %s %s", buf1, "trillion", buf2);
    } else if (number < 1000000000000000000L) {
        buf1 = numberTOwords(number / 1000000000000000L);
        buf2 = (number % 1000000000000000L != 0) ? numberTOwords(number % 1000000000000000L) : "";
        asprintf(&str, "%s %s %s", buf1, "quadrillion", buf2);
    } else {
        asprintf(&str, "%s", "Over quadrillion not supported.");
    }
    if(buf1 && *buf1) free(buf1);
    if(buf2 && *buf2) free(buf2);
    
    return str;
}
