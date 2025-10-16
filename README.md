# CS-117: Assignment 1

## The Numerian Quest

- **Author:** Muhammad Mujtaba
- **CMD ID:** 540040
- **Email:** [mmujtaba.bese25seecs@seecs.edu.pk](mailto:mmujtaba.bese25seecs@seecs.edu.pk)
- **Class:** BESE 16B
- **Batch:** 2k25

## Number Systems

### Introduction

Number systems are a way of expressing numbers in a consistent and determinable manner using a specific set of symbols.
When _N_ unique symbols are used, we call it a **Base N** number system.

---

### Commonly Used Systems

#### 1. Decimal (Base 10)

The decimal number system is the most commonly used in everyday life and is the one we are most familiar with.
It uses **10 symbols**:

`0 1 2 3 4 5 6 7 8 9`

We use this system for general communication and calculations.

---

#### 2. Binary (Base 2)

The binary system is used by computers. Since computers represent electrical signals as either **on (1)** or **off (0)**, the binary system allows humans to represent and manipulate these signals easily.

It uses **2 symbols**:

`0 1`

Conversion between binary and decimal (and vice versa) is explained in the _Special Conversion_ section.

---

#### 3. Octal (Base 8)

The octal system was developed as a more human-readable representation of binary numbers.
Each **group of 3 binary digits (bits)** corresponds to **1 octal digit**, making it a useful shorthand for binary data.

This system is used in **UNIX** operating systems to represent file permissions.

It uses **8 symbols**:

`0 1 2 3 4 5 6 7`

Conversions to and from octal are discussed in the _Special Conversion_ section.

---

#### 4. Hexadecimal (Base 16)

The hexadecimal system is the modern standard for representing binary numbers.
Each **group of 4 bits** corresponds to **1 hexadecimal digit**, which means **2 hexadecimal digits** can represent a full **byte (8 bits)**.

This system is widely used in computing, especially for memory addresses and color codes.

It uses **16 symbols**:

`0 1 2 3 4 5 6 7 8 9 A B C D E F`

> _Note: Letters can be uppercase or lowercase._

Conversions to and from hexadecimal are discussed in the _Special Conversion_ section.

---

## Conversion

### General Conversion

To convert from one arbitrary base **N** to another base **M**:

1. **Convert from Base N to Decimal:**

    Suppose we have a base **N** number.
    Each digit contributes to the total as:

$$
Decimal Value = \Sigma (digit × N^{position})
$$

where:

- **N** = base (number of unique symbols)
- **digit** = value of each symbol
- **position** = index from right (starting at 0)

2. **Convert from Decimal to Base M:**

    - Repeatedly divide the decimal number by **M**.
    - Record the remainders.
    - The remainders written in **reverse order** form the number in base **M**.

---

### Special Conversion

#### Binary → Decimal

Binary numbers can be represented in decimal form as:

Suppose we have $b_{n}b_{n-1}...b_{0}$

Then:

$$
Decimal = \Sigma (b_{i} × 2^{i})
$$

---

#### Decimal → Binary

To convert from decimal to binary:

1. Divide the number repeatedly by 2.
2. Record each remainder.
3. Write the remainders in reverse order.

---

#### Octal → Decimal

Same as the general method: multiply each digit by **8ⁱ** (where _i_ is the position).

---

#### Decimal → Octal

1. Convert the decimal number to binary.
2. Group the binary digits into sets of three (from right).
3. Replace each group with its octal equivalent.

---

#### Hexadecimal → Decimal

Multiply each digit by **16ⁱ** (where _i_ is the position).

---

#### Decimal → Hexadecimal

1. Convert the decimal number to binary.
2. Group the binary digits into sets of four (from right).
3. Replace each group with its hexadecimal equivalent.

---

## Custom Number System

For this assignment, a **Base 32** system was used with the following symbols:

```js
0 1 2 3 4 5 6 7 8 9
a b c d e f g h i j
k l m n o p q r s t
u v
```

---

### Custom → Decimal

Use the same principle as general conversion:

---

### Decimal → Custom

Divide repeatedly by 32 and record remainders.
Reverse the order of remainders to get the final number.
Each remainder maps to its corresponding custom symbol.

---

## Links

- **Email:** [mmujtaba.bese25seecs@seecs.edu.pk](mailto:mmujtaba.bese25seecs@seecs.edu.pk)

> Assistance from [ChatGPT](https://chat.openai.com/) was used to convert the word `docx` to `md`.
