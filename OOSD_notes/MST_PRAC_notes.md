# Week 1
## About Java: 
Java is compiled and interpreted. 

Java is a object-oriented. 

Java virtual machine interprets the bytecode. 

Java compiler converts source code to bytecode.

```
public static void main(String args[]); <- the String args[], i.e. the main parameters, must be implemented. 
```

Java identifiers can contain letters, digits, underscore characters. They are case sensitive, and Java predefined keywords can be use as identifiers. But it cannot start with a digit. 

lowercase datatypes are primitive data types. Like int, double, float, char. Other are derived? String, Array, Double, Int, ... 

Local variables are defined within a Java method. 

Java has no explicit pointer type. 


## Floats
correct assignment
```
float x = 3.5f; 
int x = (int)3.5; 
```
incorrect assignment
```
boolean x = 0; 
float x = 3.5; 
int x = 3.5; 
```

## Char and String
correct assignment
```
char myChar = 'a'; 
String myString = "dmm"; 
```
incorrect assignment
```
char myChar = "a"; 
String myString = 'hey'; 
```


# Week 2
## Class vs Object
Class is a template for creating objects. Objects are instances of classes. 

A class can have attributes and methods. 

Defining a class creates a new datatype. 

An object without a valid reference (can be that you have lost the reference), is a candidate for the Java Garbage collector. 
## Object oriented core: 
Encapsulation: Property of bundling data (attributes) operate on individual units into a class. It also include the concepts of data hiding, where the internal state of an object is protected from external access. 

Abstraction: inly present the essential information to the user while hiding complex implementation details. Abstract classes and interfaces are structure that applies this idea. 

Inheritance: Allow a new class to inherit properties and behaviour of an existing class. 

Polymorphism: the ability of an object to take on many forms, or a method to be called on objects of different classes and behave differently dependng on the type. Method overriding and method overloading applies this idea. 

Method overidding: An application of polymorphism. It allows methods to share the same name but behave differently for different classes that calls it. Like when a subclass overides the superclass implementation of the same method. 

Method overloading: Allows methods to share a name but not its signature. It behaves differently depending on the signature / parameters that are passed in. 
## Instance variables
These are variables native to an object. They maintain the state of an object, and is unique to that object. An attribute of a class is the blueprint for this instance variables, i.e. the attribute can become an instance variables. 

Instance variable is not unique to a class. 

## Constructor
Constructor are methods to initialise an object. 

```
public Car car; // this object is not instantialised. It is currently null. 
car = new Car(); // Now it is instantialised. Not null.
```
## Static
Static attributes are attributes share amongst the class. 

Static methods are methods native to the class. They should be call via their class name, not the objects. Static methods also are not dependent on any instance variables or state of any object. 

Static attributes can be modified (and accessed) by non-static methods.

# Week 3
## Visibility Modifiers
private: STRONGEST. Not visible to any other classes. Only within itself. 

default: When you don't put any modifers before data type declarations. It is stronger than protected. Subclasses cannot access default types. 

protected: Visible to subclasses. Not with other packages. 

public: WEAKEST. Any Classes that has the reference to the class, can change / modify it. 

A class that contains methods that can change instance variables is called a mutable class. 

## Boxing & Unboxing
### Boxing
Turns a primitive data type into its wrapper form. Example: int -> Integer
```
Double d = 2.0; 
Integer i = 1; 
```
This is not boxing: 
```
String s = "Hello world"; 
```
This is because Hello world is already a string literal, and that is already a reference type object, not a primitive object. 
### Unboxing
Turns a wrapper datatype into a primitive data type. 
```
Double d = new Double(2.0); 
double y = d; 
```
## Version Control: Git
Git is useful. 

Create local copy through git clone. 

Staged a file that's changed through git add

Add that files to the local repository throuh git commit -m "Hello"

add that file to the remote repository through git push 

Maven is a build management tool, like Make. A build managmenet tool is a program that helps, 1. compiles all source files in correct order. 2. Automatically fetches required library from repositories. 3. Ensure the correct library versions are used. 4. tesging integration - run tests as part of build. 5. Automation: One command can build the project. 6. Continuous integration support, with CI/CD. Ofcourse, the features depends on what build management tool that you are using. 

# Week 4
## Arrays
To create an array that can store 5 Room objects: 
```
Room[] room = new Room[5];    
```

Example program: 
```
int[] array1 = {1,2,3,4,5}; 
int[] array2 = array1; 

System.out.println(array2[0]); // Outputs 1
array1[0] = 15; 
System.out.println(array2[0]); // Outputs 15
```
So, arrays assigning here are stored by references. 
### Multidimensional Arrays
```
int[][] nums = new int[10][10]; // Square array
int[][] nums = new int[10][]; //Irregular array.

// Initialising 2d arrays: 
for (int i = 0; i < nums.length; i++) {
    nums[i] = new int[<length of sub_array>]; 
}
```
## Strings
String is a Class and a Data Type. 

