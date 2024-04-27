#include "framework.h"
#define AE2F_EXPORT
#include "ae2fLib/Container/Dynamic.h"

#include "defs.h"
#include "bullshit.h"

#ifdef AE2F_DYNAMIC

#pragma region consts
AE2F ptr_ae2f_Dynamic ae2f_Dynamic(ptr_ae2f_Dynamic _this, uint64_t len) {
	_this->c.raw = len != 0 ? calloc(1, len) : 0;
	_this->len = _this->c.raw ? len : 0;
	return _this;
}

AE2F ptr_ae2f_Dynamic ae2f_Dynamic_(ptr_ae2f_Dynamic _this, void* val, uint64_t len) {
	ae2f_Dynamic(_this, len);
	memcpy(_this->c.raw, val, len);

	return _this;
}
AE2F ptr_ae2f_Dynamic ae2f_Dynamic_copy(ptr_ae2f_Dynamic _this, ptr_ae2f_Dynamic p) {
	return ae2f_Dynamic_(p, _this->c.raw, _this->len);
}
AE2F ptr_ae2f_Dynamic ae2f_Dynamic_re(ptr_ae2f_Dynamic _this, uint64_t len) {
	void* new = realloc(_this->c.raw, len);

	if (!new) return 0;
	if (new != _this->c.raw) {
		free(_this->c.raw);
		_this->c.raw = new;
	}

	// memset(_this->c.raw, 0, len);
	_this->len = len;
	return _this;
}
AE2F ptr_ae2f_Dynamic ae2f_Dynamic_re_(ptr_ae2f_Dynamic _this, void* arr, uint64_t len) {
	void* new = realloc(_this->c.raw, len);

	if (!new) return 0;

	_this->c.raw = new;
	memcpy(_this->c.raw, arr, len);
	_this->len = len;
	return _this;
}
AE2F uint64_t ae2f_Dynamic_puts(ptr_ae2f_Dynamic _this, ptr_ae2f_Dynamic another, uint8_t fitToThis) {
	memcpy(_this->c.raw, another->c.raw, fitToThis && _this->len > another->len ? _this->len : another->len);
	return fitToThis ? _this->len : another->len;
}
AE2F ptr_ae2f_Dynamic ae2f_Dynamic_free(ptr_ae2f_Dynamic _this) {
	switch (_this->len && _this->c.raw)
	{
	default:
		free(_this->c.raw);
	case 0:
		_this->c.num = 0;
		_this->len = 0;
		return _this;
	}
}

/// <param name="a">: value source</param>
/// <param name="b">: value wanted</param>
/// <param name="c">: count to ignore</param>
AE2F union ae2f_Unit ae2f_Dynamic_find(
	ptr_ae2f_Dynamic a,	// value source
	ptr_ae2f_Dynamic b,	// value wanted
	uint64_t c			// count to ignore
) {
	struct ae2f_Dynamic i = { 0, a->len };

	switch (a->len < b->len) {
	case 1: return i.c;
	default: break;
	}

	for (i.c = a->c; i.len >= b->len; i.len--, i.c.bt1++) {
		uint64_t corr = ae2f_Dynamic_countEqual(&i, b);

		switch (corr == b->len) {
		case 0:
			i.len -= corr;
			i.c.bt1 += corr;
			break;
		default:
			switch (c) {
			case 0: 
				return i.c;
			default:
				i.len -= corr;
				i.c.bt1 += corr;
				return ae2f_Dynamic_find(&i, b, c - 1);
			}
		}
	}

	i.c.raw = 0;

	return i.c;
}

AE2F uint64_t ae2f_Dynamic_countEqual(ptr_ae2f_Dynamic a, ptr_ae2f_Dynamic b) {
	uint64_t count = 0;

	for (char i = 1; i && count < (a->len >> 3) && count < (b->len >> 3); count++) {
		switch (a->c.ubt8[count] == b->c.ubt8[count]) {
		case 1: break;
		default: i = 0; count--; break;
		}
	}

	count <<= 1;

	for (char i = 1; i && count < (a->len >> 2) && count < (b->len >> 2); count++) {
		switch (a->c.ubt4[count] == b->c.ubt4[count]) {
		case 1: break;
		default: i = 0; count--; break;
		}
	}

	count <<= 1;

	for (char i = 1; i && count < (a->len >> 1) && count < (b->len >> 1); count++) {
		switch (a->c.ubt2[count] == b->c.ubt2[count]) {
		case 1: break;
		default: i = 0; count--; break;
		}
	}

	count <<= 1;

	for (char i = 1; i && count < (a->len) && count < (b->len); count++) {
		switch (a->c.ubt1[count] == b->c.ubt1[count]) {
		case 1: break;
		default: i = 0; count--; break;
		}
	}

	return count;
}

AE2F int8_t ae2f_Dynamic_weigh(ptr_ae2f_Dynamic a, ptr_ae2f_Dynamic b) {
	switch (a->len == b->len)
	{
	case 1:;
		uint64_t i = 0;

		AE2F_FOR(_8, , i + 8 < a->len, i += 8, ;
		switch (*((int64_t*)(a->c.bt1 + i)) == *((int64_t*)(b->c.bt1 + i)))
		{
		case 1: break;
		default:
			return 1 - (*((int64_t*)(a->c.bt1 + i)) > *((int64_t*)(b->c.bt1 + i))) * 2;
		});

		AE2F_FOR(_4, , i + 4 < a->len, i += 4, ;
		switch (*((int32_t*)(a->c.bt1 + i)) == *((int32_t*)(b->c.bt1 + i)))
		{
		case 1: break;
		default: return 1 - (*((int32_t*)(a->c.bt1 + i)) > *((int32_t*)(b->c.bt1 + i))) * 2;
		});

		AE2F_FOR(_2, , i + 2 < a->len, i += 2, ;
		switch (*((int16_t*)(a->c.bt1 + i)) == *((int16_t*)(b->c.bt1 + i)))
		{
		case 1: break;
		default: return 1 - (*((int16_t*)(a->c.bt1 + i)) > *((int16_t*)(b->c.bt1 + i))) * 2;
		});

		AE2F_FOR(_1, , i < a->len, i++, ;
		switch ((a->c.bt1)[i] == (b->c.bt1)[i])
		{
		case 1: break;
		default: return 1 - ((a->c.bt1)[i] > (b->c.bt1)[i]) * 2;
		});

		return 0;

	default:
		return 1 - (a->len > b->len) * 2;
	}
}
#pragma endregion
#endif // AE2F_CONTAINER_ARRAY