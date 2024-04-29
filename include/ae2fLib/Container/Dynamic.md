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

> `sizeSelector` will decide the length of writing.  
> If 0, the length will be the `src`'s.  
> Otherwise, the length will be the `dest`.

Code
```c
uint64_t 
ae2f_Dynamic_puts(
	ptr_ae2f_Dynamic dest,
	ptr_ae2f_Dynamic src,
	int8_t sizeSelector
);
```



# Abstraction
## getter

### weigh
- [weigh](#ae2f_dynamic_weigh)

### ==
> compares two [`ae2f_Dynamic`](#dynamic).  
> returns if two are same.

Ref
- [weigh](#weigh)

### <
> compares two [`ae2f_Dynamic](#dynamic).  
> returns if the right one is the greater.
Ref
- [weigh](#weigh)

### >
> compares two [`ae2f_Dynamic](#dynamic).  
> returns if the left one is the greater.

Ref
- [weigh](#weigh)

### <=
> compares two [`ae2f_Dynamic](#dynamic).  
> returns if the right one is the greater or the same.

Ref
- [weigh](#weigh)

### >=
> compares two [`ae2f_Dynamic](#dynamic).  
> returns if the left one is the greater or the same.
Ref
- [weigh](#weigh)
### puts
- [ae2f_Dynamic_puts](#ae2f_dynamic_puts)
## setter : [getter](#getter)
Ref
- [getter](#getter)

### free
- [ae2f_Dynamic_free](#ae2f_dynamic_free)

### re
Code
```cpp
setter& re(
	uint64_t len
);
```

Ref
- [ae2f_Dynamic_re](#ae2f_dynamic_re)

Code
```cpp
template<typename v>
setter& re(
	v* src,
	uint64_t src_len
);
```

```cpp
setter& re(
	Linked src
);
```

Ref
- [ae2f_Dynamic_re_](#ae2f_dynamic_re_)
## starter
### alloc
Code
```cpp
inline setter alloc(
	uint64_t len
);
```

Ref
- [ae2f_Dynamic](#ae2f_dynamic)

Code
```cpp
template<typename v>
inline setter alloc(
	v* src_ptr,
	uint64_t len
);
```

Ref
- [ae2f_Dynamic_](#ae2f_dynamic_)
### copy
- [ae2f_Dynamic_copy](#ae2f_dynamic_copy)

# Classes
## Dynamic : [setter](#setter)
> allocates new heap memory to store, and copy the original value.

## Linked : [getter](#getter)
> stores the original pointer and its size.