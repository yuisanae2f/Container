#pragma once
#include "Pair.h"

#ifdef __cplusplus

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

	class fun<Container::Pair>::getter : public def<struct ae2f_Pair> {
	private:
		ptr p;
	public:
		class _key;
		class _val;

		/// <param name="a">: base ptr</param>
		inline getter(
			ptr a	// base ptr
		);

		/// <typeparam name="t">: _key or _val only</typeparam>
		template<typename t>
		inline Container::Linked get();

		inline ptr raw();
	};
	class fun<Container::Pair>::setter : public getter {
	public:
		/// <param name="a">: base ptr</param>
		inline setter(
			ptr a	// base ptr
		);

		inline starter free();

		template<typename tt>
		class el : public def<struct ae2f_Pair> {
		private:
			ptr p;
		public:
			inline ptr raw() {
				return this->p;
			}

			/// <param name="a">: base ptr</param>
			inline el(
				ptr a	// base ptr
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
	class fun<Container::Pair>::starter : public def<struct ae2f_Pair> {
	private:
		ptr p;
	public:
		/// <param name="a">: base ptr</param>
		inline starter(
			ptr a	// base ptr
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
			orig obj;

		public:
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
				orig a	// source
			);

			/// <param name="a">: source ptr</param>
			inline Pair(
				ptr a	// source ptr
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