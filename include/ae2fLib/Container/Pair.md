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
> points where the value stays.

# ae2f_Dynamic_owned
> Its memory must not be managed directly.

Code
```c
#define ae2f_Dynamic_owned ae2f_Dynamic
#define ptr_ae2f_Dynamic_owned ptr_ae2f_Dynamic
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

# Abstraction
## getter
### _key
> Stands for key of the pair.

### _val
> Stands for value of the pair.

### get
> returns the [Linked](./Dynamic.md#linked--getter) as a getter.

t
> decides where to read from key or value.  
> must be either [`_key`](#_key) or [`_val`](#_val).

Code
```cpp
template<typename t>
inline Container::Linked get();
```

Ref
- [ae2f_Pair_set](#ae2f_pair_set)
- [Linked](./Dynamic.md#linked--getter)

## setter : [getter](#getter)

### free
- [ae2f_Pair_free](#ae2f_pair_free)

### set
> returns the setter of current pair.  

t
> decides where to read from key or value.  
> must be either [`_key`](#_key) or [`_val`](#_val).


Code
```cpp
template<typename t>
inline el<t> set();
```

Ref
- [_key](#_key)
- [_val](#_val)

## el
> is the manager of the Pair.  
> helps to manage the memory for the one side while preventing to corrupt the other.

### template
tt
> decides where to manage key or value of the Pair.  
> must be either [`_key`](#_key) or [`_val`](#_val).

### ()
Code
```cpp
Linked operator()()
```

- [getter::get](#get)

Ref
- [ae2f_Pair_get](#ae2f_pair_get)
- [Linked](./Dynamic.md#linked--getter)

Code
> returns itself.

> changes the value of the [targetted destination](#template).

```cpp
el& operator()(
	Linked* src
);
```

```cpp
el& operator()(
	Linked src
);
```

Ref
- [ae2f_Pair_set](#ae2f_pair_set)
- [Linked](./Dynamic.md#linked--getter)

## starter
### alloc
Code
```cpp
setter alloc(
	Linked key,
	Linked val
);
```

```cpp
setter alloc(
	Linked* key,
	Linked* val
);
```

Ref
- [ae2f_Pair](#ae2f_pair)
- [setter](#setter--getter)
- [Linked](./Dynamic.md#linked--getter)

### copy
Code
```cpp
setter copy(
	getter src
);
```

```cpp
setter copy(
	getter* src
);
```

Ref
- [ae2f_Pair_copy](#ae2f_pair_copy)
- [setter](#setter--getter)
- [getter](#getter)

# Classes
## Pair : [setter](#setter--getter)