#include "framework.h"

#define AE2F_EXPORT
#include "ae2fLib/Container/Dimension.h"
#include "bullshit.h"

AE2F struct ae2f_Dimension* ae2f_Dimension(struct ae2f_Dimension* _this, uint64_t depth, uint64_t* lengthArray) {
	_this->depth = _this->pre = 0, _this->end = 1;

	AE2F_FOR(, uint64_t i = 0, i < depth - 1, i++,
		ae2f_Dimension_lay(_this, lengthArray[i])
	);
	ae2f_Dimension_morph(_this, lengthArray[depth - 1]);
	return _this;
}
AE2F struct ae2f_Dimension* ae2f_Dimension_lay(struct ae2f_Dimension* _this, uint64_t length) {
	switch (_this->end)
	{
	case 0: 
#pragma region for
		AE2F_FOR(, char* i = _this->c.c.bt1, i - _this->c.c.bt1 < _this->c.len, i += sizeof(struct ae2f_Dimension),
			ae2f_Dimension_lay(i, length);
		);
#pragma endregion
		break;
	default:
		// _this->end = 0;
		ae2f_Dynamic(&_this->c, length * sizeof(struct ae2f_Dimension));
#pragma region for
		AE2F_FOR(_1, struct ae2f_Dimension* i = _this->c.c.raw, i - _this->c.c.raw < length, i++,
			i->depth = _this->depth + 1;
		i->pre = _this; i->end = 1;
		);
#pragma endregion

		_this->end = 0;
		break;
	}

	return _this;
}
AE2F struct ae2f_Dimension* ae2f_Dimension_morph(struct ae2f_Dimension* _this, uint64_t length) {
	switch (_this->end)
	{
	case 0:
#pragma region for
		AE2F_FOR(, char* i = _this->c.c.bt1, i - _this->c.c.bt1 < _this->c.len, i += sizeof(struct ae2f_Dimension),
			ae2f_Dimension_morph(i, length);
		);
#pragma endregion
		break;

	default:
		ae2f_Dynamic(&_this->c, length);
		break;
	}

	return _this;
}
AE2F struct ae2f_Dimension* ae2f_Dimension_point(struct ae2f_Dimension* _this, uint64_t depth, uint64_t* posArray) {
	struct ae2f_Dimension* point = _this;
#pragma region for
	AE2F_FOR(, uint64_t i = 0, i < depth && !(point->end), i++, ;
	point = (struct ae2f_Dimension*)point->c.c.raw + posArray[i]);
#pragma endregion
	return point;
}
AE2F struct ae2f_Dimension* ae2f_Dimension_free(struct ae2f_Dimension* _this) {
	switch (_this->end)
	{
	case 0:
#pragma region for
		AE2F_FOR(_, struct ae2f_Dimension* i = _this->c.c.raw, (char*)i - _this->c.c.bt1 < _this->c.len, i++,
			ae2f_Dimension_free(i);
		);
#pragma endregion
		ae2f_Dynamic_free(&_this->c);
		return _this;
	default:
		_this->end = 1;
		return _this;
	}
}
struct ae2f_Dimension* ae2f_Dimension_copy_(struct ae2f_Dimension* _this, struct ae2f_Dimension* to, uint64_t dep) {
	to->depth = dep;  to->pre = 0; to->end = 1;
	
	switch (_this->end)
	{
	case 0: 
		ae2f_Dynamic(to, _this->c.len);
		AE2F_FOR(, uint64_t i = 0, i <= _this->c.len, i += sizeof(struct ae2f_Dimension),
			ae2f_Dimension_copy_(_this->c.c.bt1 + i, to->c.c.bt1 + i, dep + 1);
		)
		break;

	default:
		ae2f_Dynamic_(to, _this->c.c.raw, _this->c.len);
		break;
	}

	return to;
}
AE2F struct ae2f_Dimension* ae2f_Dimension_copy(struct ae2f_Dimension* _this, struct ae2f_Dimension* to) {
	ae2f_Dimension_copy_(_this, to, 0ull);
	return to;
}
AE2F struct ae2f_Dimension* ae2f_Dimension_setDepth(struct ae2f_Dimension* _this, uint64_t dep) {
	_this->depth = dep;
	switch (_this->end)
	{
	case 0:
		AE2F_FOR(, uint64_t i = 0, i < _this->c.len, i += sizeof(struct ae2f_Dimension),
			ae2f_Dimension_setDepth(_this->c.c.bt1 + i, dep + 1);
			);

	default: 
		return _this;
	}
}