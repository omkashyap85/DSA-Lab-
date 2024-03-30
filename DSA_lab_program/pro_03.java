
import java.util.Scanner;

public class ArrayOperations {
     public static void insert(int[] array, int size, int insertIndex, int insertValue) {
        if (insertIndex < 0 || insertIndex > size) {
            System.out.println("Invalid index for insertion.");
            return;
        }
        for (int i = size - 1; i > insertIndex; i--) {
            array[i] = array[i - 1];
        }
        array[insertIndex] = insertValue;
        System.out.println("Array after insertion:");
        for (int i = 0; i < size + 1; i++) {
            System.out.print(array[i] + " ");
        }
        System.out.println();
    }

    public static void delete(int[] array, int size, int deleteIndex) {
        if (deleteIndex < 0 || deleteIndex >= size) {
            System.out.println("Invalid index for deletion.");
            return;
        }
        for (int i = deleteIndex; i < size - 1; i++) {
            array[i] = array[i + 1];
        }
        size--;
        System.out.println("Array after deletion:");
        for (int i = 0; i < size; i++) {
            System.out.print(array[i] + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the size of the array: ");
        int size = scanner.nextInt();

        int[] array = new int[size];

        System.out.println("Enter elements of the array:");
        for (int i = 0; i < size; i++) {
            array[i] = scanner.nextInt();
        }

        System.out.print("Enter the location for insertion: ");
        int insertIndex = scanner.nextInt();
        System.out.print("Enter the value to be inserted: ");
        int insertValue = scanner.nextInt();

        insert(array, size, insertIndex, insertValue);

        System.out.print("Enter the location for deletion: ");
        int deleteIndex = scanner.nextInt();

        delete(array, size, deleteIndex);

        scanner.close();
    }
}
