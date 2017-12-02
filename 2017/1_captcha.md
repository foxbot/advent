# Day One

### Requirements

A C compiler (I use GCC)

### Building

`$ gcc ./1_captcha.c -o 1_captcha.o`

### Usage

#### Part 1

`$ ./1_captcha.o $(cat 1_captcha-in.txt) 1`

#### Part 2

`$ ./1_captcha.o $(cat 1_captcha-in.txt) 2`

### Sample

```
$ ./1_captcha.o $(cat 1_captcha-in.txt) 1
1034
```

```
$ ./1_captcha.o $(cat 1_captcha-in.txt) 2
1356
```