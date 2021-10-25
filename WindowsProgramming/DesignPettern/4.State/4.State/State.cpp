#include "State.h"
#include <iostream>

//부모클래스를 잘몰라도 상속받아 사용가능하고 일부부분 추가 가능하다.
void StateThree::GoNext(Context* context)
{
	context->SetState(new StateOne);
}

void StateTow::GoNext(Context* context) 
{
	context->SetState(new StateThree);
}

void StateOne::GoNext(Context* context)
{
	context->SetState(new StateTow);
}

Context::Context()
{
	m_pState = new StateOne();
}

Context::Context(State* state)
{
	m_pState = state;
}

Context::~Context()
{
	delete m_pState;
}

void Context::SetState(State* newState)
{
	if (m_pState) delete m_pState;
	std::cout << "SetState:" << typeid(*newState).name() << std::endl;
	m_pState = newState;
}

void Context::GoNext()
{
	m_pState->GoNext(this);
}
