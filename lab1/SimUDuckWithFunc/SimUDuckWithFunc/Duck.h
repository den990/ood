#ifndef DUCK_H
#define DUCK_H

#include "Dance/WaltzBehavior.h"
#include "Dance/NoDanceBehavior.h"
#include "Dance/MinuetBehavior.h"
#include "Fly/FlyNoWay.h"
#include "Fly/FlyWithWings.h"
#include "Quack/MuteQuackBehavior.h"
#include "Quack/QuackBehavior.h"
#include "Quack/SqueakBehavior.h"

#include <cassert>
#include <iostream>
#include <memory>
#include <vector>
#include <functional>

class Duck
{
public:
	Duck(std::function<void()>&& flyBehavior, std::function<void()>&& quackBehavior, std::function<void()>&& danceBehavior)
		: m_quackBehavior(std::move(quackBehavior))
	{
		assert(m_quackBehavior);
		SetFlyBehavior(std::move(flyBehavior));
		SetDanceBehavior(std::move(danceBehavior));
	}

	void Quack() const
	{
		m_quackBehavior();
	}

	void Swim() const
	{
		std::cout << "I'm swimming" << std::endl;
	}

	void Fly() const
	{
		m_flyBehavior();
	}

	void Dance() const
	{
		m_danceBehavior();
	}

	void SetFlyBehavior(std::function<void()>&& flyBehavior)
	{
		assert(flyBehavior);
		m_flyBehavior = std::move(flyBehavior);
	}

	void SetDanceBehavior(std::function<void()>&& danceBehavior)
	{
		assert(danceBehavior);
		m_danceBehavior = std::move(danceBehavior);
	}

	virtual void Display() const = 0;
	virtual ~Duck() = default;

private:
	std::function<void()> m_danceBehavior;
	std::function<void()> m_flyBehavior;
	std::function<void()> m_quackBehavior;
};

#endif
