# Dimension
> represents the multidimentional array.  
> Do not change its value manually.

Code
```c
typedef struct ae2f_Dimension {
	struct ae2f_Dynamic c;
	uint64_t depth;
	uint8_t end;
	struct ae2f_Dimension* pre;
}*ptr_ae2f_Dimension;
```

Ref
- [Dynamic](./Dynamic.md)

# ready
## ae2f_Dimension
> initialises `dimension`.  

> `depth` is the max depth level of the dimension.  
> `lengthArray` contains the value of length for each depth level.  
> Hence, `depth` must be the length of `lengthArray`.

Code
```c
ptr_ae2f_Dimension 
ae2f_Dimension(
	ptr_ae2f_Dimension dimension,
	uint64_t depth,
	uint64_t* lengthArray
);
```

## ae2f_Dimension_copy
> copies the data from `src` to `dest`.

Code
```c
ptr_ae2f_Dimension
ae2f_Dimension_copy(
	ptr_ae2f_Dimension src,
	ptr_ae2f_Dimension dest
);
```

# kill
## ae2f_Dimension_free
> frees the memory related to `block`.

Code
```c
ptr_ae2f_Dimension 
ae2f_Dimension_free(
	ptr_ae2f_Dimension block
);
```

# get
## ae2f_Dimension_point
> points where the memory allocated at `matrix`.  
> `pointArray` is the direction to point at each `depth` level.

> Hence `depth` would be the length of `pointArray`.

```c
ptr_ae2f_Dimension 
ae2f_Dimension_point(
	ptr_ae2f_Dimension matrix,
	uint64_t depth,
	uint64_t* pointArray
);
```