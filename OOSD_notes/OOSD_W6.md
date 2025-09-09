## Interfaces
### Abstract class
A class that represents common attributes and methods of subclasses, but that is missing information specific to its subclasses. Cannot be instantiated. 

### Interface
Interface is a distant relative of abstract class. It declare a set of constants and/or methods that define the behaviour of an object. 

- IT can only contains constants and abstract methods. 
- define behaviours / methods that are common across all classes. 
- A class can choose to implement an interface. 


So, all attributes must be static final. 

All methods are abstract. 

Both are all public. 

### Implementing Interface
```
public interface Printable {
    int MAXIMUM_PIXEL_DENSITY = 1000; 
    void print();
}

public class Image implements Printable {
    public void print() {
        ... // specific code to the class
    }
}
```
Concerete classes must implement an interface must implement all the methods of the interface. 

Classes that dont implement all methods must be abstract. 

Classes can only inherits from 1 Class, but can implement many interface. 

Combining, inheritance and interface allows us to build very strong programs. 

### Default method
```
public interface Printable {
    default void print() {
        sout(this.toString()); 
    }
}
```
`default` indicates a standard implementation of a method that can be overidden if the behaviour doesn't match what is expected of the implementing class. 

### Extending Interface
```
public interface Digitlisable extends Printable {
    public void digitalise(); 
}
```
This is used to extend behaviours. 

### Interface application: Sorting
```
Arrays.sort(arrayOfThings); 
```

Like a String, and the String class implements a Comparable<String> interface. 

The Comparable interface allows objects of the same classes to be compared to each others. 

They must implement a method `public int compareTo(<className> object)`

```
public int compateTo(String string) {
    return this.length() - string.length(); 
}
```


```
// Inheritance
Robot robot = new Robot(); 

// Interface
Comparable<Robot> comparable = new Robot(); 
```

Another distinction: Inheritance is a relationship - a hierarchle one, between 2 classes. Interface is a "Can do" relationship.