String is clever, in that when you do: 

```
int a = 10; int b = 15; 
System.out.println("a = " + a + ", b = " + b); 
// prints a = 10, b = 15
```
Strings are immutable, i.e. once created, they cannot be modified. Hence, Every String operation will return a new String. 

### Strings equality
```
"hello" == "hello" // true

String s1 = "hello"; 
String s2 = "hello"; 
s1 == s2 // true

String s3 = new String("hello"); 
s1 == s3 // false
```

So, if you want to test equality between 2 objects types, in this case String, you must use the equals method
```
s1.equals(s3); // true
```
## Input and Output
### Scanner class
Scanner is a class from the module java.util/ 

Creating a scanner: 
```
Scanner scanner = new Scanner(System.in); 
// System.in representes the standard input, i.e. the command line input. 

scanner.nextLine(); // Reads until the next line break or a return; 

scanner.next(); // reads the next String until the next whitespace

scanner.nextBoolean(); 
scanner.nextInt(); 
scanner.nextDouble(); 
// These all read until the next whitespace, and return in corresponding types. However, you must guarantees that the input matches the type you are trying to read. 
```

Other methods
```
scanner.hasNext(); // returns true if there's any input left ot be read. 
scanner.hasNextXXX(); // or any type you wish. 
```

Note: System.in is not a class, it is a static attribute represent the standard input. 

## Reading Files
```
import java.io.FileReader; 
import java.io.BufferedReader; 
import java.io.IOException; 


try (BufferredReader br = new BufferedReader(new FileReader("test.txt"))) {
    String text= null; 
    while ((text = br.readLine()) != null) {
        System.out.println(text); // similar like getchar()
    }
} catch (Exception e) {
    e.printStackTrace(); 
}
```

To read a file, you needed 2 classes BufferedReader and FileReader. 

FileReader - a low level file reader for simple character reading. 

BufferedReader - A higher level file that permits reading Strings. 

## Writing files
```
import java.io.FileWriter; 
import java.io.PrintWriter; 
import java.io.IOException; 

...

try(PrintWriter pw = new PrintWriter(new PrintWriter("testOut.txt"))) {
    pw.println("Hello world"); 
    pw.format("My favourtie device is %s and its %d dollars", "iphone", 1000);  
} catch (IOException e) {
    e.printStackTrace(); 
}
...
```

# Week 5
## Inheritance
Inheritance - A form of abstraction that permits generalisation of similar attributes/methods of classes. 

Superclass: The base class

Subclass: The derived class

### Note: Some weird shit

```
class Vehicle {
    public String getType() {
        return getInfo(); 
    }
    public String getInfo() {
        return "Vehicle";
    }
}

class Car extends Vehicle {
    public String getInfo() {
        return "Car";
    }
}

// You can do: 

Vehicle s1 = new Car(); 
System.out.println(s1.getInfo()); // returns Car
```
At compilation time, s1 is a vehicle.So if you call methods or access attributes that Car has but vehicle doesn;t have, it would be a compilation error. 

At runtime, s1 is a car. Hence why it can change the getInfor of the vehicle and prints Car. 
### Weird shit 2: 
```
class Vehicle {
    private void drive() {
        System.out.println("Drive inside Vehicle"); 
    }
}
class Car extends Vehicle {
    protected void drive () {
        System.out.println("Drive method inside Car");
    }
}
public class Main {
    public static void main(String[] args) {
        Vehicle s1 = new Car(); 
        s1.drive();
    }
}
```
This would be a compilation error, because like the above program, s1 during compilation is Vehicle, and drive inside vehicle is private, i.e. cannot be acccessed by Main. Hence, it is errornous. 

A good practice is to let subclasses access super elements through public or protected methods. 
### Overidding
When a subclass overrides a method of the superclass, an `@Override` is often put before that method, however it is not syntaxtically incorrect to not put it.

Not all superclass methods can be overidden. If those methods are private, so the subclass can't access them, or they are final, then subclasses cannot override them. 

If the methods are private and the subclasses have the same name with same signature, that's called method hiding - if its a static method, or simply is just a new method if not a static method. 

## Shadowing: The shittest
Shadowing is when 2 classes have the same method name and signature, but they also have overlapping scope. 

