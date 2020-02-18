//take in decimal and convert it to a binary number
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BINARYSIZE 8

void decToBinary(char change[], int number);

int main(int argc, const char* argv[]){
  char binaryNum[BINARYSIZE] = {'0','0','0','0','0','0','0','0'};
  char final[BINARYSIZE];
  char test[BINARYSIZE];
  int number = 0;
  for(int number = 0; number < 128; ++number){
    if(number % 8 == 0){
      printf("\n");
    }
  for(int i = 0; i < BINARYSIZE; ++i){
    decToBinary(binaryNum, number);
    printf("%c" , binaryNum[i]);
  }
    printf(" ");
}
  return 0;
}

void decToBinary(char change[], int number){
  int check[BINARYSIZE] = {128, 64, 32, 16, 8, 4, 2, 1};
  for(int i = 0; i < BINARYSIZE; ++i){
    if(number >= check[i]){
      change[i] = 1 + '0';
      number -= check[i];
    } else {
      change[i] = '0';
    }
  }
}
