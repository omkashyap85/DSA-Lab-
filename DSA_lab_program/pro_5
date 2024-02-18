public class in_del_atend {
        private int[] array;
        private int size;
        private int capacity;
    
        public in_del_atend(int capacity) {
            this.capacity = capacity;
            this.array = new int[capacity];
            this.size = 0;
        }
    
        // Insertion at the end
        public void insertAtEnd(int data) {
            if (size == capacity) {
                System.out.println("Overflow: Array is full, cannot insert.");
                return;
            }
            array[size] = data;
            size++;
            System.out.println("Inserted " + data + " at the end.");
        }
    
        // Deletion at the end
        public void deleteAtEnd() {
            if (size == 0) {
                System.out.println("Underflow: Array is empty, cannot delete.");
                return;
            }
            int deletedData = array[size - 1];
            size--;
            System.out.println("Deleted " + deletedData + " from the end.");
        }
    
        public static void main(String[] args) {
           in_del_atend arrayOps = new in_del_atend(5);
    
            // Insertion at the end
            arrayOps.insertAtEnd(10);
            arrayOps.insertAtEnd(20);
            arrayOps.insertAtEnd(30);
    
            // Deletion at the end
            arrayOps.deleteAtEnd();
            arrayOps.deleteAtEnd();
            arrayOps.deleteAtEnd();
            arrayOps.deleteAtEnd(); // Trying to delete from an empty array (underflow)
        }
    }
    
