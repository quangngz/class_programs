# ER modelling
### Entities and Attributes
- Entity is a real world object indistinguishable from othr objects. An entity is described by a set of attributes. 
- An entity set (the square boxes in ER diagram - mostly we are referring to this) is a collection of entities of the same type. They have the same set of attributes and each entity have their own key. 
- A key is a unique identifier for each entity. 


### Relationships
- The Connection between 2 entities. 
- relationships can have their own attributes. 
- A relationship set is a set of relationships that shares the same type. 
- The same entity can participates in different relationships. 
- The same entity set can have different roles, i.e. a relationship, with other entities within the same set. 

## Constraints

### Key Constraints
- determine how many objects taking part in a relationship set between different entity set
- types of key constraints: 
    - Many to many. Example: Entity Lecturer and Subject (A subject can be taught by multiple lecturers, and a lecturer can teach multiple subjects)
    - One to many (many to one) - i.e. One entity set on one side can take up maximum 1 relationship. example: Each department have at most 1 manager.   
    - One to one - i.e. Every entity set can take up maximum 1 relationship. 
### Participation Constraints
- determines whether all entities of a set take part in a relationship - known as total participation.

- It can be resaid as, each entity must take part in at least 1 relationships. 

- Example: Every employee MUST work in a department. 

- There's also partial participation, which says not every entity must take part in a relationship. 

- example: Not all employees are managers. 

## Weak Entities
- An entity that cannot exists on its own,it needs to consider the key of another entity to exist. 
- Weak entity set and owner entity set must participate in a relationship where each weak entity has one and only one strong entity to depend on. 
- This is total participation, and it is also called identifying relationship. 
- Weak entity also possessed its own key, called a partial key.

## Ternary Relationships
- In general, we can have N-ary relationships, and relationships can have attributes.
### Definition: 
A Ternary relationship is relationship between 3 different entities. It is a subset of the N-ary relationship, which extends for N arbitrary entity sets. 

Example: 
```
+-----------+                 +-----------+
|  SUPPLIER |                 |   PART    |
+-----------+                 +-----------+
    \                            /
    \ (min,max)          (min,max) /
        \                        /
        \                      /
        \    /-----------\   /
        ---<   SHIPS    >---
            \-----------/
                    |
                    | (min,max)
                    |
            +-----------+
            |  PROJECT  |
            +-----------+

``` 
Where SHIPS is the relationship that tied Project, Supplier, and Part. 

Transforming a ternary relationship into a binary relationship potentially loses the meaning. 

## Multi valued Relationship
### Definition: 
When attributes can have multiple (but finite) values of the same type.

Example: An employee have 2 different Phone Number: Home and Work, so the Phone Number attribute is a multi value one. 

## Composite Attributes: 
### Definition: 
When attributes have a structure hidden inside (each element can be different type).

example: An employee's adress can consist of Postcode, street name, number, making the adress attribute a composite attribute.

                                                    
## Conceptual design Using ER model
### Design Choices: 
- SHould a concept be modelled as an entity or attribute? 
- Should a concept be modelled as an entity or relationship? 
- SHould the relationship be modelled as binary, ternary, or n-ary? 

### Constraints with ER model 
- A lot of data senmantics can (and should) be captured. 

Example: Should Employee's Adress be an entity or an attribute? 

Ans: It depends on how you want to use it. 
- If have several adress per employee, it should be an entity. 
- Or if the adress have a structure inside, you probably want to model it as an entity.


The style that uses the bold arrow is called Chen's notation

By the end of this part, you need to:
- identify entities, attribtues, and relationships
- Determine key constraints and participation constraints, and weak enity. 

# Relational Model (Lec 4)
## Data model
- Data model allows us to translate real world objects into structures that the computer can store. 
- There are many models: Relational, ER, O-O (Object Oriented), Network, Hierarchical, etc. 

## Relational model: 
- Expressed data in tables - which has rows (record) and columns (attributes). 
- They use Keys and Foreign Keys to store relationships. 
### Relation
Made up of 2 parts: 
- Schema: specifies name of relation, name, and type of each column. 

