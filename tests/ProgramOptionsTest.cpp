#include "gtest/gtest.h"

#include "src/ProgramOptions.h"

#include <string>
#include <vector>


TEST(ProgramOptions, ShouldParseEmptyOptions)
{
	std::vector<std::string> args = { "benchmark.exe" };
	const int argc = static_cast<int>(args.size());
	char *argv[] = { (char *)args[0].c_str() };

	auto options = sltbench::BuildProgramOptions(argc, argv);

	EXPECT_TRUE(options.empty());
}

TEST(ProgramOptions, ShouldParseFilterOptionAsSingleArg)
{
	std::vector<std::string> args{ "benchmark.exe", "--filter=.*hohoho.*" };
	const int argc = static_cast<int>(args.size());
	char *argv[] = {
		(char *)args[0].c_str(),
		(char *)args[1].c_str()
	};

	auto options = sltbench::BuildProgramOptions(argc, argv);

	ASSERT_EQ(1, options.size());
	EXPECT_EQ(".*hohoho.*", options["--filter"]);
}

TEST(ProgramOptions, ShouldParseFilterOptionAsTwoArgs)
{
	std::vector<std::string> args{ "benchmark.exe", "--filter", ".*hohoho.*" };
	const int argc = static_cast<int>(args.size());
	char *argv[] = {
		(char *)args[0].c_str(),
		(char *)args[1].c_str(),
		(char *)args[2].c_str()
	};

	auto options = sltbench::BuildProgramOptions(argc, argv);

	ASSERT_EQ(1, options.size());
	EXPECT_EQ(".*hohoho.*", options["--filter"]);
}

TEST(ProgramOptions, ShouldParseFilterOptionIfPositionalArgExists)
{
	std::vector<std::string> args{ "benchmark.exe", "positional_arg", "--filter", ".*hohoho.*" };
	const int argc = static_cast<int>(args.size());
	char *argv[] = {
		(char *)args[0].c_str(),
		(char *)args[1].c_str(),
		(char *)args[2].c_str(),
		(char *)args[3].c_str()
	};

	auto options = sltbench::BuildProgramOptions(argc, argv);

	ASSERT_EQ(1, options.size());
	EXPECT_EQ(".*hohoho.*", options["--filter"]);
}

TEST(ProgramOptions, ShouldParseFilterOptionIfOneLetterArgExists)
{
	std::vector<std::string> args{ "benchmark.exe", "-p", "--filter", ".*hohoho.*" };
	const int argc = static_cast<int>(args.size());
	char *argv[] = {
		(char *)args[0].c_str(),
		(char *)args[1].c_str(),
		(char *)args[2].c_str(),
		(char *)args[3].c_str()
	};

	auto options = sltbench::BuildProgramOptions(argc, argv);

	ASSERT_EQ(1, options.size());
	EXPECT_EQ(".*hohoho.*", options["--filter"]);
}

TEST(ProgramOptions, ShouldParseFilterOptionIfOneLetterArgWithValueExists)
{
	std::vector<std::string> args{ "benchmark.exe", "-p", "printer", "--filter", ".*hohoho.*" };
	const int argc = static_cast<int>(args.size());
	char *argv[] = {
		(char *)args[0].c_str(),
		(char *)args[1].c_str(),
		(char *)args[2].c_str(),
		(char *)args[3].c_str(),
		(char *)args[4].c_str()
	};

	auto options = sltbench::BuildProgramOptions(argc, argv);

	ASSERT_EQ(1, options.size());
	EXPECT_EQ(".*hohoho.*", options["--filter"]);
}
