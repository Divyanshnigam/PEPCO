# PEPCO
## Data Structures and Algorithms

# Linked List 
Linked List is a linear collection of the data elements. It is a data structure consisting of collection of nodes which together represent the sequence. Each node consists of:

o	Data 

o	Reference (Address to next node) 
 
<h2>Features of Linked List</h2>

 •	Structure of Linked List allows the efficient insertion or removal of an element at any position

 •	Access time is linear in Linked List
 
 •	Random access is not feasible in Linked List 
 
 •	Arrays have better cache locality compared to Linked List 

<b>Cache Locality (Locality of Reference or Principal of Locality)</b>

Tendency of a processor to access same set of memory location repetitively over a shorter period of a time. 

<h2>Benefit of a Linked List over an Array.</h2> 

The list items could be easily removed or re-inserted without any reallocation or reorganization of an entire structure because data items could not be restored continuously in the disk, while restructuring in an array is a long process. Linked Lists are dynamic, so the length of the list can be increased or decreased depending upon situation. However, the length of the array remains same as that at the time of declaration and cannot be changed. It is costly to insert and delete elements in an array. 

In Linked List Memory allocation is done during the run time. Thereby, Linked List uses dynamic memory allocation. 

<h2> Applications of Linked List </h2>

1. Process queue in operating system, actually doubly linked list of process in ready state. There by, it process at the front of linked list denotes the one to be operated next
2. Where insertion and deletion is greater than retrievels 

<h2> Insertion in the Linked List </h2>

Insertion in the Linked List, is a proccess of adding elements in the Linked List. Insertion in the Linked List is of three types:

1. Insert at Head 

2. Insert at Tail 

3. Insert in Middle 

<h2> Deletion in the Linked List </h2>

Deletion in the Linked List, is a process of removing the elements from the Linked List. Deletion is of three types:

1. Deletion at the Head 

2. Deletion at the Tail 

3. Deletion in the Middle 

<h2> Searching in the Linked List </h2>

Searching , is a process of Searching elements in the Linked List. Search could be done by:
 
 1. Iteration 
 
 2. Recursion 
 
 <h2> Reversing the Linked List </h2> 
 
 Reversing, is a process of changing the order of elements in the linked list. Reversing is done by:
 
 1. Iteration 
 
 2. Recursion 
 
 <h2> Operator Overloading in the Linked List </h2>
 
 Operator overloading, is a process of overloading in order to perform specific operation in the list. 
 
 <h2> Printing the Linked List </h2> 
 
 A special customized loop is setup, to print up the elements in the linked list and print the value in it till NULL is reached. 
 
 <h2> Why Merge Sort is preffered for Linked List </h2>
 
 The reason behind this is:
 
 1. The complexity of the Merge sort remain as that of O(nlogn) despite the fact that, we find the mid-point in the Linked List 
 
 2. In Linked List, we can insert a node in between in O(1) time and space complexity ; if we are given reference to the previous node 
 
 3. We do not have random access to elements in the Linked List 
 
 4. Linked List follows sequential pattern, while reffering to any node. So, that could be a overhead for quick sort. Merge sort access the data sequentially. 
 
 <h2> Circular Linked List </h2>
 
 When the tail node points to the head node instead of pointing to the NULL Pointer; then that linked list is called as Circular Linked List. 
 
 Some of the Applications of the Circular Linked List are:
 
 1. In many C.P.U Algorithm, you need Circular Linked List to perform a given operation multiple times 
 
 2. In the implementation of forming different types of Queue 
 
 3. In the implementation of the advanced algorithm such as Fibonacci Heap 
 
<h2> List STL Functions </h2>

List is included in the given C++ Program. The function is there to add all its utility and is managed 

<h3> Push_Back() </h3>

This function is used to add the elements at the end of the list 

<h3> Sort() </h3>

This function is used to sort the given list 

<h3> push_front() </h3>

This function is used to add the element at the front of the list 

<h3> pop_back() </h3>

As, the name goes; This function removes the last element from the list 

<h3> pop_front() </h3>

This function removes the first element from the list 

<h3> insert(position,element) </h3>

This function is used to insert the element in the linked list 

<h3> erase(position) </h3>

This function is used to remove the element in the given list 

<h3> remove(element) </h3>

This function removes the given element from the list 

<h3> front() </h3>

This function is used to print the first element in the list 

<h1> Stack </h1>

Stack is a data structure, which represents the collection of the objects. A item could be added and stored in a stack using push operation. An object can be retrieved using pop operation, to remove an item from the stack. A item could be inserted at the top of the stack. A item could be either removed either from top or bottom of the stack. Their are two types of stack:

1. LIFO(Last In First Out)
2. FIFO(First In First Out)

Stack could be explained with the help of real life examples:

1. Stack of books 
2. ATM Machine 
3. Pile of Plates 

<b> Vectors are resizable arrays </b> 

In a stack, we can follow operations such as push(), pop(), remove(), empty(). 

FIFO stack is basically a type of Queue. 

