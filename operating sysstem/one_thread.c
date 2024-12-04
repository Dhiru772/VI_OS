#include<stdio.h>
#include<conio.h>
#include<pthread.h>
#include<dos.h>
void *printNumber(void *arg){
    int i;
    for(i=0;i<5;i++){
        printf("Thread 1:%d\n",i);
        sleep(1);
    }
    pthread_exit(NULL);
}
void *printLetter(void *arg){
    int i;
    char letters[]={'A','B','C','D','E'};
    for(i=0;i<5;i++){
        printf("Thread 2:%c\n",letters[i]);
        sleep(1);
    }
    pthread_exit(NULL);
}
void *printSLetter(void *avg){
    int i;
    char letters[]={'a','b','c','d','e'};
    for(i=0;i<5;i++){
        printf("Thread 3:%c\n",letters[i]);
        sleep(1);
    }
    pthread_exit(NULL);
}
void main(){
    printf("***Dhiraj Sharma***");
    pthread_t thread1,thread2,thread3;
    pthread_create(&thread1,NULL,printNumber,NULL);
    pthread_create(&thread2,NULL,printLetter,NULL);
    pthread_create(&thread3,NULL,printSLetter,NULL);

    pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);
    pthread_join(thread3,NULL);
    getch();

}