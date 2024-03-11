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