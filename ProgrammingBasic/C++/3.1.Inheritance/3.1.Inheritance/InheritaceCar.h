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
	protected:
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

	class CEnginer : public CVihicle
	{
		int m_nEngine;
	public:
		CEnginer(int seat, int engine):CVihicle(seat)
		{
			m_nEngine = engine;
			cout << "CEnginer[" << this << "]" << endl;
		}
		~CEnginer()
		{
			cout << "~CEnginer[" << this << "]" << endl;
		}
	};

	class CAutoBike : public CBike, public CEnginer
	{
	public:
		CAutoBike(int seat, int engine):CBike(seat),CEnginer(seat, engine)
		{
			cout << "CAutoBike[" << this << "]" << endl;
		}
		~CAutoBike()
		{
			cout << "~CAutoBike[" << this << "]" << endl;
		}
	};


	
	//계층상속: 부모가 있는 클래스를 상속받는것.
	class CTruck : public CEnginer
	{
		int m_nWeight;
	public:
		CTruck(int seat, int engine, int weight):CEnginer(seat, engine)
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
		//CBike cBike(1);
		//CVihicle cBike(1);
		CAutoBike cAutoBike(2, 100); //멤버가 추가되지않으므로 의미없는 상속이다.
		//CEnginer cAutoBike(2, 100);//엔진을 가진것으로 오토바이를 만든다.
		//CBus cBus(24,5000); 
		//CAutoBike cBus(24, 500);//오토바이로 버스를 만드는것은 개념상 문제가 있다.
		//CEnginer cBus(24, 500);//엔진을 가진것으로 버스를 만드는것은 이상하지않음.
		//CTruck cTruck(2,3000,1000);
	}
}