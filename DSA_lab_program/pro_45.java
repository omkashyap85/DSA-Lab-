import java.util.*;

public class NextGreaterToRight {
    public static void main(String[] args) {
        int[] arr = {2, 4, 2, 6, 24, 3};
        int[] result = nextGreaterToRight(arr);
        System.out.println("Next Greater Element to the Right:");
        for (int i = 0; i < arr.length; i++) {
            System.out.println(arr[i] + " --> " + result[i]);
        }
    }

    public static int[] nextGreaterToRight(int[] arr) {
        int n = arr.length;
        int[] result = new int[n];
        Stack<Integer> stack = new Stack<>();

        for (int i = n - 1; i >= 0; i--) {
            while (!stack.isEmpty() && stack.peek() <= arr[i]) {
                stack.pop();
            }
            result[i] = stack.isEmpty() ? -1 : stack.peek();
            stack.push(arr[i]);
        }
        return result;
    }
}
