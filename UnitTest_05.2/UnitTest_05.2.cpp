#include "pch.h"
#include "CppUnitTest.h"
#include "../PR-05.2.cpp"  // мій проект.

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest52
{
    TEST_CLASS(UnitTest52)
    {
    public:

        // Перевірка рекурентного співвідношення:
        // a0 = -1/x = 0.5, R = -1/(3*x^2) = -1/12  =>  a1 = -1/24
        TEST_METHOD(TestA_FirstStep)
        {
            double x = -2.0;
            double a0 = -1.0 / x;
            double a1 = A(x, 1, a0);
            Assert::AreEqual(-1.0 / 24.0, a1, 1e-12);
        }

        // Сума ряду має збігатися з atan(x) з точністю eps
        TEST_METHOD(TestS_MatchesAtan_x_minus2)
        {
            double x = -2.0, eps = 1e-6;
            int n = 0;
            double s = S(x, eps, n, 0);
            Assert::AreEqual(atan(x), s, 1e-5);
        }

        TEST_METHOD(TestS_MatchesAtan_x_minus1_5)
        {
            double x = -1.5, eps = 1e-6;
            int n = 0;
            double s = S(x, eps, n, 0);
            Assert::AreEqual(atan(x), s, 1e-5);
        }

        // Кількість доданків має бути додатною
        TEST_METHOD(TestS_TermsCount)
        {
            double x = -3.0, eps = 1e-4;
            int n = 0;
            S(x, eps, n, 0);
            Assert::IsTrue(n > 0);
        }
    };
}