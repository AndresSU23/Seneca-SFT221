#include "pch.h"
#include "CppUnitTest.h"
#include "store.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace Workshop3Testing
{
	TEST_CLASS(StringTesting)
	{
	public:
		
		TEST_METHOD(validString)
		{
			Assert::AreEqual(validateString("NAME"), true);
		}
		TEST_METHOD(invalidString)
		{
			Assert::AreEqual(validateString(""), false);
		}
		TEST_METHOD(oneJumpLine)
		{
			Assert::AreEqual(validateString("\n"), false);
		}
		TEST_METHOD(singlechar)
		{
			Assert::AreEqual(validateString("O"), false);
		}
		TEST_METHOD(minimumSizeInvalid)
		{
			Assert::AreEqual(validateString("LONGCHAR",100), false);
		}
		TEST_METHOD(oneJumpLineValid)
		{
			Assert::AreEqual(validateString("LONGCHAR",4), true);
		}
		TEST_METHOD(singleCharMinimun)
		{
			Assert::AreEqual(validateString("O",1), true);
		}
		TEST_METHOD(emptyWithMinimun)
		{
			Assert::AreEqual(validateString("", 4), false);
		}
	};

	TEST_CLASS(posCodeTest)
	{
	public:

		TEST_METHOD(validPostalCodeCaps)
		{

			Assert::AreEqual(validPostalCode("M2K 1H7"), "M2K 1H7");
		}
		TEST_METHOD(validPostalCodeNoCaps)
		{
			Assert::AreEqual(validPostalCode("m2k 1h7"), "M2K 1H7");
		}
		TEST_METHOD(validPostalCodeMixedCaps)
		{
			Assert::AreEqual(validPostalCode("m2K 1h7"), "M2K 1H7");
		}
		TEST_METHOD(validPostalCodeNoSpace)
		{
			Assert::AreEqual(validPostalCode("M2K1H7"), "M2K 1H7");
		}
		TEST_METHOD(validPostalCodemultipleSpaces)
		{
			Assert::AreEqual(validPostalCode("  M    2K 1   H  7"), "M2K 1H7");
		}
		TEST_METHOD(invalidPostalCode)
		{
			Assert::AreEqual(validPostalCode(" 1H7"), NULL);
		}
		TEST_METHOD(specialCharacters)
		{
			Assert::AreEqual(validPostalCode("!2%1@7"), NULL);
		}
		TEST_METHOD(empty)
		{
			Assert::AreEqual(validPostalCode(""), NULL);
		}
	};
}
