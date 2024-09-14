#include <stdio.h>
#include <time.h>


double getTime(int op){
    if(op == 1){
        clock_t begin = clock();
        int i = 1;
        clock_t end = clock();
        double tempo = (double)(end - begin)/CLOCKS_PER_SEC;
        printf("Tempo do comportamento assintótico 1: %f\n", tempo);
    }

    if(op == 2){
        clock_t begin = clock();
        //int a;
        for(int i=0;i<1000;i++){
            //a = i;
        }
        clock_t end = clock();
        double tempo = (double)(end - begin)/CLOCKS_PER_SEC;
        printf("Tempo do comportamento assintótico n: %f\n", tempo);
    }

    if(op == 3){
        clock_t begin = clock();
        //int a,b;
        for(int i=0;i<1000;i++){
            //a = i;
            for(int j=0;j<1000;j++){
                //b = j;
            }
        }
        clock_t end = clock();
        double tempo = (double)(end - begin)/CLOCKS_PER_SEC;
        printf("Tempo do comportamento assintótico n²: %f\n", tempo);
    }

    if(op == 4){
        clock_t begin = clock();
        //int a,b,c;
        for(int i=0;i<1000;i++){
            //a = i;
            for(int j=0;j<1000;j++){
                //b = j;
                for(int k=0;k<1000;k++){
                    //c = k;
                }
            }
        }
        clock_t end = clock();
        double tempo = (double)(end - begin)/CLOCKS_PER_SEC;
        printf("Tempo do comportamento assintótico n³: %f\n", tempo);
    }
}

int main(){
    getTime(1);
    getTime(2);
    getTime(3);
    getTime(4);

    return 0;
}