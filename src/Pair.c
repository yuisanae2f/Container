#include "framework.h"
#define AE2F_EXPORT
#include "ae2fLib/Container/Pair.h"
#include "defs.h"

#ifdef AE2F_PAIR
AE2F struct ae2f_Pair* ae2f_Pair(struct ae2f_Pair* _this, struct ae2f_Dynamic* key, struct ae2f_Dynamic* value) {
	ae2f_Dynamic(&(_this->c), key->len + value->len);
	
	struct ae2f_Dynamic tmp = _this->c; 
	ae2f_Dynamic_puts(&tmp, key, 1);

	tmp.c.raw = tmp.c.bt1 + key->len; tmp.len = value->len;
	ae2f_Dynamic_puts(&tmp, value, 1);

	_this->val.raw = _this->c.c.bt1 + key->len;
	return _this;
}
AE2F struct ae2f_Pair* ae2f_Pair_(struct ae2f_Pair* _this, void* key, uint64_t kLen, void* val, uint64_t vLen) {
	struct ae2f_Dynamic k, v;

	k.c.raw = key, k.len = kLen;
	v.c.raw = val, v.len = vLen;

	return ae2f_Pair(_this, &k, &v);
}
AE2F struct ae2f_Pair* ae2f_Pair_free(struct ae2f_Pair* _this) {
	_this->val.num = 0;
	ae2f_Dynamic_free(&(_this->c));

	return _this;
}
#include <stdio.h>

AE2F int8_t ae2f_Pair_weigh(struct ae2f_Pair* p1, struct ae2f_Dynamic* p2, int8_t where) {
	struct ae2f_Dynamic a;

	switch (where)
	{
	case 0: // key
		a.c = p1->c.c, a.len = p1->val.bt1 - p1->c.c.bt1;
		break;
	case 1: // val
		a.c = p1->val; a.len = p1->c.len - (p1->val.bt1 - p1->c.c.bt1);
		break;
	default: return 2;
	}

	return ae2f_Dynamic_weigh(&a, p2);
}
AE2F struct ae2f_Pair* ae2f_Pair_set(struct ae2f_Pair* _this, struct ae2f_Dynamic* val, int8_t where) {
	if (!_this)
		return 0;

	switch (where)
	{
	case 1:;
		const uint64_t l = _this->val.bt1 - _this->c.c.bt1;

		ae2f_Dynamic_re((&_this->c), l + val->len);
		_this->val.raw = AE2F_DYNAMIC_CASTSHIFT(_this->c, void, l);
		
		memcpy(_this->val.raw, val->c.raw, _this->c.len - l);

		return _this;

	case 0:;
		struct ae2f_Dynamic rtn; ae2f_Dynamic(&rtn, _this->c.len - (_this->val.bt1 - _this->c.c.bt1) + val->len);
		ae2f_Dynamic_puts(&rtn, val, 1);

		struct ae2f_Dynamic
			tmpV = { _this->val, _this->c.len - (_this->val.bt1 - _this->c.c.bt1) },
			tmpR = { rtn.c.bt1 + val->len, rtn.len - val->len };

		ae2f_Dynamic_puts(&tmpR, &tmpV, 1);

		ae2f_Pair_free(_this);
		_this->c = rtn;
		_this->val.raw = rtn.c.bt1 + val->len;

	default: return 0;
	}
}
AE2F struct ae2f_Dynamic ae2f_Pair_get(struct ae2f_Pair* _this, int8_t where) {
	struct ae2f_Dynamic c;

	switch (where)
	{
	case 0:
		c.c = _this->c.c;
		c.len = _this->val.bt1 - _this->c.c.bt1;
		break;
	case 1:
		c.c = _this->val;
		c.len = _this->c.len - (_this->val.bt1 - _this->c.c.bt1);
		break;
	default: break;
	}

	return c;
}
AE2F struct ae2f_Pair* ae2f_Pair_copy(struct ae2f_Pair* _this, struct ae2f_Pair* dest) {
	ae2f_Dynamic_copy(&_this->c, &dest->c);
	dest->val.raw = dest->c.c.bt1 + _this->val.unum - _this->c.c.unum;

	return dest;
}
#endif // AE2F_PAIR
