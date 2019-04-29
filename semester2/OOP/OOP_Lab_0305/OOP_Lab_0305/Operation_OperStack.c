#include "Operation_OperStack.h"
#include <stdlib.h>
#include <string.h>
#include "Country.h"

Operation * createOperation(Country * c, char * operationType)
{
	Operation* o = (Operation*)malloc(sizeof(Operation));
	o->country = copyCountry(c);

	o->operationType = (char*)malloc((strlen(operationType) + 1) * sizeof(char));
	strcpy(o->operationType, operationType);
	/*if (operationType != NULL)
	{
		
	}
	else
	{
		o->operationType = NULL;
	}*/
	return o;
}

void destroyOperation(Operation * o)
{
	if (o == NULL)
		return;
	free(o->operationType);
	destroyCountry(o->country);
	//if(o->operationType != NULL)
		
	free(o);
}

Operation * copyOperation(Operation * o)
{
	if(o == NULL)
		return NULL;
	Operation* new_o = createOperation(getCountry(o),getOperationType(o));
	return new_o;
}

char * getOperationType(Operation * o)
{
	return o->operationType;
}

Country * getCountry(Operation * o)
{
	return o->country;
}

//----------------------------------------------------------------------------

OperationsStack * createStack()
{
	OperationsStack* s = (OperationsStack*)malloc(sizeof(OperationsStack));
	s->length = 0;
	return s;
}

void destroyStack(OperationsStack * s)
{
	if (s == NULL)
		return;

	for (int i = 0; i < s->length; i++)
		destroyOperation(s->operations[i]);
	free(s);
}

void push(OperationsStack * s, Operation * o)
{
	Operation* newop = copyOperation(o);
	s->operations[s->length++] = newop ;
}

Operation * pop(OperationsStack * s)
{
	if(s == NULL)
		return NULL;
	s->length -= 1;
	return s->operations[s->length];
}

int isEmpty(OperationsStack * s)
{
	return (s->length == 0);
}

int isFull(OperationsStack * s)
{
	return (s->length == 100);
}
