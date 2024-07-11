import java.util.Scanner;

class PowerOfThree {

  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);
    PowerOfThree obj = new PowerOfThree();
    System.out.println("Enter a number");
    int n = sc.nextInt();
    boolean check = obj.powerOfThree(n);
    if (check) {
      System.out.println("YES!!");
    } else {
      System.out.println("NOOO!!");
    }

    // Close the Scanner to resolve resource leak
    sc.close();
  }

  boolean powerOfThree(int n) {
    // Ensure n is positive
    if (n <= 0) {
      return false;
    }

    int c = 0;
    while (n > 1) {
      if (n % 3 == 0) {
        n = n / 3;
      } else {
        c = 1;
        return false;
      }
    }
    return (c == 0);
  }
}
