1. Mark the following as `True` or `False`. Briefly but convincingly justify all of your answers using the definition of $$O(.)$$, $$\Theta(.)$$ and $$\Omega(.)$$  

   1. $$n = O(n\ log(n))$$  : **True**  
      Solution:  
  
      Given: $$T(n) = n$$  
  
      We know that  
  
      $$\begin{equation*}  
        1 \leqslant log(n) ,\ \ \text{for all n $\geqslant$ 2}  
      \end{equation*}$$
  
        On multiplying both sides with n we will get:  

      $$\begin{equation*}  
        n \leqslant nlog(n) ,\ \ \text{for all n $\geqslant$ 2}  
      \end{equation*}$$  
  
      Since the above line is the summary / definition of $$O(\cdot)$$ giving us  
  
      $$\begin{equation*}  
        T(n) = O(nlog(n)) ,\ \ \ \text{with $n_o$ = 2 , c = 1}  
      \end{equation*}$$  
  
      Which proves the given statement is `True`.  
  
   2. $$n^{1/log(n)} = \Theta(1)$$  : **True**  
      Solution:  
  
      Given:  

      $$\begin{equation*}  
        T(n) = n^{1/log_2(n)}
      \end{equation*}$$(1)  
  
      Since $$log_2(2) = 1$$, we will replace it in eqn. (1)  
  
      $$\begin{equation*}  
        T(n) = n^{log_2(2)/log_2(n)}
      \end{equation*}$$(2)  
  
      Applying property of logarithm: $$n^{log_b(a)} = a^{log_b(n)}$$  
  
      $$\begin{equation*}  
        T(n) = 2^{log_2(n)/log_2(n)}
      \end{equation*}$$  
  
      Cancelling $$log_2(n)$$ from the numerator and denominator   
  
      $$\begin{equation*}  
        T(n) = 2^{1} = constant
      \end{equation*}$$  
  
      Taking $$c_1 = 1$$ and $$c_2 = 3$$:  

      $$\begin{equation*}  
        c_1 \cdot 1 \leqslant T(n) = 2 \leqslant c_2\cdot 1,\ \ \text{for all n $\geqslant$ 0}  \\
      \end{equation*}$$  
  
      Since the above line is the summary / definition of $$\Theta(\cdot)$$ giving us  
  
      $$\begin{equation*}  
        T(n) = \Theta(1) \ \ \ \text{with $n_o$ = 0 , $c_1$ = 1, $c_2$ = 3}  
      \end{equation*}$$  
  
      Which proves the given statement is `True`.  

   3. If $$\begin{equation*}
\text{$f(n) = $}
\begin{cases}
  5^n & \text{if $n < 2^{1000}$} \\ 
  2^{1000}n^2 & \text{if $n \geqslant 2^{1000}$} } \\
\end{cases}
\end{equation*}$$  and $$g(n) = \frac{n^2}{2^{1000}}$$,  
then $$f(n) = O(g(n))$$.


   4. For all the possible functions $$f(n)$$, $$g(n) \geqslant 0$$, if $$f(n) = O(g(n))$$, then $$2^{f(n)} = 2^{O(g(n))}$$  

   5. $$5^{log\ log(n)}} =  O(log(n)^2)$$  .
   6. $$n = \Theta(100^{log(n)})$$.



2. **n-naught not needed**. Suppose that $$T(n) = O(n^d)$$, and that $$T(n)$$ is never equal to $$\infty$$. Prove rigorously that there exists a $$c$$ so that $$0 \leqslant T(n) \leqslant c \cdot n^d$$ for all $$n \geqslant 1$$. That is, 
the definition of $$O(\cdot)$$ holds with $$n_0 = 1$$. 
  
   Solution:  
  
   Let $$T(n)$$ be an arbitrary polynomial function of order _d_ and $$T(n) = O(n)$$: 

   $$\begin{equation*}
     T(n) = c_0 + c_1 \cdot n^1 + c_2 \cdot n^2 + \cdots + c_{d-1} \cdot n^{d-1} + c_d \cdot n^d
   \end{equation*}$$ 
  
   We know that 

   $$\begin{equation*}
   |T(n)|=|c_d \cdot n^d+c_{d-1} \cdot n^{d-1}+\cdots c_0| \leqslant |c_d| \cdot n^d+|c_{d-1}| \cdot n^{d-1}+\cdots |c_0|\\
   |T(n)| \leqslant |c_d| \cdot n^d+|c_{d-1}| \cdot n^{d-1}+\cdots|c_0|
   \end{equation*}$$ 
  
   we can also say that:
 
   $$\begin{equation*}
   |T(n)| \leqslant |c_d|n^d+|c_{d-1}|n^d+\cdots+|c_1|\cdot n^d+|c_0|\cdot n^d  ,\text{for all $n \ge 1$}\\ \\
   T(n) \leqslant \sum_{i=0}^d|c_i|\cdot n^d   ,\text{for all $n \ge 1$}\\ \\
   \end{equation*}$$ 
 
   Since the above line is the summary / definition of $$O(\cdot)$$ which states that  

   $$\begin{equation*}
     T(n) = O(n^d)
   \end{equation*}$$

   Which asserts our assumption, meaning our assumption regarding Big-Oh of $$T(n)$$
was correct. Hence Proved.  

3. Solve the following recurrence relations; i.e. express each one as $$T(n) = O(f(n))$$ 
 for the tightest possible function $$f(n)$$, and give a short justification. Be aware 
