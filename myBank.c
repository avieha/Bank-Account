#include <stdio.h>
double accounts[2][50] = {0};
int counter=0;

void open(double sum){
    if(sum<0){
    printf("the sum entered is wrong\n");
    return;
    }
    if(counter==49){
    printf("Opening an account is not possible- there are more than 50 accounts\n");
    return;
}
    int temp=0;
    for (int i = 0; i < 50; i++) {
        if(accounts[1][i]==0){
        temp=i;
        break;
        }
    }
    accounts[0][temp]=sum;
    accounts[1][temp]=1;
    printf("Your new account number is:%d\n",temp+901);
    printf("Your balance is:%0.2lf\n",accounts[0][temp]);
    counter++;
    return;
}

void check(int accountnum){
    if(accountnum<901 || accountnum>950){
    printf("wrong account number entered\n");
    return;
    };
    if(accounts[1][accountnum-901]==0){
        printf("This account is closed\n");
        return;
    }
    printf("Your balance is:%0.2lf\n",accounts[0][accountnum-901]);
return;
}

void deposit(int accountnum){
    double sum=-1;
    if(accountnum>950 || accountnum<901){
    printf("Wrong account number\n");
    return;
    }
    if(accounts[1][accountnum-901]==0){
        printf("This account is closed\n");
        return;
    }
    printf("Enter Sum:");
    scanf(" %lf",&sum);
    if(sum<0){
    printf("Wrong number entered\n");
    return;
    }
    accounts[0][accountnum-901]+=sum;
    printf("Your new balance is:%0.2lf\n",accounts[0][accountnum-901]);
    return;
}

void withdraw(int accountnum){
    double sum=-1;
    if(accountnum>950 || accountnum<901){
    printf("Wrong account number\n");
    return;
    }
    if(accounts[1][accountnum-901]==0){
        printf("This account is closed\n");
        return;
    }
    printf("Enter Sum:");
    scanf(" %lf",&sum);
    if(sum<0 || sum>accounts[0][accountnum-901]){
    printf("withdraw is not possible\n");
    return;
    }
    accounts[0][accountnum-901]-=sum;
    printf("current balance:%0.2lf\n",accounts[0][accountnum-901]);
    return;
}

void close(int accountnum){
    if(accountnum>950 || accountnum<901){
    printf("Wrong account number\n");
    return;
    }
    if(accounts[1][accountnum-901]==0){
        printf("This account is already closed\n");
        return;
    }
    accounts[0][accountnum-901]=0;
    accounts[1][accountnum-901]=0;
    counter--;
    return;
}

void interest(double intr){
if(intr<0){
printf("wrong number entered\n");
return;
}
    for (int i = 0; i < 50; i++) {
        if(accounts[1][i]==1){
        accounts[0][i]*=1+(intr/100.0);
        }
    }
    return;
}

void print(){
    for (int i = 0; i < 50; i++) {
        if(accounts[1][i]==1){
        printf("Account number:%d the balance is:%0.2lf\n",i+901,accounts[0][i]);
        }
    }
    return;
}

void closeall(){
    for (int i = 0; i < 50; i++) {
        accounts[1][i]=0;
        accounts[0][i]=0;
    }
    counter=0;
    printf("All accounts have been closed.\n");
    return;
}
