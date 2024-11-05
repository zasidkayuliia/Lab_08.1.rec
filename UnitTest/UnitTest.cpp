#define _CRT_SECURE_NO_WARNINGS
#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_8.1.rec/Lab_8.1.rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			char testStr1[] = "aabbcc";
			Assert::AreEqual(3, Count(testStr1), L"Test failed: 'aabbcc' should contain 3 pairs");
		}
	};
}
