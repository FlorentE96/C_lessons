#include <stdio.h> // For printf and scanf
#include <stdlib.h>
#include <string.h> // For strcmp
#include <math.h> // For sqrt

#define MAX_ORDER (8) // Maximum order of the polynomial

/**
 * ANSI COLORS FOR PRETTY TERMINAL OUTPUT. WILL ONLY WORK IN BASH.
 **/
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

/**
 * Function to flush the standard input of trailing characters.
 **/
static inline void flush() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF);
}

float elmt_integr(float a, float b, const float * coeff, int order);
float poly(const float * coeff, int order, float x);

/**
 * Main function.
 * @param argc : the number of input arguments passed via the command line
 * @param argv : an array of string corresponding to the command line arguments
 * @return -1 for error, 0 for success
 **/
int main(int argc, char *argv[]) {
  printf("Please enter the polynomial coefficients (enter a letter when you want to stop):\n\r");
  float coeff[MAX_ORDER] = {.0f,}; // Array of polynomial coefficients, indexed by their order.
  int order = 0; // Order of the polynomial
  int ret = 1;

  do{
    printf("c%d = ", order);
    ret = scanf("%f", &coeff[order++]);
    if(!ret) { // If something else than a nmber has been inputted
      order--; // we cancel the order incrementation
      break; // And get out the loop
    }
  } while(order < MAX_ORDER);

  order--;

  /* Display the polynomial */
  printf(ANSI_COLOR_YELLOW "\n\r\tf(x) = ");
  for(int i=order;i>0;i--) {
    printf("%.2f*x^%d + ", coeff[i], i);
  }
  printf("%.2f\n\r\n\r" ANSI_COLOR_RESET, coeff[0]);

  flush(); // Flush any remaining chars in the stdin

  float a = .0f, b = .0f;
  float alpha = .0f;
  printf("Please enter a: ");
  scanf("%f", &a);
  printf("Please enter b: ");
  scanf("%f", &b);
  printf("Please enter the step size: ");
  scanf("%f", &alpha);

  float integral = .0f;
  /* for each interval, compute the interval's trapezoidal area and accumulate. */
  for(float x = a; x+alpha<=b; x+=alpha) {
    integral += elmt_integr(x, x+alpha, coeff, order);
  }
  printf("Result : "  ANSI_COLOR_RED "%.4f\n\r" ANSI_COLOR_RESET, integral);
  return 0;
}

/**
 * Elemental integration over a single trapezoid.
 * @parameter x1    : the leftmost boundary
 * @parameter x2    : the rightmost boundary
 * @parameter coeff : a pointer to the polynomial's coefficients array
 * @parameter order : the order of the integrated polynomial
 *
 * @return The trapezoid's area (float).
 **/
float elmt_integr(float x1, float x2, const float * coeff, int order) {
  return (poly(coeff, order, x1) + poly(coeff, order, x2))*0.5*(x2-x1);
}

/**
 * Computes the value of a polynomial for a certain input.
 * @parameter coeff : a pointer to the polynomial's coefficients array
 * @parameter order : the order of the polynomial
 * @parameter x     : the value for zhich the polynomial must be computed
 *
 * @return the polynomial's value (float)
 **/
float poly(const float * coeff, int order, float x) {
  float result = 0;
  for(int i=order;i>=0;i--) {
    result += coeff[i]*pow(x,i);
  }
  return result;
}
