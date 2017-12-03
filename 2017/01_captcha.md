# Day One

### Requirements

A C compiler (I use GCC)

### Building

`$ gcc ./01_captcha.c -o 01_captcha.o`

### Usage

#### Part 1

`$ ./01_captcha.o $(cat 01_captcha-in.txt) 1`

#### Part 2

`$ ./01_captcha.o $(cat 01_captcha-in.txt) 2`

### Sample

```
$ ./01_captcha.o $(cat 01_captcha-in.txt) 1
1034
```

```
$ ./01_captcha.o $(cat 01_captcha-in.txt) 2
1356
```