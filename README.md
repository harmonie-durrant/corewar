
# README - Corewar

## ℹ️ Introduction

The Corewar project is a game in which several programs called "Champions" will fight to stay the last one alive. Corewar is actually a computer simulation in which processors will share memory to run on.

The project is based on a virtual machine in which the champions will fight for memory by all possible means in order to win, the last champion being able to signal that he is alive wins the game. In other words, the last champion to execute the "live" instruction is declared winner.

## ⚠️ Authorized functions

(f)open, (f)read, (f)write, getline, lseek, fseek, (f)close, malloc, realloc, free, exit.

## 📕 Git Commit Rules

### Message

- All keywords are in upercase

- Merges keep their default git message

- Keywords: **[ADD] [RM] [FIX] [EDIT]**

- Syntax: "**[ADD]** something"

### Commit

- No warnings

- No coding style errors

## 🔤 Naming Scheme

- creation and destruction: [name]_factory.c
- others: [name]_tools.c

Other file keywords can be used as long as they respect the syntax [name]_[function].c

## 🖥️ Run Locally

Clone the project

```bash
  git clone https://github.com/EpitechPromo2027/B-CPE-200-TLS-2-1-corewar-lucien.pineau.git
```

Go to the project directory

```bash
  cd B-CPE-200-TLS-2-1-corewar-lucien.pineau.git
```

Compile the project

```bash
  make
```

Execute the binaries

```bash
  ./asm/asm [filename] ...
```

```bash
  ./corewar/corewar [-dump nbr_cycle] [[-n prog_number] [-a load_address] prog_name] ...
```

## 💾 Running Tests

### unit tests

To run the unit tests, run the following command

```bash
  make unit_tests
```

### Binary tests

To run the binary tests, run the following command

```bash
  make btests
```

### Coverage

To see the coverage of the tests, run the following command

```bash
  make gcovr
```

## 📚 Documentation

## Install and run

To generate the documentation, run the following command

```bash
  sudo make docs-install
  make docs
```

## Uninstall installation files

To remove the installed files, run the following command

```bash
  sudo make docs-remove
```
