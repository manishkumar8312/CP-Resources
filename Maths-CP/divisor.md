# Divisors

## 1. What is a Divisor

A **divisor** (or factor) of a number `n` is an integer that divides `n` exactly without leaving a remainder.

Formally,

```
d is a divisor of n if n % d = 0
```

### Example

For

```
n = 12
```

Divisors of `12` are

```
1, 2, 3, 4, 6, 12
```

### Important Properties

* `1` is a divisor of every positive integer.
* Every number divides itself.
* Divisors appear in **pairs**.

Example:

```
36
```

Divisor pairs:

```
1 × 36
2 × 18
3 × 12
4 × 9
6 × 6
```

Divisors:

```
1, 2, 3, 4, 6, 9, 12, 18, 36
```

---

# Finding Divisors Efficiently

Instead of checking every number up to `n`, divisors can be found by iterating up to:

```
√n
```

This works because if `i` divides `n`, then

```
n / i
```

is also a divisor.

### Complexity

```
O(√n)
```

### C++ Implementation

```cpp
vector<int> divisors(int n) {
    vector<int> divs;

    for(int i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            divs.push_back(i);

            if(i != n / i)
                divs.push_back(n / i);
        }
    }

    return divs;
}
```

---

# Count of Divisors

The **divisor count function** is denoted as

```
τ(n)
```

If the prime factorization of `n` is

```
n = p1^a1 × p2^a2 × ... × pk^ak
```

then the number of divisors is

```
τ(n) = (a1 + 1)(a2 + 1)...(ak + 1)
```

### Example

```
n = 60
```

Prime factorization:

```
60 = 2² × 3¹ × 5¹
```

Number of divisors:

```
(2+1)(1+1)(1+1)
= 3 × 2 × 2
= 12
```

---

### C++ Implementation

```cpp
int countDivisors(int n) {
    int count = 1;

    for(int i = 2; i * i <= n; i++) {
        int power = 0;

        while(n % i == 0) {
            n /= i;
            power++;
        }

        count *= (power + 1);
    }

    if(n > 1)
        count *= 2;

    return count;
}
```

---

# Sum of Divisors

The **sum of divisors function** is denoted as

```
σ(n)
```

If

```
n = p1^a1 × p2^a2 × ... × pk^ak
```

then

```
σ(n) =
(p1^(a1+1) − 1)/(p1 − 1)
×
(p2^(a2+1) − 1)/(p2 − 1)
× ...
×
(pk^(ak+1) − 1)/(pk − 1)
```

### Example

```
n = 12
```

Prime factorization:

```
12 = 2² × 3¹
```

Sum:

```
(2³ − 1)/(2 − 1) × (3² − 1)/(3 − 1)
= 7 × 4
= 28
```

Divisors:

```
1 + 2 + 3 + 4 + 6 + 12 = 28
```

---
### C++ Implementation

```cpp
int countDivisors(int n) {
    int count = 1;

    for(int i = 2; i * i <= n; i++) {
        int power = 0;

        while(n % i == 0) {
            n /= i;
            power++;
        }

        count *= (power + 1);
    }

    if(n > 1)
        count *= 2;

    return count;
}
```
---
# Product of Divisors

The **product of all divisors** of `n` is

```
n^(τ(n)/2)
```

where

```
τ(n) = number of divisors
```

### Example

```
n = 12
```

Divisors:

```
1, 2, 3, 4, 6, 12
```

Product:

```
1 × 2 × 3 × 4 × 6 × 12 = 1728
```

Using the formula:

```
τ(12) = 6
```

```
12^(6/2) = 12³ = 1728
```

### Reason

Divisors form pairs:

```
d × (n/d) = n
```

Each pair contributes `n`, and the number of pairs is

```
τ(n) / 2
```

---

# Precomputing Divisors (Sieve Style)

If divisors are required for **all numbers from `1` to `N`**, they can be precomputed using a sieve-like approach.

### Complexity

```
O(N log N)
```

### C++ Implementation

```cpp
vector<vector<int>> divisors(N + 1);

for(int i = 1; i <= N; i++) {
    for(int j = i; j <= N; j += i) {
        divisors[j].push_back(i);
    }
}
```

Now

```
divisors[x]
```

stores all divisors of `x`.

---

# Additional Observations

* Perfect squares have an **odd number of divisors**.
* Non-perfect squares have an **even number of divisors**.
* The maximum number of divisors for numbers up to `10^9` is relatively small (around a few thousand).

---