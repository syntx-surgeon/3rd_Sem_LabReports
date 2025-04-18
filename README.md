# 3rd Semester Lab Reports

This repository contains laboratory reports and implementations for various courses in the third semester. It includes practical implementations, algorithms, and documentation for different subjects.

## Course Structure

### 1. Computer Graphics
Implementation of various computer graphics algorithms and techniques:
- Basic Drawing Algorithms
  - DDA Algorithm
  - Bresenham's Algorithm
  - MidPoint Circle Algorithm
  - MidPoint Ellipse Algorithm
- 2D Transformations
  - Translation
  - Rotation
  - Scaling
  - Shearing
  - Reflection
- 3D Transformations
  - Translation
  - Rotation
  - Scaling
  - Shearing
- Clipping Algorithms
  - Cohen-Sutherland Line Clipping
  - Liang-Barsky Line Clipping
  - Sutherland-Hodgman Polygon Clipping
- Hidden Surface Algorithms
  - Back Face Detection
  - Z-Buffer Algorithm
  - A-Buffer Algorithm
  - Painter's Algorithm
- Other Algorithms
  - Scan Line Algorithm
  - Polygon Fill Algorithm

### 2. Computer Architecture
Implementation of computer architecture concepts and digital logic:

#### C and C++ Programs
- Arithmetic Operations
  - One's and Two's Complement
  - Signed Magnitude Multiplication
  - Booth's Multiplication Algorithm
  - Restoring Division
  - Non-Restoring Division

#### Xilinx-based Programs
- Basic Logic Components
  - Logic Gates Implementation
  - Half Adder and Full Adder
  - Encoder and Decoder
  - 4:1 Multiplexer and 1:4 Demultiplexer
  - 4-Bit ALU (Arithmetic Logic Unit)

#### Hardware Implementations
- Digital Logic Design
  - Combinational Circuits
  - Sequential Circuits
  - Arithmetic Circuits
- Computer Organization
  - ALU Operations
  - Memory Operations
  - Control Unit Design

### 3. Data Structures and Algorithms
Implementation of fundamental data structures and algorithms:
- Basic Operations
  - Factorial
  - Fibonacci
  - GCD
  - Tower of Hanoi
  - Tail Recursion
- Memory Management
  - malloc
  - calloc
  - realloc
- Data Structures
  - Stack
  - Queue (Linear)
  - Binary Search Tree
  - Singly Linked List
  - Doubly Linked List
- Searching Algorithms
  - Linear Search
  - Binary Search
- Sorting Algorithms
  - Bubble Sort
  - Selection Sort
  - Insertion Sort
- Advanced Algorithms
  - Dijkstra's Algorithm
  - Prim's Algorithm
  - Hashing (Linear, Double, Quadratic)
  - Postfix to Prefix Conversion

### 4. Numerical Methods
Implementation of various numerical methods and algorithms:

#### Lab 1: Root Finding Methods
- Bisection Method
- Fixed Point Method
- Newton-Raphson Method
- Newton-Horner's Method
- Secant Method

#### Lab 2: Interpolation and Curve Fitting
- Forward Difference
- Backward Difference
- Newton's Interpolation
- Lagrange Method
- Curve Fitting Methods:
  - Linear Equation Fitting
  - Polynomial Equation Fitting
  - Exponential Fitting

#### Lab 3: Numerical Integration and Differentiation
- Central Difference
- Divide Difference Table
- Composite Trapezoidal Rule
- Simpson's 1/3 Rule
- Simpson's 3/8 Rule

#### Lab 4: Ordinary Differential Equations
- Euler Method
- Heun's Method
- Runge-Kutta Method
- Solving System of Differential Equations using Heun-Method
- Second Order IVP
- Boundary Value Problem

#### Lab 5: Linear Algebra and Eigenvalues
- Gauss Elimination
- Gauss Jordan
- Gauss Seidel
- Jacobi Method
- Eigenvalue and Eigenvector Calculation

#### Next Lab (Lab 6): Advanced Topics
Topics to be covered:
- Partial Differential Equations
- Finite Difference Methods
- Finite Element Methods
- Numerical Optimization
- Error Analysis and Stability

### 5. Statistics II
Lab reports covering various statistical concepts:
- Lab 1: Basic Statistical Concepts
- Lab 2: Probability Distributions
- Lab 3: Hypothesis Testing
- Lab 4: Regression Analysis
- Lab 5: Correlation Analysis
- Lab 6: Analysis of Variance
- Lab 7: Advanced Statistical Methods

## File Organization

