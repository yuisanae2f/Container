# ae2f_Context
```c
struct ae2f_Context {
	struct ae2f_Dynamic c;
	unsigned long long len;
	unsigned long long _amp;
	unsigned long long _div;
};
```
is the binder for the temporary dynamic allocation on scope.  
could be used when you want to manage `temporary dynamic allocation` in the same scope.

## ae2f_Context
```c
struct ae2f_Context* ae2f_Context(struct ae2f_Context* _this);
```
initialises `_this` ready for action.
```c
struct ae2f_Context ctx; ae2f_Context(&ctx);
```

## struct ae2f_Dynamic* ae2f_Context_malloc(struct ae2f_Context* _this, unsigned long long len);
allocates the room chained by `_this`, in the size of `len`.  
returns the address of the room allocated.
```c
struct ae2f_Context ctx; ae2f_Context(&ctx);
struct ae2f_Dynamic* a = ae2f_Context_malloc(&ctx, 4);
*(a->c.bt4) = 3; printf("%d", *(a->c.bt4));	// 3
```

## struct ae2f_Context* ae2f_Context_free(struct ae2f_Context* _this);
free all the room chained by `_this`.  
returns the address of `_this`.
```c
struct ae2f_Context ctx; ae2f_Context(&ctx);
struct ae2f_Dynamic* a = ae2f_Context_malloc(&ctx, 4);
*(a->c.bt4) = 3; printf("%d", *(a->c.bt4));	// 3

ae2f_Context_free(&ctx);
printf("%d", *(a->c.bt4));			// err
```