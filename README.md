# Push_Swap

Push_Swap is a program written in C that sorts integers using a minimal number of operations on two stacks, following a set of predefined rules. This project challenges the implementation of efficient algorithms and the understanding of computational complexity.

---

## **Features**

- **Two Stacks**: Utilizes two stacks (`a` and `b`) for sorting.
- **Efficient Sorting**: Produces the smallest sequence of operations to sort the integers in ascending order.
- **Custom Instructions**: Includes stack-specific operations such as `swap`, `push`, `rotate`, and `reverse rotate`.
- **Error Handling**: Validates input, ensuring no duplicates and all arguments are valid integers.

---

## **Usage**

### **Compilation**

Use the provided `Makefile` to compile the program:

```bash
make
```
This generates the executable push_swap

---

### **Running the Program**
Run push_swap with a list of integers as arguments:
```bash
./push_swap <list_of_integers>
```

---

### **Examples**
Sorting a list of integers:
```bash
./push_swap 2 1 3 6 5 8
# Output:
# sa
# pb
# pb
# ...
```

---

## **Rules**

- **Stack Operations**:
- sa / sb / ss: Swap the top two elements of stack a, b, or both.
- pa / pb: Push the top element from one stack to another.
- ra / rb / rr: Rotate stack a, b, or both (shift all elements up by 1).
- rra / rrb / rrr: Reverse rotate stack a, b, or both (shift all elements down by 1).

- **Stack Operations**:
- Arrange integers in ascending order in stack a with stack b empty.

- **Output**:
- A sequence of instructions, separated by newline characters, to achieve the sorting.

---

## **Error Handling**
The program handles and outputs errors for:
- Non-integer or invalid arguments.
- Duplicate integers in the input.
- Integers exceeding the valid range (INT_MIN to INT_MAX).

---

## **Performance Benchmark**
- 100 Integers: ≤ 700 operations.
- 500 Integers: ≤ 5500 operations.
Meeting these benchmarks ensures optimal performance and project validation.
