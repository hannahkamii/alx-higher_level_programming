
3. Properties vs. Getters and Setters
By Bernd Klein. Last modified: 01 Feb 2022.

Properties
Getters(also known as 'accessors') and setters (aka. 'mutators') are used in many object oriented programming languages to ensure the principle of data encapsulation. Data encapsulation - as we have learnt in our introduction on Object Oriented Programming of our tutorial - is seen as the bundling of data with the methods that operate on them. These methods are of course the getter for retrieving the data and the setter for changing the data. According to this principle, the attributes of a class are made private to hide and protect them.

Unfortunately, it is widespread belief that a proper Python class should encapsulate private attributes by using getters and setters. As soon as one of these programmers introduces a new attribute, he or she will make it a private variable and creates "automatically" a getter and a setter for this attribute. Such programmers may even use an editor or an IDE, which automatically creates getters and setters for all private attributes. These tools even warn the programmer if she or he uses a public attribute! Java programmers will wrinkle their brows, screw up their noses, or even scream with horror when they read the following: The Pythonic way to introduce attributes is to make them public.

Venetian Masks: Properties are like Masks

We will explain this later. First, we demonstrate in the following example, how we can design a class in a Javaesque way with getters and setters to encapsulate the private attribute self.__x:

class P:
    def __init__(self, x):
        self.__x = x
    def get_x(self):
        return self.__x
    def set_x(self, x):
        self.__x = x
We can see in the following demo session how to work with this class and the methods:

from mutators import P
p1 = P(42)
p2 = P(4711)
p1.get_x()
OUTPUT:
42
p1.set_x(47)
p1.set_x(p1.get_x()+p2.get_x())
p1.get_x()
OUTPUT:
4758
What do you think about the expression "p1.set_x(p1.get_x()+p2.get_x())"? It's ugly, isn't it? It's a lot easier to write an expression like the following, if we had a public attribute x:

p1.x = p1.x + p2.x
Such an assignment is easier to write and above all easier to read than the Javaesque expression.

Let's rewrite the class P in a Pythonic way. No getter, no setter and instead of the private attribute self.__x we use a public one:

class P:
    def __init__(self,x):
        self.x = x
Beautiful, isn't it? Just three lines of code, if we don't count the blank line!

from p import P
p1 = P(42)
p2 = P(4711)
p1.x
OUTPUT:
42
p1.x = 47
p1.x = p1.x + p2.x
p1.x
OUTPUT:
4758
"But, but, but, but, but ... ", we can hear them howling and screaming, "But there is NO data ENCAPSULATION!" Yes, in this case there is no data encapsulation. We don't need it in this case. The only thing get_x and set_x in our starting example did was "getting the data through" without doing anything additionally.

But what happens if we want to change the implementation in the future? This is a serious argument. Let's assume we want to change the implementation like this: The attribute x can have values between 0 and 1000. If a value larger than 1000 is assigned, x should be set to 1000. Correspondingly, x should be set to 0, if the value is less than 0.

It is easy to change our first P class to cover this problem. We change the set_x method accordingly:

class P:
    def __init__(self, x):
        self.set_x(x)
    def get_x(self):
        return self.__x
    def set_x(self, x):
        if x < 0:
            self.__x = 0
        elif x > 1000:
            self.__x = 1000
        else:
            self.__x = x
The following Python session shows that it works the way we want it to work:

from mutators1 import P
p1 = P(1001)
p1.get_x()
OUTPUT:
1000
p2 = P(15)
p2.get_x()
OUTPUT:
15
p3 = P(-1)
p3.get_x()
OUTPUT:
0
But there is a catch: Let's assume we designed our class with the public attribute and no methods:

class P2:
    def __init__(self, x):
        self.x = x
People have already used it a lot and they have written code like this:

p1 = P2(42)
p1.x = 1001
p1.x
OUTPUT:
1001
If we would change P2 now in the way of the class P, our new class would break the interface, because the attribute x will not be available anymore. That's why in Java e.g. people are recommended to use only private attributes with getters and setters, so that they can change the implementation without having to change the interface.

But Python offers a solution to this problem. The solution is called properties!

The class with a property looks like this:

class P:
    def __init__(self, x):
        self.x = x
    @property
    def x(self):
        return self.__x
    @x.setter
    def x(self, x):
        if x < 0:
            self.__x = 0
        elif x > 1000:
            self.__x = 1000
        else:
            self.__x = x
A method which is used for getting a value is decorated with "@property", i.e. we put this line directly in front of the header. The method which has to function as the setter is decorated with "@x.setter". If the function had been called "f", we would have to decorate it with "@f.setter". Two things are noteworthy: We just put the code line "self.x = x" in the __init__ method and the property method x is used to check the limits of the values. The second interesting thing is that we wrote "two" methods with the same name and a different number of parameters "def x(self)" and "def x(self,x)". We have learned in a previous chapter of our course that this is not possible. It works here due to the decorating:

from p2 import P
p1 = P(1001)
p1.x
OUTPUT:
1000
p1.x = -12
p1.x
OUTPUT:
0
Alternatively, we could have used a different syntax without decorators to define the property. As you can see, the code is definitely less elegant and we have to make sure that we use the getter function in the __init__ method agai
