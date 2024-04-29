#pragma once
#include "Pair.h"

#ifdef AE2F_PAIR
#ifndef AE2F_MAP
#define AE2F_MAP
typedef struct ae2f_Map {
	struct ae2f_Dynamic pairs;
	uint64_t len;
	uint64_t _amp; uint64_t _div;
}*ptr_ae2f_Map;
#endif // !AE2F_MAP
#ifndef AE2F_MAP_FUN
#define AE2F_MAP_FUN
/// <param name="a">: map to be initialised</param>
AE2F_CPP_PREFIX AE2F ptr_ae2f_Map ae2f_Map(
	ptr_ae2f_Map a	// map to be initialised
);

/// <param name="a">: map</param>
/// <param name="b">: key to search</param>
AE2F_CPP_PREFIX AE2F ptr_ae2f_Pair ae2f_Map_at(
	ptr_ae2f_Map a,		// map
	ptr_ae2f_Dynamic b	// key to search
);

/// <param name="a">: map</param>
/// <param name="b">: key to add</param>
/// <param name="c">: value to add</param>
AE2F_CPP_PREFIX AE2F ptr_ae2f_Map ae2f_Map_add(
	ptr_ae2f_Map a,		// map
	ptr_ae2f_Dynamic b,	// key to add
	ptr_ae2f_Dynamic c	// value to add
);

AE2F_CPP_PREFIX AE2F ptr_ae2f_Map ae2f_Map_add_(
	ptr_ae2f_Map a,		// map
	ptr_ae2f_Pair b		// key to add
);

/// <param name="a">: map</param>
/// <param name="b">: pointer to be dead</param>
AE2F_CPP_PREFIX AE2F ptr_ae2f_Map ae2f_Map_del(
	ptr_ae2f_Map a,	// map 
	ptr_ae2f_Pair b	// pointer to be dead
);

/// <param name="a">: map</param>
AE2F_CPP_PREFIX AE2F ptr_ae2f_Map ae2f_Map_free(
	ptr_ae2f_Map a	// map
);

/// <param name="a">: source</param>
/// <param name="b">: destination</param>
AE2F_CPP_PREFIX AE2F ptr_ae2f_Map ae2f_Map_copy(
	ptr_ae2f_Map a,	// source
	ptr_ae2f_Map b	// destination
);
#endif // !AE2F_MAP_FUN


#ifdef AE2F_CPP
#ifndef AE2F_MAP_CPP
#define AE2F_MAP_CPP

namespace ae2f {
	namespace Container {
		class Map;
	}

	template<>
	class fun<Container::Map> {
	public:
		class el;
		class setter;
		class starter;
	};

	class fun<Container::Map>::el : 
		public fun<Container::Pair>::setter::el<Container::Pair::_val>
	{
	public:
		typedef def<struct ae2f_Map> _root;

	private:
		_root::ptr p;
	public:
		inline _root::ptr id() { return p; }

		/// <param name="a">: base map</param>
		/// <param name="b">: pair within map</param>
		inline el(_root::ptr a, ptr b);

		inline setter del();
		inline Container::Dynamic key() {
			return fun<Container::Pair>::getter(this->raw()).get<Container::Pair::_key>();
		}
	};

	class fun<Container::Map>::setter : public def<struct ae2f_Map> {
	private:
		ptr p;
	public:
		inline ptr raw();
		
		uint64_t
			& _div,
			& _amp;

		/// <param name="a">: base ptr</param>
		inline setter(ptr a);

		/// <param name="a">: key</param>
		inline el at(
			Container::Linked* a
		);

		/// <param name="a">: key</param>
		inline el at(
			Container::Linked a
		);

		/// <param name="a">: key</param>
		/// <param name="b">: value</param>
		inline el add(
			Container::Linked* a, 
			Container::Linked* b
		);

		/// <param name="a">: key</param>
		/// <param name="b">: value</param>
		inline el add(
			Container::Linked a,
			Container::Linked b
		);

		/// <param name="a">: pair</param>
		inline el add(
			Container::Pair* a
		);

		/// <param name="a">: pair</param>
		inline el add(
			Container::Pair a
		);

		inline starter free();
	};

	class fun<Container::Map>::starter : public def<struct ae2f_Map> {
	private:
		ptr p;

	public:
		/// <param name="a">: base ptr</param>
		inline starter(ptr a);
		inline setter alloc();

