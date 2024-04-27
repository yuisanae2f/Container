#pragma once
#include "Dynamic.h"

#ifdef AE2F_DYNAMIC
#ifndef AE2F_PAIR
#define AE2F_PAIR

typedef struct ae2f_Pair {
	struct ae2f_Dynamic c;
	union ae2f_Unit val;
}* ptr_ae2f_Pair;

typedef struct ae2f_Dynamic ae2f_Dynamic_owned;
#endif // AE2F_PAIR

#ifndef AE2F_PAIR_FUN
#define AE2F_PAIR_FUN
/// <param name="a">: pair</param>
/// <param name="b">: key</param>
/// <param name="c">: value</param>
AE2F_CPP_PREFIX AE2F ptr_ae2f_Pair ae2f_Pair(
	ptr_ae2f_Pair a,	// pair
	ptr_ae2f_Dynamic b,	// key
	ptr_ae2f_Dynamic c	// value
);

/// <param name="a">: pair</param>
/// <param name="b">: key</param>
/// <param name="c">: length key</param>
/// <param name="d">: value</param>
/// <param name="e">: length value</param>
AE2F_CPP_PREFIX AE2F ptr_ae2f_Pair ae2f_Pair_(
	ptr_ae2f_Pair a,	// pair
	void* b,				// key
	uint64_t c,				// length key
	void* d,				// value
	uint64_t e				// length value
);

/// <param name="a">: pair to be freed</param>
AE2F_CPP_PREFIX AE2F ptr_ae2f_Pair ae2f_Pair_free(
	ptr_ae2f_Pair a		// pair to be freed
);

/// <param name="a">: pair</param>
/// <param name="b">: value to be compared</param>
/// <param name="c">: value on 1 otherwise key</param>
AE2F_CPP_PREFIX AE2F int8_t ae2f_Pair_weigh(
	ptr_ae2f_Pair a,	// pair
	ptr_ae2f_Dynamic b,	// value to be compared
	int8_t c				// value on 1 otherwise key
);

/// <param name="a">: pair to be set</param>
/// <param name="b">: value to set</param>
/// <param name="c">: value on 1 otherwise key</param>
AE2F_CPP_PREFIX AE2F ptr_ae2f_Pair ae2f_Pair_set(
	ptr_ae2f_Pair a,	// pair to be set
	ptr_ae2f_Dynamic b,	// value to set
	int8_t c				// value on 1 otherwise key
);

/// <param name="a">: pair to get</param>
/// <param name="b">: value on 1 otherwise key</param>
AE2F_CPP_PREFIX AE2F ae2f_Dynamic_owned ae2f_Pair_get(
	ptr_ae2f_Pair a,	// pair to get
	int8_t b				// value on 1 otherwise key
);

/// <param name="a">: source</param>
/// <param name="b">: destination</param>
AE2F_CPP_PREFIX AE2F ptr_ae2f_Pair ae2f_Pair_copy(
	ptr_ae2f_Pair a,	// source
	ptr_ae2f_Pair b		// destination
);
#endif // !AE2F_PAIR_FUN

#ifdef AE2F_CPP
#ifndef AE2F_PAIR_CPP
#define AE2F_PAIR_CPP

namespace ae2f {
	template<typename t> class fun;
	namespace Container {
		class Pair;
	}
	template<> class fun<Container::Pair> {
	public:
		class setter;
		class getter;
		class starter;
	};

	class fun<Container::Pair>::getter {
	private:
		struct ae2f_Pair* p;
	public:
		class _key;
		class _val;

		/// <param name="a">: base ptr</param>
		inline getter(
			ptr_ae2f_Pair a	// base ptr
		);
		
		/// <typeparam name="t">: _key or _val only</typeparam>
		template<typename t>
		inline Container::Linked get();

		inline ptr_ae2f_Pair raw();
	};
	class fun<Container::Pair>::setter : public getter {
	public:
		/// <param name="a">: base ptr</param>
		inline setter(
			struct ae2f_Pair* a	// base ptr
		);

		inline starter free();

		template<typename tt> 
		class el {
		private:
			ptr_ae2f_Pair p;
		public:
			inline ptr_ae2f_Pair raw() {
				return this->p;
			}

			/// <param name="a">: base ptr</param>
			inline el(
				ptr_ae2f_Pair a	// base ptr
			);

			inline Container::Linked operator()();

			/// <param name="a">: setter val ptr</param>
			inline el<tt>& operator()(
				Container::Linked* a	// setter val ptr
				);

			/// <param name="a">: setter val ptr</param>
			inline el<tt>& operator()(
				Container::Linked a	// setter val
				);
		};

		template<typename t>
		inline el<t> set();
	};
	class fun<Container::Pair>::starter {
	private:
		struct ae2f_Pair* p;
	public:
		/// <param name="a">: base ptr</param>
		inline starter(
			ptr_ae2f_Pair a	// base ptr
		);

		/// <param name="a">: key</param>
		/// <param name="b">: val</param>
		inline setter alloc(
			Container::Linked a,	// key
			Container::Linked b		// val
		);

		/// <param name="a">: key ptr</param>
		/// <param name="b">: val ptr</param>
		inline setter alloc(
			Container::Linked* a,	// key ptr
			Container::Linked* b	// val ptr
		);

		/// <param name="a">: source</param>
		inline setter copy(
			getter a	// source
		);

		/// <param name="a">: source ptr</param>
		inline setter copy(
			getter* a	// source ptr
		);
	};
	namespace Container {
		class Pair : public fun<Pair>::setter {
		private:
			struct ae2f_Pair obj;

