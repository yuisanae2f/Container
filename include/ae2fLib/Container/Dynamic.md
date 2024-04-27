# Dynamic
> Type-Free Basic Memory Allocator.  

Code
```c
typedef struct ae2f_Dynamic {
    union ae2f_Unit c;
    uint64_t len;
}* ptr_ae2f_Dynamic;
```

Ref
- [ae2f_Unit](./Unit.md)

## `len`
> describes the length of memory where `c` points.

Warnings
> If you are not aware of what you doing, do not change it manually.

# ready
## ae2f_Dynamic
> allocates the memory as the bytes of `len` at `addr`.  
> returns `addr`.

Code
```c
ptr_ae2f_Dynamic
ae2f_Dynamic(
    ptr_ae2f_Dynamic addr,
    uint64_t len
);
```

## ae2f_Dynamic_
> copies the `val` in a length of `len` as a new memory to `addr`.  
> returns `addr`.

Code
```c
ptr_ae2f_Dynamic
ae2f_Dynamic_(
    ptr_ae2f_Dynamic addr, 
    void* val, 
    uint64_t len
);
```

## ae2f_Dynamic_copy
> copies the `src` to `dest`.  

Code
```c
ptr_ae2f_Dynamic
ae2f_Dynamic_copy(
    ptr_ae2f_Dynamic src,
    ptr_ae2f_Dynamic dest
);
```

# resize
## ae2f_Dynamic_re
> resizes `mem` as `newSize`.  
> returns `mem`.

Code
```c
ptr_ae2f_Dynamic 
ae2f_Dynamic_re(
	ptr_ae2f_Dynamic mem,
	uint64_t newSize
);
```

## ae2f_Dynamic_re_
> resizes `dest` as `srcLen` and change its value as `src`.  
> returns `dest`.

Code
```c
ptr_ae2f_Dynamic 
ae2f_Dynamic_re_(
	ptr_ae2f_Dynamic dest,
	void* src,
	uint64_t srcLen
)
```

# kill
## ae2f_Dynamic_free
> frees the memory from `block`.  
> returns `block`.

Code
```c
ptr_ae2f_Dynamic 
ae2f_Dynamic_free(
	ptr_ae2f_Dynamic block
);
```

# cal
## ae2f_Dynamic_weigh
> compares `a` and `b`.  

> Provided two are the same, it returs zero.  
> Provided `a` is greater than `b`, it returns -1.  
> Otherwise it returns 1.

Code
```c
int8_t 
ae2f_Dynamic_weigh(
	ptr_ae2f_Dynamic a,
	ptr_ae2f_Dynamic b
);
```

## ae2f_Dynamic_puts
> copies `src` to `dest` without resizing the memory.  
> returns the byte written from `src`.

Code
```c
uint64_t 
ae2f_Dynamic_puts(
	ptr_ae2f_Dynamic dest,
	ptr_ae2f_Dynamic src
);
```