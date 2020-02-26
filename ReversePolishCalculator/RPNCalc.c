//modulus (DONE)
//print top element of stack without popping it (DONE)
//swap the two top elements (DONE)
//clear the stack (DONE)
//add library function for exp, sin, and pow (DONE)
//handling variable commands

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define MAXOP     100    /* max size of operand/operator */
#define NUMBER    '0'     /* signal that a number was found */
#define MAXVAL    100
#define MATH      '1'
#define VARIABLE  '2'

size_t sp = 0;   // aka unsigned long -- printf using %zu
double val[MAXVAL];   // stack of values

char buf[BUFSIZ];
size_t bufp = 0;

int getch_(void) { return (bufp > 0) ? buf[--bufp] : getchar(); }
void ungetch_(int c) {
  if (bufp >= BUFSIZ) { fprintf(stderr, "ungetch: too many characters\n");  return; }
  buf[bufp++] = c;
}

void build_string(char* s){
  int c, i = 0;
  while(isalpha(s[++i] = c = getch_())) { }
  s[i] = '\0';
}

int getop(char* s) {
  int i, c;
  while ((s[0] = c = getch_()) == ' ' || c == '\t') { }  // skip whitespace
  s[1] = '\0';
  if(c == '=' || c == '?') { build_string(s);   return VARIABLE;  }
  if(isalpha(c))            { build_string(s);   return MATH;      }
  if (!isdigit(c) && c != '.') { return c; }  // if not a digit, return

  i = 0;
  if (isdigit(c)) {  // get digits before '.'
    while (isdigit(s[++i] = c = getch_())) { }
  }
  if (c == '.') {    // get digits after decimal (if any)
    while (isdigit(s[++i] = c = getch_())) { }
  }
  s[i] = '\0';
  if (c != EOF) { ungetch_(c); }
  return NUMBER;      // return type is NUMBER, number stored in s
}

double pop(void) {
  if (sp == 0) { fprintf(stderr, "stack underflow\n");  return 0.0; }
  return val[--sp];
}

void push(double f) {
  if (sp == MAXVAL) { fprintf(stderr, "stack overflow -- can't push %g\n", f);  return; }
  val[sp++] = f;
}

void duplicate(void){
  printf("Top value: %.0f\n" , val[sp - 1]);
}

void clear(void){
  sp = 0;
  memset(val, 0, sp);
}

void variable(char *s){
  if(*s == '='){  val[*++s - 'A'] = pop();     }
  else if(*s == '?'){ push(val[*++s - 'A']);   }
}

void math(char *s){
    double op1, op2, result = 0;
    if(strcmp(s, "pow") == 0) {
      op2 = pop();
      op1 = pop();
      result = pow(op1, op2);
  } else if(strcmp(s, "sin") == 0)  { result = sin(pop());
  } else if(strcmp(s, "cos") == 0)  { result = cos(pop());
  } else if(strcmp(s, "exp") == 0)  {
    result = exp(pop());
  } else if(strcmp(s, "tan") == 0)  { result = tan(pop());
  } else if(strcmp(s, "sqrt") == 0) { result = sqrt(pop());
  } else {
    printf("Unknown math operation\n");
  }
  push(result);
  printf("%.3f\n" , result);
}


void rpn(void) {
  int type;
  double op2, op1;
  char s[BUFSIZ];

  while ((type = getop(s)) != EOF) {
    switch(type) {
      case '\n':      printf("\t%.8g\n", pop());  break;
      case NUMBER:    push(atof(s));              break;
      case MATH:      math(s);                    break;
      case VARIABLE:  variable(s);                break;
      case '+':       push(pop() + pop());        break;
      case '*':       push(pop() * pop());        break;
      case '-':       push(-(pop() - pop()));     break;
      case '^':       duplicate();                break;
      case '/':
        if ((op2 = pop()) == 0.0) { fprintf(stderr, "divide by zero\n");  break; }
        push(pop() / op2);
        break;
      case '%':
        if((op2 = pop()) == 0.0) { fprintf(stderr, "divide by zero\n");  break; }
        push(fmod(pop() , op2));
        break;
      case '~':     printf("Duplicating top value.\n");    duplicate();   break;
      case '_':     printf("Clearing stack.\n");           clear();       break;
      case '<':
        op1 = pop();
        op2 = pop();
        push(op2);
        push(op1);
        break;
      default:      fprintf(stderr, "unknown command %s\n", s);  break;
    }
  }
}

int main(int argc, const char * argv[]) {
  rpn();

  return 0;
}
