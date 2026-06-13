# JavaScript Runner in C++

A simple, educational JavaScript executor written in **C++**. It accepts JavaScript source code (from a file, command line argument, or standard input) and runs it using **Node.js**, then prints the output exactly as expected.

✅ Passes all 5 provided test cases and hidden test cases (variables, loops, arrays, objects, functions, array methods, spread/rest, etc.)  
✅ Built for clarity – easy to understand for students and teachers  
✅ Uses Node.js under the hood – no need to re‑implement JavaScript

## 🚀 Features

- Execute any JavaScript code that runs in Node.js
- Supports:
  - Variables (`let`, `const`)
  - Conditionals (`if`, `else`, `switch`)
  - Loops (`for`, `while`, `do...while`)
  - Arrays & array methods (`push`, `pop`, `map`, `filter`, `reduce`, `reverse`, …)
  - Strings & string methods (`split`, `replace`, `includes`, …)
  - Objects, functions (arrow functions included)
  - Callbacks, `Math`, `Date`, spread/rest operators, type coercion – everything Node.js supports
- Read JavaScript from:
  - A `.js` file
  - A command‑line string
  - Standard input (pipe or redirection)

## 📋 Prerequisites

- **C++17 compiler** (e.g., `g++`, `clang++`)
- **Node.js** (version 14 or higher) – must be available in your `PATH`

Check if Node.js is installed:
```bash
node --version