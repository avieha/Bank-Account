#include <stdio.h>
#include "myBank.h"

int main() {
    char c = 'L';
    do{
    double sum=-1;
    int accnum=-1;
    printf("Please choose a transaction type:\n");
    printf(" O-Open Account\n");
    printf(" B-Balance Inquiry\n");
    printf(" D-Deposit\n");
    printf(" W-Withdrawal\n");
    printf(" C-Close Account\n");
    printf(" I-Interest\n");
    printf(" P-Print\n");
    printf(" E-Exit\n");
    scanf(" %c",&c);
    switch(c){
        case 'O': printf("Please enter amount for deposit: ");scanf(" %lf",&sum);if(sum==-1){printf("Failed to read the amount\n");break;};open(sum);break;
        case 'B': printf("Please enter account number: ");scanf(" %d",&accnum);check(accnum);break;
        case 'D': printf("Please enter account number: ");scanf(" %d",&accnum);if(accnum==-1){printf("Failed to read the account number\n");break;};deposit(accnum);break;
        case 'W': printf("Please enter account number: ");scanf(" %d",&accnum);withdraw(accnum);break;
        case 'C': printf("Please enter account number: ");scanf(" %d",&accnum);close(accnum);break;
        case 'I': printf("Please enter interest rate: ");scanf(" %lf",&sum);if(sum==-1){printf("Failed to read the interest rate\n");break;};interest(sum);break;
        case 'P':print();break;
        case 'E':closeall();break;
        default: printf("Invalid transaction type\n");break;
    }if(c!='E'){printf("\n");};
    }while(c!='E');
    return 0;
}

