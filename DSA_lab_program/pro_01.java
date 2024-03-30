import java.util.Scanner;

public class pro_1 {
        public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the number of students: ");
        int numStudents = scanner.nextInt();
        System.out.print("Enter the number of subjects: ");
        int numSubjects = scanner.nextInt();

        int[][] marks = new int[numStudents][numSubjects];

        System.out.println("Enter marks for each student:");

        for (int i = 0; i < numStudents; i++) {
            System.out.println("Enter marks for Student " + (i + 1) + ":");
            for (int j = 0; j < numSubjects; j++) {
                marks[i][j] = scanner.nextInt();
            }
        }

        System.out.println("\nTotal marks of each student:");

        for (int i = 0; i < numStudents; i++) {
            int totalMarks = 0;
            for (int j = 0; j < numSubjects; j++) {
                totalMarks += marks[i][j];
            }
            System.out.println("Total marks of Student " + (i + 1) + ": " + totalMarks);
        }

        System.out.println("\nAverage marks of each subject:");

        for (int j = 0; j < numSubjects; j++) {
            int subjectTotal = 0;
            for (int i = 0; i < numStudents; i++) {
                subjectTotal += marks[i][j];
            }
            double average = (double) subjectTotal / numStudents;
            System.out.println("Average marks of Subject " + (j + 1) + ": " + average);
        }
    }
}


