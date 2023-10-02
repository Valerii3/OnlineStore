# OnlineStore
---
OnlineStore is a simplified model of a real-world store, equipped to handle operations such as adding products, recording purchases, and counting sales within a specific time frame. 

The operations supported are:
```
ADD <PRODUCT> - add product to the shop
BUY <TIME> <PRODUCT> - buy product
COUNT <PRODUCT> <TIME_FROM> <TIME_TO> - count how many products were sold during time period.
```

# Implementation

**Timestamps in Increasing Order**

In aligning with real-world scenarios where purchases are recorded chronologically, the implementation assumes that timestamps will be received in increasing order. 

**Data Structures**:
* utilizes a `hash map` where the key is the product name and the value is a vector of timestamps.

**Time Complexity**:
* ADD and BUY operations are `O(1)`.
* COUNT operation is `O(logn)` due to the use of binary search on a sorted array of timestamps.

**Space Complexity**:
* The overall space complexity is `O(n * v)`, where n represents the number of distinct products and v the volume of purchases per product.

**P.S**
 In cases where purchases could be recorded at random times, we should use [order-statistic balanced BST](https://codeforces.com/blog/entry/11080) then operation: ADD timestamp will be `O(logn)` but COUNT will be the same.

# How to build 

1) Automatic
*  `git clone git@github.com:Valerii3/OnlineStore.git`
*   Open this project in CLion and click `ctrl R`

2) Manual
*  `git clone git@github.com:Valerii3/OnlineStore.git`
*  open the project directory
*  Generate build files:
  ```
mkdir build
cd build
cmake ..
```
* Build the project: `make`
* Run the program: `./OnlineStore`  

   
  
