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
  FILE *fout = fopen(argv[2] , "w");
  const char* names[] = {"NUL", "SOH","STX", "ETX","EOT", "ENQ","ACK", "BEL","BS",
                         "HT","LF", "VT","FF", "CR","SO", "SI","DLE", "DC1","DC2",
                         "DC3","DC4","NAK","SYN", "ETB","CAN", "EM","SUB", "ESC",
                         "FS", "GS","RS", "US"};

  char binaryNums[128][BINARYSIZE + 1]; //creates an array of string size and how many inside
  char string[BINARYSIZE]; //get the strings from this
  char c;
  int stringCounter=0, charCounter =0;
  //read string from the file
  while((c = fgetc(fin)) != EOF){
    if(c != ' ' && c != '\n' && c != '\0'){
      binaryNums[stringCounter][charCounter] = c;
      ++charCounter;
      if(charCounter == BINARYSIZE){
        binaryNums[stringCounter][8] = '\0';
        ++stringCounter;
        charCounter = 0;
      }
    }
  }
  printf("\nORIGINAL\t\tASCII\t\tDECIMAL\t\tPARITY\n");
  for(int j=0; j<128; ++j){
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
  fclose(fin);
  fclose(fout);
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
