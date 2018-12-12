#pragma once

#include <vector>
#include <list>
#include <iterator>

template<class T>
class VectorList
{
private:
	using VectT = std::vector<T>;
	using ListT = std::list<VectT>;

public:
	using value_type = T;

	VectorList() = default;
	VectorList(VectorList const &) = default;
	VectorList(VectorList &&) = default;

	VectorList & operator=(VectorList &&) = default;
	VectorList & operator=(VectorList const &) = default;

	// метод, который будет использоваться для заполнения VectorList
	// гарантирует, что в списке не будет пустых массивов
	template<class It>
	void append(It p, It q)  {
		if (p != q) {
			data_.push_back(VectT(p, q));
		}
	}
							 
	bool empty() const { return size() == 0; }

	// определите метод size
	size_t size() const	{
		size_t size = 0;
		auto it = data_.begin();
		for (; it != data_.end(); ++it) {
			size += (*it).size();
		}
		return size;
	}

	// определите const_iterator
	struct const_iterator : std::iterator<std::bidirectional_iterator_tag, 
										VectorList, std::ptrdiff_t, T const *, T const &> {
		typedef typename ListT::const_iterator ListIt;
		typedef typename VectT::const_iterator VectIt;
		ListIt itl;
		VectIt itv;
		ListT const * ptr_data;

		const_iterator() = default;
		const_iterator(const_iterator const& it) = default;
		const_iterator(ListIt const & list_it, VectIt const & vect_it, ListT const * d) {
			itl = list_it;
			itv = vect_it;
			ptr_data = d;
		}

		const_iterator(ListIt const & list_it, ListT const * d) {
			itl = list_it;
			ptr_data = d;
		}

		const_iterator operator++ (int) {
			const_iterator it(*this);
			++(*this);
			return it;
		}

		const_iterator& operator++ () {
			if ((*itl).end() == ++itv) {
				++itl;
				if (ptr_data -> end() != itl) {
					itv = (*itl).begin();
				}
				
			}
			return (*this);
		}

		const_iterator& operator-- () {
			if (ptr_data->end() == itl) {
				--itl;
				--itv;
			}
			else {
				if ((*itl).begin() == itv) {
					--itl;
					itv = --(*itl).end();
				}
				else {
					--itv;
				}
			}
			return (*this);
		}

		const_iterator operator-- (int) {
			const_iterator it(*this);
			--(*this);
			return it;
		}

		bool operator== (const const_iterator& it) const {
			return ((it.itl == itl) && (it.itv == itv)) ? true : false;
		}

		bool operator!= (const const_iterator&it) const {
			return !((*this) == it);
		}

		T const& operator*() const {
			return (*itv);
		}

		const T* operator->() const {
			return &(*itv);
		}
		
	};

		// определите методы begin / end
	const_iterator begin() const { 
		if (data_.begin() == data_.end()) {
			return const_iterator(data_.begin(), &data_);
		}
		return const_iterator(data_.begin(), (*(data_.begin())).begin(), &data_);
	}
	const_iterator end() const { 
		if (data_.begin() == data_.end()) {
			return const_iterator(data_.end(), &data_);
		}
		else {
			return const_iterator(data_.end(), (*(--data_.end())).end(), &data_);
		}
	}

	//// определите const_reverse_iterator
	using const_reverse_iterator = std::reverse_iterator<const_iterator>;

	//	// определите методы rbegin / rend
	const_reverse_iterator rbegin() const { 
		return const_reverse_iterator((*this).end());
	}
	const_reverse_iterator rend()   const { 
		return const_reverse_iterator((*this).begin());
	}

private:
	ListT data_;
};
