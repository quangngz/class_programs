# Introduction to Java Package

## Package
- Allows a group of classes and interfaces be bundled together under an accepted naming convention. 
- Allows reuse.
- Prevents naming conflicts. 
- This is another level of encapsulation. 
- Packages are different to libraries, but works similarly. 
### Using Package
```
package <directory_name_1>.<directory_name_2>
// This implies dir2 is a sub dir of dir1
```
- After having the package, you have to import
```
import <packageName> *; // Everything
import <packageName>.<className>; // Import the particular class
```
- A special class, the parent directory of the utilities directory, must be in the CLASSPATH enviornment variable (most of time its already set up by Intellj). 

### Default Package
- All classes written in the current directory, is inside the default package. 
- As long as the current directory is part of CLASSPATH, then the default package is automatically included. 
# Information Hiding
- This is available because of encapsulation. 
- THis is also referred to as Visibility Control. 
- How we structure our program so that we don't have information leakage.
- OR, a program that only accesses information that it needs (and no more).
## Definition
### Information Hiding: 
- Ability to hide the details of a class from outside. 
### Access control: 
- Prevent outside class from manipulating the properties of another class in undesired ways

## Visibility Modifiers:

### `public`
When applied, it is visible / available everywhere. 

### `private`
- When applied, makes it only visible within that class. They are not visible within the subclasses and are not inherited. 
- Question, a private attribute can only be accessed by a public method in the 
### `protected`
When applied, it is visible within the class, subclasses (even outside of the package), and whitin all classes that are in the same package. In this subject, we shouldn'y use this keyword .

### `default`
This is when you don't write anything, And it is visible to the classes and the classes within the package. (Stronger than protected). Don't Use this? 

## In practice
- Attributes should be made private, and getters and setters are public. 
## Mutability
### Immutable
- Variables that are private and cannot be changed. 
- Making things immutable, you can also add a final keyword. (It's dumb to have a setter to a final variable). 

# Delegation through association
## Definition
- A class can delegate responsibility to another class. 
- AN object can invoke methods in other objects through containership.

- e.g. A student owns a laptop object. 
- This is an association relationship between the classes. 

- To do this, include a class inside another class. Then, the outside classes can use all methods of the inner classes. This cannot be done if the classes are outside of each others. 

# Wrapper classes
## Definition
### Primitive Data type 
- Primitive data types are a unit of information that doesn't have any attributes or methods. 
### Wrapper classes
- A class that gives extra functionalities to primitives, like `int`, and lets them behave like objects. 
- A wrapper class will be capitalised by the 1st letter. 
## Some classes
- You don't have to import them. 
### Integer Class
- Reverse
- Rotate left
- Signum
- Parsing // THis one you probably have to know. It processes one data type into another. 
- In python, you don't need?? Because it's weakly typed. 

## Boxing and Unboxing
- The process of turning a primitive to its wrapper form. (Boxing). The reverse is Unboxing. 
### Example of boxing: 
```
Integer a = 10; 
// this is similar to writing
Integer a = Integer.valueOf(10);
// Because 10 is initially primitive, but then is converted to wrapper. 

int b = a; // This is unboxing, because a is wrapper, then converted to primitive. 
```
