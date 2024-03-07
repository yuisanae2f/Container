# Pair
Type-free Pair Structure.
```c
typedef struct ae2f_Pair {
	struct ae2f_Dynamic c;
	union ae2f_Unit val;
}* ptr_ae2f_Pair;
```

# make
## ae2f_Pair
```c
ptr_ae2f_Pair 
ae2f_Pair(
	ptr_ae2f_Pair pair,
	ptr_ae2f_Dynamic key,
	ptr_ae2f_Dynamic value
);
```

## ae2f_Pair_
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

# kill
## ae2f_Pair_free
```c
ptr_ae2f_Pair 
ae2f_Pair_free(
	ptr_ae2f_Pair block
);
```

## ae2f_Pair_weigh
```c
int8_t 
ae2f_Pair_weigh(
	ptr_ae2f_Pair pair,
	ptr_ae2f_Dynamic compare,
	int8_t selector
);
```

# getter setter
## ae2f_Pair_set
```c
ptr_ae2f_Pair 
ae2f_Pair_set(
	ptr_ae2f_Pair pair,
	ptr_ae2f_Dynamic value,
	int8_t selector
);
```

## ae2f_Pair_get
```c
ae2f_Dynamic_owned 
ae2f_Pair_get(
	ptr_ae2f_Pair pair,
	int8_t selector
);
```