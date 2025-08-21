### Data vs Information: 
- Data can be: 
    - known facts that are stored. Can be text, numbers, images, ...
- Information:
    - Data presented in context. It is data that has been processed to enhance user's knowledge. 
- Data is everyewhere and available. Information is processed and more useful
### Metadata
- Data about data. Can be structures, rules, constraints. 
- Metadata is useful for consistency and meaning. 
### Database
- A large, integrated, structured collection of data. 
- Use to model some real world enteprise. 

- A database management system is a software system designed to store, model, manage and access to databases. 

- Database advantages (as opposes to simply storing files): 
    - Seperation of data and program, centralised repository hence management. 
    - Data redundancy (See later)
    - Improved data consistency. Single store: no disagreement, update problems, less space. 
    - Imrpoved data sharing. 
    - Reduced program maintenance. 

### Database Development Cycle: 
1. Database planning (High level) - Specifies what we want to achieve from the database
    - Relies on knowledge at that industry. Hence creating a Enterprise data model.
2. Systems definition: Defining boundaries anmd scope of the application.  
    - Models how the database will interfere with other organisional systems. 
3. Requirement Definition and Analysis: Asking questions- Understanding about the requirement of the systems. Involves talking to customers alot. But this is VERY CRUCIAL. 
4. Design: 
    - Conceptually: Construction of a model that's going to be used (Not taking any physical considerations). Eventually we want to get the Relationship Entities Diagram (ER Diagram). 
    - Logical design: Decides wich type of models we use (Relational is always in the subject). Do stuff that won't allow garbage entries. 
    - Physical Design: Decides how much memory each entries can take up. We have to be cautious of edge cases (many cases, think of the range of values of the entries) 
        - Data Dictionary: List all the requirements / data type that is going to be inserted. 
5. Application design: 
    - Includes interface, and processes that uses the databases. Like a web. 
## SQL DATATYPES
### Character Types
- CHAR(M): A fixed-length string, right-padded with spaces. The range of M is
0 to 255.
- VARCHAR(M): A variable-length string. The range of M is 1 to 65535. (its 255
max. in MySQL 4).
- BIT, BOOL, CHAR: CHAR(1).
- BLOB, TEXT: up to 65535 bytes (for blob) or characters (for text).
- ENUM (‘value1’,’value’,...) up to 65,535 members.
- SET (‘value1’,’value2’, ...) up to 64 members.

### Integer Types
- TINYINT[(M)]: Signed (-128 to 127) Unsigned(0 to 255)
- SMALLINT[(M)]: Signed (-32768 to 32767) Unsigned (0 to 65535)
- MEDIUMINT[(M)]: Signed (-8388608 to 8388607) Unsigned (0 to 16777215)
- INT[(M)] / INTEGER[(M)]: Signed (-2147483648 to 2147483647) Unsigned (0
to 4294967295)
- BIGINT[(M)]:Signed(-9223372036854775808 to 9223372036854775807)
Unsigned(0 to 18,446,744,073,709,551,615)

### Real Types
- FLOAT[(M,D)]: single-precision, allowable values: -
3.402823466E+38 to -1.175494351E-38, 0, and 1.175494351E-38 to
3.402823466E+38. M = display width, D = number of decimals.
- DOUBLE[(M,D)] / REAL[(M,D)]: double-precision, allowable values: -
1.7976931348623157E+308 to -2.2250738585072014E-308, 0, and
2.2250738585072014E-308 to 1.7976931348623157E+308.
- DECIMAL[(M[,D])]: fixed-point type. An unpacked floating-point
number. Stored as string. Good for MONEY!

### Time and Date Types
- DATE 1000-01-01 to 9999-12-31
- TIME -838:59:59 to 838:59:59
- DATETIME 1000-01-01 00:00:00 to 9999-12-31 23:59:59
- TIMESTAMP 1970-01-01 00:00:00 - ~ 2037 Stored in UTC,
converted to local
- YEAR[4] 1901 to 2155 - A useful function in MySQL: NOW()

### How to store LOOKUP Table
- Example: How to prevent user's from mistyping currency value while entering
- Solution: Store an additional entity that stores the currency code and currency name. Then simply lookup when needed. This is another use of Physical Design. 

### Normalisation: 
- A way of validating the logical design thus far. 
- Denormalisation.
- Will be covered later. 
