#include "framework.h"

#include "bullshit.h"
#include "defs.h"
#define AE2F_EXPORT
#include "ae2fLib/Container/Map.h"

// #include <stdio.h>

#ifdef AE2F_MAP
AE2F ptr_ae2f_Map ae2f_Map(ptr_ae2f_Map _this) {
	_this->len = 0, _this->_amp = 1, _this->_div = 9;
	ae2f_Dynamic(&_this->pairs, 0);
	return _this;
}

inline char ae2f_Map_is(ptr_ae2f_Map _this, struct ae2f_Pair* p, char end) {
	switch (end) {
	case 1: return p - (struct ae2f_Pair*)_this->pairs.c.raw == _this->len - 1;
	case -1: return p == (struct ae2f_Pair*)_this->pairs.c.raw;
	}
}


AE2F ptr_ae2f_Pair ae2f_Map_at(ptr_ae2f_Map _this, ptr_ae2f_Dynamic key) {
	switch (_this && key) {
	case 0:
		return 0;	// _this or key is zero
	default:
		break;
	}

	switch (_this->len) {
	case 0: return _this->pairs.c.raw;	// length is zero
	default: break;
	}

	ptr_ae2f_Pair p = _this->pairs.c.raw; // existing val

#define _isOdd(a) (a - (a >> 1ull << 1ull))
	for (uint64_t l = _this->len; l;) {
		switch (ae2f_Pair_weigh(p + (l >> 1), key, 0)) {
		case 1:		// key가 커요, 오른쪽을 가요
		{
			p += (l >> 1) + 1;
			l = (l - 1) >> 1;
		} break;
		case -1:	// idx가 커요, 왼쪽을 가요
		{
			l >>= 1;
		} break;

		case 0: 
			return p + (l >> 1);
		}
	}

	return p;
}

AE2F struct ae2f_Map* ae2f_Map_add(struct ae2f_Map* _this, struct ae2f_Dynamic* k, struct ae2f_Dynamic* v) {
	struct ae2f_Dynamic blank = { "", 1 };
	v = v ? v : &blank;

	if (!_this) {
		return 0;
	}

	switch (k || 0) {
	case 0: return 0; // no key
	default: break;
	}

	// extends
	switch (_this->pairs.len > sizeof(struct ae2f_Pair) * (_this->len + 1)) {
	default: 
		break;
	case 0: 
		ae2f_Dynamic_re(&_this->pairs, _this->pairs.len * (_this->_div + _this->_amp) / (_this->_div) + sizeof(struct ae2f_Pair));
		break;
	}

	switch (_this->len) {
	case 0: 
	{
		ae2f_Pair(_this->pairs.c.raw, k, v);
		_this->len += 1;
		return _this;
	}
	default: break;
	}

	// put on the origin when it match
	struct ae2f_Pair* assume = ae2f_Map_at(_this, k);

	if (assume - _this->pairs.c.raw == _this->len) {
		ae2f_Pair(assume, k, v);
		_this->len++;
		return _this;
	}

	switch (ae2f_Pair_weigh(assume, k, 0)) {
	case 0: 
		ae2f_Pair_set(assume, v, 1);
		return _this;
	default: break;
	}

	// shift one right put on origin
	memcpy(
		assume + 1, 
		assume, 
		((_this->len - (assume - _this->pairs.c.raw)) * sizeof(struct ae2f_Pair))
	);

	ae2f_Pair(assume, k, v);
	
	_this->len++;
	return _this;
}

AE2F ptr_ae2f_Map ae2f_Map_add_(struct ae2f_Map* _this, ptr_ae2f_Pair pair) {
	struct ae2f_Dynamic 
		v = ae2f_Pair_get(pair, 1), 
		k = ae2f_Pair_get(pair, 0);

	return ae2f_Map_add(_this, &k, &v);
}

AE2F struct ae2f_Map* ae2f_Map_del(struct ae2f_Map* _this, struct ae2f_Pair* wh) {
	const unsigned long long
		pos = wh - _this->pairs.c.raw,
		right = _this->len - pos - 1;

	switch (pos >= _this->len) {
	case 1: return 0;
	default: 
		ae2f_Pair_free(wh);
		struct ae2f_Dynamic 
			buff = { malloc(right * sizeof(struct ae2f_Pair)), right * sizeof(struct ae2f_Pair) },
			origin = { wh + 1, right * sizeof(struct ae2f_Pair) };
		ae2f_Dynamic_puts(&buff, &origin, 1);

		origin.c.raw = wh;

		ae2f_Dynamic_puts(&origin, &buff, 1);
		ae2f_Dynamic_re(&_this->pairs, --_this->len * sizeof(struct ae2f_Pair));

		return _this;
	}
}
AE2F struct ae2f_Map* ae2f_Map_free(struct ae2f_Map* _this) {
	AE2F_FOR(, unsigned long long i = 0, i < _this->len, , ae2f_Pair_free(AE2F_DYNAMIC_CAST(_this->pairs, struct ae2f_Pair) + i++));
	ae2f_Dynamic_free(&(_this->pairs));
	_this->len = 0;
	return _this;
}
AE2F struct ae2f_Map* ae2f_Map_copy(struct ae2f_Map* _this, struct ae2f_Map* p) {
	ae2f_Map(p);

	p->_amp = _this->_amp, p->_div = _this->_div;
	p->len = _this->len;

	ae2f_Dynamic(&p->pairs, _this->len * sizeof(struct ae2f_Pair));
	for (unsigned long long i = 0; i < p->len; i++) {
		ae2f_Pair_copy(((struct ae2f_Pair*)_this->pairs.c.raw) + i, ((struct ae2f_Pair*)p->pairs.c.raw) + i);
	} return p;
}
#endif // AE2F_MAP
