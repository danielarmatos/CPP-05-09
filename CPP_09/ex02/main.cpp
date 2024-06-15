/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreis-ma <dreis-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 15:53:38 by dreis-ma          #+#    #+#             */
/*   Updated: 2023/12/03 16:07:51 by dreis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <sstream>

bool stringToInt(const std::string& str, int& result) {
	std::istringstream iss(str);
	return (iss >> result) && (iss.eof());
}

bool validateSequence(int argc, char** argv)
{
	for (int i = 1; i < argc; i++) {
		int n;
		if (!stringToInt(argv[i], n) || n < 0) {
			std::cerr << "Error: please use a positive integer sequence as argument" << std::endl;
			return false;
		}
	}
	return true;
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cout << "Usage: " << argv[0] << " <positive integer sequence>" << std::endl;
        return (1);
    }

    if (!validateSequence(argc, argv))
        return (1);

    std::cout << "Before: ";
    for (int i = 1; i < argc; i++)
        std::cout << argv[i] << " ";
    std::cout << std::endl;

    PmergeMe merge;
    merge.sortVector(argv + 1);
    merge.sortDeque(argv + 1);
}