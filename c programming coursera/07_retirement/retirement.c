#include<stdlib.h>
#include<stdio.h>
double get_balance(double get_balance, double rate);
struct _retire_info{
  int months;
  double contribution;
  double rate_of_return;
};
typedef struct _retire_info retire_info;
void retirement(int startAge, double initial, retire_info working, retire_info retired){
  for(int i=0;i<working.months; i++){
    printf("Age %3d month %2d you have $%.2f\n", (startAge/12),(startAge%12),initial);
    initial=get_balance(initial,working.rate_of_return)+working.contribution;
    startAge++;
  }
  for(int i=0;i<retired.months; i++){
    printf("Age %3d month %2d you have $%.2f\n",(startAge/12),(startAge%12),initial);
    initial = get_balance(initial,retired.rate_of_return)+retired.contribution;
    startAge++;
  }
}
double get_balance(double balance,double rate_of_return){
  return balance *(1+rate_of_return/12);
}
int main(void){
  retire_info working = {489,1000,0.045};
  retire_info retired = {384,-4000, 0.01};
  retirement(327, 21345, working, retired);
  return EXIT_SUCCESS;
}
								
