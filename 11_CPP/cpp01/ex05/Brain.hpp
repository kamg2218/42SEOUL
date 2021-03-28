#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include <string>

class	Brain
{
	private:
		std::string		frontal_lobe;//전두엽-기억력
		std::string		temporal_lobe;//측두엽-청각
		std::string		parietal_lobe;//두정엽-사고력, 수학
		std::string		occipital_lobe;//후두엽-시각
	public:
		Brain()
		{
			frontal_lobe = "0123456789ABCDEF";
		}
		std::string		identify();
		std::string		getFrontal();
};

#endif
