#include "pch.h"
#include "CppUnitTest.h"
#include "Task.h"
#include "TaskList.h"
#include "Utility.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(UnitTests)
	{
	public:
		
		TEST_METHOD(AddTaskCompleteAndValidate)
		{
			TaskList tl;
			bool added = tl.AddTask("Do homework", "31-12-2099");
			Assert::IsTrue(added);
			//Validate task ID
			Assert::IsTrue(tl.IsValidTaskID(1));

			const Task& t = tl.SetTaskComplete(1);
			//Validate task data
			//Completed, name and date are all correct
			Assert::IsTrue(t.IsCompleted());
			Assert::IsTrue(t.ToString().find("Do homework") != std::string::npos);
			Assert::IsTrue(t.ToString().find("31-12-2099") != std::string::npos);
		}
		TEST_METHOD(DeleteTaskAndValidate)
		{
			TaskList tl;
			bool added = tl.AddTask("Do homework", "31-12-2099");
			Assert::IsTrue(added);
			//Validate Task exists
			Assert::IsTrue(tl.IsValidTaskID(1));
			//Ensure it's not empty
			Assert::IsFalse(tl.GetList().size() == 0);
			tl.DeleteTask(1);
			//Task deleted
			Assert::IsTrue(tl.GetList().size() == 0);
		}
		TEST_METHOD(ValidateDueDateTask)
		{
			TaskList tl;
			//Test with past date
			bool added = tl.AddTask("Do homework", "31-12-2024");
			Assert::IsFalse(added);
			//Ensure list is empty
			Assert::IsTrue(tl.GetList().size() == 0);

			//Test with wrong format
			added = tl.AddTask("Do homework", "31st March 2024");
			Assert::IsFalse(added);
			//Ensure list is empty
			Assert::IsTrue(tl.GetList().size() == 0);
			//Test with wrong day
			added = tl.AddTask("Do homework", "40-12-2026");
			Assert::IsFalse(added);
			//Ensure list is empty
			Assert::IsTrue(tl.GetList().size() == 0);
			//Test with wrong Month
			added = tl.AddTask("Do homework", "25-13-2026");
			Assert::IsFalse(added);
			//Ensure list is empty
			Assert::IsTrue(tl.GetList().size() == 0);
			//Validate with correct date
			added = tl.AddTask("Do homework", "25-12-2026");
			Assert::IsTrue(added);


			//Ensure list is not empty
			Assert::IsFalse(tl.GetList().size() == 0);

		}
		TEST_METHOD(ValidateIDTask)
		{
			TaskList tl;
			//Test with past date
			bool added = tl.AddTask("Do homework", "31-12-2024");
			//Test out of bounds upper, lower and zero
			Assert::IsFalse(tl.IsValidTaskID(2));
			Assert::IsFalse(tl.IsValidTaskID(-1));
			Assert::IsFalse(tl.IsValidTaskID(0));
			//Test correct ID
			added = tl.AddTask("Do homework", "31-12-2099");
			Assert::IsTrue(tl.IsValidTaskID(1));
		}
		TEST_METHOD(AddDeleteMultipleTasksAndValidate)
		{
			TaskList tl;

			//Add first task, ensure ID 1 is valid while id 2 isn't
			bool added = tl.AddTask("Do homework", "31-12-2099");
			Assert::IsTrue(added);
			Assert::IsTrue(tl.IsValidTaskID(1));
			Assert::IsFalse(tl.IsValidTaskID(2));
			Task t = tl.GetList()[0];
			Assert::IsTrue(t.ToString().find("Do homework") != std::string::npos);
			Assert::IsTrue(t.ToString().find("31-12-2099") != std::string::npos);

			//Test 2nd task, both 1st and 2nd ids are valid
			added = tl.AddTask("Eat dinner", "31-12-2055");
			Assert::IsTrue(added);
			Assert::IsTrue(tl.IsValidTaskID(1));
			Assert::IsTrue(tl.IsValidTaskID(2));
			t = tl.GetList()[1];
			Assert::IsTrue(t.ToString().find("Eat dinner") != std::string::npos);
			Assert::IsTrue(t.ToString().find("31-12-2055") != std::string::npos);

			//Delete 1st task, ensure remaining task is still valid
			tl.DeleteTask(1);
			Assert::IsTrue(tl.GetList().size() == 1);
			t = tl.GetList()[0];
			Assert::IsTrue(t.ToString().find("Eat dinner") != std::string::npos);
			Assert::IsTrue(t.ToString().find("31-12-2055") != std::string::npos);

			//Delete 2nd task, ensure list is empty
			tl.DeleteTask(1);
			Assert::IsTrue(tl.GetList().size() == 0);
		}
	};
}
