public class SortedRotatedArray {

    public static int findFloor(int[] arr, int target) {
        int left = 0, right = arr.length - 1;
        int floor = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == target)
                return arr[mid];
            else if (arr[mid] < target) {
                floor = arr[mid];
                left = mid + 1;
            } else
                right = mid - 1;
        }
        return floor;
    }

    public static int findCeil(int[] arr, int target) {
        int left = 0, right = arr.length - 1;
        int ceil = Integer.MAX_VALUE;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == target)
                return arr[mid];
            else if (arr[mid] > target) {
                ceil = arr[mid];
                right = mid - 1;
            } else
                left = mid + 1;
        }
        return ceil;
    }

    public static int findPeak(int[] arr) {
        int left = 0, right = arr.length - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] > arr[mid + 1])
                return arr[mid];
            else if (arr[mid] < arr[mid + 1])
                left = mid + 1;
        }
        return arr[left];
    }

    public static int findMinimum(int[] arr) {
        int left = 0, right = arr.length - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] > arr[right])
                left = mid + 1;
            else
                right = mid;
        }
        return arr[left];
    }

    public static void main(String[] args) {
        int[] arr = {6, 7, 8, 1, 2, 3, 4, 5};
        int target = 4;
        System.out.println("Floor of " + target + " is: " + findFloor(arr, target));

        target = 4;
        System.out.println("Ceil of " + target + " is: " + findCeil(arr, target));

        System.out.println("Peak element is: " + findPeak(arr));

        System.out.println("Minimum element is: " + findMinimum(arr));
    }
}
