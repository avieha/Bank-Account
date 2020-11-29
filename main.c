#include <stdio.h>
#include "myBank.h"

int main() {
    char c = 'L';
    do{
    double sum=-1;
    int accnum=-1;
    printf("'O' - Open a new account\n");
    printf("'B' - check your balance\n");
    printf("'D' - deposit\n");
    printf("'W' - withdraw\n");
    printf("'C' - Close account\n");
    printf("'I' - Add interest to all accounts\n");
    printf("'P' - Print all opened accounts\n");
    printf("'E' - Close all accounts and exit program\n");
    printf("Choose an option:\n");
    scanf(" %c",&c);
    switch(c){
        case 'O': printf("Enter the initial amount:");scanf(" %lf",&sum);open(sum);break;
        case 'B': printf("Enter Account Number:");scanf(" %d",&accnum);check(accnum);break;
        case 'D': printf("Enter Account Number:");scanf(" %d",&accnum);deposit(accnum);break;
        case 'W': printf("Enter Account Number:");scanf(" %d",&accnum);withdraw(accnum);break;
        case 'C': printf("Enter Account Number:");scanf(" %d",&accnum);close(accnum);break;
        case 'I': printf("Enter Intereset percentage:");scanf(" %lf",&sum);interest(sum);break;
        case 'P':print();break;
        case 'E':closeall();break;
        default: printf("Error- wrong char inserted\n");break;
    }
    }while(c!='E');
    return 0;
}

