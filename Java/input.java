// import java.util.*;

class input {
  public static void main(String args[]) {
    Scanner input = new Scanner(System.in);
    System.out.println("Enter a number ");
    int number = input.nextInt();
    // System.out.println("You entered " + number);
    // System.out.println("First Args is " + args[0]);
    // System.out.println("Args Length " + args.length);
    for (String i : args) {
      System.out.println(i);
    }
    input.close();
  }
}
