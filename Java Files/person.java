public class Person {

    private String name;
    private int age;

    // Create a constructor below:
    public Person(String n, int a) { // arguments
        this.name = n;
        this.age = a;
    }
    // To print out whats in the object we use a toString method:
    public String toString(){
        return "NAME:" + this.name + " AGE:" + this.age;
    }

    // we want to be able to CHANGE  the persons age etc so we make a mutator method:

    public void setAge(int n){ // mutator that will be used on personAppRunner too
        if (n <0) {
            return;

        }
        this.age = n; 
    }

    public static void main(String[] args){
        Person a = new Person("John",23);
        Person b = new Person("Paul",51);
        System.out.println(a);
        a.age = -1; // test our setAge method
        //a.setAge(40); // test our setAge method
        System.out.println(a);
        System.out.println(b);
    }



}