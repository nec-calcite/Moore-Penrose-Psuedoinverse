## Introduction

The method used here is following the spirit of this paper:

[Courrieu, P., 2008. Fast computation of Moore-Penrose inverse matrices. *arXiv preprint arXiv:0804.4809*](https://arxiv.org/abs/0804.4809).

Generally speaking, for any $m \times n$ real matrix $G$, $G^{T}G$ is an $n \times n$ real symmetric matrix. Suppose this matrix $G^{T}G$ is rank $r$ where $n \geqslant r$, it is always possible to do a Cholesky decomposition to it and find an $n \times r$ upper triangular matrix $L$ with rank $r$ such that

$$
G^{T}G = LL^{T}\ .
$$

Since $L$ is of rank $r$, $L^{T}L$ is inversible. Assume the Moore-Penrose pseudoinverse of $G$ is $G^{+}$, then

$$
G^{+} = L (L^{T}L)^{-1} (L^{T}L)^{-1} L^{T} G^{T}\ .
$$

 To accomplish this protocol, we need the at least two functions in hand: the normal inverse and the Cholesky decomposition. For the readability of the codes, we will divide these two parts into two different head files and use them in the main code to do the MP inverse.

 

