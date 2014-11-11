#include "stdafx.h"
#include "CppUnitTest.h"
#include "../EightFigure/EightFigureState.h"
#include "../EightFigure/SearchCore.h"
#include "../EightFigure/DFS.h"
#include "../EightFigure/WFS.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(GetDataArray)
		{
            char data[9] = {1,2,3,4,5,6,7,8,0};
			EightFigureState state(data);
            char result[9];
            state.GetDataArray(result);
            for (int i = 0;i<9;i++)
            {
                Assert::AreEqual(data[i],result[i]);
            }
		}
        TEST_METHOD(Move)
        {
            char data[9] = {1,2,3,4,5,6,7,8,0};
            char gold[9] = {1,2,3,4,5,6,7,0,8};
            EightFigureState state(data);
            char result[9];
            Assert::AreEqual(state.Move(left),true);
            state.GetDataArray(result);
            for (int i = 0;i<9;i++)
            {
               Assert::AreEqual(gold[i],result[i]);
            }
        }
        TEST_METHOD(InverseOrder)
        {
            char data[9] = {1,0,2,3,4,5,6,7,8};
            EightFigureState state(data);
            int result  = state.InverseOrder();
            Assert::AreEqual(result,0);
        }
        TEST_METHOD(CanSlove)
        {
            char data1[9] = {1,2,3,4,5,6,7,8,0};
            char data2[9] = {1,2,5,3,4,6,0,7,8};
            EightFigureState state1(data1);
            EightFigureState state2(data2);
            Assert::AreEqual(state1.CanSolve(state2),true);
        }
        TEST_METHOD(SetDataArray)
        {
            char data1[9] = {1,2,3,4,5,6,7,8,0};
            char data2[9] = {1,2,3,4,5,6,7,8,9};
            char data3[9] = {1,2,3,4,5,6,6,0};
            EightFigureState state;
            Assert::AreEqual(state.SetDataArray(data1),true);
            Assert::AreEqual(state.SetDataArray(data2),false);
            Assert::AreEqual(state.SetDataArray(data3),false);
        }
	};
    TEST_CLASS(DFSClass)
    {
        TEST_METHOD(DFSTest)
        {
            char data1[9] = {1,2,3,4,5,6,7,8,0};
            char data2[9] = {1,2,5,3,4,6,0,7,8};
            EightFigureState state1(data1);
            EightFigureState state2(data2);
            DFS dfs(state1,state2);
            Assert::AreEqual(dfs.Search(),true);
        }
    };

    TEST_CLASS(WFSClass)
    {
        TEST_METHOD(WFSTest)
        {
            char data1[9] = {1,2,3,4,5,6,7,8,0};
            char data2[9] = {1,2,5,3,4,6,0,7,8};
            EightFigureState state1(data1);
            EightFigureState state2(data2);
            DFS dfs(state1,state2);
            Assert::AreEqual(dfs.Search(),true);
        }
    };
}