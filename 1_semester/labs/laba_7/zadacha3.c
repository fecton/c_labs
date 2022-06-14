#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    double start_value, step_change, value_count, result;
    int i=0;

    printf("Enter start value, step_change and value count:\n");
    scanf("%lf%lf%lf", &start_value, &step_change, &value_count);

    result=start_value;

    if( step_change <= 0 ){
        printf("[-] The impossible number!");
        exit(-1);
    }

    do
    {
        result += 11.4;
        i += step_change;
    } while (i<value_count);
    
    printf("%.lf", result);

    return 0;
}


