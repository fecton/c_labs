#include <stdio.h>
#include <limits.h>
#include <float.h>

// short, unsigned int, int
// double
int main(void){
    puts("+---------+-----+---------+---------+------------+-----------+------------+");
    puts("|     Type     |Bytes| Min DEC    | Min HEX     | Max DEC    |  Max HEX   |");
    puts("+---------+-----+---------+---------+------------+-----------+------------+");
    printf("|     short    |  %ld  | %d     | 0x%x  | %d      |   0x%x   |\n",
            sizeof(short),  SHRT_MIN, SHRT_MIN, SHRT_MAX, SHRT_MAX);

    puts("+---------+-----+---------+---------+------------+-----------+------------+");
    printf("| unsgined int |  %ld  | %d          |    0x%x      | %u | 0x%x |\n",
            sizeof(unsigned int), 0, 0, UINT_MAX, UINT_MAX);

    puts("+---------+-----+---------+---------+------------+-----------+------------+");
    printf("|     int      |  %ld  | %d| 0x%x  | %d | 0x%x |\n",
            sizeof(int), INT_MIN, INT_MIN, INT_MAX, INT_MAX);

    puts("+---------+-----+---------+---------+------------+-----------+------------+\n\n");


    puts("+---------+-----+-------------------+------------------------+");
    puts("| Type   | Bytes | Min Value         | Max Value             |");
    puts("+---------+-----+-------------------+------------------------+");
    printf("| double |   %ld   | %.10e | %.10e     |\n",
           sizeof(double), DBL_MIN, DBL_MAX);
    puts("+---------+-----+-------------------+------------------------+");
}


