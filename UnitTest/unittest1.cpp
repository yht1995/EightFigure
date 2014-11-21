#include "stdafx.h"
#include "CppUnitTest.h"
#include "../EightFigure/EightFigureState.h"
#include "../EightFigure/SearchCore.h"
#include "../EightFigure/DFS.h"
#include "../EightFigure/BFS.h"
#include "../EightFigure/AStar.h"

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
            char data1[9] = {6,5,3,8,2,0,4,1,7};
            char data2[9] = {5,1,0,6,4,8,2,7,3};
            EightFigureState state1(data1);
            EightFigureState state2(data2);
            DFS dfs(state1,state2,1);
            Assert::AreEqual(dfs.Search(),false);
        }
    };

    TEST_CLASS(BFSClass)
    {
        TEST_METHOD(BFSTest)
        {
            char data1[9] = {6,5,3,8,2,0,4,1,7};
            char data2[9] = {5,1,0,6,4,8,2,7,3};
            EightFigureState state1(data1);
            EightFigureState state2(data2);
            BFS bfs(state1,state2);
            Assert::AreEqual(bfs.Search(),true);
        }
    };
    TEST_CLASS(AStarClass)
    {
        //TEST_METHOD(ClacDifference)
        //{
        //    char data1[9] = {6,5,3,8,2,0,4,1,7};
        //    char data2[9] = {5,1,0,6,4,8,2,7,3};
        //    EightFigureState state1(data1);
        //    EightFigureState state2(data2);
        //    AStar aStar(state1,state2);
        //    aStar.ClacDifference(state1);
        //    Assert::AreEqual(state1.fVaule,9);
        //}
        //TEST_METHOD(ClacManhattan)
        //{
        //    char data1[9] = {1,2,3,4,5,6,7,8,0};
        //    char data2[9] = {1,2,3,4,5,6,0,7,8};
        //    EightFigureState state1(data1);
        //    EightFigureState state2(data2);
        //    AStar aStar(state1,state2,1);
        //    Assert::AreEqual(aStar.ClacManhattan(state1,state2),4);
        //}
        TEST_METHOD(AStarTest)
        {
            char data1[9] = {6,5,3,8,2,0,4,1,7};
            char data2[9] = {5,1,0,6,4,8,2,7,3};
            EightFigureState state1(data1);
            EightFigureState state2(data2);
            AStar aStar(state1,state2,1);
            Assert::AreEqual(aStar.Search(),true);
        }
    };
}