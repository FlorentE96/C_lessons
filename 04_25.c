#include <stdio.h> // For printf and scanf
#include <stdlib.h>
#include <string.h> // For strcmp
#include <math.h> // For sqrt

void q_4_1(void);
void q_4_2(void);
void q_4_3(void);
void q_4_4(void);
void q_4_5(void);
void q_4_6(void);
void q_4_7(void);
void q_5_6(void);
void q_5_7(void);
int facto(int n);
int gcd(int A, int B);
void flip(int * A, int * B);
static inline char isMultiple(int A, int B) {return (A%B)==0;} // Returns TRUE if A is a multiple of B, FALSE otherwise


/**
 * Main function, the exercise number is passed as a command line argument
 * @param argc : the number of input arguments passed via the command line
 * @param argv : an array of string corresponding to the command line arguments
 * @return -1 for error, 0 for success
 **/
int main(int argc, char *argv[]) {
  if(argc > 1) {
    if(!strcmp(argv[1], "4.1"))
      q_4_1();
    else if(!strcmp(argv[1], "4.2"))
      q_4_2();
    else if(!strcmp(argv[1], "4.3"))
      q_4_3();
    else if(!strcmp(argv[1], "4.4"))
      q_4_4();
    else if(!strcmp(argv[1], "4.5"))
      q_4_5();
    else if(!strcmp(argv[1], "4.6"))
      q_4_6();
    else if(!strcmp(argv[1], "4.7"))
      q_4_7();
    else if(!strcmp(argv[1], "5.6"))
      q_5_6();
    else if(!strcmp(argv[1], "5.7"))
      q_5_7();
    else
      printf("This question number doesn't exist...\n\r");
  }
  else {
    printf("Not enough input arguments.\n\rUsage: myProgram.exe QUESTION_NUMBER\n\r");
    return -1;
  }
  return 0;
}

/**
 * Exercise 4.1
 * Displays the factorial of an inputted number.
 * @see int#facto(int)
 **/
void q_4_1(void) {
  printf("\n\r### Exercise 4.1 : factorial ###\r\n");
  printf("Please enter n\n\r");
  int ret, n;
  ret = scanf("%d", &n);
  if(ret == 0) // The format d
    printf("Please type an integer\n\r");
  else
    printf("Result : %d\n\r", facto(n));
}

/**
 * Exercise 4.2
 * Displays the number of combinations possible with an user-inputted size of set and subset.
 **/
void q_4_2(void) {
  printf("\n\r### Exercise 4.2 : combinations ###\r\n");
  printf("Please enter the set size\n\r");
  int ret, set, subset;
  ret = scanf("%d", &set);
  if(ret == 0) {
    printf("Please type an integer\n\r");
    return;
  }
  printf("Please enter the subset size\n\r");
  ret = scanf("%d", &subset);
  if(ret == 0) {
    printf("Please type an integer\n\r");
    return;
  }
  if(set<subset) {
    printf("The set has to be bigger than the subset...\n\r");
    return;
  }
  printf("Result = %d\n\r", facto(set)/(facto(subset)*facto(set-subset)));
}

/**
 * Exercise 4.3
 * Displays the GCD of 2 inputted numbers.
 * @see int#gcd(int,int)
 **/
void q_4_3(void) {
  printf("\n\r### Exercise 4.3 : GCD ###\r\n");
  printf("Please enter the first number (A)\n\r");
  int ret, A, B;
  ret = scanf("%d", &A);
  if(ret == 0) {
    printf("Please type an integer\n\r");
    return;
  }
  printf("Please enter the second number (B)\n\r");
  ret = scanf("%d", &B);
  if(ret == 0) {
    printf("Please type an integer\n\r");
    return;
  }
  printf("Result : %d\n\r", gcd(A, B));
}

/**
 * Exercise 4.4
 * Displays all the multiples of ONLY 5, 9 or 11.
 * Stops when the current number is a multiple of 5, 9 and 11.
 * @see int#isMultiple(int,int)
 **/
void q_4_4(void) {
  printf("\n\r### Exercise 4.4 ###\r\n");
  int num = 0;
  do {
    num++;
    if(isMultiple(num, 5)) {
      if(isMultiple(num, 9)) {
        if(isMultiple(num, 11))
          break;
      }
      else
        printf("%d; ", num);
    }
    else if(isMultiple(num, 9)) {
      if(!isMultiple(num, 11))
        printf("%d; ", num);
    }
    else if(isMultiple(num, 11))
      printf("%d; ", num);
  } while(1);
  printf("\n\r");
}

