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
first forty three lectures.

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
std::array<int, 5> array = {1, 2, 3, 4, 5};
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

### Smart Pointers

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

## Continuation of docs

A shallow copy copies the pointer or the reference to some data while the deep
copy copies the actual data residing inside the variable. When we use modern string
functions, it makes a deep copy by default. However, if we want to make a shallow
copy, then we need to copy via reference.
This is the reason we use `(const std::string &s)` while passing a string to a
function.

The arrow operator is best explained by the following example:

```cpp
Entity e;
Entity *ptr = &e;

// the following lines have the same outcome
std::cout << ptr->x << std::endl;
std::cout << (*ptr).x << std::endl;
```

<!-- We can figure out the offset of a variable in a `struct` as follows: -->
<!---->
<!-- ```cpp -->
<!-- struct Vector3 { -->
<!--     float x, y, z; -->
<!-- }; -->
<!---->
<!-- // Cherno uses int for this cuz he has a 32-bit application -->
<!-- long offset = (long)&((Vector3 *)nullptr)->z; -->
<!-- std::cout << offset << std::endl; -->
<!-- // we can also use this: -->
<!--  uint64_t offset = offsetof(Entity, m_Name); -->
<!-- ``` -->

### Vectors

```cpp
struct Vector3 {
    int x, y, z;
};

std::vector<int> vec;

// adding elements to a vector
vec.push_back(4);

std::vector<Vector3> vector;
vector.push_back({1, 2, 3});
vector.push_back({4, 5, 6});

// iterating through a vector

// the old way
for (i = 0; i < vector.size(); i++) {
    std::cout << vector[i].x << ", " << vector[i].y << ", " << vector[i].z << std::endl;
}

// new way (note that we use reference since we aren't editing the value v)
// OPTIMIZE!!!
for (Vector3 &v : vector) {
    std::cout << v.x << ", " << v.y << ", " << v.z << std::endl;
}

// another way to print the same using auto and iterator
// we utilize the fact that vector elements are stored in contiguous locations
for (auto it = vector.begin(); it < vector.end(); it++) {
    std::cout << it->x << ", " << it->y << ", " << it->z << std::endl;
}

// .begin() returns a pointer to the first object
// (.end()-1) returns a pointer to the last object
std::cout << vector.begin()->x << std::endl;
std::cout << (vector.end()-1)->x << std::endl;

// we can delete the second element in this way
vector.erase(vector.begin() + 1);

// resets the vector size to zero by deleting all elements
vector.clear();
```

#### Optimizing the use of vector

Every time we add a new element to a vector class, it has to allocate new memory,
put the variables in, and then delete the pre-allocated memory. This is a waste
of resource. Moreover, when we add a new element into a vector using `push_back`,
it first creates the element in `main` and then pushes it into the vector.
This is a resource consuming task too. We can optimize vectors as such:

```cpp
std::vector<Vertex> vertices;
// this reserves enough storage space for three Vertex objects
vertices.reserve(3);

// using emplace_back puts the objects inside the vector from the very beginning
// I googled about when I should be using emplace_back instead of push_back,
// and I see people write that one should use push_back unless they know
// absolutely well about what they are doing.
vertices.emplace_back(1, 2, 3);
vertices.emplace_back(4, 5, 6);
vertices.emplace_back(7, 8, 9);
```

### More on the `static` keyword

```cpp
void Function() {
    // Suppose we make 5 Function() calls, then due to the static keyword,
    // the int i = 0; statement is not called multiple times.
    // So, we get 1 2 3 4 5 as the output. However, if we were
    // to just use int i = 0; without the static keyword,
    // then we would've had 1 1 1 1 1 as the output. Putting the
    // declaration int i = 0 outside the function definition would've the same
    // effect except that the variable i becomes public in that case which is not
    // good. The variable instance gets preserved throughout the program time.
    static int i = 0;
    i++;
    std::cout << i << std::endl;
}

class Singleton {
public:
    // the static keyword makes sure that the instance does not get deleted beyond
    // the scope of the curly braces below.
    static Singleton &Get() {
    static Singleton instance;
        return instance;
    }

    void Hello() {}
};

int main() {
    Singleton::Get().Hello();
}
```

### Returning Different Data Types from a Single Function

One way to (not really) return different types of parameters is by using references.
This is one of the best ways to do so since this is very memory efficient.

```cpp
void func1(int in1, int &out1, float &out2) {
    out1 = in1;
    out2 = (float)in1;
}

int a = 6;
float b = 6.0f;
int c = 0;
func1(c, a, b);
```

Another way to return different types of parameters is by using pointers.
This is also great since you can check for null pointers here.

