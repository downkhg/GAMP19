#pragma once

#include <iostream>

using namespace std;
namespace Normal
{
	class CBike
	{
		int	m_nGear;
		int m_nSpeed;
		int m_nSeat;
	public:
		CBike(int seat)
		{
			m_nSeat = seat;
			m_nSpeed = 0;
			m_nGear = 0;
			cout << "CBike[" << this << "]" << endl;
		}
		~CBike()
		{
			cout << "~CBike[" << this << "]" << endl;
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

	class CAutoBike
	{
		int	m_nGear;
		int m_nSpeed;
		int m_nSeat;
		int m_nEngine;
	public:
		CAutoBike(int seat, int engine)
		{
			m_nSeat = seat;
			m_nSpeed = 0;
			m_nGear = 0;
			m_nEngine = engine;
			cout << "CAutoBike[" << this << "]" << endl;
		}
		~CAutoBike()
		{
			cout << "~CAutoBike[" << this << "]" << endl;
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

	class CBus
	{
		int	m_nGear;
		int m_nSpeed;
		int m_nSeat;
		int m_nEngine;
	public:
		CBus(int seat, int engine)
		{
			m_nSeat = seat;
			m_nSpeed = 0;
			m_nGear = 0;
			m_nEngine = engine;
			cout << "CBus[" << this << "]" << endl;
		}
		~CBus()
		{
			cout << "~CBus[" << this << "]" << endl;
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

	class CTruck
	{
		int	m_nGear;
		int m_nSpeed;
		int m_nSeat;
		int m_nEngine;
		int m_nWeight;
	public:
		CTruck(int seat, int engine, int weight)
		{
			m_nSeat = seat;
			m_nSpeed = 0;
			m_nGear = 0;
			m_nEngine = engine;
			m_nWeight = weight;
			cout << "CTruck[" << this << "]" << endl;
		}
		~CTruck()
		{
			cout << "~CTruck[" << this << "]" << endl;
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

	void CarTestMain()
	{
		CBike cBike(1);
		CAutoBike cAutoBike(2,100);
		CBus cBus(24,5000);
		CTruck cTruck(2,3000,1000);
	}
}