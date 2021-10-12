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


	
	//�������: �θ� �ִ� Ŭ������ ��ӹ޴°�.
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
		CAutoBike cAutoBike(2, 100); //����� �߰����������Ƿ� �ǹ̾��� ����̴�.
		//CEnginer cAutoBike(2, 100);//������ ���������� ������̸� �����.
		//CBus cBus(24,5000); 
		//CAutoBike cBus(24, 500);//������̷� ������ ����°��� ����� ������ �ִ�.
		//CEnginer cBus(24, 500);//������ ���������� ������ ����°��� �̻���������.
		//CTruck cTruck(2,3000,1000);
	}
}