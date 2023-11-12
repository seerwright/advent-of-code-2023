# Advent of Code 2023

* [Advent of Code](https://adventofcode.com) coding challenge
* Using C++ this year
* Working through a few days in 2015's AoC - those are in _solution_template
* Each day's data and code will be in a day_xx directory


## Notes to Self

For anyone checking out this repo that is not me, there will probably be more going on here than is needed for AoC. I'm using AoC to refresh my memory on C++. 

---
### Approaches from Python
* Data Structures
  * dict -> unordered_map or map
  * list -> vector or stack
  * heap (?) -> linked list (forward_list or priority_queue)
  * set -> set
  * dataframe -> lol

* Control
  * Mostly the same stuff. Python has comprehensions and interesting iterators.
  * C++ is wordier, although a scattershot approach can be wordy in any language.

* Useful packages
  * NumPy -> Eigen, Armadillo, or IT++
  * SciPy -> Dlib

---

### Ignoring binaries
Put an .app extension so it will _not_ be picked up by .gitignore.

---

### Building DuckDB lib for C++

Make sure you install it. I'm assuming Linux here. Then compile with a DuckDB link (last note).


**Build from source**

`sudo apt-get install build-essential cmake llvm libarrow-dev`

`git clone https://github.com/duckdb/duckdb.git`

```
cd duckdb
mkdir build
cd build
```

`cmake ..`

`make -j`

`sudo make install`



**Use the lib**

`g++ your_program.cpp -o your_program -lduckdb`

**Note!** You might get a complaint about shared libraries not being available. Your problem is probably LD_LIBRARY_PATH. 
