#pragma once
#include <string>

//Resource base class
namespace neu {
	class Resource {
	public:
		virtual bool Create(std::string name, ...) = 0;
	};
}