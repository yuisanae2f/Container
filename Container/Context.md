# Context
> binder for the memory.  
> When this is freed, <>

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


Code
```c
ptr_ae2f_Context 
ae2f_Context(
	ptr_ae2f_Context a	// container
);
```