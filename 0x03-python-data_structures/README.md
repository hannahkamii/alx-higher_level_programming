You can assume that the list only contains integers
You are not allowed to cast integers into strings
You have to use str.format() to print integers
guillaume@ubuntu:~/0x03$ cat 0-main.py
#!/usr/bin/python3
print_list_integer = __import__('0-print_list_integer').print_list_integer

my_list = [1, 2, 3, 4, 5]
print_list_integer(my_list)

guillaume@ubuntu:~/0x03$ ./0-main.py
1
2
3
4
5
guillaume@ubuntu:~/0x03$ 
Repo:

GitHub repository: alx-higher_level_programming
Directory: 0x03-python-data_structures
File: 0-print_list_integer.py
    
1. Secure access to an element in a list
mandatory
Score: 0.0% (Checks completed: 0.0%)
Write a function that retrieves an element from a list like in C.

Prototype: def element_at(my_list, idx):
If idx is negative, the function should return None
If idx is out of range (> of number of element in my_list), the function should return None
You are not allowed to import any module
You are not allowed to use try/except
guillaume@ubuntu:~/0x03$ cat 1-main.py
#!/usr/bin/python3
element_at = __import__('1-element_at').element_at

my_list = [1, 2, 3, 4, 5]
idx = 3
print("Element at index {:d} is {}".format(idx, element_at(my_list, idx)))

guillaume@ubuntu:~/0x03$ ./1-main.py
Element at index 3 is 4
guillaume@ubuntu:~/0x03$ 
Repo:

GitHub repository: alx-higher_level_programming
Directory: 0x03-python-data_structures
File: 1-element_at.py
    
2. Replace element
mandatory
Score: 0.0% (Checks completed: 0.0%)
Write a function that replaces an element of a list at a specific position (like in C).

Prototype: def replace_in_list(my_list, idx, element):
If idx is negative, the function should not modify anything, and returns the original list
If idx is out of range (> of number of element in my_list), the function should not modify anything, and returns the original list
You are not allowed to import any module
You are not allowed to use try/except
guillaume@ubuntu:~/0x03$ cat 2-main.py
#!/usr/bin/python3
replace_in_list = __import__('2-replace_in_list').replace_in_list

my_list = [1, 2, 3, 4, 5]
idx = 3
new_element = 9
new_list = replace_in_list(my_list, idx, new_element)

print(new_list)
print(my_list)

guillaume@ubuntu:~/0x03$ ./2-main.py
[1, 2, 3, 9, 5]
[1, 2, 3, 9, 5]
guillaume@ubuntu:~/0x03$ 
Repo:

GitHub repository: alx-higher_level_programming
Directory: 0x03-python-data_structures
File: 2-replace_in_list.py
    
3. Print a list of integers... in reverse!
mandatory
Score: 0.0% (Checks completed: 0.0%)
Write a function that prints all integers of a list, in reverse order.
