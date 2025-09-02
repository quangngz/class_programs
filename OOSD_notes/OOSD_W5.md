



## Acess control
private methods cannot be overidden. 

another way is to assigned that attribute or method to be final. 


Child classes cannot call private methods
## Protected
Child classes can call protected, however it shold be avoided. ???

Child class can see protected, but the outside cannot. 

Outside is another object in another module? 

A good design should ensure that any method pf the Piece that update the attributes, should check the states if its correct. 

## Inheritance and Shadowing
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
```
```
public class DemoShadowing {
    public static void main(String[] args) {
RookS r1 = new RookS(4,3);
System.out.println("r1: row print 1: " + r1.getCurrentRow());
System.out.println("r1: row print 2: "+ r1.currentRow);

PieceS r2 = new RookS(4,3);
System.out.println("r2: row print 1: " + r2.getCurrentRow());
System.out.println("r2: row print 2: " + r2.currentRow);
}
}
```

This is an example of shadowing, i.e. a variables is declared twice. 

But it is not a good practice. 


## Public
Public is visible to subclasses, and outside. 

### Object class
All classes are of type Object

All class have a toString method.

All classes have an equals method.

getClass - return an object of type Class that represents the details of the calling oject's class. 


### Upcasting
When an object of a child class is assigned to a variable of an ancestor class
```
Piece p = new Rook(2,3); 
```

### Downcasting
When an object of an ancestor class is assigned to a variable of a child class. 
```
Piece robot = new WingedRobot(); 
WingedRobot plane = (WingedRobot) tobot; 
```


### Polymorphism
The ability to use objects or methods in many different ways, roughly means multiple forms. 