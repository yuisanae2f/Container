# Pair
> Type-free Pair Structure.

Code
```c
typedef struct ae2f_Pair {
	struct ae2f_Dynamic c;
	union ae2f_Unit val;
}* ptr_ae2f_Pair;
```

Ref
- [ae2f_Dynamic](./Dynamic.md)
- [ae2f_Unit](./Pair.md)

## `val`
points where 

# ae2f_Dynamic_owned
> Its memory must not be managed directly.

Code
```c
typedef struct ae2f_Dynamic ae2f_Dynamic_owned;
```

Ref
- [ae2f_Dynamic](./Dynamic.md)

# ready
## ae2f_Pair
> initialises the structure with given `key` and `value`.  
> returns `pair` itself when succeed.

Code
```c
ptr_ae2f_Pair 
ae2f_Pair(
	ptr_ae2f_Pair pair,
	ptr_ae2f_Dynamic key,
	ptr_ae2f_Dynamic value
);
```

Ref
- [ptr_ae2f_Dynamic](./Dynamic.md)


## ae2f_Pair_
> initialises the structure by reading the data from `key` and `value`.  
> `keyLen` and `valLen` represents the each length of data which `key`/`value` points.

Code
```c
ptr_ae2f_Pair 
ae2f_Pair_(
	ptr_ae2f_Pair pair,	
	void* key,
	uint64_t keyLen,
	void* val,
	uint64_t valLen
);
```

## ae2f_Pair_copy
> copies the data from `src` to `dest`.

Code
```c
ptr_ae2f_Pair 
ae2f_Pair_copy(
	ptr_ae2f_Pair src,
	ptr_ae2f_Pair dest
);
```

# kill
## ae2f_Pair_free
> frees the memory which `block` points.

Code
```c
ptr_ae2f_Pair 
ae2f_Pair_free(
	ptr_ae2f_Pair block
);
```

# oper
## selector
> Following functions has the argument as `selector`.  
> is to determinate which memory to access.  

> 0 for key.  
> 1 for value.

## ae2f_Pair_get
> returns the value from `pair`
> as whole structure.

Code
```c
ae2f_Dynamic_owned 
ae2f_Pair_get(
	ptr_ae2f_Pair pair,
	int8_t selector
);
```

Ref
- [ae2f_Dynamic_owned](#ae2f_dynamic_owned)
- [selector](#selector)

## ae2f_Pair_set
> changes the value from `pair`
> to given `value`.

Code
```c
ptr_ae2f_Pair 
ae2f_Pair_set(
	ptr_ae2f_Pair pair,
	ptr_ae2f_Dynamic value,
	int8_t selector
);
```

Ref
- [ptr_ae2f_Dynamic](./Dynamic.md)
- [selector](#selector)

## ae2f_Pair_weigh
> Choose a value from `pair`.  
> Compare the chosen value with `compare`
> as [`ae2f_Dynamic_weigh`](./Dynamic.md#ae2f_dynamic_weigh).

Code
```c
int8_t 
ae2f_Pair_weigh(
	ptr_ae2f_Pair pair,
	ptr_ae2f_Dynamic compare,
	int8_t selector
);
```

Ref
- [ae2f_Dynamic_weigh](./Dynamic.md#ae2f_dynamic_weigh)
- [ptr_ae2f_Dynamic](./Dynamic.md)
- [selector](#selector)