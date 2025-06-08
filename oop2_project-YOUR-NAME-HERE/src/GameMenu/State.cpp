#include "GameMenu/State.h"

State::State()
	:m_start(false), 
	m_exit(false),
	m_help(false),
	m_store(false),
	m_watch(false),
	m_gitHub(false)
{}


// Setters
void State::setStart(bool value) { m_start = value; }
void State::setExit(bool value) { m_exit = value; }
void State::setHelp(bool value) { m_help = value; }
void State::setStore(bool value) { m_store = value; }
void State::setWatch(bool value) { m_watch = value; }
void State::setGitHub(bool value) { m_gitHub = value; }

// Getters
bool State::isStart() const { return m_start; }
bool State::isExit() const { return m_exit; }
bool State::isHelp() const { return m_help; }
bool State::isStore() const { return m_store; }
bool State::isWatch() const{ return m_watch; }
bool State::isGitHub() const{ return m_gitHub; }



void State::initStates()
{
	m_start = false;
	m_exit = false;
	m_help = false;
	m_store = false;
	m_watch = false;
	m_gitHub = false;
}
