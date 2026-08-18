# better_next_line 

## Description

**BETTER_NEXT_LINE** is a C++ implementation of the project [Get Next Line](https://github.com/msalmonella/get_next_line).  
The goal of this project is to create a program that reads the file line by line.

Through this project, students learn:
- Static functions and how to use them beneficially. 
- Defensive programming in C.
- Difficult backtracking.

### My journey in the making of this project and recommendations:
Project may sound quite fraustrating, it took like a week or so for me to undestand the whole thing.  
Doing things slowly and one by one at a time is encouraged.  

### How I started  

I started out just by reading the file, nothing else. I wasn't even aware of static function
when I started doing the project, the whole thing was working on stack with enough buffersize.
Created a function to write until the first `\n` that loop sees.  
Called another function that cleans up the written part and returns the remaining part.  

The project itself is pretty basic but really hard to understand in my honest opinion.  

Ask your peers, do not do this project without your peers if it hadn't clicked yet.  

---

## Instructions

### Compilation

Since this project doesn't require Makefile,  

```bash
cc *.c
```  

## Resources  

**AI** is used to handle memory leaks and edge cases. 
PS: Not all memory leaks handled by AI, I also used backtracking in order to fully understand the project.

[Subject PDF](https://cdn.intra.42.fr/pdf/pdf/190905/en.subject.pdf) This one was pretty useless, I'm not gonna lie.<br>
[Learn-C](https://www.learn-c.org/) Is used to understand the static variables.<br>


