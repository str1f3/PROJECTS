# PIN GUESSING GAME

<p align="center">
  <img src="pinGuessingGame.png" alt="Centered Image">
</p>

## OVERVIEW

This is a **PORT** of my simple C-based terminal game that simulates a PIN guessing challenge. The user is prompted to guess a hardcoded 4-digit PIN to gain "access" to a simulated system. It's designed as a lightweight demonstration of **input validation**, **looping logic**, and **boolean control flow** in C.

---

## FEATURES

- Validates 4-digit integer input (scanf("%4d", ...))
- Provides feedback and a basic hint loop
- Reinforces do...while loop control and user interaction
- Uses bool to track system state (accessGranted flag)

---

## FUTURE DEVELOPMENT

This tool is intentionally minimal but can be extended to include:

- Randomized PIN generation
- Limited attempt count / lockout mechanism
- User-selectable PIN length (4-digit, 6-digit, etc.)
- Logging guessed attempts for pattern analysis
- Integration with file-based input or argument-based execution

---

## DISCLAIMER

This program is for **educational use** only. It is not meant to simulate real-world authentication systems and should not be used for any security-related applications.

---

## REVERSE ENGINEERING NOTE:

Students or researchers interested in learning how to **bypass the hardcoded PIN mechanism** through string/binary patching or stack-based redirection can follow step-by-step guides available on my GitBook:

- [String Patching](https://git.cnd.dev/playbook/sre/exploit-development/binary-exploitation/binary-modification/string-patching)
- [Binary Patching](https://git.cnd.dev/playbook/sre/exploit-development/binary-exploitation/binary-modification/binary-patching)
- [Stack Redirection](https://git.cnd.dev/playbook/sre/exploit-development/binary-exploitation/memory-corruption/buffer-overflow/stack-redirection)

These tutorials provide hands-on examples of basic software exploitation and binary modification techniques.

---

## USE CASES

- C programming students practicing loop control and conditional logic
- Cybersecurity learners exploring password guessing mechanics
- Basic terminal interaction and logic flow for beginners

## FILE INTEGRITY

#### SHA-256 CHECKSUM: 
 - sha256sum pinGuessingGame-v1.0.0-linux-x86-64 
    - 3b2f5f6f9d839a1b7a8d27edb2ef131435b23a87544c1dbe9b0c94adbc996000  pinGuessingGame-v1.0.0-linux-x86-64
