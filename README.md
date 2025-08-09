Here’s a **simple README.md** you can drop in your folder so anyone can understand how to run your polynomial solver project:

---

# Polynomial Secret Finder

This project reads polynomial root data from a JSON file, decodes the values, solves for the coefficients of the polynomial, and prints the constant term `c`.

## 📂 Project Structure

```
├── main.cpp        # Main C++ code for solving the polynomial
├── input.json      # JSON file containing the encoded polynomial roots
├── json.hpp        # nlohmann/json single-header library
└── README.md       # This file
```

## ⚙️ Requirements

* **g++ 6.3 or later** (MinGW or any GCC-based compiler)
* **nlohmann/json** library (single header file `json.hpp`)
* **VS Code** or any C++ editor
* JSON input file formatted as per the specification

## 📥 Installing the JSON Library

1. Download [`json.hpp`](https://github.com/nlohmann/json/releases/latest/download/json.hpp).
2. Place it in the same folder as `main.cpp`.

## 📜 JSON Input Format

Example:

```json
{
    "keys": {
        "n": 4,
        "k": 3
    },
    "1": {
        "base": "10",
        "value": "4"
    },
    "2": {
        "base": "2",
        "value": "111"
    },
    "3": {
        "base": "10",
        "value": "12"
    },
    "6": {
        "base": "4",
        "value": "213"
    }
}
```

* **n** = total number of points provided
* **k** = minimum number of points to solve for polynomial coefficients
* Each other key = x-coordinate (string form)
* **base** = numerical base of the encoded `y` value
* **value** = y-coordinate encoded in the given base

## 🚀 How to Compile and Run

### On Windows (MinGW)

```bash
g++ -std=c++11 main.cpp -o poly
poly.exe
```

### On Linux/Mac

```bash
g++ -std=c++11 main.cpp -o poly
./poly
```

Make sure your `input.json` file is in the same directory as `main.cpp` before running.

## 🧮 Output

The program prints **only the constant term `c`** from the solved polynomial.

Example output:

```
110680544278521404696
```

---

Do you want me to also include **a second “example input & output”** section in this README so you can verify your program manually? That would make debugging easier.
