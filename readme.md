# Notes to Self on using the template

## FAQ

### How do I used DuckDB?

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

---

### Question
Answer

---

### Question
Answer

