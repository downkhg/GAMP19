#pragma once

#include <iostream>

using namespace std;
namespace Inheritance
{
	class CVihicle
	{
		int	m_nGear;
		int m_nSpeed;
		int m_nSeat;
	public:
		CVihicle(int seat)
		{
			m_nSeat = seat;
			m_nSpeed = 0;
			m_nGear = 0;
			cout << "CVihicle[" << this << "]" << endl;
		}
		~CVihicle()
		{
			cout << "~CVihicle[" << this << "]" << endl;
		}
		void SetGeat(int gear)
		{
			m_nGear = gear;
		}
		void Accel()
		{
			m_nSpeed++;
		}
		void Break()
		{
			m_nSpeed--;
		}
	};

	class CBike : public CVihicle
	{
	public:
		CBike(int seat):CVihicle(seat)
		{
			cout << "CBike[" << this << "]" << endl;
		}
		~CBike()
		{
			cout << "~CBike[" << this << "]" << endl;
		}
	};

	class CAutoBike : public CVihicle
	{
		int m_nEngine;
	public:
		CAutoBike(int seat, int engine):CVihicle(seat)
		{
			m_nEngine = engine;
			cout << "CAutoBike[" << this << "]" << endl;
		}
		~CAutoBike()
		{
			cout << "~CAutoBike[" << this << "]" << endl;
		}
	};

	class CBus : public CAutoBike
	{
	public:
		CBus(int seat, int engine):CAutoBike(seat, engine)
		{
			cout << "CBus[" << this << "]" << endl;
		}
		~CBus()
		{
			cout << "~CBus[" << this << "]" << endl;
		}
	};

	class CTruck : public CBus
	{
		int m_nWeight;
	public:
		CTruck(int seat, int engine, int weight):CBus(seat, engine)
		{
			m_nWeight = weight;
			cout << "CTruck[" << this << "]" << endl;
		}
		~CTruck()
		{
			cout << "~CTruck[" << this << "]" << endl;
		}
	};

	void CarTestMain()
	{
		CBike cBike(1);
		CAutoBike cAutoBike(2,100);
		CBus cBus(24,5000);
		CTruck cTruck(2,3000,1000);
	}
}