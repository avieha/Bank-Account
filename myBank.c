#include <stdio.h>
#define size 50
double accounts[2][size] = {0};
int counter=0;

void open(double sum){
    if(sum<0){
    printf("Invalid Amount\n");
    return;
    }
    if(counter==49){
    printf("Opening an account is not possible- there are more than 50 accounts\n");
    return;
}
    int temp=0;
    for (int i = 0; i < size; i++) {
        if(accounts[1][i]==0){
        temp=i;
        break;
        }
    }
    accounts[0][temp]=sum;
    accounts[1][temp]=1;
    printf("New account number is: %d \n",temp+901);
    counter++;
    return;
}

void check(int accountnum){
    if(accountnum<901 || accountnum>950){
    printf("Failed to read the account number\n");
    return;
    };
    if(accounts[1][accountnum-901]==0){
        printf("This account is closed\n");
        return;
    }
    printf("The balance of account number %d is: %0.2lf\n",accountnum,accounts[0][accountnum-901]);
return;
}

void deposit(int accountnum){
    double sum=-1;
    if(accountnum>950 || accountnum<901){
    printf("Invalid account number\n");
    return;
    }
    if(accounts[1][accountnum-901]==0){
        printf("This account is closed\n");
        return;
    }
    printf("Please enter the amount to deposit: ");
    scanf(" %lf",&sum);
    if(sum<0){
    printf("Cannot deposit a negative amount\n");
    return;
    }
    accounts[0][accountnum-901]+=sum;
    printf("The new balance is: %0.2lf\n",accounts[0][accountnum-901]);
    return;
}

void withdraw(int accountnum){
    double sum=-1;
    if(accountnum>950 || accountnum<901){
    printf("Invalid account number\n");
    return;
    }
    if(accounts[1][accountnum-901]==0){
        printf("This account is closed\n");
        return;
    }
    printf("Please enter the amount to withdraw: ");
    scanf(" %lf",&sum);
    if(sum<0){
    printf("Cannot withdraw a negative amount\n");
    return;
    }
    if(sum>accounts[0][accountnum-901]){
    printf("Cannot withdraw more than the balance\n");
    return;
    }
    accounts[0][accountnum-901]-=sum;
    printf("The new balance is: %0.2lf\n",accounts[0][accountnum-901]);
    return;
}

void close(int accountnum){
    if(accountnum>950 || accountnum<901){
    printf("Invalid account number\n");
    return;
    }
    if(accounts[1][accountnum-901]==0){
        printf("This account is already closed\n");
        return;
    }
    accounts[0][accountnum-901]=0;
    accounts[1][accountnum-901]=0;
    counter--;
    printf("Closed account number %d\n",accountnum);
    return;
}

void interest(double intr){
if(intr<0){
printf("Invalid interest rate\n");
return;
}
    for (int i = 0; i < size; i++) {
        if(accounts[1][i]==1){
        accounts[0][i]*=1+(intr/100.0);
        }
    }
    return;
}

void print(){
    for (int i = 0; i < size; i++) {
        if(accounts[1][i]==1){
        printf("The balance of account number %d is: %0.2lf\n",i+901,accounts[0][i]);
        }
    }
    return;
}

void closeall(){
    for (int i = 0; i < size; i++) {
        accounts[1][i]=0;
        accounts[0][i]=0;
    }
    counter=0;
    return;
}