```
3rd_Sem_LabReports/
├── Computer Graphics/
│   ├── Basic Drawing/
│   │   ├── DrawLine_Function.c
│   │   ├── Bresenham's_Algorithm.c
│   │   ├── DDA.c
│   │   ├── MidPoint_CircleAlgorithm.c
│   │   ├── MidPoint_EllipseAlgorithm.c
│   │   ├── RectangleDraw.c
│   │   └── TriangleDraw.c
│   ├── 2D Transformations/
│   │   ├── 2D_Translation.c
│   │   ├── 2D_Rotation.c
│   │   ├── 2D_Scaling.c
│   │   ├── 2D_Shearing.c
│   │   └── 2D_Reflection.c
│   ├── 3D Transformations/
│   │   ├── 3D_Translation.c
│   │   ├── 3D_Rotation.c
│   │   ├── 3D_Scaling.c
│   │   └── 3D_Shearing.c
│   ├── Clipping Algorithms/
│   │   ├── Cohen_SutherLandLine_Clipping.c
│   │   ├── Liang_BarskyLine_Clipping.c
│   │   └── Sutherland_Hodgman_(Polygon_Clipping).c
│   └── Hidden Surface Algorithms/
│       ├── Back_Face_DetectionAlgorithm.c
│       ├── Z-BufferAlgorithm.c
│       ├── A-BufferAlgorithm.c
│       ├── Painter's_Algorithm.c
│       └── ScanLine_Algorithm.c
├── Computer Architecture/
│   ├── C and Cpp program/
│   │   ├── onestwosComplement.cpp
│   │   ├── Muliplication_Of_SignedMagnitude.c
│   │   ├── booth_Multiplication.cpp
│   │   ├── restoring.cpp
│   │   └── non-restoring.cpp
│   └── Xilinx_based_Programs/
│       ├── Logic_Gates
│       ├── HalfAdder__FullAdder
│       ├── Encoder__Decoder
│       ├── 4_1MUX___1_4DMUX
│       └── 4_BIT_ALU
├── Data Structure And Algorithm/
│   ├── Basic Operations/
│   │   ├── factorial.c
│   │   ├── fibonacci.c
│   │   ├── GCD.c
│   │   ├── TOH.c
│   │   └── Tail_Recursion.c
│   ├── Memory Management/
│   │   ├── malloc.c
│   │   ├── calloc.c
│   │   └── realloc.c
│   ├── Data Structures/
│   │   ├── stack.c
│   │   ├── linerqueue.c
│   │   ├── BST.c
│   │   ├── SinglyLInkedlistInsertion.c
│   │   └── DoublyLinkedListDelete.c
│   ├── Searching/
│   │   ├── LinearSearch.c
│   │   └── BinarySearch.c
│   ├── Sorting/
│   │   ├── BubbleSort.c
│   │   ├── SelectionSort.c
│   │   └── InsertionSort.c
│   └── Advanced Algorithms/
│       ├── DIjkstra.c
│       ├── Prim's.c
│       ├── DoubleAndQuadriticHashing.c
│       └── PostoRprefix.c
├── Numerical Methods/
│   ├── lab 1/ (Root Finding Methods)
│   ├── lab 2/ (Interpolation and Curve Fitting)
│   ├── lab 3/ (Numerical Integration and Differentiation)
│   ├── lab 4/ (Ordinary Differential Equations)
│   └── lab 5/ (Linear Algebra and Eigenvalues)
└── Stat II/
    ├── Stats_Lab_no1.docx
    ├── stats_lab_no_02.docx
    ├── stats (lab_no_3 ).docx
    ├── stats Lab no 4.docx
    ├── stats_lab_no_5.docx
    ├── STAT_LAB_06.docx
    └── Stats_Lab_07.docx
```

## How to Use

1. Navigate to the specific course directory
2. Each course has its own README with specific instructions
3. For programming assignments:
   - Source code is provided in respective directories
   - Compilation instructions are included in comments
4. For lab reports:
   - Documents are in .docx format
   - Follow standard academic formatting

## Development Environment

- Programming Languages: C, C++
- Tools: Xilinx, Microsoft Word
- Operating System: Windows

## Contributing

When adding new content:
1. Place files in appropriate course directories
2. Follow existing naming conventions
3. Include necessary documentation
4. Update relevant README files

## Version Control

This repository uses Git for version control to track changes and maintain a history of all lab reports and implementations.

## Contact

For any queries regarding these lab reports and implementations, please contact the repository owner.
Email:infobrb04@gmail.com

## License

### Academic License

Copyright (c) 2025 syntx-surgeon

This repository and all its contents are protected under the following terms:

1. **Academic Use**
   - All code, documentation, and lab reports are provided for academic purposes only
   - Students may use this material for learning and reference
   - Proper attribution must be given when using any part of this repository

2. **Restrictions**
   - Commercial use is strictly prohibited
   - Redistribution of this material without permission is not allowed
   - Modifications must be clearly marked and attributed

3. **Code Usage**
   - Code implementations may be used as reference for academic projects
   - Direct copying without understanding is discouraged
   - Students should implement their own solutions while learning from these examples

4. **Documentation**
   - Lab reports and documentation are for personal academic use
   - Plagiarism of any content is strictly prohibited
   - Proper citations must be used when referencing this material

5. **Disclaimer**
   - The author is not responsible for any misuse of this material
   - Use at your own risk and responsibility
   - Verify all implementations before use

For permissions beyond the scope of this license, please contact the repository owner.

---
Last Updated: [2025-4-17]
