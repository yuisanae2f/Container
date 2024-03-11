# Dimension
> represents the multidimentional array.


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