		/// <param name="a">: source value</param>
		inline setter copy(ptr a);
		/// <param name="a">: source value</param>
		inline setter copy(orig a);
		/// <param name="a">: source value</param>
		inline setter copy(setter a);
		/// <param name="a">: source value</param>
		inline setter copy(setter* a);
	};

	namespace Container {
		class Map : public fun<Map>::setter {
		private:
			orig obj;
		public:
			inline Map();
			/// <param name="a">: source value</param>
			inline Map(ptr a);
			/// <param name="a">: source value</param>
			inline Map(orig a);
			/// <param name="a">: source value</param>
			inline Map(setter a);
			/// <param name="a">: source value</param>
			inline Map(setter* a);

			

			inline ~Map();
		};
	}
}

#define ae2f_nname ae2f::Container
#define ae2f_ffun ae2f::fun<ae2f::Container::Map>

#pragma region el
inline ae2f_ffun::el::el(ptr_ae2f_Map m, ptr_ae2f_Pair p)
	: ae2f_nname::Pair::el<ae2f_nname::Pair::_val>(p), p(m) {}

inline ae2f_ffun::setter ae2f_ffun::el::del() {
	ae2f_Map_del(this->p, this->raw());
	return this->p;
}
#pragma endregion
#pragma region setter
inline ptr_ae2f_Map ae2f_ffun::setter::raw() {
	return this->p;
}

inline ae2f_ffun::setter::setter(ptr_ae2f_Map a)
	: p(a), _div(a->_div), _amp(a->_amp) {}

inline ae2f_ffun::el ae2f_ffun::setter::at(Container::Linked* a) {
	auto p = ae2f_Map_at(this->p, a->raw());

#define within(l, r, c) (c >= l && c < r)

	if (!p || !within(0, this->p->len, (p - this->raw()->pairs.c.raw))) {
		return this->add(Container::Pair(a[0], Container::Linked("", 1)));
	}

#undef within

	return { this->p, p };
}

inline ae2f_ffun::el ae2f_ffun::setter::at(Container::Linked a) {
	return this->at(&a);
}

inline ae2f_ffun::el ae2f_ffun::setter::add(Container::Pair* a) {
	ae2f_Map_add_(this->p, a->raw());
	return this->at(a->get<Container::Pair::_key>());
}

inline ae2f_ffun::el ae2f_ffun::setter::add(Container::Pair a) {
	return this->add(&a);
}

inline ae2f_ffun::el ae2f_ffun::setter::add(Container::Linked* a, Container::Linked* b) {
	Container::Pair p(a, b);
	return this->add(&p);
}

inline ae2f_ffun::el ae2f_ffun::setter::add(Container::Linked a, Container::Linked b) {
	return this->add(&a, &b);
}

inline ae2f_ffun::starter ae2f_ffun::setter::free() { return this->p; }
#pragma endregion
#pragma region starter
inline ae2f_ffun::starter::starter(ptr_ae2f_Map a) : p(a) {}
inline ae2f_ffun::setter ae2f_ffun::starter::alloc() {
	ae2f_Map(this->p);
	return p;
}

inline ae2f_ffun::setter ae2f_ffun::starter::copy(ptr_ae2f_Map a) {
	ae2f_Map_copy(a, this->p);
	return p;
}

inline ae2f_ffun::setter ae2f_ffun::starter::copy(struct ae2f_Map a) {
	return this->copy(&a);
}

inline ae2f_ffun::setter ae2f_ffun::starter::copy(setter a) {
	return this->copy(a.raw());
}

inline ae2f_ffun::setter ae2f_ffun::starter::copy(setter* a) {
	return this->copy(a->raw());
}
#pragma endregion

#pragma region Map
inline ae2f_nname::Map::Map()
	: setter(ae2f_ffun::starter(&this->obj).alloc()) {}

inline ae2f_nname::Map::Map(ptr_ae2f_Map a)
	: setter(ae2f_ffun::starter(&this->obj).copy(a)) {}

inline ae2f_nname::Map::Map(struct ae2f_Map a)
	: setter(ae2f_ffun::starter(&this->obj).copy(a)) {}

inline ae2f_nname::Map::Map(setter a)
	: setter(ae2f_ffun::starter(&this->obj).copy(a)) {}

inline ae2f_nname::Map::Map(setter* a)
	: setter(ae2f_ffun::starter(&this->obj).copy(a)) {}
inline ae2f_nname::Map::~Map() {
	ae2f_Map_free(this->raw());
}
#pragma endregion

#undef ae2f_ffun
#undef ae2f_nname

#endif // !AE2F_MAP_CPP
#endif

#endif // AE2F_PAIR