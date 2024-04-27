# Unit
Pointer slicer

```c
union ae2f_Unit {
    void* raw;

    char* bt1;
    unsigned char* ubt1;

    short* bt2;
    unsigned short* ubt2;

    int* bt4;
    unsigned int* ubt4;

    long long* bt8;
    unsigned long long* ubt8;

    long long num;
    unsigned long long unum;

    double real;

    float* rbt4;
    double* rbt8;
};
```