```cpp
void func2(int in1, int *out1, float *out2) {
    if (out1) {
        *out1 = in1;
    }
    if (out2) {
        *out2 = (float)in1;
    }
}

int *e;
e = nullptr;
float *f = &b;
*f = 6.0f;
int g = 0;

// In this case, e only gets returned if it is not a null pointer. Hence, this
// idea may be used to exclude some returns like shaders when we want to
// disable them in-game.
func2(g, e, f);
```

We may also use vectors/arrays to do the same task, but they end up
allocating extra memory which just goes to waste.

C++ also provides us one way of doing this, which is by making tuples.

```cpp
std::tuple<std::string, int, int> func3() {
    return std::make_tuple("hi", 1, 2);
}

// std::tuple<std::string, int, int> res1 = func3();
auto res1 = func3(); // the auto keyword auto-fills the type

// we can also use using to do the same thing
using Func1Type = std::tuple<std::string, int, int>;
Func1Type res1 = func3();

std::cout << std::get<0>(res1) << ", "
    << std::get<1>(res1) << ", "
    << std::get<2>(res1) << std::endl;
```

If there are only two return arguments, then we can use `make_pair`.

```cpp
std::pair<std::string, int> func4() {
    return std::make_pair("avigyan chakraborty", 2);
}

std::pair<std::string, int> res2 = func4();

// this is the benefit of using pairs
std::cout << res2.first << ", " << res2.second << std::endl;
```

We may also use a `struct` to do the same thing which would then be much
clearer. So, we can choose any one between this `struct` or the reference
method to return data of different types from a function.

```cpp
struct profile {
    std::string name;
    int age;
};

profile biodata() { return {"Bubu", 19}; }

// This is the struct way to do this. Man this looks so much cleaner.
profile bubuprof = biodata();
std::cout << bubuprof.name << ", " << bubuprof.age << std::endl;
```

> [!TIP]
> Using the `struct` method or making references are the only decent ways
> to do this.

> [!NOTE]
> C++ versions 17 and beyond support structured bindings where you can load
> the arguments returned from a function into variables as such:
>
> ```cpp
> auto[a, b] = func(); // func returns (int a, int b)
> ```

### Templates

Templates are also explained best by using examples:

```cpp
template <typename T> void Print(T value) { std::cout << value << std::endl; }

template <typename T, int N> class Array {
private:
    std::array<T, N> arr;

public:
    int GetSize() { return arr.size(); }
};

Array<std::string, 5> arr;
// std::cout << arr.GetSize() << std::endl;

// Let's print an array
template <int length> void PrintArray(const std::array<int, length> &array) {
    int i;
    for (i = 0; i < array.size(); i++) {
        std::cout << array[i] << std::endl;
    }
}

std::array<int, 9> array = {1, 2, 3, 4, 5, 6, 7, 8, 9};
PrintArray<array.size()>(array);
```

### Compiler Directives: `#define`, `#if`, `#elif`, `#endif`

```cpp
#define WAIT std::cin.get()
#define DEBUG 1
// #define RELEASE 1

#if DEBUG == 1
// macro with parameter
#define Log(x) std::cout << x << std::endl
#elif defined(RELEASE)
#define Log(x) std::cout << "In RELEASE mode" << std::endl
#else
// removes the text all together
#define Log(x)
#endif

#if 0
    std::cout << "I wanna make this line removable using macros!" << std::endl;
#endif
```

### Namespaces

> [!WARNING]
> Never use `using namespace std`. Never use namespaces in headers.

```cpp
namespace apple {
namespace functions {
void Print() { std::cout << "Apple" << std::endl; }
} // namespace functions
} // namespace apple

namespace orange {
void Print() { std::cout << "Orange" << std::endl; }
} // namespace orange

int main() {
    apple::functions::Print();
    orange::Print();

    // using namespace apple::functions;
    // this allows us to use Print() directly as shown below
    // Print();

    // using orange::Print; // this allows us to use Print() function directly
    // (note that the entity at the end is a function and not a namespace!!!)
    // Print();

    namespace a = apple::functions; // this is an alias
    a::Print();
}
```

### Other Miscellaneous Implementations

```cpp
#include <algorithm>

std::reverse(temp.begin(), temp.end()); // reverses the string/arrays/vectors/etc


std::vector<int> vec = {1, 2, 3, 4, 5};

// finds and returns an iterator if found
// if not found then it returns the pointer to vec.end() which is
// beyond the range of vec! we must always manually check if problems
// like this arise!
// to just check if an element is there or not, use std::any_of
auto it =
  std::find_if(vec.begin(), vec.end(), [](int value) { return value > 3; });

std::vector<int> vec = {2, 4, 3, 5, 1};
// std::sort(vec.begin(), vec.end()); // sorts in ascending order by default
std::sort(vec.begin(), vec.end(), [](int a, int b) {
    if (a == 1) {
        return false;
    } else if (b == 1) {
        // returning true means you put a before b and vice-versa
        return true;
    } else {
        return a < b;
    }
});
```

