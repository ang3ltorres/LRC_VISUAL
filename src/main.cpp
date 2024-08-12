#include <print>
#include <fstream>
#include <string>
#include <vector>
#include <cstdint>
#include <print>

struct Time
{
	std::uint8_t mm;
	std::uint8_t ss;
	std::uint8_t hs;
};

struct Tag
{
	Tag(const std::string &line)
	{
		auto it = line.begin();

		while (*it == '[')
		{
			std::string aux{};
			Time time;

			auto get = [&]() -> std::uint8_t
			{
				aux.clear();
				it++;
				aux += *it; it++;
				aux += *it; it++;
				return std::stoul(aux);
			};

			time.mm = get();
			time.ss = get();
			time.hs = get();

			// Next
			it++;
			times.push_back(time);
		}

		// String
		for (; it != line.end(); it++)
			str += *it;
	}

	std::vector<Time> times;
	std::string str;
};


std::vector<std::string> get_lines(const std::string &filename)
{
	std::string string;
	std::vector<std::string> lines;
	std::fstream file;
	
	file.open(filename, std::ios::in);
	while (std::getline(file, string))
	{
		if (!string.empty())
			lines.push_back(string);
	}

	return lines;
}

int main()
{
	auto lines = get_lines("../test.lrc");
	std::vector<Tag> tags;

	for (const auto &i : lines)
		tags.push_back(i);

	for (const auto &i : tags)
	{
		for (const auto &t : i.times)
			std::print("[{:02}:{:02}:{:02}]", t.mm, t.ss, t.hs);

		std::print("{}", i.str);
		std::print("\n\n");
	}

	return 0;
}
