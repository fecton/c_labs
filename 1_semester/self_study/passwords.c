#include <math.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    FILE *file_laptop, *file_rasp, *file_android;
    
    file_laptop = fopen("passwords_laptop.txt", "w");
    file_rasp = fopen("passwords_rasp.txt", "w");
    file_android = fopen("passwords_android.txt", "w");
	
    // 10000000 - min number
    // 100000000 - max number

    unsigned int number, highest_rank, s=0;


    for(int number=0;number<10000000;number++){
        // for laptop (much power than others)
        for(highest_rank=1;highest_rank<5;highest_rank++){
            s = highest_rank*10000000+number;
            printf("Laptop: %u\n", s);
            fprintf(file_laptop, "%u\n", s);
        }
        
        // for raspberry pi
        for(highest_rank=5;highest_rank<8;highest_rank++){
            s = highest_rank*10000000+number;
            printf("Rasp: %u\n", s);
            fprintf(file_rasp, "%u\n", s);
        }       
        
        // for smartphone
        for(highest_rank=8;highest_rank<10;highest_rank++){
            s = highest_rank*10000000+number;
            printf("Android: %u\n", s);
            fprintf(file_android, "%u\n", s);
        }

    }
    
    fclose(file_laptop);
    fclose(file_rasp);
    fclose(file_android);


    return 0;
}
