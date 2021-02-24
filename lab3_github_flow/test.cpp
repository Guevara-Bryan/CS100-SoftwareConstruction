#include "c-echo.h"
#include "c-count.h"

#include "gtest/gtest.h"

TEST(EchoTest, HelloWorld) {
	char* test_val[3]; test_val[0] = "./c-echo"; test_val[1] = "hello"; test_val[2] = "world";
	EXPECT_EQ("hello world", echo(3,test_val));
}

TEST(EchoTest, EmptyString) {
	char* test_val[1]; test_val[0] = "./c-echo";
	EXPECT_EQ("", echo(1,test_val));
}


// For the demo
// non-ascii character: É
const int TEST_SIZE = 5;
char* TEST_VAL[TEST_SIZE]{"./c-echo", "There", "are", "8", "houses"};


TEST(LabTest, HasDigit) {
	/*char* test_val[3];
	test_val[0] = "./c-echo"; test_val[1] = "123"; test_val[2] = "456";*/
	bool hasDigit = false;
	for (auto cha : echo(TEST_SIZE,TEST_VAL))
	{
		if (!isblank(cha) && isdigit(cha)){
			hasDigit = true;
			break;
		}
	}
	EXPECT_TRUE(hasDigit);
}


TEST(LabTest, AsciiOnly) {
	/*char* test_val[4]; test_val[0] = "./c-echo";
	test_val[1] = "Wow"; test_val[2] = "nice"; test_val[3] = "house"*/	
	bool isAscii = true;	

	for(auto cha : echo(TEST_SIZE, TEST_VAL)){
		if(cha < 0 || cha > 255){
			isAscii = false;
			break;
		}
		
	}
	EXPECT_TRUE(isAscii);
	
}

TEST(LabTest, HasUpper) {
	/*char* test_val[3];
	test_val[0] = "./c-echo"; test_val[1] = "Pretty"; test_val[2] = "car";*/
	bool hasUpper = false;
	for (auto cha : echo(TEST_SIZE,TEST_VAL))
	{
		if (!isblank(cha) && isupper(cha)){
			hasUpper = true;
			break;
		}
	}
	EXPECT_TRUE(hasUpper);
}

//============== CountTest suite ===============================

TEST(CountTest, HelloWorld) {
    std::string test_str = "hello world";
	EXPECT_EQ(2, count(test_str));
}

TEST(CountTest, EmptyString) {
	std::string test_str = "";
	EXPECT_EQ(0, count(test_str));
}



TEST(CountTest, ManySpaces) {
	std::string test_str = "   this   string has     weird   spacing";
	EXPECT_EQ(5, count(test_str));
}


int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

