//first convert all the string into an int
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define BINARYSIZE 8
int stringToInt(char * string);
char intToAscii(int AssVal);

int main(int argc, const char* argv[]){
  FILE *fin = fopen(argv[1] , "r");
  bool check;
  const char* names[] = {"NUL", "SOH","STX", "ETX","EOT", "ENQ","ACK", "BEL","BS",
                         "HT","LF", "VT","FF", "CR","SO", "SI","DLE", "DC1","DC2",
                         "DC3","DC4","NAK","SYN", "ETB","CAN", "EM","SUB", "ESC",
                         "FS", "GS","RS", "US"};

  char binaryNums[10][BINARYSIZE + 1]; //creates an array of string size and how many inside
  char string[BINARYSIZE]; //get the strings from this
  char c;
  /*if(argc != 2){ //if there is no file and from user input into console
  for(int i = 0; i < 4; ++i){ //for loop to get the strings of binary numbers inputted
      printf("Enter the binary number: ");
      scanf("%s" , binaryNums[i]);
      binaryNums[i][9] = '\0';
  }
  printf("\nORIGINAL\t\tASCII\t\tDECIMAL\t\tPARITY\n");
  for(int j=0; j<4; ++j){
  int asciiNum = stringToInt(binaryNums[j]);
  char asciiChar = intToAscii(asciiNum);
  if(asciiNum < 32){
  if(asciiNum % 2 != 0){
  printf("%s\t\t%s\t\t%d\t\t%s\n" , binaryNums[j] , names[asciiNum] , asciiNum , "ODD");
  } else {
  printf("%s\t\t%s\t\t%d\t\t%s\n" , binaryNums[j] , names[asciiNum] , asciiNum , "EVEN");
  }
} else {
  if(asciiNum % 2 != 0){
  printf("%s\t\t%c\t\t%d\t\t%s\n" , binaryNums[j] , asciiChar , asciiNum , "ODD");
  } else {
  printf("%s\t\t%c\t\t%d\t\t%s\n" , binaryNums[j] , asciiChar , asciiNum , "EVEN");
  }
}
}
} else {  */
  for(int i = 0; i < 10; ++i){ //for loop to get the strings of binary numbers inputted
      for(int k = 0; k < 10 && ((c = fgetc(fin)) != EOF); ++k){
        binaryNums[k][BINARYSIZE + 1] = '\0';
        for(int j = 0; j < BINARYSIZE + 1; ++j){
          binaryNums[k][j] = c;
        }
      }
  }
  for(int j = 0; j < 10; ++j){
    printf("%s\n" , binaryNums[j]);
  }
  /*printf("\nORIGINAL\t\tASCII\t\tDECIMAL\t\tPARITY\n");
  for(int j=0; j<4; ++j){
  int asciiNum = stringToInt(binaryNums[j]);
  char asciiChar = intToAscii(asciiNum);
  if(asciiNum < 32){
  if(asciiNum % 2 != 0){
  printf("%s\t\t%s\t\t%d\t\t%s\n" , binaryNums[j] , names[asciiNum] , asciiNum , "ODD");
  } else {
  printf("%s\t\t%s\t\t%d\t\t%s\n" , binaryNums[j] , names[asciiNum] , asciiNum , "EVEN");
  }
} else {
  if(asciiNum % 2 != 0){
  printf("%s\t\t%c\t\t%d\t\t%s\n" , binaryNums[j] , asciiChar , asciiNum , "ODD");
  } else {
  printf("%s\t\t%c\t\t%d\t\t%s\n" , binaryNums[j] , asciiChar , asciiNum , "EVEN");
  }
}
}
}*/
  return 0;
}


int stringToInt(char * string){
  int total = 0;
  for(int i = 1; i < strlen(string); ++i){
    total += (string[i] - '0') * pow(2 , strlen(string) - i - 1);
  }
  return total;
}

char intToAscii(int AssVal){
  char ascii = AssVal;
  return ascii;
}