Example of Schema: 
```
TABLE Books (
    book_id      INT PRIMARY KEY,
    title        VARCHAR(100) NOT NULL,
    author_id    INT NOT NULL,
    published_on DATE
)

TABLE Authors (
    author_id    INT PRIMARY KEY,
    name         VARCHAR(100) NOT NULL
)

FOREIGN KEY (author_id) REFERENCES Authors(author_id)
```

- Instance: a table, with rows and columns.
- Other keywords: Cardinality: no. rows, degree (arity): no. columns. 
### Logical Design: Transforming from ER to relational model
- Entities -> Relation, attributes -> attributes of relation.

```
        +--------------+
        |   EMPLOYEE   |
        +--------------+
        /     |      \
       /      |       \
_______   _______   _______
(SSN   )  ( Name  ) (  Age  )
-------   -------   -------
```
into
```
// Logical design: 
Employee(ssn, name, age)

// and finaly into physical design: 
Employee(ssn CHAR(11), name VARCHAR(20), age INTEGER)
```
Then, implementation: 
```
CREATE TABLE Employee 
    (
        ssn CHAR(11), 
        name VARCHAR(20), 
        age INTEGER, 
        PRIMARY KEY (ssm)
    )
```
then, record instance
```
+-----------+----------------+-----+
| SSN       | Name           | Age |
+-----------+----------------+-----+
| 123-45-678| Alice Johnson  |  29 |
| 987-65-432| Bob Smith      |  41 |
| 555-11-222| Charlie Brown  |  35 |
| 111-22-333| Diana Prince   |  30 |
+-----------+----------------+-----+
```

## Key and Integrity Constraints
### Key: 
Keys are ways to associate tuples in different relations

Keys are one form of integrity constraints. 
- Key: A set of one or more column (attributes) that uniquely identifies a row (tuple) in a relation (table) 
- Super key: Any combinations of columns that uniquely identifies a class
- Candidate Key: A super key which cannot have any columns removed from it without losing the unqiue identification property. It is the minimal super key. 
- Primary Key: Is just one candidate key chosen, and it cannot be null. It's often automaticaly assigned by the DBMS, and is often the key's refered to by others. 
- Surrogate Key: An artificial key wich aims to uniquely identify each record. It's not the NATURAL KEY, which is derived from business data. These keys are created when you don't have any natural primary key. It is usually an integer, and doesn't lend any meaning to the data. 
- Foreign Key is a key that references the Primary key of another entity, establishing a relationship between them
- If all foreign keys are enforced in DBMS, we say referential integrity is achieved. 
### Integrity constraints: 
A condition that must be true for any isntance of the database, e.g. domain constraints. 
- ICs are specified when schema is defined. 
- ICs are checked when relations are modified. 

A legal instance of a relation is one that sastifies all specified ICs. 
- DBMS should not allow illegal instances. 

## Impplementing the relational model
- Multi value attribute is flatten out to implement relational model. 
- Composite Attributes are also flatten like that.
- Many-to-many binary relationship set to a relation attributes of a new relation must include.  
    - Keys of each entity sets are transformed into a composite key. 

Example:
```
Employee(ssn, name, age) 
Department(did, dname, budget)
Works_in(ssn, did, since) // This is the relationship
``` 

Similar to the binary relationship, for many-to-many ternary relationship, you simply make a composite foreign key of all other participating entity sets. 

For Many-to-one: 

RULE: Primary key from the MANY side, becomes a foreign key on the one side. 

To ensure participation constraints, simply add NOT NULL into the field. 

A weak entity / identifying relationship, can be implemented as: 
```
CREATE TABLE Dependent(
    dname CHAR(20) NOTNULL; 
    ... 
    PRIMARY KEY (dname, ssn), 
    FOREIGN KEY (ssn) REFERENCES Employees ON DELETE CASCADE
)
```
This makes it so that the dependent key is deleted when the strong key (the employee) is deleted