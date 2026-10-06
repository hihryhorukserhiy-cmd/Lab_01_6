#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_1_6/Date.h"
#include "../lab_1_6/Date.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Date::Triad t;
			t.Init(10, 20, 30);
			t.IncrementAll();
			Assert::AreEqual(11, t.GetFirst());
			Assert::AreEqual(21, t.GetSecond());
			Assert::AreEqual(31, t.GetThird());

		}
	};
}

