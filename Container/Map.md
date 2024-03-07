# #include
## <a href="../Container.md#Pair">ae2f</a>_<a href="./Pair.md">Pair</a> <d id="_Pair"></d>
binds two pieces of data to the same location, `c`.  
`val` points where the value is allocated.

# <a href="../Container.md#Map">ae2f</a>_Map <d id="_Map"></d>
```c
struct ae2f_Map {
	struct ae2f_Dynamic pairs;
	unsigned long long len;
	unsigned long long _amp; 
	unsigned long long _div;
};
```
is an unordered map similar to the hashmap.  
but it is not the same.  

provides the map, which has a key.

## struct ae2f_Map* ae2f_Map(struct ae2f_Map* _this); <d id="init"></d>
initialies the value from `_this`.
```c
struct ae2f_Map a; ae2f_Map(&a);
```

## struct ae2f_Map* ae2f_Map_add(struct ae2f_Map* _this, struct ae2f_Dynamic k, struct ae2f_Dynamic v);
copies of the pair of value of `k` and `v` and adds this map `_this`.  
Since <a href="#_Dynamic">`dynamics`</a> as parametres <a href="./Dynamic.md#copy">has been duplicated</a>,
still the original ones are need to be freed after the map has been freed.
```c
struct ae2f_Map a; ae2f_Map(&a);
struct ae2f_Dynamic k, v;

ae2f_Dynamic_(&k, "Hello World!", 15);
ae2f_Dynamic_(&v, "Goodbye World!", 23);

ae2f_Map_add(&a, k, v);

ae2f_Dynamic_free(&k); ae2f_Dynamic_free(&v);
ae2f_Map_free(&a);
```
## struct ae2f_Map* ae2f_Map_del(struct ae2f_Map* _this, struct ae2f_Pair* wh);
deletes the value in `wh` as a pointer of value which belongs to `_this`.  
pointer of value could be found via `ae2f_Map_at`.

## struct ae2f_Pair* ae2f_Map_at(struct ae2f_Map* _this, struct ae2f_Dynamic key);
returns the pointer of the value where the `key` matches the key from the structure, `_this`.  
returns zero when `key` has not been found.
```c
struct ae2f_Map a; ae2f_Map(&a);
struct ae2f_Dynamic k, v;

ae2f_Dynamic_(&k, "Hello World!", 15);
ae2f_Dynamic_(&v, "Goodbye World!", 23);

ae2f_Map_add(&a, k, v);

printf("%s", ae2f_Map_at(&a, k)->val.bt1);	//Goodbye World!

ae2f_Dynamic_free(&k); ae2f_Dynamic_free(&v);
ae2f_Map_free(&a);
```

## struct ae2f_Map ae2f_Map_free(struct ae2f_Map _this); <d id="free"></d>
will reset the map `_this`.
```c
struct ae2f_Map a; ae2f_Map(&a);
ae2f_Map_free(&a);
```