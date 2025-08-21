
### JAVA VARIABLES HIERARCHY
- byte -> short -> int -> long -> float -> double
- char -> int
- datatypes in front can be assigned to datatypes after.
        
        int i = 0; float y = 2.0 
        i = y; // Invalid
        y = i; // Valid



# W2
## Overview of Object Oriented Programming
- Classes and object are the building blocks of OO. 
- Class is a entity in a real world. It is the blueprint of objects. 
- Objects are <span style="color: red;">instances</span> of class
- Attributes are characterisics of classes. 
- Methods are classes functions. 
- Data abstraction: The technique of creating new data types that are well
suited to an application by defining new classes
- Data encapsulation: The ability to group data and methods that manipulate the data to a single entity through defining a class. 
- Instance variable: A property or attribute that is unique to each instance of a class. 
- Local variable: 
## How to define a class in Java? 
```
<visibility modifier> class <ClassName> {
        <attribute declarations>
        <method declatation>
}

// for now, make visibility modifier to public. 
```

## Using a class 
- Objects are null until they are instantiated(create a object). 
```
public class CircleTest {
        public static void main(String args[]) {
                Circle circleA = new Circle(); 
                Circle circleB = new Circle(); 
                circleA = circleB; // Memory leaks. But in Java it is handled by the garbage collector. 
        }
}
```
- When you define without new, you the variable is a null referenced. 
## Main method
- It is a method of the program class. 
- It is a void method. (Null is empty in memory, void is return type, i.e. return nothing). 
- When you invoke java to run a program, this is the method that's first run. 
- static: 