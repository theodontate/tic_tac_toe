#ifndef id41881476617158
#define id41881476617158

#include <iostream>
#include "BoardField.hpp"

class Player {
	public:
		Player (std::string name, mark type);
		std::string GetName ( );
		std::string GetType ( );

	private:
		std::string m_name;
		mark m_type;
};


#endif
