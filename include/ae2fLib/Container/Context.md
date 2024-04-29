# Context
> binder for the memory.  
> When this is freed, its children will also be freed.

Code
```c
typedef struct ae2f_Context {
	struct ae2f_Dynamic c;
	uint64_t len, _amp, _div;
}*ptr_ae2f_Context;
```

Ref
- [Dynamic](./Dynamic.md)

## `len`
> represents the count of data it stores.  

Warnings
> If you are not aware of what you doing, do not change it manually.


## `_amp`, `_div`
> are used for calculation of newly allocating the existing memory.  

> When the `len` times the size of [`ae2f_Dynamic`](./Dynamic.md) is greater than the `len` of `c`,
> the new memory length will be suggested as
> `(c.len * (1 + (_amp / _div)))`.  
> When its value is lower than `c.len + 1`, the later one would be the new length of the memory, `c`.

> You are able to change them manually.

Ref
- [ae2f_Dynamic](./Dynamic.md)

# ready
## ae2f_Context
> initialises `ctx`.

Code
```c
ptr_ae2f_Context 
ae2f_Context(
	ptr_ae2f_Context ctx
);
```

## ae2f_Context_copy
> copies the values from `src` to `dest`.

Code
```c
void ae2f_Context_copy(
	ptr_ae2f_Context dest,
	ptr_ae2f_Context src
);
```

# kill
## ae2f_Context_free
> frees the memory of `block` and its owned memory blocks.

Code
```c
ptr_ae2f_Context 
ae2f_Context_free(
	ptr_ae2f_Context block
);
```

# oper
## ae2f_Context_malloc
> creates the memory on `ctx` as a length of `len`.

Code
```c
ptr_ae2f_Dynamic 
ae2f_Context_malloc(
	ptr_ae2f_Context ctx,
	uint64_t len
);
```

Ref
- [ptr_ae2f_Dynamic](./Dynamic.md)

## ae2f_Context_del
> deletes the memory of `block` from `ctx`.

Code
```c
ptr_ae2f_Context 
ae2f_Context_del(
	ptr_ae2f_Context ctx, 
	ptr_ae2f_Dynamic block
);
```

Ref
- [ptr_ae2f_Dynamic](./Dynamic.md)

# Abstraction
## setter 
### free
- [ae2f_Context_free](#ae2f_context_free)
### malloc
- [ae2f_Context_malloc](#ae2f_context_malloc)

## el : [Dynamic](./Dynamic.md#abstraction)::[getter](./Dynamic.md#getter)
### _root

### id
> retuns the pointer of the [`Context`](#context)

Code
```cpp
_root::ptr id()
```

Ref
- [_root](#_root)

### del
- [ae2f_Context_del](#ae2f_context_del)

### re
Code
```cpp
el& re(uint64_t bytesize);
```

Ref
- [ae2f_Dynamic_re](./Dynamic.md#ae2f_dynamic_re)

Code
```cpp
el& re(Linked src);
```

Ref
- [Dynamic/Linked](./Dynamic.md#linked--getter)
- [ae2f_Dynamic_re](./Dynamic.md#ae2f_dynamic_re_)

## starter
### alloc
- [ae2f_Context](#ae2f_context)
### copy
- [ae2f_Context_copy](#ae2f_context_copy)

# Classes
## Context : [setter](#setter)