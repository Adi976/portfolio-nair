public class Main {
    public static void main(String[] args) {
        // Creating an instance of the Person class
        Person person = new Person("Alice", 30);
        // Calling a method on the Person instance
        person.displayInfo();
    }
}

class Person {
    private String name;
    private int age;

    public Person(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public String getName() {
        return name;
    }

    public int getAge() {
        return age;
    }

    public void displayInfo() {
        System.out.println("Name: " + name + ", Age: " + age);
    }
}
