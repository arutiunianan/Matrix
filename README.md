# Anishka's Matrix

<image src="for_readme/thematrix.png" width=500px>

## What does it do?

You can use this project to work with matrices, perform basic operations on them, and most importantly, for calculating the determinant.

## What is the working principle?

To find the determinant, I used Bareiss' algorithm. 

### Description of the algorithm

This is an improved version of the Gauss method, where the triangular form is reduced as follows:

<image src="for_readme/pic1.png" width=250px>

Division increases the margin of error, so Bareiss proposed this algorithm:

<image src="for_readme/pic2.png" width=250px>,

but then there is a problem with the growth of values during the calculation, which do not always fit into our range.

Bareis proposed dividing the expression above by a<sub>j-1,j-1</sub> and showed that if the initial elements of the matrix are integers, then the result of calculating such an expression will also be an integer, that is, without accumulating calculation errors!!!!

As a result, the algorithm looks like this:

<image src="for_readme/pic3.png" width=250px>

The greater the denominator of the fraction, the smaller the margin of error, so in my project I used the choice of the maximum in the column.

### Improvement for the algorithm

Before starting work on this project, I asked my friends who are interested in mathematics about the fastest algorithm for calculating the determinant of very large matrices. 

My classmate from Moscow State University told me about an improved version of the Gauss method - the Gauss block method. This method was invented by his teacher and there is no information about it on the Internet.

That's why I wrote my own [manual](/for_readme/manual.pdf) with a detailed implementation!!

The advantage of this method over the standard Gaussian method is that in it we completely process one block of memory (matrix block) first and only then move on to the next block of memory (matrix).

In the standard method, we jump from one end of the memory to the other during the work. And so it is several times. This contributes to frequent cache uploads.

<image src="for_readme/pic4.png" width=500px>

As we can see, this is not the most expensive operation. But can you imagine how many cache misses occur with huge matrices?  How many times do we have to spend time loading the cache?

I hope in the future, as I have more time, I will implement this method:)

## How do I run the program?

```
cmake -S . -B build
```

To build a project:

```
cmake --build build
```

To run manual input and tests, respectively:

```
./build/matrix
ctest --output-on-failure --test-dir build
```

## What does the result of the program look like?

The program will be waiting for input data in stdin in such way:

```
<matrix size>
<elem00> <elem01> <elem02> ...
```

For this test:

```
10
2 0 0 18 0 6 0 18 0 12
0 2 0 0 0 0 0 0 0 0
-2 0 1 -18 0 -6 0 -18 0 -16
-4 0 0 -33 2 -11 1 -33 3 -34
-4 0 0 -36 2 -11 1 -33 3 -34
-2 0 0 -18 0 -5 1 -15 3 -18
-3 0 0 -27 0 -9 1 -24 3 -24
-1 0 0 -9 0 -3 0 -6 3 -8
-1 0 0 -9 0 -3 0 -9 3 -8
1 0 0 9 0 3 0 9 0 8
```

the result of the program will be as follows:

```
432
```

We can verify the correctness of the result using a python script:

```
python3 tests/det.py
```

He gave the answer:
```
432.0000000
```

So our program worked correctly yeeeeeeee.