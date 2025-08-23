# Crowfoot notation (lec 5)
The Chen's notation is the original notation, and is often use in research. However, it is impractical, and the real world use this notation more often. 

## How to use? 
The entity is still a rectangle, however the attributes are listed within the entity.

[derived], {multivalued}, Composite(item1, item2) are some ways to notate different types of attributes. 

### derived attribute
Attributes that are derived from another attributes. Like DOB can derive someone's age. 

A derived attribute is not stored within the database, and it can reduces updates, and redundancies. 

### Relationships
Unary - relationship to itself, Binary - relationship to another entity, Ternary - relationship with 2 more entity

Cardinaity constraints:

```
Parent ||-----O{ Child

// The O before the crowleg ({), is optional many. The O is optional, and the crow leg is many. 
// Because this notation is nearer to the child, it applies to the child, i.e. there can be many children or none. 
// The | signals a maximum of one, and the other | (further away) signals compulsory.
// It's closer to the parent, so it applies to the parent, i.e. the parent must be exactly 1. 
```
Similarly, we can derive other Cardinaity constraints, such as optional many(0 or more), mandatory many(1 or more), optional one (O or 1), or mandatory one (exactly 1). 

from here, we can derve cardinaity relationships, one to one (each entity have exactly 0 or 1 related entity)

one to many (One of the entity have 0 or more related entities, and the other will have 0 or 1)

Many to many (Each entities can have 0 or more relationships)

NOTE: the Crowfoot notation is opposite to the Chen's notation. The Chen's notation, the relationship nearer to the entity, refers to the constraints of the other entity.

```

Book === Has <=== Page
// The relationship near the page is a mandatory one. It applies that there must be exactly 1 book participating. 
// The relationship near the book is a mandatory many, applies to the page that there must be atleast 1 page participating. 
```

## checklist of converting from conceptual to logical design
1. Flatten composite and multivalued attributes.  
    - Multivalued attributes can become another table. 
    - It can be a look up table, i.e. a one-many relationships (one as the employee, and many as the roles), as an employee must have atleast 1 role. 
2. Resolve many-many relationships
    - Create an associative entity. 
    ```
    employee }|---------O{role
    // transforms into logical design 
    employee ----- associative ------ role


    where an associative stores the foreign keys of employee and role
    ```
3. Resolve one-many relationships
    - add foreign key to crows foot end (the many side)
### Convert to logical design
4. Generate attributes data types

### For one to one relationships
- Need to decide where to put foreign key. 
- Primary key on the madatory side becomes the foreign key on the optional one. 
- If both are optional or madatory, decide one arbitrarily. 

### Unary relationships 
- You handle unary relationships exactly how you would handle binary relationships 

1-1: Put a Foreign key in the relation

1-m: Put a foreign key in the relation

m-m: Generate an associative key. Put 2 foreign keys in the associative key

### Ternary relationshps
- For 3 m-m relationships, also put an associative key between the rleationships.


### Identifying relationships
Foreign key goes into crowfoot end. 

But the foreign key becomes part of the primary key.