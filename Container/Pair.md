# #include
## <a href="../Container.md#Dynamic">ae2f</a>_<a href="./Dynamic.md">Dynamic</a> <d id="_Dynamic"></d>
is the structure where the pointer of the dynamically allocated room and its length are contained.

# <a href="../Container.md">ae2f</a>_Pair <d id="_Pair"></d>
```c
struct ae2f_Pair {
	struct ae2f_Dynamic c;
	union ae2f_Unit val;
};
```
binds two pieces of data to the same location, `c`.  
`val` points where the value is allocated.

## struct ae2f_Pair* ae2f_Pair(struct ae2f_Pair* _this, struct ae2f_Dynamic key, struct ae2f_Dynamic value);
initialises `_this` with `key` and `value`.
```c
struct ae2f_Pair p;
struct ae2f_Dynamic k, v;

ae2f_Dynamic_(&k, "Hello World!", 15);
ae2f_Dynamic_(&v, "Goodbye World!", 23);

ae2f_Pair(&p, k, v);

ae2f_Dynamic_free(&k);
ae2f_Dynamic_free(&v);

ae2f_Pair_free(&p);
```

## struct ae2f_Pair* ae2f_Pair_(struct ae2f_Pair* _this, void* key, unsigned long long kLen, void* val, unsigned long long vLen);
initialises the `_this` with a `key` and `value` with a length of `kLen` and `vLen`.
```c
struct ae2f_Pair p;
ae2f_Pair_(&p, "Hello World!", 13, "Goodbye World!", 15);
ae2f_Pair_free(&p);
```

## struct ae2f_Pair* ae2f_Pair_free(struct ae2f_Pair* _this);
frees the memory of `_this`.
```c
struct ae2f_Pair p;
ae2f_Pair_free(&p);
```

## char ae2f_Pair_weigh(struct ae2f_Pair p1, struct ae2f_Dynamic p2, char where);
compares the values `p1` and `p2`.  
`where` decides which value to compare.  
When `where` equals zero, it will compare between the key of the `p1` and `p2`.  
When `where` equals one, it will compare between the value of the `p1` and `p2`.
```c
struct ae2f_Pair p;
struct ae2f_Dynamic a, b;

ae2f_Dynamic_(&a, "Hello World!", 13);
ae2f_Dynamic_(&b, "Goodbye World!", 15);
	
ae2f_Pair(&p, a, b);

printf("%d ", ae2f_Pair_weigh(p, a, 0));	// 0
printf("%d", ae2f_Pair_weigh(p, a, 1));		// 1
```

## struct ae2f_Dynamic ae2f_Pair_get(struct ae2f_Pair* _this, char where);
is the getter for `ae2f_Pair`.
returns the value at which `where` decides to set among the members of `_this`.
returns the key of `_this` when `where` equals zero.  
returns  the value of `_this` when `where` equals one.
```c
struct ae2f_Pair p;
ae2f_Pair_(&p, "Hello World!", 13, "Goodbye World!", 15);

printf("%s\n", ae2f_Pair_get(&p, 0).c.bt1);	 // Hello World!
printf("%s\n", ae2f_Pair_get(&p, 1).c.bt1);	 // Goodbye World!
```

## struct ae2f_Pair* ae2f_Pair_set(struct ae2f_Pair* _this, struct ae2f_Dynamic val, char where);
is the setter for `ae2f_Pair`.  
changes the value at which `where` decides to set among the members of `_this`.
changes the key of `_this` when `where` equals zero.  
changes the value of `_this` when `where` equals one.
```c
struct ae2f_Pair p;
ae2f_Pair_(&p, "Hello World!", 13, "Goodbye World!", 15);

printf("%s\n", p.val.bt1);	// Goodbye World!

struct ae2f_Dynamic _new  = { {"It's just another value!"}, 25 };
ae2f_Pair_set(&p, _new, 1);

printf("%s", p.val);		// It's just another value!

ae2f_Pair_free(&p);
```

## struct ae2f_Pair ae2f_Pair_copy(struct ae2f_Pair* _this);
returns the independent copy of given pointer of `ae2f_Pair` as `_this`.