		public:
			typedef ptr_ae2f_Pair binder;

			/// <param name="a">: key</param>
			/// <param name="b">: val</param>
			inline Pair(
				Linked a,	// key
				Linked b	// value
			);

			/// <param name="a">: key ptr</param>
			/// <param name="b">: val ptr</param>
			inline Pair(
				Linked* a,	// key ptr
				Linked* b	// val ptr
			);

			/// <param name="a">: key</param>
			inline Pair(
				Linked a	// key
			);

			/// <param name="a">: key ptr</param>
			inline Pair(
				Linked* a	// key ptr
			);

			/// <param name="a">: source</param>
			inline Pair(
				struct ae2f_Pair a	// source
			);

			/// <param name="a">: source ptr</param>
			inline Pair(
				struct ae2f_Pair* a	// source ptr
			);

			inline ~Pair();
		};
	}
}

#define ae2f_ffun ae2f::fun<ae2f::Container::Pair>
#define ae2f_nname ae2f::Container

#pragma region getter
inline ae2f_ffun::getter::getter(ptr_ae2f_Pair a)
	: p(a) {}

template<>
inline ae2f_nname::Linked ae2f_ffun::getter::get<ae2f_ffun::getter::_key>() {
	return ae2f_Pair_get(this->p, 0);
}

template<>
inline ae2f_nname::Linked ae2f_ffun::getter::get<ae2f_ffun::getter::_val>() {
	return ae2f_Pair_get(this->p, 1);
}

inline ptr_ae2f_Pair ae2f_ffun::getter::raw() { return this->p; }


#pragma endregion
#pragma region setter

inline ae2f_ffun::setter::setter(
	struct ae2f_Pair* a	// base ptr
) : getter(a) {}

inline ae2f_ffun::starter ae2f_ffun::setter::free() {
	ae2f_Pair_free(this->raw());
	return this->raw();
}

template<>
inline ae2f_ffun::setter::el<ae2f_ffun::getter::_key> ae2f_ffun::setter::set<ae2f_ffun::getter::_key>() { return this->raw(); }

template<>
inline ae2f_ffun::setter::el<ae2f_ffun::getter::_val> ae2f_ffun::setter::set<ae2f_ffun::getter::_val>() { return this->raw(); }
#pragma endregion
#pragma region el
template<typename t>
inline ae2f_ffun::setter::el<t>::el(ptr_ae2f_Pair a)
	: p(a) {}

template<typename t>
inline ae2f_nname::Linked ae2f_ffun::setter::el<t>::operator()() {
	return setter(this->p).get<t>();
}

template<typename t>
inline ae2f_ffun::setter::el<t>& 
ae2f_ffun::setter::el<t>::operator()(ae2f_nname::Linked a) {
	return this[0](&a);
}

template<>
inline ae2f_ffun::setter::el<ae2f_ffun::setter::_key>& 
ae2f_ffun::setter::el<ae2f_ffun::setter::_key>::operator()(ae2f_nname::Linked* a) {
	ae2f_Pair_set(this->p, a->raw(), 0);
	return *this;
}

template<>
inline ae2f_ffun::setter::el<ae2f_ffun::setter::_val>&
ae2f_ffun::setter::el<ae2f_ffun::setter::_val>::operator()(ae2f_nname::Linked* a) {
	ae2f_Pair_set(this->p, a->raw(), 1);
	return *this;
}
#pragma endregion
#pragma region starter
ae2f_ffun::starter::starter(ptr_ae2f_Pair a) : p(a) {}
ae2f_ffun::setter ae2f_ffun::starter::alloc(Container::Linked* a, Container::Linked* b) {
	ae2f_Pair(this->p, a->raw(), b->raw());

	return this->p;
}
ae2f_ffun::setter ae2f_ffun::starter::alloc(Container::Linked a, Container::Linked b) {
	return this->alloc(&a, &b);
}

ae2f_ffun::setter ae2f_ffun::starter::copy(getter* a) {
	ae2f_Pair_copy(a->raw(), this->p);

	return this->p;
}

ae2f_ffun::setter ae2f_ffun::starter::copy(getter a) {
	return this->copy(&a);
}

#pragma endregion

#pragma region Pair
ae2f_nname::Pair::Pair(Linked* a, Linked* b)
	: setter(ae2f_ffun::starter(&this->obj).alloc(a, b)) {}

ae2f_nname::Pair::Pair(Linked a, Linked b)
	: setter(ae2f_ffun::starter(&this->obj).alloc(a, b)) {}

ae2f_nname::Pair::Pair(Linked* a) : setter(&this->obj) {
	ae2f_Pair(&this->obj, a->raw(), 0);
	return;
}

ae2f_nname::Pair::Pair(Linked a) : setter(&this->obj) {
	ae2f_Pair(&this->obj, a.raw(), 0);
	return;
}

ae2f_nname::Pair::Pair(ptr_ae2f_Pair a)
	: setter(ae2f_ffun::starter(&this->obj).copy(a)) {}

ae2f_nname::Pair::Pair(struct ae2f_Pair a)
	: setter(ae2f_ffun::starter(&this->obj).copy(&a)) {}

ae2f_nname::Pair::~Pair() {
	this->free();
}
#pragma endregion

#undef ae2f_ffun
#undef ae2f_nname
#endif
#endif // !AE2F_PAIR_CPP
#endif // !AE2F_DYNAMIC
