# Docs of C++ Tutorial by The Cherno

Holy, I got super burnt out. What better time can there be to write docs!
I just `ls -la`ed into my `cpp` source code directory and found out that
I had started the course just on July, 1. I just love the feeling when I'm
so immersed in doing/learning something productive that I completely lose
the sense of time. Anyways, without further ado, let's get started.

## `build.sh` and `CMakeLists.txt`

Since we're programming in linux, we gotta do a bit of setup before
we can actually execute our program. We gotta create a directory
with the name of the project, suppose `PROJECT_NAME`.
Then we `cd` into this directory and create two files: `CMakeLists.txt`
and `build.sh`. The file `CMakeLists.txt` contains flags,
minimum version, source directory paths, source files, etc.
The file `build.sh` contains the build command. I added two new snippets
to UltiSnips: `cpp` for `bash` files and `template` for `cmake` files.
These automatically generate the text that are meant to be put into these
setup files. Then we add the executable flag to `build.sh` and build our
project. I also added a keymap in `keymaps.lua` which allows you to
type out `<leader>cr` resulting in making a vertical terminal split
(inside NVIM) and runs `make && ./PROJECT_NAME`. Hence, we do not need to
manually run the program anymore.

## Basic Introduction

I am going to pack into a single place what I've learn so far from the
first forty four lectures.

`#include <iostream>` to include input-output features.

`std::cout << "Hello World!" << std::endl;` prints `Hello World!` with
a `\n` at the end.

`std::cin.get();` waits for the enter key to be
pressed.

`#include "header.h"` pastes the code of `header.h` verbatim where
you have this include statement.

`#pragma once` at the top of the
header file implies that every definition in this file should be
included only once if found more than once. The same can be achieved
using:

```cpp
#ifndef _LOG_H_
#define _LOG_H_
...
#endif
```

`void Log(const char *message) { ... };` takes a character array (mostly used for
defining strings) as the input. `int Multiply(int a, int b) { ... };` takes two
integers as input and has `int` as the return type. (Functions defined in a file
in `src/` can be used across other files in the same directory.)
`sizeof(<data_type>)` returns the size of the data type.

### Conditional Statements

```cpp
if (...) {
    ...
} else if {
    ...
} else {
    ...
}

var = (condition) ? <value_if_true> : <value_if_false>;
```

### Loops

```cpp
// the conditions can be kept empty too
for (...;...;...) {
    ...
}

while (...) {
    ...
}

do {
    ...
} while(...);
```

### Pointers and References

`int *ptr = &var;` --- a pointer

`int &ref = var;` --- a reference (passes the variable itself, not a copy to it)

`int **pptr = &ptr;` --- a pointer to a pointer

`*ptr = &newvar;` --- changes the address of the pointer

`ref = newval;` --- changes the value of the variable (`var`) it was referring to

We need to use `*ptr` to refer to a pointer's value. Initially, we can set
`ptr = nullptr;` to initiate as the null pointer.

### Classes and Structs

There's no strict rule for differentiating between the use cases of
class and struct, but a general rule of thumb says that we use classes when
working with complex applications that use properties like inheritance and stuff,
and use structs for simpler purposes. Everything defined under a class is `private`
by default and everything defined under a struct is `public` by default.

```cpp
class Entity {
private:
    float X, Y;
public:
    // this is the default constructor, i.e., the one run when no args are given
    Entity() {
        ...
    }

    // you can give multiple constructors that are non-identical based on the args
    Entity (float x, float y) {
        X = x;
        Y = y;
    }

    // this is a destructor which is called when the work of the class is done
    ~Entity() {
        ...
    }
};
```

You may manually call the destructor as `e.~Entity();`, but this isn't recommended.

By default, every class has a default constructor which is pre-defined by C++.
If you want to delete that, you may do that by using
any one of the following methods below:

```cpp
class Log {
private:
    Log() {}
};
```

OR

```cpp
class Log {
public:
    Log() = delete;

    static void Print() {
        ...
    }
};
```

On a side note, you need to access the `Print()` function here as
`Log::Print()` (due to the `static` keyword) and not via a
class object (you may do that, but it gets confusing).

`static int var2;` restricts the visibility of the variable `var2` up to
only the current translation unit. You should absolutely use the keyword
`static` for all function and variable definitions if you are sure that
the entity does not need to be accessed from other units.

`extern int var1;` searches for the variable explicitly in other translation units.

In the case below, we mark `x`, `y`, and `Print()` as static inside the struct.
This means that these variable(s)/function(s) are meant to be dependent only
on the class and not the objects derived from it. (You can think of this as
making the variable/function global under the struct scope. Using `static` under
`public` inside a class does the same job.)
This means that if you access
and change the value of `x` from `e0`, then the value of `e1.x` also gets changed
to the same value. The correct way to access these values is by doing
`Entity::x = 6;`, `Entity::y = 7;`, and `Entity::Print();`.