```cpp
#include <functional>

void ForEach(const std::vector<int> &values,
             const std::function<void(int)> &func) {
    for (int value : values) {
        func(value);
    }
}

// function pointer
auto function = PrintValue;

std::vector<int> vec = {1, 2, 3, 4, 5};
ForEach(vec, function);

// We can achieve the same using lambda functions.
// If you don't pass anything in the first square brackets, no variable from
// the outer scope gets imported into the lambda function. We can pass multiple
// arguments into lambda using [a, &b, ...],
// = -> everything by value,
// & -> everything by reference
ForEach(vec, [](int value) { std::cout << value << std::endl; });
```

### Threads

We need `#include <thread>` in order to use threading.

```cpp
#include <thread>

static bool s_Finished = false;

void DoWork() {

    std::cout << "Started thread with id = " << std::this_thread::get_id()
            << std::endl;
    while (!s_Finished) {
        std::cout << "Working..." << std::endl;
        std::this_thread::sleep_for(1s);
    }
}

int main() {
    std::cout << "Started thread with id = " << std::this_thread::get_id()
            << std::endl;

    // starts a new thread with the name "worker"
    std::thread worker(DoWork);

    std::cin.get();
    s_Finished = true;

    // holds the current thread till the work in the "worker" thread is done
    worker.join();

    std::cin.get();

    std::cout << "Finished thread with id = " << std::this_thread::get_id()
            << std::endl;
}
```

### Chrono Statis (!)

In order to use [Chrono Statis][chronostasis] in this mortal world,
we need `#include <chrono>`.

```cpp
#include <chrono>

class Timer {
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> m_StartPoint;
public:
    Timer() {
        m_StartPoint = std::chrono::high_resolution_clock::now();
    }

    ~Timer() {
        Stop();
    }

    void Stop() {
        auto endTimePoint = std::chrono::high_resolution_clock::now();

        auto start = std::chrono::time_point_cast<std::chrono::milliseconds>(start)
                          .time_since_epoch()
                          .count();
        auto end = std::chrono::time_point_cast<std::chrono::microseconds>(end)
                        .time_since_epoch()
                        .count();

        auto duration = end1 - start1;
        std::cout << "Timer took " << duration << "ms" << std::endl;
    }
}

void Function() {
    Timer timer; // automatically gets destroyed when the scope ends and gives us
               // our benchmark metrics
    int i;
    for (int i = 0; i < 100; i++) {
        std::cout << i << std::endl; // removing endl has a huge improvement
    }
}

int main() {
  auto start = std::chrono::high_resolution_clock::now();
  std::this_thread::sleep_for(1s);
  auto end = std::chrono::high_resolution_clock::now();

  std::chrono::duration<float> duration = end - start;
  std::cout << duration.count() << "s" << std::endl;

  Function();
}
```

### Making 3d Arrays

```cpp
int main() {
    const int arr_size_1 = 5;
    const int arr_size_2 = 6;
    const int arr_size_3 = 7;
    int i, j, k;

    int *arr_new = new int[arr_size_1 * arr_size_2 * arr_size_3];

    for (i = 0; i < arr_size_1; i++) {
        for (j = 0; j < arr_size_2; j++) {
            for (k = 0; k < arr_size_3; k++) {
                arr_new[arr_size_2 * arr_size_3 * i + arr_size_3 * j + k]
                    = i + j + k;
            }
        }
    }

    delete[] arr_new;
}
```

### Type Casting

```cpp
// C style casts
double a = 9.5;
int b = a; // implicit casting
int c = (int)a; // explicit casting

// C++ style cast
int d = static_cast<int>(a);
```

### Pre-compiled Headers

> [!WARNING]
> I'm not sure about this section. The commands were suggested to me
> by an LLM and I'm too lazy to look into how pre-compiled headers work right now.

In order to use pre-compiled headers in C++, we need to compile the
pre-compile header (.h) file that contains all the imports using the command
`g++ -std=c++14 pch.h` and then add
`target_precompile_headers(PROJECT_NAME PRIVATE "${source_dir}/pch.h")` to
`CMakeLists.txt`.

<!-- TODO: add links to important videos -->

## Features introduced in C++ 17

### `std::optional`