/**
 * Exercise 4.5
 * Displays the time schedule of a bus between 10am and 4pm
 **/
void q_4_5(void) {
  printf("\n\r### Exercise 4.5 ###\r\n");
  const int starting_time = 7*60;
  const int end_time = 16*60;
  const int display_starting_time = 10*60;
  for(int time = starting_time; time <= end_time; time+=50) {
    if(time>=display_starting_time) {
      printf("%d:%d\r\n", time/60, time%60);
    }
  }
}

/**
 * Exercise 4.6
 * Displays the maximum number of layers that can be made with a certain number of bricks.
 **/
void q_4_6(void) {
  printf("\n\r### Exercise 4.6 ###\r\n");
  printf("Please enter the number of bricks :\t");
  int ret, N;
  int layers=0;
  ret = scanf("%d", &N);
  if(ret == 0) {
    printf("Please type an integer\n\r");
    return;
  }
  for(int i=1; N-i>=0; i++) {
    N = N-i;
    layers++;
  }
  printf("You can make %d layers.\n\r", layers);
}

/**
 * Exercise 4.7
 * Displays how long it will take for a bank account to reach 10000000 yen
 **/
void q_4_7(void) {
  printf("\n\r### Exercise 4.7 ###\r\n");
  int months = 0;
  long int balance = 0;
  do {
    months++;
    balance = (balance*1.001) + 10000;
  } while(balance < 1000000);
  printf("It will take %d years and %d months\r\n", months/12, months%12);
}

/**
 * Exercise 5.6
 * Sorts students' average grade from smallest to biggest
 * @see void#flip(int*,int*)
 **/
void q_5_6(void) {
  printf("\n\r### Exercise 5.6 ###\r\n");
  printf("Please enter each student's grade:\n\r");
  float grade[10] = {0,};
  for(int i=0; i<10; i++) {
    printf("Student %d:\t", i);
    int ret;
    ret = scanf("%f", &grade[i]);
    if(ret == 0) {
      printf("Please type an number\n\r");
      i--;
    }
  }
  printf("\n\r------ Sorting ------\n\r");
  int student_order[10] = {0,1,2,3,4,5,6,7,8,9};
  for(int i=0; i<10; i++) {
    int * max = &student_order[i];
    for(int j=i; j<10; j++) {
      if(grade[student_order[j]]>grade[*max]) {
        flip(&student_order[j], max);
        /* flip(&student_order[j], min_ind); */
      }
    }
  }
  for(int i=0; i<10; i++) {
    printf("student %d: %f\n\r", student_order[i], grade[student_order[i]]);
  }
}

/**
 * Exercise 5.7
 * Displays the histogram of inputted students grades
 **/
void q_5_7(void) {
  printf("\n\r### Exercise 5.7 ###\r\n");
   printf("Please enter each student's grade:\n\r");
  float grade[100] = {0,};
  int n=0;
  while(n<100) {
    printf("Student %d:\t", n);
    int ret;
    ret = scanf("%f", &grade[n]);
    if(ret == 0) {
      printf("Please type an number\n\r");
      n--;
    }
    if(grade[n] < 0)
      break;
    n++;
  }
  int histo[10] = {0,};
  for(int i=0; i<10; i++) {
    histo[(unsigned int)grade[i]/10]++;
  }
  for(int i=0; i<n; i++) {
    printf("%d<=grade<%d: %d\n\r", i*10, (i+1)*10, histo[i]);
  }
}

/**
 * Computes the factorial of 2 number.
 * @parameter n : the integer of which the factorial must be determined
 * @returns : n!
 **/
int facto(int n) {
  int result = 1;
  for(int i=1;i<=n;i++)
    result = i*result;
  return result;
}

/**
 * Computes de GCD of 2 numbers using successive substractions algorithm
 * @parameter A : The first number
 * @parameter B : the second number
 * @return an int corresponding to the GCD
 **/
int gcd(int A, int B) {
  int diff = A;
  if (A == B)
    return A;
  do {
    if(A<B) {
      int temp = A;
      A = B;
      B = temp;
    }
    diff = A - B;
    A = B;
    B = diff;
  } while(diff != 0);
  return A;
}

/**
 * Flips 2 ints in place.
 * @parameter A : a pointer to the first int
 * @parameter B : a pointer to the second int
 **/
void flip(int * A, int * B) {
  int temp;
  temp = *A;
  *A = *B;
  *B = temp;
}
