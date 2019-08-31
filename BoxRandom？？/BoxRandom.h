#pragma once
#include <deque>
#include <cstdint>
#include <random>

template<class Rnd=std::mt19937>
class BoxRandom {
public:

	BoxRandom() { Initialize(100); }
	
	BoxRandom(std::size_t N) {
		Initialize(N);
	}

	bool Initialize(std::size_t N) {
		B.clear();
		for (std::size_t i = 0; i < N; i++) {
			B.push_back(i);
		}
		return true;
	}
	bool Randmize() {
		std::shuffle(B.begin() + P, B.end(),R);
		return true;
	}
	bool SetZero() {
		P = 0;
		return true;
	}
	std::size_t Get() {
		P = (P % B.size());
		if (P == 0) { std::shuffle(B.begin(), B.end(),R); }
		return B[P++];
	}

	std::size_t Size() const{
		return B.size();
	}

protected:
	typedef std::deque<std::size_t> Box;

	Box B;
	std::size_t P = 0;
	Rnd R{ std::random_device()() };
};