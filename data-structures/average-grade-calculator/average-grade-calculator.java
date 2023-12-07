  import java.util.Scanner;

  class Main {
      // this is a method to print the programming specifications for the project
      static void programSpecifications() {
          System.out.println("This is a program that will allow a student to:");
          System.out.println("1. Enter up to 10 test quiz scores");
          System.out.println("2. Compute the average score");
          System.out.println("3. Display the letter grade");
          System.out.println();
      }

      public double computeAverage(int[] arrayScores) {
          int arraySums = 0;
          double arrayAvg;
          //this loop will add all the values
          for (int i = 0; i < arrayScores.length; i++) {
              arraySums = arraySums + arrayScores[i];
          }
          //
          arrayAvg = (double) arraySums / (arrayScores.length);
          return arrayAvg;
      }

      //create a static method that will display the final letter grade
      static void computeLetterGrade(double averageVal) {
          char letterGrade;

          System.out.println("The Average Is: " + averageVal);
          if (averageVal >= 90) {
              letterGrade = 'A';
          } else if (averageVal >= 80) {
              letterGrade = 'B';
          } else if (averageVal >= 70) {
              letterGrade = 'C';
          } else if (averageVal >= 60) {
              letterGrade = 'D';
          } else {
              letterGrade = 'F';
          }
          System.out.println("The Letter Grade Is: " + letterGrade);
      }

      public static void main(String[] args) {
          //create an instance of the Main class
          Main lab = new Main();
          //create an instance of the scanner
          Scanner scr = new Scanner(System.in);
          //call the ProgramSpecifications method to display
          programSpecifications();

          //create array, limits array to 10 items
          int[] arr = new int[10];

          //grade is where the input will be read into
          int grade;
          // runningTotal will hold the sum of the grades
          int runningTotal = 0;
          //count is a counter for the grades
          int count = 0;
          //avgGrade will hold the average grade
          double avgGrade;

          System.out.println("Enter your your grades, entering 999 will make you exit. Grades are from 0 to 100.");
          System.out.println("Limit is 10 grades: ");

          //read in grades in scanner
          grade = scr.nextInt();
          //while loop to read in grades as long as it is not 999, and the maximum grades are 10
          while (grade != 999 & count < 10) {
              //add the grade to the count index of the array
              arr[count] = grade;
              //add the grade to the running sum
              runningTotal = runningTotal + grade;
              //check if there is a next value to read in
              if (scr.hasNext()) {
                  //read the next integer
                  grade = scr.nextInt();
                  //increase the counter
                  count++;
              } else {
                  //if there is no next grade, break and exit the loop
                  break;
              }
          }
          System.out.println();

          //loop to print each grade, separated by a new line
          System.out.println("The grades are: ");
          for (int i = 0; i < 10; i++) {
              //print out each grade by index order
              System.out.println(arr[i]);
          }
          System.out.println();

          //create the average by dividing the running total by the counts
          avgGrade = (double) runningTotal / count;

          //display the average grade and the final letter grade
          computeLetterGrade(avgGrade);
      }
  }