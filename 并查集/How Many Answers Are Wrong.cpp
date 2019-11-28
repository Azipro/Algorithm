// HDU 3038

Problem Description
TT and FF are ... friends. Uh... very very good friends -________-b
FF is a bad boy, he is always wooing TT to play the following game with him. This is a very humdrum game. 
To begin with, TT should write down a sequence of integers-_-!!(bored).
Then, FF can choose a continuous subsequence from it(for example the subsequence from the third to the fifth integer inclusively). 
After that, FF will ask TT what the sum of the subsequence he chose is. The next, TT will answer FF's question. Then, FF can redo this 
process. In the end, FF must work out the entire sequence of integers.
Boring~~Boring~~a very very boring game!!! TT doesn't want to play with FF at all. To punish FF, she often tells FF the wrong answers 
on purpose.
The bad boy is not a fool man. FF detects some answers are incompatible. Of course, these contradictions make it difficult to calculate
the sequence.
However, TT is a nice and lovely girl. She doesn't have the heart to be hard on FF. To save time, she guarantees that the answers are 
all right if there is no logical mistakes indeed.
What's more, if FF finds an answer to be wrong, he will ignore it when judging next answers.
But there will be so many questions that poor FF can't make sure whether the current answer is right or wrong in a moment. So he 
decides to write a program to help him with this matter. The program will receive a series of questions from FF together with the 
answers FF has received from TT. The aim of this program is to find how many answers are wrong. Only by ignoring the wrong answers 
can FF work out the entire sequence of integers. Poor FF has no time to do this job. And now he is asking for your help~(Why asking 
trouble for himself~~Bad boy)
 

Input
Line 1: Two integers, N and M (1 <= N <= 200000, 1 <= M <= 40000). Means TT wrote N integers and FF asked her M questions.

Line 2..M+1: Line i+1 contains three integer: Ai, Bi and Si. Means TT answered FF that the sum from Ai to Bi is Si. It's guaranteed that 0 < Ai <= Bi <= N.

You can assume that any sum of subsequence is fit in 32-bit integer.
 

Output
A single line with a integer denotes how many answers are wrong.
 

Sample Input
10 5
1 10 100
7 10 28
1 3 32
4 6 41
6 6 1
 

Sample Output
1


