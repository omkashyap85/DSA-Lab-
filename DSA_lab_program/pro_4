public class ins_del_atbeg {
    private int[] array;
    private int size;
    private int capacity;

    public ins_del_atbeg(int capacity) {
        this.capacity = capacity;
        this.array = new int[capacity];
        this.size = 0;
    }

    public void insertAtBeginning(int data) {
        if (size == capacity) {
            System.out.println("Overflow: Array is full, cannot insert.");
            return;
        }
        for (int i = size - 1; i >= 0; i--) {
            array[i + 1] = array[i];
        }
        array[0] = data;
        size++;
        System.out.println("Inserted " + data + " at the beginning.");
    }

    public void deleteAtBeginning() {
        if (size == 0) {
            System.out.println("Underflow: Array is empty, cannot delete.");
            return;
        }
        int deletedData = array[0];
        for (int i = 1; i < size; i++) {
            array[i - 1] = array[i];
        }
        size--;
        System.out.println("Deleted " + deletedData + " from the beginning.");
    }

    public static void main(String[] args) {
        ins_del_atbeg arrayOps = new ins_del_atbeg(5);

        arrayOps.insertAtBeginning(10);
        arrayOps.insertAtBeginning(20);
        arrayOps.insertAtBeginning(30);

        arrayOps.deleteAtBeginning();
        arrayOps.deleteAtBeginning();
        arrayOps.deleteAtBeginning();
        arrayOps.deleteAtBeginning(); 
    }
}
