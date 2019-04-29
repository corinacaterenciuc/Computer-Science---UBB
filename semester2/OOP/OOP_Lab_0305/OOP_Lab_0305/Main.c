#include "UI.h"
#include "Controller.h"
#include "Repository.h"
#include "Country.h"
#include <crtdbg.h> 
#include "Operation_OperStack.h"



int main()
{
	Test_Country();
	Test_Repository();
	Test_Controller();

	Repository* repo = init_repo(100);
	OperationsStack* operationsStack_undo = createStack();
	OperationsStack* operationsStack_redo = createStack();

	Controller* controller = init_controller(repo,operationsStack_undo,operationsStack_redo);
	UI* ui= init_ui(controller);
	
	existing_values(ui);
	start_ui(ui);

	destroyArray(repo);
	destroyStack(operationsStack_redo);
	destroyStack(operationsStack_undo);
	
	
	destroy_controller(controller);
	destroy_ui(ui);
	_CrtDumpMemoryLeaks();

	return 0;

}