# 1. GCD (Greatest Common Divisor)

## Definition

**GCD of two integers** (a) and (b) is the **largest positive integer that divides both numbers without leaving a remainder**.

Example:

```
a = 12
b = 18

Divisors of 12 → 1,2,3,4,6,12
Divisors of 18 → 1,2,3,6,9,18

Common divisors → 1,2,3,6
GCD = 6
```

---

## Important Properties of GCD

1️⃣ **Commutative Property**

```
gcd(a, b) = gcd(b, a)
```

2️⃣ **Associative Property**

```
gcd(a, b, c) = gcd(gcd(a, b), c)
```

3️⃣ **If one number is 0**

```
gcd(a, 0) = a
```

4️⃣ **For consecutive numbers**

```
gcd(a, a+1) = 1
```

5️⃣ **If gcd(a,b) = 1**

Numbers are **coprime**.

Example:

```
gcd(8,15) = 1
```

---

# 2. Euclidean Algorithm (Most Important for CP)

The fastest way to compute GCD.

Idea:

```
gcd(a,b) = gcd(b, a % b)
```

Repeat until remainder becomes **0**.

Example:

```
gcd(48,18)

48 % 18 = 12
18 % 12 = 6
12 % 6 = 0

Answer = 6
```

---

## C++ Implementation (Euclidean Algorithm)

```cpp
#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    while(b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    int a = 48, b = 18;
    cout << gcd(a,b);
}
```

Time Complexity:

```
O(log(min(a,b)))
```

Very fast for CP.

---

## Recursive Version

```cpp
int gcd(int a, int b)
{
    if(b == 0)
        return a;

    return gcd(b, a % b);
}
```

---

## Built-in Function (Recommended in CP)

C++ STL already provides it.

```cpp
#include <algorithm>

int g = __gcd(a,b);
```

Example:

```cpp
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a = 24, b = 36;
    cout << __gcd(a,b);
}
```

Output

```
12
```

---

# 3. LCM (Least Common Multiple)

## Definition

The **smallest positive integer that is divisible by both numbers**.

Example:

```
a = 4
b = 6

Multiples of 4 → 4,8,12,16,20
Multiples of 6 → 6,12,18,24

LCM = 12
```

---

## Relation Between GCD and LCM

This formula is **very important in CP**.

a \times b = \gcd(a,b) \times \mathrm{lcm}(a,b)

Therefore,

```
lcm(a,b) = (a*b) / gcd(a,b)
```

---

## C++ Code for LCM

```cpp
#include <bits/stdc++.h>
using namespace std;

long long lcm(long long a, long long b)
{
    return (a / __gcd(a,b)) * b;
}

int main()
{
    long long a = 12, b = 18;

    cout << lcm(a,b);
}
```

Output

```
36
```

⚠ Important:

```
(a / gcd) * b
```

instead of

```
(a*b)/gcd
```

to **avoid overflow**.

---

# 4. GCD of Multiple Numbers

Use associative property.

Example:

```
gcd(a,b,c) = gcd(gcd(a,b),c)
```

### C++ Code

```cpp
int gcdArray(vector<int>& arr)
{
    int result = arr[0];

    for(int i=1;i<arr.size();i++)
        result = __gcd(result, arr[i]);

    return result;
}
```

---

# 5. LCM of Multiple Numbers

Same logic.

```
lcm(a,b,c) = lcm(lcm(a,b),c)
```

### C++ Code

```cpp
long long lcmArray(vector<int>& arr)
{
    long long ans = arr[0];

    for(int i=1;i<arr.size();i++)
        ans = (ans * arr[i]) / __gcd(ans, arr[i]);

    return ans;
}
```

---

# 6. Applications in Competitive Programming

### 1️⃣ Fraction Simplification

```
num / den
```

reduce using gcd.

```cpp
int g = __gcd(num, den);
num /= g;
den /= g;
```

---

### 2️⃣ Finding Coprime Numbers

```
if(__gcd(a,b) == 1)
```

---

### 3️⃣ Modular Arithmetic

Used in:

* Modular inverse
* Extended Euclid
* Diophantine equations

---

### 4️⃣ Array Problems

Examples:

* GCD of array
* Subarray GCD
* LCM constraints

---

# 7. Extended Euclidean Algorithm (Advanced CP)

Used for:

* **Modular inverse**
* **Diophantine equations**

Equation:

```
ax + by = gcd(a,b)
```

### Code

```cpp
int extended_gcd(int a, int b, int &x, int &y)
{
    if(b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }

    int x1, y1;
    int g = extended_gcd(b, a % b, x1, y1);

    x = y1;
    y = x1 - y1 * (a / b);

    return g;
}
```

---

# 8. Time Complexity

| Operation    | Complexity |
| ------------ | ---------- |
| GCD          | O(log n)   |
| LCM          | O(log n)   |
| Extended GCD | O(log n)   |

---

# 9. Common CP Tricks

### Trick 1

```
gcd(a,b) = gcd(a-b,b)
```

---

### Trick 2

If

```
gcd(a,b) = g
```

then

```
gcd(a/g , b/g) = 1
```

---

### Trick 3

If

```
gcd(a,b) = 1
```

then

```
gcd(a, b^k) = 1
```

---

