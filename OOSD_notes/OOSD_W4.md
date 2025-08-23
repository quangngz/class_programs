# Array
## Definition
Array is a sequence of element of the same type being arranged in ordrr in memory. 

### How to define an array
```
int[] a_1 = {1,2,3,4}; 
```

```
// Another way
int a_2[] = int new int[5]; 
// This creates the space, but initilaise everything to 0 
but you now can access properties, such as a_2.length()
```
Once you create an array,you cant change the size. 

IF you want to access an element in the array, you need to keep a reference of the array

Java also allows mullti-dimesional array. 
```
int[][] nums = new int[10][10]
int[][] nums2 = new int[10][]; // Irregular array
```
Java multidimensional arrays can be non even size, as they are essentially pointers to pointers only. 

SO you could have a length5 array at a[0], but a length 2 array at a[1]

### Array of objects
```
Circle[] circleArray; // Declaration of array
circleArray = new Circle[25]; // Allocation of space

for ( int i = 0; i < circleArray; i++) {
    circleArray[i] - new Circle(i,i,i+2); 
}
// Initialising objects; 
```

### Array methods
```
int len = array.length; 

int[] n1 = {1,2,3}; 
int[] n2 = {4,5,6}; 
Array.equals(n1, n2); 
Array.sort(n1); 
```

### For Each Loop
```
for (<type> varName : <iterable object>) {
    ...
}
```
THis is an easier way to loop through array

## Strings
```
final String STRING_CONSTANT = "Welcome to JAva"; 
```

String is a Java class made up of sequence of characters. 

You can't use single quotes to define strings. 

If you want to print special characters, like double quote, you use the `/` beforehand. 

### String operations
You can use + to concantenate strings. 
```
System.out.println("1 + 1 = " 1 + 1); // outputs "1 + 1 = 11"
System.out.println("1 + 1 = " (1 + 1)); // outputs "1 + 1 = 2"

```
It has a method `<varname>.length()`

`.toUpperCase()`, `.split(" ")`, `s.contains("Substring")`, `s.indexOf("Substring")`, `s.replace("e","i")`, `s.subString(0,2)`

Strings are immutable classes. Hence the methods above would return a new string, hence you would want to assign the methods to a new variables. 

Note: 
```
System.out.println("Hello" == "Hello"); // return true


String s = "Hello"; 
System.out.println(s == "Hello"); // return true


String s2 = "Hello"; 
System.out.println(s == s2); // return true


String s3 = new String("Hello"); 
System.out.println(s == s3); // return false
// TO actually do this, do
System.out.println(s.equals(s3)); // return true
```
This should be note, that to compare any class objects, always use equals()


# Command lines argument
```
public static void main(String args[]) {
    // the args are what reading from the command line. 
}
```
You can input to the command line by
```
java program arg1 arg2 arg3 ...
```

## Scanner class
```
import java.util.Scanner; 
...
Scanner scanner = new Scanner(System.in); 

Double d = scanner.nextDouble(); 
String s1 = scanner.next(); 
int i1 = scanner.nextInt(); 

System.out.format("%d %.2f", i1, d);
```


## Reading files
```
import java.io.FileReader; 
import java.io.BufferedReader; 
import java.io.IOException; 


public class ReadFile {
    public static void main(String args[]) {
        try (BufferedReader br = 
            new BufferedReader(new FileReader("test.txt"))) {
                String text = null; 

                while ((text = br.readLine()) != null) {
                    System.out.println(text); 
                }
            } catch {
                e.printStackTrace();
            }
    }
}
```

Scanner should be use 