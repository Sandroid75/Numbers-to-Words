/************************************************************************
**                                                                     **
**  Copyleft 1991-2022 by Sandroid75 with GNU General Public License.  **
**                                                                     **
*************************************************************************/

#include <stdio.h>
#include <stdlib.h>

char *numberTOwords(long number);

int main() {
    //Get input number from user
    long num;
    char *str;
    
    // convert given number in words
    while(1) {
        printf("Number: ");
        scanf("%ld", &num);
        if(num < 0) {
            break;
        }
        str = numberTOwords(num);
        printf("Words:\t%s\n", str);
        free(str);
    }
    
    return 0;
}
