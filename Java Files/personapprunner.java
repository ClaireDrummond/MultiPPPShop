public class PersonAppRunner{

// test to se if we can do this outside the person class (file)
// to demonstrate encapsulation (data hiding)


    public static void main(String[] args){
        Person a = new Person("John",23);
        Person b = new Person("Paul",51);
        System.out.println(a);
        //a.age = -1; // test our setAge method
        a.setAge(-1); // test our setAge method: Through this mutator method, we arent 
                        // allowed supply nonsense values for the age
        System.out.println(a);
        System.out.println(b);
    }

}