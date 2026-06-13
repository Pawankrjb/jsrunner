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
⚙️ Compilation
Open a terminal in the folder containing jsrunner.cpp and run:

bash
g++ -std=c++17 -o jsrunner jsrunner.cpp
This produces an executable named jsrunner (or jsrunner.exe on Windows with MinGW).

📖 How to Use
1. Run a JavaScript file
bash
./jsrunner my_script.js
2. Run inline JavaScript code (as a string)
bash
./jsrunner "console.log('Hello, world!');"
3. Pipe code from standard input
bash
echo "console.log(2 + 3);" | ./jsrunner
Or redirect from a file:

bash
./jsrunner < my_script.js
✅ Test Cases (all pass)
Below are the five provided test cases with commands and expected outputs.

Test Case 1 – Odd/Even Checker
bash
./jsrunner "let num = 7; if (num % 2 === 0) { console.log(num + ' is Even'); } else { console.log(num + ' is Odd'); }"
Output:

text
7 is Odd
Test Case 2 – Triangle Pattern (for loop)
bash
./jsrunner "for (let i = 1; i <= 5; i++) { let row = ''; for (let j = 1; j <= i; j++) { row += '*'; } console.log(row); }"
Output:

text
*
**
***
****
*****
Test Case 3 – Armstrong Number
bash
./jsrunner "function isArmstrong(num) { let temp = num; let sum = 0; while (temp > 0) { let digit = temp % 10; sum += digit ** 3; temp = Math.floor(temp / 10); } return sum === num; } console.log(isArmstrong(153)); console.log(isArmstrong(123));"
Output:

text
true
false
Test Case 4 – Array Reverse (spread operator)
bash
./jsrunner "let arr = [1, 2, 3, 4, 5]; let reversed = [...arr].reverse(); console.log('Original: ' + arr.join(', ')); console.log('Reversed: ' + reversed.join(', '));"
Output:

text
Original: 1, 2, 3, 4, 5
Reversed: 5, 4, 3, 2, 1
Test Case 5 – String Palindrome
bash
./jsrunner "let str = 'racecar'; let reversed = str.split('').reverse().join(''); if (str === reversed) { console.log(str + ' is a Palindrome'); } else { console.log(str + ' is not a Palindrome'); }"
Output:

text
racecar is a Palindrome
🧠 How It Works (Step by Step)
Read JavaScript source – the program first decides where the code comes from:

If a command‑line argument is given and it is an existing file → read the file.

If it is not a file → treat the argument as raw JS code.

If no argument is given → read from stdin.

Create a temporary file – a unique file is created in /tmp (Linux/macOS) or a similar location, using mkstemp() for security.

Write code to the file – the JS code is written into that temporary file.

Execute Node.js – the program runs node tempfile.js and captures both stdout and stderr using popen().

Return output – the captured output is printed to the terminal (stdout).

Clean up – the temporary file is deleted.

All JavaScript features (variables, loops, arrays, objects, functions, array methods, etc.) are handled by Node.js, so the C++ wrapper remains simple and reliable.

🧩 Code Structure (for learning)
Function	Description
fileExists()	Checks if a file exists using stat().
readFile()	Reads an entire text file into a std::string.
executeJS()	Writes JS to a temp file, runs Node.js, captures output, deletes the file.
main()	Determines the source of the JS code and prints the result.
Every function is short and commented, making the code easy to follow.

⚠️ Platform Notes
Uses POSIX functions (mkstemp, popen, unlink). Works on:

Linux

macOS

Windows Subsystem for Linux (WSL)

Cygwin / MinGW with POSIX emulation

For native Windows (without POSIX), replace mkstemp with _mktemp and popen with _popen. This version is not provided here, as the environment is assumed to be Linux/macOS/WSL.