Stacks have several applications in the Computer Programming. LIFO is used to retrieve, recently used objects from cache. FIFO stacks is used to ensure the data is retrieved in the order it was entered. Stacks are basically created at the background, while application was running in front. If stack, runs out of memory such situation is termed as <b> Stack Overflow </b>.

<h2> Genralizaition of Stack </h2>

A stack could be generalized using templated class <b> template <Typename T> </b> . You can generalize the given code in a following way as told in file <b>generalization of stack </b>
	
<h1> QUEUES </h1>
 Queue is a data structure designed to operate in FIFO (First in First out) context. In queue elements are inserted from rear end and get removed from front end operations called <b>'enqueued'</b> and <b>'dequed'</b> respectively. Queue class is container adapter. Container is an objects that hold data of same type. Queue can be created from different sequence containers.
 
 <h4> There are two ways to implement Queues</h4>
 
   1. Circular Array based 
   2. Linked List based 
   
   <b>Out of the two Circular Array based implementation is quite lengthier than the Linked List based implementation.</b>
   
   <b>Note:</b> In a circular array (n-1) position is adjacent to the first element of the circular array. 
   
   <b>Applications:</b> Queue is used for maintaining the whatsapp status messages, placing the delivery order on e-commerce sites like flipkart, amazon or myntra. 
   
   <h4> STL Operations in Queue </h4> 
   
   1. q.push() : Adds element in the list 
   2. q.front() : Returns the first element 
   3. q.pop() : Removes the element 
   4. q.empty() : Check wheather the queue is empty or not 
   
   <h4> Deque </h4>
   
   1. In Deque, insertion and deletion could be done from both the ends.
   2. Deque are the sequence containers with dynamic size, that can be expanded or contracted at both the ends 
   3. Some functionalities are much more in deque. As, we can extend the vector only in one direction 
   4. Deque can extend in both the direction like linked list 
   5. Deque does not contain an internal storage. Deque are more complex than vector internally
   6. In certain operations where insertion or deletion is done at a positon other than begining or end. In such situation, Deque perform the worst. 
   
   <h1> Binary Trees </h1>
   
Binary Trees are build using recursion. It is a top-down appraoch. 

<b> Algorithm </b>

   1. Build a root 
   2. Recursively build left and right subtree 
   
<b> More info about Binary Tree </b>

   Binary Operation such as Insertion, Deletion, Search, Ordering decide which Data Structure is helpful for a particular problem. As the name goes, in Binary Trees atleast one    node should be connected to atleast 2 nodes. The nodes in the Binary Trees is connected using the adress. The basic node is called as the root node. And , the subsequents of    root node are called as children node. Moreover, the nodes which do not have any children are called as Leaf Nodes. 
   
   The different types of Traversal in a Binary Tree are:
   
   1. In-Order Traversal ( ROOT - > LEFT - > RIGHT )
   2. Pre-Order Traversal ( LEFT - > ROOT - > RIGHT )
   3. Post-Order Traversal ( LEFT - > RIGHT - > ROOT )
   4. Level-Order Traversal ( Recursive Approach )
  

     /desktop   <-- root
     
    /            \
    
  
...       
                     
                     my computer

                  /                \
      
          local (c):           local (d):
   
           /                  /      |       \
    
       ...                  prg1    prg2       prg3
  
  
   A skew tree is one where each root node has one child node or no node. In case of a Skew Tree, it takes O(n) time to calculate the value or the hieght of the given tree.
   
   Some common problems in the Binary Tree:
   
   1. Counting Number of Nodes in the Binary Tree
   2. Finding the longest chord in the Binary Tree
   3. Binary Tree Sum Replacement 
   4. Height Balanced Binary Tree
   5. Nodes at Distance K from Given Node 
   6. Lowest Common Ancestor 
   7. Maximum Sum Path from Any Node to Node 
   8. Shortest Distance between the Nodes of the Binary Tree 
   
   Priority Queue STL is used to work efficiently when we need to code to find the output based on some term and condition. For eg, When you go to bank and they say that they 	    would do the work first for the persons who are more than 70 years of age and there are 1000 people standing in queue. So, that is a way they could easily priortize and add      the people. 
   
<h1> What is the purpose of Hash Data Structure </h1>
	
Hash Map is their to do support insertion, deletion, and search in average case-constant time O(1) time complexity. This data is not useful if you want to do some kind 	of an order of an element.
	
Hash ["string key"] ==> Integer Value 

Array is the simplest kind of hashing because, in an array we maintain index and a value. Hash Table is an array of a fixed size. 

<b> Operations in Hash Table </b>

Insert - T[h(key)] = value
Delete - T[h(key)] = NULL
Search - return T[h(key)]

If h("John") = h("Joe") then collision cannot be avoided. Collision cannot be avoided only its chances can be reduced by using a good hash function. 

A "good hash function" has following properties:

1. Reduce a chance of collision - Distribute Key Uniformly over the Table
2. Should be fast to compute

<b> How Hash Table is build </b>

h(key) = key % tablesize


