// #define AE2F_DYNAMIC(name, byte) struct ae2f_Dynamic name; ae2f_Dynamic(&name, byte);
#define AE2F_DYNAMIC_(name, type, count) AE2F_DYNAMIC(name, sizeof(type) * count)
#define AE2F_DYNAMIC_CAST(name, type) ((type*)name.c.raw)
#define AE2F_DYNAMIC_CASTSHIFT(name, type, byte) ((type*)(name.c.bt1 + byte))
#define AE2F_DYNAMIC_INIT(name, type, ...) struct ae2f_Dynamic name; { \
type arr##name[] = __VA_ARGS__; \
ae2f_Dynamic(&name, sizeof(arr##name)); \
type* p##name = AE2F_DYNAMIC_CAST(name, type); \
for(unsigned long long i##name = 0; i##name < sizeof(arr##name); i##name += sizeof(type)) \
	*(p##name++) = arr##name[p##name - AE2F_DYNAMIC_CAST(name, type)]; \
}
#define AE2F_DYNAMIC_INIT_(name, type, count, ...) struct ae2f_Dynamic name; { \
type arr##name[] = __VA_ARGS__; \
ae2f_Dynamic(&name, count * sizeof(type)); \
type* p##name = AE2F_DYNAMIC_CAST(name, type); \
unsigned long long i##name = 0;\
for(; i##name < sizeof(arr##name) && i##name < count; i##name++)\
	*(p##name++) = arr##name[p##name - AE2F_DYNAMIC_CAST(name, type)]; \
for(;i##name < count; i##name++) *(p##name++) = arr##name[p##name - AE2F_DYNAMIC_CAST(name, type)];\
}
#define AE2F_DYNAMIC_FOREACH(name, type, ...) {\
type* name##_pointer = AE2F_DYNAMIC_CAST(name, type); \
for(unsigned long long name##_i = 0; name##_i < name.len; name##_i += sizeof(type)) { \
__VA_ARGS__ name##_pointer++;}}

#define AE2F_DYNAMIC_USING(name, byte, ...) {AE2F_DYNAMIC(name, byte) __VA_ARGS__ ae2f_Dynamic_free(&name);}
#define AE2F_DYNAMIC_PUTS(this, another, idxName, id) { \
idxName = 0; \
AE2F_FOR(id##ida,, idxName + 8 < another.len, idxName += 8, *((long long*)(this.c.bt1 + idxName)) = *((long long*)(another.c.bt1 + idxName));); \
AE2F_FOR(id##idb,, idxName + 4 < another.len, idxName += 4, *((long*)(this.c.bt1 + idxName)) = *((long*)(another.c.bt1 + idxName));); \
AE2F_FOR(id##idc,, idxName + 2 < another.len, idxName += 2, *((short*)(this.c.bt1 + idxName)) = *((short*)(another.c.bt1 + idxName));); \
AE2F_FOR(id##idd,, idxName < another.len, /**/, (this.c.bt1)[idxName] = (another.c.bt1)[idxName++]); \
}