#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

// 4 for loops for nums 1-9 inclusive
// 3 for operators
// rand % 3188 to choose from one of those for easy off

/* The displayMenu function simply outputs the welcome menu message */
void displayMenu() {
  printf("Welcome to the game of TwentyFour.\n");
  printf("Use each of the four numbers shown below exactly once,\n");
  printf("combining them somehow with the basic mathematical operators (+,-,*,/)\n");
  printf("to yield the value twenty-four.\n");
}

/* The isValidOperator function intakes the string of user inputted operators,
and loops through the 3 characters being inputted. If the user inputted operators
are not equal to one of +, -, *. or /, the validcount is not incremented and thus
1 is not returned, indicating invalid. Otherwise, 1 is returned, indicating valid operators*/
int isValidOperator(char ops[10]) {
  int validCount = 0;
  for (int i = 0; i < 3; i++) {
    if (ops[i] == '+' || ops[i] == '-' || ops[i] == '*' || ops[i] == '/') {
      validCount += 1; // incrementing count for each valid operator 
    }
  }
  if (validCount == 3) { // if the valid operators count is exactly 3, the input is good
    return 1;
  }
  return 0;
}

/* The calculate function intakes two double numbers, and a character operator as parameters. Its 
purpose is to check the operator and carry out the operation with said operator, completing each
operation with the double numbers provided as parameters. It then returns the total. */
int calculate(double num1, double num2, char op) {
    double total;
    if (op == '+') {
      total = num1 + num2;
    }
    else if (op == '-') {
      total = num1 - num2;
    }
    else if (op == '*') {
      total = num1 * num2;
    }
    else if (op == '/') {
      total = num1 / num2;
    }
    printf("%d %c %d = %d.\n", (int)num1, op, (int)num2, (int)total); // outputting the operation being done
    return total; 
}

/* the calculateDebug function intakes two double numbers and an operator character as parameters. 
Its purpose is similar to that of the calculate function, but it does not print the output. */
double calculateDebug(double num1, double num2, char op) {
    double total;
    if (op == '+') {
      total = num1 + num2;
    }
    else if (op == '-') {
      total = num1 - num2;
    }
    else if (op == '*') {
      total = num1 * num2;
    }
    else if (op == '/') {
      total = num1 / num2;
    }
    return total; 
}

/* the debug function intakes the debugMode command line value, 4 numbers of type double, and an empty
array to store found solutions in. It loops through numbers 1-9 inclusive, and each operator, carrying out 
the operation on every possible combination of numbers 1-9 and operators until it finds some that result in
24. If the calculation results in 24, it is stored in the puzzleNums array, the array of all possible solutions.
if debug mode is on, all solutions are printed as well */
void debug(int debugMode, double num1, double num2, double num3, double num4, int puzzleNums[3189][4]) {
  char ops[4] = {'+', '-', '*', '/'};
  double total1, total2, total3;
  int solCount = 1;
  
  for (int num1 = 1; num1 <= 9; num1++) {
    for (int num2 = 1; num2 <= 9; num2++) {
      for (int num3 = 1; num3 <= 9; num3++) {
        for (int num4 = 1; num4 <= 9; num4++) {
          for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
              for (int k = 0; k < 4; k++) {
                  total1 = calculateDebug(num1, num2, ops[i]);
                  total2 = calculateDebug(total1, num3, ops[j]);
                  total3 = calculateDebug(total2, num4, ops[k]);
                  if (total3 > 23.9999999 && total3 < 24.00000001) {
                    // below, storing the numebers which can evaluate to 24 via operators
                    // in the array corresponding to the solution number
                    puzzleNums[solCount][0] = num1; 
                    puzzleNums[solCount][1] = num2;
                    puzzleNums[solCount][2] = num3;
                    puzzleNums[solCount][3] = num4;
                    if (debugMode == 1) {
                      printf("\n%d. %d%c%d%c%d%c%d", solCount, (int)num1, ops[i], (int)num2, ops[j], (int)num3, ops[k], (int)num4);
                    }
                    solCount += 1; // a solution counter is incremented to number each possible solution.
                  }
                  else {
                    continue;
                  }
              }
            }
          }
        }
      }
    }
  }
}

