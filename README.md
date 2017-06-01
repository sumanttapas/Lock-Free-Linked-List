# Lock-Free-Linked-List
This repository contains code and information to use a multi-threaded lock free linked list in a big project.

The repository contains the following files:

1. LockFreeListFinal.cpp: This file contains all the source code to implement the linked list.
2. LockFreeListFinal.h: This is header file which contains the structures, constants and function declaration.
3. testProgramIni.cpp: This is a initial test program to test the integrity of the code.
4. Makefile: This is the initial GNU make file. Use this make file to test the testProgramIni.cpp program.

###API call details:

Each element in the list holds a integer key and a void pointer to a value. The structure also contains additional variables which the user should not change. Additionally, the list is designed to hold unique key values sorted in non-decreasing order. So, duplicate keys would be simply ignored.

First step is to initialise the list head and tail element. The function to do this is *list_init()*.
The correct way to use init function is follows:
```
List mylist = list_init();  
```
*mylist* holds the head and tail elements of the list. From here onward, any mention of *head* pointer should be considered as *mylist->head*. 

####Function prototypes:

1. *node_lf \* Search(int key, node\_lf \* head)*: *Search()* returns pointer to the element if it is found, else it returns NULL. The arguments to *Search()* function is a interger key associated with the element to be searched and a pointer to the head of the list. It should be noted and the head of the list can be accessed by *mylist->head* (as mentioned above).

2. *int insert(int key, node\_lf \* head, void \* value)*: *insert()* inserts element into the sorted list. *insert()* function returns 0 on success and -1 on failure. The arguments to *insert()* function are an integer key, a void pointer to a value and a pointer to the head of the list.

3. *int delete\_node(int key, node\_lf \* head)*: *delete\_node()* deletes the specified node from the list. On success this functions returns 0 and -1 on failure. Arguments to *delete\_node()* are an integer key and a pointer to the head of the list.

4. *void \* printlist(node\_lf \* head)*: *printlist()* prints the integer keys associated with each element in the list. Argument to this function is a pointer to the head of the list.

5. *void destroy(node\_lf \* head)*: *destroy()* function frees up the **all** the memory used by the list. So, *destroy()* function is like a destructor for the list. The argument is a pointer to the head of the list.  

It should be noted that all the functions mentioned above can be accessed by the *mylist* list variable created in the initialization function. 
The way to access the function is as follows:
```
mylist->search(int key, node_lf * head);
mylist->insert(int key, node_lf * head, void * value);
mylist->delete_node(int key, node_lf * head);
mylist->print(node_lf * head);
mylist->destructor(node_lf * head);

```

For any doubts on using the list please refer to the testprogramini.cpp file or leave a comment on the blog and we would get back to you.
