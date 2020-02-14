//take in decimal and convert it to a binary number
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BINARYSIZE 8


int main(int argc, const char* argv[]){
  int number = 50;
  char binaryNum[BINARYSIZE] = {'0','0','0','0','0','0','0','0'};
  int binChecker[BINARYSIZE] = {128, 64, 32, 16, 8, 4, 2, 1};
  int i = BINARYSIZE - 1;
  while(i >= 0){  
    if(number >= binChecker[i]){
      binaryNum[i] = '1';
      number -= binChecker[i];
      --i;
      printf("%d" , number);
    }
  }

  return 0;
}
