#include "framework.h"

#include "bullshit.h"
#include "defs.h"
#define AE2F_EXPORT
#include "ae2fLib/Container/Context.h"

AE2F ptr_ae2f_Context ae2f_Context(ptr_ae2f_Context _this) {
	_this->len = 0; _this->_amp = 1; _this->_div = 9;
	ae2f_Dynamic(&_this->c, 0);

	return _this;
}

AE2F uint64_t ae2f_Context_malloc(ptr_ae2f_Context _this, uint64_t len) {

	_this->_div += !(_this->_div && 1);
	switch (_this->c.len > (_this->len + 1) * sizeof(struct ae2f_Dynamic))
	{
	case 0:
		ae2f_Dynamic_re(&_this->c, _this->c.len * (1 + _this->_amp / _this->_div) + sizeof(struct ae2f_Dynamic));
	default:
		return ae2f_Dynamic(AE2F_DYNAMIC_CAST(_this->c, struct ae2f_Dynamic) + (_this->len)++, len) - _this->c.c.raw;
	}

	return 0;
}

AE2F ptr_ae2f_Context ae2f_Context_free(ptr_ae2f_Context _this) {

	AE2F_FOR(_, uint64_t i = 0, i < _this->len, i++;,
		ae2f_Dynamic_free(AE2F_DYNAMIC_CAST(_this->c, struct ae2f_Dynamic) + i)
	);

	ae2f_Dynamic_free(&_this->c);
	_this->len = 0;
	return _this;
}

AE2F ptr_ae2f_Context ae2f_Context_del(
	ptr_ae2f_Context a,
	uint64_t b
) {
	if (b >= a->len) {
		return 0;
	}

	ae2f_Dynamic_free(ae2f_Context_point((*a)) + b);


	// 1 2 3 -> 1, 1 + 1, 3 - 1 - 1
	// 1 3
	memcpy(
		ae2f_Context_point((*a)) + b,
		ae2f_Context_point((*a)) + b + sizeof(struct ae2f_Dynamic),
		a->len - (b)
	);

	a->len -= 1;
	printf("%llu\n", a->len);

	return a;
}

/// <param name="a">: source</param>
/// <param name="b">: destination</param>
AE2F_CPP_PREFIX AE2F void ae2f_Context_copy(
	ptr_ae2f_Context a,
	ptr_ae2f_Context b
) {
	b = malloc(a->len * sizeof(struct ae2f_Dynamic));
	b->_amp = a->_amp;
	b->_div = a->_div;

	for (int i = 0; i < a->len; i++)
		ae2f_Dynamic_copy(ae2f_Context_point(a[0]) + i, ae2f_Context_point(b[0]) + i);

	return;
}