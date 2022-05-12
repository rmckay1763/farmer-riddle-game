# Farmer Riddle Game

### **Synopsis**
A console program that implements the classic riddle where a farmer must get a chicken, fox, and grain across a river.

---

### **Riddle**
A farmer must take a chicken, a fox, and a sack of grain across a river. The farmer can take one item at a time when he crosses, or he can cross by himself. If the farmer leaves the chicken and the fox together, the fox will eat the chicken. If the farmer leaves the chicken and the grain together, the chicken will eat the grain. How can the farmer get all items safely across the river?

---

### **Objective**
Implement a program that allows the user to play the game and solve the riddle. Define a data structure to maintain the farmer's items.

---

### **Implementation**
The program defines three classes:
- `BankList` - Singly linked list of strings to represent the items on a bank of the river.
- `River` - Represents the river. Maintains a BankList for the north and south banks.
 - `Farmer` - Represents the farmer. Defines available actions.

The `driver` instantiates data structures and executes a menu based program that allows the user to play multiple times.

---

### **Usage**
The `Makefile` provides a target to execute the program, compiling any dependent files if necessary:
```
make run
```
See the `Makefile` for additional targets.
