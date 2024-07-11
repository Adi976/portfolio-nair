public class JuneTenth {
    public static void main(String[] args) {
        int n = 10; // Change the value of n to the desired Fibonacci sequence length
        System.out.println("Fibonacci sequence:");
        for (int i = 0; i < n; i++) {
            System.out.print(fibonacci(i) + " ");
        }
    }

    // Recursive method to calculate the nth Fibonacci number
    public static int fibonacci(int n) {
        if (n <= 1) {
            return n;
        } else {
            return fibonacci(n - 1) + fibonacci(n - 2);
        }
    }
}
