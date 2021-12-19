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
