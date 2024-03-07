# Dynamic
Basic Memory Allocator.
```c
typedef struct ae2f_Dynamic {
    union ae2f_Unit c;
    uint64_t len;
}* ptr_ae2f_Dynamic;
```

## ae2f_Dynamic
```c
ptr_ae2f_Dynamic
ae2f_Dynamic(
    ptr_ae2f_Dynamic addr,
    uint64_t len
);
```
allocates the memory as the bytes of `len` at `addr`.  
returns `addr`.

## ae2f_Dynamic_
```c
ptr_ae2f_Dynamic
ae2f_Dynamic_(
    ptr_ae2f_Dynamic addr, 
    void* val, 
    uint64_t len
);
```
copies the `val` in a length of `len` as a new memory to `addr`.  
returns `addr`.

## ae2f_Dynamic_copy
```c
ptr_ae2f_Dynamic
ae2f_Dynamic_copy(
    ptr_ae2f_Dynamic src,
    ptr_ae2f_Dynamic dest
);
```
copies the `src` to `dest`.  

## ae2f_Dynamic_puts
```c
uint64_t 
ae2f_Dynamic_puts(
	ptr_ae2f_Dynamic dest,
	ptr_ae2f_Dynamic src
);
```
copies 

## ae2f_Dynamic_free
```c
ptr_ae2f_Dynamic 
ae2f_Dynamic_free(
	ptr_ae2f_Dynamic block
);
```
frees the memory from `block`.  
returns `block`.

## ae2f_Dynamic_re
```c
ptr_ae2f_Dynamic 
ae2f_Dynamic_re(
	ptr_ae2f_Dynamic mem,
	uint64_t newSize
);
```
resizes `mem` as `newSize`.  
returns `mem`.

## ae2f_Dynamic_re_
```c
ptr_ae2f_Dynamic 
ae2f_Dynamic_re_(
	ptr_ae2f_Dynamic dest,
	void* src,
	uint64_t srcLen
)
```
resizes `dest` as `srcLen` and change its value as `src`.  
returns `dest`.

## ae2f_Dynamic_weigh
```c
int8_t 
ae2f_Dynamic_weigh(
	ptr_ae2f_Dynamic a,
	ptr_ae2f_Dynamic b
);
```
compares `a` and `b`.  

Provided two are the same, it returs zero.  
Provided `a` is greater than `b`, it returns -1.  
Otherwise it returns 1.
