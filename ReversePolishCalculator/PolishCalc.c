/* 4.3 (DONE)
   4.4 (DONE)
   4.5
   4.6  */
#include <stdio.h>
#include <stdlib.h> // for atof()
#include <ctype.h>
#include <math.h>


#define MAXOP 100 //max size of operand or operator
#define NUMBER '0' //signal that a number was found
#define MAXVAL 100 //max depth of val stack
#define BUFSIZE 100 //size of buffer

int sp = 0;  //next free stack position
double val[MAXVAL]; //value stack
char buf[BUFSIZE]; //buffer for ungetch
int bufp = 0; //next free position in buffer

//main functions
int getop(char[]);  //get next character or numeric operand
void push(double); //push f onto value stack
double pop(void); //pop and return top value from stack
void duplicate(void); //print the top element of stack without popping it to duplicate
void swap(void); //swap the top two elements
void clear(void); //clear the stack


//functions for getop()
int getch(void); //get a (possibly pushed-back) character
void ungetch(int); //push character back on input


//Reverese polish calculator
int main(int argc, const char* argv[]){
  int type, var = 0;
  double op2,v;
  char s[MAXOP];
  double variable[26];

  while((type = getop(s)) != EOF){
    switch (type) {
      case NUMBER:
        push(atof(s)); //converts string argument into a floating pt number(double)
        break;
      case '+':
        push(pop() + pop());
        break;
      case '*':
        push(pop() * pop());
        break;
      case '-':
        op2 = pop();
        push(pop() - op2);
        break;
      case '/':
        op2 = pop();
        if(op2 != 0.0)
          push(pop() / op2);
        else
          printf("error: unknown command %s\n" , s);
        break;
      case '%':
        op2 = pop();
        if(op2 != 0.0)
          push(fmod(pop() ,op2));
        else
          printf("error: zero divisor\n");
        break;
      case '~':
          printf("Duplicating top value.\n");
          duplicate();
        break;
      case '^':
          printf("Swapping the top two elements.\n");
          swap();
        break;
      case '#':
          printf("clearing the stack.\n");
          clear();
        break;
      case '!':
          op2 = pop();
          push(sin(op2));
        break;
      case 'e':
          op2 = pop();
          push(exp(op2));
        break;
      case 'p':
          op2 = pop();
          push(pow(pop(), op2));
        break;
      case '=':
          pop();
          if(var>='A' && var <='Z')
            variable[var-'A']=pop();
          else
            printf("error: novariablename\n");
        break;
      case'\n':
        printf("\t%.8g\n" , pop());
        break;
      default:
        printf("error: unknown command %s\n" , s);
    }
  }
  return 0;
}


void push(double f){
  if(sp < MAXVAL)
    val[sp++] = f;
  else
    printf("error: stack full, can't push %g\n", f);
}


double pop(void){
  if(sp > 0)
    return val[--sp];
  else{
    printf("error: stack empty\n");
    return 0.0;
  }
}


int getop(char s[]){
  int i, c;
  while((s[0] = c = getch()) == ' ' || c == '\t');
  s[1] = '\0';
  if(!isdigit(c) && c != '.')
    return c; //not a number
  i = 0;
  if(isdigit(c))
    while(isdigit(s[++i] = c = getch()));
  if(c == '.')
    while(isdigit(s[++i] = c = getch()));
    s[i] = '\0';
  if(c != EOF)
    ungetch(c);
  return NUMBER;
}

double sin(double f){
  double sin_value = sin(f);
  return sin_value;
}

int getch(void){
  return(bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c){
  if(bufp >= BUFSIZE)
    printf("ungetch: too many characters\n");
  else
    buf[bufp++] = c;
}


void duplicate(void){
  printf("Top value: %f" , val[sp - 1]);
}

void clear(void){
  if(sp = 0){
    printf("the stack is already empty.");
  } else {
    while(--sp >= 0){
      val[sp] = 0.0;
    }
  }
  sp = 0;
}


void swap(void){
  double swap;
  int i;
    if(sp < 2){
      printf("error: not enough values to swap");
    }
    else{
      i = sp - 1;
      swap = val[i];
      val[i] = val[i - 1];
      val[i - 1] = swap;
    }
  printf("swapped: %f %f", val[i], val[i-1]);
}