```cpp
struct Entity {
    static int x, y;
    static void Print() { ... }
};
```

#### More on Classes

We take a look at inheritance now.

```cpp
class Entity {
    ...
};

// this inherits everything from under Entity that is set to public
class Player : public Entity {
    ...
};
```

> [!IMPORTANT]
> **A short digression on strings:** In order to use strings, we need
> to use `#include <string>`. For defining a string, we use
> `std::string name = "...";`.

`public` --- can be accessed from anywhere

`protected` --- can only be accessed from its sub-classes

`private` --- can only be accessed from within its own class

Now we take a look at the `virtual` keyword.

```cpp
class Printable {
public:
    virtual std::string GetClassName() = 0;
};

class Entity : public Printable {
    std::string GetClassName() override { return "Entity"; }
};
```

> [!NOTE]
> When you are overriding a function,
> you should always use the "override" keyword
> even though it is not compulsory to do so.

It is always recommended to use constructor initializer list instead of
manually initializing them inside the scope of the constructor since it
prevents from multiple copies of the same variable be made.
However, the ordering of the variables in the list should be identical
to that of how they had been defined.

```cpp
class Player : public Entity {
    std::string m_Name;
public:
    Player(const std::string &name) : m_Name(name) {}
    std::string GetClassName() override { return m_Name; }
};
```

Another example of using initializer list is given below:

```cpp
class Entity {
private:
    std::string m_Name;
    int m_Score;
public:
    // the ordering is crucial when passing multiple initializers
    Entity() : m_Name("Unknown"), m_Score(10) {}

};
```

### Enumerate

```cpp
// the datatype can only be something related to int
enum Example : char {
    A = 65,
    B = 9,
    C = 66
};
```

Then we set a variable by choosing an option from those given under
`Example` by using `Example var = A;`. This restricts the set of values
that `var` can take to only the set defined under `Example`. Since
`var` is still something related to `int`, you can check conditions such
as `var == 62` or `var == 'K'`, etc.

A realistic usage of `enum` has been provided in
[LogClass/src/main.cpp](LogClass/src/main.cpp).

### Arrays

In order to use arrays, we need to use `#include <array>`.
We can create arrays in two ways.

Modern way to create an array:

```cpp
std::array<int, 5> array;
// prints the size of the array
std::cout << array.size() << std::endl;
std::cout << array[2] << std::endl;
```

Old way to create an array:

```cpp
// allocate an array in the stack
int array1[5];
// allocate an array in the heap
int *array2 = new int[5];
// the new keyword always returns a pointer to the location
// of the starting point of the created entity

// returns the number of elements in the array
sizeof(array1);

*(array + 2) = 3; // this is equal to array[2]

// we must deleted heap allocated memory manually
delete[] array2;
```

### Strings

Let's cover strings properly this time. As we have already seen in
the digression, we need to use `#include <string>` to use strings.

We cover only the new way to work with strings and not as an
array of characters.

```cpp
std::string name1 = "Bubu";
std::wstring name2 = L"Bubu"; // wide string
std::u16string name3 = u"Bubu"; // 16 bit string
std::u32string name4 = U"Bubu"; // 32 bit string

// raw string
std::string name5 = R"(Line 1
Line 2
Line 3
Line 4)";

// prints the length of the string
std::cout << name1.size() << std::endl;

// we gotta concatenate like this
std::string newname = std::string("Bubu") + "Droid";

// this lets us append stuff to strings too
using namespace std::string_literals;

// adding trailing "s" using this namespace allows us to concatenate strings
std::string name6 = "Bubu"s + "Droid";

// lets us search for a sub-string
bool contains name6.find("bu") != std::string::npos;
```

When passing a string to a function, if we aren't modifying it, then we
should always pass the string as a reference and add the `const` keyword
so that the function does not create a local copy of the same string
and waste memory.

```cpp
void PrintString(const std::string &string) {
    std::cout << string << std::endl;
}
```

### `const` and `mutable` keywords

```cpp
const int MAX_AGE = 90;

// cannot change the value in *a, i.e., cannot do *a = ...
const int *a = &x;

// cannot change the value in b, i.e., cannot do a = ...
int *const b = &y;

// cannot change anything
const int *const c = &z;

// we are not going to edit the value of *e, but we may edit the value of e
const Entity *e;

// we are not going to edit the value of e itself
const Entity &e;

class Entity {
private:
    int m_X, m_Y;
    mutable int var;

public:
    // the const here implies that you are not supposed
    // to change values inside this function
    int GetX() const {
        // see how we can change its value even though we are inside const?
        var = 2;

        return m_X;
    }

    int GetX() {
        return m_X;
    }
};

// Using const Entity here implies that we are not going to edit the object
// here. This assists us further by saving memory by not creating a copy of
// the object for the function that we are working with. This is beneficial
// when we know that we are only going to read the data and not edit/write
// anything into it.
void PrintEntity(const Entity &e) {
    std::cout << e.GetX() << std::endl;
}
```

