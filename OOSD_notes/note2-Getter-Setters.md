### Getter, Setter
- These are methods within a class to set and get a property of an object. It is also called Accessor / Mutator methods.  
- IDEs support automatic generation of Getter and Settor. 
- It is useful for information hiding, visibility control and privacy. 

### Constructor
- You can technically set all attributes of an object by using setters only, but it would be lengthy. Hence born construtor. 
- Constructor is a method to create and initialise objects. 
```
class Circle {
    public double centreX, centreY, centreZ; 
    public Circle() {
        centreX = 10; 
        centreY = 10; 
        centreZ = 10; 
    }
}

// before 
Circle circleA = new Circle() // initialise a null reference. 
// after
Circle circleA = new Circle() // already initialise to the values. 
```
- A class can have multiple constructors, and a constructor can take arguments. 
- Note: The benefit of having multiple construtor is because people may have different prefernece of how they initialise new objects.   
- Constructor is automatically called when creating a new object. 

### Method Overloading & Polymorphism
- Methods that have the same name, but different arguments signature (no. args, type, position).
- Any methods can be overloaded. It is a form of polymorphism (same method, 
different behaviour) 

### `this` Keyword
- `this` refers to the calling object, i.e. the object that's calling the method.   
```
class Circle {
    // Constructor
    public Circle() {
        this.centreX = 10; 
        this.centreY = 10; 
        this.centreZ = 10; 
    }
    // Overiding
    public Circle(double centreX, double centreY,double centreZ,) {
        this.centreX = 10; 
        this.centreY = 10; 
        this.centreZ = 10; 
    }
}
```

### static variables and method
- A problem: How to count the number of objects you created? - Answer: Static variables
- static members: methods or attribute that don't belong to any class. 
- static variables are variables that are shared between objects with the same class - Local to each class. This is different to Instance variable - Local to each object. 
- static methods: methods that don't depend on any instance variables of the class. Static methods can be alled using the clas name. 


## standard methods: 
- Some methods are used soo frequently, that they appear in almost every class. 
### `equals` method
```
public boolean equals(Circle circle) {
    return Double.compare(circle.centreX, centreX) == 0 &&
    Double.compare(circle.centreY, centreY) == 0 &&
    Double.compare(circle.radius, radius) == 0;
}
```
- Note how Java provides you with a Double method, that helps you compare Doubles (as doubles are very high in precision and may not result in wanted outputs). 
- Also note that the `equals` method here is a static method, as it is called from the class name. 
### `toString` methodtoString
- A method that is used to prnt the content of a class.
- You should almost always provide this method in your classes.  
```
public String toString() {
    return "I am a Circle with {" + "centreX=" + centreX +
    ", centreY=" + centreY +
    ", radius=" + radius +'}';
}
```
### copy Constructor
- A method that copies the contents of an object into another separated object. 
```
public class Circle {
    public double centreX, centreY, radius;
    // Copy Constructor
    Circle (Circle aCircle) {
        if (aCircle == null) {
            System.out.println("Not valid Circle");
            System.exit(0);
        }
        this.centreX = aCircle.centreX;
        this.centreY = aCricle.centreY;
        this.radius = aCircle.radius;
    }
}
```
```
Circle c1 = new Circle(10.0, 10.0, 5.0); 
Circle c2 = c1; //a reference to the same object pointed by c1
Circle c3 = new Circle(c1); //a new object - state is same as c1
```
