#include <iostream>
#include <string>

#include <boost/program_options/options_description.hpp>
#include <boost/program_options/variables_map.hpp>
#include <boost/program_options/parsers.hpp>


namespace po = boost::program_options;


const std::string version = "0.1.0";


int
main(int argc, char* argv[])
{
	po::options_description desc("Options");
	desc.add_options()
		("help", "Show this help message.")
		("version", "Show this program version.")
		("threads", po::value<int>(),
			"Thread count to use for task execution.")
	;

	po::variables_map options;
	po::store(po::parse_command_line(argc, argv, desc), options);
	po::notify(options);

	if (options.count("help") > 0 ) {
		std::cout << desc << '\n';
	}

	if (options.count("version") > 0) {
		std::cout << "Boost Program Options sample " << version << '\n';
	}

	if (options.count("threads") > 0) {
		std::cout << "Thread count: " << options["threads"].as<int>()
			<< '\n';
	}

	return 0;
}