Example:
```
public class PieceS {
    public int currentRow;
    public int currentColumn;
    final static int BOARD_SIZE = 8;
    public PieceS(int currentRow, int currentColumn) {
        this.currentRow = currentRow;
        this.currentColumn = currentColumn;
    }
public int getCurrentRow() { return this.currentRow;}
 ...
}
public class RookS extends PieceS {
    public int currentRow;
    public int currentColumn;
    public RookS(int currentRow, int currentColumn) {
        super(currentRow, currentColumn);
    }
    public int getCurrentRow() { return this.currentRow;}
...
}

public class DemoShadowing {
    public static void main(String[] args) {
        RookS r1 = new RookS(4,3);
        System.out.println("r1: row print 1: " + r1.getCurrentRow()); // outputs 0
        System.out.println("r1: row print 2: "+ r1.currentRow);
        PieceS r2 = new RookS(4,3); // outputs 0
        System.out.println("r2: row print 1: " + r2.getCurrentRow()); // outputs 0
        System.out.println("r2: row print 2: " + r2.currentRow); // outputs 0
    }
 }
```
This is really shit. I dont even understand what's happening. It's best to make everything private as you go, and make them more loose if required. 

And to avoid this, only declare common variables inside the SUPERCLASS.
## Some Java defined classes
### Object class: 
Every class is an extension from this class. Some method of this is `.toString`, it returns the class in a string format.

`.equals(<other class>)` returns false if class type, or value stored is differnet. Otherwise it's true.

`.getClass` is a method that returns the class name of the object? 

`instanceof` is an operator that checks if two object A and B are instances of the same class, or if A inherits from B.

```
return new Rook() instanceof new Piece; // true
return new Piece() instanceof Rook; // false
```

## Upcasting and downcasting
### Upcasting: Small to big or Big from small. 
When an object of a child class is assigned to a variable of an acestor class. 
```
Piece p = new Rook(2,3); 
```
Notices how p is assigned as Piece, however it was instantiated via Rook (piece)
### Downcasting: Big to small, or small from big. 
When an object of an ancestor class is assigned to a variable of a child class. 
```
Piece robot = new WingedRobot(); 
WingedRobot plane = (WingedRobot) robot; 
```
Notices how robot transform from robot (base class, ancestor) to WingedRobot (child). 

## Polymorphism
The ability to use objects or methods in many different ways. Some application of it is: 

Overloading: Same method but behaves differently depending on the signature. 

Overriding: Same method but behaves differently on different scope / depending on the class that owns it? 

Substitution: Using subclasses in place of superclasses (Subtype polymorphism)

Generics: Defining parametrised methods / classes (Parametric polymorphism)


## Abstract classes
Some classes aren't meant to be instantiated ecause they arent completely defined, like Piece. What is it really? It's only an abstraction of a set of entities. 

Abstract classes are class that represents common attributes and methods of its subclasses, but is missng some information to specific to its subclasses. Cannot be instantiated. 

Concrete class: Classes that are not abstract, has well-defined, specific implementations for all actions it can take. 

Abstract class will define a superclasses that is common to all of its subclasses, but has no implementation. Then, the subclasses can implement those methods through overriding. 

In other words, you dont want to do `Piece p = new Piece();`, however you still can declare normal methods and fields.  
```
public abstract class Piece {
    private double centreX, centreY; 
    public Shape(double centreX, double centreY) {
        this.centreX = centreX; 
        this.centreY = centreY; 
    }

    public abstract boolean isValidMove(int toRow, int toColumn); // If this is called without overidden, it would be a compiler error. 
}
```
# Week 6
## Interfaces
Declares a set of constants and/or methods that define the behaviour of an object. 

Interfaces represents a can do relationship. 

Classes that implement an interface can do all the actions defined by that interface. 

Interface names are generally called <...>able, relating to an action. 

Inside interface, there's never any code. All methods implied must be abstractt, and all attributes are static final. All methods and attributes are implied to be public. 

Classes can implement many interfaces. 
```
public interface Printable {
    int MAXUMIM_PIXEL_DENSITY = 1000; 
    void print(); 
}

public class Image implements Printable {
    public void print() {
        ... 
    }
}
```

### Example of stuff that uses interface in Java
Comparable interface allows stuff to be sorted and compare. 

Comparable<String>, Comparable<ClassName>; ....

All implementation of this interface must implement `compareTo(<ClassName> object)`

### Subtype polymorphism: 
```
// Inheritance
Robot robot = new WingedRobot(...); 


// Interfaces
Comparable<Robot> comparable = new Robot(...);
```
### When to use Inheritance vs Interfaces
Inheritance is passing shared information into child class. It is fundamentally a "Is a " relationship. Example: All Dogs are Animals. 

Interface represents the ability of a class to perform an action, t is fundamentally a "can do" relationship. 