that some parts might be slightly more involved than others. Unless otherwise stated, 
assume $$T(1) = 1$$.  

   1. $$T(n) = 2T(n/2) + 3n$$  
   We can write the above statement as  
    
   $$\begin{equation*}  
   T(n) = 2T(n/2) + O(n)  
   \end{equation}$$  
  
   We apply the master theorem with $$a=b=2$$ and with $$d=1$$.
   We have $$a=b^d$$, and so the running time is $$O(n^d \cdot log_2(n)) = O(n \cdot log_2n)$$.

   2. $$T(n) = 3T(n/4) + \sqrt n$$  
   We can write the above statement as  
    
   $$\begin{equation*}  
   T(n) = 3T(n/4) + O(n^{\frac12})  
   \end{equation}$$  
  
   We apply the master theorem with $$a=3, b=4$$ and with $$d=\frac12$$.
   We have $$a<b^d$$, and so the running time is $$O(n^d) = O(\sqrt n})$$.

   3. $$T(n) = 7T(n/2) + \Theta(n^3)$$  
   We can write the above statement as  
    
   $$\begin{equation*}  
   T(n) = 7T(n/2) + \Theta(n^3)  
   \end{equation}$$  
  
   We apply the master theorem with $$a=7, b=2$$ and with $$d=3$$.
   We have $$a>b^d$$, and so the running time is $$O(n^{log_b(a)}) = O(n^{log_2(7)}})$$.

   4. $$T(n) = 4T(n/2) + n^2\cdot log(n)$$  
   We can write the above statement as  
    
   $$\begin{equation*}  
   T(n) = 4T(n/2) + n^2 \cdot log(n)   
   \end{equation}$$  
  
   **No Solution yet**

   5. $$T(n) = 2T(n/3) + n^c$$, where $$c\geqslant 1$$ is a constant  
   We can write the above statement as  
    
   $$\begin{equation*}  
   T(n) = 2T(n/3) + n^c  
   \end{equation}$$  
  
   We apply the master theorem with $$a=2, b=3$$ and with $$d=c$$, where $$c\geqslant 1$$.
   We have $$a<b^c$$ , $$\forall c \geqslant 1$$ and so the running time is $$O(n^d) = O(n^c)$$.

   6. $$T(n) = 2T\cdot (\sqrt n) + 1$$, where $$T(2) = 1$$  
   Let us consider $$n = 2^{2^k}$$  
   We can write the above statement as  
    
   $$\begin{equation*}  
   T(2^{2^k}) = 2\cdot T(\sqrt{2^{2^k}}) + 1   
   \end{equation}$$  

   Which will be  
  
   $$\begin{equation*}  
   T(2^{2^k}) = 2\cdot T(2^{2^{k-1}}) + 1   
   \end{equation}$$  

   Now we can apply substitution here  

   $$\begin{equation*}  
   T(2^{2^k}) &= 2\cdotT(2^{2^{k-1}}) + 1 \\ \\
   T(2^{2^k}) &= 2(2\cdot T(2^{2^{k-2}}) + 1) + 1 \\ \\ 
   T(2^{2^k}) &= 2^2(2\cdot T(2^{2^{k-3}}) + 1) + 1 + 2 \\ \\ 
   T(2^{2^k}) &= 2^3(2\cdot T(2^{2^{k-4}}) + 1) + 1 + 2 + 4\\ \\ 
   & \cdots \\ \\
   T(2^{2^k}) &= 2^k\cdot T(2^{2^0}) + 1 + 2 + 4 + \cdots + 2^{k-1} \\ 
   T(2^{2^k}) &= 2^k + 2^{k-1} + \cdots + 4 + 2 + 1 \\
   T(2^{2^k}) &=  \sum_{i=0}^k{2^i}  = 2^{k+1} - 1\\
   \end{equation}$$ 
 
   Which means that 

   $$\begin{equation*}  
   T(2^{2^k}) \leqslant 2^{k+1} \\  \\
   \text{On substituting back $2^{2^k} = n$ } \\ \\
   T(n) \leqslant log_2(log_2(2^{k+1})) = log_2(k + 1) \\ \\ 
   T(n) \leqslant log_2(k + 1)  \leqslant log_2(k^2) \ \forall \  k \geqslant 2 \\ \\
   T(n) \leqslant log_2(k^2) = 2\cdot log_2(k) \ \forall \  k \geqslant 2 \\ \\
   \end{equation}$$  

   Since the above line is the summary / definition of $$O(\cdot)$$ giving us  

   $$\begin{equation*}  
   T(n) = O(log(n)) \text{ for $c = 2, n_0 = 2$} \\ \\
   \end{equation}$$  

   Hence the Algorithm has Complexity $$O(log(n))$$  

4. Different-sized sub-problems. (6 points) Solve the following recurrence relation. 
   $$T(n) = T(n/2) + T(n/4) + T(n/8) + n$$ where $$T(1) = 1$$.  

5. What's wrong with this proof? (9 points) Consider the following recurrence relation:
$$T(n) = T(n/5) + 10\cdot n $$ for n=5, where $$T(0) = T(1) = T(2) = T(3) = T(4) = 1$$. Consider the following three arguments.  

   1. Claim: $$T(n) = O(n)$$. To see this, we will use strong induction. The inductive
hypothesis is that $$T(k) = O(k)$$ for all $$5 \leqslant k < n$$. For the base case, we see
$$T(5) = T(0)+10 \cdot 5 = 51 = O(1)$$. For the inductive step, assume that the inductive
hypothesis holds for all $$k < n$$. Then  

      $$\begin{equation*}
      T(n) = T(n - 5) + 10\cdot n\\
      \end{equation*}$$ 

      and by induction $$T(n-5) = O(n/5) $$ , so $$T(n) = O(n-5) + 10\cdot n = O(n)$$    
      This establishes the inductive hypothesis for n. Finally, we conclude that  
      $$T(n) = O(n)$$ for all $$n$$
   