/* The easyOn function intakes no parameters. It initializes a hard coded set of 10 puzzles for the user
to play. It first finds the number of the puzzle using the rand function, and then the 4 numbers from that
puzzle are loaded into the num1-4 variables as doubles. The numbers are output, the operators are taken in,
checked for validity and quantity to ensure 3 valid operators, and if not the error message is displayed. */
int easyOn() {
  char ops[10];
  double num1, num2, num3, num4, total1, total2, total3;
  int indexToPlay = (rand() % 10), validOp;
  int easyPuzzles[10][4] = {
      {3, 9, 4, 1}, {8, 5, 8, 1}, 
      {6, 1, 5, 1}, {2, 8, 7, 8}, 
      {5, 2, 9, 2}, {2, 6, 8, 4}, 
      {5, 5, 4, 3}, {6, 6, 2, 6}, 
      {8, 4, 2, 6}, {6, 2, 8, 1}
  };
  // below, storing the numbers into their variables
  num1 = easyPuzzles[indexToPlay][0];
  num2 = easyPuzzles[indexToPlay][1];
  num3 = easyPuzzles[indexToPlay][2];
  num4 = easyPuzzles[indexToPlay][3];
  
  printf("\nThe numbers to use are: %d, %d, %d, %d.", (int)num1, (int)num2, (int)num3, (int)num4); // printing the numbers


  printf("\nEnter the three operators to be used, in order (+,-,*, or /): ");
  scanf("%s", &(ops));// getting the operators
  int numOps = strlen(ops); // getting the operators

  // this code block checks the operators first for number then validity
  if (numOps > 3 || numOps < 3) {
    printf("Error! The number of operators is incorrect. Please try again.\n");
    return 1;
  }
  else {
    validOp = isValidOperator(ops);
    if (validOp != 1) {
      printf("Error! Invalid operator entered. Please try again.\n");
      return 1;
    }
  }

  // the numbers are sent to the calculate function, the result of each operation being used as the first operand again
  // in the next call to calculate(). total3 is the final value, and is checked to see if it is close enough to the result,
  // 24. and if it is or is not, the output message is displayed indicating success or failure
  total1 = calculate(num1, num2, ops[0]);
  total2 = calculate(total1, num3, ops[1]);
  total3 = calculate(total2, num4, ops[2]);
  
  if (total3 == 24 || (total3 - 24) < 0.001 && total3 - 24 > 0) {
    printf("Well done! You are a math genius.\n");
    return 0;
  }
  else {
    printf("Sorry. Your solution did not evaluate to 24.\n");
    return 0;
  }
  return 0;
  
}

/* The easyOff function intakes the entire correct solutions array as a parameter. It uses this array, using the rand
function to get a set of numbers to play from the array, and stores them as num1-4. The numbers are output, the operators
are input and checked for validity, then the calculations are done with the operators and the numbers to 
ensure the calculation equals 24. If it doesn, the pass is output, otherwise the fail message is output*/
int easyOff(int puzzleNums[3189][4]) {
  char ops[10];
  double num1, num2, num3, num4, total1, total2, total3;
  int indexToPlay = (rand() % 3188) + 1, validOp;
  num1 = puzzleNums[indexToPlay][0];
  num2 = puzzleNums[indexToPlay][1];
  num3 = puzzleNums[indexToPlay][2];
  num4 = puzzleNums[indexToPlay][3];
  printf("\nThe numbers to use are: %d, %d, %d, %d.", (int)num1, (int)num2, (int)num3, (int)num4); // printing the numbers

  printf("\nEnter the three operators to be used, in order (+,-,*, or /): ");
  scanf("%s", &(ops)); // getting the operators
  int numOps = strlen(ops); // getting the operators

  // this code block checks the operators first for number then validity
  if (numOps > 3 || numOps < 3) {
    printf("Error! The number of operators is incorrect. Please try again.\n");
    return 1;
  }
  else {
    validOp = isValidOperator(ops);
    if (validOp != 1) {
      printf("Error! Invalid operator entered. Please try again.\n");
      return 1;
    }
  }
  
  // the numbers are sent to the calculate function, the result of each operation being used as the first operand again
  // in the next call to calculate(). total3 is the final value, and is checked to see if it is close enough to the result,
  // 24. and if it is or is not, the output message is displayed indicating success or failure
  total1 = calculate(num1, num2, ops[0]);
  total2 = calculate(total1, num3, ops[1]);
  total3 = calculate(total2, num4, ops[2]);
  
  if (total3 == 24 || (total3 - 24) < 0.001 && total3 - 24 > 0) {
    printf("Well done! You are a math genius.\n");
    return 0;
  }
  else {
    printf("Sorry. Your solution did not evaluate to 24.\n");
    return 0;
  }
  return 0;
}

int main(int argc, char *argv[]) {
  int i, debugMode = 0, easyMode = 1, returnVal; // declaring variables to hold returnvals and debug and easy mode argv vals
  srand(1); 
  double num1, num2, num3, num4; // declaring the four numbers used in debug function to hold the valid numbers which operate to 24
  int puzzleNums[3189][4]; // declaring an array to hold every possible solution
  char playAgain;

  displayMenu();

  // below, the command line parameters are parsed to determine if easymode and debugmode is on/off
  for (i = 1; i < argc; i++) {
    if (argv[i][1] == 'd' && argv[i][3] == '1') {
      debugMode = 1;
    }
    if (argv[i][1] == 'e' && argv[i][3] == '0') {
      easyMode = 0;
    }
  }
  
  //below, calling the debug function to store every possible solution
  debug(debugMode, num1, num2, num3, num4, puzzleNums);

  // the blow while loop iterates for each replay of the game as well as if the game is failed, until N is input, when it ends
  while (playAgain != 'N') {
    
    if (easyMode == 1) {
      returnVal = easyOn();
      if (returnVal == 1) {
        continue;
      }
    }
    else if (easyMode == 0) {
      returnVal = easyOff(puzzleNums);
      if (returnVal == 1) {
        continue;
      }
    }
    
    printf("\nWould you like to play again? Enter N for no and any other character for yes. ");
    scanf("%1s", &playAgain);
  }

  printf("\nThanks for playing!");
  return 0;
}