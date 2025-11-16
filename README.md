# Doubly Linked List Practice Project

## 📌 Definition: What Is a Doubly Linked List?
A **Doubly Linked List (DLL)** is a dynamic data structure made up of nodes, where each node stores:
- Data  
- A pointer to the **next** node  
- A pointer to the **previous** node  

This two-directional structure makes insertion, deletion, and traversal more flexible compared to singly linked lists.

---

# 🚀 Project Overview  
This project is a **hands-on implementation** of a fully functional, templated `DoublyLinkedList<T>` class in C++.  
It helped me practice:
- **Data Structures fundamentals**
- **Deep internal understanding** of how DLLs work under the hood
- **Problem-solving** through iterative debugging
- **Object-Oriented Programming (OOP)** concepts (encapsulation, abstraction, copy constructor, method overloading)

---

# ⭐ STAR Method Breakdown

## **S — Situation**
I wanted to reinforce my understanding of linked lists, especially **how pointers form connections** and how operations like insertion, deletion, and reversing actually work inside memory.

---

## **T — Task**
Build a **clean, reusable, and fully manual implementation** of a Doubly Linked List that would allow me to:
- Control every pointer update  
- Debug pointer changes step-by-step  
- Understand the real internal mechanics beyond textbook theory  
- Practice writing and maintaining production-style data structures

---

## **A — Action**
I implemented the entire DLL manually, including:
- Node class with getters/setters  
- Insertions (head, tail, after index, after node)  
- Deletions (head, tail, specific value, delete after)  
- Search, update, and traversal functions  
- Full reverse algorithm using pointer-swapping  
- Safety helpers like index validation  
- Deep-copy constructor to practice OOP cloning behavior  

Each method was built to show:
- How pointers move  
- What happens to `previous` and `next`  
- What edge cases look like internally

---

## **R — Result**
By completing this project:
- I fully internalized how DLLs behave in memory  
- Improved my debugging and pointer management skills  
- Strengthened problem-solving through iterative corrections  
- Practiced clean, modular OOP design  
- Created a reusable data structure for future projects  

This project ensured I no longer see a Doubly Linked List as “just a diagram,”  
but as a **living structure built through precise pointer logic**.

---

# 🎯 Project Goals
✔ Understand how doubly linked lists work internally  
✔ Strengthen OOP principles through real implementation  
✔ Improve memory and pointer debugging skills  
✔ Practice building data structures from scratch  
✔ Develop algorithmic thinking through operations like reverse, delete, and traversal  

---

# 🛠 How to Use the Project
1. Include `DoublyLinkedList.h` in your C++ file.  
2. Create a list using any data type:

```cpp
DoublyLinkedList<int> list;
list.insertAtHead(10);
list.insertAtTail(20);
list.display();   // 10 <-> 20
```

3. Experiment with operations to understand internal pointer behavior.

---

# 📚 Why This Project Matters
Building data structures manually is one of the best ways to:
- Become better at problem solving  
- Understand memory deeply  
- Improve performance intuition  
- Strengthen software engineering foundations  

This project is part of my journey to become a **stronger Backend developer** with solid mastery of DSA & OOP.

---

# 🙌 Feel Free to Explore & Contribute!
This project reflects my ongoing learning journey — feedback and ideas are always welcome!

