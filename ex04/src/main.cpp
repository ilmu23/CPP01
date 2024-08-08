// ███████╗████████╗     ██████╗ ██╗   ██╗████████╗ ██████╗██╗  ██╗ █████╗ ██████╗
// ██╔════╝╚══██╔══╝     ██╔══██╗██║   ██║╚══██╔══╝██╔════╝██║  ██║██╔══██╗██╔══██╗
// █████╗     ██║        ██████╔╝██║   ██║   ██║   ██║     ███████║███████║██████╔╝
// ██╔══╝     ██║        ██╔═══╝ ██║   ██║   ██║   ██║     ██╔══██║██╔══██║██╔══██╗
// ██║        ██║███████╗██║     ╚██████╔╝   ██║   ╚██████╗██║  ██║██║  ██║██║  ██║
// ╚═╝        ╚═╝╚══════╝╚═╝      ╚═════╝    ╚═╝    ╚═════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝
//
// <<main.cpp>>

#include <string>
#include <fstream>
#include <iostream>

static inline void	_replace(std::string &line, std::string &s1, std::string &s2);

int32_t	main(int argc, char **argv)
{
	std::string		s1;
	std::string		s2;
	std::string		line;
	std::string		fname;
	std::ifstream	infile;
	std::ofstream	outfile;

	if (argc != 4)
	{
		std::cerr << "ft_sed: usage: ft_sed <filename> <match> <replace>" << std::endl;
		return 1;
	}
	s1 = argv[2];
	s2 = argv[3];
	fname = argv[1];
	infile.open(fname);
	outfile.open(fname + ".replace");
	if (infile.fail() || outfile.fail())
	{
		if (infile.fail())
			std::cerr << "ft_sed: error opening file: " << fname << std::endl;
		else
			infile.close();
		if (outfile.fail())
			std::cerr << "ft_sed: error opening file: " << fname << ".replace" << std::endl;
		else
			outfile.close();
		return 1;
	}
	while (!infile.eof())
	{
		std::getline(infile, line);
		_replace(line, s1, s2);
		outfile << line;
		if (!infile.eof())
			outfile << std::endl;
	}
	infile.close();
	outfile.close();
	return 0;
}

static inline void	_replace(std::string &line, std::string &s1, std::string &s2)
{
	size_t	match;

	match = line.find(s1, 0);
	while (match != std::string::npos)
	{
		line = line.substr(0, match) + s2 + line.substr(match + s1.length(), line.length());
		match = line.find(s1, match + s2.length());
	}
}
