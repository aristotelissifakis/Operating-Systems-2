#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

int input(int);
int vector_input(char, int);
pthread_mutex_t mutex ;

void functiontest(int A[], int B[], int count, int n){
        int i, j;
        int local_sum;
        int product;
        for(i = 0;i < count;i++){
                for(j = 0;j < n;j++){
                        product = A[j] + B[j];
                }
        }

}

int input(int i){
        int number;
        if (i == 1){
                printf("Enter threads(if threads are at limit the program will take some time to print the result): ");
                scanf("%d", &number);
        }
        else{
                printf("enter items n for A and B: ");
                scanf("%d", &number);
        }
        return number;
}

int vector_input(char c, int i){
        int number;
        printf("Item %c%d: ", c, i);
        scanf("%d", &number);
        return number;
}
int main(){
        int  p,b,a, n, i;
        int sum=0;
        p = input(1);
        n = input(2);
        int vector_A[n], vector_B[n];

        for(i = 0;i < n; i++){
                a = vector_input('A',i);
                sum = a+sum;
        }
        printf("\n");
        for(i = 0;i < n;i++){
                b = vector_input('B', i);
                sum=sum+b;
        }

        int count = n/p;
        pthread_t tid[p];
        for (i=0;i<p;i++){
        if( pthread_create(&tid[i], NULL, &functiontest, a, b, count, n) != 0 ){
                printf("An error occured");
                exit(1);
        }
        };

        for (i=0;i<p;i++){
        pthread_join (tid[i], NULL);
        
        }
        printf ("The sum is :%d\n",sum);
       pthread_mutex_destroy(&mutex);
        return 0;
}
