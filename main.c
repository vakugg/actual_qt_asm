#include <stdio.h>
#include <time.h>
#include <stdint.h>
#include <stdlib.h>
#include <windows.h>

#define FIND_ASSEMBLER_FILE "C:\Users\Admin\Documents\rebuild_asm_test\find_assembler.s"

#define moloko_size 5*1024*1024/4
#define reg_quant 5




uint32_t LRD_rand(uint32_t *our_arr)
{

    uint32_t seed_holder = *our_arr;


    // Algorithm "xor" from p. 4 of Marsaglia, "Xorshift RNGs"

    seed_holder ^= seed_holder << 13;

    seed_holder ^= seed_holder >> 17;

    seed_holder ^= seed_holder << 5;



    *our_arr = seed_holder;



    return(seed_holder);
}





int main()
{
    printf("Hello World!\n");

    // time vars
        clock_t strt_time, fin_time;     double rslt;
        uint32_t* DWN_range;
        uint32_t* UP_range;



        uint32_t* moloko = malloc(moloko_size * sizeof(uint32_t*));
        if (moloko == NULL) exit(911);

        DWN_range = moloko;
        UP_range = moloko + moloko_size - 1;

        //std::cout << DWN_range << " - " << UP_range<< std::endl;
        //printf();

        //for (int i=0; i < moloko_size-1; i++) DWN_range++;
        //std::cout << DWN_range << " - " << UP_range << std::endl;






        strt_time = clock();// обходим адреса внутри


        uint32_t adr_hldr= (uint32_t)DWN_range; // потому,что static внутри блока нельзя по какой-то причине - понятия не имею по какой
        for (int i = 0; i < moloko_size; i++)
        {
            uint32_t* strt_rmbrr = DWN_range;
            uint32_t temp = LRD_rand(&adr_hldr) ;// получаем интовое смещение - temp ведёт себя непонятно как


            for (uint32_t j = 0; j < temp; j++) // смещаемся
            {
                strt_rmbrr++;
            }

            //get_call_adress(); //сам файл не трогал - или цикл не в порядке, или отладчик врёт


        }

        fin_time = clock();




        rslt = (double)((fin_time - strt_time) / CLOCKS_PER_SEC);




    return 0;
}
