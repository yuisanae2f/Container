# #include
## <a href="../Container.md#Dynamic">ae2f</a>_<a href="./Dynamic.md">Dynamic</a> <d id="_Dynamic"></d>
is the basic allocator for dynamic data type for C.  

# <a href="../Container.md#Dimension">ae2f</a>_Dimension
```c
struct ae2f_Dimension {
	struct ae2f_Dynamic c;
	unsigned long long depth;
	char end;
	struct ae2f_Dimension* pre;
};
```
provides the feature of managing the multidimensional array.  
## ae2f_Dimension::depth
stands for the count of the parent above this structure.
## ae2f_Dimension::end <d id="end"></d>
describes if this has a child.
## ae2f_Dimension::pre
points the parent structure of this.
## ae2f_Dimension::c
container for the value.  
contains the array of pointer of its child provided <a>`end`</a> does not equals to zero.
## struct ae2f_Dimension* ae2f_Dimension(struct ae2f_Dimension* _this, unsigned long long depth, unsigned long long* lengthArray);
initialises the certain structure of `_this`.  
receives the `depth`, and array of required length for each depth level as `lengthArray`.
```c
struct ae2f_Dimension dimension;
unsigned long long lenArray[] = { 2,16 };
ae2f_Dimension(&dimension, 2, lenArray);
```
## struct ae2f_Dimension* ae2f_Dimension_lay(struct ae2f_Dimension* _this, unsigned long long length);
iterates the end of the childs of `_this` and sets the array of `ae2f_Dimension` with a count of `length`.
```c
struct ae2f_Dimension dimension;
dimention.depth = 0;
ae2f_Dimension_lay(&dimension, 4);
```
is also could be called multiple times.
```c
struct ae2f_Dimension dimension;
dimention.depth = 0;
ae2f_Dimension_lay(&dimension, 4);
ae2f_Dimension_lay(&dimension, 5);
```

## struct ae2f_Dimension* ae2f_Dimension_morph(struct ae2f_Dimension* _this, unsigned long long length);
iterates the end of the childs of `_this` and allocates the value with a length of `length`.
```c
struct ae2f_Dimension dimension;
dimention.depth = 0;
ae2f_Dimension_lay(&dimension, 4);
ae2f_Dimension_lay(&dimension, 5);
ae2f_Dimension_morph(&dimension, 3); // whatever the printing method
```
must be called once with `this` which is not morphed.

## struct ae2f_Dimension* ae2f_Dimension_setDepth(struct ae2f_Dimension* _this, unsigned long long dep);
sets the value of `depth` where `_this` points.  
its child's value of `depth` would be one greater than its parents'.
```c
struct ae2f_Dimension dimension;
ae2f_Dimension_lay(&dimension, 4);
ae2f_Dimension_setDepth(struct ae2f_Dimension* _this, unsigned long long dep);
ae2f_Dimension_morph(&dimension, 3); // whatever the printing method
```
## struct ae2f_Dimension* ae2f_Dimension_free(struct ae2f_Dimension* _this);
free the memory of `_this`.  
will iterate its child and also free them.
```c
struct ae2f_Dimension dimension;
ae2f_Dimension_lay(&dimension, 4);

// whatever you would like to do.

ae2f_Dimension_free(&dimension);
```
## struct ae2f_Dimension* ae2f_Dimension_point(struct ae2f_Dimension* _this, unsigned long long depth, unsigned long long* posArray);
points the child of `_this` in the depth level of `depth`.  
in each level of depth will read the `posArray` with index of `depth` as a position where the child has been estimated.
```c
struct ae2f_Dimension dimension;

unsigned long long lenArray[] = { 2,16 };
ae2f_Dimension(&dimension, 2, lenArray);

lenArray[0] = 1;
printf("%p", ae2f_Dimension_point(&dimension, 1, lenArray));
```

## struct ae2f_Dimension* ae2f_Dimension_copy(struct ae2f_Dimension* _this, struct ae2f_Dimension* to);
copies the value of `_this` and its child and paste in `to`.
```c
struct ae2f_Dimension dimension, dimension2;

unsigned long long lenArray[] = { 2,16 };
ae2f_Dimension(&dimension, 2, lenArray);
ae2f_Dimension_copy(&dimension, &dimension2);
```