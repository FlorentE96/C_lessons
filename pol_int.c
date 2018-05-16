#include <stdio.h> // For printf and scanf
#include <stdlib.h>
#include <string.h> // For strcmp
#include <math.h> // For sqrt

#define MAX_ORDER (8)

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

static inline int flush() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF);
}

float elmt_integr(float a, float b, const float * coeff, int order);
float poly(const float * coeff, int order, float x);

int main(int argc, char *argv[]) {
  printf("Please enter the polynomial coefficients (enter a letter when you want to stop):\n\r");
  float coeff[MAX_ORDER] = {0,};
  int order = 0;

  int ret = 1;
  
  do{
    printf("c%d = ", order);
    ret = scanf("%f", &coeff[order++]);
    if(!ret) {
      order--;
      break;
    }
  } while(order < MAX_ORDER);
  
  order--;
  printf(ANSI_COLOR_YELLOW "\n\r\tf(x) = ");
  for(int i=order;i>0;i--) {
    printf("%.2f*x^%d + ", coeff[i], i);
  }
  printf("%.2f\n\r\n\r" ANSI_COLOR_RESET, coeff[0]);

  flush();
  
  float a = 0, b = 0;
  
  printf("Please enter a: ");
  scanf("%f", &a);

  printf("Please enter b: ");
  scanf("%f", &b);

  float alpha = 0;

  printf("Please enter the step size: ");
  scanf("%f", &alpha);

  float integral = 0;
  
  for(float x = a; x+alpha<=b; x+=alpha) {
    integral += elmt_integr(x, x+alpha, coeff, order);
  }

  printf("Result : "  ANSI_COLOR_RED "%.4f\n\r" ANSI_COLOR_RESET, integral);

  return 0;
}

float elmt_integr(float x1, float x2, const float * coeff, int order) {
  return (poly(coeff, order, x1) + poly(coeff, order, x2))*0.5*(x2-x1);
}

float poly(const float * coeff, int order, float x) {
  float result = 0;
  for(int i=order;i>=0;i--) {
    result += coeff[i]*pow(x,i);
  }
  return result;
}