> [!NOTE]
> When we comment out the first `GetX()` function above, the `e.GetX()` statement
> below starts failing. Why is that you ask? Well, when we do not provide the
> `const` keyword, we do not give any guarantee that we are not going to
> make edits. Hence, if we are going to take the argument of the `Entity`
> as `const Entity &e`, then we must make sure functions like `e.GetX()`
> absolutely do not tinker with the value associated with `e`. Hence, we
> need a `const` only method for that purpose.

### Lambda Functions

```cpp
// = stands for passing by value and & stands for passing by reference
// we can also use it as: auto f = [x]() ... OR f = [&x]() ...
auto f = [=]() mutable {
    x++; // this is some variable defined in the current scope
    std::cout << x << std::endl;
};

f(); // this does not change the value of x
```

> [!NOTE]
> The `mutable` keyword above is actually necessary if we want to capture
> something by value and intentionally want to modify the lambda's private copy.

Let's try to understand a class now.

```cpp
class Entity {
private:
    std::string m_Name;
public:
    Entity() : m_Name("Unknown") {}
    Entity(const std::string &name) : m_Name(name) {}

    const std::string &GetName() const {
        return m_Name;
    }
};
```

Let's try to understand the working of the `GetName()` function above.
The second `const` implies that we aren't changing any variable inside
the function. The `&` before the function name implies that we are
returning the variable `m_Name` that is inside the class as a reference.
The first `const` implies that the result returned should not be changed.

Moreover, when we create an array of `Entity`s using new, the default constructor
is automatically run for each of those individual `Entity` in the array.
`delete` also calls the destructor (if any) assigned to `Entity`.

```cpp
Entity *e = new Entity[50];
delete[] e;
```

### `explicit` keyword

We can disable implicit conversion by using the `explicit` keyword as follows:

```cpp
class Entity {
private:
    std::string m_Name;
    int m_Age;
public:
    explicit Entity(int age) : m_Name("Unknown"), m_Age(age) {}
};

int main() {
    // Entity c = 23; // implicit conversion
}
```

### Operator Overloading

```cpp
struct Vector2 {
    float x, y;

    Vector2(float x, float y) : x(x), y(y) {}

    Vector2 Add(const Vector2 &v) const { return Vector2(x + v.x, y + v.y); }
    Vector2 Mul(const Vector2 &v) const { return Vector2(x * v.x, y * v.y); }

    Vector2 operator+(const Vector2 &v) { return Add(v); }
    Vector2 operator*(const Vector2 &v) { return Mul(v); }
    Vector2 operator==(const Vector2 &v) { return x == v.x && y == v.y; }
};

Vector2 pos(4.0f, 4.0f);
Vector2 speed(0.5f, 1.5f);
Vector2 power(1.1f, 1.1f);

Vector2 result = pos.Add(speed.Multiply(powerup));
Vector2 newresult = pos + (speed * power);

if (result == newresult) {
    std::cout << "Same values!" << std::endl;
}
```

### `this` keyword

The `this` keyword is a **pointer** to the current object in the class.
If we access `this` in a non-`const` function, then we may edit `this` and
its associated values. Otherwise, if `this` was inside a `const` function,
we wouldn't be able to do so.

```cpp
class Entity {
public:
    int x, y;
    Entity(int x, int y) {
        this->x = x;
        this->y = y;
    }
};
```

### Unique, Shared, and Weak Pointers

A unique pointer frees the memory allocated whenever the scope ends.
We cannot have two unique pointers pointing towards the same memory location.
A shared pointer frees the memory allocated after all the scopes in which
the references are present end. On making a shared copy of a pointer, the
ref count is increased by one. Once the ref count goes down to zero, the memory
allocated for this shared memory gets freed.
A weak pointer does the same job as that of a shared pointer except that it
does not increase the reference count when we create a weak pointer.

```cpp
class Entity {
public:
    Entity() { std::cout << "Created Entity!" << std::endl; }
    ~Entity() { std::cout << "Destroyed Entity!" << std::endl; }
    void Print() const { std::cout << "Printing!" << std::endl; }
};
int main() {
    // This is a substitute for new. This creates the memory in the heap.
    // The benefit of such pointers is that you do not have to manually free
    // the memory.
    std::unique_ptr e = std::make_unique<Entity>();
    e->Print();

    {
        std::shared_ptr<Entity> e0;
        std::weak_ptr<Entity> e1;
        {
            std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>();
            e0 = sharedEntity;
            // this gets deleted as soon as the scopes with the other references
            // end, since weak pointers do not increase the ref count
            e1 = sharedEntity;
        }
    }
}
```
