// example of inheritance between subclass student and superclass person

public class Student extends Person {   // means Person is the superclass of Student
private String[] classes; // stores the students classes

public Student(String n, int a, String[] c){
// the persons name and age are already handled by the Person superclass
// we call the superclass constructor

super(n,a);
this.classes = c;
}        

// Building on parent class to extend our student class/module details  
public String toString(){ // Overriding the method and adding to it
String repr = super.toString() + "\n CLASSES: \n";  //will call the toString method of the superclass (Person)
for(int i = 0; i< classes.length; i++){     // Increment i
repr += classes[i] + "\n";
} 
return repr; // returns the string 
}        

public static void main(String[] args){

String[] classes = new String[] {"Intro to math", "Management for computing", "Programming"};
Student s = new Student("Pramod",58, classes); // s is what weve named the Student class
s.setAge(59);
System.out.println(s); // passing the "s" object to println calls the toString method of that object

}//We inherited the toString method the setAge method and the constructor from Person class

}