```cpp
#include <optional>

std::optional<std::string> ReadFileAsString(const std::string &filepath) {
    std::ifstream stream(filepath);
    // if file is successfully opened, then this if block is run
    if (stream) {
        std::string result;
        // read the file
        stream.close();
        return result;
    }

    // otherwise return an empty std::optional
    return {};
}

int main() {
    std::optional<std::string> data = ReadFileAsString("data.txt");
    std::string value = data.value_or("Not present!");
    std::cout << value << std::endl;
    if (data) {
        std::cout << "File read successfully!" << std::endl;
    } else {
        std::cout << "File couldn't be accessed!" << std::endl;
    }
    std::cin.get();
}
```

### `std::variant`

```cpp
#include <variant>

std::variant<std::string, int> newdat;
newdat = "bubu";
newdat.index();
// this tell us which index the data is being stored in
// for this case, it returns 0 as the datatype is string
newdat = 1;
newdat.index();
// for this case, it returns 1 as the datatype is int

// this gets the string value from newdat, given that the type is string and
// otherwise throws an error (probably)
std::get<std::string>(newdat);

// this returns nullptr if the data is not of the mentioned type and otherwise
// returns the pointer to the string
if (auto newval = std::get_if<std::string>(&newdat)) {
    std::string &v = *newval;
} else {
// ...
}

enum ErrorCode { NoError = 0, NotFound = 1 };

std::variant<std::string, ErrorCode> ReadFileAsStringNew() {
    if (1) {
        return "file read successfully!";
    } else {
        return NotFound;
    }
}
```

### String Optimizations

```cpp
#include <string_view>

std::string name = "Yan Chernikov";
std::cout << name.substr(0, 3) << std::endl;
// string allocations are slow
// every time you use substr, it makes a new string.
// instead of that, we use a string_view this makes no allocations
std::string_view first_name(name.c_str(), 3);
std::string_view last_name(name.c_str() + 4, 9);
```

### `std::move`

Think of this as stealing the data from one variable and putting that
into another variable. The variable from which the data is being stolen is
rendered empty after using move.

```cpp
std::string meow = "meow";
std::string neow;

std::cout << "Meow: " << meow << std::endl;
std::cout << "Neow: " << neow << std::endl;

neow = std::move(meow);

std::cout << "Meow: " << meow << std::endl;
std::cout << "Neow: " << neow << std::endl;
```

### `std::map` and `std::unordered_map`

`std::map`, as it suggests, is an ordered map. The ordering is based with respect
to the keys.

```cpp
struct CityRecord {
  int population;
  float area;
};

// this is an unordered_map
std::unordered_map<std::string, CityRecord> city_map;

// this is a ordered map
// std::map<typename Key, typename Tp>

city_map["kolkata"] = CityRecord{100, 10.0f};
city_map["delhi"] = CityRecord{100, 10.0f};
city_map["chennai"] = CityRecord{100, 10.0f};
city_map["mumbai"] = CityRecord{100, 10.0f};

CityRecord &koldata = city_map["kolkata"];
std::cout << koldata.population << std::endl;

// we use .at everywhere unless we want to modify the data
// (we prepend the const word too)
// if we just want to read the data and not modify it, we can do it in this way:
const auto &cities = city_map;
const CityRecord &newkol = cities.at("kolkata");

if (cities.find("kolkata") != cities.end()) {
    printf("Data found!\n");
    // we delete the city
    city_map.erase("kolkata");
    printf("Data deleted!\n");
}

// iterating through maps
for (auto [name, city] : city_map) {
std::cout << name << " and " << city.population << ", " << city.area
          << std::endl;
}
```

## Features introduced in C++ 19

### Logging functions

```cpp
std::string string = std::format("Hello {} (AKA {})", "Avigyan", "Bubu");

// println can directly format strings
std::println("Hello {} (AKA {})", "Avigyan", "Bubu");
std::print("No new line character at the end!");

std::cout << string << std::endl;
```

### Exception Handling

```cpp
// the first datatype is the datatype of the result and the second one is for
// the type of the error (structs are mostly used for this)
std::expected<int, std::string> divide(int a, int b) {
    if (b == 0) {
        return std::unexpected("cannot divide by 0");
    }
    return a / b;
}

// we use transform instead of and_then if we know that we know something
// won't go wrong
// if something goes wrong in and_then, then the flow is passed to or_else too
auto result = divide(12, 0)
                .and_then([](int result) { return divide(result, 2); })
                .or_else([](const std::string &error) {
                  std::println("Error: {}", error);
                  return std::expected<int, std::string>{69};
                });
std::println("result = {}", *result);
```

[chronostasis]: https://blackclover.fandom.com/wiki/Chrono_Stasis
