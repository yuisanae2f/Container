# Map
> Type-Free unordered map.  
> is able to use [`ae2f_Dynamic`](./Dynamic.md) as an index.  
> sorts its values by its keys.

Code
```c
typedef struct ae2f_Map {
	struct ae2f_Dynamic pairs;
	uint64_t len;
	uint64_t _amp; uint64_t _div;
} *ptr_ae2f_Map;
```

Ref
- [ae2f_Dynamic](./Dynamic.md)

## `len`
> represents the count of data it stores.  

Warnings
> If you are not aware of what you doing, do not change it manually.


## `_amp`, `_div`
> are used for calculation of newly allocating the existing memory.  

> When the `len` times the size of [`ae2f_Dynamic`](./Dynamic.md) is greater than the `len` of `pairs`,
> the new memory length will be suggested as
> `(pairs.len * (1 + (_amp / _div)))`.  
> When its value is lower than `pairs.len + 1`, the later one would be the new length of the memory, `pairs`.

> You are able to change them manually.

Ref
- [ae2f_Dynamic](./Dynamic.md)

# ready
## ae2f_Map
> initialies the `map`.

> `_amp` will be set as 1.  
> `_div` will be set as 9.

Code
```c
ptr_ae2f_Map 
ae2f_Map(
	ptr_ae2f_Map map
);
```

Ref
- [_amp, _div](#_amp-_div)

## ae2f_Map_copy
> copies the value from `src` to `dest`.

Code
```c
ptr_ae2f_Map 
ae2f_Map_copy(
	ptr_ae2f_Map src,
	ptr_ae2f_Map dest
);
```

# kill
## ae2f_Map_free
> frees the memory of `block`.

Code
```c
ptr_ae2f_Map 
ae2f_Map_free(
	ptr_ae2f_Map block
);
```

# access
## ae2f_Map_at
> tries to find the value which key matches `key` from `map`.  
> returns the address which points the found value.

> The result may not be exact.  
> Provided `map` has no value which matches `key`,
> this function will return the valid address within `map`, still not exact to `key`.

Code
```c
ptr_ae2f_Pair 
ae2f_Map_at(
	ptr_ae2f_Map map,		
	ptr_ae2f_Dynamic key	
);
```

Ref
- [ptr_ae2f_Dynamic](./Dynamic.md)
- [ptr_ae2f_Pair](./Pair.md)

## ae2f_Map_add
> tries to find the value which key matches `key` from `map`.  
> if found, set its value as `value`.  
> unless, makes the new one as `key` and `value`.

Code
```c
ptr_ae2f_Map 
ae2f_Map_add(
	ptr_ae2f_Map map,
	ptr_ae2f_Dynamic key,
	ptr_ae2f_Dynamic value
);
```

Ref
- [ae2f_Map_at](#ae2f_map_at)
- [ptr_ae2f_Dynamic](./Dynamic.md)

## ae2f_Map_del
> Deletes `tar` from `map`, when `tar` is valid to `map`.

Code
```c
ptr_ae2f_Map 
ae2f_Map_del(
	ptr_ae2f_Map map, 
	ptr_ae2f_Pair tar
);
```

Ref
- [ptr_ae2f_Pair](./Pair.md)

# Abstraction
## setter
### _amp, _div
> refers to the `_amp`, `_div` from the primitive structure.

Ref
- [amp, div](#_amp-_div)

### at
> points which pair inside this class has a `kcmp` as value of [key](./Pair.md#_key).

> returns the Abstraction of [el](#el--pairel_val).
Code
```cpp
el at(
	Linked kcmp
);
```

```cpp
el at(
	Linked* kcmp
);
```

Ref
- [Linked](./Dynamic.md#linked--getter)
- [ae2f_Map_at](#ae2f_map_at)
- [el](#el--pairel_val)

### add
Code
```cpp
el add(
	Linked* k, 
	Linked* v
);
```

```cpp
el add(
	Linked k, 
	Linked v
);
```

Ref
- [Linked](./Dynamic.md#linked--getter)
- [ae2f_Map_add](#ae2f_map_add)
- [el](#el--pairel_val)

Code
```cpp
el add(
	Pair pair
);
```

```cpp
el add(
	Pair* pair
);
```

Ref
- [Pair](./Pair.md)
- [ae2f_Map_add](#ae2f_map_add)
- [el](#el--pairel_val)

### free
- [ae2f_Map_free](#ae2f_map_free)
## el : [Pair](./Pair.md)::[el](./Pair.md#el)&lt;[_val](./Pair.md#_val)&gt;
> is the [value part](./Pair.md#_val) of a [pair](./Pair.md) which belongs to a [Map](#map).

Ref
- [Pair](./Pair.md)
- [Pair/el](./Pair.md#el)
- [Pair/_val](./Pair.md#_val)

### _root
> contains the alter name of [the primitive type](#map).

Code
```cpp
typedef def<struct ae2f_Map> _root;
```

Ref
- [ae2fLib/def](https://github.com/yuisanae2f/ae2fLib#def)
- [struct ae2f_Map](#map)

### id
> returns the pointer of the map.

Code
```cpp
_root::ptr id();
```

Ref
- [Pair](./Pair.md)
- [Pair/el](./Pair.md#el)
- [Pair/_val](./Pair.md#_val)
- [_root](#_root)

### key
> copies the [key](./Pair.md#_key) of this [pair](./Pair.md), returns as [Dynamic](./Dynamic.md#dynamic--setter).

Code
```cpp
Container::Dynamic key();
```

Ref
- [Dynamic](./Dynamic.md#dynamic--setter)
- [Pair/_key](./Pair.md#_key)

### del
> deletes the selected element from the map.

Code
```cpp
setter del()
```

Ref
- [ae2f_Map_del](#ae2f_map_del)
## starter
### alloc
- [ae2f_Map](#ae2f_map)
### copy
- [ae2f_Map_copy](#ae2f_map_copy)

# Classes
## Map : [setter](#setter)